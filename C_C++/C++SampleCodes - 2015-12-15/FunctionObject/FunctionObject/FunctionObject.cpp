// FunctionObject.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//함수 객체 클래스의 선언 및 정의
class Add
{
public:
	//함수 호출 연산자를 오버로딩한다.
	int operator()(int a, int b)
	{
		cout << "()(int, int)" << endl;
		return a + b;
	}
	//다양한 매개변수 구성으로 다중정의 할 수 있다.
	double operator()(double a, double b)
	{
		cout << "()(double, double)" << endl;
		return a + b;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Add adder;
	//함수 객체로 호출한다. 
	cout << adder(3, 4) << endl;
	cout << adder(3.3, 4.4) << endl;

	return 0;
}

