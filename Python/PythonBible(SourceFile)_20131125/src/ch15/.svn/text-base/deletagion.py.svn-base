# delegation.py

class Delegation:
    def __init__(self, data):
        self.stack = data
    def __getattr__(self, name):	# 정의되지 않은 속성을 참조할 때 호출한다.
        print('Delegating {} '.format(name), end=' ')
        return getattr(self.stack, name)		# self.stack의 속성을 대신 이용한다.

a = Delegation([1,2,3,1,5])
print(a.pop())
print(a.count(1))
