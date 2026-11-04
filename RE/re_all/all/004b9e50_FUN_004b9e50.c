
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b9e50(void)

{
  if (DAT_00a11800 != (HMODULE)0x0) {
    FreeLibrary(DAT_00a11800);
    DAT_00a11800 = (HMODULE)0x0;
    _DAT_00a117f8 = 0;
    _DAT_00a117fc = 0;
  }
  return 1;
}

