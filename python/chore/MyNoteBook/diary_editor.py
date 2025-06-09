import os
import markdown2
from datetime import datetime
from PyQt5.QtWidgets import (
    QMainWindow,
    QWidget,
    QVBoxLayout,
    QHBoxLayout,
    QSplitter,
    QTextEdit,
    QFileDialog,
    QToolBar,
    QAction,
    QStatusBar,
)
from PyQt5.QtWebEngineWidgets import QWebEngineView
from PyQt5.QtCore import Qt, QTimer
from PyQt5.QtGui import QIcon, QTextCursor


class DiaryEditor(QMainWindow):

    def __init__(self):
        super().__init__()
        # 初始化css属性
        self.css = """
        body {
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif;
            line-height: 1.6;
            color: #333;
            padding: 20px;
        }
        """
        self.init_ui()
        self.current_file = None
        self.setup_connections()
        self.create_diary_dir()

    def init_ui(self):
        """init the UI interface"""
        self.setWindowTitle("Sickwag Diary")
        self.setGeometry(100, 100, 800, 600)

        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)

        self.create_toolbar()

        self.splitter = QSplitter(Qt.Horizontal)

        self.editor = QTextEdit()
        self.editor.setStyleSheet("font-size: 14px;")
        self.editor.textChanged.connect(self.schedule_preview_update)

        self.preview = QWebEngineView()
        self.preview.setHtml(self.get_empty_html())

        self.splitter.addWidget(self.editor)
        self.splitter.addWidget(self.preview)
        self.splitter.setSizes([400, 400])

        self.layout.addWidget(self.splitter)

        # MenuBar
        self.status_bar = QStatusBar()
        self.setStatusBar(self.status_bar)

        # Preview Time ticker
        self.preview_timer = QTimer()
        self.preview_timer.setSingleShot(True)
        self.preview_timer.timeout.connect(self.update_preview)

        # load CSS
        self.load_styles()

    def create_toolbar(self):
        """创建工具栏"""
        toolbar = QToolBar()
        self.addToolBar(toolbar)

        # 新建日记
        new_action = QAction(QIcon.fromTheme("document-new"), "新建", self)
        new_action.triggered.connect(self.new_diary)
        toolbar.addAction(new_action)

        # 打开日记
        open_action = QAction(QIcon.fromTheme("document-open"), "打开", self)
        open_action.triggered.connect(self.open_diary)
        toolbar.addAction(open_action)

        # 保存日记
        save_action = QAction(QIcon.fromTheme("document-save"), "保存", self)
        save_action.triggered.connect(self.save_diary)
        toolbar.addAction(save_action)

        # 分隔线
        toolbar.addSeparator()

        # 插入日期
        date_action = QAction(QIcon.fromTheme("x-office-calendar"), "插入日期", self)
        date_action.triggered.connect(self.insert_date)
        toolbar.addAction(date_action)

    def setup_connections(self):
        """设置信号连接"""
        self.editor.textChanged.connect(self.schedule_preview_update)

    def create_diary_dir(self):
        """创建日记存储目录"""
        if not os.path.exists("diaries"):
            os.makedirs("diaries")

    def load_styles(self):
        """加载CSS样式"""
        css_path = os.path.join("resources", "styles.css")
        if os.path.exists(css_path):
            try:
                with open(css_path, "r", encoding="utf-8") as f:
                    self.css = f.read()
            except:
                # 如果加载失败，保留默认样式
                pass

    def schedule_preview_update(self):
        """安排预览更新"""
        self.preview_timer.start(500)  # 500毫秒延迟

    def update_preview(self):
        """更新预览内容"""
        markdown_text = self.editor.toPlainText()
        html = markdown2.markdown(
            markdown_text, extras=["fenced-code-blocks", "tables"]
        )

        full_html = f"""
        <!DOCTYPE html>
        <html>
        <head>
            <meta charset="utf-8">
            <style>{self.css}</style>
        </head>
        <body>
            {html}
        </body>
        </html>
        """

        self.preview.setHtml(full_html)

    def new_diary(self):
        """新建日记"""
        self.editor.clear()
        self.current_file = None
        self.insert_date()
        self.status_bar.showMessage("已创建新日记", 2000)

    def open_diary(self):
        """打开日记文件"""
        file_path, _ = QFileDialog.getOpenFileName(
            self, "打开日记", "diaries", "Markdown文件 (*.md);;所有文件 (*)"
        )

        if file_path:
            try:
                with open(file_path, "r", encoding="utf-8") as f:
                    content = f.read()
                    self.editor.setPlainText(content)
                    self.current_file = file_path
                    self.status_bar.showMessage(f"已打开: {file_path}", 2000)
            except Exception as e:
                self.status_bar.showMessage(f"打开文件失败: {str(e)}", 3000)

    def save_diary(self):
        """保存日记"""
        if self.current_file:
            file_path = self.current_file
        else:
            # 默认使用当前日期作为文件名
            default_name = datetime.now().strftime("%Y-%m-%d.md")
            file_path = os.path.join("diaries", default_name)

            file_path, _ = QFileDialog.getSaveFileName(
                self, "保存日记", file_path, "Markdown文件 (*.md);;所有文件 (*)"
            )

            if not file_path:
                return

        try:
            with open(file_path, "w", encoding="utf-8") as f:
                f.write(self.editor.toPlainText())
                self.current_file = file_path
                self.status_bar.showMessage(f"已保存到: {file_path}", 2000)
        except Exception as e:
            self.status_bar.showMessage(f"保存文件失败: {str(e)}", 3000)

    def insert_date(self):
        """插入当前日期"""
        date_str = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        self.editor.textCursor().insertText(f"# {date_str}\n\n")

    def get_empty_html(self):
        """获取空HTML模板"""
        return f"""
        <!DOCTYPE html>
        <html>
        <head>
            <meta charset="utf-8">
            <style>{self.css}</style>
        </head>
        <body>
            <p>开始输入Markdown内容...</p>
        </body>
        </html>
        """
