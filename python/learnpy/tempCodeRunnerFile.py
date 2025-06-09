# Please install OpenAI SDK first: `pip3 install openai`

from openai import OpenAI

client = OpenAI(api_key="sk-de04993332ca49afa7ebc7c383be3d08", base_url="https://api.deepseek.com")

with open('D:\\Code Files\\vscode\\python\\learnpy\\dialog_input.txt','r',encoding='utf-8') as file:
    content = file.read()


response = client.chat.completions.create(
    model="deepseek-chat",
    messages=[
        {"role": "system", "content": "You are a helpful assistant in algorithm , you should answer questions about how to solve an algorithm problem with the the least costly solution with chinese language"},
        {"role": "user", "content": content},
    ],
    stream=False
)

print(response.choices[0].message.content)