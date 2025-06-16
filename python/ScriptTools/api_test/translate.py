from aliyun_translate import AliyunTranslator

def main():
    translator = AliyunTranslator(source_language="en", target_language="zh")
    plain_text = "this is a test text"
    output:str = translator.render(plain_text)
    print(output)

if __name__ == "__main__":
    main()