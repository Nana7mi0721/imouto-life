
void FUN_00668960(int param_1,undefined4 param_2)

{
  if ((*(uint *)(param_1 + 0x78) & 0x100000) == 0) {
    if (((*(uint *)(param_1 + 0x74) & 0x8000) == 0) || (*(int *)(param_1 + 0x11c) == 0)) {
      FUN_00668620(param_1,param_2);
      return;
    }
    FUN_00668a30(param_1,param_2);
    return;
  }
  if (((*(uint *)(param_1 + 0x74) & 0x8000) == 0) || (*(int *)(param_1 + 0x11c) == 0)) {
    FUN_006687b0(param_1,param_2);
    return;
  }
  FUN_00668b30(param_1,param_2);
  return;
}

