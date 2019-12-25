# process03.py
from multiprocessing import Process, Queue
from multiprocessing import queues
import time

def producer(q):
    for k in range(3):  # 천천히 생산
        q.put(k)
        print('produced', k)
        time.sleep(1)
    for k in range(3,6):    # 빨리 생산
        q.put(k)
        print('produced', k)

def consumer(q):
    while True:
        try:
            ele = q.get(block=True, timeout=3)
            print('consumed', ele)
            time.sleep(0.5)
        except queues.Empty:
            break
    q.close()

if __name__ == '__main__':
    q = Queue()
    con_p = Process(target=consumer, args=(q,))
    con_p.start()

    producer(q)

    con_p.join()
