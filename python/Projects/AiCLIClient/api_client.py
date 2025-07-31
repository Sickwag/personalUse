# api_client.py

import requests
import json
from colorama import Fore


def send_api_request(api_key, base_url, model, messages, temperature):
    headers = {
        "Content-Type": "application/json",
        "Authorization": f"Bearer {api_key}",
        "HTTP-Referer": "http://localhost",
        "X-Title": "CLI AI Tool",
    }

    payload = {
        "model": model,
        "messages": messages,
        "temperature": temperature,
        "stream": True,
    }

    response = requests.post(base_url, headers=headers, json=payload, stream=True)
    response.raise_for_status()

    ai_response = ""
    # set stream output
    for chunk in response.iter_lines():
        if chunk:
            decoded = chunk.decode("utf-8")
            if decoded.startswith("data: "):
                data_str = decoded[6:]
                if data_str.strip() == "[DONE]":
                    break
                try:
                    data = json.loads(data_str)
                    content = (
                        data.get("choices", [{}])[0].get("delta", {}).get("content", "")
                    )
                    if content:
                        print(f"{Fore.CYAN}{content}", end="", flush=True)
                        ai_response += content
                except (json.JSONDecodeError, IndexError):
                    pass
    return ai_response
