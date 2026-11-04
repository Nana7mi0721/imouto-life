
void FUN_007a2390(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  
  uVar1 = *(uint *)(param_1 + 0x1c);
  uVar2 = uVar1 / param_4;
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x1c) = uVar1 - (param_4 - param_3) * uVar2;
  }
  else {
    *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + (uVar1 - (param_4 - param_2) * uVar2);
    *(uint *)(param_1 + 0x1c) = (param_3 - param_2) * uVar2;
  }
  if (*(undefined **)(param_1 + 0x1c) < &UNK_00800001) {
    do {
      FUN_007a2420(param_1,*(uint *)(param_1 + 0x20) >> 0x17);
      *(uint *)(param_1 + 0x20) = (*(uint *)(param_1 + 0x20) & 0x7fffff) << 8;
      puVar3 = (undefined *)(*(int *)(param_1 + 0x1c) * 0x100);
      *(undefined **)(param_1 + 0x1c) = puVar3;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 8;
    } while (puVar3 < &UNK_00800001);
  }
  return;
}

