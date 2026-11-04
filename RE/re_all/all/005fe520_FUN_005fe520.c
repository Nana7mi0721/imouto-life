
undefined4 __fastcall FUN_005fe520(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2308;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x94);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  if (*(int *)(param_1 + 100) == 0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return 0;
  }
  *(undefined4 *)(param_1 + 0xc0) = 0;
  if (*(int *)(param_1 + 0x50) != 0) {
    FUN_00600b50();
  }
  *(undefined4 *)(param_1 + 0x74) = 1;
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    param_1 = param_1 + 0xc;
  }
  uVar1 = FUN_006006b0(1,0,param_1);
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return uVar1;
}

