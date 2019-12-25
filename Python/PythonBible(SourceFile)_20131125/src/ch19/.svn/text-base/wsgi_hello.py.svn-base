# wsgi_hello.py

import cgi
import html

def hello_world(environ, start_response):
    form = cgi.FieldStorage(environ['wsgi.input'], environ=environ)
    name = html.escape(form.getvalue('name', 'World'))
    start_response('200 OK', [('Content-Type', 'text/html;charset=utf-8')])
    response = ['안녕하세요 {0}'.format(name)]
    return (line.encode('utf-8') for line in response)

if __name__ == '__main__':
    from wsgiref.simple_server import make_server
    srv = make_server('localhost', 8080, hello_world)
    srv.serve_forever()
