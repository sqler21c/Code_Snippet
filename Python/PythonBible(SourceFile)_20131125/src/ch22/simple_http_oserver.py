# simple_http_oserver.py
import asynchat
import asyncore
import socket

class AsyncServer(asyncore.dispatcher):
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
        return HttpHandler(sock=csock)


class HttpHandler(asynchat.async_chat):
    def __init__(self, sock=None):
        asynchat.async_chat.__init__(self, sock)
        self.set_terminator(b'\r\n\r\n')
        self.incom_data = b''

    def collect_incoming_data(self, data):
        self.incom_data += data

    def found_terminator(self):
        header_lines = self.incom_data.decode().splitlines()
        request = header_lines[0]
        print(request)
        self.push_text("HTTP/1.0 200 OK\r\n")
        self.push_text("Content-type: text/html\r\n")
        self.push_text("\r\n")
        self.push_text("<html><body><pre>\r\n")
        self.push_text(self.incom_data)
        self.push_text("</pre></body></html>\r\n")
        self.close_when_done()

    def push_text(self, text):
        if type(text) == bytes:
            self.push(text)
        else:        
            self.push(text.encode())

server = AsyncServer(5004)
asyncore.loop()
