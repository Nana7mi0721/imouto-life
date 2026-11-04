
undefined4 FUN_00515880(uint param_1,int *param_2,int *param_3)

{
  int *piVar1;
  
  if ((param_1 == 0xfffffffc) || (param_1 == 0xfffffffe)) {
    if (param_2 != (int *)0x0) {
      *param_2 = DAT_00a37e60;
    }
    if (param_3 != (int *)0x0) {
      *param_3 = DAT_00a37e64;
    }
  }
  else if ((((DAT_00cc47d0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc47f8))
          || (((DAT_00cc4800 <= (int)(param_1 & 0xffff) ||
               (piVar1 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
              (*piVar1 * 0x10000 != (param_1 & 0x3ff0000))))) {
    if (((DAT_00cc79c0 == 0) || ((int)param_1 < 0)) ||
       ((((param_1 & 0x7c000000) != DAT_00cc79e8 ||
         (((DAT_00cc79f0 <= (int)(param_1 & 0xffff) ||
           (piVar1 = *(int **)(DAT_00cc79c4 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
          (*piVar1 * 0x10000 != (param_1 & 0x3ff0000))))) || (piVar1[4] != 0)))) {
      return 0xffffffff;
    }
    if (param_2 != (int *)0x0) {
      *param_2 = piVar1[0x48];
    }
    if (param_3 != (int *)0x0) {
      *param_3 = piVar1[0x49];
      return 0;
    }
  }
  else {
    if (param_2 != (int *)0x0) {
      *param_2 = piVar1[0x18];
    }
    if (param_3 != (int *)0x0) {
      *param_3 = piVar1[0x19];
      return 0;
    }
  }
  return 0;
}

