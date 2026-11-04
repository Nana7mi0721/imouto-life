
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a6bb0(float *param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  
  fVar2 = _DAT_007d5344;
  if (0 < param_2) {
    pfVar3 = param_1;
    iVar4 = param_2;
    do {
      fVar1 = *pfVar3;
      pfVar3 = pfVar3 + 1;
      iVar4 = iVar4 + -1;
      fVar2 = fVar1 * fVar1 + fVar2;
    } while (iVar4 != 0);
  }
  fVar2 = _DAT_00804108 / SQRT(fVar2 + _DAT_0083c5b8);
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      *param_1 = fVar2 * param_3 * *param_1;
      param_1 = param_1 + 1;
    } while (param_2 != 0);
  }
  return;
}

