
void FUN_00401080(void)

{
  if (DAT_00a0f7ec != 0) {
    if (DAT_00a0f7ec != 0) {
      FUN_004016e0(1);
    }
    DAT_00a0f7ec = 0;
  }
  if (DAT_00a0f7f0 != (HMODULE)0x0) {
    FreeLibrary(DAT_00a0f7f0);
    DAT_00a0f7f0 = (HMODULE)0x0;
  }
  return;
}

