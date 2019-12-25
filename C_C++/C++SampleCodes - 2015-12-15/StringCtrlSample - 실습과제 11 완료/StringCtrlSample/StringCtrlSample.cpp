// StringCtrlSample.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MyStringEx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyStringEx strTest;
	strTest.SetString("멍멍이아들");
	cout << strTest << endl;
	return 0;
}

