// LambdaCap01.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
