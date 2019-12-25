# args04.py
import sys
import argparse

parser = argparse.ArgumentParser(description='options example')

parser.add_argument('count', type=int)  # 기본 action:”store”
parser.add_argument('units', type=float) # 필수 고정 인수들.. float로 형변환된다.

# 기본 자료형:문자열. 기본 action:“store” 기본값:None ↓
parser.add_argument('-m')
# int로 형변환. 기본값은 None ↓
parser.add_argument('-s', action="store", type=int) 
# rate란 이름에 저장. 기본 값은 1.0 ↓
parser.add_argument('-r', dest="rate", type=float, default=1.0) 
# -t가 사용되면 True 저장. 기본 값은 False ↓
parser.add_argument('-t', action="store_true", default=False, help='default=False') 
# -f가 사용되면 False 저장. 기본 값은 True ↓
parser.add_argument('-f', action="store_false", default=True, help='default=True') 
# 롱옵션. 지정된 값이 int로 변환되어 height에 저장. ↓
parser.add_argument('--height', action="store", type=int, default=512, help='높이 설정') 
# 기본 값은 None이나 --big이 지정되면 2.0이 저장된다. ↓
parser.add_argument('--big', action="store_const", const=2.0, help='make it big..') 
parser.add_argument('-a', action="append", type=int)       # 결과가 모아진다
parser.add_argument('-v', action="append_const", const='v') # 상수 결과가 모아진다

# 사용 예. 코드 안에서 테스트 하기 위해 인수를 직접 입력해본다.
args = parser.parse_args('3 2.54'.split())    # 고정 인수 리스트
print (1, args.count, args.units, args)    # 필수 인수 + 기본값 출력
print (2, parser.parse_args('-mmsg -s1024 3 2.54 '.split()))    # short option에 인수 붙여쓸 경우
print (3, parser.parse_args('-m msg -r 0.9 -s 1024 3 2.54 '.split())) # short option에 인수 띄어쓸 경우
print (5, parser.parse_args('-t -f 3 2.54'.split()))           # 부울값..
args = parser.parse_args('3 2.54 --height 2048'.split())
print (6, 'height={} big={}'.format(args.height, args.big))   # long option 
args = parser.parse_args('3 2.54 --big'.split())
print (7, 'big={}'.format(args.big))           # store_const
args = parser.parse_args('3 2.54 -a 1 -a 2 -a 3'.split())
print (8, 'a={}'.format(args.a))           # append
args = parser.parse_args('3 2.54 -v -v -v'.split())
print (9, 'v={}'.format(args.v))           # append_const
