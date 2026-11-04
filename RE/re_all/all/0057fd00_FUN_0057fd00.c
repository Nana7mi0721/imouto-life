
undefined4 __thiscall FUN_0057fd00(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  FUN_0056da60(&DAT_00ca4230,"..\\..\\..\\..\\Source\\Library\\Main\\DxASyncLoad.cpp",0x301,param_1)
  ;
  if (param_2 + DAT_00ca3d28 <= DAT_00ca422c) {
    FUN_0056dac0(&DAT_00ca4230);
    return 0;
  }
  param_2 = 0;
  iVar6 = -1;
  do {
    iVar4 = -1;
    iVar2 = 0;
    if (DAT_00ca3d24 < 1) {
LAB_0057fdcb:
      iVar4 = -1;
      iVar2 = 0;
      if (DAT_00ca3d24 < 1) goto LAB_0057fe67;
      iVar5 = -0x28;
      piVar1 = &DAT_00ca3d48;
      iVar3 = 0;
      do {
        if (((piVar1[-3] != 1) && (*piVar1 != 0)) &&
           ((piVar1[-1] != 1 &&
            ((iVar4 == -1 || (piVar1[1] < *(int *)((int)&DAT_00ca3d4c + iVar5))))))) {
          iVar4 = iVar2;
          iVar5 = iVar3;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x28;
        piVar1 = piVar1 + 10;
      } while (iVar2 < DAT_00ca3d24);
      if (iVar4 == -1) goto LAB_0057fe67;
    }
    else {
      iVar5 = -0x28;
      piVar1 = &DAT_00ca3d48;
      iVar3 = 0;
      do {
        if (((((piVar1[-3] != 1) && (*piVar1 != 0)) && (piVar1[-2] != 0)) && (piVar1[-1] != 1)) &&
           ((iVar4 == -1 ||
            (*(int *)(piVar1[2] + 8) < *(int *)(*(int *)((int)&DAT_00ca3d50 + iVar5) + 8))))) {
          iVar4 = iVar2;
          iVar5 = iVar3;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x28;
        piVar1 = piVar1 + 10;
      } while (iVar2 < DAT_00ca3d24);
      if (iVar4 == -1) goto LAB_0057fdcb;
    }
    iVar2 = FUN_0056da00(&DAT_00ca3d2c + iVar4 * 0x28);
    if (iVar2 != 0) {
      (&DAT_00ca3d48)[iVar4 * 10] = 0;
      DAT_00ca422c = DAT_00ca422c + 1;
      goto LAB_0057fe67;
    }
    if (iVar6 == iVar4) {
      param_2 = param_2 + 1;
      if (param_2 == 3) {
LAB_0057fe67:
        FUN_0056dac0(&DAT_00ca4230);
        return 0;
      }
    }
    else {
      param_2 = 1;
      iVar6 = iVar4;
    }
  } while( true );
}

