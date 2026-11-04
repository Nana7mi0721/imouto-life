
undefined4 FUN_006004a0(int param_1,LPCWSTR param_2,int *param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2308;
  local_c = ExceptionList;
  iVar5 = 0;
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
    ExceptionList = &local_c;
    EnterCriticalSection(lpCriticalSection);
    local_4 = 0;
    iVar2 = (**(code **)(*(int *)(param_1 + -0xc) + 0x18))();
    if (0 < iVar2) {
      do {
        iVar3 = (**(code **)(*(int *)(param_1 + -0xc) + 0x1c))(iVar5);
        iVar4 = lstrcmpW(*(LPCWSTR *)(iVar3 + 0x14),param_2);
        if (iVar4 == 0) {
          if (iVar3 == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = iVar3 + 0xc;
          }
          *param_3 = iVar5;
          (**(code **)(*(int *)(iVar3 + 0xc) + 4))(iVar3 + 0xc);
          LeaveCriticalSection(lpCriticalSection);
          ExceptionList = local_c;
          return 0;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar2);
    }
    *param_3 = 0;
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0x80040216;
  }
  ExceptionList = local_c;
  return uVar1;
}

