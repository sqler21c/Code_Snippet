# mime_decode.py
import re

def decode_str(codec, mimecodec, a):
    import base64
    import quopri
    if mimecodec == 'B':
        return base64.b64decode(a).decode(codec)
    elif mimecodec == 'q':
        return quopri.decodestring(a).decode(codec)

p = re.compile(r'=\?(\S+?)\?(.)\?(\S+?)\?=')
s = "=?euc-kr?q?=B1=E8=20=C7=FC=BA=B9?= <gudwns_kim@yahoo.co.kr>"
s1 = "2000120146 =?euc-kr?B?vsjA58jG?= <=?euc-kr?B?tOu80rmuwNo=?==?euc-kr?B?udmy2bHi?=> "

for codec, mimecodec, a in p.findall(s):
    print(decode_str(codec, mimecodec, a))

for codec, mimecodec, a in p.findall(s1):
    print(decode_str(codec, mimecodec, a))
