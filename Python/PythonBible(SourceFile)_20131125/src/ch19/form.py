#!/usr/local/bin/python3

print ("Content-Type: text/html;charset=utf-8\n\n")

print ('''
<form name="form" method="post" action="/cgi-bin/subscribe.py">
  <p>
    email:<input type="text" name="email">
    name:<input type="text" name="name">
    <input type="submit" value="Submit">
  </p>
</form>
''')
