# relex.py
import re
import keyword

tokenREList = [
	('KEYWORD','|'.join(keyword.kwlist)),
	('NAME',r'[a-zA-Z_]\w*'),
	('NUMBER', r'\d+|\d+\.\d*|\.\d+'),
	('LPAREN', r'\('),
	('RPAREN', r'\)'),
	('PLUS', r'\+'),
	('COLON', r':'),
	('WHITESPACE', r'\s+')
]

rexp = ['(%s)' % exp for tokName, exp in tokenREList]
p = re.compile('|'.join(rexp))

def lex(s):
	pos = 0
	match = p.match(s, pos)
	while match:
		token = match.groups()
		pos = match.end()
		for k in range(len(token)):
			if token[k]: break
		else:
			break
		yield (tokenREList[k][0], token[k])
		match = p.match(s, pos)

if __name__ == '__main__':
    s = '''
    for i in range(10):
        print (i + 5)'''

    for tok in lex(s):
        print(tok)
