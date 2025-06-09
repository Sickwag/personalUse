import tkinter as tk
from tkinter import scrolledtext
# import re
from utils import render_markdown
import os
import datetime


class ChatApp:
    def __init__(self, root, chat_func, history):
        self.root = root
        self.chat_func = chat_func
        self.history = history
        self.content = ""
        self.output_message = ""
        self.role = "User"
        self.root.title("Simple Chatting")
        self.root.geometry("400x500")

        # 初始化界面
        self.init_ui()
        self.check_log_file()

    def init_ui(self):
        """初始化用户界面"""
        # 聊天历史显示框
        self.history_frame = tk.Frame(self.root)
        self.history_frame.pack(fill=tk.BOTH, expand=True)
        self.history_text = scrolledtext.ScrolledText(
            self.history_frame, wrap=tk.WORD, state="disabled"
        )
        self.history_text.pack(fill=tk.BOTH, expand=True)

        # 初始化样式
        self.history_text.tag_config("role_user", background="lightblue", font=("Arial", 10, "bold"))
        self.history_text.tag_config("role_assistant", background="lightgreen", font=("Arial", 10, "bold"))
        self.history_text.tag_config("center", justify="center")

        # 输入框和发送按钮
        self.input_frame = tk.Frame(self.root)
        self.input_frame.pack(fill=tk.X)
        self.input_entry = tk.Entry(self.input_frame)
        self.input_entry.pack(side=tk.LEFT, fill=tk.X, expand=True)
        self.input_entry.focus()

        self.send_button = tk.Button(self.input_frame, text="Send", command=self.send_message)
        self.send_button.pack(side=tk.LEFT)

        # 绑定回车键
        self.input_entry.bind("<Return>", lambda event: self.send_message())

    def check_log_file(self):
        log_file_path = "AI_chat_log.txt"
        if os.path.exists(log_file_path) and os.path.getsize(log_file_path) > 0:
            with open(log_file_path, "r", encoding="utf-8") as log_file:
                lines = log_file.readlines()
                if lines:
                    last_log_time = lines[-2].split(": ")[0]
                    self.display_message(
                        f"the latest chat time point {last_log_time}", center=True
                    )

    def send_message(self):
        if self.role == "User":
            message = self.input_entry.get()
            if message:
                self.content = message
                self.display_message(message)
                self.input_entry.delete(0, tk.END)
                self.toggle_role() 

                self.waiting_message_id = self.display_message(
                    "Waiting for AI answer...", role="Assistant"
                )

                self.root.after(100, lambda: self.get_ai_response(message))

    def get_ai_response(self, message):
        self.output_message = self.chat_func(message, self.history)

        self.history_text.config(state="normal")
        self.history_text.delete(self.waiting_message_id)
        self.history_text.config(state="disabled")

        self.display_message(self.output_message, role="Assistant")
        self.write_log()

        self.toggle_role()

    def display_message(self, message, role=None, center=False):
        self.history_text.config(state="normal")
        if role is None:
            role = self.role

        # 添加角色名称（带背景色）
        self.history_text.insert(tk.END, f"{role}: ", f"role_{role.lower()}")

        # 渲染 Markdown 内容
        render_markdown(self.history_text, message)

        # 添加换行符
        self.history_text.insert(tk.END, "\n")

        if center:
            self.history_text.tag_add("center", "end-2c", "end-1c")

        self.history_text.config(state="disabled")
        self.history_text.yview(tk.END)

        return self.history_text.index(tk.END)

    def toggle_role(self):
        """切换用户和助理角色"""
        self.role = "Assistant" if self.role == "User" else "User"

    def write_log(self):
        """将对话写入日志文件"""
        current_time = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        with open("AI_chat_log.txt", "a", encoding="utf-8") as log_file:
            log_file.write(f"{current_time}: {self.role} - {self.content}\n")
            log_file.write(f"{current_time}: Assistant - {self.output_message}\n")
            log_file.write("\n")
