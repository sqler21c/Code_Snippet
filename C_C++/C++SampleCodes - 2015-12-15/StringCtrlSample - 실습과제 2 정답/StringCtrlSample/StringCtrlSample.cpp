// StringCtrlSample.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MyString.h"

void TestFunc(const CMyString &param)
{
	cout << param.GetString() << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CMyString strData;
	strData.SetString("Hello");
	TestFunc(strData);
	return 0;
}
