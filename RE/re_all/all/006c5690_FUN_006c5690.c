
void FUN_006c5690(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  
  if ((DAT_00f488dc == 0) || ((MXCSR & 0x1f80) != 0x1f80 || (in_FPUControlWord & 0x7f) != 0x7f)) {
    FUN_00507298((double)in_ST0);
    FUN_006c56e8();
    return;
  }
  FUN_006c76f0();
  return;
}

