
undefined4
FUN_00523c60(int param_1,undefined4 param_2,int param_3,int param_4,uint param_5,undefined4 param_6,
            int param_7)

{
  int *piVar1;
  undefined4 uVar2;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (DAT_00a37d70 == 0) {
    return 0xffffffff;
  }
  if (param_7 == 0) {
    if ((((DAT_00cc47d0 != 0) && (-1 < (int)param_5)) && ((param_5 & 0x7c000000) == DAT_00cc47f8))
       && ((((int)(param_5 & 0xffff) < DAT_00cc4800 &&
            (piVar1 = *(int **)(DAT_00cc47d4 + (param_5 & 0xffff) * 4), piVar1 != (int *)0x0)) &&
           ((*piVar1 * 0x10000 == (param_5 & 0x3ff0000) && (piVar1[4] == 0)))))) goto LAB_00523d24;
  }
  else if (((DAT_00cc47d0 != 0) && (-1 < (int)param_5)) &&
          (((param_5 & 0x7c000000) == DAT_00cc47f8 &&
           ((((int)(param_5 & 0xffff) < DAT_00cc4800 &&
             (piVar1 = *(int **)(DAT_00cc47d4 + (param_5 & 0xffff) * 4), piVar1 != (int *)0x0)) &&
            (*piVar1 * 0x10000 == (param_5 & 0x3ff0000))))))) {
LAB_00523d24:
    local_8 = *(int *)(param_1 + 0x428) + param_3;
    local_4 = *(int *)(param_1 + 0x42c);
    piVar1[0x11] = (int)(float)param_3;
    piVar1[0x10] = param_4;
    local_4 = local_4 + param_4;
    local_c = param_4;
    piVar1[0x12] = (int)(float)param_4;
    piVar1[0xf] = param_3;
    local_10 = param_3;
    uVar2 = FUN_00518620(&local_10,0,0,param_5,param_1,param_2,*(undefined1 *)(piVar1[0x13] + 0x17),
                         param_6,0,param_7);
    return uVar2;
  }
  return 0xffffffff;
}

