
undefined4 FUN_005c0030(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if ((DAT_00cc47d0 != 0) && (iVar3 = DAT_00cc4808, DAT_00cc4808 <= DAT_00cc480c)) {
    do {
      iVar1 = *(int *)(DAT_00cc47d4 + iVar3 * 4);
      if (iVar1 != 0) {
        FUN_005806c0(*(undefined4 *)(iVar1 + 4));
        if (*(int *)(iVar1 + 0x4c) != 0) {
          FUN_00568aa0(*(int *)(iVar1 + 0x4c));
          if (*(int *)(iVar1 + 0x34) != -1) {
            FUN_0057b600(*(int *)(iVar1 + 0x34));
          }
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= DAT_00cc480c);
  }
  if ((DAT_00cc79c0 != 0) && (iVar3 = DAT_00cc79f8, DAT_00cc79f8 <= DAT_00cc79fc)) {
    do {
      iVar1 = *(int *)(DAT_00cc79c4 + iVar3 * 4);
      if (iVar1 != 0) {
        FUN_005806c0(*(undefined4 *)(iVar1 + 4));
        FUN_005bfa30(iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= DAT_00cc79fc);
  }
  if ((DAT_00cc70f0 != 0) && (iVar3 = DAT_00cc7128, DAT_00cc7128 <= DAT_00cc712c)) {
    do {
      iVar1 = *(int *)(DAT_00cc70f4 + iVar3 * 4);
      if (iVar1 != 0) {
        FUN_005806c0(*(undefined4 *)(iVar1 + 4));
        if (**(int **)(iVar1 + 0x40) != 0) {
          FUN_005d1ec0(**(int **)(iVar1 + 0x40));
          **(undefined4 **)(iVar1 + 0x40) = 0;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= DAT_00cc712c);
  }
  if ((DAT_00cc73e0 != 0) && (iVar3 = DAT_00cc7418, DAT_00cc7418 <= DAT_00cc741c)) {
    do {
      iVar1 = *(int *)(DAT_00cc73e4 + iVar3 * 4);
      if (iVar1 != 0) {
        FUN_005806c0(*(undefined4 *)(iVar1 + 4));
        if (**(int **)(iVar1 + 0x40) != 0) {
          FUN_005d1ec0(**(int **)(iVar1 + 0x40));
          **(undefined4 **)(iVar1 + 0x40) = 0;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= DAT_00cc741c);
  }
  if ((DAT_00cc6820 != 0) && (iVar3 = DAT_00cc6858, DAT_00cc6858 <= DAT_00cc685c)) {
    do {
      iVar1 = *(int *)(DAT_00cc6824 + iVar3 * 4);
      if (iVar1 != 0) {
        FUN_005806c0(*(undefined4 *)(iVar1 + 4));
        piVar2 = *(int **)(iVar1 + 0x3c);
        if (*(int *)(iVar1 + 0x30) == 0) {
          if (*piVar2 != 0) {
            FUN_005d1fc0(*piVar2);
            **(undefined4 **)(iVar1 + 0x3c) = 0;
          }
        }
        else if (*piVar2 != 0) {
          FUN_005d1fa0(*piVar2);
          **(undefined4 **)(iVar1 + 0x3c) = 0;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= DAT_00cc685c);
  }
  FUN_0056d380(&DAT_00f13454,0,0x200);
  DAT_00f13700 = 0;
  DAT_00f136f4 = 0;
  DAT_00f136ec = 0;
  DAT_00f136f8 = 0;
  DAT_00f13704 = 0;
  FUN_0056d380(&DAT_00f1370c,0,0x20);
  FUN_0056d380(&DAT_00f1388c,0,0x20);
  DAT_00f138ac = 0;
  DAT_00f138dc = 0;
  return 0;
}

