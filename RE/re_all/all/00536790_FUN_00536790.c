
undefined4 FUN_00536790(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  
  if (param_1 == 0xfffffffe) {
    FUN_00530d80();
    param_1 = DAT_00a4bca8;
  }
  if ((((DAT_00cc5c60 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc5c88)) ||
     (((DAT_00cc5c90 <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc5c64 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  piVar1[0xd] = (int)param_2;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  return 0;
}

