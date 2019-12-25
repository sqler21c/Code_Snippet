# args03.py
import sys
import argparse

parser = argparse.ArgumentParser(description='variable arguement list example')

parser.add_argument('files', nargs='*')  # 0개 이상. + 면 1개 이상, ?면 0개 혹은 1개

args = parser.parse_args(sys.argv[1:])
print (args.files)
