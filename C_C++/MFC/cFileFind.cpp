CFileFind cfileFind;
BOOL IsFile;

//MKT---모든 파일을 다 찾도록 합니다
IsFile=cfileFind.FindFile(strSeletedItem + "\\*.*");
CString strTempPath;
char* P_FileList = new char[100];


//MKT---프로젝트의 시작 경로를 고정으로 기억시키기 위함 입니다.
    if(strTemp == "")
    {
        strTemp=strSeletedItem;
    }


    while(IsFile)
    {
        IsFile=cfileFind.FindNextFileA();
        //MKT---.과 ..을 만나면 무시 합니다.
        if(cfileFind.IsDots())
        {
            continue;
        }
//MKT--- 디렉토리 라면 해당 디렉토리의 절대 경로를 가져와 재귀호출 합니다.
        if(cfileFind.IsDirectory())
        {
            strTempPath = cfileFind.GetFilePath();
             M_GetFileList(cfile, strTempPath);
        }

    //MKT---디렉토리가 아닌 파일이면 라이트를 위한 단계를 거칩니다.
        if(!cfileFind.IsDirectory())
        {
            int ii=0;
            //MKT---RootDir의 길이를 구합니다.
            ii = strTemp.GetLength();
            //MKT---파일이라면 이에 대한 절대경로를 구합니다.
            strTempPath = cfileFind.GetFilePath();
            //MKT---줄바꿈을 입력 합니다.
            strTempPath += "\r\n";
            //MKT---RootDir를 지우고 저장 합니다.
            strTempPath.Delete(0, ii+1);
            //MKT---해당 문자열을 파일로 저장하기 위한 단계 입니다.
            P_FileList=strTempPath.GetBuffer(0);
            strTempPath.ReleaseBuffer();
            //MKT---받아온 포인터를 통해 파일을 기록 합니다.
            cfile->Write(P_FileList, strTempPath.GetLength());
        }
}


출처: http://0411.tistory.com/250 [컴맹]

void GetFileList(CString strFolder)
{
    CFileFind file;
    BOOL b = file.FindFile(strFolder + _T("\\*.*"));
    CString strMusicFilter = ".MP3.OGG.WMA.WAV";
    CString srFolderItem, strFileExt, strTempString;

    while(b){
        b = file.FindNextFile();
        if(file.IsDirectory() && !file.isDots()){
            strFolderItem = file.GetFilePath();
            GetFileList(strFolderItem);
        }

        strFolderItem = GetFilePath();
        strFileExt = strFolderItem.Mid(strFolderItem.ReverseFind("."));

        if(!file.IsDots()){
            strFileExt.MakeUpper();
            if(file.IsDirectory()){
                m_sCopyList.push_back(strFolderItem);
            }
        }
    }
}


출처: http://mynotepad.tistory.com/50 [MyNotepad]



지정한 경로에 존재하는 폴더와 파일목록을 얻는 방법에 대해서 알아보겠습니다.

// c:\work\example 경로에 존재하는 파일 목록을 얻고자 한다면 아래와 같이 코드를 구성하면 된다.
char 클래스명::SearchDirectory(const char *parm_search_path)
{
    // parm_search_path에는 c:\work\example 경로가 있다.
    CString search_path = parm_search_path;

    WIN32_FIND_DATA file_data;
    // 지정된 경로에 존재하는 모든 파일의 목록을 구성하고 해당 정보의 핸들값을 얻는다.
    // 만약, 해당 경로에 파일이나 자식 폴더가 존재하지 않는다면 INVALID_HANDLE_VALUE 값을 반환한다.
    // 그리고 이 함수가 성공적으로 목록을 구성한 경우라면 file_data 변수에 구성된 목록들중에서 첫번째에
    // 존재하는 파일의 정보를 넣어준다.
    HANDLE search_handle = FindFirstFile(search_path + "*.*", &file_data);
    if(INVALID_HANDLE_VALUE != search_handle){
        // 파일 목록을 성공적으로 구성한 경우
        do{
            if(FILE_ATTRIBUTE_DIRECTORY & file_data.dwFileAttributes){
                // 현재 정보가 폴더인 경우, file_data.cFileName 에 폴더 이름이 들어있다.
                // 현재 폴더(.)와 이전폴더("..")를 의미하는 심볼은 제외시킨다.
                if(strcmp(file_data.cFileName, ".") && strcmp(file_data.cFileName, "..")){

                    // 서브 디렉토리를 계속 검색한다.
                    SearchDirectory(search_path + file_data.cFileName + CString("\\"));

                    // 자신이 설정한 패턴을 찾은 경우, 검색 결과 리스트(m_result_list)에 추가한다. strstr 함수는
                    // 대소문자를 구별하는 함수이기 때문에 Test와 test는 서로 다른 문자열로 간주한다.
                    if(NULL != strstr(file_data.cFileName, m_search_pattern)){
                        m_result_list.InsertString(-1, "[DIR]: " + search_path + file_data.cFileName);
                    }
                }
            } else {

                // 현재 정보가  파일인 경우, file_data.cFileNam 에 파일 이름이 들어있다.
                // 자신이 설정한 패턴을 찾은 경우, 검색 결과 리스트에 추가한다. strstr 함수는
                // 대소문자를 구별하는 함수이기 때문에 Test와 test는 서로 다른 문자열로 간주한다.
                if(NULL != strstr(file_data.cFileName, m_search_pattern)){
                    m_result_list.InsertString(-1, "[FILE]: " + search_path + file_data.cFileName);
                }
            }
            // 구성된 목록에서 다음 파일의 정보를 file_data에 복사하여 가져온다.
            // 더이상의 정보가 없다면 FindNextFile 함수는 0을 반환한다.
        } while(FindNextFile(search_handle, &file_data));

       // 구성된 파일 목록을 삭제한다.
        FindClose(search_handle);
    }

    return 1;
}
