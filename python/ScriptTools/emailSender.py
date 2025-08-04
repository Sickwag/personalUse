# email sender 硬编码版
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication


def send_mail(sender_email, receiver_email, sender_password):
    # 创建邮件
    message = MIMEMultipart()
    message["From"] = sender_email
    message["To"] = receiver_email
    message["Subject"] = "带附件的邮件示例"

    # 添加邮件正文
    message.attach(MIMEText("这是一封带附件的邮件。", "plain"))

    # 添加附件
    with open("E:\\file_storage\\常用图片\\脚本属性页.png", "rb") as attachment:
        part = MIMEApplication(attachment.read(), Name="附件文件.png")
        part["Content-Disposition"] = 'attachment; filename="附件文件.png"'
        message.attach(part)

    # 连接到SMTP服务器并发送邮件
    try:
        with smtplib.SMTP("smtp.126.com", 25) as server:
            server.starttls()
            server.login(sender_email, sender_password)
            server.sendmail(sender_email, receiver_email, message.as_string())
        print("带附件的邮件已发送成功！")
    except smtplib.SMTPAuthenticationError:
        print(
            "认证失败：请检查邮箱地址和授权码是否正确，并确认已在126邮箱设置中开启SMTP服务"
        )
    except smtplib.SMTPException as e:
        print(f"发送邮件时出错：{e}")
    except Exception as e:
        print(f"发生未知错误：{e}")


def main():
    sender_email = "AzzatoWaydell@126.com"
    receiver_email = "Sickwag@outlook.com"
    password = "H"  # 请替换为实际的授权码
    send_mail(sender_email, receiver_email, password)

main()