
undefined4 FUN_005d21e0(void)

{
  undefined4 uVar1;
  
  FUN_0056bb10(&DAT_007ff5d8);
  DAT_00f3a05c = LoadLibraryW(L"dxgi.dll");
  if (DAT_00f3a05c == (HMODULE)0x0) {
    FreeLibrary(DAT_00f3a058);
    DAT_00f3a058 = (HMODULE)0x0;
    uVar1 = FUN_0056bb10("1YWe\n");
    return uVar1;
  }
  FUN_0056bb10(&DAT_007d4974);
  return 0;
}

