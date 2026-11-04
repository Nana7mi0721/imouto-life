
undefined4
FUN_005cbbc0(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,int param_6,
            int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  undefined4 local_c [3];
  
  iVar1 = *(int *)(&DAT_007fcd74 + param_1 * 4);
  iVar2 = 0;
  if (param_7 == 0x2a) {
    iVar2 = 4;
  }
  else if (param_7 == 0x39) {
    iVar2 = 2;
  }
  FUN_005c31f0(iVar1 * param_4);
  FUN_005c3280(iVar2 * param_6);
  FUN_005d5220(DAT_00f07350,0,4,0,local_c,0);
  FUN_0056d420(local_c[0],param_3,iVar1 * param_4);
  FUN_005d52a0(DAT_00f07350,0,0);
  FUN_005d5220(DAT_00f07358,0,4,0,local_c,0);
  FUN_0056d420(local_c[0],param_5,iVar2 * param_6);
  FUN_005d52a0(DAT_00f07358,0,0);
  if ((DAT_00f3a070 != 0) && ((DAT_00f13674 != param_2 || (DAT_00ef7324 != 0)))) {
    DAT_00f13674 = param_2;
    FUN_005d2cf0(param_2);
  }
  iVar2 = (&DAT_00ef728c)[param_1];
  if ((DAT_00f3a070 != 0) && ((DAT_00f13700 != iVar2 || (DAT_00ef7324 != 0)))) {
    if (iVar2 != 0) {
      FUN_005d2c60(iVar2);
    }
    DAT_00ef72cc = 1;
    DAT_00f13700 = iVar2;
  }
  if (param_8 != 0) {
    if (param_1 == 5) {
      iVar2 = FUN_005c09b0();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
    }
    else {
      iVar2 = (&DAT_00ef1bac)[param_1];
      if (((DAT_00f136f4 != iVar2) || (DAT_00ef7324 != 0)) && (DAT_00f3a070 != 0)) {
        FUN_005d2bb0(iVar2,0,0);
        DAT_00f136f0 = 1;
        DAT_00f136f4 = iVar2;
      }
    }
  }
  FUN_005bb970(DAT_00f07350,*(undefined4 *)(&DAT_007fcd74 + param_1 * 4));
  iVar2 = DAT_00f07358;
  if (((DAT_00f136f8 != DAT_00f07358) || (DAT_00ef7324 != 0)) && (DAT_00f3a070 != 0)) {
    if (DAT_00f07358 != 0) {
      FUN_005d2cb0(DAT_00f07358,param_7,0);
    }
    DAT_00f136f8 = iVar2;
    DAT_00f136fc = param_7;
  }
  FUN_005c2d50();
  FUN_005d2bd0(param_6,0,0);
  DAT_00a37de4 = DAT_00a37de4 + 1;
  return 0;
}

