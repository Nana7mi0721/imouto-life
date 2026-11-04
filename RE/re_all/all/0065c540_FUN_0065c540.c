
undefined4 FUN_0065c540(undefined4 param_1,int *param_2,int param_3,undefined4 param_4,uint param_5)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    *param_2 = *param_2 + 1;
    return 1;
  }
  if (param_5 < 0x10000) {
    uVar1 = FUN_0065cc10();
    return uVar1;
  }
  uVar1 = FUN_0065cd00(param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}

