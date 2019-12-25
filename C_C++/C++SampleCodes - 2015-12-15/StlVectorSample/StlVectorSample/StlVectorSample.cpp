// StlVectorSample.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//요소가 int이고 개수가 3개인 벡터 선언
	vector<int> vec(3);
	vec[0] = 10;
	vec[1] = 20;
	vec[2] = 20;

	for (auto &n : vec)
		cout << n << '\t';
	cout << endl;

	//뒤에 새로운 요소 두 개를 더 추가한다.
	vec.push_back(30);
	vec.push_back(40);

	for (auto &n : vec)
		cout << n << '\t';
	cout << endl;
	return 0;
}

