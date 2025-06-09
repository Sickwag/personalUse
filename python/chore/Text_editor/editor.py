import tkinter as tk
from tkinter import scrolledtext


class TextEditor:
    def __init__(self, root):
        self.root = root
        self.root.title("Gizmos Editor by Sickwag")
        self.text_area = scrolledtext.ScrolledText(
            self.root, wrap=tk.WORD, font=("Arial", 12)
        )
        self.text_area.pack(fill=tk.BOTH, expand=True)
        self.is_source_mode = False
