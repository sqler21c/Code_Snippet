// ExceptStack.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void TestFunc1()
{
	//※ 가장 마지막에 호출된 함수가 예외를 던진다.
	cout << "***TestFunc1() - Begin***" << endl;
	throw 0;
	cout << "****TestFunc1() - End****" << endl;
}

void TestFunc2()
{
	cout << "***TestFunc2() - Begin***" << endl;
	TestFunc1();
	cout << "****TestFunc2() - End****" << endl;
}

void TestFunc3()
{
	cout << "***TestFunc3() - Begin***" << endl;
	TestFunc2();
	cout << "****TestFunc3() - End****" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		TestFunc3();
	}
	catch (...)
	{
		//함수들이 반환하지 않고 스택이 즉시 풀리고 흐름이 넘어온다.
		cout << "Exception handling" << endl;
	}
	return 0;
}

