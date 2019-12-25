import square

s = square.Square(10)
print('square object=', s)

print('s.limit=', s.limit)
print('s.middle()=', s.middle())

print('len(s)=', len(s))

for i in s:
    print (i)

print('list(s)=', list(s))
print('tuple(s)=', tuple(s))
