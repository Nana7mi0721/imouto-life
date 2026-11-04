
void FUN_007a1f70(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 9;
  param_1[6] = 0;
  param_1[7] = 0x80;
  iVar1 = FUN_007a1fd0(param_1);
  param_1[10] = iVar1;
  param_1[0xb] = 0;
  param_1[8] = (param_1[7] - (iVar1 >> 1)) + -1;
  FUN_007a2000(param_1);
  return;
}

