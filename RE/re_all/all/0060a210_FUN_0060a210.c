
undefined4 * __thiscall
FUN_0060a210(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_007b2843;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_LAB_00803e88;
  local_4 = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  param_1[7] = param_2;
  param_1[8] = param_3;
  param_1[10] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  param_1[9] = param_4;
  param_1[0xb] = 0;
  param_1[0xc] = param_5;
  *param_1 = &PTR_FUN_00803e6c;
  uVar1 = (*DAT_00aba168)();
  param_1[0xd] = uVar1;
  ExceptionList = pvStack_c;
  return param_1;
}

