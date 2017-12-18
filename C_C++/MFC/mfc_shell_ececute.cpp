BOOL SetDemonExec(TCHAR *sParam)
{
    TRACE(_T("CGBLUtil::SetDemoExec() In sParam :  %s \n"), sParam);
    TCHAR               sName[MAX_PATH];
    CString             strBKPath;
    SHELLEXECUTEINFO    Shell = {0};

    strBKPath = GetADBToolPath();
    wsprintf(sName, _T("%s\\adb.exe"), strBKPath.GetBuffer());
    strBKPath.ReleaseBuffer();

    Shell.cbSize = sizeof(SHELLEXECUTEINFO);
    Shell.fMask = SEE_MASK_NOCLOSEPROCESS;
#ifdef _DEBUG
    Shell.nShow         = SW_SHOW;
#else
    Shell.nShow         = SW_HIDE;
#endif
    Shell.lpVerb = _T("open");
    Shell.lpFile = sName;
    Shell.lpParameters = sParam;
    ::ShellExecuteEx(&Shell);

    if(WaitForSingleObject(Shell.hProcess, 10000) == WAIT_OBJECT_0 ) {
        return TRUE;
    }
    return FALSE;
}
