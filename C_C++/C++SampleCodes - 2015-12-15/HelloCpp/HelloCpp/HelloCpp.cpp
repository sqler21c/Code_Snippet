// HelloCpp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <cstdio>

//제작자의 코드
class USERDATA
{
public:
	//멤버 변수 선언
	int nAge;
	char szName[32];
	//멤버 함수 선언 및 정의
	void Print(void)
	{
		//※ nAge와 szName은 Print() 함수의 지역변수가 아니다!
		printf("%d, %s\n", nAge, szName);
	}
};

//사용자의 코드
int _tmain(int argc, _TCHAR* argv[])
{
	USERDATA user = { 10, "철수" };
	user.Print();
	return 0;
}

