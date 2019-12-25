// OperOverArithmetic.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CMyData
{
public:
	//��ȯ ������
	CMyData(int nParam)	: m_nData(nParam)
	{	cout << "CMyData(int)" << endl; }
	//���� ������
	CMyData(const CMyData &rhs) : m_nData(rhs.m_nData) {
		cout << "CMyData(const CMyData &)" << endl; }
	//�̵� ������
	CMyData(const CMyData &&rhs) : m_nData(rhs.m_nData) {
		cout << "CMyData(const CMyData &&)" << endl;
	}

	//���ĺ�ȯ
	operator int() { return m_nData; }

	//+
	CMyData operator+(const CMyData &rhs)
	{
		cout << "operator+" << endl;
		CMyData result(0);
		result.m_nData = this->m_nData + rhs.m_nData;
		return result;
	}

	//=
	CMyData& operator=(const CMyData &rhs)
	{
		cout << "operator=" << endl;
		m_nData = rhs.m_nData;
		return *this;
	}

private:
	int m_nData = 0;
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	CMyData a(0), b(3), c(4);
	//b + c ������ �����ϸ� �̸� ���� �ӽ� ��ü�� ���������
	//a�� �����ϴ� ���� �� �ӽ� ��ü��.
	a.operator=( b.operator+(c) );
	cout << a << endl;
	cout << "******End******" << endl;
	return 0;
}

