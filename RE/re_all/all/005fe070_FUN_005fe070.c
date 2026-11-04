
int __thiscall FUN_005fe070(int *param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  int iVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2330;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1f);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  param_1[0x2d] = 1;
  iVar1 = FUN_00601af0(param_1[0x1e] + 0x98,param_2);
  if (iVar1 == 0) {
    iVar1 = ((int *)param_1[0x1e])[0x33];
    if ((iVar1 != 0) && (iVar1 = (**(code **)(*(int *)param_1[0x1e] + 0x24))(iVar1), iVar1 < 0)) {
      param_1[0x2d] = 0;
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return iVar1;
    }
    lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1 + 0x25);
    EnterCriticalSection(lpCriticalSection_00);
    local_4 = CONCAT31(local_4._1_3_,1);
    if (((param_1[0x1b] == 0) && (param_1[0x1c] == 0)) && (param_1[0x18] == 0)) {
      if (param_1[0x14] != 0) {
        FUN_006009b0(param_2);
      }
      if ((param_1[0x19] == 1) && (iVar1 = (**(code **)(*param_1 + 0x54))(param_2), iVar1 == 0)) {
        param_1[0x2d] = 0;
        LeaveCriticalSection(lpCriticalSection_00);
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = local_c;
        return -0x7ffbfdd5;
      }
      param_1[0x2e] = *(int *)(param_1[0x1e] + 0xc0);
      iVar1 = *(int *)(param_1[0x1e] + 0xc4);
      param_1[0x1b] = (int)param_2;
      param_1[0x2f] = iVar1;
      (**(code **)(*param_2 + 4))(param_2);
      if (param_1[0x19] == 0) {
        FUN_005fe750(1);
      }
      LeaveCriticalSection(lpCriticalSection_00);
      LeaveCriticalSection(lpCriticalSection);
      iVar1 = 0;
    }
    else {
      SetEvent((HANDLE)param_1[0x17]);
      param_1[0x2d] = 0;
      LeaveCriticalSection(lpCriticalSection_00);
      LeaveCriticalSection(lpCriticalSection);
      iVar1 = -0x7fff0001;
    }
  }
  else {
    param_1[0x2d] = 0;
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = -0x7fffbffb;
  }
  ExceptionList = local_c;
  return iVar1;
}

