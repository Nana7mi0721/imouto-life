
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0061a5c0(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
                 float *param_6,undefined4 *param_7)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  float10 fVar5;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [16];
  
  fVar1 = *param_1;
  pfVar4 = param_1 + 1;
  fVar2 = _DAT_00804108 / param_5;
  param_1 = (float *)(fVar2 * (param_2[2] - param_1[2]));
  param_5 = (param_2[1] - *pfVar4) * fVar2;
  param_2 = (float *)((*param_2 - fVar1) * fVar2);
  FUN_005fc500(&param_2,&param_5,&param_1);
  pfVar3 = param_3;
  *param_6 = local_30;
  pfVar4 = param_3 + 3;
  param_6[1] = local_2c;
  param_6[2] = local_28;
  param_6[3] = local_24;
  if ((((*pfVar4 == param_4[3]) && (param_3[2] == param_4[2])) && (param_3[1] == param_4[1])) &&
     (*param_3 == *param_4)) {
    *param_7 = 0;
    param_7[1] = 0;
    param_7[2] = 0;
    param_7[3] = 0;
    return;
  }
  FUN_0061a8b0(local_10,param_4);
  param_2 = (float *)-pfVar3[2];
  param_1 = (float *)-pfVar3[1];
  param_5 = -*pfVar3;
  FUN_0061a080(&param_5,&param_1,&param_2,pfVar4);
  FUN_0061a150(&local_30,local_10,&local_20);
  fVar5 = (float10)FUN_0061a2f0(&local_30);
  param_2 = (float *)(float)((float10)_DAT_00804108 / SQRT(fVar5));
  FUN_0061a880(&param_2);
  fVar5 = (float10)FUN_006c5580();
  param_2 = (float *)(float)(fVar5 + fVar5);
  pfVar4 = (float *)FUN_005fc500(&local_30,&local_2c,&local_28);
  local_40 = *pfVar4;
  local_3c = pfVar4[1];
  local_38 = pfVar4[2];
  local_34 = 0.0;
  fVar5 = (float10)FUN_005fcc30(&local_40);
  if ((float10)_DAT_0080410c <= fVar5) {
    param_1 = (float *)(float)((float10)_DAT_00804108 / SQRT(fVar5));
    FUN_0061a860(&param_1);
  }
  else {
    param_1 = (float *)0x0;
    param_5 = 0.0;
    param_6 = (float *)0x3f800000;
    pfVar4 = (float *)FUN_005fc500(&param_6,&param_5,&param_1);
    local_40 = *pfVar4;
    local_3c = pfVar4[1];
    local_38 = pfVar4[2];
    local_34 = pfVar4[3];
  }
  local_30 = local_40 * (float)param_2;
  local_2c = local_3c * (float)param_2;
  local_24 = 0.0;
  local_28 = local_38 * (float)param_2;
  param_2 = (float *)fVar2;
  FUN_0060fe40(&local_20,&local_30,&param_2);
  *param_7 = local_20;
  param_7[1] = local_1c;
  param_7[2] = local_18;
  param_7[3] = local_14;
  return;
}

