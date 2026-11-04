
undefined4 * __thiscall
FUN_004ebf00(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined1 param_6)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  FUN_004ebfb0(param_5);
  *(undefined1 *)(param_1 + 0xb) = param_6;
  *(undefined1 *)((int)param_1 + 0x2d) = 0;
  return param_1;
}

