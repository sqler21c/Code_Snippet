// ClassNew.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CTest
{
	int m_nData;

public:
	CTest()
	{
		cout << "CTest::CTest()" << endl;
	}

	~CTest()
	{
		cout << "~CTest::CTest()" << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Begin" << endl;
	//�迭�� new ������ ������ �� �ִ�.
	CTest *pData = new CTest[3];
	//�迭�� ������ ���� �ݵ�� �迭�� �����Ѵ�!
	delete [] pData;
	cout << "End" << endl;
	return 0;
}

