
undefined1 * __thiscall FUN_00472740(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  FUN_004cff20(param_2 + 0x14);
  FUN_004d0370(param_2 + 0x24);
  FUN_004727f0(param_2 + 0x34);
  FUN_004cce30(param_2 + 0x40);
  FUN_004cce30(param_2 + 0x50);
  return param_1;
}

