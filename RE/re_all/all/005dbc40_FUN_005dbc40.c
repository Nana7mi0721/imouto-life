
undefined4 FUN_005dbc40(void)

{
  if (DAT_00f3a10c != (HMODULE)0x0) {
    return 0;
  }
  DAT_00f3a10c = LoadLibraryA("msacm32.dll");
  if ((((((DAT_00f3a10c == (HMODULE)0x0) ||
         (DAT_00f3a114 = GetProcAddress(DAT_00f3a10c,"acmFormatSuggest"),
         DAT_00f3a114 == (FARPROC)0x0)) ||
        (DAT_00f3a110 = GetProcAddress(DAT_00f3a10c,"acmStreamOpen"), DAT_00f3a110 == (FARPROC)0x0))
       || ((DAT_00f3a118 = GetProcAddress(DAT_00f3a10c,"acmStreamClose"),
           DAT_00f3a118 == (FARPROC)0x0 ||
           (DAT_00f3a11c = GetProcAddress(DAT_00f3a10c,"acmMetrics"), DAT_00f3a11c == (FARPROC)0x0))
          )) || ((DAT_00f3a120 = GetProcAddress(DAT_00f3a10c,"acmStreamPrepareHeader"),
                 DAT_00f3a120 == (FARPROC)0x0 ||
                 ((DAT_00f3a124 = GetProcAddress(DAT_00f3a10c,"acmStreamConvert"),
                  DAT_00f3a124 == (FARPROC)0x0 ||
                  (DAT_00f3a128 = GetProcAddress(DAT_00f3a10c,"acmStreamUnprepareHeader"),
                  DAT_00f3a128 == (FARPROC)0x0)))))) ||
     (DAT_00f3a12c = GetProcAddress(DAT_00f3a10c,"acmStreamSize"), DAT_00f3a12c == (FARPROC)0x0)) {
    return 0xffffffff;
  }
  return 0;
}

