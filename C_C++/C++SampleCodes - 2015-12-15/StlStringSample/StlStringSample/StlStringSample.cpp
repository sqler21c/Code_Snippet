// StlStringSample.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
//string Ŭ������ ����ϱ� ���� ���
#include <string>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string strName;
	cout << "�̸�: ";
	cin >> strName;
	cout << "����� �̸��� " + strName + "�Դϴ�." << endl;

	std::string strData("Hello");
	if (strData == "World")
		cout << "Same" << endl;
	return 0;
}

