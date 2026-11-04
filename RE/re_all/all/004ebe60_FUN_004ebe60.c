
undefined4 * __thiscall
FUN_004ebe60(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined1 param_6)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  FUN_004ebf50(param_5);
  *(undefined1 *)(param_1 + 0x11) = param_6;
  *(undefined1 *)((int)param_1 + 0x45) = 0;
  return param_1;
}

