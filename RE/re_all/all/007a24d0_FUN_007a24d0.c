
void FUN_007a24d0(int param_1,int param_2,byte param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = (undefined *)(*(uint *)(param_1 + 0x1c) >> (param_3 & 0x1f));
  puVar2 = (undefined *)(*(uint *)(param_1 + 0x1c) - (int)puVar1);
  if (param_2 != 0) {
    *(int *)(param_1 + 0x20) = (int)(puVar2 + *(int *)(param_1 + 0x20));
    puVar2 = puVar1;
  }
  *(undefined **)(param_1 + 0x1c) = puVar2;
  while (puVar2 < &UNK_00800001) {
    FUN_007a2420(param_1,*(uint *)(param_1 + 0x20) >> 0x17);
    puVar2 = (undefined *)(*(int *)(param_1 + 0x1c) * 0x100);
    *(uint *)(param_1 + 0x20) = (*(uint *)(param_1 + 0x20) & 0x7fffff) << 8;
    *(undefined **)(param_1 + 0x1c) = puVar2;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 8;
  }
  return;
}

