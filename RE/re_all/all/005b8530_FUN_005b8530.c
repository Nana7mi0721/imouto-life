
undefined4 FUN_005b8530(uint param_1)

{
  if (0xff < param_1) {
    return 0xffffffff;
  }
  if ((&DAT_00ee9bc0)[param_1 * 0x20] != 0) {
    FUN_005d1f20((&DAT_00ee9bc0)[param_1 * 0x20]);
    (&DAT_00ee9bc0)[param_1 * 0x20] = 0;
  }
  if ((&DAT_00ee9bc4)[param_1 * 0x20] != 0) {
    FUN_005d1f40((&DAT_00ee9bc4)[param_1 * 0x20]);
    (&DAT_00ee9bc4)[param_1 * 0x20] = 0;
  }
  if ((&DAT_00ee9b90)[param_1 * 0x20] != 0) {
    FUN_005d1ee0((&DAT_00ee9b90)[param_1 * 0x20]);
    (&DAT_00ee9b90)[param_1 * 0x20] = 0;
  }
  return 0;
}

