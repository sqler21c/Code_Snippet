# args02.py
import argparse

parser = argparse.ArgumentParser(description='fixed size arguement list example')

parser.add_argument('size', nargs=2)

args = parser.parse_args('1024 768'.split())
print (args.size)

