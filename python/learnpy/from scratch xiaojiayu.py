# import easygui as eg
# import sys
# while 1 :
#     eg.msgbox("first message","first graphic interface window !")
#     # ---------------------------定义变量
#     msg = "what do you want ?"
#     title = "a game waiting on you "
#     choices = ["1.programming", "do math","just have fun"]
#     # -----------------------------------
#     # choice = eg.choicebox(msg,title,choices) # we can define vars in the bracket
#     choice = eg.choicebox(msg=msg,title=title,choices= choices) # we can input argument in formal_arg = var ; or just input real arg
#     # 编译器会在你输入msg时默认弹出msg= ，也就是说choicebox中的参数都是关键字传参位置确定的
#     #---------------------------------定义变量
#     msg = "do you wanna replay the game ?"
#     title = "make you choice"
#     # -----------------------------------------
#     if eg.ccbox(re_msg = msg,re_title= title):
#         #ccbox only return true or false,what you chose decide what you going to do in if statement
#         pass
#     else :
#         sys.exit()

    

# import easygui as eg
# eg.egdemo()

# from easygui import EgStore
# class Settings(EgStore):
#     def __init__(self, filename):
#         self.author = ""
#         self.book_name = ""
#         self.filename = filename #egstore 默认提供了一个filename参数，一般用来匹配__init__函数的第二参数
#         self.restore() # 允许被store的变量通过实例化类来返回“记住的值”

#     settingsFilename = "settings_doc"
#     settings = Settings(settingsFilename)
#     author = "sickwag"
#     book_name = "rookie's self-cultivation"
#     settings.author = author
#     settings.book_name = book_name

    # class test:
#     def print_something(self):
#         print("something out now")
#     def print_no_self():
#         print("this method only can be called by class with no object")

# test.print_no_self()
# # test.print_something() #this line will raise an error
# test.print_something()
# #error no self,no call,print_something doesn't know who call it
# object = test()
# object.print_something()#no error

# class capstr(str):
#     def __new__(cls,string):
#         string = string.upper()
#         return str.__new__(cls,string)
    
# a = capstr("romantic")
# print(a)

# class try_int(int):
#     #定义新的加减运算变为运算两次
#     def __add__(self,other):
#         return self + other + other
#     def __sub__(self,other):
#         return self - other - other

# class new_int(int):
#     def __rsub__(self, value: int) -> int:
#         return int.__sub__(self,value)    
# a = new_int(4)#创建一个值位4的a对象
# print(3-a)
import time as t

class mytime:
    def start(self):
        self.start = t.localtime()  # 获取当前时间并赋值给self.start
        print("now time is going...")

    def stop(self):
        self.stop = t.localtime()   # 获取当前时间并赋值给self.stop
        self._calc()
        print("now time clock is stop")

    def _calc(self):
        self.last = []               # 初始化self.last为一个空列表
        self.prompt = "this program has run "
        for index in range(6):
            # 计算时间差并添加到self.last列表中
            time_diff = self.stop() - self.start()
            self.last.append(time_diff)
            # 将时间差转换为字符串并添加到self.prompt字符串中
            self.prompt += str(time_diff)
        print(self.prompt)

test = mytime()
test.start()
test.stop()

