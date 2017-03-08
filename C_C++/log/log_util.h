/*
클리핑 출처: http://downman.tistory.com/155

Log 생성하기

프로그램을 개발할 때에, 중요한 요소 중의 하나가 쉽게 디버깅하고, runtime시에 발생한 오류에 대해서도 오류상태 값을 표시하여 빠른게 오류를 fix해야 합니다. 이를 위하여 프로그램에서는 log를 파일로 생성합니다. 로그레벨에 따라서 개발시에는 debug용으로 runtime시에는 오류로그만 생성한다든지 하여 성능문제가 발생하지 않도록 해야합니다. 새로운 프로젝트나 프로그램을 개발할 때에 로그를 생성하는 함수들을 만드는 것 자체도 쉽지 않습니다.
그래서 printf(3)함수로 로그를 출력하다가 오류가 fix되면 지운다든 지, 아니면 #if _DEBUG ~ #endif 에 printf(3)를 잔뜩 표시해서 컴파일시 -D_DEBUG option을 주어 debug을 켰다가 껐다가 하는 등, 귀찮은 일입니다.

log 생성 요건
로그 파일을 생성하는 요건들에는 어떤 것들이 있을까요?
   1. 로그레벨을 조정할 수 있어야 함. (trace, debug, info, warning, error, fatal)
   2. 프로그램의 재컴파일없이 로그 레벨을 조정할 수 있어야 함.
   3. 로그가 생성된 위치정보를 정확 표시되어야 함. (어느 소스, 어느 함수의 몇번째 라인)
   4. 로그를 생성한 시간이 찍혀야 함. (구간별 성능 확인 등에 사용)
   5. 어느 프로세스가 수행했는 지 확인 필요함. (pid를 로깅함)
   6. 날짜가 변경되면 자동으로 로그 파일이 날짜에 연동하여 새로운 파일로 변경되어야 함.      (오랫동안 실행되는 daemon 프로그램 들에서 유효함)
위의 요건들을 충족하도록 source를 만들었습니다.

사용방법
   1. 로그레벨에 맞는 함수를 사용하여 로그를 생성함.
      상세한 디버그용 - 주로 시스템 공통 등 : LOG_TRACE( )      일반 디버그용: LOG_DEBUG( )
      중요 정보 로깅용: LOG_INFO( )
      경고 로그용: LOG_WARNING( )
      오류 로그용: LOG_ERROR( )
      치명적 오류로그용: LOG_FATAL( )
      - 로그를 생성하는 이들 함수의 사용법은 printf(3)와 같으며 단지 new line만 자동으로 붙이므로 \n는 format이 넣지 않음.
      또한 함수의 시작 종료를 찍기 위하여 LOG_CALL( )함수가 있습니다.

   2. 환경변수 LOG_LEVEL의 값을 설정하고 실행하면 자동으로 로그레벨이 변경됨.
       그렇지 않으면 default로 로그레벨은 INFO로 설정됨
     모든 로그를 생성하려면: export LOG_LEVEL=TRACE
     DEBUG 이하만 로그 생성하려면: export LOG_LEVEL=DEBUG
     INFO 이하의 로그만 생성하려면: export LOG_LEVEL=INFO
     WARNING 이하의 로그만 생성하려면: export LOG_LEVEL=WARNING 
     ERROR 이하의 로그만 생성하려면: export LOG_LEVEL=ERROR 
     FATAL 로그만 생성하려면: export LOG_LEVEL=FATAL

   3. 프로그램의 로그 생성 위치와 로그의 prefix 설정
    프로그램이 시작하는 main()함수의 첫번째라인에 LOGsetInfo()호출함.    LOGsetInfo(로그 생성할 디렉토리, 로그파일명); 함수로 설정함.

    ex).
       #include <libgen.h>
       ......
       LOGsetInfo(".", basename(argv[0]));
       현재 디렉토리에 실행파일명 이름을 규칙으로 log 생성 위치 및 이름을 지정함

*/
#ifndef __LOG_UTIL__
#define __LOG_UTIL__

#define LOG_LVL_TRACE   50
#define LOG_LVL_DEBUG   40
#define LOG_LVL_INFO    30
#define LOG_LVL_WARNING 20
#define LOG_LVL_ERROR   10
#define LOG_LVL_FATAL   0

/*
* 각각의 level에서 LOG를 생성가능한 상태인지를 체크하는 macro
*/
#define LOG_IS_TRACE    (LOGgetLevel() >= LOG_LVL_TRACE)
#define LOG_IS_DEBUG    (LOGgetLevel() >= LOG_LVL_DEBUG)
#define LOG_IS_INFO     (LOGgetLevel() >= LOG_LVL_INFO)
#define LOG_IS_WARNING  (LOGgetLevel() >= LOG_LVL_WARNING)
#define LOG_IS_ERROR    (LOGgetLevel() >= LOG_LVL_ERROR)
#define LOG_IS_FATAL    (LOGgetLevel() >= LOG_LVL_FATAL)

int LOGsetInfo(const char *dir, const char *prefix);
int LOGlogging(char log_type, const char *src_file, const char *func, int line_no, const char *fmt, ...);
int LOGsetLevel(int log_lvl);
int LOGgetLevel(void);

/*
* 함수의 실행 시작과 종료를 log로 생성하는 macro 함수
*/
#define LOG_CALL(func)\
LOG_TRACE("%s #### starting...", #func);\
func;\
LOG_TRACE("%s #### end.", #func)

/*
* Trace Log를 생성하는 macro 함수
*/
#define LOG_TRACE(...) \
    do { \
        if(LOG_IS_TRACE) { \
            LOGlogging('T', __FILE__, __func__, __LINE__, __VA_ARGS__);\
        } \
    } while(0)

/*
* debug Log를 생성하는 macro 함수
*/
#define LOG_DEBUG(...) \
    do { \
        if(LOG_IS_DEBUG) { \
            LOGlogging('D', __FILE__, __func__, __LINE__, __VA_ARGS__);\
        } \
    } while(0)

/*
* 중요 정보 Log를 생성하는 macro 함수
*/
#define LOG_INFO(...) \
    do { \
        if(LOG_IS_INFO) { \
            LOGlogging('I', __FILE__, __func__, __LINE__, __VA_ARGS__);\
        } \
    } while(0)

/*
* warning Log를 생성하는 macro 함수
*/
#define LOG_WARNING(...) \
    do { \
        if(LOG_IS_WARNING) { \
            LOGlogging('W', __FILE__, __func__, __LINE__, __VA_ARGS__);\
        } \
    } while(0)

/*
* error Log를 생성하는 macro 함수
*/
#define LOG_ERROR(...) \
    do { \
        if(LOG_IS_ERROR) { \
            LOGlogging('E', __FILE__, __func__, __LINE__, __VA_ARGS__);\
        } \
    } while(0)


/*
* fatal error Log를 생성하는 macro 함수
*/
#define LOG_FATAL(...) \
    do { \
        if(LOG_IS_FATAL) { \
            LOGlogging('F', __FILE__, __func__, __LINE__, __VA_ARGS__);\
        } \
    } while(0)

#endif // __LOG_UTIL__
