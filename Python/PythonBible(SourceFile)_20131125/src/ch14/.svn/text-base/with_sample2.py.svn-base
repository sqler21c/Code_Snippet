# with_sample2.py

from contextlib import contextmanager
import threading

@contextmanager
def Locked2(lock):
    lock.acquire()
    yield lock
    lock.release()

lock = threading.Lock()
with Locked2(lock):
    print ('I am in C.S.')
