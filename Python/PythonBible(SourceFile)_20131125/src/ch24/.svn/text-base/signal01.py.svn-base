# signal 01.py
import signal
import time
import sys

def handler(signum, f):
	print(signum)			# signal 번호를 출력하고 종료한다
	sys.exit()

signal.signal(signal.SIGINT, handler)
						# SIGINT는 Ctrl-C가 눌렸을 때 발생되는 signal임.
						# 그때 처리할 핸들러를 지정
while True:
	print (time.ctime())
	time.sleep(1)
