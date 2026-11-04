
undefined4 __thiscall FUN_005fdb50(int param_1,int param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  void *pvVar2;
  int *piVar3;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b22d3;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc4);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  if (param_2 != 0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return 0;
  }
  if (*(int *)(param_1 + 0x78) == 0) {
    param_2 = 0;
    pvVar2 = operator_new(0xe0);
    local_4._0_1_ = 1;
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_005fe780(param_1,&param_2,&DAT_00a06030);
    }
    local_4 = (uint)local_4._1_3_ << 8;
    *(int **)(param_1 + 0x78) = piVar3;
    if (piVar3 == (int *)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return 0;
    }
    if (param_2 < 0) {
      (**(code **)(*piVar3 + 0xc))(1);
      *(undefined4 *)(param_1 + 0x78) = 0;
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = pvVar2;
      return 0;
    }
  }
  uVar1 = *(undefined4 *)(param_1 + 0x78);
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return uVar1;
}

