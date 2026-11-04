
int FUN_00608860(int param_1,undefined4 *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b23b8;
  local_c = ExceptionList;
  if (param_2 == (undefined4 *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x78);
    ExceptionList = &local_c;
    EnterCriticalSection(lpCriticalSection);
    local_4 = 0;
    iVar2 = *(int *)(*(int *)(param_1 + 0x48) + 0x90);
    if (*(int *)(iVar2 + 0x18) == 0) {
      iVar2 = FUN_006019a0(param_1,param_2);
    }
    else {
      piVar1 = *(int **)(iVar2 + 0x9c);
      iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,param_2);
      if (-1 < iVar2) {
        FUN_00608d00(*param_2);
      }
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  ExceptionList = local_c;
  return iVar2;
}

