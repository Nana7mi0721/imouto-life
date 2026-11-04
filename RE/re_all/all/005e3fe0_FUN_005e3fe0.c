
undefined4 FUN_005e3fe0(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((((DAT_00cc6e00 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc6e28)) ||
     (((DAT_00cc6e30 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc6e04 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      (*piVar1 * 0x10000 != (param_1 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  iVar2 = 0;
  if (0 < *(int *)(piVar1[0x10] + 0x124)) {
    puVar3 = (undefined4 *)(piVar1[0x6b] + 0xc);
    do {
      if (*(int *)*puVar3 != 0) {
        FUN_005d5640(*(int *)*puVar3,0);
        *(undefined4 *)*puVar3 = 0;
      }
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 6;
    } while (iVar2 < *(int *)(piVar1[0x10] + 0x124));
  }
  return 0;
}

