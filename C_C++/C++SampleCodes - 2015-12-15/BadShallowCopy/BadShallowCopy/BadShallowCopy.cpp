#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//��'��'
	int *pA, *pB;
	//�� ģ���� �׳� ź��
	pA = new int;
	*pA = 10;
	//�ڱ� ����ģ�� ���ΰ� ģ���� ģ���� ������ ���� �ٺ�.
	pB = new int;
	pB = pA;
	//�׷��� ��� �� ������ ��ó�� ���δ�.
	cout << *pA << endl;
	cout << *pB << endl;
	//�׷� �̰�?
	delete pA;
	delete pB;
	return 0;
}
