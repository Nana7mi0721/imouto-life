
undefined4 FUN_004db620(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_18;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined4 local_8;
  
  iVar1 = FUN_004d0b50();
  if (iVar1 == 0) {
    local_18 = 0;
  }
  else {
    uVar2 = FUN_004ce060(local_c);
    local_18 = FUN_004e93b0(uVar2);
  }
  local_8 = local_18;
  FUN_004e4ce0(param_2,1,param_3);
  uVar2 = param_1;
  uVar3 = local_8;
  FUN_004ce060(local_10);
  FUN_004df1d0(uVar2,uVar3);
  return param_1;
}

