
undefined4 FUN_00607bf0(int *param_1)

{
  int iVar1;
  int iVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b22e8;
  local_c = ExceptionList;
  if (param_1 == (int *)0xc) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 1);
  }
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  if ((param_1[0x11] == 0) && (param_1[0x12] == 0)) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    param_1[0x11] = 0;
    iVar2 = param_1[8];
    iVar1 = param_1[0xc];
    if (iVar1 <= iVar2) {
      param_1[0x12] = 0;
      (**(code **)(param_1[-3] + 0x10))();
    }
    else {
      param_1[0x12] = 1;
    }
    FUN_00607b10();
    local_4 = 0xffffffff;
    LeaveCriticalSection(lpCriticalSection);
    if (iVar1 <= iVar2) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  ExceptionList = local_c;
  return 0;
}

