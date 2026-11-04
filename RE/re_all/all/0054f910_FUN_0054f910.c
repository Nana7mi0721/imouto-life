
undefined4 FUN_0054f910(byte *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if (DAT_00a72a60 == 0) {
    uVar1 = FUN_0056a010();
    return uVar1;
  }
  if (DAT_00a828c8 != 1) {
    DAT_00a828c8 = 1;
    FUN_0056a240(1);
    DAT_00a828c8 = 0;
  }
  iVar2 = 0;
  do {
    *param_1 = (byte)(&DAT_00a72a6c)[iVar2] >> 7;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
  } while (iVar2 < 0x100);
  return 0;
}

