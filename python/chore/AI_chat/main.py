import tkinter as tk
from chat import ChatApp
from menu import Menu
from openai import OpenAI

# 全局变量
client = OpenAI(
    api_key="sk-9Rpyk7MGABNVVnDZfLHqrHYogU1cv7A5qgm3nFNAKg9eJzNd",
    base_url="https://api.moonshot.cn/v1",
)

history = [
    {
        "role": "system",
        "content": "You are an intelligent artificial intelligence. You are good at solving various algorithm problems and problems in the computer field. You can accurately answer the questions raised by users. You are better at the dialogue between Chinese and English. Users may send texts in the format of: topic requirements-solutions to enable you to analyze errors in the algorithm or to give you what you think is the optimal solution to the algorithm problem. You generally answer the questions raised by users in Chinese and answer question in an elegant without losing accuracy, concise and refined without missing the main points.",
    }
]


def chat(query, history):
    """main chat process"""
    history.append({"role": "user", "content": query})
    completion = client.chat.completions.create(
        model="moonshot-v1-8k",
        messages=history,
        temperature=0.3,
    )
    result = completion.choices[0].message.content
    history.append({"role": "assistant", "content": result})
    return result


if __name__ == "__main__":
    root = tk.Tk()
    app = ChatApp(root, chat, history)
    menu = Menu(root, app, client)  # 将 client 传递给 Menu
    root.mainloop()
