// OperOverAssign.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//������ �ڵ�
class CMyData
{
public:
	explicit CMyData(int nParam)
	{
		m_pnData = new int(nParam);
	}

	~CMyData() { delete m_pnData; }

	operator int() { return *m_pnData; }

	//�ܼ� ���� ������ �����ε�
	CMyData& operator = (const CMyData &rhs)
	{
		//r-value�� �ڽ��̸� ������ �������� �ʴ´�.
		if (this == &rhs)		return *this;

		delete m_pnData;
		m_pnData = new int(*rhs.m_pnData);
		return *this;
	}

	CMyData& operator += (const CMyData &rhs)
	{
		//���� �� ó��
		int *pnNewData = new int(*m_pnData);
		//������ �� ó��
		*pnNewData += *rhs.m_pnData;

		//���� �����͸� �����ϰ� �� �޸𸮷� ��ü
		delete m_pnData;
		m_pnData = pnNewData;
		return *this;
	}

private:
	int *m_pnData = nullptr;
};

//����� �ڵ�
int _tmain(int argc, _TCHAR* argv[])
{
	CMyData a(0), b(5), c(10);
	a += b;
	a += c;
	cout << a << endl;
	return 0;
}

