
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065efa0(uint param_1,float *param_2)

{
  double dVar1;
  int iVar2;
  float10 fVar3;
  double local_20;
  double local_18;
  double local_10;
  
  fVar3 = (float10)FUN_0065ea90(param_1 >> 0xe & 0x3ff);
  local_18 = (double)fVar3;
  if ((float10)_DAT_007d0a60 < fVar3) {
    iVar2 = FUN_0065eef0(&local_20,&local_10,param_1 & 0x3fff);
    if (iVar2 < 0) {
      local_20 = 0.210526316;
      local_10 = _DAT_008053b8;
    }
    fVar3 = (float10)_DAT_00802e18 /
            (((float10)local_20 * (float10)_DAT_008053e0 -
             (float10)local_10 * (float10)_DAT_008053d8) + (float10)_DAT_00805370);
    dVar1 = (double)(fVar3 * (float10)local_20 * (float10)_DAT_008053d0);
    fVar3 = fVar3 * (float10)local_10 * (float10)_DAT_008053c8;
    *param_2 = (float)(((float10)dVar1 / fVar3) * (float10)local_18);
    param_2[1] = (float)local_18;
    param_2[2] = (float)(((((float10)_DAT_00802e18 - (float10)dVar1) - fVar3) / fVar3) *
                        (float10)local_18);
    return;
  }
  param_2[2] = 0.0;
  param_2[1] = 0.0;
  *param_2 = 0.0;
  return;
}

