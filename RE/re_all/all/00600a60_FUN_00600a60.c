
int __thiscall FUN_00600a60(int *param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  void *pvVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2308;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 7);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  if (param_1[0x12] == 1) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_c;
    return -0x7fffbffb;
  }
  pvVar2 = (void *)param_1[0xf];
  iVar1 = (**(code **)(*param_1 + 0x34))(param_1,param_2,0,param_1[0xe],pvVar2,&DAT_0085ece4);
  if ((lpCriticalSection != (LPCRITICAL_SECTION)0x0) && (-1 < iVar1)) {
    iVar1 = (**(code **)(*param_1 + 0x34))
                      (param_1,lpCriticalSection,0,param_1[0x10],param_1[0x11],&DAT_0085ece4);
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = pvVar2;
  return iVar1;
}

