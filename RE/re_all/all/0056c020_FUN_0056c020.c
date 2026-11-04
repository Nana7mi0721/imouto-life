
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0056c020(void)

{
  int iVar1;
  
  iVar1 = FUN_005d6830();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if (DAT_00ab012c != 1) {
    DAT_00ab012c = 1;
    DAT_00ab0138 = 1;
    DAT_00aba0a8 = 0x10;
    DAT_00ab0134 = 0xffffffff;
    DAT_00aba0a4 = 0;
    _DAT_00aba0b4 = 0;
    _DAT_00aba0ac = 4;
    _DAT_00ab0140 = 0;
    _DAT_00ab013c = 0;
    FUN_0056d380(&DAT_00ab0144,0,0x9f60);
  }
  return 0;
}

