// CallByReference.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//�Ű������� int�� ���� ���������̴�.
void TestFunc(int &rParam)
{
	//��ȣ���� �Լ����� ������ ���� �����ߴ�.
	rParam = 100;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nData = 0;
	//������ ���� �μ������̴�.
	TestFunc(nData);
	cout << nData << endl;
	return 0;
}

