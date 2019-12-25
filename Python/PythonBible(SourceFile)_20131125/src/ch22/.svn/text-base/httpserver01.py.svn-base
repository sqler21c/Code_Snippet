# httpserver01.py
from http.server import HTTPServer, BaseHTTPRequestHandler
import sys
import time

PORT = 8000

class MyHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        if self.path != '/':
            self.send_error(404, 'File not found')
            return
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        self.send_body()

    def send_body(self):
        t = time.asctime()
        msg = '<html><body>access time : <b>{}</b></body></html>'.format(t)
        self.wfile.write(msg.encode())

httpd = HTTPServer(('', PORT), MyHandler)
print ('listening on port', PORT)
httpd.serve_forever()
