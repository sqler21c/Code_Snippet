// LambdaCap01.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <functional>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int nData = 10;
	cout << nData << endl;
	std::function<void(void)> TestFunc = [nData, &nData](void)->void
	{
		cout << nData << endl;
	};

	TestFunc();

	return 0;
}
