
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a1c60(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_8;
  
  FUN_00494480(0,_DAT_00802e18,_DAT_00802e18,_DAT_007d0a60);
  *param_2 = 0;
  *param_1 = 0;
  local_8 = 0;
  while( true ) {
    iVar1 = FUN_004ce080();
    if (iVar1 <= local_8) break;
    piVar2 = (int *)FUN_004ce990(local_8);
    if (*param_1 < *piVar2) {
      piVar2 = (int *)FUN_004ce990(local_8);
      *param_1 = *piVar2;
    }
    piVar2 = (int *)FUN_004ce990(local_8);
    piVar3 = (int *)FUN_004ce990(local_8);
    if (*param_2 < *piVar2 + *piVar3) {
      piVar2 = (int *)FUN_004ce990(local_8);
      piVar3 = (int *)FUN_004ce990(local_8);
      *param_2 = *piVar2 + *piVar3;
    }
    local_8 = local_8 + 1;
  }
  return;
}

