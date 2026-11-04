
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00646980(float param_1,float param_2,float param_3,float param_4,float param_5)

{
  if (param_3 < param_2) {
    return (float10)_DAT_00804108;
  }
  if (param_2 == param_3) {
    return (float10)_DAT_007d5344;
  }
  param_4 = param_4 / param_5;
  if (_DAT_007d5344 <= param_4) {
    if ((param_4 <= _DAT_007d5344) || (param_3 < param_1)) goto LAB_00646a45;
    if (param_3 - param_4 < param_1) {
      return ((float10)param_3 - (float10)param_1) / (float10)param_4;
    }
  }
  else {
    if (param_1 < param_2) {
LAB_00646a45:
      return (float10)_DAT_007d5344;
    }
    if (param_1 < param_2 - param_4) {
      return ((float10)param_2 - (float10)param_1) / (float10)param_4;
    }
  }
  return (float10)_DAT_00804108;
}

