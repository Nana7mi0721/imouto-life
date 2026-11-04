
undefined4 FUN_0057fc10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_0056da60(&DAT_00ca4230,"..\\..\\..\\..\\Source\\Library\\Main\\DxASyncLoad.cpp",0x20b);
  iVar1 = (&DAT_00ca44d4)[param_1];
  if (iVar1 == 0) {
    FUN_0056dac0(&DAT_00ca4230);
    return 0xffffffff;
  }
  if ((param_2 != 0) && (*(int *)(iVar1 + 4) != 0)) {
    FUN_0056dac0(&DAT_00ca4230);
    return 0xfffffffe;
  }
  DAT_00cc44d4 = DAT_00cc44d4 + -1;
  iVar3 = DAT_00cc44d8 + -1;
  if (param_1 == iVar3) {
    if (DAT_00cc44d4 == 0) {
      DAT_00cc44d8 = 0;
    }
    else {
      iVar2 = (&DAT_00ca44d0)[iVar3];
      DAT_00cc44d8 = iVar3;
      while (iVar2 == 0) {
        DAT_00cc44d8 = DAT_00cc44d8 + -1;
        iVar2 = (&DAT_00ca44d0)[DAT_00cc44d8];
      }
    }
  }
  FUN_0056e1d0(iVar1);
  (&DAT_00ca44d4)[param_1] = 0;
  FUN_0056dac0(&DAT_00ca4230);
  return 0;
}

