
undefined4 FUN_005dbd30(void)

{
  if (DAT_00f3a10c != (HMODULE)0x0) {
    FreeLibrary(DAT_00f3a10c);
    DAT_00f3a10c = (HMODULE)0x0;
    DAT_00f3a114 = 0;
    DAT_00f3a110 = 0;
    DAT_00f3a118 = 0;
    DAT_00f3a11c = 0;
    DAT_00f3a120 = 0;
    DAT_00f3a124 = 0;
    DAT_00f3a128 = 0;
    DAT_00f3a12c = 0;
  }
  return 0;
}

