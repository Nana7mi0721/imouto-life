
undefined4 FUN_005bcda0(void)

{
  int *piVar1;
  int iVar2;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  piVar1 = &DAT_00ef72b0;
  do {
    iVar2 = 3;
    do {
      if (*piVar1 != 0) {
        FUN_005d1f80(*piVar1);
        *piVar1 = 0;
      }
      piVar1 = piVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  } while ((int)piVar1 < 0xef72c8);
  return 0;
}

