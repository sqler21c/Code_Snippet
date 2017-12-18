
//UTF-8 문자열을 ANSI 문자열
char* ANSIToUTF8(const char * pszCode)
{
    int     nLength, nLength2;
    BSTR    bstrCode;
    char*   pszUTFCode = NULL;

    nLength = MultiByteToWideChar(CP_ACP, 0, pszCode, lstrlen(pszCode), NULL, NULL);
    bstrCode = SysAllocStringLen(NULL, nLength);
    MultiByteToWideChar(CP_ACP, 0, pszCode, lstrlen(pszCode), bstrCode, nLength);

    nLength2 = WideCharToMultiByte(CP_UTF8, 0, bstrCode, -1, pszUTFCode, 0, NULL, NULL);
    pszUTFCode = (char*)malloc(nLength2+1);
    WideCharToMultiByte(CP_UTF8, 0, bstrCode, -1, pszUTFCode, nLength2, NULL, NULL);

    return pszUTFCode;
}



//출처: http://snowbora.tistory.com/370 [눈보라 이야기]
