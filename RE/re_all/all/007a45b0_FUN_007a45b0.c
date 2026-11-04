
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a45b0(int param_1,float *param_2,int param_3,int param_4,int param_5,int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  fVar1 = *(float *)(param_4 + param_5 * 4);
  fVar2 = *(float *)(param_4 + (*(int *)(param_1 + 8) + param_5) * 4);
  fVar3 = SQRT(fVar1 * fVar1 + fVar2 * fVar2 + _DAT_0083c5b8) + _DAT_0083c5b8;
  if (0 < param_6) {
    pfVar4 = param_2;
    do {
      param_6 = param_6 + -1;
      *pfVar4 = *pfVar4 * (fVar1 / fVar3) +
                *(float *)((param_3 - (int)param_2) + (int)pfVar4) * (fVar2 / fVar3);
      pfVar4 = pfVar4 + 1;
    } while (param_6 != 0);
  }
  return;
}

