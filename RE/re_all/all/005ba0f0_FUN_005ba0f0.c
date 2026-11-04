
undefined4 FUN_005ba0f0(void)

{
  int *piVar1;
  int iVar2;
  
  DAT_00f07680 = 0;
  FUN_0056d380(&DAT_00f07684,0,0x40);
  piVar1 = &DAT_00f07a04;
  do {
    if (*piVar1 != 0) {
      if (piVar1[0x10] != 0) {
        FUN_005d2040(*piVar1);
        piVar1[0x10] = 0;
      }
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0xf07a44);
  piVar1 = &DAT_00f07a84;
  iVar2 = 0x2d90;
  do {
    if (*piVar1 != 0) {
      FUN_005d2040(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

