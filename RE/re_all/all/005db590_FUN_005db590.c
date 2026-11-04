
undefined4
FUN_005db590(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  
  if (DAT_00ca3a2c == 0) {
    *(undefined4 *)(param_1 + 0x640) = 0;
    iVar1 = FUN_005dadd0(param_3,param_4,param_5,param_7,param_8);
    if (iVar1 != -1) {
      return 0;
    }
  }
  *(undefined4 *)(param_1 + 0x640) = 0;
  iVar1 = FUN_005d9dc0(param_1,param_3,param_4,param_5,param_6,param_7,param_8);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  return 0;
}

