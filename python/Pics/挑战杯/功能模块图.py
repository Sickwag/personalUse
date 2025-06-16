from pyecharts import options as opts
from pyecharts.charts import Graph

nodes = [
    {"name": "核心系统"},
    {"name": "种植管理"},
    {"name": "病虫害识别"},
    {"name": "市场行情"},
    {"name": "药材溯源"},
    {"name": "专家问诊"},
    {"name": "社区交流"},
]

links = [
    {"source": "核心系统", "target": "种植管理"},
    {"source": "核心系统", "target": "病虫害识别"},
    {"source": "核心系统", "target": "市场行情"},
    {"source": "核心系统", "target": "药材溯源"},
    {"source": "核心系统", "target": "专家问诊"},
    {"source": "核心系统", "target": "社区交流"},
]

c = (
    Graph()
    .add("", nodes, links, repulsion=800)
    .set_global_opts(title_opts=opts.TitleOpts(title="灵草慧农APP功能模块关系图"))
)

c.render("功能模块图.html")
