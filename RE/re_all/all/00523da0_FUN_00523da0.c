
undefined4
FUN_00523da0(undefined4 param_1,undefined4 param_2,int *param_3,int param_4,int param_5,uint param_6
            ,undefined4 param_7,int param_8)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (DAT_00a37d70 == 0) {
    return 0xffffffff;
  }
  if (param_8 == 0) {
    if ((((DAT_00cc47d0 != 0) && (-1 < (int)param_6)) && ((param_6 & 0x7c000000) == DAT_00cc47f8))
       && ((((int)(param_6 & 0xffff) < DAT_00cc4800 &&
            (piVar1 = *(int **)(DAT_00cc47d4 + (param_6 & 0xffff) * 4), piVar1 != (int *)0x0)) &&
           ((*piVar1 * 0x10000 == (param_6 & 0x3ff0000) && (piVar1[4] == 0)))))) goto LAB_00523e5e;
  }
  else if (((DAT_00cc47d0 != 0) && (-1 < (int)param_6)) &&
          (((param_6 & 0x7c000000) == DAT_00cc47f8 &&
           ((((int)(param_6 & 0xffff) < DAT_00cc4800 &&
             (piVar1 = *(int **)(DAT_00cc47d4 + (param_6 & 0xffff) * 4), piVar1 != (int *)0x0)) &&
            (*piVar1 * 0x10000 == (param_6 & 0x3ff0000))))))) {
LAB_00523e5e:
    piVar1[0xf] = *param_3 - param_4;
    piVar1[0x11] = (int)(float)(*param_3 - param_4);
    piVar1[0x10] = param_3[1] - param_5;
    piVar1[0x12] = (int)(float)(param_3[1] - param_5);
    uVar2 = FUN_00518620(param_3,param_4,param_5,param_6,param_1,param_2,
                         *(undefined1 *)(piVar1[0x13] + 0x17),param_7,0,param_8);
    return uVar2;
  }
  return 0xffffffff;
}

