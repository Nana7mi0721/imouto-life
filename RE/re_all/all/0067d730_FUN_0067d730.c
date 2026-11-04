
void FUN_0067d730(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  FUN_0067f5d0(iVar1);
  uVar2 = *(uint *)(iVar1 + 0x14);
  if (*(uint *)(param_1 + 0x10) < *(uint *)(iVar1 + 0x14)) {
    uVar2 = *(uint *)(param_1 + 0x10);
  }
  if (uVar2 != 0) {
    puVar5 = *(undefined4 **)(iVar1 + 0x10);
    puVar6 = *(undefined4 **)(param_1 + 0xc);
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + uVar2;
    *(uint *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + uVar2;
    *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar2;
    *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - uVar2;
    iVar4 = *(int *)(iVar1 + 0x14) - uVar2;
    *(int *)(iVar1 + 0x14) = iVar4;
    if (iVar4 == 0) {
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 8);
    }
  }
  return;
}

