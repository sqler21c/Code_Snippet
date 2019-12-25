# singleton_meta.py

class Singleton(type):
    __instances = {}
    def __call__(cls, *args, **kwargs):
        if cls not in cls.__instances:
            cls.__instances[cls] = super().__call__(*args, **kwargs)
        return cls.__instances[cls]


class MyClass(metaclass=Singleton):
    pass

m1 = MyClass()
m2 = MyClass()
print(m1 is m2)		# True이다. 동일한 객체가 맞다.
