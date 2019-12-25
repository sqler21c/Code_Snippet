#!/usr/local/bin/python3

import cgi
import cgitb; cgitb.enable()

print ('Content-type: text/plain\n\n')

form = cgi.FieldStorage()
myfile = form['myfile']

print(myfile.filename.encode('utf-8'))

fileobj = myfile.file
print(fileobj.read(100))
print('-'*50)
print(fileobj.read())
