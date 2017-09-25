"""
 키워드: python, 파이썬, 커맨드라인 옵션, argument parser, argparse, command parser,
 파이썬 인자 받기, 파이썬 명령행 인자 받기, verbose options, logging level, 로깅 레벨, 파이썬 로깅

문제:
파이썬 모듈을 실행할 때, -v 또는 --verbose 옵션을 인자로 전달해서 로깅 레벨을 설정하고 싶다.


해결책:

역시 스택오버플로우에 해답이 있다.ㅎㅎ

커맨드라인 옵션을 파싱하는 목적의 argparse 모듈이 있고,
아래처럼 사용하면 간단히 구현할 수 있다.
"""


import argparse
import logging

parser = argparse.ArgumentParser(
    description='A test script for http://stackoverflow.com/q/14097061/78845'
)
parser.add_argument("-v", "--verbose", help="increase output verbosity",
                    action="store_true") # action="store_true"는 옵션이 있을 경우 True로 설정한다는 의미이다.

args = parser.parse_args()
if args.verbose: # 옵션이 있다면, 로깅 레벨을 디버그로 설정한다.
    logging.basicConfig(level=logging.DEBUG)

logging.debug('Only shown in debug mode')

"""/*

참고:
http://stackoverflow.com/questions/14097061/easier-way-to-enable-verbose-logging
https://docs.python.org/2/howto/argparse.html

파이썬 로깅에 대해 친절히 설명해둔 블로그가 있다. (한글)
http://gyus.me/?p=418
*/"""
