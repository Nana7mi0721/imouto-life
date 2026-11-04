
void FUN_00672040(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    if ((*(ushort *)(param_2 + 0x14) != 0) && (*(ushort *)(param_2 + 0x14) < 0x101)) {
      FUN_00669290(param_1,param_2,8,0);
      iVar1 = FUN_0066cb30(param_1,0x200);
      *(int *)(param_2 + 0xcc) = iVar1;
      if (iVar1 == 0) {
        FUN_006687b0(param_1,s_Insufficient_memory_for_hIST_chu_00a0ca20);
        return;
      }
      iVar1 = 0;
      *(uint *)(param_2 + 0xe8) = *(uint *)(param_2 + 0xe8) | 8;
      if (*(short *)(param_2 + 0x14) != 0) {
        do {
          *(undefined2 *)(*(int *)(param_2 + 0xcc) + iVar1 * 2) =
               *(undefined2 *)(param_3 + iVar1 * 2);
          iVar1 = iVar1 + 1;
        } while (iVar1 < (int)(uint)*(ushort *)(param_2 + 0x14));
      }
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x40;
      return;
    }
    FUN_006687b0(param_1,s_Invalid_palette_size__hIST_alloc_00a0c9f0);
  }
  return;
}

