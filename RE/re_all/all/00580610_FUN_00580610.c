
undefined4 FUN_00580610(uint param_1,int param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = (param_1 >> 0x1a & 0x1f) * 0x2f0;
  if (*(int *)(&DAT_00cc44e0 + iVar3) == 0) {
    return 0xffffffff;
  }
  puVar1 = &DAT_00cc4524 + iVar3;
  FUN_0056da60(puVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxHandle.cpp",0x2a5);
  if ((((*(int *)(&DAT_00cc44e0 + iVar3) == 0) || ((int)param_1 < 0)) ||
      ((param_1 & 0x7c000000) != *(uint *)(&DAT_00cc4508 + iVar3))) ||
     (((*(int *)(&DAT_00cc4510 + iVar3) <= (int)(param_1 & 0xffff) ||
       (piVar2 = *(int **)(*(int *)(&DAT_00cc44e4 + iVar3) + (param_1 & 0xffff) * 4),
       piVar2 == (int *)0x0)) || (*piVar2 * 0x10000 != (param_1 & 0x3ff0000))))) {
    FUN_0056dac0(puVar1);
    return 0xffffffff;
  }
  piVar2[4] = piVar2[4] + 1;
  piVar2[6] = param_2;
  FUN_0056dac0(puVar1);
  return 0;
}

