
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_00610f50(undefined4 *param_1,undefined4 param_2,float param_3)

{
  FUN_0060f4b0();
  param_3 = param_3 * _DAT_007d589c;
  *param_1 = &PTR_FUN_00804228;
  param_1[1] = 10;
  param_1[0xd] = 1;
  param_1[7] = param_2;
  param_1[8] = param_3;
  param_1[9] = param_2;
  param_1[10] = 0;
  return param_1;
}

