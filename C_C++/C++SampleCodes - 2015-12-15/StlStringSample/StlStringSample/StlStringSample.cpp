// StlStringSample.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
//string 클래스를 사용하기 위한 헤더
#include <string>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string strName;
	cout << "이름: ";
	cin >> strName;
	cout << "당신의 이름은 " + strName + "입니다." << endl;

	std::string strData("Hello");
	if (strData == "World")
		cout << "Same" << endl;
	return 0;
}

