
undefined4 FUN_00515170(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00582330(&DAT_00a37df8,DAT_00a37e60,DAT_00a37e64,DAT_00a37e70 != 0x10);
  if (iVar1 < 0) {
    uVar2 = FUN_0056bb10(&DAT_007d530c);
    return uVar2;
  }
  iVar1 = FUN_00582330(&DAT_00a37e10,DAT_00a37e60,DAT_00a37e64,DAT_00a37e70 != 0x10);
  if (iVar1 < 0) {
    uVar2 = FUN_0056bb10(&DAT_007d52dc);
    return uVar2;
  }
  FUN_0056d380(&DAT_00a37e40,0,0x18);
  FUN_0056d380(&DAT_00a37e28,0,0x18);
  FUN_005820e0(&DAT_00a37e28,DAT_00a37e60,DAT_00a37e64,0xffffffff,0,DAT_00a37e70 != 0x10,0,0,0,0);
  FUN_005820e0(&DAT_00a37e40,DAT_00a37e60,DAT_00a37e64,0xffffffff,0,DAT_00a37e70 != 0x10,0,1,0,0);
  uVar2 = FUN_005440f0(*(undefined4 *)(DAT_00a37e0c + 0x14),DAT_00a37ed8,DAT_00a37edc,DAT_00a37ee0,0
                      );
  FUN_00581fb0(&DAT_00a37df8,0,uVar2);
  DAT_00a37e58 = &DAT_00a37df8;
  return 0;
}

