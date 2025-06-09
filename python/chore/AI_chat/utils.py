import re
import tkinter as tk


def render_markdown(text_widget, text):
    """渲染 Markdown 内容到 Text 组件"""
    # 处理加粗：**text**
    bold_text = re.findall(r"\*\*(.*?)\*\*", text)
    for match in bold_text:
        text = text.replace(f"**{match}**", f"{match}")
        text_widget.insert(tk.END, match, "bold")

    # 处理斜体：*text*
    italic_text = re.findall(r"\*(.*?)\*", text)
    for match in italic_text:
        text = text.replace(f"*{match}*", f"{match}")
        text_widget.insert(tk.END, match, "italic")

    # 插入剩余的普通文本
    text_widget.insert(tk.END, text)

    # 添加换行符
    text_widget.insert(tk.END, "\n")
