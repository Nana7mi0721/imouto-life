
void FUN_007a2000(int param_1)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  
  puVar2 = *(undefined **)(param_1 + 0x1c);
  if (puVar2 < &UNK_00800001) {
    do {
      iVar1 = *(int *)(param_1 + 0x28);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 8;
      *(int *)(param_1 + 0x1c) = (int)puVar2 << 8;
      uVar3 = FUN_007a1fd0(param_1);
      *(uint *)(param_1 + 0x28) = uVar3;
      puVar2 = *(undefined **)(param_1 + 0x1c);
      *(uint *)(param_1 + 0x20) =
           (~((int)(iVar1 << 8 | uVar3) >> 1) & 0xffU) + *(int *)(param_1 + 0x20) * 0x100 &
           0x7fffffff;
    } while (puVar2 < &UNK_00800001);
  }
  return;
}

