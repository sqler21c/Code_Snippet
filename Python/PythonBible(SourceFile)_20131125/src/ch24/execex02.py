# execex02.py
import os

print ('ls를 실행하기 직전. 내 pid={}'.format(os.getpid()))
if os.fork() == 0:
	os.execl("/bin/ls", "ls")	# 자식 프로세스가 'ls' 프로세스로 전환된다.
print ('부모 프로세스만 이 글을 출력함')
