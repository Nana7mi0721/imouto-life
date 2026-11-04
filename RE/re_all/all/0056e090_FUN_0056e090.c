
int FUN_0056e090(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar1 = FUN_0056df00(param_2,0,param_4,param_5,0);
    return iVar1;
  }
  if (DAT_00afe8b8 == 0) {
    FUN_0056da30(&DAT_00afe8bc);
    DAT_00afe8b8 = 1;
  }
  FUN_0056da60(&DAT_00afe8bc,"..\\..\\..\\..\\Source\\Library\\Main\\DxMemory.cpp",0x152);
  iVar1 = FUN_005d8a10(param_1,0);
  iVar2 = FUN_005d8d30(param_1,0,param_2,param_3,param_4,param_5);
  if (iVar2 == 0) {
    FUN_0056ddd0();
    FUN_0056dac0(&DAT_00afe8bc);
    return 0;
  }
  DAT_00afa258 = DAT_00afa258 - iVar1;
  iVar1 = FUN_005d8a10(iVar2,0);
  DAT_00afa258 = DAT_00afa258 + iVar1;
  if (((DAT_00afa26c < 0) || (DAT_00afa26c == param_2)) || (DAT_00afa260 == 1)) {
    FUN_0056bb00(L"mem realloc  ");
    FUN_005d7680(param_1,0);
  }
  if (DAT_00afa264 == 1) {
    FUN_0056db40();
  }
  if (DAT_00afa268 == 1) {
    FUN_0056de90();
  }
  FUN_0056dac0(&DAT_00afe8bc);
  return iVar2;
}

