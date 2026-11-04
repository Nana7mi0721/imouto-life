
void __thiscall FUN_00612f80(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar1 = param_1[10];
  fVar2 = param_1[9];
  fVar3 = param_1[8];
  fVar4 = param_1[6];
  fVar5 = param_1[5];
  fVar6 = param_1[4];
  fVar7 = param_1[2];
  fVar8 = param_1[1];
  *param_2 = ABS(*param_1);
  param_2[2] = ABS(fVar7);
  param_2[1] = ABS(fVar8);
  param_2[3] = 0.0;
  param_2[7] = 0.0;
  param_2[4] = ABS(fVar6);
  param_2[5] = ABS(fVar5);
  param_2[6] = ABS(fVar4);
  param_2[8] = ABS(fVar3);
  param_2[9] = ABS(fVar2);
  param_2[10] = ABS(fVar1);
  param_2[0xb] = 0.0;
  return;
}

