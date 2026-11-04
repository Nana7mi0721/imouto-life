
undefined4 FUN_0057fe80(void)

{
  undefined4 *puVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  if ((DAT_00ca3d18 == 0) || (DVar2 = GetCurrentThreadId(), DVar2 != DAT_00ca3d1c)) {
    return 0xffffffff;
  }
  FUN_0056da60(&DAT_00ca4230,"..\\..\\..\\..\\Source\\Library\\Main\\DxASyncLoad.cpp",0x376);
  if (DAT_00ca44d0 != 0) {
    iVar3 = FUN_00550060(0);
    iVar6 = 0;
    if (0 < DAT_00ca44d0) {
      do {
        iVar4 = FUN_00550060(0);
        if (2 < iVar4 - iVar3) break;
        puVar1 = (undefined4 *)(&DAT_00ca4450)[iVar6];
        uVar5 = (*(code *)*puVar1)(puVar1);
        puVar1[2] = uVar5;
        (&DAT_00ca3d44)[puVar1[1] * 10] = 0;
        FUN_0057fd00(0);
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_00ca44d0);
    }
    if (iVar6 == DAT_00ca44d0) {
      DAT_00ca44d0 = 0;
    }
    else {
      iVar3 = DAT_00ca44d0 - iVar6;
      FUN_0056d460(&DAT_00ca4450,&DAT_00ca4450 + iVar6,iVar3 * 4);
      DAT_00ca44d0 = iVar3;
    }
  }
  iVar3 = DAT_00ca3d28 + -1;
  if (iVar3 == 0) {
    iVar3 = 1;
  }
  if (DAT_00cc44d4 < iVar3) {
    iVar3 = DAT_00cc44d4;
  }
  if (((DAT_00cc44d4 != 0) && (DAT_00ca422c < iVar3)) && (DAT_00ca422c < iVar3)) {
    iVar3 = iVar3 - DAT_00ca422c;
    do {
      FUN_0057fd00(0);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  FUN_0056dac0(&DAT_00ca4230);
  return 0;
}

