
uint __fastcall FUN_00607090(LPVOID param_1)

{
  HANDLE pvVar1;
  DWORD DVar2;
  LPVOID local_4;
  
  if (*(int *)((int)param_1 + 0x80) == 0) {
    local_4 = param_1;
    ResetEvent(*(HANDLE *)((int)param_1 + 0x7c));
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_006070f0,param_1
                          ,0,(LPDWORD)&local_4);
    *(HANDLE *)((int)param_1 + 0x80) = pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
      DVar2 = GetLastError();
      if (DVar2 != 0) {
        return DVar2 & 0xffff | 0x80070000;
      }
    }
  }
  return 0;
}

