
undefined4 FUN_005525d0(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if ((((DAT_00cc50a0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc50c8)) ||
     (((DAT_00cc50d0 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc50a4 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[0xc] != 0)))))) {
    return 0xffffffff;
  }
  uVar2 = FUN_00580b80();
  return uVar2;
}

