
int FUN_00526e30(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                uint param_7,undefined4 param_8,int param_9,int param_10)

{
  int *piVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((param_5 < 1) || (param_6 < 1)) {
    return -1;
  }
  local_1c = DAT_00a38198;
  local_20 = DAT_00a38194;
  local_14 = DAT_00a381a0;
  local_18 = DAT_00a3819c;
  local_c = DAT_00a381a8;
  local_10 = DAT_00a381a4;
  local_4 = DAT_00a381b0;
  local_8 = DAT_00a381ac;
  DAT_00a3819c = param_5 + param_1;
  DAT_00a381a0 = param_2 + param_6;
  DAT_00a38194 = param_1;
  DAT_00a38198 = param_2;
  FUN_00514e10(&DAT_00a38194,&local_20);
  if (DAT_00a37d78 == 0) {
    FUN_005811b0(&DAT_00a38194);
  }
  DAT_00a381a4 = (float)DAT_00a38194;
  DAT_00a381a8 = (float)DAT_00a38198;
  DAT_00a381ac = (float)DAT_00a3819c;
  DAT_00a381b0 = (float)DAT_00a381a0;
  if ((param_9 == 0) && (param_10 == 0)) {
    param_5 = FUN_0051e930(param_1 - param_3,param_2 - param_4,param_7,param_8);
  }
  else {
    if ((((DAT_00cc47d0 == 0) || ((int)param_7 < 0)) || ((param_7 & 0x7c000000) != DAT_00cc47f8)) ||
       (((DAT_00cc4800 <= (int)(param_7 & 0xffff) ||
         (piVar1 = *(int **)(DAT_00cc47d4 + (param_7 & 0xffff) * 4), piVar1 == (int *)0x0)) ||
        ((*piVar1 * 0x10000 != (param_7 & 0x3ff0000) || (piVar1[4] != 0)))))) {
      return -1;
    }
    if (param_9 == 0) {
      if (param_10 != 0) {
        param_5 = FUN_00520630(param_1 - param_3,(param_2 - piVar1[0x19]) + param_4 + param_6,
                               param_7,param_8,0,param_10);
      }
    }
    else {
      param_5 = (param_1 - piVar1[0x18]) + param_3 + param_5;
      if (param_10 == 0) {
        param_5 = FUN_00520630(param_5,param_2 - param_4,param_7,param_8,param_9,0);
      }
      else {
        param_5 = FUN_00520630(param_5,(param_2 - piVar1[0x19]) + param_4 + param_6,param_7,param_8,
                               param_9,param_10);
      }
    }
  }
  if (DAT_00ca39f4 != 0) {
    FUN_005217e0(local_20,local_1c,local_18,local_14);
    return param_5;
  }
  DAT_00a38194 = local_20;
  DAT_00a38198 = local_1c;
  DAT_00a3819c = local_18;
  DAT_00a381a0 = local_14;
  if (DAT_00a37d78 == 0) {
    FUN_005811b0(&local_20);
  }
  DAT_00a381a4 = (float)local_10;
  DAT_00a381b0 = (float)local_4;
  DAT_00a381a8 = (float)local_c;
  DAT_00a381ac = (float)local_8;
  return param_5;
}

