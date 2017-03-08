/*
위의 소스를 컴파일합니다.$ gcc -o log_test log_test.c log_util.c -I./

로그레벨을 TRACE로 조정합니다.
$ export LOG_LEVEL=TRACE

프로그램을 컴파일한 프로그램을 실행합니다.
$ ./logtest

실행 결과 log_test-20161204.log 파일이 생성됩니다.

log_test-20161204.log 파일의 내용입니다.
로그레벨 로그생성일:시분마이크로초:프로세스ID:소스파일:함수(라인수) : 출력내용의 format으로 출력됩니다.

example). log_test-20161204.log
(T) 20161204:114121788079:03043:log_test.c:main(22)                               : TRACE LOG...1
(D) 20161204:114121788211:03043:log_test.c:main(23)                               : TEST
(T) 20161204:114121788216:03043:log_test.c:main(24)                               : TRACE LOG...2
(T) 20161204:114121788218:03043:log_test.c:main(25)                               : ret = my_test_test_func(value) #### starting...
(T) 20161204:114121788221:03043:log_test.c:my_test_test_func(8)                   : TRACE LOG...1
(D) 20161204:114121788223:03043:log_test.c:my_test_test_func(9)                   : TEST
(T) 20161204:114121788230:03043:log_test.c:my_test_test_func(11)                  : TRACE LOG...2
(D) 20161204:114121788233:03043:log_test.c:my_test_test_func(12)                  : sample test
(T) 20161204:114121788235:03043:log_test.c:main(25)                               : ret = my_test_test_func(value) #### end.
(D) 20161204:114121788238:03043:log_test.c:main(26)                               : sample test
(T) 20161204:114121788240:03043:log_test.c:main(27)                               : TRACE LOG...3
(E) 20161204:114121788242:03043:log_test.c:main(28)                               : sample test 오류입니다.
(T) 20161204:114121788245:03043:log_test.c:main(29)                               : TRACE LOG...4


*/

#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include <log_util.h>

int my_test_test_func(int value)
{
    LOG_TRACE("TRACE LOG...1");
    LOG_DEBUG("TEST");
printf("%d\n", value);
    LOG_TRACE("TRACE LOG...2");
    LOG_DEBUG("%s", "sample test");
}

int main(int argc, char **argv)
{
    int ret;
    int value = 0;

    /*    * 로그의 위치는 현재 디렉토리에 생성하고 로그 파일명은 실행파일명-yyyymmdd.log
    * 로 설정합니다.
    */
    LOGsetInfo(".", basename(argv[0]));

    LOG_TRACE("TRACE LOG...1");
    LOG_DEBUG("TEST");
    LOG_TRACE("TRACE LOG...2");
    LOG_CALL(ret = my_test_test_func(value));
    LOG_DEBUG("%s", "sample test");
    LOG_TRACE("TRACE LOG...3");
    LOG_ERROR("%s 오류입니다.", "sample test");
    LOG_TRACE("TRACE LOG...4");
    return 0;
}
