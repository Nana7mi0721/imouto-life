
undefined4 FUN_00560e70(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = FUN_0057e0e0();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  FUN_0056da60(&DAT_00cc4df4,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0xad1);
  FUN_0056da60(&DAT_00a837b0,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0xad4);
  iVar2 = DAT_00a8379c[3];
  puVar1 = DAT_00a8379c;
  while (iVar2 != 0) {
    if (*(char *)(puVar1[1] + 0x24d4) != '\0') {
      FUN_005607a0(*puVar1,0);
    }
    puVar1 = (undefined4 *)puVar1[3];
    iVar2 = puVar1[3];
  }
  FUN_0056dac0(&DAT_00a837b0);
  FUN_0055eee0();
  FUN_0056dac0(&DAT_00cc4df4);
  return 0;
}

