
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0063cd70(float *param_1,undefined4 param_2)

{
  float fVar1;
  float10 fVar2;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  local_10 = param_1[5] * param_1[10] - param_1[9] * param_1[6];
  local_20 = param_1[6] * param_1[8] - param_1[10] * param_1[4];
  local_2c = param_1[9] * param_1[4] - param_1[5] * param_1[8];
  fVar1 = _DAT_00804108 / (local_2c * param_1[2] + local_10 * *param_1 + local_20 * param_1[1]);
  local_34 = (param_1[5] * *param_1 - param_1[1] * param_1[4]) * fVar1;
  local_30 = (param_1[1] * param_1[8] - param_1[9] * *param_1) * fVar1;
  local_2c = local_2c * fVar1;
  local_28 = (param_1[4] * param_1[2] - param_1[6] * *param_1) * fVar1;
  local_24 = (*param_1 * param_1[10] - param_1[8] * param_1[2]) * fVar1;
  local_20 = local_20 * fVar1;
  local_1c = (param_1[6] * param_1[1] - param_1[5] * param_1[2]) * fVar1;
  fVar2 = (float10)FUN_0063cea0(0,2,2,1);
  local_18 = (float)(fVar2 * (float10)fVar1);
  local_14 = local_10 * fVar1;
  FUN_005fcc50(&local_14,&local_18,&local_1c,&local_20,&local_24,&local_28,&local_2c,&local_30,
               &local_34);
  return param_2;
}

