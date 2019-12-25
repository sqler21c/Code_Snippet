# tarfile01.py
import tarfile

# 여러 개 파일 압축해서 하나의 tar 파일 만들기
flist = ['c:\\python33\\README.txt', 'c:\\python33\\python.exe']

with tarfile.open('test.tar.gz', 'w:gz') as mytar:
    for fpath in flist:
        mytar.add(fpath)

# 파일 한 번에 압축 풀기
#tarfile.open('test.tar.gz').extractall()

# 압축한 파일 목록 확인하고 하나씩 압축 풀기
with tarfile.open('test.tar.gz', 'r:*') as mytar:
    for tarinfo in mytar:
        print('{} : file_size={}'.format(
            tarinfo.name, tarinfo.size))
        if tarinfo.isreg():     # 정규 파일일 경우..
            mytar.extract(tarinfo.name) # 압축 풀기
        elif tarinfo.isdir():     # 디렉토리일 경우..
            print('    folder')
