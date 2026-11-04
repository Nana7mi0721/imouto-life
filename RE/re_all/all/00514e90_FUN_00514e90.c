
int __fastcall FUN_00514e90(undefined4 param_1,int param_2)

{
  int *piVar1;
  
  if (DAT_00a37d78 != 0) {
    return 0;
  }
  if (DAT_00a380e8 != 0) {
    return -1;
  }
  if ((((DAT_00cc47d0 == 0) || ((int)DAT_00a380d4 < 0)) ||
      ((DAT_00a380d4 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(DAT_00a380d4 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc47d4 + (DAT_00a380d4 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (DAT_00a380d4 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return -1;
  }
  return -(uint)(((piVar1[0x19] - *(int *)(param_2 + 100) | piVar1[0x18] - *(int *)(param_2 + 0x60))
                 & 0x80000000U) != 0);
}

