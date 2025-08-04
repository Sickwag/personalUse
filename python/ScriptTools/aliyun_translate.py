# 阿里云翻译组件，no_args仅供别的文件使用
from alibabacloud_tea_openapi import models as open_api_models
from alibabacloud_alimt20181012.client import Client as AlimtClient
from alibabacloud_alimt20181012 import models as alimt_models


class AliyunTranslator:
    def __init__(
        self,
        source_language: str,
        target_language: str,
        access_key_id: str = "LTAI5tLynqGJ5mRv5zPJTihz",
        access_key_secret: str = "DV1HN5IOo89H0Ib1wC4ZXnYK8rYiwo",
    ):
        """
        初始化翻译器

        :param source_language: 源语言代码（如 "en"）
        :param target_language: 目标语言代码（如 "zh"）
        :param access_key_id: 阿里云AccessKey ID（建议从环境变量读取）
        :param access_key_secret: 阿里云AccessKey Secret（建议从环境变量读取）
        """
        self.source_language = source_language
        self.target_language = target_language
        self.access_key_id = access_key_id
        self.access_key_secret = access_key_secret

        # 初始化阿里云客户端
        self.client = self._create_client()

    def _create_client(self) -> AlimtClient:
        """创建阿里云翻译服务客户端"""
        config = open_api_models.Config(
            access_key_id=self.access_key_id, access_key_secret=self.access_key_secret
        )
        config.endpoint = "mt.aliyuncs.com"
        return AlimtClient(config)

    def render(self, text: str) -> str:
        """
        执行翻译

        :param text: 需要翻译的文本
        :return: 翻译结果字符串
        """
        request = alimt_models.TranslateGeneralRequest(
            format_type="text",
            source_language=self.source_language,
            target_language=self.target_language,
            source_text=text,
            scene="general",
        )
        try:
            response = self.client.translate_general(request)
            return str(response.body.data.translated)
        except Exception as e:
            raise RuntimeError(f"翻译请求失败: {str(e)}")

    def __call__(self, text: str) -> str:
        """支持直接实例调用，等价于render方法"""
        return self.render(text)


# 保留原有独立函数功能（可选）
def output_result(
    source_text="你好，世界！",
    source_language="zh",
    target_language="en",
    access_key_id="LTAI5tLynqGJ5mRv5zPJTihz",
    access_key_secret="DV1HN5IOo89H0Ib1wC4ZXnYK8rYiwo",
) -> str:
    """兼容旧版本的独立函数"""
    translator = AliyunTranslator(
        source_language=source_language,
        target_language=target_language,
        access_key_id=access_key_id,
        access_key_secret=access_key_secret,
    )
    return translator.render(source_text)


if __name__ == "__main__":
    # 测试示例
    translator = AliyunTranslator(source_language="en", target_language="zh")
    print(translator("Hello world"))  # 使用__call__
    print(translator.render("This is a test"))  # 使用render方法
