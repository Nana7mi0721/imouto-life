
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00645190(int param_1,undefined4 *param_2,float param_3,float param_4)

{
  float10 fVar1;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_10 [16];
  
  fVar1 = (float10)fcos((float10)param_3);
  local_2c = (float)fVar1;
  fVar1 = (float10)fsin((float10)param_3);
  local_28 = (float)fVar1;
  fVar1 = (float10)*(float *)(param_1 + 0x1e0);
  if ((float)_DAT_00804920 < ABS(local_2c)) {
    fVar1 = ((float10)local_28 * (float10)local_28) / ((float10)local_2c * (float10)local_2c);
    fVar1 = SQRT((fVar1 + (float10)_DAT_00804108) /
                 (fVar1 / ((float10)*(float *)(param_1 + 0x1e0) *
                          (float10)*(float *)(param_1 + 0x1e0)) +
                 (float10)_DAT_00804108 /
                 ((float10)*(float *)(param_1 + 0x1e4) * (float10)*(float *)(param_1 + 0x1e4))));
  }
  local_28 = -local_28;
  local_30 = 0.0;
  local_24 = 0;
  param_3 = (float)(fVar1 * (float10)_DAT_007d589c);
  fVar1 = (float10)fsin(fVar1 * (float10)_DAT_007d589c);
  local_48 = (float)fVar1;
  fVar1 = (float10)FUN_005fcc30(&local_30);
  fVar1 = (float10)local_48 / SQRT(fVar1);
  local_40 = (float)(fVar1 * (float10)local_30);
  local_3c = (float)((float10)local_2c * fVar1);
  local_38 = (float)(fVar1 * (float10)local_28);
  fVar1 = (float10)fcos((float10)param_3);
  local_34 = (float)fVar1;
  param_3 = (-(local_40 * param_4) - _DAT_007d5344) - _DAT_007d5344;
  local_48 = (_DAT_007d5344 + _DAT_007d5344) - local_3c * param_4;
  local_44 = (local_38 * param_4 + _DAT_007d5344) - _DAT_007d5344;
  param_4 = (local_34 * param_4 + _DAT_007d5344) - _DAT_007d5344;
  FUN_0061a080(&param_4,&local_44,&local_48,&param_3);
  param_4 = -local_38;
  param_3 = -local_3c;
  local_44 = -local_40;
  FUN_0061a080(&local_44,&param_3,&param_4,&local_34);
  FUN_00646660(local_10);
  *param_2 = local_20;
  param_2[1] = local_1c;
  param_2[2] = local_18;
  param_2[3] = 0;
  return;
}

