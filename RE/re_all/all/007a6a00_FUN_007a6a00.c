
void FUN_007a6a00(float *param_1,int param_2,int param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  
  iVar4 = param_2 - param_3;
  pfVar3 = param_1;
  if (0 < iVar4) {
    do {
      fVar1 = *pfVar3;
      fVar2 = pfVar3[param_3];
      iVar4 = iVar4 + -1;
      pfVar3[param_3] = fVar1 * param_5 + fVar2 * param_4;
      *pfVar3 = fVar2 * -param_5 + fVar1 * param_4;
      pfVar3 = pfVar3 + 1;
    } while (iVar4 != 0);
  }
  param_2 = param_2 + param_3 * -2;
  if (-1 < param_2 + -1) {
    pfVar3 = param_1 + param_2 + -1;
    do {
      fVar1 = *pfVar3;
      fVar2 = pfVar3[param_3];
      param_2 = param_2 + -1;
      pfVar3[param_3] = fVar1 * param_5 + fVar2 * param_4;
      *pfVar3 = fVar2 * -param_5 + fVar1 * param_4;
      pfVar3 = pfVar3 + -1;
    } while (param_2 != 0);
  }
  return;
}

