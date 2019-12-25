# echoclient.py
import asyncore
import socket

class EchoClient(asyncore.dispatcher):
    def __init__(self, host, port):
        asyncore.dispatcher.__init__(self)
        self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connect((host, port))
        self.messages = ['hi', 'hello', '안녕하세요!\n안녕~']
        self.seperator = b'\r\n\r\n'

    def handle_connect(self):
        pass

    def handle_expt(self):
        self.close() # connection failed, shutdown

    def writable(self):
        return self.messages

    def handle_write(self):
        if self.messages:
            msg = self.messages.pop(0)
            self.send(msg.encode())
            self.send(self.seperator)

    def handle_read(self):
        s = self.recv(2048)
        for msg in s.split(self.seperator):
            if msg:
                print(msg.decode())

    def handle_close(self):
        self.close()


request = EchoClient("localhost", 5003)
asyncore.loop()
