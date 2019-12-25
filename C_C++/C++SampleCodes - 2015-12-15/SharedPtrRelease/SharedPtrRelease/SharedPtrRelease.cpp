// SharedPtrRelease.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	//대상 객체를 수동으로 삭제한다.
	ptr1.reset();
	cout << "**********" << endl;
	return 0;
}

