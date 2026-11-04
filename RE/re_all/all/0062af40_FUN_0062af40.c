
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0062af40(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  pfVar3 = param_1;
  local_30 = *param_3 - *param_1;
  local_2c = param_3[1] - param_1[1];
  local_28 = param_3[2] - param_1[2];
  local_20 = *param_2 - *param_1;
  local_1c = param_2[1] - param_1[1];
  local_18 = param_2[2] - param_1[2];
  fVar2 = local_20 * local_30 + local_1c * local_2c + local_18 * local_28;
  if (fVar2 <= _DAT_007d5344) {
    fVar2 = _DAT_007d5344;
  }
  else {
    fVar1 = local_20 * local_20 + local_1c * local_1c + local_18 * local_18;
    if (fVar1 <= fVar2) {
      local_30 = local_30 - local_20;
      local_2c = local_2c - local_1c;
      local_28 = local_28 - local_18;
      fVar2 = _DAT_00804108;
    }
    else {
      param_3 = (float *)(fVar2 / fVar1);
      param_1 = (float *)(local_18 * (float)param_3);
      param_2 = (float *)(local_1c * (float)param_3);
      local_3c = local_20 * (float)param_3;
      FUN_005fc500(&local_3c,&param_2,&param_1);
      local_30 = local_30 - local_10;
      local_2c = local_2c - local_c;
      local_28 = local_28 - local_8;
      fVar2 = (float)param_3;
    }
  }
  param_3 = (float *)(local_18 * fVar2);
  param_1 = (float *)(local_1c * fVar2);
  param_2 = (float *)(local_20 * fVar2);
  FUN_005fc500(&param_2,&param_1,&param_3);
  local_3c = local_8 + pfVar3[2];
  local_38 = local_c + pfVar3[1];
  local_34 = local_10 + *pfVar3;
  FUN_005fc500(&local_34,&local_38,&local_3c);
  *param_4 = local_20;
  param_4[1] = local_1c;
  param_4[2] = local_18;
  param_4[3] = local_14;
  return (float10)local_2c * (float10)local_2c +
         (float10)local_30 * (float10)local_30 + (float10)local_28 * (float10)local_28;
}

