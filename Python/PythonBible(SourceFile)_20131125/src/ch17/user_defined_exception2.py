# user_defined_exception2.py

class MessageException(Exception):	# 사용자 예외 클래스를 정의한다.
    def __init__(self, message, dur):
        self.message = message
        self.duration = dur
    def __str__(self):
        return '{}: message={}, duration={}'.format(
            self.__class__.__name__,
            self.message, self.duration)

def f():
    raise MessageException('message', 10)	# 예외 객체를 전달한다.

try:
    f()
except MessageException as a:		 # 예외 객체를 a란 이름으로..
    print(a)
    print(a.message, a.duration)
