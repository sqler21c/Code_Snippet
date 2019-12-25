# process_non_daemon.py
import logging
import multiprocessing
import time

def non_daemon():
    p = multiprocessing.current_process()
    print ('Starting:', p.name, p.pid)
    time.sleep(1)
    print ('Exiting :', p.name, p.pid)

if __name__ == '__main__':
    logger = multiprocessing.log_to_stderr()
    logger.setLevel(logging.INFO)
    p = multiprocessing.current_process()
    print ('Starting:', p.name, p.pid)
    n = multiprocessing.Process(name='non-daemon', target=non_daemon)
    n.start()