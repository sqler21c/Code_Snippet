# httpserver03.py
from http.server import HTTPServer, CGIHTTPRequestHandler

PORT = 8000

Handler = CGIHTTPRequestHandler
httpd = HTTPServer(('', PORT), Handler)

print ('listening on port', PORT)
httpd.serve_forever()
