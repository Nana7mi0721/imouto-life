
undefined4 FUN_00580da0(uint param_1,int param_2)

{
  undefined *puVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = (param_1 >> 0x1a & 0x1f) * 0x2f0;
  if (*(int *)(&DAT_00cc44e0 + iVar5) == 0) {
    return 0xffffffff;
  }
  if ((((*(int *)(&DAT_00cc44e0 + iVar5) == 0) || ((int)param_1 < 0)) ||
      ((param_1 & 0x7c000000) != *(uint *)(&DAT_00cc4508 + iVar5))) ||
     (((uVar4 = param_1 & 0xffff, *(int *)(&DAT_00cc4510 + iVar5) <= (int)uVar4 ||
       (piVar2 = *(int **)(*(int *)(&DAT_00cc44e4 + iVar5) + uVar4 * 4), piVar2 == (int *)0x0)) ||
      (*piVar2 * 0x10000 != (param_1 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  if (piVar2[2] == param_2) {
    return 0;
  }
  puVar1 = &DAT_00cc4524 + iVar5;
  FUN_0056da60(puVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxHandle.cpp",0x18c);
  piVar3 = (int *)FUN_0056e1b0(piVar2,param_2,"..\\..\\..\\..\\Source\\Library\\Main\\DxHandle.cpp",
                               399);
  if (piVar3 == (int *)0x0) {
    FUN_0056dac0(puVar1);
    return 0xffffffff;
  }
  if (piVar3 != piVar2) {
    *(int **)(*(int *)(&DAT_00cc44e4 + iVar5) + uVar4 * 4) = piVar3;
    piVar3[9] = (int)piVar3;
    *(int **)(piVar3[10] + 0xc) = piVar3 + 8;
    *(int **)(piVar3[0xb] + 8) = piVar3 + 8;
  }
  FUN_0056dac0(puVar1);
  return 0;
}

