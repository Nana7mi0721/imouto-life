
undefined4 FUN_0056db80(void)

{
  int iVar1;
  
  if (DAT_00afe8b8 == 0) {
    FUN_0056da30(&DAT_00afe8bc);
    DAT_00afe8b8 = 1;
  }
  FUN_0056da60(&DAT_00afe8bc,"..\\..\\..\\..\\Source\\Library\\Main\\DxMemory.cpp",0x4f);
  if (DAT_00afa270 == 0) {
    DAT_00afa270 = 1;
    iVar1 = FUN_005e2310();
    if (iVar1 < 0) {
      FUN_0056dac0(&DAT_00afe8bc);
      return 1;
    }
    FUN_005d82c0(&DAT_00afa278,1,0x10,1,0x400000,0,&LAB_005d9030,&LAB_005d9090,&LAB_005d90a0,
                 &LAB_005d90b0,0,0,0,0,0,0,0);
    FUN_005d82c0(&DAT_00afc598,1,0x10,1,0x2000000,0,&LAB_005d9030,&LAB_005d9090,&LAB_005d90a0,
                 &LAB_005d90b0,0,0,0,0,0,0,0);
  }
  FUN_0056dac0(&DAT_00afe8bc);
  return 0;
}

