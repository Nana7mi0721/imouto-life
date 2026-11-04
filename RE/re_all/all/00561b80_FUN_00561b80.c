
undefined4 FUN_00561b80(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00561290(*(undefined4 *)(param_1 + 4));
  if (iVar1 == 1) {
    FUN_0055f6b0(*(undefined4 *)(param_1 + 4));
  }
  iVar1 = FUN_0057e0f0(param_1);
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    FUN_0056d380(*(int *)(param_1 + 0x3c),0,*(undefined4 *)(param_1 + 0x40));
    FUN_0056e1d0(*(undefined4 *)(param_1 + 0x3c));
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return 0;
}

