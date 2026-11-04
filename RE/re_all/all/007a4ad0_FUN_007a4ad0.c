
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a4ad0(float *param_1,float *param_2,float param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  float local_4;
  
  local_4 = _DAT_007d5344;
  fVar3 = _DAT_007d5344;
  if (0 < param_4) {
    pfVar5 = param_2;
    iVar6 = param_4;
    do {
      iVar6 = iVar6 + -1;
      fVar3 = *(float *)(((int)param_1 - (int)param_2) + (int)pfVar5) * *pfVar5 + fVar3;
      local_4 = *pfVar5 * *pfVar5 + local_4;
      pfVar5 = pfVar5 + 1;
    } while (iVar6 != 0);
  }
  fVar3 = fVar3 * param_3 + fVar3 * param_3;
  fVar4 = (param_3 * param_3 + local_4) - fVar3;
  local_4 = param_3 * param_3 + fVar3 + local_4;
  if ((local_4 < _DAT_0083c5bc) || (fVar4 < _DAT_0083c5bc)) {
    for (; param_4 != 0; param_4 = param_4 + -1) {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
  }
  else {
    fVar3 = _DAT_00804108 / SQRT(fVar4);
    fVar4 = _DAT_00804108 / SQRT(local_4);
    if (0 < param_4) {
      pfVar5 = param_2;
      do {
        fVar2 = *(float *)((int)pfVar5 + ((int)param_1 - (int)param_2)) * param_3;
        fVar1 = *pfVar5;
        param_4 = param_4 + -1;
        *(float *)((int)pfVar5 + ((int)param_1 - (int)param_2)) = (fVar2 - fVar1) * fVar3;
        *pfVar5 = (fVar1 + fVar2) * fVar4;
        pfVar5 = pfVar5 + 1;
      } while (param_4 != 0);
      return;
    }
  }
  return;
}

