
undefined4 * __thiscall FUN_004f0150(undefined4 *param_1,undefined4 *param_2)

{
  uint local_8;
  
  *param_1 = *param_2;
  FUN_004cb840(param_2 + 1);
  *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_2 + 8);
  param_1[9] = param_2[9];
  param_1[10] = param_2[10];
  *(undefined1 *)(param_1 + 0xb) = *(undefined1 *)(param_2 + 0xb);
  *(undefined1 *)((int)param_1 + 0x2d) = *(undefined1 *)((int)param_2 + 0x2d);
  FUN_004cead0(param_2 + 0xc);
  FUN_004cd5b0(param_2 + 0x10);
  FUN_004cb840(param_2 + 0x14);
  FUN_004cc270(param_2 + 0x1b);
  FUN_004cd5b0(param_2 + 0x1f);
  FUN_004cdcd0(param_2 + 0x23);
  FUN_004cd190(param_2 + 0x27);
  FUN_004f09c0(param_2 + 0x2b);
  for (local_8 = 0; local_8 < 100; local_8 = local_8 + 1) {
    FUN_004cb840(param_2 + local_8 * 7 + 0x2f);
  }
  param_1[0x2eb] = param_2[0x2eb];
  FUN_004cb840(param_2 + 0x2ec);
  param_1[0x2f3] = param_2[0x2f3];
  FUN_004cb840(param_2 + 0x2f4);
  return param_1;
}

