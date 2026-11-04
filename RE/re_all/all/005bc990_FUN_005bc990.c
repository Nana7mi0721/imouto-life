
undefined4 FUN_005bc990(void)

{
  int *piVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  piVar1 = &DAT_00ef728c;
  do {
    if (*piVar1 != 0) {
      FUN_005d1f80(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0xef72a8);
  if (DAT_00ef72a8 != 0) {
    FUN_005d1f80(DAT_00ef72a8);
    DAT_00ef72a8 = 0;
  }
  if (DAT_00ef72ac != 0) {
    FUN_005d1f80(DAT_00ef72ac);
    DAT_00ef72ac = 0;
  }
  return 0;
}

