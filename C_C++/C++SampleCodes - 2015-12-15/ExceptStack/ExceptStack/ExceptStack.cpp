// ExceptStack.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void TestFunc1()
{
	//�� ���� �������� ȣ��� �Լ��� ���ܸ� ������.
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
		//�Լ����� ��ȯ���� �ʰ� ������ ��� Ǯ���� �帧�� �Ѿ�´�.
		cout << "Exception handling" << endl;
	}
	return 0;
}

