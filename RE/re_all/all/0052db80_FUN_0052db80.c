
int FUN_0052db80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0056e030(0xc88,"..\\..\\..\\..\\Source\\Library\\Main\\DxFile.cpp",0x1a6b);
  if (iVar1 != 0) {
    FUN_0056d380(iVar1,0,0xc88);
    *(undefined4 *)(iVar1 + 0x18) = param_4;
    iVar2 = FUN_005950d0(iVar1,param_1,param_2,param_3);
    if (-1 < iVar2) {
      return iVar1;
    }
    FUN_0056e1d0(iVar1);
  }
  return 0;
}

