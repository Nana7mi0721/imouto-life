
int FUN_00562830(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_2 <= param_1) {
    return -1;
  }
  iVar1 = FUN_00562630(param_1,param_3,param_4);
  if (iVar1 < 0) {
    return -1;
  }
  iVar1 = FUN_00562730(param_2,param_3,param_4);
  return (-1 < iVar1) - 1;
}

