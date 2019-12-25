# rectangle.py

import os

def debugged(func, cls_name):	# 장식자
    # 디버깅 모드가 아니면 수정 없이 func을 반환한다.
    if os.environ.get('DEBUG','FALSE') != 'TRUE':
        return func

    # 디버깅 래퍼(wrapper) 만들기
    def call(*args,**kwargs):
        print("* {}.{} {} {}".format(cls_name, func.__name__, args[1:], kwargs))
        result = func(*args,**kwargs)
        print("    returning {}".format(result))
        return result
    return call

class DebugMeta (type):	# 메타클래스
    def __new__(cls,name,bases,dict):
        if os.environ.get('DEBUG','FALSE') == 'TRUE':
            # 호출 가능한 모든 멤버를 찾아서
            # 디버깅 래퍼에 적용한다.
            for key,member in dict.items():
                if hasattr(member,'__call__'):
                    dict[key] = debugged(member, name)
        return type.__new__(cls,name,bases,dict)


class Rectangle(metaclass=DebugMeta):
    def __init__(self,width,height):
        self.width = width
        self.height = height
    def area(self):
        return self.height*self.width

r = Rectangle(3, 4)
print(r.area())
