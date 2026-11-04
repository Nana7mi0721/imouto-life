
undefined4 FUN_0056dd00(void)

{
  int iVar1;
  uint uVar2;
  
  if (DAT_00afe8b8 == 0) {
    FUN_0056da30(&DAT_00afe8bc);
    DAT_00afe8b8 = 1;
  }
  FUN_0056da60(&DAT_00afe8bc,"..\\..\\..\\..\\Source\\Library\\Main\\DxMemory.cpp",0xa9);
  iVar1 = FUN_00550060(0);
  if (iVar1 < DAT_00afa274) {
    iVar1 = (iVar1 - DAT_00afa274) + 0x7fffffff;
  }
  else {
    iVar1 = iVar1 - DAT_00afa274;
  }
  uVar2 = iVar1 / 1000 & 0xffff;
  FUN_005d7850(&DAT_00afa278,uVar2);
  FUN_005d7850(&DAT_00afc598,uVar2);
  iVar1 = FUN_005e2310();
  if (iVar1 < 0) {
    FUN_0056dac0(&DAT_00afe8bc);
    return 0xffffffff;
  }
  FUN_0056dac0(&DAT_00afe8bc);
  return 0;
}

