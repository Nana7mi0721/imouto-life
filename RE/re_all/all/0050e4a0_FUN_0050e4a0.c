
void FUN_0050e4a0(void)

{
  bool bVar1;
  
  bVar1 = false;
  FUN_0056da60(&DAT_00a37a50,"..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxWindow.cpp",0x6df);
  if (DAT_00a2fa3c == 1) {
    DAT_00a2fa40 = 0;
    DAT_00a2fa44 = 0xffffffff;
    if (0 < DAT_00a37a4c) {
      bVar1 = true;
    }
  }
  DAT_00a2fa3c = DAT_00a2fa3c + -1;
  FUN_0056dac0(&DAT_00a37a50);
  if (bVar1) {
    SetEvent(DAT_00a2fa4c);
    Sleep(0);
  }
  return;
}

