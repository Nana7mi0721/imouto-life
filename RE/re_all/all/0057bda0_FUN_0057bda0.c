
undefined4 FUN_0057bda0(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((((DAT_00cc5680 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc56a8)) ||
     (((DAT_00cc56b0 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc5684 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  if (piVar1[0x33] == 1) {
    return 0;
  }
  if (piVar1[0xd] == 0) {
    iVar2 = FUN_005da500(piVar1,param_2);
    if (iVar2 < 0) {
      return 0;
    }
  }
  else {
    FUN_0055f370(piVar1[0x1c]);
    FUN_0057b670(param_1,0);
  }
  piVar1[0x33] = 1;
  if (param_2 == 0) {
    piVar1[0x32] = 0;
  }
  return 0;
}

