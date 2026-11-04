
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a6c10(float *param_1,float *param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float10 fVar4;
  float local_4;
  
  fVar4 = (float10)_DAT_0083c5b8;
  local_4 = _DAT_0083c5b8;
  if (param_3 == 0) {
    local_4 = _DAT_007d5344;
    if (0 < param_4) {
      iVar3 = param_4;
      do {
        fVar1 = *param_1;
        param_1 = param_1 + 1;
        iVar3 = iVar3 + -1;
        local_4 = fVar1 * fVar1 + local_4;
      } while (iVar3 != 0);
    }
    local_4 = local_4 + _DAT_0083c5b8;
    fVar4 = (float10)_DAT_007d5344;
    if (0 < param_4) {
      do {
        fVar1 = *param_2;
        param_2 = param_2 + 1;
        param_4 = param_4 + -1;
        fVar4 = (float10)fVar1 * (float10)fVar1 + fVar4;
      } while (param_4 != 0);
    }
    fVar4 = fVar4 + (float10)_DAT_0083c5b8;
  }
  else if (0 < param_4) {
    iVar3 = (int)param_1 - (int)param_2;
    do {
      fVar2 = *(float *)(iVar3 + (int)param_2) + *param_2;
      fVar1 = *(float *)(iVar3 + (int)param_2) - *param_2;
      param_2 = param_2 + 1;
      param_4 = param_4 + -1;
      local_4 = fVar2 * fVar2 + local_4;
      fVar4 = (float10)fVar1 * (float10)fVar1 + fVar4;
    } while (param_4 != 0);
  }
  fVar4 = (float10)fpatan(SQRT(fVar4),SQRT((float10)local_4));
  FUN_006c5af0((double)(fVar4 * (float10)_DAT_0083c820 + (float10)_DAT_00804a60));
  __ftol();
  return;
}

