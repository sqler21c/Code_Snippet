# bz2_sample.py
from bz2 import BZ2Compressor as Compressor

compressor = Compressor()

fpath = 'c:\\python33\\README.txt'
with open(fpath) as f:
    data = f.read(128)
    while data:
        c = compressor.compress(data.encode())
        if compressed:
            print('compressed:', c)
        data = f.read(128)
    c = compressor.flush()
    if c:
        print('compressed:', c)
