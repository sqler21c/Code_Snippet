GetModuleFileName
우선 중요 API 는 위의 GetModuleFileName 입니다.
아주 오래전에 GetCurrentDirectory 라는 API 로 사용했다가 낭패를 본적이 있습니다.
이 GetCurrentDirectory 프로그램의 작업디렉토리이지 절대 프로그램이 존재하는 디렉토리가 아닙니다.


DWORD WINAPI GetModuleFileName(HMODULE hModule, LPSTR IpFileName, DWORD nSize)
첫번째 인수를 살펴보면 현재 실행되고 있는 모듈의 핸들 또는 NULL이 옵니다.
        만약 첫번째 인수로 NULL이 온다면, 자신의 실행 경로를 반환합니다.
두번째 인수는 자신의 실행 경로를 받을 포인터가,
세번째 인수로는 자신의 실행 경로가 들어갈 버퍼의 길이를 말합니다.

GetModuleFileName API 함수를 통해, 자신의 실행 경로를 받아와보도록 합시다.

#include <stdio.h>
#include <windows.h>

int main()
{
    char Path[MAX_PATH];
    GetModuleFileName(NULL, Path, MAX_PATH);

    printf("%s\n", Path);
    return 0;
}
결과:
D:\WORK\Test\Debug\Test.exe
계속하려면 아무 키나 누르십시오 . . .

첫번째 인수를 NULL로 준 덕분에, Path에 자신의 실행 경로가 들어갑니다. 출력해보면, 실행 경로가 출력됨을 확인하실 수 있습니다.
그러나 문제점이 있습니다.
실행 파일의 파일명까지 반환됐네요..
우리가 원하는것은 폴더만 구하는 것입니다.
위 실행경로에서 파일명을 자르는 방법은 다양합니다. 그중 몇가지 소개해 드리겠습니다.

1. CString 의 Left 메소드를 이용하여 자르는 방식
CString GetProgPath()
{
    TCHAR szTemp[300];
    ::GetModuleFileName(NULL, szTemp, 300);
    CString path = szTemp;
    if (0 < path.ReverseFind('\\')) {
        path = path.Left(path.ReverseFind('\\'));
    }
    return path;
}


2. Win32API 인 PathRemoveFileSpec 를 이용하는 방법
PathRemoveFileSpec 는 파일명이 포함된 경로에서 파일명을 제외한 Path 만을 남겨줍니다.

MSDN 의 예제를 잠시 살펴 보겠습니다.
#include <windows.h>
#include <iostream.h>
#include "Shlwapi.h"

void main( void )
{
    // Path to include file spec.
    char buffer_1[ ] = "C:\\TEST\\sample.txt";
    char *lpStr1;
    lpStr1 = buffer_1;

    // Print the path with the file spec.
    cout << "The path with file spec is          : " << lpStr1 << endl;

    // Call to "PathRemoveFileSpec".
    PathRemoveFileSpec(lpStr1);

    // Print the path without the file spec.
    cout << "\nThe path without file spec is       : " << lpStr1 << endl;
}
우리가 원하는 Api  이네요.
자 그럼 실행 파일 경로를 구해보죠

CString GetProgPath()
{
    TCHAR szTemp[300];
    ::GetModuleFileName(NULL, szTemp, 300);
    PathRemoveFileSpec(szTemp)
}
와우 참 쉽죠..
참고로 파일명에서 확장자만 따라 분리하는 API 도 존재합니다.
PathFindExtension 입니다.
PathFindExtension(a.cpp) 일경우 .cpp 만을 분리해 냅니다.

3 _tsplitpath_s  라는 함수로 경로를 분리
드라이브, 폴더, 파일이름, 확장자 이렇게 4로 분리 할수 있는데
분리된 토큰중 드라이브와 폴더를 남기고 다시 조합하는 방법입니다.

_tsplitpath_s  는 경로에서 분리하는 것이고
_tmakepath_s 는 분리된 토큰을 붙이는 함수입니다.

TCHAR lpszFilePath [_MAX_PATH];
if (::GetModuleFileName (NULL, lpszFilePath, _MAX_PATH) > 0)
{
            TCHAR path_buffer[_MAX_PATH];
            TCHAR drive[_MAX_DRIVE];
            TCHAR dir[_MAX_DIR];
            TCHAR fname[_MAX_FNAME];
            TCHAR ext[_MAX_EXT];

            _tsplitpath_s (lpszFilePath, drive, _MAX_DRIVE, dir, _MAX_DIR, NULL, 0, NULL, 0);
            _tsplitpath_s (strFileName, NULL, 0, NULL, 0, fname, _MAX_FNAME, ext, _MAX_EXT);
            _tmakepath_s (path_buffer, drive, dir, fname, ext);

}
출처: http://ds3evx.tistory.com/entry/MFC-Tip-실행-파일-폴더-구하기 [Haro's Development Story]
