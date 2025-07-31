import argparse


def parse_args():
    parser = argparse.ArgumentParser(description="CLI AI client")
    parser.add_argument("-m", "--model", type=str, help="point to LLM ID")
    parser.add_argument("-a", "--api", type=str, help="set api_key")
    parser.add_argument("-b", "--base-url", type=str, help="set API base URL")
    parser.add_argument("--preset", type=str, help="use preset config")
    parser.add_argument("--list-config", action="store_true", help="display preset config")
    parser.add_argument("--edit-config", action="store_true",help="open config file by vscode")
    parser.add_argument("--history", type=str, help="open certain chat-log file by vscode(such as:--history default)")
    parser.add_argument(
        "-t", "--temperature", type=float, default=0.7, help="LLM temperature, default = 0.7"
    )
    parser.add_argument("--prompt", type=str, default="", help="Resident prompt reminder")
    parser.add_argument(
        "--init-prompt",
        type=str,
        default="You are a helpful assistant.",
        help="init first prompt",
    )
    parser.add_argument("--memory", type=int, default=15, help="dialog rounds in memory default = 15")
    return parser.parse_args()
