# process02.py
from multiprocessing import Process
import os

class MyProcess(Process):

    def __init__(self, n, m):
        Process.__init__(self)
        self.n = n
        self.m = m

    def run(self):
        for i in range(self.n):
            print('id={} --> {}'.format(os.getpid(), i))
            for k in range(self.m):  # 시간을 보내기 위한 코드
                pass

if __name__ == '__main__':
    p_list = []         # 프로세스 리스트
    for i in range(2):  # 프로세스 두 개 생성
        p = MyProcess(3, 100000)
        p.start()       # 프로세스 실행 시작
        p_list.append(p)  # 프로세스 객체를 리스트에 저장

    for p in p_list:
        p.join()       # 각 프로세스가 끝날 때까지 대기
    print('Exiting')
