#pragma once
class CMyString
{
public:
	CMyString();
	//���� ������
	CMyString(const CMyString &rhs);
	~CMyString();
private:
	// ���ڿ��� ����� ���� �Ҵ��� �޸𸮸� ����Ű�� ���� ������.
	char* m_pszData;
	// ����� ���ڿ��� ����
	int m_nLength;
public:
	int SetString(const char* pszParam);
	//��� �б⸸ �����ϹǷ� �޼��带 ���ȭ �Ѵ�.
	const char* GetString() const;
	void Release();
	CMyString& operator=(const CMyString & rhs);
};

