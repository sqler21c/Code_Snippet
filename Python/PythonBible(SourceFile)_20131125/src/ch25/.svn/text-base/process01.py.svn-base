# process01.py
from multiprocessing import Process
import os

# 프로세스로 실행될 함수를 정의한다
def f(n, m):
    print('pid=', os.getpid(), 'id(m)=', id(m))
    for i in range(n):
        print('id={} --> {}'.format(os.getpid(), i))
        for k in range(m):  # 시간을 보내기 위한 코드
            pass

if __name__ == '__main__':
    p_list = []         # 프로세스 리스트
    m = 100000
    for i in range(2):  # 프로세스 두 개 생성
        p = Process(target=f, args=(3, m))
        p.start()       # 프로세스 실행 시작
        p_list.append(p)  # 프로세스 객체를 리스트에 저장

    for p in p_list:
        p.join()       # 각 프로세스가 끝날 때까지 대기
    print('Exiting')
