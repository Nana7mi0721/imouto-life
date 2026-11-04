
undefined4 FUN_005b8c50(void)

{
  int *piVar1;
  
  piVar1 = &DAT_00ef1fa8;
  do {
    if (*piVar1 != 0) {
      FUN_005d2040(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0xef1fb0);
  if (DAT_00ef1fb0 != 0) {
    FUN_005d2020(DAT_00ef1fb0);
    DAT_00ef1fb0 = 0;
  }
  if (DAT_00ef1fb4 != 0) {
    FUN_005d2000(DAT_00ef1fb4);
    DAT_00ef1fb4 = 0;
  }
  piVar1 = &DAT_00ef1fb8;
  do {
    if (*piVar1 != 0) {
      FUN_005d1fe0(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0xef1fc0);
  return 0;
}

