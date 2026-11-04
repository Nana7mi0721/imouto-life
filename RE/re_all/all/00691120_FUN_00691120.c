
undefined4 FUN_00691120(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x198);
  uVar2 = *(undefined4 *)(param_1 + 0x168);
  *(undefined4 *)(iVar1 + 0x70) = **(undefined4 **)(param_1 + 0x18);
  *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(*(int *)(param_1 + 0x18) + 4);
  if ((*(int *)(param_1 + 0xe0) != 0) && (*(int *)(iVar1 + 0x24) == 0)) {
    FUN_00690d50(iVar1,*(undefined4 *)(iVar1 + 0x28));
  }
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    do {
      FUN_00690be0(iVar1,(int)(*(short *)*param_2 >> ((byte)uVar2 & 0x1f)),1);
      iVar3 = iVar3 + 1;
      param_2 = param_2 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x130));
  }
  **(undefined4 **)(param_1 + 0x18) = *(undefined4 *)(iVar1 + 0x70);
  iVar3 = *(int *)(param_1 + 0x18);
  *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar1 + 0x74);
  if (*(int *)(param_1 + 0xe0) != 0) {
    iVar3 = *(int *)(iVar1 + 0x24);
    if (iVar3 == 0) {
      *(int *)(iVar1 + 0x24) = *(int *)(param_1 + 0xe0);
      *(uint *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + 1U & 7;
    }
    *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + -1;
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}

