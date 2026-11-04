
undefined4 FUN_00514e10(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_1[2] < *param_1) {
    param_1[2] = *param_1;
  }
  if (param_1[3] < param_1[1]) {
    param_1[3] = param_1[1];
  }
  iVar1 = param_2[3];
  if ((iVar1 < param_1[3]) || (iVar1 = param_2[1], param_1[3] < iVar1)) {
    param_1[3] = iVar1;
  }
  iVar1 = param_2[3];
  if ((iVar1 < param_1[1]) || (iVar1 = param_2[1], param_1[1] < iVar1)) {
    param_1[1] = iVar1;
  }
  iVar1 = param_2[2];
  if ((iVar1 < param_1[2]) || (iVar1 = *param_2, param_1[2] < iVar1)) {
    param_1[2] = iVar1;
  }
  if (param_2[2] < *param_1) {
    *param_1 = param_2[2];
    return 0;
  }
  if (*param_1 < *param_2) {
    *param_1 = *param_2;
  }
  return 0;
}

