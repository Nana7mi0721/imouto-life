
undefined4 FUN_00580f70(uint param_1)

{
  int *piVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = (param_1 >> 0x1a & 0x1f) * 0x2f0;
  if (*(int *)(&DAT_00cc44e0 + iVar4) == 0) {
    return 0xffffffff;
  }
  puVar2 = &DAT_00cc4524 + iVar4;
  FUN_0056da60(puVar2,"..\\..\\..\\..\\Source\\Library\\Main\\DxHandle.cpp",0x2c7);
  if (((((*(int *)(&DAT_00cc44e0 + iVar4) == 0) || ((int)param_1 < 0)) ||
       ((param_1 & 0x7c000000) != *(uint *)(&DAT_00cc4508 + iVar4))) ||
      ((*(int *)(&DAT_00cc4510 + iVar4) <= (int)(param_1 & 0xffff) ||
       (piVar3 = *(int **)(*(int *)(&DAT_00cc44e4 + iVar4) + (param_1 & 0xffff) * 4),
       piVar3 == (int *)0x0)))) || (*piVar3 * 0x10000 != (param_1 & 0x3ff0000))) {
    FUN_0056dac0(puVar2);
    return 0xffffffff;
  }
  piVar1 = piVar3 + 4;
  *piVar1 = *piVar1 + -1;
  if ((*piVar1 == 0) && (piVar3[7] != 0)) {
    FUN_00580b80(param_1);
  }
  FUN_0056dac0(puVar2);
  return 0;
}

