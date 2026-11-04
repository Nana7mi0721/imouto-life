
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00634bf0(float param_1,float *param_2,float *param_3,float param_4,float param_5)

{
  float fVar1;
  float *pfVar2;
  float10 fVar3;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined1 local_10 [16];
  
  local_50 = param_4 * param_2[1];
  local_4c = param_4 * *param_2;
  param_2 = (float *)(param_4 * param_2[2]);
  FUN_005fc500(&local_4c,&local_50,&param_2);
  local_48 = local_1c + *(float *)((int)param_1 + 0x34);
  local_44 = local_20 + *(float *)((int)param_1 + 0x30);
  param_1 = local_18 + *(float *)((int)param_1 + 0x38);
  FUN_005fc500(&local_44,&local_48,&param_1);
  pfVar2 = param_3;
  *(float *)((int)param_5 + 0x30) = local_30;
  *(float *)((int)param_5 + 0x34) = local_2c;
  *(float *)((int)param_5 + 0x38) = local_28;
  *(float *)((int)param_5 + 0x3c) = local_24;
  fVar3 = (float10)FUN_005fcc30(param_3);
  param_2 = (float *)(float)SQRT(fVar3);
  if ((float10)_DAT_007d97a0 < SQRT(fVar3) * (float10)param_4) {
    param_2 = (float *)(_DAT_007d97a0 / param_4);
  }
  if (_DAT_007d652c <= (float)param_2) {
    fVar3 = (float10)fsin((float10)(float)param_2 * (float10)param_4 * (float10)_DAT_007d589c);
    fVar3 = fVar3 / (float10)(float)param_2;
    param_1 = (float)(fVar3 * (float10)pfVar2[2]);
    param_5 = (float)(fVar3 * (float10)pfVar2[1]);
    param_3 = (float *)(float)(fVar3 * (float10)*pfVar2);
    FUN_005fc500(&param_3,&param_5,&param_1);
  }
  else {
    fVar1 = param_4 * _DAT_007d589c -
            param_4 * param_4 * param_4 * (float)param_2 * (float)param_2 * _DAT_0080480c;
    param_1 = fVar1 * pfVar2[2];
    param_5 = fVar1 * pfVar2[1];
    param_3 = (float *)(fVar1 * *pfVar2);
    FUN_005fc500(&param_3,&param_5,&param_1);
  }
  fVar3 = (float10)fcos((float10)(float)param_2 * (float10)param_4 * (float10)_DAT_007d589c);
  local_14 = (float)fVar3;
  local_40 = local_30;
  local_3c = local_2c;
  local_38 = local_28;
  FUN_0061abb0(&local_30);
  param_4 = ((local_24 * local_14 - local_30 * local_40) - local_2c * local_3c) -
            local_28 * local_38;
  param_2 = (float *)((local_2c * local_40 + local_28 * local_14 + local_24 * local_38) -
                     local_30 * local_3c);
  param_1 = (local_2c * local_14 + local_24 * local_3c + local_30 * local_38) - local_28 * local_40;
  param_5 = (local_24 * local_40 + local_30 * local_14 + local_28 * local_3c) - local_2c * local_38;
  FUN_0061a080(&param_5,&param_1,&param_2,&param_4);
  fVar3 = (float10)FUN_0061a2f0(local_10);
  param_4 = (float)((float10)_DAT_00804108 / SQRT(fVar3));
  FUN_0061a880(&param_4);
  FUN_0061a350(local_10);
  return;
}

