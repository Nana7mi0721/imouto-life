
undefined4 __fastcall FUN_006071b0(int param_1)

{
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2308;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  local_4 = 0;
  uVar1 = FUN_006039d0();
  if ((*(int *)(param_1 + 0x58) == 0) &&
     ((*(int *)(param_1 + 0x34) == 0 || (*(int *)(param_1 + 0x74) != 0)))) {
    ResetEvent(*(HANDLE *)(param_1 + 0x6c));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  ExceptionList = local_c;
  return uVar1;
}

