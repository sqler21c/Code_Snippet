# readmail02.py
import poplib
import email
import mimetypes
from email import header

def login(host, userid, passwd):
    mbox = poplib.POP3(host)	# 서버에 연결
    mbox.user(userid)			# 로그인
    mbox.pass_(passwd)			# 로그인
    return mbox

def decodeHeader(headerMsg):
    L = header.decode_header(headerMsg)
    s = ''
    for s1, chset in L:
        if (type(s1) == bytes):
            s += s1.decode(chset) if chset else s1.decode()
        else:
            s += s1
    return s

def read_email(mbox, no):
    (server_msg, body, octets) = mbox.retr(no)			# 첫 메일을 읽는다 
    message = '\n'.join([b.decode() for b in body])
    msg = email.message_from_string(message)		# 문자열에서 Message 객체로..
    print (decodeHeader(msg['from']))					# 보낸 사람
    print (decodeHeader(msg['to']) )					# 받는 사람
    print (decodeHeader(msg['subject']) )				# 제목
    print (msg['date'])								# 날짜

    for part in msg.walk():							# 각각의 파트에 대해
        if part.is_multipart():
            continue
        filename = part.get_filename()				# 파일 이름을 얻고
        if filename:
            fp = open(filename, 'wb')
            fp.write(part.get_payload(decode=True))			# 디코드해서 파일로 저장
            fp.close()
            print (filename, 'saved..')
        else:
            charset = part.get_content_charset()
            print(part.get_payload(decode=True).decode(charset))
    return


host = ''					# 적당한 값을 써 넣을 것
userid = ''					# 적당한 값을 써 넣을 것
passwd = ''					# 적당한 값을 써 넣을 것

mbox = login(host, userid, passwd)

noMsg, tsize = mbox.stat()
print (noMsg, 'messages')
for k in range(1, noMsg+1):
    print ('-'*40, k)
    read_email(mbox, k)
mbox.quit ()
