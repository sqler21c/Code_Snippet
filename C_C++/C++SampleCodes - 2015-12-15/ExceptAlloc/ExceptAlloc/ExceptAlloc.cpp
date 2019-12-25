// ExceptAlloc.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <new>		//bad_alloc Ŭ������ ����ϱ� ���� ���
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest(int nSize)
	{
		//�޸� �Ҵ翡 �����ϸ� ���ܸ� ������!
		m_pszData = new char[nSize];
	}

	~CTest()
	{
		delete[] m_pszData;
		cout << "���������� ��ü�� �Ҹ���" << endl;
	}
private:
	char *m_pszData;
};

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		int nSize;
		cout << "Input size: ";
		//����ڰ� �Է��� ���� �������� �״�� ����� ��ü�� ����
		cin >> nSize;
		CTest a(nSize);
	}
	catch (bad_alloc &exp )
	{
		//�ý����� ���� ������ ����Ѵ�.
		cout << exp.what() << endl;
		cout << "ERROR: CTest()" << endl;
	}
	return 0;
}

