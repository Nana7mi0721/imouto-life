
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0056ddd0(undefined4 param_1)

{
  float fVar1;
  
  if (DAT_00afe8b8 == 0) {
    FUN_0056da30(&DAT_00afe8bc,param_1);
    DAT_00afe8b8 = 1;
  }
  FUN_0056da60(&DAT_00afe8bc,"..\\..\\..\\..\\Source\\Library\\Main\\DxMemory.cpp",0x1d7);
  FUN_0056bb00(&DAT_007d4b08);
  FUN_0056bb00(L"Alloc memory dump\n");
  FUN_005d7800(&DAT_00afa278);
  FUN_005d7800(&DAT_00afc598);
  fVar1 = (float)DAT_00afa258;
  if (DAT_00afa258 < 0) {
    fVar1 = fVar1 + _DAT_007d4bd8;
  }
  FUN_0056bc50(L"\tTotal size:%d(%.3fkb)  Alloc num:%d",DAT_00afa258,
               (double)(fVar1 * (float)_DAT_007d7ff0),DAT_00afa25c);
  FUN_005e2310();
  FUN_0056bb00(&DAT_007d4b08);
  FUN_0056dac0(&DAT_00afe8bc);
  return;
}

