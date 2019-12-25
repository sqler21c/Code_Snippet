# args01.py
import sys
import argparse

parser = argparse.ArgumentParser(description='arguments example')

parser.add_argument('count', type=int)
parser.add_argument('units', type=float)
parser.add_argument('msg')

args = parser.parse_args()
print ('count={}  units={}  msg={}'.format(args.count, args.units, args.msg))
print (type(args.count), type(args.units), type(args.msg))
