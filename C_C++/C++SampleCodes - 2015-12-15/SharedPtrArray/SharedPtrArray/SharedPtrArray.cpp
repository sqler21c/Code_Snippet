// SharedPtrArray.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <memory>
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest()" << endl; }
	~CTest() { cout << "~CTest()" << endl; }
	void TestFunc() { cout << "TestFunc()" << endl; }
};

void RemoveTest(CTest *pTest)
{
	cout << "RemoveTest()" << endl;
	//����� �迭�� �����Ѵ�.
	delete [] pTest;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	//��� ��ü�� �Ҹ��� �Լ��� ������ ����ߴ�.
	shared_ptr<CTest> ptr(new CTest[3], RemoveTest);
	cout << "******End******" << endl;
	return 0;
}

