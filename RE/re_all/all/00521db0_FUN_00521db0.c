
undefined4 FUN_00521db0(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int *piVar1;
  undefined4 uVar2;
  
  if ((((DAT_00cc47d0 == 0) || ((int)param_5 < 0)) || ((param_5 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(param_5 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc47d4 + (param_5 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_5 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  if (piVar1[0x18] == param_3 - param_1) {
    if (piVar1[0x19] == param_4 - param_2) {
      uVar2 = FUN_00519140(DAT_00a38120,DAT_00a38140,DAT_00a38160,param_1,param_2,param_3,param_4,0,
                           0,param_5);
      return uVar2;
    }
  }
  return 0xffffffff;
}

