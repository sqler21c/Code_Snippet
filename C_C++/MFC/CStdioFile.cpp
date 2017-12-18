1. CStdioFile 클래스의 소개
     CStdioFile 클래스는 CFile 클래스의 자식 클래스로서 텍스트 속성의 파일을 손쉽게 처리할수
    있도록 제공되는 클래스입니다. 런타임 함수를 사용하거나 API 함수를 사용해서 파일을 처리하는
    경우, 텍스트 파일의 내용을 한줄씩 읽어서 처리하는 경우가 많은데 CStdioFile 클래스는
    배열이나 포인터 외에도 CString 클래스를 인자로 사용할수 있기 때문에 여러가지 예외 사항에
    대처하기 좋습니다.


2. CStdioFile 클래스를 사용하여 텍스트 파일 열기와 닫기
     텍스트 파일에서 텍스트를 읽기 위해서는 CStdioFile 클래스의 Open 함수를 아래와 같이
    사용하면 됩니다.

    CStdioFile tip_file;
     // 현재 경로에서 "tipssoft.txt" 파일을 연다.
    // CFile::modeRead  ->  파일을 읽기 모드로 연다. ( 파일이 없다면 실패한다. )
    // CFile::typeText  ->  파일의 속성을 텍스트 형식으로 지정한다. ( 생략 가능)
    if(tip_file.Open("tipssoft.txt", CFile::modeRead | CFile::typeText)){

        // 성공적으로 파일이 열렸으면 원하는 작업을 한다.

        // 작업을 마친후에 파일을 닫는다.
        tip_file.Close();
    }


3. 파일에서 한줄씩 텍스트를 읽어서 CString 클래스 변수에 저장하기
     CStdioFile 클래스의 WriteString 함수와 달리 ReadString 함수를 사용하면 파일에 저장된
    텍스트를 한번에 읽지 않고 한줄씩 읽습니다. 따라서 두개의 CString 변수를 선언하여
    한개는 한줄씩 읽는데 사용하고 나머지 한개는 한줄씩 읽은 정보를 합쳐서 한개의 문자열로
    저장하는데 사용하시면 됩니다.

    CString display_str, str;
    // 파일에 더이상 텍스트 내용이 없을때까지 한줄씩 반복해서 읽어서 str 변수에 저장한다.
    while(src_file.ReadString(str)){

        // 읽어들인 한줄의 텍스트를 display_str 변수에 추가한다.
        display_str += str;

        // 멀티라인 속성을 가진 에디트 컨트롤은 줄의 끝에 "\r\n" 가 있어야지 줄바꿈을 해준다.
        // ReadString 함수가 한줄의 텍스트를 읽을때 해당줄의 끝에있는 "\n" 은 읽어서 버리기
        // 때문에 텍스트의 한줄끝에 "\n" 이 있다고 할지라도 반드시 "\n" 을 붙여야 합니다.
        display_str += "\r\n";
    }

    // 반복문을 빠져나오면 display_str에 텍스트 파일의 내용이 모두 저장되어 있습니다.


4. CString 클래스 변수에 저장된 테스트 내용을 에디트 컨트롤에 출력하기
    CString 변수에 저장된 텍스트는 SetDlgItemText 함수를 사용하여 간단하게 에디트 컨트롤에
    출력할수 있습니다.

    // display_str 변수에 저장되어 있는 내용을 IDC_MY_TEXT 에디트 컨트롤에 출력한다.
    SetDlgItemText(IDC_MY_TEXT, display_str);

5. 완성 코드
    "tipssoft.txt" 파일에 저장된 텍스트 내용을 IDC_MY_TEXT 에디트 컨트롤에 출력하는 코드를
    완성해보면 다음과 같습니다.

    CStdioFile tip_file;

    // 현재 경로에서 "tipssoft.txt" 파일을 연다.
    // CFile::modeRead  ->  파일을 읽기 모드로 연다. ( 파일이 없다면 실패한다. )
    // CFile::typeText  ->  파일의 속성을 텍스트 형식으로 지정한다. ( 생략 가능)
    if(tip_file.Open("tipssoft.txt", CFile::modeRead | CFile::typeText)){

        CString display_str, str;

        // 파일에 더이상 텍스트 내용이 없을때까지 한줄씩 반복해서 읽어서 str 변수에 저장한다.
        while(tip_file.ReadString(str)){

            // 읽어들인 한줄의 텍스트를 display_str 변수에 추가한다.
            display_str += str;

            // 멀티라인 속성을 가진 에디트 컨트롤은 줄의 끝에 "\r\n" 가 있어야지 줄바꿈을 해준다.
            // ReadString 함수가 한줄의 텍스트를 읽을때 해당줄의 끝에있는 "\n" 은 읽어서 버리기
            // 때문에 텍스트의 한줄끝에 "\n" 이 있다고 할지라도 반드시 "\n" 을 붙여야 합니다.
            display_str += "\r\n";
        }

        // display_str 변수에 저장되어 있는 내용을 IDC_MY_TEXT 에디트 컨트롤에 출력한다.
        SetDlgItemText(IDC_MY_TEXT, display_str);

        // 작업을 마친후에 파일을 닫는다.
        tip_file.Close();
    }

