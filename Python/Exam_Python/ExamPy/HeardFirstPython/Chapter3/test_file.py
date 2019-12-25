import os
cwd = os.getcwd()
cwd = cwd + '/Code_Exam/github/Code_Snippet/Python/Exma_Python/ExamPy/HeardFirstPython/Chapter3/'
#if os.path.exists('sketch.txt'):
try:
    data = open('sketch.txt')
# print(data.readline(), end='')
# print(data.readline(), end='')
# data.seek(0)
# for each_line in data:
#    print(each_line, end='')
    for each_line in data:
    #(role, line_spoken) = each_line.split(':', maxsplit=1)
#    if each_line.find(':') != -1:
        try:
            (role, line_spoken) = each_line.split(':', 1)
            print(role, end='')
            print('  said : ', end='')
            print(line_spoken, end='')
        except:
            pass
    data.close()
except:
    print('The data file is missing?')
