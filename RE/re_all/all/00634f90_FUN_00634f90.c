
void __thiscall FUN_00634f90(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  param_1[1] = 0x3f800000;
  *(undefined2 *)(param_1 + 2) = 1;
  *(undefined2 *)((int)param_1 + 10) = 0xffff;
  *param_1 = &PTR_LAB_00804820;
  param_1[3] = *param_2;
  param_1[4] = param_2[1];
  param_1[5] = param_2[2];
  param_1[6] = param_2[3];
  param_1[7] = *param_3;
  param_1[8] = param_3[1];
  param_1[9] = param_3[2];
  uVar1 = param_3[3];
  param_1[0x13] = 0;
  param_1[10] = uVar1;
  *param_1 = &PTR_LAB_00804838;
  return;
}

