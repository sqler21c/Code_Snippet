// StringCtrlSample.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MyStringEx.h"		//�� CMyStringEx Ŭ���� ���

int _tmain(int argc, _TCHAR* argv[])
{
	CMyStringEx strTest;
	strTest.SetString("I am a boy.");
	cout << strTest << endl;

	int nIndex = strTest.Find("am");
	cout << "Index: " << nIndex << endl;
	return 0;
}

