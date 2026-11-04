
undefined4 FUN_005ba4f0(void)

{
  int *piVar1;
  int iVar2;
  
  DAT_00f13210 = 0;
  if (DAT_00f1324c != 0) {
    FUN_005d2000(DAT_00f13248);
    DAT_00f1324c = 0;
  }
  DAT_00f13248 = 0;
  piVar1 = &DAT_00f13250;
  iVar2 = 0x24;
  do {
    if (*piVar1 != 0) {
      FUN_005d2000(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

