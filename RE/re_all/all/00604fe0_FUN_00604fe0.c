
int FUN_00604fe0(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2590;
  local_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x50);
  ExceptionList = &local_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    piVar1 = *(int **)(param_1 + 0x80);
    if (((piVar1 != (int *)0x0) && (piVar1[6] != 0)) &&
       (*(int *)(*(int *)(param_1 + 0x84) + 0x18) != 0)) {
      (**(code **)(*piVar1 + 0x18))();
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x68));
      local_4 = CONCAT31(local_4._1_3_,1);
      (**(code **)(**(int **)(param_1 + 0x84) + 0x18))();
      iVar2 = (**(code **)(*(int *)(param_1 + -0xc) + 0x3c))();
      if (-1 < iVar2) {
        *(undefined4 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0x44) = 0;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x68));
      LeaveCriticalSection(lpCriticalSection);
      ExceptionList = local_c;
      return iVar2;
    }
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_c;
  return 0;
}

