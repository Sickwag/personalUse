# config.py

PRESETS = {
    "default": {
        "name": "or-ds",
        "api": "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",
        "base_url": "https://openrouter.ai/api/v1/chat/completions",
        "model": "deepseek/deepseek-chat:free",
    },
    "qwen": {
        "name": "or-qwen",
        "api": "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",
        "base_url": "https://openrouter.ai/api/v1/chat/completions",
        "model": "qwen/qwen3-235b-a22b:free",
    },
    "moonshot": {
        "name": "or-ms-k2",
        "api": "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",
        "base_url": "https://openrouter.ai/api/v1/chat/completions",
        "model": "moonshotai/kimi-k2:free",
    },
}
