from pyecharts import options as opts
from pyecharts.charts import Line

years = ["2025", "2026", "2027"]
users = [10.8, 26, 50]  # 单位：万人

line = (
    Line()
    .add_xaxis(years)
    .add_yaxis("用户规模 (万人)", users, is_smooth=True)
    .set_global_opts(
        title_opts=opts.TitleOpts(title="2025-2027年用户增长预测"),
        yaxis_opts=opts.AxisOpts(name="用户规模（万人）"),
        xaxis_opts=opts.AxisOpts(name="年份"),
    )
)

line.render("用户增长预测图.html")
