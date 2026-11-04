
undefined4 FUN_0057e250(int param_1)

{
  int iVar1;
  
  if (DAT_00a83c5c - 1U < 2) {
    iVar1 = (**(code **)(*DAT_00aa4250 + 0x38))(DAT_00aa4250,*(undefined4 *)(param_1 + 0x48),0);
    if (*(int *)(param_1 + 0x34) == 0) {
      if ((iVar1 != 1) == 1) {
        *(undefined4 *)(param_1 + 0x34) = 1;
        return 0;
      }
    }
    else {
      *(uint *)(param_1 + 0x30) = (uint)(iVar1 != 1);
    }
  }
  return 0;
}

