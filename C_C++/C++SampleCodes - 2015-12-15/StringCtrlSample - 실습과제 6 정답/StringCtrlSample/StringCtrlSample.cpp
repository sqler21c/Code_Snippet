// StringCtrlSample.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MyString.h"

void TestFunc(const CMyString &strParam)
{
	cout << strParam[0] << endl;
	cout << strParam[ strParam.GetLength() - 1 ] << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CMyString strParam("HelloWorld");
	cout << strParam << endl;
	TestFunc(strParam);
	return 0;
}

