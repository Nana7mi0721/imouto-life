
undefined4 FUN_00601a30(int param_1,int *param_2,undefined1 param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b23b8;
  local_c = ExceptionList;
  if (param_2 == (int *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x78);
    ExceptionList = &local_c;
    EnterCriticalSection(lpCriticalSection);
    piVar1 = *(int **)(param_1 + 4);
    local_4 = 0;
    (**(code **)(*param_2 + 4))(param_2);
    *(int **)(param_1 + 4) = param_2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined1 *)(param_1 + 8) = param_3;
    LeaveCriticalSection(lpCriticalSection);
    uVar2 = 0;
  }
  ExceptionList = local_c;
  return uVar2;
}

