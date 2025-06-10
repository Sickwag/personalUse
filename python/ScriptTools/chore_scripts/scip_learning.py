from urllib.request import urlopen

shakespeare = urlopen('http://inst.eecs.berkeley.edu/~cs61a/fa11/shakespeare.txt')

words = set(shakespeare.read().decode().split())
result = {w for w in words if len(w) >= 5 and w[::-1] in words}

print(result)