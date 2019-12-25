#pragma once
class CMyString
{
public:
	CMyString();
	~CMyString();
private:
	// 문자열이 저장될 동적 할당한 메모리를 가리키기 위한 포인터.
	char* m_pszData;
	// 저장된 문자열의 길이
	int m_nLength;
public:
	int SetString(const char* pszParam);
	//멤버 읽기만 수행하므로 메서드를 상수화 한다.
	const char* GetString() const;
	void Release();

};

