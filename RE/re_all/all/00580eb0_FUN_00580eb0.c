
undefined4 FUN_00580eb0(int param_1,code *param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  param_1 = param_1 * 0x2f0;
  if (*(int *)(&DAT_00cc44e0 + param_1) == 0) {
    return 0xffffffff;
  }
  puVar1 = &DAT_00cc4524 + param_1;
  FUN_0056da60(puVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxHandle.cpp",0x1ed);
  do {
    iVar6 = *(int *)(&DAT_00cc4518 + param_1);
    iVar2 = *(int *)(&DAT_00cc451c + param_1);
    piVar5 = (int *)(*(int *)(&DAT_00cc44e4 + param_1) + iVar6 * 4);
    while( true ) {
      if (iVar2 < iVar6) {
        FUN_0056dac0(puVar1);
        return 0;
      }
      if ((*piVar5 != 0) && ((param_2 == (code *)0x0 || (iVar4 = (*param_2)(*piVar5), iVar4 == 0))))
      break;
      iVar6 = iVar6 + 1;
      piVar5 = piVar5 + 1;
    }
    uVar3 = *(undefined4 *)(*piVar5 + 4);
    FUN_0056dac0(puVar1);
    FUN_00580b80(uVar3);
    FUN_0056da60(puVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxHandle.cpp",0x211);
  } while( true );
}

