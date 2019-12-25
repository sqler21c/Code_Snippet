# orphan.py
import os
import time

print("원래 프로세스 PID=", os.getpid())
pid = os.fork()   # 이 시점에서 프로세스가 두 개로 나뉜다.
if pid:
        print("난 부모 프로세스 PID={} 내자식 PID={}".format(os.getpid(), pid))
else:
        print("난 자식 프로세스 PID={} 내부모 PID={}".format(os.getpid(), os.getppid()))
        time.sleep(5)
        print("난 자식 프로세스 PID={} 내부모 PID={}".format(os.getpid(), os.getppid()))
