
undefined4 FUN_0055f6b0(uint param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = FUN_0057e0e0();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (((((DAT_00cc5390 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_00cc53b8)) &&
      (((int)(param_1 & 0xffff) < DAT_00cc53c0 &&
       (piVar1 = *(int **)(DAT_00cc5394 + (param_1 & 0xffff) * 4), piVar1 != (int *)0x0)))) &&
     ((*piVar1 * 0x10000 == (param_1 & 0x3ff0000) && (piVar1[4] == 0)))) {
    if ((DAT_00a834e4 != 0) && (DAT_00a834e8 == 1)) {
      FUN_0055f370(DAT_00a834e4);
      FUN_00580b80(DAT_00a834e4);
      DAT_00a834e4 = 0;
      return 0;
    }
    DAT_00a834d8 = 0;
    iVar2 = FUN_0057f4f0(piVar1);
    if (-1 < iVar2) {
      piVar1[0xc] = 0;
      piVar1[0xd] = 0;
      return 0;
    }
  }
  return 0xffffffff;
}

