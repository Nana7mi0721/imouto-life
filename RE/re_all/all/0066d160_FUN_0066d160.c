
undefined4 FUN_0066d160(int param_1,int param_2)

{
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0x78) & 0x40) == 0) {
      if ((param_2 == 0) || ((*(byte *)(param_1 + 0x74) & 1) != 0)) {
        *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 0x4000;
        return 1;
      }
      FUN_00668a00(param_1,s_invalid_before_the_PNG_header_ha_00a0c670);
      return 0;
    }
    FUN_00668a00(param_1,s_invalid_after_png_start_read_ima_00a0c69c);
  }
  return 0;
}

