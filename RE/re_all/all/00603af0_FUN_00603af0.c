
undefined4 FUN_00603af0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  param_1 = FUN_00603760();
  do {
    if (param_1 == 0) {
      return 1;
    }
    uVar1 = FUN_00603940(&param_1);
    iVar2 = FUN_00603a60(uVar1);
  } while (iVar2 != 0);
  return 0;
}

