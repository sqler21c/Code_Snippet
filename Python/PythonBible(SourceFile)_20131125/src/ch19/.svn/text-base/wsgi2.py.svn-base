# wsgi2.py
import re
from html import escape
import urllib.parse

def index(environ, start_response):
    start_response('200 OK', [('Content-Type', 'text/html;charset=utf-8')])
    response = ['index called']
    return (line.encode('utf-8') for line in response)

def hello(environ, start_response):
    args = environ['url_args']
    if args:
        q = ''.join(['%{:X}'.format(ord(c)) for c in escape(args[0])])
        name = urllib.parse.unquote(q)
    else:
        name = 'world'
    start_response('200 OK', [('Content-Type', 'text/html;charset=utf-8')])
    response = ['Hello {}'.format(name)]
    return (line.encode('utf-8') for line in response)

def not_found(environ, start_response):
    start_response('404 NOT FOUND', [('Content-Type', 'text/plain;charset=utf-8')])
    response = ['Not Found']
    return (line.encode('utf-8') for line in response)

urls = [
    (r'^$', index),
    (r'hello/?$', hello),
    (r'hello/(.+)$', hello)
]

def application(environ, start_response):
    path = environ.get('PATH_INFO', '').lstrip('/')
    for regex, callback in urls:
        match = re.search(regex, path)
        if match:
            environ['url_args'] = match.groups()
            return callback(environ, start_response)
    return not_found(environ, start_response)

if __name__ == '__main__':
    from wsgiref.simple_server import make_server
    srv = make_server('localhost', 8080, application)
    srv.serve_forever()
