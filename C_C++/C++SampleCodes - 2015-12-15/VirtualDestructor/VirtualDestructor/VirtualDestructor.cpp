// VirtualDestructor.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//������ �ڵ�
class CMyData
{
public:
	CMyData() { m_pszData = new char[32]; }
	//�Ҹ��ڸ� ���� �Լ��� ����
	virtual ~CMyData()
	{
		cout << "~CMyData()" << endl;
		delete m_pszData;
	}

private:
	char *m_pszData;
};

class CMyDataEx : public CMyData
{
public:
	CMyDataEx() { m_pnData = new int; }
	~CMyDataEx()
	{
		cout << "~CMyDataEx()" << endl;
		delete m_pnData;
	}

private:
	int *m_pnData;
};

//����� �ڵ�
int _tmain(int argc, _TCHAR* argv[])
{
	CMyData *pData = new CMyDataEx;
	//�Ҹ��ڰ� ����ȭ �Ǹ� �������� �Ҹ��ڰ� ȣ��ȴ�.
	delete pData;
	return 0;
}

