
void FUN_006787e0(int param_1,byte *param_2,uint param_3)

{
  undefined4 uVar1;
  byte local_8 [2];
  char local_6 [2];
  char local_4 [4];
  
  if (param_3 == 3) {
    if (((*(ushort *)(param_1 + 0x148) != 0) || ((*(byte *)(param_1 + 0x268) & 1) == 0)) &&
       (*(ushort *)(param_1 + 0x148) <= (ushort)*param_2)) {
      FUN_006687b0(param_1,s_Invalid_background_palette_index_00a0d7a4);
      return;
    }
    local_8[0] = *param_2;
    uVar1 = 1;
  }
  else {
    if ((param_3 & 2) == 0) {
      if ((int)(uint)*(ushort *)(param_2 + 8) < 1 << (*(byte *)(param_1 + 0x158) & 0x1f)) {
        FUN_00677270(local_8,(uint)*(ushort *)(param_2 + 8));
        FUN_00677430(param_1,0x624b4744,local_8,2);
        return;
      }
      FUN_006687b0(param_1,s_Ignoring_attempt_to_write_bKGD_c_00a0d724);
      return;
    }
    FUN_00677270(local_8,*(undefined2 *)(param_2 + 2));
    FUN_00677270(local_6,*(undefined2 *)(param_2 + 4));
    FUN_00677270(local_4,*(undefined2 *)(param_2 + 6));
    if ((*(char *)(param_1 + 0x158) == '\b') &&
       ((local_4[0] != '\0' || local_6[0] != '\0') || local_8[0] != 0)) {
      FUN_006687b0(param_1,s_Ignoring_attempt_to_write_16_bit_00a0d764);
      return;
    }
    uVar1 = 6;
  }
  FUN_00677430(param_1,0x624b4744,local_8,uVar1);
  return;
}

