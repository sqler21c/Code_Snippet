// InheritAndConstructor.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CMyDataA
{
public:
	CMyDataA() {
		cout << "CMyDataA()" << endl;
		m_pszData = new char[32];
	}
	~CMyDataA() {
		cout << "~CMyDataA()" << endl;
		delete m_pszData;
	}

protected:
	char *m_pszData;
};

class CMyDataB : public CMyDataA
{
public:
	CMyDataB() {
		cout << "CMyDataB()" << endl;
	}
	~CMyDataB() {
		cout << "~CMyDataB()" << endl;
	}
};

class CMyDataC : public CMyDataB
{
public:
	CMyDataC() {
		cout << "CMyDataC()" << endl;
	}
	~CMyDataC() {
		cout << "~CMyDataC()" << endl;
		//�Ļ� Ŭ�������� �θ� Ŭ���� ��� �޸𸮸� �����ߴ�.
		delete m_pszData;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	CMyDataC data;
	cout << "******End******" << endl;
	return 0;
}

