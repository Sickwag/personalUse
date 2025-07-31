# history.py

from datetime import datetime
from collections import deque
from constants import HISTORY_FILE_TEMPLATE
import os



def ensure_history_dir():
    history_dir = os.path.dirname(HISTORY_FILE_TEMPLATE.format(""))
    if not os.path.exists(history_dir):
        os.makedirs(history_dir)


def create_history_deque(memory):
    return deque(maxlen=memory * 2)


def log_message(preset_name, role, content):
    ensure_history_dir()
    history_file = HISTORY_FILE_TEMPLATE.format(preset_name)
    with open(history_file, "a", encoding="utf-8") as f:
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        f.write(f"[{timestamp}] {role.upper()} {str(preset_name)}:\n{content}\n{'-'*40}\n")
