
undefined4 FUN_005369c0(undefined *param_1,int param_2)

{
  if (param_1 == (undefined *)0x0) {
    param_1 = &DAT_007d5c78;
  }
  FUN_0056cf70(&DAT_00a4bcb0,0x200,param_1);
  if (DAT_00a4becc != param_2) {
    DAT_00a4bed0 = 1;
    DAT_00a4becc = param_2;
  }
  if (DAT_00a4b760 == 0) {
    DAT_00a4bcac = 1;
    DAT_00a4bec8 = 1;
    return 0;
  }
  FUN_00530d80();
  return 0;
}

