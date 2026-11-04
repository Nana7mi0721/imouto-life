
undefined4 FUN_005d6730(LPCWSTR param_1)

{
  HANDLE hFile;
  undefined1 local_8;
  undefined1 local_7;
  DWORD local_4;
  
  DeleteFileW(param_1);
  hFile = CreateFileW(param_1,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,1,0x80,(HANDLE)0x0);
  local_8 = 0xff;
  local_7 = 0xfe;
  WriteFile(hFile,&local_8,2,&local_4,(LPOVERLAPPED)0x0);
  if (hFile != (HANDLE)0x0) {
    CloseHandle(hFile);
  }
  return 0;
}

