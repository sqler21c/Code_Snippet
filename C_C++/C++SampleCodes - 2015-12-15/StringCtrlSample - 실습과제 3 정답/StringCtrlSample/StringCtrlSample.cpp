// StringCtrlSample.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MyString.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyString strData, strTest;
	strData.SetString("Hello");
	strTest.SetString("World");

	//���� ����
	CMyString strNewData(strData);
	cout << strNewData.GetString() << endl;

	//�ܼ� ���� ������ ȣ��
	strNewData = strTest;
	cout << strNewData.GetString() << endl;
	return 0;
}


