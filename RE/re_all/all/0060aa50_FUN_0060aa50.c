
undefined4 __fastcall FUN_0060aa50(LPVOID param_1)

{
  HANDLE pvVar1;
  LPVOID local_4;
  
  local_4 = param_1;
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
  *(HANDLE *)((int)param_1 + 600) = pvVar1;
  if (pvVar1 == (HANDLE)0x0) {
    return 0x80004005;
  }
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_0060aac0,param_1,0
                        ,(LPDWORD)&local_4);
  *(HANDLE *)((int)param_1 + 0x254) = pvVar1;
  if (pvVar1 == (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)((int)param_1 + 600));
    *(undefined4 *)((int)param_1 + 600) = 0;
    return 0x80004005;
  }
  return 0;
}

