
undefined4 FUN_005c0250(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_18 [6];
  
  if ((DAT_00cc47d0 != 0) && (iVar3 = DAT_00cc4808, DAT_00cc4808 <= DAT_00cc480c)) {
    do {
      iVar1 = *(int *)(DAT_00cc47d4 + iVar3 * 4);
      if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0x4c), iVar1 != 0)) {
        FUN_00568a80(iVar1,0);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= DAT_00cc480c);
  }
  if ((DAT_00cc79c0 != 0) && (iVar3 = DAT_00cc79f8, DAT_00cc79f8 <= DAT_00cc79fc)) {
    do {
      iVar1 = *(int *)(DAT_00cc79c4 + iVar3 * 4);
      if (iVar1 != 0) {
        FUN_005bf720(iVar1,0);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= DAT_00cc79fc);
  }
  if ((DAT_00cc70f0 != 0) && (iVar3 = DAT_00cc7128, DAT_00cc7128 <= DAT_00cc712c)) {
    do {
      iVar1 = *(int *)(DAT_00cc70f4 + iVar3 * 4);
      if (iVar1 != 0) {
        FUN_0056d380(local_18,0,0x18);
        local_18[0] = *(int *)(iVar1 + 0x34) * *(int *)(iVar1 + 0x38);
        local_18[1] = 0;
        local_18[2] = 1;
        local_18[3] = 0;
        iVar2 = FUN_005d27b0(local_18,0,*(undefined4 *)(iVar1 + 0x40));
        if (iVar2 < 0) {
          FUN_0056bca0(&DAT_007fceb8);
        }
        else {
          FUN_00516a40(0,*(undefined4 *)(iVar1 + 0x3c),*(undefined4 *)(iVar1 + 0x38),
                       *(undefined4 *)(iVar1 + 4));
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= DAT_00cc712c);
  }
  if ((DAT_00cc73e0 != 0) && (iVar3 = DAT_00cc7418, DAT_00cc7418 <= DAT_00cc741c)) {
    do {
      iVar1 = *(int *)(DAT_00cc73e4 + iVar3 * 4);
      if (iVar1 != 0) {
        FUN_0056d380(local_18,0,0x18);
        local_18[0] = *(int *)(iVar1 + 0x34) * *(int *)(iVar1 + 0x38);
        local_18[1] = 0;
        local_18[2] = 2;
        local_18[3] = 0;
        iVar2 = FUN_005d27b0(local_18,0,*(undefined4 *)(iVar1 + 0x40));
        if (iVar2 < 0) {
          FUN_0056bca0(&DAT_007fcef8);
        }
        else {
          FUN_00516b00(0,*(undefined4 *)(iVar1 + 0x3c),*(undefined4 *)(iVar1 + 0x38),
                       *(undefined4 *)(iVar1 + 4));
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= DAT_00cc741c);
  }
  if ((DAT_00cc6820 != 0) && (iVar3 = DAT_00cc6858, DAT_00cc6858 <= DAT_00cc685c)) {
    do {
      iVar1 = *(int *)(DAT_00cc6824 + iVar3 * 4);
      if (iVar1 != 0) {
        if (*(int *)(iVar1 + 0x30) == 0) {
          FUN_005d2910(*(undefined4 *)(iVar1 + 0x34),*(undefined4 *)(iVar1 + 0x38),0,
                       *(undefined4 *)(iVar1 + 0x3c));
        }
        else {
          FUN_005d28e0();
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= DAT_00cc685c);
  }
  return 0;
}

