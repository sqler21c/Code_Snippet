// AddressBook_OOP.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "UserInterface.h"
#include "MyListEx.h"
#include "UserData.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyListEx DB( new CUserData("Dummy","Head") );
	CUserInterface UI(DB);
	UI.Run();
	return 0;
}

