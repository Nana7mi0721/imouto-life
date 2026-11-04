
undefined4 FUN_0059d910(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00ddb5d8 == 0) {
    FUN_005d4ba0(DAT_00ddb5e0);
    DAT_00ddb5e0 = 0;
    return 0;
  }
  FUN_005d4ba0(DAT_00ddb5d8);
  iVar2 = DAT_00ddb5dc;
  iVar1 = DAT_00ddb5dc * 0x18;
  if (((&DAT_00ecfb1c)[iVar1] != '\0') && ((&DAT_00ecfb1d)[iVar1] != '\0')) {
    (&DAT_00ecfb1d)[iVar1] = 0;
    uVar3 = FUN_00550060(0);
    (&DAT_00ecfb2c)[iVar2 * 6] = uVar3;
  }
  DAT_00ddb5dc = 0xffffffff;
  DAT_00ddb5d8 = 0;
  return 0;
}

