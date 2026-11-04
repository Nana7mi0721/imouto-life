
int FUN_005bac90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_005ba900(param_1,param_4);
  if (-1 < iVar1) {
    iVar1 = FUN_005baa30(param_2,param_4);
    if (-1 < iVar1) {
      iVar1 = FUN_005bab60(param_3,param_4);
      return (-1 < iVar1) - 1;
    }
  }
  return -1;
}

