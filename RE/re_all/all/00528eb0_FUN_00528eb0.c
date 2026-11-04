
int FUN_00528eb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                undefined4 param_9,undefined4 param_10,int param_11)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_005809a0(1,param_11,0xffffffff);
  if (iVar1 != -1) {
    iVar2 = FUN_00527c20(iVar1,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                         param_9,param_10,param_11);
    if (param_11 != 0) {
      FUN_00580f70(iVar1);
    }
    if (-1 < iVar2) {
      return iVar1;
    }
    FUN_00580b80(iVar1);
  }
  return -1;
}

