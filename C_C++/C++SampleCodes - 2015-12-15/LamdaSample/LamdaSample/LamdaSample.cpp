// LamdaSample.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int TestFunc(int nParam)
{
	cout << "Function Pointer: " << nParam << endl;
	return nParam;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//람다식 선언 및 정의
	auto func = [](int nParam) -> int
	{
		cout << "Lamda: " << nParam << endl;
		return nParam;
	};

	//람다식 호출
	func(5);
	//함수 포인터를 이용한 호출
	auto pfTest = TestFunc;
	pfTest(10);
	return 0;
}

