# ex09.py
import math
from turtle import *

reset()

yamp = 100
for deg in range(0, 361, 10):
    rad = math.radians(deg)
    y = yamp * math.sin(rad)
    goto(rad*50, y)

done()
