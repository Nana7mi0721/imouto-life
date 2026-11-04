
void FUN_00678680(int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  char local_8 [2];
  char local_6 [2];
  char local_4 [4];
  
  if (param_5 == 3) {
    if ((param_4 < 1) || ((int)(uint)*(ushort *)(param_1 + 0x148) < param_4)) {
      FUN_006689d0(param_1,s_Invalid_number_of_transparent_co_00a0d6f4);
      return;
    }
    FUN_00677430(param_1,0x74524e53,param_2,param_4);
    return;
  }
  if (param_5 == 0) {
    if ((int)(uint)*(ushort *)(param_3 + 8) < 1 << (*(byte *)(param_1 + 0x158) & 0x1f)) {
      FUN_00677270(local_8,(uint)*(ushort *)(param_3 + 8));
      FUN_00677430(param_1,0x74524e53,local_8,2);
      return;
    }
    FUN_006689d0(param_1,s_Ignoring_attempt_to_write_tRNS_c_00a0d6b4);
    return;
  }
  if (param_5 != 2) {
    FUN_006689d0(param_1,s_Can_t_write_tRNS_with_an_alpha_c_00a0d64c);
    return;
  }
  FUN_00677270(local_8,*(undefined2 *)(param_3 + 2));
  FUN_00677270(local_6,*(undefined2 *)(param_3 + 4));
  FUN_00677270(local_4,*(undefined2 *)(param_3 + 6));
  if ((*(char *)(param_1 + 0x158) == '\b') &&
     ((local_4[0] != '\0' || local_6[0] != '\0') || local_8[0] != '\0')) {
    FUN_006689d0(param_1,s_Ignoring_attempt_to_write_16_bit_00a0d674);
    return;
  }
  FUN_00677430(param_1,0x74524e53,local_8,6);
  return;
}

