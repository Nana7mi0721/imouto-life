
undefined * FUN_0041b5f0(int param_1)

{
  DAT_00a19cf8 = (DAT_00a19cf8 + 1) % 10;
  __itoa(param_1,&DAT_00a192f8 + DAT_00a19cf8 * 0x100,10);
  return &DAT_00a192f8 + DAT_00a19cf8 * 0x100;
}

