
int FUN_005fe800(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2590;
  pvStack_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 0xcc) + 0x7c);
  ExceptionList = &pvStack_c;
  EnterCriticalSection(lpCriticalSection);
  local_4 = 0;
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(*(int *)(param_1 + 0xcc) + 0x94);
  EnterCriticalSection(lpCriticalSection_00);
  local_4 = CONCAT31(local_4._1_3_,1);
  iVar1 = (**(code **)(*(int *)(param_1 + -0xc) + 0x3c))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0xcc) + 0x68))();
    if (-1 < iVar1) {
      iVar1 = FUN_00634bb0(param_1);
    }
  }
  LeaveCriticalSection(lpCriticalSection_00);
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = pvStack_c;
  return iVar1;
}

