
undefined4 FUN_005728b0(void)

{
  uint uVar1;
  
  if (DAT_00b239c0 == 0) {
    if (DAT_00f3a0b8 == 0) {
      FUN_005702e0(&DAT_00860b28,&DAT_00860b28);
      DAT_00f3a0b8 = 1;
    }
    FUN_00570180(&DAT_00860b28,&DAT_00b239c4);
    uVar1 = 0;
    do {
      *(short *)(&DAT_00b439c4 + (uint)(ushort)(&DAT_00b239c4)[uVar1] * 2) = (short)uVar1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x10000);
    if (DAT_00f3a0c4 == 0) {
      FUN_005702e0(&DAT_008661c8,&DAT_008661c8);
      DAT_00f3a0c4 = 1;
    }
    FUN_00570180(&DAT_008661c8,&DAT_00b639c4);
    uVar1 = 0;
    do {
      *(short *)(&DAT_00b839c4 + (uint)(ushort)(&DAT_00b639c4)[uVar1] * 2) = (short)uVar1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x10000);
    if (DAT_00f3a0cc == 0) {
      FUN_005702e0(&DAT_00873d00,&DAT_00873d00);
      DAT_00f3a0cc = 1;
    }
    FUN_00570180(&DAT_00873d00,&DAT_00ba39c4);
    uVar1 = 0;
    do {
      *(short *)(&DAT_00bc39c4 + (uint)(ushort)(&DAT_00ba39c4)[uVar1] * 2) = (short)uVar1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x10000);
    if (DAT_00f3a0bc == 0) {
      FUN_005702e0(&DAT_0087dce8,&DAT_0087dce8);
      DAT_00f3a0bc = 1;
    }
    FUN_00570180(&DAT_0087dce8,&DAT_00be39c4);
    uVar1 = 0;
    do {
      *(short *)(&DAT_00c039c4 + (uint)(ushort)(&DAT_00be39c4)[uVar1] * 2) = (short)uVar1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x10000);
    if (DAT_00f3a0c8 == 0) {
      FUN_005702e0(&DAT_008893e8,&DAT_008893e8);
      DAT_00f3a0c8 = 1;
    }
    FUN_00570180(&DAT_008893e8,&DAT_00c239c4);
    uVar1 = 0;
    do {
      *(short *)(&DAT_00c439c4 + (uint)(ushort)(&DAT_00c239c4)[uVar1] * 2) = (short)uVar1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x100);
    if (DAT_00f3a0c0 == 0) {
      FUN_005702e0(&DAT_00889648,&DAT_00889648);
      DAT_00f3a0c0 = 1;
    }
    FUN_00570180(&DAT_00889648,&DAT_00c639c4);
    uVar1 = 0;
    do {
      *(short *)(&DAT_00c839c4 + (uint)(ushort)(&DAT_00c639c4)[uVar1] * 2) = (short)uVar1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x100);
    DAT_00b239c0 = 1;
  }
  return 0;
}

