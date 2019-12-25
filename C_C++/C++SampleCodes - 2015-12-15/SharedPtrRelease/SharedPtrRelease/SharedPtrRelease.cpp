// SharedPtrRelease.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "**********" << endl;
	shared_ptr<CTest> ptr1(new CTest);
	cout << "**********" << endl;
	//��� ��ü�� �������� �����Ѵ�.
	ptr1.reset();
	cout << "**********" << endl;
	return 0;
}

