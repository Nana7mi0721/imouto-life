
undefined1 * __thiscall FUN_004b36a0(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  param_1[8] = param_2[8];
  FUN_004cd5b0(param_2 + 0xc);
  FUN_004f09c0(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
  return param_1;
}

