import tkinter as tk
from tkinter import filedialog, messagebox
import easygui
import os


class Menu:
    def __init__(self, root, chat_app, client):
        self.root = root
        self.chat_app = chat_app
        self.client = client  # 将 client 作为成员变量
        self.init_menu()

    def init_menu(self):
        """初始化菜单栏"""
        self.menubar = tk.Menu(self.root)
        self.root.config(menu=self.menubar)

        # 文件菜单
        self.file_menu = tk.Menu(self.menubar, tearoff=0)
        self.menubar.add_cascade(label="File", menu=self.file_menu)
        self.file_menu.add_command(label="Open log file", command=self.open_log_file)
        self.file_menu.add_command(
            label="Set log directory", command=self.set_log_directory
        )
        self.file_menu.add_separator()
        self.file_menu.add_command(label="Exit", command=self.exit_program)

        # 选项菜单
        self.option_menu = tk.Menu(self.menubar, tearoff=0)
        self.menubar.add_cascade(label="Options", menu=self.option_menu)
        self.option_menu.add_command(
            label="Export latest dialog", command=self.export_last_conversation
        )

        # API 设置菜单
        self.api_menu = tk.Menu(self.menubar, tearoff=0)
        self.menubar.add_cascade(label="API Settings", menu=self.api_menu)
        self.api_menu.add_command(label="API key", command=self.set_api_key)

    def open_log_file(self):
        """打开日志文件"""
        log_file_path = "AI_chat_log.txt"
        if not os.path.exists(log_file_path):
            with open(log_file_path, "w", encoding="utf-8") as log_file:
                log_file.write("")
        os.system(f"notepad.exe {log_file_path}")

    def set_log_directory(self):
        """设置日志文件目录"""
        directory = easygui.diropenbox(title="Select your log directory")
        if directory:
            print(f"log directory: {directory}")

    def exit_program(self):
        """退出程序"""
        self.root.quit()

    def export_last_conversation(self):
        """导出最近一次对话"""
        last_conversation = self.chat_app.history_text.get("end-2c", tk.END).strip()
        if last_conversation:
            file_path = filedialog.asksaveasfilename(
                defaultextension=".txt",
                filetypes=[("Text files", "*.txt"), ("All files", "*.*")],
                title="Save dialog",
            )
            if file_path:
                with open(file_path, "w", encoding="utf-8") as file:
                    file.write(last_conversation)
                messagebox.showinfo("Success", "Export success!")
        else:
            messagebox.showwarning("warning", "No log to Export")

    def set_api_key(self):
        """设置 API key"""
        new_api_key = easygui.enterbox("Input your API key:", title="API key")
        if new_api_key:
            self.client.api_key = new_api_key  # 使用成员变量 client
            messagebox.showinfo("Success", "API key 已更新！")
