
undefined4 FUN_005d1690(void)

{
  int iVar1;
  
  iVar1 = FUN_005d2270();
  if (-1 < iVar1) {
    iVar1 = FUN_005d21e0();
    if (-1 < iVar1) {
      iVar1 = FUN_005c13d0();
      if (iVar1 == 0) {
        iVar1 = FUN_005bcdf0();
        if (iVar1 == 0) {
          iVar1 = FUN_005c11f0();
          if (iVar1 == 0) {
            iVar1 = FUN_005cac90();
            if (iVar1 == 0) {
              iVar1 = FUN_005c2e90();
              if (iVar1 == 0) {
                iVar1 = FUN_005c30c0();
                if (iVar1 == 0) {
                  FUN_005b6a60();
                  iVar1 = FUN_0050e7d0();
                  if (iVar1 == 0) {
                    iVar1 = FUN_005cfda0();
                    if (iVar1 != 0) goto LAB_005d16f8;
                  }
                  iVar1 = FUN_005b8a10();
                  if (iVar1 == 0) {
                    DAT_00a37d78 = 1;
                    return 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_005d16f8:
  FUN_005caa40();
  return 0xffffffff;
}

