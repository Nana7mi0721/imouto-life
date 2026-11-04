
uint FUN_0052d0f0(undefined4 param_1,uint param_2,uint param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_4[2];
  if (iVar1 == param_4[1]) {
    param_4[3] = 1;
    return 0;
  }
  uVar2 = param_4[1] - iVar1;
  if (uVar2 < param_2 * param_3) {
    param_3 = uVar2 / param_2;
  }
  if (param_3 != 0) {
    FUN_0056d420(param_1,*param_4 + iVar1,param_2 * param_3);
    param_4[2] = param_4[2] + param_2 * param_3;
    param_4[3] = 0;
    return param_3;
  }
  if (uVar2 != 0) {
    FUN_0056d420(param_1,*param_4 + iVar1,uVar2);
    param_4[2] = param_4[2] + uVar2;
  }
  param_4[3] = 0;
  return (uint)(uVar2 != 0);
}

