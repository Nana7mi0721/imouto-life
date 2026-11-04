
undefined4 * __thiscall
FUN_005febc0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_007b2398;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_005fd0b0(param_2,param_3,param_4,param_5);
  param_1[0x38] = &PTR_LAB_008033d0;
  param_1[0x39] = &PTR_LAB_00803220;
  local_4 = 0;
  param_1[0x3b] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  *param_1 = &PTR_LAB_0080315c;
  param_1[3] = &PTR_LAB_00803120;
  param_1[4] = &PTR_LAB_00803db0;
  param_1[0x38] = &PTR_LAB_008030fc;
  param_1[0x39] = &PTR_LAB_008030e8;
  FUN_005fecc0();
  ExceptionList = local_c;
  return param_1;
}

