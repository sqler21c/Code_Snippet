# multithread.py

import time
from threading import *			# 스레드 클래스를 제공하는 모듈 : threading
class MyThread(Thread):			# 하위 클래스 MyThread를 정의한다.
    def __init__(self):
        super().__init__()		# 기반 클래스의 초기화 루틴을 불러야 한다.

    def run(self):				# 실제적으로 실행을 위해서 정의해야 할 부분이다.
        for el in range(10):		# 10번 반복한다.
            print('{}=>{}\n'.format(self.getName(), el), end=' ')
            time.sleep(0.01)		# 0.01초 대기

thread1 = MyThread()			# 스레드 객체(인스턴스) thread1 생성
thread2 = MyThread()			# 스레드 객체(인스턴스) thread2 생성
thread1.start()					# 스레드 실행 시작. run() 메서드가 호출된다.
thread2.start()
