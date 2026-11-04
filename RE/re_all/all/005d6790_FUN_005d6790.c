
undefined4 FUN_005d6790(LPCWSTR param_1,LPCWSTR param_2)

{
  WCHAR WVar1;
  HANDLE hFile;
  int iVar2;
  DWORD local_4;
  
  if ((DAT_00aba154 == 0) && (FUN_0056c2c0(), DAT_00aba154 == 0)) {
    return 0xffffffff;
  }
  hFile = CreateFileW(param_1,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0x0) {
    SetFilePointer(hFile,0,(PLONG)0x0,2);
    iVar2 = 0;
    WVar1 = *param_2;
    while (WVar1 != L'\0') {
      iVar2 = iVar2 + 1;
      WVar1 = param_2[iVar2];
    }
    WriteFile(hFile,param_2,iVar2 * 2,&local_4,(LPOVERLAPPED)0x0);
    OutputDebugStringW(param_2);
    CloseHandle(hFile);
  }
  return 0;
}

