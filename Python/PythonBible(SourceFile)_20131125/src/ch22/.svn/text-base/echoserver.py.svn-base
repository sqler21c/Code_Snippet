# echoserver.py
import asyncore
import socket

class EchoServer(asyncore.dispatcher):
    def __init__(self, port):
        asyncore.dispatcher.__init__(self)
        self.port = port
        self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
        self.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.bind(('localhost', port))
        self.listen(5)
        print ("listening on port", self.port)

    def handle_accepted(self, csock, addr):
        print ("accepted", addr)
        return EchoHandler(sock=csock)


class EchoHandler(asyncore.dispatcher):
    def __init__(self, sock=None):
        asyncore.dispatcher.__init__(self, sock)
        self.incom_data = b''
        self.seperator = b'\r\n\r\n'
        self.write_queue = []
        
    def handle_read(self):
        data = self.recv(2048)
        self.incom_data += data
        if self.seperator in self.incom_data:
            *msgs, self.incom_data = self.incom_data.split(self.seperator)
            for msg in msgs:
                print('got message', msg.decode())
                self.write_queue.append(msg)

    def writable(self):
        return self.write_queue
    
    def handle_write(self):
        if self.write_queue:
            msg = self.write_queue.pop(0)
            print('sending..', msg.decode())
            sent = self.send(msg)
            self.send(self.seperator)
        if not self.write_queue:
            print('closing..')
            self.close()

server = EchoServer(5003)
asyncore.loop()
