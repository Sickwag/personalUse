# 让用户输入 3 个单词，用空格分隔
words_input = input("input 3 words, separate with blank:")
words = words_input.split()
reversed_words = [word[::-1] for word in words]
sorted_words = sorted(reversed_words)
print("after sorted:")
for word in sorted_words:
    print(word)
