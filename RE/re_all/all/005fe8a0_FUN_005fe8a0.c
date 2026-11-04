
undefined4 FUN_005fe8a0(int param_1)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2590;
  pvStack_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 0xcc) + 0x7c);
  ExceptionList = &pvStack_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(*(int *)(param_1 + 0xcc) + 0x94);
  EnterCriticalSection(lpCriticalSection_00);
  local_4._0_1_ = 1;
  FUN_00601d60(param_1);
  (**(code **)(**(int **)(param_1 + 0xcc) + 0x84))();
  local_4 = (uint)local_4._1_3_ << 8;
  LeaveCriticalSection(lpCriticalSection_00);
  uVar1 = (**(code **)(**(int **)(param_1 + 0xcc) + 100))();
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = pvStack_c;
  return uVar1;
}

