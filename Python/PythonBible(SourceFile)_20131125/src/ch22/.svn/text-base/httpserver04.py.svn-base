# httpserver04.py
from http.server import HTTPServer, CGIHTTPRequestHandler

PORT = 8000

class Handler(CGIHTTPRequestHandler):
    cgi_directories = ['/cgi-bin', '/public_html/cgi-bin']

httpd = HTTPServer(('', PORT), Handler)

print ('listening on port', PORT)
httpd.serve_forever()
