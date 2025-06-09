import argparse
from PIL import Image

parser = argparse.ArgumentParser(description="transform pic to ascii plaint text")
parser.add_argument("file")
parser.add_argument("-o", "--output")
parser.add_argument("--width", type=int, default=80)
parser.add_argument("--height", type=int, default=80)

args = parser.parse_args()
img = args.file
width = args.width
height = args.height
output = args.output

ascii_char = list(
    "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. "
)


def get_char(r, g, b, alpha=256):
    if alpha == 0:
        return " "
    length = len(ascii_char)
    gray = int(0.2126 * r + 0.7152 * g + 0.0722 * b)
    unit = (256.0 + 1) / length
    # 把rgb转化为gray(0~255)之间的值之后，映射到alpha中的字符
    return ascii_char[int(gray / unit)]


if __name__ == "__main__":

    im = Image.open(img)
    im = im.resize((width, height), Image.NEAREST)
    txt = ""
    for i in range(height):
        for j in range(width):
            txt += get_char(*im.getpixel((j, i)))
        txt += "\n"
    print(txt)

    if output:
        with open(output, "w") as f:
            f.write(txt)
    else:
        with open("output.txt", "w") as f:
            f.write(txt)
