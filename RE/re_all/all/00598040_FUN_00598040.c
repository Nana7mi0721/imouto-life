
undefined4 FUN_00598040(void)

{
  int iVar1;
  
  if (DAT_00f3a04c != 0) {
    if (DAT_00ddb5c8 != 0) {
      FUN_005d3370(DAT_00ddb5c8);
      DAT_00ddb5c8 = 0;
    }
    FUN_0056bb10(&DAT_007fa1fc);
    if (((DAT_00ddb378 == 0) || (DAT_00ddb5cc == 0)) || (DAT_00ddb5d0 == 0)) {
      DAT_00ddb5cc = 1;
      if (1 < DAT_00a37e60) {
        do {
          DAT_00ddb5cc = DAT_00ddb5cc * 2;
        } while (DAT_00ddb5cc < DAT_00a37e60);
      }
      DAT_00ddb5d0 = 1;
      if (1 < DAT_00a37e64) {
        do {
          DAT_00ddb5d0 = DAT_00ddb5d0 * 2;
        } while (DAT_00ddb5d0 < DAT_00a37e64);
      }
    }
    if ((DAT_00ddb37c == 0) || (DAT_00ddb5d4 == 0)) {
      DAT_00ddb5d4 = 0x10;
      iVar1 = 0;
    }
    else if (DAT_00ddb5d4 == 0x18) {
      iVar1 = 1;
    }
    else if (DAT_00ddb5d4 == 0x20) {
      iVar1 = 2;
    }
    else {
      iVar1 = 0;
    }
    iVar1 = FUN_005d37d0(DAT_00ddb5cc,DAT_00ddb5d0,(&DAT_00ddb598)[iVar1],DAT_00a37d84,DAT_00a37d88,
                         1,&DAT_00ddb5c8,0);
    if (-1 < iVar1) {
      FUN_005d38f0(DAT_00ddb5c8);
      FUN_005d3970(0,0,2,0,0x3f800000,0);
      FUN_0056bb10(&DAT_007d4974);
      return 0;
    }
    FUN_0056bb10(&DAT_007fa1d8);
  }
  return 0xffffffff;
}

