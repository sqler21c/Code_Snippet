# udp01.py 
# UDP 에코 서버 
from socket import * 
import select 
 
PORT = 5001   # 서버 UDP 포트 
 
svrsock = socket(AF_INET, SOCK_DGRAM) 
svrsock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
svrsock.bind(('localhost', PORT)) 
args = [svrsock], [], [] 
print ('Started..')
while True: 
    retr, retw, retx = select.select(*args)   # 클라이언트에서 메시지가 오면 리턴된다. 
    for sock in retr: 
        msg, addr = sock.recvfrom(1024)       # 준비된 데이터와 주소를 읽는다. 
        print (msg.decode(), addr)
        sock.sendto(msg, addr)   # 클라이언트에게 받은 메시지를 그대로 전달한다. 
