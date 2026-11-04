
undefined4 __thiscall FUN_0052caf0(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_4 == 0) {
    if ((((DAT_00cc76d0 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_00cc76f8))
       && ((((int)(param_1 & 0xffff) < DAT_00cc7700 &&
            (piVar1 = *(int **)(DAT_00cc76d4 + (param_1 & 0xffff) * 4), piVar1 != (int *)0x0)) &&
           ((*piVar1 * 0x10000 == (param_1 & 0x3ff0000) && (piVar1[4] == 0)))))) goto LAB_0052cb8f;
  }
  else if (((DAT_00cc76d0 != 0) && (-1 < (int)param_1)) &&
          (((param_1 & 0x7c000000) == DAT_00cc76f8 &&
           ((((int)(param_1 & 0xffff) < DAT_00cc7700 &&
             (piVar1 = *(int **)(DAT_00cc76d4 + (param_1 & 0xffff) * 4), piVar1 != (int *)0x0)) &&
            (*piVar1 * 0x10000 == (param_1 & 0x3ff0000))))))) {
LAB_0052cb8f:
    uVar2 = (*(code *)piVar1[0xf])(param_2,1,param_3,piVar1[0x13]);
    return uVar2;
  }
  return 0xffffffff;
}

