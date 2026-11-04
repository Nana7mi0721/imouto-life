
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0055e710(void)

{
  int iVar1;
  
  if (DAT_00a834f0 != 0) {
    iVar1 = FUN_0057def0();
    if (-1 < iVar1) {
      FUN_0055c820();
      FUN_00551d60();
      if (DAT_00a834f0 != 0) {
        FUN_00580eb0(3,&LAB_00550c50);
        _DAT_00a83c50 = 0xffffffff;
        if (DAT_00a834f0 != 0) {
          FUN_00580eb0(4,&LAB_005520d0);
          if (DAT_00a834f0 != 0) {
            FUN_00580eb0(4,&LAB_005520e0);
          }
        }
      }
      FUN_00580eb0(5,0);
      FUN_00581030(3);
      FUN_00581030(4);
      FUN_00581030(5);
      FUN_0056da50(&DAT_00a83570);
      FUN_0056da50(&DAT_00a83a30);
      FUN_0056da50(&DAT_00a837b0);
      iVar1 = FUN_0057df40();
      if (-1 < iVar1) {
        DAT_00a834f0 = 0;
        return 0;
      }
    }
  }
  return 0xffffffff;
}

