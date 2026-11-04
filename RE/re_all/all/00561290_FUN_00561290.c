
undefined4 FUN_00561290(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_0057e0e0();
  if (((((iVar2 == 0) || (DAT_00cc5390 == 0)) || ((int)param_1 < 0)) ||
      (((param_1 & 0x7c000000) != DAT_00cc53b8 || (DAT_00cc53c0 <= (int)(param_1 & 0xffff))))) ||
     ((piVar1 = *(int **)(DAT_00cc5394 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0 ||
      ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  if ((DAT_00a834e4 == 0) || (DAT_00a834e8 != 1)) {
    uVar3 = FUN_0057e220();
    return uVar3;
  }
  uVar3 = FUN_00560f10();
  return uVar3;
}

