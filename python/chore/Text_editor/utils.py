import tkinter as tk
from tkinter import filedialog, messagebox, simpledialog
import re


def open_file(text_area):
    file_path = filedialog.askopenfilename(filetypes=[("Text Files", "*.txt")])
    if file_path:
        with open(file_path, "r", encoding="utf-8") as file:
            text_area.delete("1.0", tk.END)
            text_area.insert(tk.END, file.read())


def new_file(text_area):
    text_area.delete("1.0", tk.END)


def find_text(text_area):
    search_term = simpledialog.askstring("Find", "input you want find")
    if search_term:
        content = text_area.get("1.0", tk.END)
        if search_term in content:
            messagebox.showinfo("Search", f"Found : {search_term}")
        else:
            messagebox.showinfo("Find", "No matched")


def replace_text(text_area):
    search_term = simpledialog.askstring("Replace", "input you want replace:")
    if search_term:
        replace_term = simpledialog.askstring("Replace", "input you want replace :")
        if replace_term:
            content = text_area.get("1.0", tk.END)
            new_content = content.replace(search_term, replace_term)
            text_area.delete("1.0", tk.END)
            text_area.insert(tk.END, new_content)
            messagebox.showinfo("Replace", "Done")


def regex_search_replace(text_area):
    pattern = simpledialog.askstring("Replace by regex", "input regex : ")
    if pattern:
        try:
            replace_term = simpledialog.askstring(
                "regex", "input words you want replace:"
            )
            if replace_term:
                content = text_area.get("1.0", tk.END)
                new_content = re.sub(pattern, replace_term, content)
                text_area.delete("1.0", tk.END)
                text_area.insert(tk.END, new_content)
                messagebox.showinfo("replace by regex", "Done")
        except re.error:
            messagebox.showerror("replace by regex", "nonsense regex expression")


def contact_dev():
    messagebox.showinfo("Contact", "Developer's Email: developer@example.com")


def donate():
    messagebox.showinfo("Donate", "Thank you! here is donate link : https://example.com/donate")
