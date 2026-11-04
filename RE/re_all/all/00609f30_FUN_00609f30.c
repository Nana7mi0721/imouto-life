
undefined4 FUN_00609f30(int param_1,int param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b27e0;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x50);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  if (param_2 == 0) {
    uVar1 = FUN_006034d0();
    local_4._0_1_ = 1;
    FUN_00603500(uVar1);
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_006034c0();
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return 0;
  }
  uVar1 = FUN_005fcdf0(param_1 + 4,param_2);
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return uVar1;
}

