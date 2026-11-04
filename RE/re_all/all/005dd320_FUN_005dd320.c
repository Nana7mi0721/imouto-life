
undefined4 FUN_005dd320(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 3) {
    FUN_005dc790(param_1);
  }
  else if (iVar1 == 4) {
    if (*(int *)(param_1 + 0x4a) != 0) {
      FUN_0056e1d0(*(int *)(param_1 + 0x4a));
      *(undefined4 *)(param_1 + 0x4a) = 0;
      return 0;
    }
  }
  else if (iVar1 == 5) {
    uVar2 = FUN_005dced0(param_1);
    return uVar2;
  }
  return 0;
}

