import matplotlib.pyplot as plt


years = ["2025", "2026", "2027"]
income = [736, 1850, 3200]  # 收入（万元）
profit = [336, 925, 1760]  # 净利润（万元）
roi = [84, 148, 190]  # ROI (%)

fig, ax1 = plt.subplots(figsize=(10, 6))
plt.rcParams["font.sans-serif"] = ["SimHei"]  # 设置中文字体（根据系统可用字体调整）
plt.rcParams["axes.unicode_minus"] = False  # 解决负号显示问题

# 左轴：收入和净利润
ax1.plot(years, income, label="收入 (万元)", color="#5470C6", marker="o")
ax1.plot(years, profit, label="净利润 (万元)", color="#91CC75", marker="s")
ax1.set_xlabel("年份")
ax1.set_ylabel("金额（万元）")
ax1.tick_params(axis="y")

# 右轴：ROI
ax2 = ax1.twinx()
ax2.plot(years, roi, label="ROI (%)", color="#FAC858", marker="^", linestyle="--")
ax2.set_ylabel("ROI (%)")

# 图例合并
lines, labels = ax1.get_legend_handles_labels()
lines2, labels2 = ax2.get_legend_handles_labels()
ax1.legend(lines + lines2, labels + labels2, loc="upper left")

plt.title("成本收益比分析图")
plt.tight_layout()
plt.savefig("成本收益比分析图.png")
plt.show()
