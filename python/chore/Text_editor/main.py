import tkinter as tk
from editor import TextEditor
from menu import MenuBar


def main():
    root = tk.Tk()
    editor = TextEditor(root)
    MenuBar(root, editor.text_area)
    root.mainloop()


if __name__ == "__main__":
    main()
