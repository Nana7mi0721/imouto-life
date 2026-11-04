
int * FUN_00580500(uint param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (param_1 >> 0x1a & 0x1f) * 0x2f0;
  if ((((*(int *)(&DAT_00cc44e0 + iVar1) == 0) || ((int)param_1 < 0)) ||
      ((param_1 & 0x7c000000) != *(uint *)(&DAT_00cc4508 + iVar1))) ||
     (((*(int *)(&DAT_00cc4510 + iVar1) <= (int)(param_1 & 0xffff) ||
       (piVar2 = *(int **)(*(int *)(&DAT_00cc44e4 + iVar1) + (param_1 & 0xffff) * 4),
       piVar2 == (int *)0x0)) || (*piVar2 * 0x10000 != (param_1 & 0x3ff0000))))) {
    piVar2 = (int *)0x0;
  }
  return piVar2;
}

