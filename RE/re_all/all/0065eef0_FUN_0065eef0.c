
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0065eef0(double *param_1,double *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_3 < 0) || (0x3fa0 < param_3)) {
    return 0xffffffff;
  }
  iVar3 = 0xa3;
  iVar2 = 0;
  do {
    iVar1 = iVar3 + iVar2 >> 1;
    if (param_3 - *(short *)(&DAT_00a0aafe + iVar1 * 8) < 1) {
      if (-1 < param_3 - *(short *)(&DAT_00a0aafe + iVar1 * 8)) break;
      iVar3 = iVar1;
    }
    else {
      iVar2 = iVar1;
    }
    iVar1 = iVar2;
    iVar2 = iVar1;
  } while (1 < iVar3 - iVar1);
  *param_1 = ((double)(param_3 - *(short *)(&DAT_00a0aafe + iVar1 * 8)) + _DAT_00804a60) *
             _DAT_008053c0 + (double)*(float *)(&DAT_00a0aaf8 + iVar1 * 8);
  *param_2 = ((double)iVar1 + _DAT_00804a60) * _DAT_008053c0 + _DAT_00805390;
  return 0;
}

