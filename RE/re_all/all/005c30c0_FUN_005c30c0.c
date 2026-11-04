
undefined4 FUN_005c30c0(void)

{
  undefined **ppuVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  undefined4 *puVar6;
  
  FUN_005bc990();
  FUN_0056bb10(&DAT_007fec94);
  puVar4 = &DAT_00f22470;
  ppuVar5 = &PTR_s_POSITION_00860000;
  puVar6 = &DAT_00ef728c;
  do {
    iVar2 = 0;
    if (*ppuVar5 != (undefined *)0x0) {
      ppuVar1 = ppuVar5;
      do {
        ppuVar1 = ppuVar1 + 7;
        iVar2 = iVar2 + 1;
      } while (*ppuVar1 != (undefined *)0x0);
    }
    if ((DAT_00a37dcc != 0) && (0 < iVar2)) {
      ppuVar1 = ppuVar5 + 2;
      iVar3 = iVar2;
      do {
        if (*ppuVar1 == (undefined *)0x1c) {
          *ppuVar1 = (undefined *)0x57;
        }
        ppuVar1 = ppuVar1 + 7;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    iVar2 = FUN_005d28a0(ppuVar5,iVar2,*puVar4,puVar4[1],puVar6);
    if (iVar2 != 0) {
      FUN_0056bb10(&DAT_007fec08);
      return 0xffffffff;
    }
    puVar6 = puVar6 + 1;
    ppuVar5 = ppuVar5 + 0x4f;
    puVar4 = puVar4 + 2;
  } while ((int)puVar6 < 0xef72a8);
  iVar2 = FUN_005d28a0(&PTR_s_POSITION_00860ab0,3,DAT_00f22c68,DAT_00f22c6c,&DAT_00ef72a8);
  if (iVar2 != 0) {
    FUN_0056bb10(&DAT_007fec50);
    return 0xffffffff;
  }
  iVar2 = FUN_005d28a0(&PTR_s_POSITION_008609b0,9,DAT_00f22c70,DAT_00f22c74,&DAT_00ef72ac);
  if (iVar2 == 0) {
    FUN_0056bb10(&DAT_007d4974);
    return 0;
  }
  FUN_0056bb10(&DAT_007febb0);
  return 0xffffffff;
}

