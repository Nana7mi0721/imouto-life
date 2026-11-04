
undefined4 FUN_005ea0b0(uint param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if ((((DAT_00cc6e00 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc6e28)) ||
     (((DAT_00cc6e30 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc6e04 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      (*piVar1 * 0x10000 != (param_1 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  iVar2 = 0;
  if (0 < *(int *)(piVar1[0x10] + 0x124)) {
    piVar3 = (int *)(piVar1[0x6b] + 0xc);
    do {
      if (*(int *)*piVar3 != 0) {
        FUN_0056e1d0(*(int *)*piVar3);
        *(undefined4 *)*piVar3 = 0;
      }
      if (*(int *)(*piVar3 + 4) != 0) {
        FUN_005d1ec0(*(int *)(*piVar3 + 4));
        *(undefined4 *)(*piVar3 + 4) = 0;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 6;
    } while (iVar2 < *(int *)(piVar1[0x10] + 0x124));
  }
  return 0;
}

