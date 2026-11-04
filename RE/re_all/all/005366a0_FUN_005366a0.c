
undefined4
FUN_005366a0(undefined *param_1,int param_2,int param_3,uint param_4,int param_5,int param_6,
            undefined4 param_7)

{
  if ((int)param_4 < 0) {
    param_4 = -(uint)(DAT_00a4b76c != 0) & 2;
  }
  if (1 < param_6) {
    param_4 = param_4 | 1;
  }
  if (param_2 < 0) {
    param_2 = 0x10;
  }
  if (param_3 < 0) {
    param_3 = 6;
  }
  if (param_6 < 0) {
    param_6 = 1;
  }
  if (param_1 == (undefined *)0x0) {
    param_1 = &DAT_007d5c78;
  }
  FUN_0056cf70(&DAT_00a4bcb0,0x200,param_1);
  DAT_00a4bebc = param_3;
  DAT_00a4beb4 = param_2;
  DAT_00a4bec4 = param_4;
  if (DAT_00a4becc != param_5) {
    DAT_00a4bed0 = 1;
    DAT_00a4becc = param_5;
  }
  DAT_00a4bed8 = param_6;
  DAT_00a4bee0 = param_7;
  if (DAT_00a4b760 == 0) {
    DAT_00a4bcac = 1;
    DAT_00a4bec0 = 1;
    DAT_00a4beb0 = 1;
    DAT_00a4beb8 = 1;
    DAT_00a4bec8 = 1;
    DAT_00a4bed4 = 1;
    DAT_00a4bedc = 1;
    return 0;
  }
  FUN_00530d80();
  return 0;
}

