
undefined4 FUN_00536810(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1 == 0xfffffffe) {
    FUN_00530d80();
    param_1 = DAT_00a4bca8;
  }
  if ((((DAT_00cc5c60 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc5c88)) ||
     (((DAT_00cc5c90 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc5c64 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  iVar4 = piVar1[0x24b67];
  iVar2 = 0;
  if (0 < iVar4) {
    piVar3 = piVar1 + 0x24b68;
    do {
      if (*piVar3 == param_2) break;
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 3;
    } while (iVar2 < iVar4);
  }
  if (iVar2 == iVar4) {
    return 0xffffffff;
  }
  piVar1[0x24b67] = iVar4 + -1;
  iVar4 = (iVar4 + -1) - iVar2;
  if (0 < iVar4) {
    FUN_0056d460(piVar1 + iVar2 * 3 + 0x24b68,piVar1 + iVar2 * 3 + 0x24b6b,iVar4 * 0xc);
  }
  return 0;
}

