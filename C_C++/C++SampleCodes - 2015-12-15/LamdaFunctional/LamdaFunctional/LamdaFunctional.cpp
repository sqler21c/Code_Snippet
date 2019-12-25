// LamdaFunctional.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
//std::function ��ü�� ����ϱ� ���� ��� �߰�
#include <functional>
#include <iostream>
using namespace std;

//std::function ���ø� Ŭ������ �Ű������� �޴´�.
void TestFunc(char* pszParam, std::function<int (char*, int)> param)
{
	cout << pszParam << endl;
	param("Hello", 10);
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	::TestFunc(
		"TestFunc()",
		//�Լ��� ���μ��� �Լ� ��ü�� ���ٽ����� ����ߴ�.
		[](char *pszParam, int nParam)->int
		{
			cout << pszParam << " : " << nParam << endl;
			return 0;
		}
	);
	cout << "******End******" << endl;
	return 0;
}

