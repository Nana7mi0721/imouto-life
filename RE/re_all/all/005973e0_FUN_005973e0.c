
undefined4 FUN_005973e0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_1[3] < param_3) {
    return 0xffffffff;
  }
  iVar1 = param_1[4];
  if (param_1[1] == iVar1) {
    param_1[1] = 0;
  }
  if (param_1[2] == iVar1) {
    param_1[2] = 0;
  }
  iVar2 = param_1[1];
  if (iVar1 < iVar2 + param_3) {
    FUN_0056d420(param_2,*param_1 + iVar2,iVar1 - iVar2);
    FUN_0056d420((param_1[4] - param_1[1]) + param_2,*param_1,(param_1[1] - param_1[4]) + param_3);
    if (param_4 == 0) {
      param_1[3] = param_1[3] - param_3;
      param_1[1] = param_1[1] + (param_3 - param_1[4]);
      return 0;
    }
  }
  else {
    FUN_0056d420(param_2,*param_1 + iVar2,param_3);
    if (param_4 == 0) {
      param_1[1] = param_1[1] + param_3;
      param_1[3] = param_1[3] - param_3;
    }
  }
  return 0;
}

