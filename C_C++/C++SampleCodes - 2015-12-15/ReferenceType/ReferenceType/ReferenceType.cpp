// ReferenceType.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int nData = 10;
	//nData ������ ���� ������ ����
	int &ref = nData;
	//�� �����ڷ� ���� �����ϸ� ������ ����ȴ�!
	ref = 20;
	cout << nData << endl;

	//�����͸� ���� �Ͱ� ����ϴ�.
	int *pnData = &nData;
	*pnData = 30;
	cout << nData << endl;
	return 0;
}

