
undefined4 FUN_00562730(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_0057e0e0();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (param_3 == 0) {
    if ((((DAT_00cc4db0 != 0) && (-1 < (int)param_2)) && ((param_2 & 0x7c000000) == DAT_00cc4dd8))
       && ((((int)(param_2 & 0xffff) < DAT_00cc4de0 &&
            (piVar1 = *(int **)(DAT_00cc4db4 + (param_2 & 0xffff) * 4), piVar1 != (int *)0x0)) &&
           ((*piVar1 * 0x10000 == (param_2 & 0x3ff0000) && (piVar1[4] == 0)))))) goto LAB_005627ee;
  }
  else if (((DAT_00cc4db0 != 0) && (-1 < (int)param_2)) &&
          (((param_2 & 0x7c000000) == DAT_00cc4dd8 &&
           ((((int)(param_2 & 0xffff) < DAT_00cc4de0 &&
             (piVar1 = *(int **)(DAT_00cc4db4 + (param_2 & 0xffff) * 4), piVar1 != (int *)0x0)) &&
            (*piVar1 * 0x10000 == (param_2 & 0x3ff0000))))))) {
LAB_005627ee:
    if (param_1 == -1) {
      FUN_005622f0(0xffffffff,param_2,param_3);
      return 0;
    }
    uVar3 = FUN_0055bbc0(param_1);
    FUN_005622f0(uVar3,param_2,param_3);
    return 0;
  }
  return 0xffffffff;
}

