
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00524b70(void)

{
  double dVar1;
  
  dVar1 = 1.0;
  if (DAT_00a384e0 != 2) {
    dVar1 = ((double)DAT_00a381b8 / (double)DAT_00a381b4) * _DAT_00a384f8;
  }
  if (DAT_00a384e0 == 0) {
    FUN_00585530(&DAT_00a38510,_DAT_00a38500,_DAT_00a384e8,_DAT_00a384f0,dVar1);
    FUN_00524ad0();
    return;
  }
  if (DAT_00a384e0 == 1) {
    FUN_00585650(&DAT_00a38510,_DAT_00a38508,_DAT_00a384e8,_DAT_00a384f0,dVar1);
    FUN_00524ad0();
    return;
  }
  FUN_00524ad0();
  return;
}

