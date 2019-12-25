// OperOverIncrement.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam) : m_nData(nParam) {}
	//���ĺ�ȯ
	operator int() { return m_nData; }
	//���� ���� ������
	int operator++()
	{
		cout << "operator++()" << endl;
		return ++m_nData;
	}
	//���� ���� ������
	int operator++(int)
	{
		cout << "operator++(int)" << endl;
		int nData = m_nData;
		m_nData++;
		return nData;
	}

private:
	int m_nData = 0;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyData a(10);
	//���� ���� �����ڸ� ȣ���Ѵ�.
	cout << ++a << endl;
	//���� ���� �����ڸ� ȣ���Ѵ�.
	cout << a++ << endl;
	cout << a << endl;
	return 0;
}

