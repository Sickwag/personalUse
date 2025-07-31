# main.py
import sys
import os
from colorama import Fore, init
from args import parse_args
from config import PRESETS
from constants import HISTORY_FILE_TEMPLATE, CONFIG_DIR
from conversation import run_conversation
from history import create_history_deque, log_message


# 初始化颜色
init(autoreset=True)
def list_config():
    print(f"{Fore.CYAN}presettings")
    for name, preset in PRESETS.items():
        print(f"{Fore.YELLOW}preset model: {name}")
        print(f"  name: {preset['name']}")
        print(f"  model: {preset['model']}")
        print(f"  API url: {preset['base_url']}")
        print("-" * 40)


def open_history_file(preset_name):
    history_file = HISTORY_FILE_TEMPLATE.format(preset_name)
    if not os.path.exists(history_file):
        print(f"{Fore.RED}error, log file not exist {history_file}")
        return
    os.system(f'code "{history_file}"')

def edit_config_file():
    config_file = CONFIG_DIR
    if not os.path.exists(config_file):
        print(f"{Fore.RED}error, log file not exist {config_file}")
        return
    os.system(command=f'code "{config_file}"')


def main():
    args = parse_args()

    if args.list_config:
        list_config()
        sys.exit(0)

    if args.history:
        open_history_file(args.history or PRESETS["default"]["name"])
        sys.exit(0)

    if args.edit_config:
        edit_config_file()
        sys.exit(0)
    
    preset_name = args.preset or "default"
    if preset_name not in PRESETS:
        print(f"{Fore.RED}error, preset '{preset_name}' not exist.")
        sys.exit(1)

    preset = PRESETS[preset_name]

    preset = {
        "name": preset["name"],
        "api": args.api or preset["api"],
        "base_url": args.base_url or preset["base_url"],
        "model": args.model or preset["model"],
    }

    if not preset["api"]:
        print(f"{Fore.RED}error, need api_key preset")
        sys.exit(1)

    history = create_history_deque(args.memory)

    run_conversation(preset, args, history)


if __name__ == "__main__":
    main()
