# zlib01.py - compressobj

libtype=1

if libtype == 1:
    from zlib import compressobj as Compressor
    from zlib import decompressobj as Decompressor
    fpath_out = 'readme.z'
elif libtype == 2:
    from bz2 import BZ2Compressor as Compressor
    from bz2 import BZ2Decompressor as Decompressor
    fpath_out = 'readme.bz2'
elif libtype == 3:
    from lzma import LZMACompressor as Compressor
    from lzma import LZMADecompressor as Decompressor
    fpath_out = 'readme.xz'

compressor = Compressor()

fpath = 'c:\\python33\\README.txt'

# 증분 압축
with open(fpath_out, 'wb') as fout:
    with open(fpath) as f:
        data = f.read(128)  # 부분적으로 읽어서
        while data:
            c = compressor.compress(data.encode())  # 버퍼에 추가
            if c:               # 압축되었으면
                fout.write(c)   # 파일에 출력
            data = f.read(128)
    c = compressor.flush()
    if c:
        fout.write(c)


# 증분 해제
decompressor = Decompressor()

with open(fpath_out, 'rb') as f:
    data = f.read(128)          # 부분적으로 읽어서
    while data:
        c = decompressor.decompress(data)   # 버퍼에 추가
        if c:                   # 압축해제 되었으면
            print(c.decode())   # 화면 출력
        data = f.read(128)

if hasattr(decompressor, 'flush'):
    c = decompressor.flush()
    if c:
        print(c.decode())
