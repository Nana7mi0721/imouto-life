
void FUN_00544840(int param_1)

{
  int iVar1;
  
  if ((uint)*(byte *)(param_1 + 0xb) + (uint)*(byte *)(param_1 + 10) + (uint)*(byte *)(param_1 + 9)
      + (uint)*(byte *)(param_1 + 8) == (uint)*(byte *)(param_1 + 5)) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  if (*(byte *)(param_1 + 5) != 0) {
    iVar1 = 0;
    do {
      *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) * 2 | 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(uint)*(byte *)(param_1 + 5));
  }
  *(uint *)(param_1 + 0x20) =
       *(uint *)(param_1 + 0x20) &
       ~*(uint *)(param_1 + 0x1c) & ~*(uint *)(param_1 + 0x18) & ~*(uint *)(param_1 + 0x14) &
       ~*(uint *)(param_1 + 0x10);
  return;
}

