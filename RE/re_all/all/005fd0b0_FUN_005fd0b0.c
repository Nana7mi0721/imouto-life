
undefined4 * __thiscall
FUN_005fd0b0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b224e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_005ffec0(param_3,param_4,(LPCRITICAL_SECTION)(param_1 + 0x1f),param_2);
  local_4 = 0;
  param_1[0x14] = 0;
  FUN_00603040(0);
  local_4._0_1_ = 1;
  FUN_00603040(1);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00603040(1);
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1f));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x25));
  param_1[0x2b] = 0;
  param_1[0x2c] = 1;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x31));
  *param_1 = &PTR_FUN_00802f74;
  param_1[3] = &PTR_LAB_00802f38;
  param_1[4] = &PTR_LAB_00803db0;
  SetEvent((HANDLE)param_1[0x17]);
  ExceptionList = local_c;
  return param_1;
}

