
int FUN_006050a0(int param_1)

{
  int iVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2590;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x50));
  iVar1 = 0;
  local_4 = 0;
  if (*(int *)(param_1 + 8) != 1) {
    if ((*(int *)(param_1 + 0x80) == 0) || (*(int *)(*(int *)(param_1 + 0x80) + 0x18) == 0)) {
      if ((*(int **)(param_1 + 0x84) != (int *)0x0) && (*(int *)(param_1 + 0x44) == 0)) {
        (**(code **)(**(int **)(param_1 + 0x84) + 0x50))();
        *(undefined4 *)(param_1 + 0x44) = 1;
      }
    }
    else if (*(int *)(*(int *)(param_1 + 0x84) + 0x18) != 0) {
      if (*(int *)(param_1 + 8) == 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x68));
        local_4._0_1_ = 1;
        iVar1 = (**(code **)(*(int *)(param_1 + -0xc) + 0x38))();
        local_4 = (uint)local_4._1_3_ << 8;
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x68));
        if (iVar1 < 0) goto LAB_0060514c;
      }
      iVar1 = FUN_00600230(param_1);
      goto LAB_0060514c;
    }
    *(undefined4 *)(param_1 + 8) = 1;
  }
LAB_0060514c:
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x50));
  ExceptionList = pvStack_c;
  return iVar1;
}

