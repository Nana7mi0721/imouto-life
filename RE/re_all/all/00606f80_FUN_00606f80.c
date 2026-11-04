
undefined4 __fastcall FUN_00606f80(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  HANDLE hEvent;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2308;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1c);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  *(undefined4 *)(param_1 + 0x34) = 1;
  iVar1 = FUN_00607140();
  while (iVar1 != 0) {
    FUN_006072c0(iVar1);
    iVar1 = FUN_00607140();
  }
  if (*(int *)(param_1 + 0x70) < 1) {
    hEvent = *(HANDLE *)(param_1 + 0x6c);
  }
  else {
    *(undefined4 *)(param_1 + 0x74) = 1;
    LeaveCriticalSection(lpCriticalSection);
    while( true ) {
      WaitForSingleObject(*(HANDLE *)(param_1 + 0x78),0xffffffff);
      EnterCriticalSection(lpCriticalSection);
      if (*(int *)(param_1 + 0x70) == 0) break;
      LeaveCriticalSection(lpCriticalSection);
    }
    hEvent = *(HANDLE *)(param_1 + 0x6c);
    *(undefined4 *)(param_1 + 0x74) = 0;
  }
  SetEvent(hEvent);
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return 0;
}

