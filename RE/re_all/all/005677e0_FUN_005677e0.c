
undefined4 FUN_005677e0(void)

{
  LONG LVar1;
  DEVMODEA local_9c;
  
  FUN_0056bca0(&DAT_007d6d38,DAT_00a37e60,DAT_00a37e64,DAT_00a37e70);
  FUN_0056bfd0();
  FUN_00522420();
  if ((DAT_00a37e94 != 0x10) && (DAT_00a37e94 != 0x20)) {
    FUN_0056bb10("1YWeW0~0W0_0\n");
    FUN_0056bd30(0x1020003,&DAT_007d6ce0);
    FUN_0056bfe0();
    return 0xffffffff;
  }
  FUN_0056bb10(&DAT_007d6cbc);
  FUN_0056d380(&local_9c,0,0x9c);
  local_9c.dmSize = 0x9c;
  local_9c.dmBitsPerPel = DAT_00a37e70;
  local_9c.dmFields = 0x1c0000;
  if (DAT_00a37e74 != 0) {
    local_9c.dmDisplayFrequency = DAT_00a37e74;
    local_9c.dmFields = (DWORD)FUN_005c0000;
  }
  local_9c.dmPelsWidth = DAT_00a37e8c;
  local_9c.dmPelsHeight = DAT_00a37e90;
  LVar1 = ChangeDisplaySettingsA(&local_9c,4);
  if (LVar1 != 0) {
    local_9c.dmFields = local_9c.dmFields & 0xffbfffff;
    DAT_00a37e74 = 0;
    local_9c.dmDisplayFrequency = 0;
    LVar1 = ChangeDisplaySettingsA(&local_9c,0);
    if (LVar1 != 0) {
      FUN_0056bd30(0x1020004,&DAT_007d6c98);
      FUN_0056bfe0();
      return 0xffffffff;
    }
  }
  DAT_00aaf0d0 = 1;
  FUN_0056bb10(&DAT_007d6c88);
  DAT_00aaf100 = 10;
  return 0;
}

