
undefined4 FUN_005c3310(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_58 [3];
  undefined1 *local_4c [3];
  int local_40;
  
  if (param_2 != 0) {
    local_4c[0] = &LAB_005bcf30;
    local_40 = param_1;
    uVar1 = FUN_0057ffd0(local_4c);
    return uVar1;
  }
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (DAT_00f07334 != 0) {
    iVar2 = FUN_0052ea40();
    if ((iVar2 == 0) && (DAT_00f0734c == 0)) {
      iVar2 = *(int *)(&DAT_007fcd90 + (DAT_00f0733c + DAT_00f07338 * 3) * 4);
      if ((DAT_00f07330 != 0) && (DAT_00f07328 != 0)) {
        FUN_005d52a0(DAT_00f07330,0,0);
        DAT_00f07328 = 0;
      }
      if (DAT_00f13674 != DAT_00f07340) {
        FUN_005bb3b0(DAT_00f07340);
      }
      if (DAT_00f13700 != (&DAT_00ef728c)[iVar2]) {
        FUN_005bb6a0((&DAT_00ef728c)[iVar2]);
      }
      if (iVar2 == 5) {
        iVar3 = FUN_005c09b0();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
      }
      else if (DAT_00f136f4 != (&DAT_00ef1bac)[iVar2]) {
        FUN_005bb6f0((&DAT_00ef1bac)[iVar2],1);
      }
      if ((DAT_00f13704 != DAT_00f07330) || (DAT_00f13708 != *(int *)(&DAT_007fcd74 + iVar2 * 4))) {
        FUN_005bb970(DAT_00f07330,*(undefined4 *)(&DAT_007fcd74 + iVar2 * 4));
      }
      FUN_005c2d50();
      FUN_005d2bf0(DAT_00f07334,0);
      DAT_00a37de4 = DAT_00a37de4 + 1;
    }
  }
  if (-1 < param_1) {
    DAT_00f07338 = param_1;
  }
  DAT_00f07334 = 0;
  if ((DAT_00f07330 != 0) && (DAT_00f07328 == 0)) {
    FUN_005d5220(DAT_00f07330,0,4,0,local_58,0);
    DAT_00f07328 = local_58[0];
  }
  DAT_00f0732c = DAT_00f07328;
  return 0;
}

