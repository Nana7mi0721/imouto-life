
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00645080(int param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  
  fVar4 = (float10)FUN_006c5580();
  *param_3 = (float)(fVar4 + fVar4);
  if ((float10)_DAT_00804520 < fVar4 + fVar4) {
    fVar1 = param_2[1];
    fVar2 = param_2[2];
    *param_4 = *param_2;
    param_4[1] = fVar1;
    param_4[2] = fVar2;
    param_4[3] = 0.0;
    fVar4 = (float10)FUN_005fcc30(param_4);
    fVar1 = (float)((float10)_DAT_00804108 / SQRT(fVar4));
    *param_4 = (float)(((float10)_DAT_00804108 / SQRT(fVar4)) * (float10)*param_4);
    fVar2 = fVar1 * param_4[1];
    param_4[1] = fVar2;
    fVar1 = fVar1 * param_4[2];
    param_4[2] = fVar1;
    fVar1 = -fVar1;
    fVar3 = (float)_DAT_00804920;
    *param_5 = *(float *)(param_1 + 0x1e0);
    if (fVar3 < ABS(fVar2)) {
      fVar1 = (fVar1 * fVar1) / (fVar2 * fVar2);
      *param_5 = SQRT((fVar1 + _DAT_00804108) /
                      (fVar1 / (*(float *)(param_1 + 0x1e0) * *(float *)(param_1 + 0x1e0)) +
                      _DAT_00804108 / (*(float *)(param_1 + 0x1e4) * *(float *)(param_1 + 0x1e4))));
    }
  }
  return;
}

