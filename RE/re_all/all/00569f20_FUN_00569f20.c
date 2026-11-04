
undefined4 FUN_00569f20(void)

{
  if (DAT_00a828ac != (int *)0x0) {
    if (DAT_00a828ac == (int *)0xffffffff) {
      FUN_0056bb10(&DAT_007d7754);
      DAT_00a828ac = (int *)0x0;
    }
    else {
      FUN_0056bb10(&PTR_LAB_007d7778);
      FUN_0054f400();
      if (DAT_00a828b4 != (int *)0x0) {
        (**(code **)(*DAT_00a828b4 + 0x30))(DAT_00a828b4,0);
        (**(code **)(*DAT_00a828b4 + 0x20))(DAT_00a828b4);
        (**(code **)(*DAT_00a828b4 + 8))(DAT_00a828b4);
        DAT_00a828b4 = (int *)0x0;
        CloseHandle(DAT_00a828b8);
      }
      if (DAT_00a828b0 != (int *)0x0) {
        (**(code **)(*DAT_00a828b0 + 0x20))(DAT_00a828b0);
        (**(code **)(*DAT_00a828b0 + 8))(DAT_00a828b0);
        DAT_00a828b0 = (int *)0x0;
      }
      if (DAT_00a828ac != (int *)0x0) {
        (**(code **)(*DAT_00a828ac + 8))(DAT_00a828ac);
        DAT_00a828ac = (int *)0x0;
      }
      if (DAT_00a82890 != (HMODULE)0x0) {
        FreeLibrary(DAT_00a82890);
        DAT_00a82890 = (HMODULE)0x0;
        DAT_00a82894 = 0;
        DAT_00a82898 = 0;
        return 0;
      }
    }
  }
  return 0;
}

