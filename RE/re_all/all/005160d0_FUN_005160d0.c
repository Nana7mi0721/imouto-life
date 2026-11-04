
undefined4 FUN_005160d0(int param_1,int param_2)

{
  if ((DAT_00a380cc != param_1) || (DAT_00a380d0 != param_2)) {
    if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
      FUN_0050e770();
    }
    if (DAT_00a380cc != param_1) {
      DAT_00a380cc = param_1;
      DAT_00a3d360 = 1;
    }
    if (param_2 < 0x100) {
      if (param_2 < 0) {
        param_2 = 0;
      }
    }
    else {
      param_2 = 0xff;
    }
    DAT_00a380d0 = param_2;
    FUN_005811e0(DAT_00a380cc,param_2);
    if (DAT_00a37d78 != 0) {
      FUN_00567b70(param_1,param_2);
    }
  }
  return 0;
}

