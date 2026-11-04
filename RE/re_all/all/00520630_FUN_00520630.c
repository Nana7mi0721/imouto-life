
undefined4
FUN_00520630(int param_1,int param_2,uint param_3,undefined4 param_4,int param_5,int param_6)

{
  int *piVar1;
  undefined4 uVar2;
  
  if ((((DAT_00cc47d0 == 0) || ((int)param_3 < 0)) || ((param_3 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(param_3 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc47d4 + (param_3 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_3 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  if (param_5 == 0) {
    if (param_6 == 0) {
      uVar2 = FUN_0051e930(param_1,param_2,param_3,param_4);
      return uVar2;
    }
    uVar2 = FUN_0051f060(param_1,piVar1[0x19] + param_2,piVar1[0x18] + param_1,param_2);
    return uVar2;
  }
  if (param_6 == 0) {
    uVar2 = FUN_0051f060();
    return uVar2;
  }
  uVar2 = FUN_0051f060(piVar1[0x18] + param_1,piVar1[0x19] + param_2,param_1,param_2,param_3,param_4
                      );
  return uVar2;
}

