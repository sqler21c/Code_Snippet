# gzip01.py
import gzip

data = open(r'C:\Python33\README.txt').read().encode()
with gzip.open('readme.txt.gz', 'wb', compresslevel=6) as f:
    f.write(data)


with gzip.open('readme.txt.gz', 'rb') as f:
    print(f.read())
