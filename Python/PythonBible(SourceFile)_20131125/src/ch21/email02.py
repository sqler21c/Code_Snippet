# email02.py
import smtplib
import mimetypes
import glob

from email.header import Header
from email import encoders
from email.message import Message
from email.mime.base import MIMEBase
from email.mime.audio import MIMEAudio
from email.mime.image import MIMEImage
from email.mime.text import MIMEText
from email.mime.application import MIMEApplication

HOST = 'smtp.server'		# SMTP 서버
me = 'gslee@localhost'		# 내 주소
receiver = ['gslee@localhost', 'jangc@localhost'] # 받을 사람 주소 리스트
subject = '첨부 파일 메일 보내기'

outer = MIMEBase('multipart', 'mixed')
outer['Subject'] = Header(subject.encode('utf-8'), 'utf-8')
outer['From'] = me
outer['To'] = ', '.join(receiver)   # 수신자 문자열 만들기
outer.preamble = 'This is a multi-part message in MIME format.\n\n'
outer.epilogue = ''	      # 이렇게 하면 멀티파트 경계 다음에 줄 바꿈 코드가 삽입 됨
msg = MIMEText('파일들을 첨부합니다.'.encode('utf-8'), _charset='utf-8')
outer.attach(msg)

files = glob.glob('*.*')
for fileName in files:
    ctype, encoding = mimetypes.guess_type(fileName)
    if ctype is None or encoding is not None:
        ctype = 'application/octet-stream'
    maintype, subtype = ctype.split('/', 1)
    if maintype == 'text':
        fd = open(fileName, encoding='utf-8')   # utf-8이라 가정..
        msg = MIMEText(fd.read().encode('utf-8'), _subtype=subtype, _charset='utf-8')
    elif maintype == 'image':
        fd = open(fileName, 'rb')
        msg = MIMEImage(fd.read(), _subtype=subtype)
    elif maintype == 'audio':
        fd = open(fileName, 'rb')
        msg = MIMEAudio(fd.read(), _subtype=subtype)
    else:
        fd = open(fileName, 'rb')
        msg = MIMEApplication(fd.read(), _subtype=subtype)
    fd.close()
    msg.add_header('Content-Disposition', 'attachment', filename=fileName)
    outer.attach(msg)

# SMTP 서버를 통해서 메일 보내기
s = smtplib.SMTP(HOST)
s.sendmail(me, receiver, outer.as_string())
s.quit()
