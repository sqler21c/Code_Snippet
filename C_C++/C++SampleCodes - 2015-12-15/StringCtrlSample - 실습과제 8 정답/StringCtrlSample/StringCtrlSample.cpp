// StringCtrlSample.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MyStringEx.h"		//※ CMyStringEx 클래스 헤더

int _tmain(int argc, _TCHAR* argv[])
{
	CMyStringEx strTest;
	strTest.SetString("I am a boy.");
	cout << strTest << endl;

	int nIndex = strTest.Find("am");
	cout << "Index: " << nIndex << endl;
	return 0;
}

