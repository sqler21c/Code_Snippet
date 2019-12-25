// BroadcastSender.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <winsock2.h>
#pragma comment(lib, "ws2_32")


void ErrorHandler(const char *pszMessage)
{
	printf("ERROR: %s\n", pszMessage);
	::WSACleanup();
	exit(1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	//윈속 초기화
	WSADATA wsa = { 0 };
	if (::WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		ErrorHandler("윈속을 초기화 할 수 없습니다.");

	//소켓 생성
	SOCKET hSocket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (hSocket == INVALID_SOCKET)
		ErrorHandler("UDP 소켓을 생성할 수 없습니다.");

	//포트 바인딩
	SOCKADDR_IN	addr = { 0 };
	addr.sin_family				= AF_INET;
	addr.sin_port				= htons(25000);
	addr.sin_addr.S_un.S_addr	= htonl(INADDR_BROADCAST);

	//
	int nOption = 1;
	::setsockopt(hSocket,
		SOL_SOCKET,
		SO_BROADCAST,
		(const char*)&nOption,
		sizeof(nOption));

	char szBuffer[128] = { 0 };
	while (1)
	{
		//사용자로부터 문자열을 입력 받는다.
		gets_s(szBuffer);
		if (strcmp(szBuffer, "EXIT") == 0)		break;

		//
		::sendto(hSocket, szBuffer, sizeof(szBuffer), 0,
			(const SOCKADDR*)&addr, sizeof(addr));
	}

	::closesocket(hSocket);
	::WSACleanup();
	return 0;
}

