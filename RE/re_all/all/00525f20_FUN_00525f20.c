
undefined4 FUN_00525f20(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 local_6c [48];
  undefined4 local_3c;
  int local_38;
  
  if ((param_3 == 0) || (DAT_00a37d78 != 0)) {
    FUN_005193b0(local_6c);
    local_3c = 1;
    local_38 = param_3;
    uVar1 = FUN_0052eb20(0);
    uVar1 = FUN_005243b0(local_6c,param_1,param_2,0,0,0,uVar1);
    return uVar1;
  }
  return 0xffffffff;
}

