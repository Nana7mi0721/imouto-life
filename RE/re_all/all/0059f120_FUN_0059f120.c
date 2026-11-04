
undefined4 FUN_0059f120(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  
  iVar5 = 0;
  pcVar4 = &DAT_00ec3b18;
  if (0 < DAT_00ecfb18) {
    do {
      if (*pcVar4 != '\0') {
        iVar5 = iVar5 + 1;
        FUN_0059ce90(pcVar4);
      }
      pcVar4 = pcVar4 + 0x18;
    } while (iVar5 < DAT_00ecfb18);
  }
  iVar5 = 0;
  pcVar4 = &DAT_00ecfb1c;
  if (0 < DAT_00edbb1c) {
    do {
      if (*pcVar4 != '\0') {
        iVar5 = iVar5 + 1;
        FUN_0059d030(pcVar4);
      }
      pcVar4 = pcVar4 + 0x18;
    } while (iVar5 < DAT_00edbb1c);
  }
  if ((DAT_00cc47d0 != 0) && (iVar5 = DAT_00cc4808, DAT_00cc4808 <= DAT_00cc480c)) {
    do {
      iVar1 = *(int *)(DAT_00cc47d4 + iVar5 * 4);
      if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0x4c), iVar1 != 0)) {
        FUN_00568a80(iVar1,0);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= DAT_00cc480c);
  }
  if ((DAT_00cc79c0 != 0) && (iVar5 = DAT_00cc79f8, DAT_00cc79f8 <= DAT_00cc79fc)) {
    do {
      iVar1 = *(int *)(DAT_00cc79c4 + iVar5 * 4);
      if (iVar1 != 0) {
        FUN_0059e610(iVar1,0);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= DAT_00cc79fc);
  }
  if ((DAT_00cc70f0 != 0) && (iVar5 = DAT_00cc7128, DAT_00cc7128 <= DAT_00cc712c)) {
    do {
      iVar1 = *(int *)(DAT_00cc70f4 + iVar5 * 4);
      if (((iVar1 != 0) && ((DAT_00ddb4b0 != 0 || (DAT_00ddb5f0 != 0)))) &&
         ((*(int *)(iVar1 + 0x30) == 0 || (*(int *)(iVar1 + 0x30) == 1)))) {
        iVar2 = FUN_005d5ba0(*(int *)(iVar1 + 0x34) * *(int *)(iVar1 + 0x38),8,0x2d2,0,
                             *(undefined4 *)(iVar1 + 0x40),0);
        if (iVar2 < 0) {
          FUN_0056bb10(&DAT_007fa188);
        }
        else {
          FUN_00516a40(0,*(undefined4 *)(iVar1 + 0x3c),*(undefined4 *)(iVar1 + 0x38),
                       *(undefined4 *)(iVar1 + 4));
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= DAT_00cc712c);
  }
  if ((DAT_00cc73e0 != 0) && (iVar5 = DAT_00cc7418, DAT_00cc7418 <= DAT_00cc741c)) {
    do {
      iVar1 = *(int *)(DAT_00cc73e4 + iVar5 * 4);
      if ((iVar1 != 0) && ((DAT_00ddb4b0 != 0 || (DAT_00ddb5f0 != 0)))) {
        uVar3 = 0x65;
        if ((*(int *)(iVar1 + 0x30) != 0) && (*(int *)(iVar1 + 0x30) == 1)) {
          uVar3 = 0x66;
        }
        iVar2 = FUN_005d5c30(*(int *)(iVar1 + 0x34) * *(int *)(iVar1 + 0x38),8,uVar3,0,
                             *(undefined4 *)(iVar1 + 0x40),0);
        if (iVar2 < 0) {
          FUN_0056bb10(&DAT_007fa1ac);
        }
        else {
          FUN_00516b00(0,*(undefined4 *)(iVar1 + 0x3c),*(undefined4 *)(iVar1 + 0x38),
                       *(undefined4 *)(iVar1 + 4));
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= DAT_00cc741c);
  }
  if ((DAT_00cc6820 != 0) && (iVar5 = DAT_00cc6858, DAT_00cc6858 <= DAT_00cc685c)) {
    do {
      iVar1 = *(int *)(DAT_00cc6824 + iVar5 * 4);
      if (iVar1 != 0) {
        if (*(int *)(iVar1 + 0x30) == 0) {
          FUN_005d3d00(*(undefined4 *)(iVar1 + 0x34),*(undefined4 *)(iVar1 + 0x3c));
        }
        else {
          FUN_005d3c10();
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= DAT_00cc685c);
  }
  return 0;
}

