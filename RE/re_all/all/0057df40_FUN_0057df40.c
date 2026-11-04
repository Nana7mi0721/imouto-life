
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0057df40(void)

{
  if (DAT_00a828d8 != 0) {
    DeleteFileW(&DAT_00a828d8);
  }
  if (DAT_00a83c5c == 0) {
    _DAT_00a83c50 = 0xffffffff;
  }
  else if (DAT_00a83c5c - 1U < 2) {
    if (DAT_00aa4250 != (int *)0x0) {
      (**(code **)(*DAT_00aa4250 + 0x14))(DAT_00aa4250,0,0,0,0);
      (**(code **)(*DAT_00aa4250 + 0x98))(DAT_00aa4250);
      (**(code **)(*DAT_00aa4250 + 8))(DAT_00aa4250);
      DAT_00aa4250 = (int *)0x0;
    }
    if (DAT_00aa424c != (int *)0x0) {
      (**(code **)(*DAT_00aa424c + 8))(DAT_00aa424c);
      DAT_00aa424c = (int *)0x0;
    }
  }
  if (DAT_00aa4fa0 == 0) {
    if (DAT_00aa4f98 != (int *)0x0) {
      (**(code **)(*DAT_00aa4f98 + 0x48))(DAT_00aa4f98);
      (**(code **)(*DAT_00aa4f98 + 8))(DAT_00aa4f98);
      DAT_00aa4f98 = (int *)0x0;
    }
    if (DAT_00aa4f9c != (int *)0x0) {
      (**(code **)(*DAT_00aa4f9c + 0x48))(DAT_00aa4f9c);
      (**(code **)(*DAT_00aa4f9c + 8))(DAT_00aa4f9c);
      DAT_00aa4f9c = (int *)0x0;
    }
    if ((int *)0x1 < DAT_00aa4270) {
      (**(code **)(*DAT_00aa4270 + 8))(DAT_00aa4270);
    }
    DAT_00aa4270 = (int *)0x0;
    FUN_0056bb10(&PTR_LAB_007d9764);
    return 0;
  }
  if (DAT_00aa4f1c != (int *)0x0) {
    (**(code **)(*DAT_00aa4f1c + 0x48))(DAT_00aa4f1c);
    DAT_00aa4f1c = (int *)0x0;
  }
  if (DAT_00aa4f20 != (int *)0x0) {
    (**(code **)(*DAT_00aa4f20 + 0x48))(DAT_00aa4f20);
    DAT_00aa4f20 = (int *)0x0;
  }
  if (DAT_00aa4270 != (int *)0x0) {
    (**(code **)(*DAT_00aa4270 + 8))(DAT_00aa4270);
    DAT_00aa4270 = (int *)0x0;
  }
  if (DAT_00aa4254 != (HMODULE)0x0) {
    FreeLibrary(DAT_00aa4254);
    DAT_00aa4254 = (HMODULE)0x0;
    DAT_00aa4258 = 0;
    _DAT_00aa425c = 0;
    DAT_00aa4260 = 0;
    DAT_00aa4268 = 0;
    DAT_00aa426c = 0;
  }
  if (DAT_00aa4264 != (HMODULE)0x0) {
    FreeLibrary(DAT_00aa4264);
    DAT_00aa4264 = (HMODULE)0x0;
    DAT_00aa4268 = 0;
    DAT_00aa426c = 0;
  }
  return 0;
}

