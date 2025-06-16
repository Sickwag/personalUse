import matplotlib.pyplot as plt
plt.rcParams["font.sans-serif"] = ["SimHei"]  # 设置中文字体（根据系统可用字体调整）
plt.rcParams["axes.unicode_minus"] = False  # 解决负号显示问题
years = ["2025", "2026", "2027"]
users = [10.8, 26, 50]  # 单位：万人

plt.figure(figsize=(10, 6))
plt.plot(years, users, marker="o", color="#5470C6", linestyle="-", linewidth=2)
plt.xlabel("年份")
plt.ylabel("用户规模（万人）")
plt.title("2025-2027年用户增长预测")
plt.grid(True, linestyle="--", alpha=0.5)
plt.tight_layout()
plt.savefig("用户增长预测图.png")
plt.show()
