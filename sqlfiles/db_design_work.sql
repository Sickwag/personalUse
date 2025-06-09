-- 创建数据库
USE master;
GO

CREATE DATABASE kehudingdandengjisystem
ON 
( NAME = kehudingdandengjisystem_data,
  FILENAME = 'd:\kehudingdandengjisystem.mdf',
  SIZE = 10MB,
  MAXSIZE = 50MB,
  FILEGROWTH = 5MB )
LOG ON
( NAME = kehudingdandengjisystem_log,
  FILENAME = 'd:\kehudingdandengjisystem.ldf',
  SIZE = 5MB,
  MAXSIZE = 25MB,
  FILEGROWTH = 5MB );
GO

--客户表建立:
CREATE TABLE clients(
cno  char (10)  NOT NULL  primary key,
cname  char (20)  NOT NULL ,
csex  char(2), 
cage  smallint,
ctel  char (11)  NOT NULL ,
cadress  char(100)  )


--产品表建立:
CREATE TABLE product(
pno  char (10)  NOT NULL primary key ,
pname  char (20)  NOT NULL ,
pmodel  char (8)  NOT NULL ,
pnorm  char (10)  NOT NULL ,
pprice  char (20)  NOT NULL ,
ptotal  char(50)  NOT NULL )

--员工表建立:
CREATE TABLE  clerks(
clerkno  char (20)  NOT NULL  primary key,
clerkname  char (20)  NOT NULL ,
clerksex  char(2), 
clerkage  smallint,
clerktel  char (11)  NOT NULL ,
clerkadress  char(100) )

--订单表建立:
CREATE TABLE lists(
lno  char (10) NOT NULL ,
cno  char (10) NOT NULL ,
pno  char (10)  NOT NULL,
lnumber  int NOT NULL,
ldate  datetime,
clerkno char(20) NOT NULL,
primary key(lno,cno,pno,clerkno),
foreign key (cno) REFERENCES clients(cno),
foreign key (pno) REFERENCES product(pno),
foreign key (clerkno) REFERENCES  clerks(clerkno))




--2、数据初始化：
--将客户信息  加入表client 中
INSERT INTO clients(cno, cname, csex, cage, ctel, cadress)
VALUES 
('1001', '叶宇', '女', '20', '15625475825', '宝鸡市'),
('1002', '芳芳', '女', '32', '13941684569', '西安市'),
('1003', '陆楠', '男', '22', '16359626595', '北京'),
('1004', '围时', '男', '36', '13541696246', '黑龙江'),
('1005', '周镇', '男', '52', '14256335633', '甘肃'),
('1006', '齐涛', '男', '33', '13558954598', '汉中'),
('1007', '夏玲', '女', '25', '13645259974', '广西'),
('1008', '一一', '女', '20', '13542695266', '广东'),
('1010', '陈东', '男', '20', '13455445541', '西安');


-- 将产品信息加入产品表中
INSERT INTO product(pno, pname, pmodel, pnorm, pprice, ptotal)
VALUES 
('C02', '玩具猫', '13', '小', '38', '655'),
('C03', '玩具长颈鹿','12', '大', '69', '600'),
('C12', '玩具狗', '10', '小', '20', '500'),
('C18', '玩具老虎','16', '大', '59', '750'),
('C35', '玩具猪','20', '中', '110', '360'),
('C53', '玩具熊','18', '大', '100', '360'),
('C98', '玩具蛇','30', '中', '45', '200');

-- 将订单信息加入订单表中
ALTER TABLE lists
DROP CONSTRAINT FK__lists__pno__320C68B7;

INSERT INTO lists(lno, cno, pno, lnumber, ldate, clerkno)
VALUES 
('1001', '1001', 'C12', '200', '2007-12-10', '001'),
('1002', '1003', 'C01', '300', '2008-10-02', '002'),
('1003', '1005', 'C53', '200', '2008-02-20', '006'),
('1004', '1004', 'C35', '340', '2008-10-10', '003'),
('1005', '1002', 'C18', '200', '2007-11-01', '005'),
('1006', '1006', 'C98', '100', '2007-04-10', '008'),
('1007', '1007', 'C02', '120', '2008-02-20', '007'),
('1008', '1005', 'C02', '140', '2008-02-20', '008');


ALTER TABLE lists
ADD CONSTRAINT fk_lists_product 
FOREIGN KEY (pno) 
REFERENCES product(pno); 


 -- 修复了clerkno的值
-- 将员工信息加入员工表中
INSERT INTO clerks(clerkno, clerkname, clerksex, clerkage, clerktel, clerkadress)
VALUES 
('001', '赵军', '男', 26, '13314587954', '湖南长沙'),
('002', '小强', '男', 30, '15825454555', '宝鸡'),
('003', '张在', '男', 32, '15652225548', '宝鸡'),
('004', '沙沙', '女', 34, '13456899755', '西安'),
('005', '赵刚', '男', 42, '13856784122', '渭南'),
('006', '叶云', '女', 23, '15924566665', '榆林'),
('007', '刘建', '男', 38, '15154656644', '韩城'),
('008', '陈风', '女', 24, '15823456878', '西安');
