from pyecharts import options as opts
from pyecharts.charts import Bar, Line

# 数据
components = ["黄芩苷", "黄芩素", "汉黄芩苷"]
exp_values = [16.5, 0.82, 5.75]
ctrl_values = [12.8, 0.64, 4.48]
increase_rates = [22.4, 22.0, 22.1]

bar = (
    Bar()
    .add_xaxis(components)
    .add_yaxis("实验组 (mg/g)", exp_values, color="#5470C6")
    .add_yaxis("对照组 (mg/g)", ctrl_values, color="#91CC75")
    .extend_axis(
        yaxis=opts.AxisOpts(name="提升幅度 (%)", type_="value", min_=0, max_=30)
    )
    .set_global_opts(
        title_opts=opts.TitleOpts(title="实验组 vs 对照组有效成分含量对比"),
        yaxis_opts=opts.AxisOpts(name="含量 (mg/g)"),
    )
)

line = (
    Line()
    .add_xaxis(components)
    .add_yaxis(
        "提升幅度 (%)", increase_rates, color="#FAC858", yaxis_index=1, is_smooth=True
    )
)

bar.overlap(line).render("数据对比图.html")
