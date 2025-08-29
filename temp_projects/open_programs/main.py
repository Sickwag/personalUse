import webbrowser
import time
import os
import subprocess

apps = {
    "vscode": r"D:\Program\MicrosoftVscode\Microsoft VS Code\Code.exe",
    "wechat": r"D:\Program\Wechat\WeChat.exe",
    "obsidian": r"D:\Obsidian\Obsidian.exe",
    "cherry_studio": r"D:\Program\CherryStudio\Cherry Studio\Cherry Studio.exe",
    "vutron_music": r"D:\Program\VutronMusic\VutronMusic.exe"
}

urls = [
    "https://chat.qwen.ai/", # "qwen-ai" : 
    "https://chat.deepseek.com/" # "deepseek" : 
]

use_chrome = False
chrome_path = r"C:\Program Files\Google\Chrome\Application\chrome.exe"

delay_between_apps = 1
delay_before_urls = 2

edge_paths = [
    r"C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe",
    r"C:\Program Files\Microsoft\Edge\Application\msedge.exe",  # 常见路径
    r"C:\Users\%USERNAME%\AppData\Local\Microsoft\Edge\Application\msedge.exe"
]

def find_edge_path():
    for path in edge_paths:
        expanded_path = os.path.expandvars(path)  # 处理 %USERNAME%
        if os.path.exists(expanded_path):
            return expanded_path
    return None

def open_app_windows(path):
    if os.path.exists(path):
        subprocess.Popen([path])
        print(f"start: {path}")
    else:
        print(f"cannot found path: {path}")

def open_urls_in_edge():
    edge_path = find_edge_path()
    if not edge_path:
        print("edge path not found, check your script.")
        return

    print(f"Edge found: {edge_path}")

    first_url = urls[0]
    subprocess.Popen([edge_path, first_url])
    print(f"open: {first_url}")

    time.sleep(2)

    for url in urls[1:]:
        subprocess.Popen([edge_path, "--new-tab", url])
        print(f"new tab: {url}")
        time.sleep(0.5)

def other_command():
    result = subprocess.run("api", shell=True, capture_output=True,text=True,executable="powershell")
    print(result.stdout)

def main():
    print("start process.")
    other_command()
    system = os.name
    is_windows = (system == 'nt')

    for name, path in apps.items():
        if is_windows:
            open_app_windows(path)
        time.sleep(delay_between_apps)

    open_urls_in_edge()
    print("done.")

if __name__ == "__main__":
    main()