// AccessCtrl.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//������ �ڵ�
class CMyData
{
	//�� �⺻ �������� �����ڴ� 'private'�̴�.
	CMyData() {};
	int m_nData;

public:
	int GetData(void)			{ return m_nData; 	}
	void SetData(int nParam)	{ m_nData = nParam; }
};

//����� �ڵ�
int _tmain(int argc, _TCHAR* argv[])
{
	CMyData data;
	return 0;
}

