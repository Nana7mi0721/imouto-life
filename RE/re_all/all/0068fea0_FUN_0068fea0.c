
void FUN_0068fea0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  iVar1 = *(int *)(param_1 + 0x184);
  if (*(int *)(param_1 + 0x114) < 2) {
    if (*(uint *)(iVar1 + 8) < *(int *)(param_1 + 0x110) - 1U) {
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(*(int *)(param_1 + 0x118) + 0xc);
      *(undefined4 *)(iVar1 + 0xc) = 0;
      *(undefined4 *)(iVar1 + 0x10) = 0;
      return;
    }
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x118) + 0x4c);
  }
  *(undefined4 *)(iVar1 + 0x14) = uVar2;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  return;
}

