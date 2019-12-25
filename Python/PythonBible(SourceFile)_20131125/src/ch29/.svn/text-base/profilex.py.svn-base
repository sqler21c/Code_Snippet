# file : profilex.py
def count105():
    for x in range(100000):
        pass

def count106():
    for x in range(1000000):
        pass

def fast():
    count105()
    count105()
    count105()

def slow():
    count106()
    count106()
    count106()
    count106()

def spam():
    fast()
    slow()

if __name__ == '__main__':
    import cProfile
    cProfile.run('spam()')
#    cProfile.run('spam()', 'spamprofile.txt')