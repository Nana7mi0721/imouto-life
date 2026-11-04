
void FUN_0064c3d0(int param_1)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x28);
  iVar3 = 1 << (*(byte *)(param_1 + 0x18) & 0x1f);
  if (-1 < iVar3 + -1) {
    puVar1 = (ushort *)(iVar4 + (iVar3 + -1) * 2);
    iVar2 = *(int *)(param_1 + 0x24) - iVar4;
    iVar4 = *(int *)(param_1 + 0x2c) - iVar4;
    do {
      *(ushort *)(iVar2 + (int)puVar1) = (ushort)*(byte *)(iVar2 + 1 + (int)puVar1);
      *puVar1 = (ushort)*(byte *)((int)puVar1 + 1);
      *(ushort *)(iVar4 + (int)puVar1) = (ushort)*(byte *)(iVar4 + 1 + (int)puVar1);
      puVar1 = puVar1 + -1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

