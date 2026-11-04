
undefined4
FUN_00651e50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00652630(param_1,1);
  if (iVar1 != 0) {
    iVar1 = FUN_00651410(param_1,param_3,param_4,param_5,param_6);
    if (iVar1 != 0) {
      uVar2 = FUN_00651320(param_1,param_3,param_4,param_5,param_6,param_2,0xffffffff);
      uVar2 = FUN_00651ec0(param_1,uVar2);
      return uVar2;
    }
  }
  return 0xffffffff;
}

