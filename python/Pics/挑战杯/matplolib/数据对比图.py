import matplotlib.pyplot as plt
import numpy as np

plt.rcParams["font.sans-serif"] = ["SimHei"]  # 设置中文字体（根据系统可用字体调整）
plt.rcParams["axes.unicode_minus"] = False  # 解决负号显示问题
# 数据
components = ["黄芩苷", "黄芩素", "汉黄芩苷"]
exp_values = [16.5, 0.82, 5.75]
ctrl_values = [12.8, 0.64, 4.48]
increase_rates = [22.4, 22.0, 22.1]

x = np.arange(len(components))  # 标签位置
width = 0.35  # 柱状图宽度

fig, ax1 = plt.subplots(figsize=(10, 6))
rects1 = ax1.bar(
    x - width / 2, exp_values, width, label="实验组 (mg/g)", color="#5470C6"
)
rects2 = ax1.bar(
    x + width / 2, ctrl_values, width, label="对照组 (mg/g)", color="#91CC75"
)

ax2 = ax1.twinx()
line = ax2.plot(
    x, increase_rates, color="#FAC858", marker="o", linestyle="--", label="提升幅度 (%)"
)

# 添加标签与标题
ax1.set_xlabel("有效成分")
ax1.set_ylabel("含量 (mg/g)")
ax2.set_ylabel("提升幅度 (%)")
ax1.set_title("实验组 vs 对照组有效成分含量对比")
ax1.set_xticks(x)
ax1.set_xticklabels(components)
ax1.legend(loc="upper left")
ax2.legend(loc="upper right")

plt.tight_layout()
plt.savefig("数据对比图.png")
plt.show()
