# compose_hangul1.py
def compose_hangul(cho, jung, jong):
	code = 0xac00 + ((cho*21) + jung)*28 + jong
	return chr(code)

print (compose_hangul(18, 0, 4))
