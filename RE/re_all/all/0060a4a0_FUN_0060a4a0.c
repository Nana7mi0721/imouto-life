
undefined4 * __thiscall
FUN_0060a4a0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[10] = param_3;
  param_1[3] = 0;
  param_1[9] = param_2;
  param_1[0xb] = param_4;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  *param_1 = &PTR_FUN_00803ea4;
  FUN_0056da30(param_1 + 0xd);
  FUN_0060a610(param_1);
  (*DAT_00aba218)(param_1 + 0xc,0);
  return param_1;
}

