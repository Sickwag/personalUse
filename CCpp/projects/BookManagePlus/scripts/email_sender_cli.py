import argparse
import smtplib
import os
import getpass
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication


def args_parser():
    parser = argparse.ArgumentParser(
        prog="email-sender", description="parse email sending arguments.",
        epilog="\nusage:\n\t python email_sender_cli.py -s sender@126.com -r receiver@qq.com -p \"app password\" -m \"test\" -a \"E:\\image.png\""
    )
    parser.add_argument(
        "-s","--sender",
        type=str,
        default="AzzatoWaydell@126.com",
        action="store",
        help="the sender address.",
    )
    parser.add_argument(
        "-p","--password",
        type=str,
        default=None,
        required=True,
        help="sender's password(maybe have to use app password instead account password.)",
    )
    parser.add_argument(
        "-r", "--receiver", type=str, nargs="+", help="receiver addresses"
    )
    parser.add_argument("-m","--message", type=str, default=None, help="")
    parser.add_argument("--subject", type=str, default=None, help="email subject.")
    parser.add_argument("--username", type=str, default=None,help="the smtp authorization username, default same as your sender email.")
    parser.add_argument(
        "--smtp", type=str, default="smtp.126.com", help="smtp service url address"
    )
    parser.add_argument(
        "-a","--attach", type=str, nargs="*", help="input filepaths you wanna attach to, avoid to use path includes Chinese characters which may cause unstable parsing."
    )
    parser.add_argument("--port", type=int, default=25, help="smtp service port.")

    args = parser.parse_args()
    if args.message is None:
        args.message = f"this is a simple email from {args.sender}"

    if args.username is None:
        args.username = args.sender

    if args.receiver is None:
        parser.error("you have not set receiver")

    if args.password is None:
        # parser.error("you have not set password")
        args.password = getpass.getpass("you have not input sender password, try again:")

    if not args.sender.endswith("@126.com") and (args.smtp == "smtp.126.com" and args.port == 25):
        parser.error(
            "when you point sender address not use 126 email, you must change --smtp to reset smtp service address and port."
        )

    return args


def send_email(args):
    email = MIMEMultipart()
    email["From"] = args.sender
    email["To"] = ", ".join(args.receiver)
    email["Subject"] = args.subject
    MIMEText(args.message, "plain", "utf-8")
    email.attach(payload=MIMEText(f"{args.message}", "plain"))

    if args.attach:
        for file_path in args.attach:
            with open(file=file_path, mode='rb') as attachment:
                part = MIMEApplication(attachment.read(), Name=file_path)
                part["Content-Disposition"] = f'attachment; filename={os.path.basename(file_path)}'
                email.attach(part)

    try:
        with smtplib.SMTP(args.smtp, args.port) as server:
            server.starttls()
            server.login(user=args.username,password=args.password)
            server.sendmail(args.sender, to_addrs=args.receiver, msg=email.as_string())
        print("email send successfully")
    except smtplib.SMTPAuthenticationError:
        print(
            "authorization fail, check whether your mailbox open SMTP service or you have use app password instead account password."
        )
    except smtplib.SMTPException as e:
        print(f"fatal error: {e}")
    except Exception as e:
        print(f"unexpected error: {e}")
    return

def start():
    args = args_parser()
    send_email(args=args)

start()
