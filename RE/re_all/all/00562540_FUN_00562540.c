
int FUN_00562540(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_2 <= param_1) {
    return -1;
  }
  iVar1 = FUN_005620a0(param_1,param_3,param_4);
  if (iVar1 < 0) {
    return -1;
  }
  iVar1 = FUN_005622f0(param_2,param_3,param_4);
  return (-1 < iVar1) - 1;
}

