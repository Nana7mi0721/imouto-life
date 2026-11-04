
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050e770(void)

{
  int iVar1;
  
  iVar1 = FUN_0050e710();
  if (((iVar1 == 1) && (DAT_00a21060 == 0)) && (DAT_00a20bec != 0)) {
    _DAT_00a21084 = FUN_00550060(0);
    _DAT_00a21080 = 1;
    do {
      iVar1 = FUN_005501a0();
      if (iVar1 != 0) {
        return;
      }
    } while ((DAT_00a21078 == 0) || (DAT_00a2107c == 1));
  }
  return;
}

