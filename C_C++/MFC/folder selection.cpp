이전 경로를 유지하면서 FolderSelection 대화 상자 열기
컴퓨터/MFC_API 2009.12.27 23:16


   처음 시작 폴더를 지정해 준 후, 폴더 선택 다이얼로그를 띄우는 방법. 종종 기존에 선택했던 경로가 선택된 상태로 폴더 선택 대화 상자를 열고 싶을 때가 있는데, 그 때 사용한다.

   기본적인 원리는 폴더 선택 대화 상자를 표시할 때, 기존에 저장된 경로를 선택하도록 하는 것이다. 그리고 IDOK에 해당하는 버튼을 누르면, 즉 폴더를 선택하고 '취소'를 누르지 않았다면, 선택된 경로를 특정 파일에다 저장해 놓는다. 그리고 다음 번에 폴더 선택 대화 상자를 표시할 때 파일에 저장해 놓았던 경로를 읽어 와서 SHBrowseForFolder API에 인자로 넘기는 콜백 함수에 그 경로를 넘겨 주면 된다. 우선 코드를 보고 방법을 이해해 보자.

int CALLBACK MyBrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
    switch (uMsg) {
        case BFFM_INITIALIZED:
            ::SendMessage( hwnd, BFFM_SETSELECTION, TRUE, lpData );
            break;
   }
   return 0;
}

위와 같은 callback function을 cpp 파일의 위쪽에 정의해 주고,


// 'path.txt' 파일에 기존에 선택되었던 경로가 저장되어 있다고 가정하자.
HANDLE hFile = CreateFile("path.txt",GENERIC_READ | GENERIC_WRITE, 0, NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
TCHAR *pFolderName = NULL;
int size = GetFileSize(hFile,NULL);
DWORD len = 0;
if(size>1){
    pFolderName = new TCHAR[size+1];
    ReadFile(hFile,pFolderName,size,&len,NULL);
    // callback에서 메모리로 접근하기 때문에 뒤에 널이 있어야 한다.
    pFolderName[size] = NULL;
    CloseHandle(hFile);
}

BROWSEINFO bi;
ZeroMemory(&bi, sizeof(BROWSEINFO));
bi.hwndOwner = this->GetSafeHwnd();
bi.pidlRoot = NULL;
bi.ulFlags = BIF_RETURNONLYFSDIRS;
if(size > 1){
    bi.lpfn =MyBrowseCallBackProc;
    bi.lParam = (LPARAM)(LPCTSTR)pFolderName;
}

LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
if(pidl == NULL){
    // stop here.
}
TCHAR szPath[MAX_PATH] = {0};
if(SHGetPathFromIDList(pidl, szPath)){
    m_DestPath = szPath; // 수정 필요. 내 코드에서만 필요했던 부분.
    SetDlgItemText(IDC_DEST,szPath); // 수정 필요. 내 코드에서만 필요했던 부분.
}

// 파일에 저장된 경로 update.
hFile = CreateFile("path.txt",GENERIC_READ | GENERIC_WRITE, 0, NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
WriteFile(hFile,szPath,_tcslen(szPath),&len,NULL);
CloseHandle(hFile); delete pFolderName;


를 하면 된다. 변수 이름은 적당히 바꿀 것.

SHBrowseForFolder 함수는 인자로 BROWSEINFO 구조체를 입력받는데, 이 구조체에 있는 폴더 선택 대화 상자가 나타날 때 호출하라고 함수 포인터를 저장해 놓는 부분이 있다. 그것이 바로 BROWSEINFO 안에 있는 lpfn. 이 인자에 콜백으로 사용할 함수 포인터를 설정해 주면 된다 (라인 15).

SHBrowseForFolder 가 불리면, 각각의 상황에 따라 그 상황을 설명하는 인자를 콜백 함수로 넘기면서 콜백 함수를 부른다. 콜백 함수로 넘겨 주는, 상황에 대한 인자는 다음과 같은 것이 있다.

BFFM_INITIALIZED 폴더 선택 대화 상자의 초기화가 끝났다는 것을 알려 준다. 콜백 함수로 넘기는 인자 중 lParam 값이 0 이다.
BFFM_SELCHANGED 폴더 선택 대화 상자가 화면에 뜬 상태에서, 사용자가 선택한 폴더를 다른 것으로 바꾸었다는 것을 알려 준다. 콜백으로 넘기는 인자 중 lParam은 새로 선택된 폴더에 대한 정보를 갖고 있는 ITEMIDLIST 구조체의 포인터이다.
BFFM_VALIDATEFAILED 사용자가 에디트 박스에 잘못된 텍스트를 집어 넣었다(맨 아래 그림 첨부된 설명 참고). 즉, 경로를 사용자가 직접 써 넣을 수 있는 에디트 박스에 잘못된 경로 (없는 경로 등) 를 입력하였다. lParam 이 그 잘못된 문자열에 대한 포인터이다.

   즉, 우리가 사용할 콜백 함수는, SHBrowseForFolder 함수가 초기화를 끝냈을 때 작동을 해야 하므로 인자 중 BFFM_INITIALIZED 를 확인해서 작업을 해야 한다. 위 콜백 함수에서 그렇게 하고 있다. 이제, 원하는 경로를 선택해야 하는데 어떻게 해야 할까? 그것은, 특정 메세지를 폴더 선택 대화 상자로 날려 보내면 된다. 그 메세지가 바로 BFFM_SETSELECTION 이다. 이 메세지의 wParam 인자는 lParam 이 어떤 형태인지를 나타낸다. wParam 이 true 이면 lParam 이 경로에 대한 문자열 포인터(null-terminated) 이고, wParam 이 false 이면 lParam 은 선택할 폴더에 대한 ITEMIDLIST 구조체 이다.

   자, 이제 다시 코드를 보면, SHBrowseForFolder 함수는 자신이 인자로 받은 BROWSEINFO 구조체 중 lParam 값(16번째 줄)을 콜백 함수로 넘긴다. 바로 이 값이 콜백 함수의 네 번째 인자로 들어 가게 된다. 그래서 이 값을 우리가 선택했으면 하는 폴더의 문자열로 설정해 주면, SHBrowseForFolder는 이 값을 네 번째 인자로 넘기면서 콜백 함수를 부른다. 콜백 함수는 이 문자열 값을 LPARAM 값으로 사용하고, wParam 값을 true로 설정해서 BFFM_SETSELECTION 메세지를 날릴 때 같이 날리는 것이다.



   참고로 위 코드의 14번 줄에 있는 ulFlags에는 BIF_USENEWUI 옵션을 OR 시켜서 사용할 수 있는데, 차이점은 이 옵션이 없으면 예전 스타일의, 크기 조절도 안되고 새 폴더를 만들 수도 없고, 경로를 직접 입력하는 에디트도 없는 폴더 선택 대화 상자가 뜬다는 것이다. 이 옵션이 없고, 있고에 따른 폴더 선택 대화 상자는 다음과 같다.

ulFlags에 BIF_USENEWUI 사용 안한 모습
ulFlags에 BIF_USENEWUI 사용하지 않을 경우.

ulFlags에 BIF_USENEWUI 사용 한
ulFlags에 BIF_USENEWUI 사용 경우.




ps. 선택된 경로를 파일로 저장하는 부분은 좀 엉성한데, 어차피 이 루틴에서는 읽어갈 때 문자열로 읽어가기 때문에 널 뒤에 뭐가 있든 잘리기 때문에 그냥 저렇게 하였다. 실제로 path.txt 파일을 열어 보면 뒤에 지저분한 것이 있을 수 있다. 만약 이것이 문제가 된다면 아예 파일을 지우고 다시 쓰는 것이 나을 것이다. (코드 수정함)


   또한, unicode 를 사용할 경우, 기존에 경로를 저장한 파일을 불러 와서 [pFolderName]에 설정하는 부분에서 약간의 작업을 더 해 주어야 한다. 즉, 기존 경로를 저장했던 text file 의 size 는 byte 수인데, unicode 의 경우 한 글자가 2 byte 라서

    pFolderName[size>>1] = NULL;

위와 같이 해주어야 한다.
