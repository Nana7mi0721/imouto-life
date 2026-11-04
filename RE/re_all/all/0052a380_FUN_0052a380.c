
undefined4
FUN_0052a380(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            ,int param_6,undefined4 param_7,undefined4 param_8,int param_9,int param_10)

{
  undefined4 uVar1;
  
  if ((param_5 < 1) || (param_6 < 1)) {
    return 0xffffffff;
  }
  uVar1 = FUN_0052a120(param_3,param_4,param_5,param_6,param_7);
  if ((param_9 == 0) && (param_10 == 0)) {
    FUN_0051ecb0(param_1,param_2,uVar1,param_8);
    FUN_00580b80(uVar1);
    return 0;
  }
  FUN_005207b0(param_1,param_2,uVar1,param_8,param_9,param_10);
  FUN_00580b80(uVar1);
  return 0;
}

