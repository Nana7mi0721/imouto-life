
undefined4 FUN_00551a00(int *param_1,int *param_2)

{
  int iVar1;
  
  if (*param_1 == 0) {
    return 0xffffffff;
  }
  if ((DAT_00a83c64 == 0) && (iVar1 = FUN_0057ea00(param_1,param_2), iVar1 != 2)) {
    if (iVar1 < 0) {
      return 0xffffffff;
    }
    return 0;
  }
  iVar1 = param_1[10];
  if (iVar1 < 0) {
    iVar1 = param_1[0xd];
  }
  *param_2 = iVar1;
  return 0;
}

