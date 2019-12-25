# readmail03.py
import poplib
import email
import mimetypes
from email import header
import mailbox


def decodeHeader(headerMsg):
    L = header.decode_header(headerMsg)
    s = ''
    for s1, chset in L:
        if (type(s1) == bytes):
            s += s1.decode(chset) if chset else s1.decode()
        else:
            s += s1
    return s

host = ''			# 적당한 값을 써 넣을 것
userid = ''		# 적당한 값을 써 넣을 것
passwd = ''		# 적당한 값을 써 넣을 것
mbox = poplib.POP3(host)
mbox.user(userid)
mbox.pass_(passwd)
noMsg, tsize = mbox.stat()

for k in range(1, noMsg+1):
    res = mbox.top(k, 0)[1]
    headerMsg = '\n'.join([b.decode('utf-8') for b in res])
    msg = mailbox.Message(headerMsg)
    print (k, '보낸이: %s, 받는이: %s, 제목: %s, 날짜: %s' % (
            decodeHeader(msg['from']), 
            decodeHeader(msg['to']), 
            decodeHeader(msg['subject']), 
            msg['date'])) 
mbox.quit()
