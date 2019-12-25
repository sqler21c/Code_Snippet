print('count things')

count = 0
sum = 0

for i in range(1, 11): # i 500원 갯수
    for j in range(1,11): # j 1000원 갯수
        sum = (i*500) + (j*1000)
        if sum == 10000:
            count += 1
            print('500원 갯수는 %d개, 1000원 갯수는 %d' %(i, j))

print('경우의 수는 %', count, '가지 입니다.')


test = [1, 2, 3, 4, 5, 3.5]
print(test[0])
print(test[5])

test1 = [None]
test2 = None
test3 = []
print(test1)
print(test2)
print(test3)
test4 =[['수성', 2440, 0.055],['금성', 6052, 8.815]]
print(test4[0])
print(test4[0][0])

print()
print()

a = 1
def sum():
    #sums = a + b
    #global a 
    a = 10
    print(a, "ID : ", id(a))

sum()
print(a, "ID : ", id(a))

summ=0
def fact(n):
    global summ
    f = 1
    for k in range(1,n+1):
        f *= k
    summ += f
    #print("f : %d" %(f))
    return f
fact(3)

summ = 0
for k in range(1, 6):
    fact(k)

print(type(summ))
print(type("dkdkdk"))
print(type(0.005))

