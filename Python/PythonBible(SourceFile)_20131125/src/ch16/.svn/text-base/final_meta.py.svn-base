# final_meta.py

class final(type):
    def __init__(cls, name, bases, namespace):
        super().__init__(name, bases, namespace)
        for klass in bases:	# 기반 클래스에 final이 있으면 에러를 발생시킨다
            if isinstance(klass, final):	
                raise TypeError(klass.__name__ + ' is final')


class A: pass
class B(A, metaclass=final): pass
class C(B): pass
