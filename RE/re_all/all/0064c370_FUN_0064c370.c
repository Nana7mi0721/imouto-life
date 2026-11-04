
undefined4 FUN_0064c370(int param_1)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  
  puVar3 = *(ushort **)(param_1 + 0x24);
  puVar4 = *(ushort **)(param_1 + 0x2c);
  puVar5 = *(ushort **)(param_1 + 0x28);
  iVar2 = 1 << (*(byte *)(param_1 + 0x18) & 0x1f);
  do {
    if (iVar2 < 1) {
      return 8;
    }
    iVar2 = iVar2 + -1;
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
  } while (((uVar1 < 0x100) && (uVar1 = *puVar5, puVar5 = puVar5 + 1, uVar1 < 0x100)) &&
          (uVar1 = *puVar4, puVar4 = puVar4 + 1, uVar1 < 0x100));
  return 0x10;
}

