# conversation.py

from colorama import Fore
from utils import multiline_input, print_thinking, clear_thinking
from history import log_message
from api_client import send_api_request


def run_conversation(preset, args, history):
    preset_name = preset["name"]
    api_key = preset["api"]
    base_url = preset["base_url"]
    model = preset["model"]
    temperature = args.temperature

    print(
        f"{Fore.CYAN}AI assistant start up(preset: {preset_name} | model: {model}, input 'exit()' to exit."
    )
    print("-" * 40)

    while True:
        user_input = multiline_input(f"{Fore.GREEN}You: ")
        if user_input is None:
            continue
        if user_input.lower() == "exit()":
            print(f"{Fore.CYAN} conversation over.")
            break
        if not user_input.strip():
            continue

        log_message(preset_name, "user", user_input)
        history.append({"role": "user", "content": user_input})

        print(f"{Fore.CYAN}AI({preset_name} - {model}): ", end="", flush=True)
        print_thinking()

        try:
            ai_response = send_api_request(
                api_key=api_key,
                base_url=base_url,
                model=model,
                messages=list(history),
                temperature=temperature,
            )
            clear_thinking()

            if ai_response:
                print()
                history.append({"role": "assistant", "content": ai_response})
                log_message(preset_name, "assistant", ai_response)

        except Exception as e:
            print(f"\n{Fore.RED}error：{e}")
