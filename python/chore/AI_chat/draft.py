# original file
import tkinter as tk
from tkinter import filedialog, messagebox, scrolledtext
from openai import OpenAI
import datetime
import easygui
import os

client = OpenAI(
    api_key="sk-9Rpyk7MGABNVVnDZfLHqrHYogU1cv7A5qgm3nFNAKg9eJzNd",
    base_url="https://api.moonshot.cn/v1",
)

history = [
    {
        "role": "system",
        "content": "You are an intelligent artificial intelligence. You are good at solving various algorithm problems and problems in the computer field. You can accurately answer the questions raised by users. You are better at the dialogue between Chinese and English. Users may send texts in the format of: topic requirements-solutions to enable you to analyze errors in the algorithm or to give you what you think is the optimal solution to the algorithm problem. You generally answer the questions raised by users in Chinese and answer question in an elegant without losing accuracy, concise and refined without missing the main points.",
    }
]


def chat(query, history):
    history.append({"role": "user", "content": query})
    completion = client.chat.completions.create(
        model="moonshot-v1-8k",
        messages=history,
        temperature=0.3,
        # stream=True
    )
    result = completion.choices[0].message.content
    history.append({"role": "assistant", "content": result})
    return result


class Menu:
    def __init__(self, root, chat_app):
        self.root = root
        self.chat_app = chat_app

        # 创建菜单栏
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
        self.streaming_menu = tk.Menu(self.api_menu, tearoff=0)
        self.api_menu.add_cascade(label="Streaming", menu=self.streaming_menu)
        self.streaming_menu.add_command(label="enable", command=self.enable_streaming)
        self.streaming_menu.add_command(label="disable", command=self.disable_streaming)

    def open_log_file(self):
        # 使用 Windows 自带的记事本打开日志文件
        log_file_path = "AI_chat_log.txt"
        if os.path.exists(log_file_path):
            os.system(f"notepad.exe {log_file_path}")
        else:
            messagebox.showwarning("warning", "Log file does't exist")

    def set_log_directory(self):
        # 使用 easygui 让用户选择日志文件存储目录
        directory = easygui.diropenbox(title="Select your log directory")
        if directory:
            # 假设这里需要将目录路径存储到某个配置文件或全局变量中
            print(f"log directory: {directory}")

    def exit_program(self):
        self.root.quit()

    def export_last_conversation(self):
        # 导出最近一次对话
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
        # 使用 easygui 获取用户输入的 API key
        new_api_key = easygui.enterbox("Input your API key:", title="API key")
        if new_api_key:
            client.api_key = new_api_key
            messagebox.showinfo("Success", "API key 已更新！")

    def enable_streaming(self):
        # 开启流式传输
        # client.streaming = True
        messagebox.showinfo("Success", "Streaming enable")

    def disable_streaming(self):
        # 关闭流式传输
        # client.streaming = False
        messagebox.showinfo("Success", "Streaming disable")


class ChatApp:
    def __init__(self, root):
        self.root = root
        self.content = ""
        self.output_message = ""
        self.root.title("Simple Chatting")
        self.root.geometry("400x500")

        # 初始化角色，默认从 "User" 开始
        self.role = "User"

        # 创建显示框（聊天历史）
        self.history_frame = tk.Frame(self.root)
        self.history_frame.pack(fill=tk.BOTH, expand=True)
        self.history_text = scrolledtext.ScrolledText(
            self.history_frame, wrap=tk.WORD, state="disabled"
        )
        self.history_text.pack(fill=tk.BOTH, expand=True)

        # 创建输入框和发送按钮
        self.input_frame = tk.Frame(self.root)
        self.input_frame.pack(fill=tk.X)
        self.input_entry = tk.Entry(self.input_frame)
        self.input_entry.pack(side=tk.LEFT, fill=tk.X, expand=True)
        self.input_entry.focus()  # 默认聚焦到输入框

        self.send_button = tk.Button(
            self.input_frame, text="sent", command=self.send_message
        )
        self.send_button.pack(side=tk.LEFT)

        # 绑定按键事件
        self.input_entry.bind("<Return>", lambda event: self.send_message())

    def send_message(self):
        if self.role == "User":
            message = self.input_entry.get()
            if message:
                self.content = message
                self.display_message(message)
                self.input_entry.delete(0, tk.END)  # 清空输入框
                self.toggle_role()  # 切换角色
                self.output_message = chat(self.content, history)
                self.display_message(message=self.output_message)

    def display_message(self, message):
        # 在显示框中显示消息
        self.history_text.config(state="normal")
        self.history_text.insert(tk.END, f"{self.role}: {message}\n")
        self.history_text.config(state="disabled")
        self.history_text.yview(tk.END)  # 滚动到最底部

    def toggle_role(self):
        # 切换角色：User 和 Assistant 交替
        self.role = "Assistant" if self.role == "User" else "User"

    import datetime


def write_log(self):
    # 获取当前系统时间
    current_time = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    # 打开日志文件，文件名为 "AI_chat_log"，以追加模式打开
    with open("AI_chat_log.txt", "a", encoding="utf-8") as log_file:
        # 写入用户输入的内容
        log_file.write(f"{current_time}: {self.role} - {self.content}\n")
        # 写入AI的回答
        log_file.write(f"{current_time}: Assistant - {self.output_message}\n")
        # 添加换行符分隔每次对话
        log_file.write("\n")


if __name__ == "__main__":
    root = tk.Tk()
    app = ChatApp(root)
    menu = Menu(root, app)
    root.mainloop()
