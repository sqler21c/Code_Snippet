[MFC] 폰트 사이즈 설정 방법
폰트 사이즈 설정하는 방법을 소개 할까 합니다.
간단하게 말로 설명합니다. 모르겠다 싶으면 댓글 달아주세요.
우선 전역변수를 설정해 줍니다.

CFont m_font;
그리고 OnInitDialog() 를 선택하고 다음 코드를 작성합니다.

여기서 또 두가지 방법이 있습니다. 두가지 방법 모두 설명해 드립니다.

 CDialog::OnInitDialog();

   m_font.CreateFont( 100, // nHeight
                      80, // nWidth
                               0, // nEscapement
                               0, // nOrientation
                               1, // nWeight
                               0, // bItalic
                               0, // bUnderline
                               0, // cStrikeOut
                               0, // nCharSet
                               OUT_DEFAULT_PRECIS, // nOutPrecision
                               0,                              // nClipPrecision
                               DEFAULT_QUALITY,       // nQuality
                               DEFAULT_PITCH | FF_DONTCARE,  // nPitchAndFamily
                               "굴림" ); // lpszFacename

이렇게 작성해주고.
원하는 폼(에디트 박스, 버튼 등..) 을 설정해줍니다.
m_edit1.SetFont(&m_font, TRUE);

일케
또는 GetDlgItem(IDC_EDIT1)->SetFont(&m_font);

일케 ㅇㅋ?


그리고 저 위에 보면 폰트사이즈 설정하는 코드가 무지막지하게 길다 싶으면
다른 방법이 있습죠.
바로 요거


m_font.CreatePointFont(180,"굴림");
그리고 설정은 위와 똑같이
m_edit1.SetFont(&m_font, TRUE);

이거나
GetDlgItem(IDC_EDIT1)->SetFont(&m_font);

일케 해주면 됩니다!^^

쉽죠?

어렵다면 답변 달아주세요;





내가 아는건 이 세상 사람이 다 알수 있도록!

공부합시다 아자아자!!

출처: http://starfactory.tistory.com/85 [StarFactory]
