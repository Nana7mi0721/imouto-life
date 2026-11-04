
void FUN_0066a3e0(undefined1 *param_1,uint param_2)

{
  undefined1 uVar1;
  
  *param_1 = 0x27;
  uVar1 = FUN_0066a430(param_2 >> 0x18);
  param_1[1] = uVar1;
  uVar1 = FUN_0066a430(param_2 >> 0x10);
  param_1[2] = uVar1;
  uVar1 = FUN_0066a430(param_2 >> 8);
  param_1[3] = uVar1;
  uVar1 = FUN_0066a430(param_2);
  param_1[4] = uVar1;
  param_1[5] = 0x27;
  return;
}

