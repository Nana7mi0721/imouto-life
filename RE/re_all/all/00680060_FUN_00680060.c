
void FUN_00680060(int param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x16bc);
  if (iVar2 < 0xc) {
    *(ushort *)(param_1 + 0x16b8) =
         *(ushort *)(param_1 + 0x16b8) | (ushort)(param_2 + -0x101 << ((byte)iVar2 & 0x1f));
    *(int *)(param_1 + 0x16bc) = iVar2 + 5;
  }
  else {
    *(ushort *)(param_1 + 0x16b8) =
         *(ushort *)(param_1 + 0x16b8) | (ushort)(param_2 + -0x101 << ((byte)iVar2 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16b8);
    iVar2 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar2;
    *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
    iVar2 = *(int *)(param_1 + 0x16bc);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x16bc) = iVar2 + -0xb;
    *(ushort *)(param_1 + 0x16b8) = (ushort)(param_2 + -0x101) >> (0x10U - (char)iVar2 & 0x1f);
  }
  iVar2 = *(int *)(param_1 + 0x16bc);
  if (iVar2 < 0xc) {
    *(ushort *)(param_1 + 0x16b8) =
         *(ushort *)(param_1 + 0x16b8) | (ushort)(param_3 + -1 << ((byte)iVar2 & 0x1f));
    *(int *)(param_1 + 0x16bc) = iVar2 + 5;
  }
  else {
    *(ushort *)(param_1 + 0x16b8) =
         *(ushort *)(param_1 + 0x16b8) | (ushort)(param_3 + -1 << ((byte)iVar2 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16b8);
    iVar2 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar2;
    *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
    iVar2 = *(int *)(param_1 + 0x16bc);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x16bc) = iVar2 + -0xb;
    *(ushort *)(param_1 + 0x16b8) = (ushort)(param_3 + -1) >> (0x10U - (char)iVar2 & 0x1f);
  }
  iVar3 = *(int *)(param_1 + 0x16bc);
  iVar2 = param_4 + -4;
  if (iVar3 < 0xd) {
    *(ushort *)(param_1 + 0x16b8) =
         *(ushort *)(param_1 + 0x16b8) | (ushort)(iVar2 << ((byte)iVar3 & 0x1f));
    *(int *)(param_1 + 0x16bc) = iVar3 + 4;
  }
  else {
    *(ushort *)(param_1 + 0x16b8) =
         *(ushort *)(param_1 + 0x16b8) | (ushort)(iVar2 << ((byte)iVar3 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16b8);
    iVar3 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
    iVar3 = *(int *)(param_1 + 0x16bc);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x16bc) = iVar3 + -0xc;
    *(ushort *)(param_1 + 0x16b8) = (ushort)iVar2 >> (0x10U - (char)iVar3 & 0x1f);
  }
  iVar2 = 0;
  if (0 < param_4) {
    do {
      iVar3 = *(int *)(param_1 + 0x16bc);
      if (iVar3 < 0xe) {
        *(ushort *)(param_1 + 0x16b8) =
             *(ushort *)(param_1 + 0x16b8) |
             *(short *)(param_1 + 0xa7e + (uint)(byte)(&DAT_00821d58)[iVar2] * 4) <<
             ((byte)iVar3 & 0x1f);
        *(int *)(param_1 + 0x16bc) = iVar3 + 3;
      }
      else {
        uVar1 = *(ushort *)(param_1 + 0xa7e + (uint)(byte)(&DAT_00821d58)[iVar2] * 4);
        *(ushort *)(param_1 + 0x16b8) =
             *(ushort *)(param_1 + 0x16b8) | uVar1 << ((byte)iVar3 & 0x1f);
        *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
             *(undefined1 *)(param_1 + 0x16b8);
        iVar3 = *(int *)(param_1 + 0x14) + 1;
        *(int *)(param_1 + 0x14) = iVar3;
        *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16b9);
        iVar3 = *(int *)(param_1 + 0x16bc);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        *(int *)(param_1 + 0x16bc) = iVar3 + -0xd;
        *(ushort *)(param_1 + 0x16b8) = uVar1 >> (0x10U - (char)iVar3 & 0x1f);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_4);
  }
  FUN_006802d0(param_1,param_1 + 0x94,param_2 + -1);
  FUN_006802d0(param_1,param_1 + 0x988,param_3 + -1);
  return;
}

