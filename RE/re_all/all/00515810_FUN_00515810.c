
undefined4 FUN_00515810(uint param_1,int param_2)

{
  int *piVar1;
  
  if ((((DAT_00cc47d0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      (*piVar1 * 0x10000 != (param_1 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  piVar1[0x21] = (uint)(param_2 != 0);
  return 0;
}

