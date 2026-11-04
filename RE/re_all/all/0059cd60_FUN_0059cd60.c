
undefined4 FUN_0059cd60(void)

{
  uint uVar1;
  int *piVar2;
  
  if (DAT_00f3a04c != 0) {
    FUN_0059b780(0);
    if (((DAT_00e39a54 != 0) || (DAT_00e80624 != 0)) && (DAT_00f3a04c != 0)) {
      if ((DAT_00e39a54 != 0) || (DAT_00e80624 != 0)) {
        FUN_005d3d20(0);
        DAT_00e80624 = 0;
      }
      DAT_00e80620 = 0;
      DAT_00e39a00 = 1;
    }
    uVar1 = 0;
    do {
      if (*(int *)((int)&DAT_00e39924 + uVar1) != 0) {
        FUN_005d3370(*(int *)((int)&DAT_00e39924 + uVar1));
        *(undefined4 *)((int)&DAT_00e39924 + uVar1) = 0;
      }
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0xd8);
    piVar2 = &DAT_00e398f4;
    do {
      if (*piVar2 != 0) {
        FUN_005d3370(*piVar2);
        *piVar2 = 0;
      }
      piVar2 = piVar2 + 1;
    } while ((int)piVar2 < 0xe3991c);
    piVar2 = &DAT_00e3991c;
    do {
      if (*piVar2 != 0) {
        FUN_005d3370(*piVar2);
        *piVar2 = 0;
      }
      piVar2 = piVar2 + 1;
    } while ((int)piVar2 < 0xe39924);
  }
  return 0;
}

