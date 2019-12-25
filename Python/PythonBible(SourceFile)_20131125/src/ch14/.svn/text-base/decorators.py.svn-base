# decorators.py

import functools

def counter(func):
    """
    함수 호출 회수 카운트 한다
    """
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        wrapper.count = wrapper.count + 1
        res = func(*args, **kwargs)
        print("{0} : {1} 호출".format(func.__name__, wrapper.count))
        return res
    wrapper.count = 0
    return wrapper

def logging(func):
    """
    함수 호출 내용을 로깅(프린트)하는 장식. 
    """
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        res = func(*args, **kwargs)
        print('{}({}, {}) => {}'.format(func.__name__, args, kwargs, res))
        return res
    return wrapper

def benchmark(func):
    """
    실행 시간을 출력하는 장식자
    """
    import time
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        t = time.clock()
        res = func(*args, **kwargs)
        print(func.__name__, time.clock()-t)
        return res
    return wrapper

@counter
@benchmark
@logging
def add(a,b):
    return a+b

print(add(1,2))
print(add(2,3))
