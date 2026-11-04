
void FUN_00688000(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  iVar1 = *(int *)(param_1 + 0x1a0);
  if (*(int *)(param_1 + 0x130) < 2) {
    if (*(uint *)(param_1 + 0x80) < *(int *)(param_1 + 0x128) - 1U) {
      *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(*(int *)(param_1 + 0x134) + 0xc);
      *(undefined4 *)(iVar1 + 0x14) = 0;
      *(undefined4 *)(iVar1 + 0x18) = 0;
      return;
    }
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x134) + 0x4c);
  }
  *(undefined4 *)(iVar1 + 0x1c) = uVar2;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  return;
}

