// StringCtrlSample.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MyStringEx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyString b("World"), c;
	c = "Hello" + b;
	cout << c << endl;
	return 0;
}

