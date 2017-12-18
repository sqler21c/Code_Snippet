INI파일은 어플리케이션의 설정을 내보내거나 읽어올때 혹은 어플리케이션 시작 시
초기정보를 읽어올때 흔히 쓰이는 파일 포맷입니다.

다음은 이러한 INI 파일포맷을 다루는 예제입니다.

1. 예제 INI 파일문서(sample.ini).

view plaincopy to clipboardprint?
[Server]
IP=127.0.0.1
PORT=23
ID=admin
PASSWORD=1234
INI 파일은 섹션, 키, 값 으로 구성되어 있으며 위의 INI파일은
"Server 섹션의 IP 키의 값은 127.0.0.1" 이러한 방식으로 이해하면 됩니다.
마찬가지로 "Server 섹션의 PORT 키의 값은 23" 이렇게도 물론 가능합니다.

2. INI 파일작성.
INI 파일작성은 섹션, 키, 값에 해당하는 정보를 입력하여
WritePrivateProfileString() API 함수를 통해 작성이 가능합니다.
WritePrivateProfileString(섹션, 키, 값, INI파일경로)

view plaincopy to clipboardprint?
CString strINIPath(_T("D:\\sample.ini"));
CString strSection, strKey, strValue;

strSection = _T("Server");   // 섹션

strKey = _T("IP");     // 키
strValue = _T("127.0.0.1");   // 값
WritePrivateProfileString(strSection, strKey, strValue, strINIPath);

strKey = _T("PORT");
strValue = _T("23");
WritePrivateProfileString(strSection, strKey, strValue, strINIPath);

strKey = _T("ID");
strValue = _T("admin");
WritePrivateProfileString(strSection, strKey, strValue, strINIPath);

strKey = _T("PASSWORD");
strValue = _T("1234");
WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
3. INI 파일파싱.
INI 파일파싱은 섹션, 키에 해당하는 정보를 입력하여 GetPrivateProfileString() API 함수를 통해 해당 정보에 대한 값의 파싱이 가능합니다.
GetPrivateProfileString(섹션, 키, 디폴트값, 값을 읽어올 버퍼, 버퍼크기, INI파일경로)

view plaincopy to clipboardprint?
TCHAR szBuf[MAX_PATH]={0,};
CString strINIPath(_T("D:\\sample.ini"));
CString strSection, strKey, strValue;

strSection = _T("Server");   // 섹션

strKey = _T("IP");     // 키
GetPrivateProfileString(strSection, strKey, _T(""), szBuf, MAX_PATH, strINIPath);
strValue.Format(_T("%s"), szBuf); // 값

strKey = _T("PORT");
GetPrivateProfileString(strSection, strKey, _T(""), szBuf, MAX_PATH, strINIPath);
strValue.Format(_T("%s"), szBuf);

strKey = _T("ID");
GetPrivateProfileString(strSection, strKey, _T(""), szBuf, MAX_PATH, strINIPath);
strValue.Format(_T("%s"), szBuf);

strKey = _T("PASSWORD");
GetPrivateProfileString(strSection, strKey, _T(""), szBuf, MAX_PATH, strINIPath);
strValue.Format(_T("%s"), szBuf);


출처: http://myblue0324.tistory.com/93 [나만의 상상력]
