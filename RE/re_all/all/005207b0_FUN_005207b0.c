
undefined4 __thiscall
FUN_005207b0(undefined4 param_1,float param_2,float param_3,uint param_4,undefined4 param_5,
            int param_6,int param_7)

{
  int *piVar1;
  undefined4 uVar2;
  
  if ((((DAT_00cc47d0 == 0) || ((int)param_4 < 0)) || ((param_4 & 0x7c000000) != DAT_00cc47f8)) ||
     (((DAT_00cc4800 <= (int)(param_4 & 0xffff) ||
       (piVar1 = *(int **)(DAT_00cc47d4 + (param_4 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
      ((*piVar1 * 0x10000 != (param_4 & 0x3ff0000) || (piVar1[4] != 0)))))) {
    return 0xffffffff;
  }
  if (param_6 == 0) {
    if (param_7 == 0) {
      uVar2 = FUN_0051ecb0(param_2,param_3,param_4,param_5,param_1);
      return uVar2;
    }
    uVar2 = FUN_0051f460(param_2,(float)piVar1[0x1b] + param_3,param_2 + (float)piVar1[0x1a],param_3
                         ,param_4,param_5);
    return uVar2;
  }
  if (param_7 == 0) {
    uVar2 = FUN_0051f460(param_2 + (float)piVar1[0x1a],param_3,param_2,param_3 + (float)piVar1[0x1b]
                         ,param_4,param_5);
    return uVar2;
  }
  uVar2 = FUN_0051f460(param_2 + (float)piVar1[0x1a],(float)piVar1[0x1b] + param_3,param_2,param_3,
                       param_4,param_5);
  return uVar2;
}

