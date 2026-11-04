
uint FUN_0054f8b0(int param_1)

{
  uint uVar1;
  
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
  return (uint)((byte)(&DAT_00a72a6c)[param_1] >> 7);
}

