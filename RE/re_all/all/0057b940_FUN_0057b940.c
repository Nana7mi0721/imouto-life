
undefined4 FUN_0057b940(uint param_1,int param_2,int param_3)

{
  int *piVar1;
  
  if ((((DAT_00cc5680 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc56a8)) ||
     (((DAT_00cc56b0 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc5684 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  piVar1[0x158] = param_2;
  piVar1[0x159] = param_3;
  return 0;
}

