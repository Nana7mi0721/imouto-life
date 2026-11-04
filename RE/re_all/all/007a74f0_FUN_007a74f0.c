
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a74f0(float *param_1,float *param_2,int param_3,int param_4,int *param_5)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  fVar2 = _DAT_00804108;
  local_10 = -1.0;
  local_c = -1.0;
  local_8 = 0.0;
  local_4 = 0.0;
  *param_5 = 0;
  param_5[1] = 1;
  if (0 < param_3) {
    pfVar3 = param_2;
    iVar4 = param_3;
    do {
      fVar1 = *pfVar3;
      pfVar3 = pfVar3 + 1;
      iVar4 = iVar4 + -1;
      fVar2 = fVar1 * fVar1 + fVar2;
    } while (iVar4 != 0);
  }
  iVar4 = 0;
  if (0 < param_4) {
    pfVar3 = param_2 + param_3;
    iVar5 = (int)param_2 - (int)param_1;
    do {
      if ((_DAT_007d5344 < *param_1) &&
         (fVar1 = *param_1 * _DAT_0083c884 * *param_1 * _DAT_0083c884,
         local_c * fVar2 < fVar1 * local_4)) {
        if (fVar1 * local_8 <= local_10 * fVar2) {
          param_5[1] = iVar4;
          local_c = fVar1;
          local_4 = fVar2;
        }
        else {
          local_c = local_10;
          local_4 = local_8;
          param_5[1] = *param_5;
          *param_5 = iVar4;
          local_10 = fVar1;
          local_8 = fVar2;
        }
      }
      fVar1 = *(float *)(iVar5 + (int)param_1);
      fVar2 = (*pfVar3 * *pfVar3 - fVar1 * fVar1) + fVar2;
      if (fVar2 < _DAT_00804108) {
        fVar2 = _DAT_00804108;
      }
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 1;
      pfVar3 = pfVar3 + 1;
    } while (iVar4 < param_4);
  }
  return;
}

