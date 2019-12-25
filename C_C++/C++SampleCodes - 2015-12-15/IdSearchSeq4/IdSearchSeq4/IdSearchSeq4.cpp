// IdSearchSeq4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include <iostream>
using namespace std;

int nData = 100;
namespace TEST
{
	int nData = 200;
}

using namespace TEST;
int _tmain(int argc, _TCHAR* argv[])
{
	cout << nData << endl;
	return 0;
}

