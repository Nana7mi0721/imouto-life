
void FUN_006c545c(void)

{
  ushort in_FPUControlWord;
  
  if ((DAT_00f488dc == 0) || ((MXCSR & 0x1f80) != 0x1f80 || (in_FPUControlWord & 0x7f) != 0x7f)) {
    __cintrindisp1();
    return;
  }
  FUN_006c7430();
  return;
}

