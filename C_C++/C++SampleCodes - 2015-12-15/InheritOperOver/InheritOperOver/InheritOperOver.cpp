// InheritOperOver.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	//인터페이스를 맞춰주기 위한 연산자 오버로딩.
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

