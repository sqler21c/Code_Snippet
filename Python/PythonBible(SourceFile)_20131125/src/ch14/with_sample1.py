# with_sample.py

import threading

class Locked:
   def __init__(self, lock):
       self.lock = lock
   def __enter__(self):
       self.lock.acquire()
   def __exit__(self, type, value, tb):
       self.lock.release()


lock = threading.Lock()
with Locked(lock):
    print ('I am in C.S.')


from contextlib import contextmanager

@contextmanager
def Locked2(lock):
    lock.acquire()
    yield lock
    lock.release()

with Locked2(lock):
    print ('I am in C.S.')
