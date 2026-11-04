
undefined4 FUN_005d18e0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00f3a028 != (int *)0x0) {
    (**(code **)(*DAT_00f3a028 + 8))(DAT_00f3a028);
    DAT_00f3a028 = (int *)0x0;
  }
  FUN_0056bb10(&PTR_LAB_007ff268);
  iVar1 = (*DAT_00aba190)(&DAT_0085e784,0,7,&DAT_0085e7f4,&DAT_00f3a028);
  if (iVar1 < 0) {
    FUN_0056bd30(0x1020001,&DAT_007ff1f0);
    return 0xffffffff;
  }
  FUN_0056bb10(&DAT_007d4974);
  FUN_0056bb10(&DAT_007d761c);
  iVar1 = (**(code **)(*DAT_00f3a028 + 0x48))(DAT_00f3a028,0);
  if (iVar1 < 0) {
    FUN_0056bd30(0x1020002,&PTR_LAB_007ff22c);
    (**(code **)(*DAT_00f3a028 + 8))(DAT_00f3a028);
    return 0xffffffff;
  }
  FUN_0056bb10(&DAT_007ff214);
  iVar1 = *DAT_00f3a028;
  uVar2 = FUN_0050e7c0(-(uint)(DAT_00a210a8 != 0) & 0x1000 | 8);
  (**(code **)(iVar1 + 0x50))(DAT_00f3a028,uVar2);
  if (DAT_00aaf0d8 == 2) {
    FUN_0050ea10(0);
  }
  return 0;
}

