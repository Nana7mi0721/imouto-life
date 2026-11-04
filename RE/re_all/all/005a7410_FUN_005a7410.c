
undefined4 FUN_005a7410(void)

{
  int iVar1;
  undefined1 local_20 [24];
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00ddb5c4 != 0) {
    return 0;
  }
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  iVar1 = FUN_005d35f0();
  if ((iVar1 != 0) && (DAT_00e79688 != 0)) {
    FUN_005d3950();
    DAT_00e79688 = 0;
  }
  DAT_00ddb5c0 = 0;
  if ((DAT_00a37d84 != 0) || (DAT_00a37d88 != 0)) goto LAB_005a7557;
  if (DAT_00a37db0 == 0) {
    DAT_00ddb5b8 = DAT_00a37e60;
    iVar1 = DAT_00a37e64;
LAB_005a74e0:
    DAT_00ddb5bc = iVar1;
  }
  else {
    iVar1 = 1;
    DAT_00ddb5b8 = 1;
    if (1 < DAT_00a37e60) {
      do {
        iVar1 = iVar1 * 2;
      } while (iVar1 < DAT_00a37e60);
      DAT_00ddb5b8 = iVar1;
    }
    iVar1 = 1;
    DAT_00ddb5bc = 1;
    if (1 < DAT_00a37e64) {
      do {
        iVar1 = iVar1 * 2;
      } while (iVar1 < DAT_00a37e64);
      goto LAB_005a74e0;
    }
  }
  iVar1 = FUN_005d5820(DAT_00ddb5b8,DAT_00ddb5bc,1,1,DAT_00ddb4d0,0,&DAT_00ddb5c0,0,0);
  if (iVar1 == 0) {
    iVar1 = FUN_005d5cc0(DAT_00ddb5c0,0,&DAT_00ddb5c4,0);
    if (iVar1 != 0) {
      FUN_0056bb10(&DAT_007fcaf8);
      return 0xffffffff;
    }
  }
  else {
    FUN_0056bca0(&DAT_007fca80,DAT_00ddb4d0,DAT_00ddb5b8,DAT_00ddb5bc);
  }
LAB_005a7557:
  if ((DAT_00ddb5c4 == 0) &&
     (iVar1 = FUN_005d3790(DAT_00a37e60,DAT_00a37e64,DAT_00ddb4d0,DAT_00a37d84,DAT_00a37d88,0,
                           &DAT_00ddb5c4,0), iVar1 < 0)) {
    FUN_0056bb10(&DAT_007fca50);
    return 0xffffffff;
  }
  FUN_005d3850(DAT_00ddb5b4,0,DAT_00ddb5c4,0,0);
  FUN_005d3880(DAT_00ddb5b4,0,0);
  iVar1 = DAT_00ddb5c4;
  DAT_00e39a54 = 1;
  if (DAT_00f3a04c != 0) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    FUN_005d38d0(0,iVar1);
    DAT_00e8063c = iVar1;
    FUN_005d2730(iVar1,local_20);
    FUN_005a0ad0(0,0,local_8,local_4);
  }
  DAT_00e39a54 = 0;
  return 0;
}

