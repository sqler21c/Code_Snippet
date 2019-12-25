// InheritSample.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//������ - �ʱ� ������
class CMyData
{
public:		//������ ���� ����
	CMyData() { cout << "CMyData()" << endl; }
	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
protected:	//�Ļ� Ŭ������ ���� ����
	void PrintData() { cout << "CMyData::PrintData()" << endl; }
private:	//������ ���� �Ұ���
	int m_nData = 0;
};

//������ - �ı� ������
class CMyDataEx : public CMyData
{
public:
	CMyDataEx() { cout << "CMyDataEx()" << endl; }
	void TestFunc()
	{
		//�⺻ ���� ����� ����
		PrintData();
		SetData(5);
		cout << CMyData::GetData() << endl;
	}
};

//�����
int _tmain(int argc, _TCHAR* argv[])
{
	CMyDataEx data;
	//�⺻ Ŭ����(CMyData) ����� ����
	data.SetData(10);
	cout << data.GetData() << endl;
	//�Ļ� Ŭ����(CMyDataEx) ����� ����
	data.TestFunc();
	return 0;
}

