
undefined4 FUN_005ba2f0(void)

{
  int *piVar1;
  int iVar2;
  
  DAT_00f130dc = 0;
  if (DAT_00f1310c != 0) {
    FUN_005d2020(DAT_00f13108);
    DAT_00f1310c = 0;
  }
  DAT_00f13108 = 0;
  piVar1 = &DAT_00f13110;
  iVar2 = 0x40;
  do {
    if (*piVar1 != 0) {
      FUN_005d2020(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

