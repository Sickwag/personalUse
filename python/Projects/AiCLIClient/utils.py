# utils.py

import sys
from colorama import Fore


def multiline_input(prompt=""):
    print(prompt, end="")
    lines = []
    while True:
        try:
            line = input()
            lines.append(line)
        except KeyboardInterrupt:
            return None
        if line.endswith("\\"):
            lines[-1] = lines[-1][:-1]  # 去掉反斜杠
        else:
            break
    return "\n".join(lines).strip()


def print_thinking():
    sys.stdout.write(f"{Fore.YELLOW}AI thinking..\r")
    sys.stdout.flush()


def clear_thinking():
    sys.stdout.write(" " * 20 + "\r")
    sys.stdout.flush()
