// QuickSortSample.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//����ڴ� �� ���� ���ϴ� ����� �����ؾ� �Ѵ�.
int CompareData(const void *pLeft, const void *pRight)
{
	return *(int *)pRight - *(int *)pLeft;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int aList[5] = {30, 50, 10, 20, 40};
	//�� ���� ���ϴ� ���(�Լ��ּ�)�� Call back �Լ��� �����Ѵ�.
	qsort(aList, 5, sizeof(int), CompareData);

	for(auto &n : aList)
		cout << n << '\t';
	cout << endl;
	return 0;
}

