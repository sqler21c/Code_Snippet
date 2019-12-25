// StringCtrlSample.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MyStringEx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyStringEx strTest;
	//문자열이 필터링 되어 대체되는 경우
	strTest.SetString("멍멍이아들");
	cout << strTest << endl;
	//필터링 되지 않는 경우
	strTest.SetString("Hello");
	cout << strTest << endl;
	return 0;
}

