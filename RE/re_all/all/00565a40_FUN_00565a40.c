
undefined4 FUN_00565a40(void)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = &DAT_00aa84b8;
  uVar1 = 0;
  do {
    if (*piVar2 == 1) {
      FUN_00564510((piVar2[1] | 0x2400U) << 0x10 | uVar1);
    }
    uVar1 = uVar1 + 1;
    piVar2 = piVar2 + 0x17;
  } while ((int)uVar1 < 0x100);
  if (DAT_00aa7020 != 0) {
    FUN_0056e1d0(DAT_00aa7020);
    DAT_00aa7020 = 0;
  }
  DAT_00aa84b0 = 0xffffffff;
  return 0;
}

