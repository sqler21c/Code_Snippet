// RangeBasedfor.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int aList[5] = {10, 20, 30, 40, 50};
	//1. �������� C��� ��Ÿ�� �ݺ���
	for (int i = 0; i < 5; ++i)
		cout << aList[i] << ' ';
	cout << endl;

	//���� ��� C++11 ��Ÿ�� �ݺ���
	//�� ����� ���� n�� �����Ѵ�.
	for (auto n : aList)
		cout << n << ' ';
	cout << endl;

	//n�� �� ��ҿ� ���� �����̴�.
	for (auto &n : aList)
		cout << n << ' ';
	cout << endl;
	return 0;
}

