
undefined * FUN_0041b690(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DAT_00a1b108 = (DAT_00a1b108 + 1) % 10;
  _sprintf(&DAT_00a1a708 + DAT_00a1b108 * 0x100,"%d %d %d",param_1,param_2,param_3);
  return &DAT_00a1a708 + DAT_00a1b108 * 0x100;
}

