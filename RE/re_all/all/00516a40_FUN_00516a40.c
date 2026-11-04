
undefined4 FUN_00516a40(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  
  if (((((DAT_00cc70f0 == 0) || ((int)param_4 < 0)) || ((param_4 & 0x7c000000) != DAT_00cc7118)) ||
      ((DAT_00cc7120 <= (int)(param_4 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc70f4 + (param_4 & 0xffff) * 4), piVar1 == (int *)0x0)))) ||
     ((*piVar1 * 0x10000 != (param_4 & 0x3ff0000) || (piVar1[4] != 0)))) {
    return 0xffffffff;
  }
  if ((piVar1[0xe] < param_1 + param_3) || (param_1 < 0)) {
    return 0xffffffff;
  }
  iVar2 = FUN_00568ae0(piVar1,param_1,param_2,param_3);
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  FUN_0056d420(piVar1[0xd] * param_1 + piVar1[0xf],param_2,piVar1[0xd] * param_3);
  return 0;
}

