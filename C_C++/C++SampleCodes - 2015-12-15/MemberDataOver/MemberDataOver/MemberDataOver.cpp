// MemberDataOver.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//�ʱ� ������
class CMyData
{
public:
	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

protected:
	//�Ļ� ���Ŀ��� ������ �� �ִ�.
	int m_nData = 0;
};

//�ı� ������
class CMyDataEx : public CMyData
{
public:
	void SetData(int nParam)
	{
		if (nParam > 10)	nParam = 10;
		//�� �Ļ� ������ m_nData�� �����ϴ� ���̴�!
		m_nData = nParam;
	}

protected:
	//�Ļ� ���Ŀ��� �⺻ ���İ� ���� ����� �������ߴ�.
	int m_nData = 0;
};

//�����
int _tmain(int argc, _TCHAR* argv[])
{
	CMyDataEx a;
	a.SetData(15);
	cout << a.GetData() << endl;
	return 0;
}

