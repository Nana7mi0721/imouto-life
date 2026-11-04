
undefined4 FUN_004dc880(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 extraout_var;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined4 local_8;
  
  iVar1 = FUN_004d2d60();
  uVar3 = extraout_var;
  if (iVar1 == 0) {
    local_8 = 0;
  }
  else {
    uVar2 = FUN_004ce060(local_c);
    local_8 = FUN_004e94e0(uVar2);
  }
  FUN_004e6840(param_2,1,param_3,local_8,uVar3);
  uVar3 = param_1;
  uVar2 = local_8;
  FUN_004ce060(local_10);
  FUN_004df310(uVar3,uVar2);
  return param_1;
}

