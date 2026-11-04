
undefined4 __fastcall FUN_005fe010(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2308;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x94));
  piVar1 = *(int **)(param_1 + 0x6c);
  local_4 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  uVar2 = *(undefined4 *)(param_1 + 0x6c);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x94));
  ExceptionList = pvStack_c;
  return uVar2;
}

