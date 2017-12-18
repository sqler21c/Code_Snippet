

CString str = "118.131.90.22"; //파싱할 문자열
CString strA, strB, strC, strD; //파싱되는 문자열을 담을 변수선언
AfxExtractSubString(strA, str, 0, '.'); // strA == "118"
AfxExtractSubString(strB, str, 1, '.'); // strB == "131"
AfxExtractSubString(strC, str, 2, '.'); // strC == "90"
AfxExtractSubString(strD, str, 3, '.'); // strD == "22"

출처: http://bigmark.tistory.com/11 [마크의 맥시멈 라이프]