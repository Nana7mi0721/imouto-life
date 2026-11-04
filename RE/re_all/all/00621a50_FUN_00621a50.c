
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00621a50(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = param_1[4];
  fVar2 = *param_1;
  fVar3 = param_1[5];
  fVar4 = param_1[1];
  fVar5 = param_1[6];
  fVar6 = param_1[2];
  param_2[3] = 0.0;
  *param_2 = (fVar1 + fVar2) * _DAT_007d589c;
  param_2[1] = (fVar3 + fVar4) * _DAT_007d589c;
  param_2[2] = (fVar5 + fVar6) * _DAT_007d589c;
  return;
}

