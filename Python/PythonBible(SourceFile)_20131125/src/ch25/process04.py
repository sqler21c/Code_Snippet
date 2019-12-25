# process04.py
from multiprocessing import Process, Pipe

def reader(pipe):
    p, q = pipe
    p.close()    # 입력은 닫는다
    while True:
        try:
            msg = q.recv()    # 파이프에서 항목 읽음
        except EOFError:
            break

def writer(p):
    for i in range(0, 1000):
        p.send(i)

if __name__ == '__main__':
    p, q = Pipe()
    reader_p = Process(target=reader, args=((p, q),))
    reader_p.start()       # 읽기 프로세스 시작

    q.close()       # 파이프 출력은 닫는다
    writer(p)        # 항목을 생산
    p.close()        # 생산 끝
    reader_p.join()
