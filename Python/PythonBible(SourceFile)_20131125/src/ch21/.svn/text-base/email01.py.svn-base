# email01.py
import smtplib
from email.mime.text import MIMEText
from email.header import Header

HOST = 'localhost'				# SMTP 서버
me = 'gslee@localhost'		# 내 주소
you = 'gslee@localhost'	# 받을 사람 주소
contents = '''
메일 시험 중..
파이썬으로 보내는 메일임..
'''
msg = MIMEText(contents.encode('utf-8'), _subtype='plain', _charset='utf-8')
msg['Subject'] = Header('I love 파이썬', 'utf-8')
msg['From'] = me
msg['To'] = you

s = smtplib.SMTP(HOST)
s.sendmail(me, [you], msg.as_string())
s.quit()
