
undefined4 __thiscall FUN_005fd2e0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  int iVar2;
  void *local_18;
  LPCRITICAL_SECTION local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b22d3;
  pvStack_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x31);
  ExceptionList = &pvStack_c;
  local_14 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  iVar2 = param_1[0x14];
  local_4 = 0;
  if (iVar2 == 0) {
    local_18 = (void *)0x0;
    local_10 = operator_new(0x50);
    local_4._0_1_ = 1;
    if (local_10 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (**(code **)(*param_1 + 0x1c))(0);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = iVar2 + 0xc;
      }
      iVar2 = FUN_00600880(s_Renderer_D_CPosPassThru_00a0600c,param_1[1],&local_18,iVar2);
    }
    local_4 = (uint)local_4._1_3_ << 8;
    param_1[0x14] = iVar2;
    if (iVar2 == 0) {
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = pvStack_c;
      return 0x8007000e;
    }
    if ((int)local_18 < 0) {
      (**(code **)(*(int *)(iVar2 + 8) + 0xc))(1);
      param_1[0x14] = 0;
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_10;
      return 0x80004002;
    }
    uVar1 = (**(code **)(*param_1 + 0x24))(param_2,param_3);
  }
  else {
    uVar1 = (*(code *)**(undefined4 **)(iVar2 + 8))(iVar2 + 8,param_2,param_3);
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_18;
  return uVar1;
}

