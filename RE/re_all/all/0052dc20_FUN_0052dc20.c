
undefined4 FUN_0052dc20(undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  
  if (param_4 != 0) {
    if (param_4 == 1) {
      bVar2 = CARRY4(param_1[2],param_2);
      param_2 = param_1[2] + param_2;
      param_3 = param_1[3] + param_3 + (uint)bVar2;
    }
    else {
      if (param_4 != 2) {
        return 0xffffffff;
      }
      bVar2 = CARRY4(param_1[4],param_2);
      param_2 = param_1[4] + param_2;
      param_3 = param_1[5] + param_3 + (uint)bVar2;
    }
  }
  if ((param_3 < 1) && (param_3 < 0)) {
    param_3 = 0;
    param_2 = 0;
  }
  else {
    iVar1 = param_1[5];
    if (iVar1 <= param_3) {
      if (param_3 <= iVar1) {
        if (param_2 <= (uint)param_1[4]) goto LAB_0052dc8d;
      }
      param_3 = iVar1;
      param_2 = param_1[4];
    }
  }
LAB_0052dc8d:
  iVar1 = FUN_005953c0(param_1,param_2,param_3);
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  param_1[2] = param_2;
  param_1[3] = param_3;
  *param_1 = 0;
  return 0;
}

