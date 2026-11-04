
undefined4 * __thiscall
FUN_004ebeb0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,undefined1 param_6)

{
  undefined4 uVar1;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  uVar1 = param_5[1];
  param_1[3] = *param_5;
  param_1[4] = uVar1;
  *(undefined1 *)(param_1 + 5) = param_6;
  *(undefined1 *)((int)param_1 + 0x15) = 0;
  return param_1;
}

