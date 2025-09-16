import tkinter as tk
from tkinter import messagebox
import pystray
from PIL import Image
import threading
import time
import sys
import os

class FocusReminderApp:
    def __init__(self):
        # 主窗口设置
        self.root = tk.Tk()
        self.root.withdraw()  # 初始隐藏主窗口

        # 系统托盘图标
        self.create_tray_icon()

        # 计时变量
        self.remaining_seconds = 20 * 60  # 20分钟
        self.is_paused = False
        self.timer_thread = threading.Thread(target=self.run_timer, daemon=True)
        self.timer_thread.start()

    def create_tray_icon(self):
        """创建系统托盘图标"""
        image = Image.new('RGB', (64, 64), 'white')
        menu = (
            pystray.MenuItem('显示', self.show_window),
            pystray.MenuItem('退出', self.quit_app)
        )
        self.tray_icon = pystray.Icon(
            "focus_reminder",
            image,
            "专注提醒器",
            menu
        )

        # 在单独线程运行托盘图标
        threading.Thread(target=self.tray_icon.run, daemon=True).start()

    def run_timer(self):
        """后台计时器核心逻辑"""
        while True:
            if self.is_paused:
                time.sleep(1)
                continue

            time.sleep(1)
            self.remaining_seconds -= 1

            if self.remaining_seconds <= 0:
                self.show_reminder()
                self.remaining_seconds = 20 * 60  # 重置计时

    def show_reminder(self):
        """显示提醒窗口"""
        self.root.deiconify()  # 显示窗口
        self.root.attributes('-topmost', True)  # 置于最前

        # 创建提醒界面
        reminder_window = tk.Toplevel(self.root)
        reminder_window.title("该休息了")
        reminder_window.geometry("300x150")

        tk.Label(
            reminder_window,
            text="20分钟已到，请暂停30秒",
            font=('Arial', 12)
        ).pack(pady=20)

        # 按钮框架
        btn_frame = tk.Frame(reminder_window)
        btn_frame.pack(pady=10)

        tk.Button(
            btn_frame,
            text="好的 (30秒)",
            command=lambda: self.handle_response(reminder_window, pause=True)
        ).pack(side=tk.LEFT, padx=10)

        tk.Button(
            btn_frame,
            text="稍后 (继续)",
            command=lambda: self.handle_response(reminder_window, pause=False)
        ).pack(side=tk.LEFT, padx=10)

    def handle_response(self, window, pause):
        """处理用户选择"""
        window.destroy()
        self.root.withdraw()

        if pause:
            self.is_paused = True
            self.show_countdown(30)  # 30秒倒计时
            self.is_paused = False
        else:
            self.remaining_seconds = 20 * 60  # 重置20分钟计时

    def show_countdown(self, seconds):
        """显示倒计时窗口"""
        countdown_window = tk.Toplevel(self.root)
        countdown_window.title("休息中")
        countdown_window.geometry("250x100")
        countdown_window.attributes('-topmost', True)

        label = tk.Label(
            countdown_window,
            text=f"休息倒计时: {seconds}秒",
            font=('Arial', 12)
        )
        label.pack(pady=20)

        def update():
            nonlocal seconds
            seconds -= 1
            label.config(text=f"休息倒计时: {seconds}秒")
            if seconds > 0:
                countdown_window.after(1000, update)
            else:
                countdown_window.destroy()

        update()
        countdown_window.wait_window()  # 阻塞直到窗口关闭

    def show_window(self, icon=None, item=None):
        """显示主窗口"""
        self.root.deiconify()

    def quit_app(self, icon=None, item=None):
        """退出程序"""
        self.tray_icon.stop()
        self.root.quit()
        os._exit(0)

if __name__ == "__main__":
    # 在Windows系统隐藏主窗口
    if sys.platform == 'win32':
        import ctypes
        ctypes.windll.user32.ShowWindow(ctypes.windll.kernel32.GetConsoleWindow(), 0)

    app = FocusReminderApp()
    app.root.mainloop()
