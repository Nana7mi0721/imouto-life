
undefined4 FUN_00580830(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = (param_1 >> 0x1a & 0x1f) * 0x2f0;
  if ((((*(int *)(&DAT_00cc44e0 + iVar2) == 0) || ((int)param_1 < 0)) ||
      ((param_1 & 0x7c000000) != *(uint *)(&DAT_00cc4508 + iVar2))) ||
     (((*(int *)(&DAT_00cc4510 + iVar2) <= (int)(param_1 & 0xffff) ||
       (piVar1 = *(int **)(*(int *)(&DAT_00cc44e4 + iVar2) + (param_1 & 0xffff) * 4),
       piVar1 == (int *)0x0)) || (*piVar1 * 0x10000 != (param_1 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  piVar1[3] = param_2;
  return 0;
}

