# logging03.py
import logging
import mymath

logging.basicConfig(
    level=logging.DEBUG, 
    format='%(levelname)s:%(module)s(%(lineno)s):%(funcName)s:%(message)s')
logging.info('debug message')
mymath.add(2,3)
