# automember.py

class AutoMemberSetType(type):
    def __call__(cls, *args, **kwargs):
        obj = type.__call__(cls, *args, **kwargs)
        arg_names = obj.__init__.__func__.__code__.co_varnames[1:]
        defaults = obj.__init__.__func__.__defaults__
        for name, value in zip(arg_names, args+defaults):
            setattr(obj, name, value)
        for name, value in kwargs.items():
            setattr(obj, name, value)
        return obj

class Panel(metaclass=AutoMemberSetType):
    def __init__(self, width, height=400):
        pass			# 별로 할 일이 없다.


p = Panel(60, 40)

print (p.width, p.height)