
void FUN_00668bc0(int param_1,undefined4 param_2,int param_3)

{
  if ((*(uint *)(param_1 + 0x74) & 0x8000) == 0) {
    if (param_3 < 1) {
      FUN_006689d0(param_1,param_2);
      return;
    }
    FUN_00668a00(param_1,param_2);
    return;
  }
  if (param_3 < 2) {
    FUN_00668b30(param_1,param_2);
    return;
  }
  FUN_00668b90(param_1,param_2);
  return;
}

