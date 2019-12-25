def f(i, myList):
    i = i + 1
    myList.append(0)

k = 10
m = [1, 2, 3 ]
t = (1, 3)

f(k, m)
print(k, m)


def total(*number):
    tot = 0
    for n in number:
        tot += n
    return tot

t = total(1,2)
print(t)

class Rectanglesss:
    count = 8

    def __init__(self, width, height):

        self.width = width
        self.height = height
        Rectangle.count += 1

    def calcArea(self):
        area = self.width * self.height
        return area

class Rectangle:
    count = 0 # Class var

    def __init__(self, width, hight):
        self.width = width
        self.height = hight
        Rectangle.count += 1

    def calcArea(self):
        area = self.width * self.height
        return area

    @staticmethod
    def isSquare(rectWidth, rectHight):
        return rectHight == rectWidth

    @classmethod
    def printCount(cls):
        print(cls.count)


#square = Rectangle.isSquare(5,5)
#print("square : ".join(str(square)))
Rectangle.printCount()

rect1 = Rectangle(5,5)
rect2 = Rectangle(2,4)
rect1.printCount()


try:
    fp = open("test.txt", "r")
    try:
        lines = fp.readlines()
        print(lines)
    finally:
        fp.close()
except IOError:
    print("error")

with open("t.t", "r"):
    liene = fp.readlines()
    print(liene)