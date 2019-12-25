#!/usr/local/bin/python3

import sys
import codecs

writer = codecs.getwriter('utf-8')(sys.stdout.buffer)

print("Content-Type: text/html;charset=utf-8\n", file=writer)

print('''
<HTML>
<HEAD></HEAD>
<BODY>
<H2>한글</H2>
Hello again,
</BODY>
</HTML>
''', file=writer)
