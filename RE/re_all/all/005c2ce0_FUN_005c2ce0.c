
undefined4 FUN_005c2ce0(uint param_1)

{
  int *piVar1;
  
  if (((((DAT_00cc6820 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc6848)) ||
      ((DAT_00cc6850 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc6824 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)))) ||
     ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || ((piVar1[4] != 0 || (piVar1[0xc] != 0)))))) {
    return 0xffffffff;
  }
  FUN_005bb880(*(undefined4 *)piVar1[0xf],0);
  return 0;
}

