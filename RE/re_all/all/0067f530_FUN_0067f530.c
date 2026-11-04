
void FUN_0067f530(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x16bc);
  if (iVar1 < 0xe) {
    *(ushort *)(param_1 + 0x16b8) =
         *(ushort *)(param_1 + 0x16b8) | (ushort)(param_4 << ((byte)iVar1 & 0x1f));
    *(int *)(param_1 + 0x16bc) = iVar1 + 3;
  }
  else {
    *(ushort *)(param_1 + 0x16b8) =
         *(ushort *)(param_1 + 0x16b8) | (ushort)(param_4 << ((byte)iVar1 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16b8);
    iVar1 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar1;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar1) = *(undefined1 *)(param_1 + 0x16b9);
    iVar1 = *(int *)(param_1 + 0x16bc);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x16bc) = iVar1 + -0xd;
    *(ushort *)(param_1 + 0x16b8) = (ushort)param_4 >> (0x10U - (char)iVar1 & 0x1f);
  }
  FUN_00680e30(param_1,param_2,param_3,1);
  return;
}

