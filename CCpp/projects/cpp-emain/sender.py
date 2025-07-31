import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication

# 发件人和收件人信息
# sender_email = "3540825116@qq.com"
sender_email = "AzzatoWaydell@126.com"
receiver_email = "Sickwag@outlook.com"
# 注意：这里需要填写126邮箱的授权码，而不是登录密码
# 请在126邮箱设置中开启SMTP服务并获取授权码
password = "HRUyUsZP3RwgnFz4"  # 请替换为实际的授权码

# 创建邮件
message = MIMEMultipart()
message["From"] = sender_email
message["To"] = receiver_email
message["Subject"] = "带附件的邮件示例"

# 添加邮件正文
message.attach(MIMEText("这是一封带附件的邮件。", "plain"))

# 添加附件
with open("附件文件.txt", "rb") as attachment:
    part = MIMEApplication(attachment.read(), Name="附件文件.txt")
    part["Content-Disposition"] = f'attachment; filename="附件文件.txt"'
    message.attach(part)

# 连接到SMTP服务器并发送邮件
try:
    with smtplib.SMTP("smtp.126.com", 25) as server:
        server.starttls()
        server.login(sender_email, password)
        server.sendmail(sender_email, receiver_email, message.as_string())
    print("带附件的邮件已发送成功！")
except smtplib.SMTPAuthenticationError:
    print("认证失败：请检查邮箱地址和授权码是否正确，并确认已在126邮箱设置中开启SMTP服务")
except smtplib.SMTPException as e:
    print(f"发送邮件时出错：{e}")
except Exception as e:
    print(f"发生未知错误：{e}")
