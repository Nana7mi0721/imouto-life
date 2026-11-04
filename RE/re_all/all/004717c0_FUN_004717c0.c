
undefined4 __thiscall FUN_004717c0(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004d00e0(param_1);
  if (param_2 < iVar1) {
    FUN_004d0120(param_2);
    iVar1 = FUN_004cfc90();
    if (0 < iVar1) {
      FUN_004d0120(param_2);
      uVar2 = FUN_004cfc90();
      return uVar2;
    }
  }
  return 0xffffffff;
}

