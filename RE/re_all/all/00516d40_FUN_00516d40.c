
undefined4 FUN_00516d40(uint param_1)

{
  int *piVar1;
  
  if (((int)param_1 < 1) ||
     (((((DAT_00cc6820 != 0 && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_00cc6848)) &&
       (((int)(param_1 & 0xffff) < DAT_00cc6850 &&
        (piVar1 = *(int **)(DAT_00cc6824 + (param_1 & 0xffff) * 4), piVar1 != (int *)0x0)))) &&
      ((*piVar1 * 0x10000 == (param_1 & 0x3ff0000) && ((piVar1[4] == 0 && (piVar1[0xc] != 1))))))))
  {
    DAT_00a38ddc = ((int)param_1 < 1) - 1 & param_1;
    return 0;
  }
  return 0xffffffff;
}

