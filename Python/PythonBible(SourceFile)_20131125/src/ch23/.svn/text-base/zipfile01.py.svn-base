# zipfile01.py
import zipfile

# 여러 개 파일 압축해서 하나의 zip 파일 만들기
flist = ['c:\\python33\\README.txt', 'c:\\python33\\python.exe']

with zipfile.ZipFile('test.zip', 'w', compression=zipfile.ZIP_BZIP2) as myzip:
    for fpath in flist:
        myzip.write(fpath)

# 파일 한 번에 압축 풀기
zipfile.ZipFile('test.zip').extractall()

# 압축한 파일 목록 확인하고 하나씩 압축 풀기
with zipfile.ZipFile('test.zip') as myzip:
    namelist = myzip.namelist()
    print(namelist, '\n')
    for name in namelist:
        info = myzip.getinfo(name)
        print('{} : date_time={} CRC={} file_size={} compress_size={}'.format(
            info.filename, info.date_time, info.CRC, info.file_size, info.compress_size))
        myzip.extract(name) # 압축 풀기
