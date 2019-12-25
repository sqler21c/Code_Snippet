#!/usr/local/bin/python3

import cgi
import codecs
import sys
import os
import cgitb; cgitb.enable()

w = codecs.getwriter('utf-8')(sys.stdout.buffer)

print ("Content-Type: text/html;charset=utf-8\n\n", file=w)
form = cgi.FieldStorage()
for name in form.keys():
    print ("Input: {} value: {}<br/>".format(name, form.getvalue(name)), file=w)
print ("Finished!", file=w)
print (os.environ['DOCUMENT_ROOT'], file=w)
