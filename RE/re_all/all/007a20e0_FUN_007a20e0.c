
void FUN_007a20e0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = (param_4 - param_3) * *(int *)(param_1 + 0x24);
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) - iVar1;
  if (param_2 == 0) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) - iVar1;
    FUN_007a2000(param_1);
    return;
  }
  *(int *)(param_1 + 0x1c) = (param_3 - param_2) * *(int *)(param_1 + 0x24);
  FUN_007a2000(param_1);
  return;
}

