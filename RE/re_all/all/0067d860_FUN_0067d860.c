
void FUN_0067d860(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x2c) << 1;
  *(undefined2 *)(*(int *)(param_1 + 0x44) + -2 + *(int *)(param_1 + 0x4c) * 2) = 0;
  uVar4 = *(int *)(param_1 + 0x4c) * 2 - 2;
  puVar5 = *(undefined4 **)(param_1 + 0x44);
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  iVar2 = *(int *)(param_1 + 0x84) * 0xc;
  *(uint *)(param_1 + 0x80) = (uint)*(ushort *)(&DAT_00821a4a + iVar2);
  *(uint *)(param_1 + 0x8c) = (uint)*(ushort *)(&DAT_00821a48 + iVar2);
  *(uint *)(param_1 + 0x90) = (uint)*(ushort *)(&DAT_00821a4c + iVar2);
  uVar1 = *(ushort *)(&DAT_00821a4e + iVar2);
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x16b4) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(uint *)(param_1 + 0x7c) = (uint)uVar1;
  *(undefined4 *)(param_1 + 0x78) = 2;
  *(undefined4 *)(param_1 + 0x60) = 2;
  return;
}

