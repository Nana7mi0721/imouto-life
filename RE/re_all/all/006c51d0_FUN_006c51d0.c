
void FUN_006c51d0(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  float10 in_ST1;
  
  if ((DAT_00f488dc == 0) || ((MXCSR & 0x1f80) != 0x1f80 || (in_FPUControlWord & 0x7f) != 0x7f)) {
    FUN_006c522d((double)in_ST1,(double)in_ST0);
    return;
  }
  FUN_006c6500();
  return;
}

