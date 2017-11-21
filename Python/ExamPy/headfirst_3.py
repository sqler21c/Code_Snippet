"""
This is the stadard way to
include a multiple-line comment in your code.
"""
def print_lol(the_list, indent = 0, step = 0):
    '''
    this function is nasty list print
    '''
    for each in the_list:
        if isinstance(each, list):
            print_lol(each, indent, step + 1)
        else:
            # print() 함수는 기본적으로 한 라인을 인쇄 할때 마다 라인을 변경한다.
            # 라인을 바꾸지 않고  tab 문자 하나만 입력 할려면 print('\t', end='')와 같이 호출하면 된다
            if indent:
                for tab in range(step):
                    print("\t", end = '')
            print(each)

movies = ["The Holy Grail", 1975, "Tarry Jones & Terry Gilliam", 91, \
["Graham Chapman", ["Michael Pain", "John Cleese", "Terry Gilliam", "Eric Idle", "Terry Johne"]]]

print_lol(movies, False,  4)
