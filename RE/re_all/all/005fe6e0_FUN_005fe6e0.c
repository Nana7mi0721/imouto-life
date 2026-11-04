
undefined4 __fastcall FUN_005fe6e0(int *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2308;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x25));
  local_4 = 0;
  param_1[0x1d] = 0;
  if (param_1[0x19] == 1) {
    param_1[0x19] = 0;
    (**(code **)(*param_1 + 0x44))();
    (*DAT_00aba164)(1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x25));
  ExceptionList = pvStack_c;
  return 0;
}

