
uint FUN_00669a80(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 local_20 [32];
  
  uVar1 = FUN_00669c60(param_1,param_2);
  if (uVar1 == 0) {
    uVar1 = FUN_00669ad0(local_20,param_1);
    if (uVar1 == 0) {
      iVar2 = FUN_0066a040(param_2,local_20,5);
      uVar1 = (uint)(iVar2 == 0);
    }
  }
  return uVar1;
}

