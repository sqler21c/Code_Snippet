[MFC] 전체파일 경로에서 파일명만 추출하기
Maj0r Tom 2012.11.29 03:25


1. CString 이용
CStringT Right( __in int nCount )  함수를 이용한다.
ex)
  CString str = "C:\\test\\file.exe";
  CString name = str.Right( str.GetLength() - str.ReverseFind('\\')-1);

2. strchr(), strrchr() 이용
지정한 문자열에서 원하는 문자가 포함되어있는지 확인한다.
원하는 문자를 찾은 경우 찾은 주소를 반환한다. 찾을수 없다면 NULL을 반환한다.
ex)
char* str ="C:\\test\\file.exe";
char* name = strrchr(str, '\\') + 1;

3. AfxExtractSubString 사용

BOOL AFXAPI AfxExtractSubString (
   CString& rString, // 분리할 문자열
   LPCTSTR lpszFullString, // 전체 문자
   int iSubString, // 분리할 문자의 위치
   TCHAR chSep = '\n' // 분리할 인자
);
ex)
CString strTok, str = _T("hi;abc;def");
int iSub = 0;
while(AfxExtractSubString(strTok, str, iSub++, ';'))
{
        MessageBox(strTok);
}

4.문자열 위치변경 사용
ex)
char* strTotal; //전체경로
char* strName; //파일명을 담을 변수
int nTotalLen = strlen(strTotal);

while(1)
{
 if(strTotal + nTotalLen == '\\')
 {
   strcpy(strName, strTotal + nTotlaLen);
   break;
 }
 nTotlaLen--;
}

5. CFileFind 사용
GetFileName
GetFilePath
GetFileTitle 사용
ex)
CFileFind finder;
if(finder.FindFile("C:\\download\\aa.txt") )
{
 finder.FindNextFile();
 MessageBox(finder.GetFileTitle());    // aa 만 출력..
 finder.Close();
}


출처: http://code13.tistory.com/21 [# 13]
