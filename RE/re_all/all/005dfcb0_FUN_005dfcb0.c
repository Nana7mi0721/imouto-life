
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005dfcb0(float param_1,float param_2,float param_3,float *param_4,float *param_5,
                 float *param_6)

{
  float fVar1;
  float fVar2;
  
  fVar2 = (float)_DAT_008023c8;
  if (param_3 + param_2 + param_1 < fVar2) {
    *param_4 = 1.0;
    *param_5 = 1.0;
    *param_6 = 1.0;
    return;
  }
  if (param_1 <= param_2) {
    if (param_2 <= param_3) {
      fVar1 = param_3 - param_1;
      if (fVar1 < fVar2) {
        *param_4 = 1.0;
        *param_5 = 1.0;
        *param_6 = 1.0;
        return;
      }
      *param_4 = 1.0 - fVar1 / param_3;
      *param_5 = 1.0 - (1.0 - (param_2 - param_1) / fVar1) * (fVar1 / param_3);
      *param_6 = 1.0;
      return;
    }
    if (param_1 <= param_3) {
      fVar1 = param_2 - param_1;
      if (fVar2 <= fVar1) {
        *param_4 = 1.0 - fVar1 / param_2;
        *param_5 = 1.0;
        *param_6 = 1.0 - (1.0 - (param_3 - param_1) / fVar1) * (fVar1 / param_2);
        return;
      }
    }
    else {
      fVar1 = param_2 - param_3;
      if (fVar2 <= fVar1) {
        *param_4 = 1.0 - (fVar1 / param_2) * (1.0 - (param_1 - param_3) / fVar1);
        *param_5 = 1.0;
        *param_6 = 1.0 - fVar1 / param_2;
        return;
      }
    }
  }
  else {
    if (param_3 < param_1) {
      if (param_2 <= param_3) {
        fVar1 = param_1 - param_2;
        if (fVar2 <= fVar1) {
          *param_4 = 1.0;
          *param_5 = 1.0 - fVar1 / param_1;
          *param_6 = 1.0 - (1.0 - (param_3 - param_2) / fVar1) * (fVar1 / param_1);
          return;
        }
      }
      else {
        fVar1 = param_1 - param_3;
        if (fVar2 <= fVar1) {
          *param_4 = 1.0;
          *param_5 = 1.0 - (fVar1 / param_1) * (1.0 - (param_2 - param_3) / fVar1);
          *param_6 = 1.0 - fVar1 / param_1;
          return;
        }
      }
      *param_4 = 1.0;
      *param_5 = 1.0;
      *param_6 = 1.0;
      return;
    }
    fVar1 = param_3 - param_2;
    if (fVar2 <= fVar1) {
      *param_4 = 1.0 - (fVar1 / param_3) * (1.0 - (param_1 - param_2) / fVar1);
      *param_5 = 1.0 - fVar1 / param_3;
      *param_6 = 1.0;
      return;
    }
  }
  *param_4 = 1.0;
  *param_5 = 1.0;
  *param_6 = 1.0;
  return;
}

