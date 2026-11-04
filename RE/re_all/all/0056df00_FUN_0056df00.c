
int FUN_0056df00(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  
  if (DAT_00afe8b8 == 0) {
    FUN_0056da30(&DAT_00afe8bc);
    DAT_00afe8b8 = 1;
  }
  FUN_0056da60(&DAT_00afe8bc,"..\\..\\..\\..\\Source\\Library\\Main\\DxMemory.cpp",0xec);
  if (DAT_00afa270 == 0) {
    iVar1 = FUN_0056db80();
    if (iVar1 < 0) {
      FUN_0056dac0(&DAT_00afe8bc);
      return 0;
    }
  }
  puVar2 = &DAT_00afc598;
  if (param_1 < 0x10001) {
    puVar2 = &DAT_00afa278;
  }
  iVar1 = FUN_005d86c0(puVar2,param_1,param_2,0,param_3,param_4,param_5);
  if (iVar1 == 0) {
    FUN_0056ddd0();
    FUN_0056de90();
    FUN_0056dac0(&DAT_00afe8bc);
    return 0;
  }
  if ((((int)DAT_00afa26c < 0) || (DAT_00afa26c == param_1)) || (DAT_00afa260 == 1)) {
    FUN_0056bb00(L"mem alloc  ");
    FUN_005d7680(iVar1,0);
  }
  iVar3 = FUN_005d8a10(iVar1,0);
  DAT_00afa258 = DAT_00afa258 + iVar3;
  DAT_00afa25c = DAT_00afa25c + 1;
  if (DAT_00afa264 == 1) {
    FUN_0056db40();
  }
  if (DAT_00afa268 == 1) {
    FUN_0056de90();
  }
  FUN_0056dac0(&DAT_00afe8bc);
  return iVar1;
}

