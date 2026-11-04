
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0055c820(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &DAT_00a83cb8;
  do {
    if (*piVar2 != 0) {
      FUN_0057e620(piVar2);
      iVar1 = piVar2[0x13];
      if (iVar1 != 0) {
        *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + -1;
        if ((*(int *)(iVar1 + 0xc) < 1) && (-1 < *(int *)(iVar1 + 0xc))) {
          FUN_0056e1d0(iVar1);
        }
        piVar2[0x13] = 0;
      }
      *piVar2 = 0;
    }
    if (piVar2[0x71] != 0) {
      FUN_0056e1d0(piVar2[0x71]);
      piVar2[0x71] = 0;
    }
    piVar2[0x73] = 0;
    piVar2[0x74] = 0;
    piVar2[0x75] = 0;
    piVar2[0x76] = 0;
    piVar2 = piVar2 + 0x77;
  } while ((int)piVar2 < 0xa8424c);
  _DAT_00a83cac = 0;
  DAT_00a83cb4 = 0;
  DAT_00a83cb0 = 0;
  return 0;
}

