
void FUN_006bc4b0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  
  *(undefined4 *)(param_1 + 0x20c) = 0;
  *(undefined4 *)(param_1 + 0x210) = 0;
  *(undefined4 *)(param_1 + 0x214) = 0;
  uVar4 = *(uint *)(param_1 + 0x240);
  iVar1 = *(int *)(param_1 + 0xf8);
  uVar3 = (int)uVar4 >> 0x1f;
  puVar5 = (undefined4 *)(param_1 + 0xec);
  puVar6 = (undefined4 *)(param_1 + 0xd328);
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar7 = *(int *)(param_1 + 8) + 0x20;
  iVar2 = (uVar4 ^ uVar3) - uVar3;
  *(int *)(param_1 + 0x22c) = iVar1;
  uVar4 = (int)*(uint *)(param_1 + 0x244) >> 0x1f;
  *(int *)(param_1 + 0x228) = iVar1;
  *(int *)(param_1 + 0x224) = iVar1;
  uVar4 = iVar7 * iVar2 + 0x10 +
          ((*(uint *)(param_1 + 0x244) ^ uVar4) - uVar4) *
          (iVar7 >> ((byte)(~*(uint *)(param_1 + 0x30) >> 1) & 1)) * 2;
  puVar5 = (undefined4 *)((iVar1 - (*(int *)(param_1 + 8) + 0xf) * iVar2) + -0x10);
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar5 = 0x80808080;
    puVar5 = puVar5 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar5 = 0x80;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  return;
}

