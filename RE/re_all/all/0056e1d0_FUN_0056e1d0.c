
void FUN_0056e1d0(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  if (DAT_00afe8b8 == 0) {
    FUN_0056da30(&DAT_00afe8bc);
    DAT_00afe8b8 = 1;
  }
  FUN_0056da60(&DAT_00afe8bc,"..\\..\\..\\..\\Source\\Library\\Main\\DxMemory.cpp",400);
  if (DAT_00afa268 == 1) {
    FUN_0056de90();
  }
  iVar1 = FUN_005d8a10(param_1,0);
  DAT_00afa258 = DAT_00afa258 - iVar1;
  DAT_00afa25c = DAT_00afa25c + -1;
  if (((DAT_00afa26c < 0) || (DAT_00afa26c == iVar1)) || (DAT_00afa260 == 1)) {
    FUN_0056bb00(L"mem free  ");
    FUN_005d7680(param_1,0);
  }
  FUN_005d8c60(param_1,0);
  if (DAT_00afa264 == 1) {
    FUN_0056db40();
  }
  FUN_0056dac0();
  return;
}

