# udp02.py 
# UDP 에코 클라이언트 
from socket import * 
 
HOST = 'localhost'   # 적당한 호스트로 변경 
PORT = 5001         # 서버 UDP 포트 
 
csock = socket(AF_INET, SOCK_DGRAM) 
csock.sendto(b'HI', (HOST, PORT)) 
msg, addr = csock.recvfrom(1024) 
print (msg.decode(), addr )
csock.sendto('안녕하세요'.encode(), (HOST, PORT)) 
msg, addr = csock.recvfrom(1024) 
print (msg.decode(), addr)
