from pyecharts import options as opts
from pyecharts.charts import Line

years = ["2025", "2026", "2027"]
income = [736, 1850, 3200]  # 收入（万元）
profit = [336, 925, 1760]  # 净利润（万元）
roi = [84, 148, 190]  # ROI (%)

line = (
    Line()
    .add_xaxis(years)
    .add_yaxis("收入/净利润 (万元)", income, color="#5470C6")
    .add_yaxis("净利润 (万元)", profit, color="#91CC75")
    .extend_axis(yaxis=opts.AxisOpts(name="ROI (%)", type_="value", min_=0, max_=200))
    .set_global_opts(
        title_opts=opts.TitleOpts(title="成本收益比分析图"),
        yaxis_opts=opts.AxisOpts(name="金额（万元）"),
    )
)

line2 = (
    Line().add_xaxis(years).add_yaxis("ROI (%)", roi, color="#FAC858", yaxis_index=1)
)

line.overlap(line2).render("成本收益比分析图.html")
