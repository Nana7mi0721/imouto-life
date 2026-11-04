
int FUN_00799ab0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00799a70(param_1,param_2);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar2 = FUN_00798510(param_1,param_3);
  iVar2 = iVar2 * iVar1;
  if (param_3 * 3 < iVar2 * 0x19) {
    iVar2 = -4;
  }
  return iVar2;
}

