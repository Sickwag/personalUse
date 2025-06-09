import tkinter as tk
# from tkinter import messagebox, filedialog
from utils import (
    open_file,
    new_file,
    find_text,
    replace_text,
    regex_search_replace,
    contact_dev,
    donate,
)


class MenuBar:
    def __init__(self, root, text_area):
        self.root = root
        self.text_area = text_area
        self.menu_bar = tk.Menu(self.root)
        self.root.config(menu=self.menu_bar)

        # 文件菜单
        self.file_menu = tk.Menu(self.menu_bar, tearoff=0)
        self.menu_bar.add_cascade(label="File", menu=self.file_menu)
        self.file_menu.add_command(
            label="Open", command=lambda: open_file(self.text_area)
        )
        self.file_menu.add_command(
            label="New file", command=lambda: new_file(self.text_area)
        )
        self.file_menu.add_separator()
        self.file_menu.add_command(label="Exit", command=self.root.quit)

        # 选项菜单
        self.option_menu = tk.Menu(self.menu_bar, tearoff=0)
        self.menu_bar.add_cascade(label="Tools", menu=self.option_menu)
        self.option_menu.add_command(
            label="Find", command=lambda: find_text(self.text_area)
        )
        self.option_menu.add_command(
            label="Replace", command=lambda: replace_text(self.text_area)
        )
        self.option_menu.add_command(
            label="Replace with regex", command=lambda: regex_search_replace(self.text_area)
        )
        self.source_mode_var = tk.BooleanVar()

        # 帮助菜单
        self.help_menu = tk.Menu(self.menu_bar, tearoff=0)
        self.menu_bar.add_cascade(label="Help", menu=self.help_menu)
        self.help_menu.add_command(label="Contact us", command=contact_dev)
        self.help_menu.add_command(label="Donate", command=donate)
