import sys
from PyQt5.QtWidgets import QApplication
from diary_editor import DiaryEditor


def main():
    app = QApplication(sys.argv)
    editor = DiaryEditor()
    editor.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
