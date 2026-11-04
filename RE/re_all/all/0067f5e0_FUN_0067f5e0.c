
void FUN_0067f5e0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x16bc);
  if (iVar3 < 0xe) {
    *(ushort *)(param_1 + 0x16b8) =
         *(ushort *)(param_1 + 0x16b8) | (ushort)(2 << ((byte)iVar3 & 0x1f));
    *(int *)(param_1 + 0x16bc) = iVar3 + 3;
  }
  else {
    *(ushort *)(param_1 + 0x16b8) =
         *(ushort *)(param_1 + 0x16b8) | (ushort)(2 << ((byte)iVar3 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16b8);
    iVar3 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar3) = *(undefined1 *)(param_1 + 0x16b9);
    iVar3 = *(int *)(param_1 + 0x16bc);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x16bc) = iVar3 + -0xd;
    *(ushort *)(param_1 + 0x16b8) = 2 >> (0x10U - (char)iVar3 & 0x1f);
  }
  uVar2 = DAT_0082216c;
  iVar3 = *(int *)(param_1 + 0x16bc);
  uVar1 = DAT_0082216c >> 0x10;
  if ((int)(0x10 - uVar1) < iVar3) {
    *(ushort *)(param_1 + 0x16b8) =
         *(ushort *)(param_1 + 0x16b8) | (ushort)((DAT_0082216c & 0xffff) << ((byte)iVar3 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16b8);
    iVar3 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar3) = *(undefined1 *)(param_1 + 0x16b9);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(ushort *)(param_1 + 0x16b8) =
         (ushort)uVar2 >> (0x10U - (char)*(int *)(param_1 + 0x16bc) & 0x1f);
    *(uint *)(param_1 + 0x16bc) = *(int *)(param_1 + 0x16bc) + -0x10 + uVar1;
    FUN_00680d20(param_1);
    return;
  }
  iVar4 = DAT_0082216c << ((byte)iVar3 & 0x1f);
  *(uint *)(param_1 + 0x16bc) = iVar3 + uVar1;
  *(ushort *)(param_1 + 0x16b8) = *(ushort *)(param_1 + 0x16b8) | (ushort)iVar4;
  FUN_00680d20(param_1);
  return;
}

