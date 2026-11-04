
undefined4 __fastcall FUN_00607040(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 0x34) = 0;
  if (*(int *)(param_1 + 0x58) < 1) {
    ResetEvent(*(HANDLE *)(param_1 + 0x6c));
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  SetEvent(*(HANDLE *)(param_1 + 0x6c));
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}

