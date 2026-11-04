
undefined4 FUN_005cba60(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 local_c [3];
  
  iVar1 = *(int *)(&DAT_007fcd74 + param_1 * 4);
  FUN_005c31f0(iVar1 * param_4);
  FUN_005d5220(DAT_00f07350,0,4,0,local_c,0);
  FUN_0056d420(local_c[0],param_3,iVar1 * param_4);
  FUN_005d52a0(DAT_00f07350,0,0);
  if ((DAT_00f3a070 != 0) && ((DAT_00f13674 != param_2 || (DAT_00ef7324 != 0)))) {
    DAT_00f13674 = param_2;
    FUN_005d2cf0(param_2);
  }
  iVar1 = (&DAT_00ef728c)[param_1];
  if ((DAT_00f3a070 != 0) && ((DAT_00f13700 != iVar1 || (DAT_00ef7324 != 0)))) {
    if (iVar1 != 0) {
      FUN_005d2c60(iVar1);
    }
    DAT_00ef72cc = 1;
    DAT_00f13700 = iVar1;
  }
  if (param_5 != 0) {
    if (param_1 == 5) {
      iVar1 = FUN_005c09b0();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
    }
    else {
      iVar1 = (&DAT_00ef1bac)[param_1];
      if (((DAT_00f136f4 != iVar1) || (DAT_00ef7324 != 0)) && (DAT_00f3a070 != 0)) {
        FUN_005d2bb0(iVar1,0,0);
        DAT_00f136f0 = 1;
        DAT_00f136f4 = iVar1;
      }
    }
  }
  FUN_005bb970(DAT_00f07350,*(undefined4 *)(&DAT_007fcd74 + param_1 * 4));
  FUN_005c2d50();
  FUN_005d2bf0(param_4,0);
  DAT_00a37de4 = DAT_00a37de4 + 1;
  return 0;
}

