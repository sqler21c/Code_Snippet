// FunctionObject.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//�Լ� ��ü Ŭ������ ���� �� ����
class Add
{
public:
	//�Լ� ȣ�� �����ڸ� �����ε��Ѵ�.
	int operator()(int a, int b)
	{
		cout << "()(int, int)" << endl;
		return a + b;
	}
	//�پ��� �Ű����� �������� �������� �� �� �ִ�.
	double operator()(double a, double b)
	{
		cout << "()(double, double)" << endl;
		return a + b;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Add adder;
	//�Լ� ��ü�� ȣ���Ѵ�. 
	cout << adder(3, 4) << endl;
	cout << adder(3.3, 4.4) << endl;

	return 0;
}

