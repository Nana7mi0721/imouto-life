
int FUN_00602120(int param_1,int param_2,undefined4 param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b23b8;
  local_c = ExceptionList;
  if (param_2 == 0) {
    return -0x7fffbffd;
  }
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x14);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return -0x7ffbfdfc;
  }
  if ((*(int *)(*(int *)(param_1 + 0x1c) + 0x14) != 0) && (*(char *)(param_1 + 0x19) == '\0')) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return -0x7ffbfddc;
  }
  iVar1 = FUN_00602430(param_2,param_3);
  if (iVar1 < 0) {
    (**(code **)(*(int *)(param_1 + -0xc) + 0x2c))();
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return iVar1;
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return 0;
}

