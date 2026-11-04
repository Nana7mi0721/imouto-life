
undefined * FUN_0041b640(undefined4 param_1,undefined4 param_2)

{
  DAT_00a1a700 = (DAT_00a1a700 + 1) % 10;
  _sprintf(&DAT_00a19d00 + DAT_00a1a700 * 0x100,"%d %d",param_1,param_2);
  return &DAT_00a19d00 + DAT_00a1a700 * 0x100;
}

