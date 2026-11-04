
undefined4 FUN_00516bd0(uint param_1,uint param_2)

{
  int *piVar1;
  
  if (0xf < param_1) {
    return 0xffffffff;
  }
  if (param_2 == 0xffffffff) {
    (&DAT_00a38d78)[param_1] = 0;
    return 0;
  }
  if (((((DAT_00cc47d0 == 0) || ((int)param_2 < 0)) || ((param_2 & 0x7c000000) != DAT_00cc47f8)) ||
      (((DAT_00cc4800 <= (int)(param_2 & 0xffff) ||
        (piVar1 = *(int **)(DAT_00cc47d4 + (param_2 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
       ((*piVar1 * 0x10000 != (param_2 & 0x3ff0000) || (piVar1[4] != 0)))))) &&
     ((((DAT_00cc79c0 == 0 || ((int)param_2 < 0)) ||
       (((param_2 & 0x7c000000) != DAT_00cc79e8 ||
        (((DAT_00cc79f0 <= (int)(param_2 & 0xffff) ||
          (piVar1 = *(int **)(DAT_00cc79c4 + (param_2 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
         (*piVar1 * 0x10000 != (param_2 & 0x3ff0000))))))) || (piVar1[4] != 0)))) {
    return 0xffffffff;
  }
  (&DAT_00a38d78)[param_1] = param_2;
  return 0;
}

