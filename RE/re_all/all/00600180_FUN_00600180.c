
int FUN_00600180(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2308;
  pvStack_c = ExceptionList;
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
  ExceptionList = &pvStack_c;
  EnterCriticalSection(lpCriticalSection);
  iVar5 = 0;
  iVar4 = 0;
  local_4 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    iVar1 = (**(code **)(*(int *)(param_1 + -0xc) + 0x18))();
    if (0 < iVar1) {
      do {
        piVar2 = (int *)(**(code **)(*(int *)(param_1 + -0xc) + 0x1c))(iVar5);
        if (((piVar2[6] != 0) && (iVar3 = (**(code **)(*piVar2 + 0x18))(), iVar3 < 0)) &&
           (-1 < iVar4)) {
          iVar4 = iVar3;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
  }
  *(undefined4 *)(param_1 + 8) = 0;
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = pvStack_c;
  return iVar4;
}

