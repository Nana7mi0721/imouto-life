
undefined4 FUN_00580290(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  FUN_0056da60(&DAT_00ca4230,"..\\..\\..\\..\\Source\\Library\\Main\\DxASyncLoad.cpp",0x1d5);
  if (DAT_00cc44d4 == 0x8000) {
    FUN_0056dac0(&DAT_00ca4230);
    uVar1 = FUN_0056bb10();
    return uVar1;
  }
  iVar3 = DAT_00cc44d8;
  if (DAT_00cc44d8 == 0x8000) {
    iVar3 = 0;
    do {
      if ((&DAT_00ca44d4)[iVar3] == 0) break;
      if ((&DAT_00ca44d8)[iVar3] == 0) {
        iVar3 = iVar3 + 1;
        break;
      }
      if ((&DAT_00ca44dc)[iVar3] == 0) {
        iVar3 = iVar3 + 2;
        break;
      }
      if ((&DAT_00ca44e0)[iVar3] == 0) {
        iVar3 = iVar3 + 3;
        break;
      }
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x8000);
  }
  *param_1 = iVar3;
  param_1[1] = 0;
  iVar2 = FUN_00550060(0);
  param_1[2] = iVar2;
  if (DAT_00cc44d8 == iVar3) {
    DAT_00cc44d8 = DAT_00cc44d8 + 1;
  }
  (&DAT_00ca44d4)[iVar3] = param_1;
  DAT_00cc44d4 = DAT_00cc44d4 + 1;
  FUN_0057fd00(0);
  FUN_0056dac0(&DAT_00ca4230);
  return 0;
}

