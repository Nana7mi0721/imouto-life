
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00652cc0(int param_1,uint param_2,int param_3,int param_4,float *param_5,float *param_6,
                 float *param_7)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)param_2 * _DAT_00804c50;
  if (_DAT_00804c4c <= fVar1) {
    fVar1 = (fVar1 + _DAT_00804c3c) * _DAT_00804c38;
    *param_6 = fVar1 * *(float *)(param_1 + 0x14) * fVar1 * fVar1;
  }
  else {
    fVar1 = fVar1 * *(float *)(param_1 + 0x14) * _DAT_00804c48;
    *param_6 = fVar1;
    fVar1 = (fVar1 / *(float *)(param_1 + 0x14)) * _DAT_00804c44 + _DAT_00804c40;
  }
  fVar2 = (float)param_3 * _DAT_007d592c + fVar1;
  if (_DAT_00804c34 <= fVar2) {
    *param_5 = fVar2 * *(float *)(param_1 + 0x10) * fVar2 * fVar2;
  }
  else {
    *param_5 = (fVar2 - _DAT_00804c30) * *(float *)(param_1 + 0x10) * _DAT_00804c2c;
  }
  fVar1 = fVar1 - (float)param_4 * _DAT_00804c28;
  if (fVar1 < _DAT_00804c34) {
    *param_7 = (fVar1 - _DAT_00804c30) * *(float *)(param_1 + 0x18) * _DAT_00804c2c;
    return;
  }
  *param_7 = fVar1 * *(float *)(param_1 + 0x18) * fVar1 * fVar1;
  return;
}

