// StringCtrlSample.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MyStringEx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyStringEx strTest;
	//���ڿ��� ���͸� �Ǿ� ��ü�Ǵ� ���
	strTest.SetString("�۸��̾Ƶ�");
	cout << strTest << endl;
	//���͸� ���� �ʴ� ���
	strTest.SetString("Hello");
	cout << strTest << endl;
	return 0;
}

