// UniquePtrSample.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	unique_ptr<CTest> ptr1(new CTest);
	//�Ʒ� �ڵ���� ��� ������ ������ �߻��Ѵ�.
//	unique_ptr<CTest> ptr2(ptr1);
//	ptr2 = ptr1;
	return 0;
}

