
int FUN_006a96d0(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1[0x16] != 1) {
    return -0x83;
  }
  param_1[0x16] = 2;
  if (param_1[1] == 0) {
    param_1[0x16] = 3;
    return 0;
  }
  iVar1 = FUN_006a9720(param_1);
  if (iVar1 != 0) {
    *param_1 = 0;
    FUN_006a8f20(param_1);
  }
  return iVar1;
}

