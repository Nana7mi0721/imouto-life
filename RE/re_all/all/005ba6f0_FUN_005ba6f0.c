
undefined4 FUN_005ba6f0(void)

{
  int *piVar1;
  int iVar2;
  
  DAT_00f132e4 = 0;
  if (DAT_00f133f4 != 0) {
    FUN_005d1fe0(DAT_00f133f0);
    DAT_00f133f4 = 0;
  }
  DAT_00f133f0 = 0;
  piVar1 = &DAT_00f133f8;
  iVar2 = 0x17;
  do {
    if (*piVar1 != 0) {
      FUN_005d1fe0(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

