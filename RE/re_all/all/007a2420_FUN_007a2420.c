
void FUN_007a2420(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  if (param_2 == 0xff) {
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    return;
  }
  if (-1 < *(int *)(param_1 + 0x28)) {
    uVar1 = FUN_007a24a0(param_1,*(int *)(param_1 + 0x28) + ((int)param_2 >> 8));
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | uVar1;
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    do {
      uVar1 = FUN_007a24a0(param_1,((int)param_2 >> 8) - 1U & 0xff);
      iVar2 = *(int *)(param_1 + 0x24) + -1;
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | uVar1;
      *(int *)(param_1 + 0x24) = iVar2;
    } while (iVar2 != 0);
  }
  *(uint *)(param_1 + 0x28) = param_2 & 0xff;
  return;
}

