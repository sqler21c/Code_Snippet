// InheritOperOver.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam) :m_nData(nParam) {}

	CMyData operator + (const CMyData &rhs)
	{
		return CMyData(m_nData + rhs.m_nData);
	}

	CMyData& operator = (const CMyData &rhs)
	{
		m_nData = rhs.m_nData;
		return *this;
	}

	operator int() { return m_nData; }

private:
	int m_nData = 0;
};

class CMyDataEx : public CMyData
{
public:
	CMyDataEx(int nParam) : CMyData(nParam) {}
	//�������̽��� �����ֱ� ���� ������ �����ε�.
	using CMyData::operator+;
	using CMyData::operator=;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyData a(3), b(4);
	cout << a + b << endl;

	CMyDataEx c(3), d(4), e(0);
	e = c + d;
	cout << e << endl;
	return 0;
}

