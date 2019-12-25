# ex11.py
import math
from turtle import *

reset()

t1 = Turtle()

yamp = 100
xscale = 20
rad = 0
t1.up()
x = math.radians(math.degrees(-6*math.pi))
y = yamp * math.sin(x) / x
t1.goto(x*xscale,y)
t1.down()
for deg in range(int(math.degrees(-6*math.pi)), int(math.degrees(6*math.pi))+1, 10):
    x = math.radians(deg)
    if x == 0:
        y = yamp
    else:
        y = yamp * math.sin(x) / x
    t1.goto(x*xscale, y)

done()
