// OperOverArray.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//제작자 코드
class CIntArray
{
public:
	CIntArray(int nSize)
	{
		//전달 된 개수만큼 int자료를 담을 수 있는 메모리를 확보한다.
		m_pnData = new int[nSize];
		memset(m_pnData, 0, sizeof(int) * nSize);
	}

	~CIntArray() { delete m_pnData; }

	//상수형 참조인 경우의 배열 언산자
	int operator[] (int nIndex) const
	{
		cout << "operator[] const" << endl;
		return m_pnData[nIndex];
	}

	//일반적인 배열 연산자
	int& operator[] (int nIndex)
	{
		cout << "operator[]" << endl;
		return m_pnData[nIndex];
	}
private:
	int *m_pnData;		//배열 메모리
	int m_nSize;		//배열 요소의 개수
};

//사용자 코드
void TestFunc(const CIntArray &arParam)
{
	cout << "TestFunc()" << endl;
	//상수형 참조이므로 'operator[] (int nIndex) const'를 호출한다.
	cout << arParam[3] << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CIntArray arr(5);
	for (int i = 0; i < 5; ++i)
		arr[i] = i * 10;

	TestFunc(arr);
	return 0;
}

