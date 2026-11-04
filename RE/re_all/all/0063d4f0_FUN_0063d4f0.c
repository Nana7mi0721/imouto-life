
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0063d4f0(float *param_1,float *param_2)

{
  float10 extraout_ST0;
  float10 fVar1;
  
  if (_DAT_00804108 <= param_1[8]) {
    fVar1 = (float10)fpatan((float10)param_1[1],(float10)param_1[5]);
    param_2[1] = 1.5707964;
    param_2[2] = 0.0;
    *param_2 = (float)fVar1;
    return 0;
  }
  if (_DAT_007d5340 < param_1[8]) {
    fVar1 = (float10)fpatan(-(float10)param_1[9],(float10)param_1[10]);
    *param_2 = (float)fVar1;
    FUN_006c54b0();
    param_2[1] = (float)extraout_ST0;
    fVar1 = (float10)fpatan(-(float10)param_1[4],(float10)*param_1);
    param_2[2] = (float)fVar1;
    return 1;
  }
  fVar1 = (float10)fpatan((float10)param_1[1],(float10)param_1[5]);
  param_2[1] = -1.5707964;
  param_2[2] = 0.0;
  *param_2 = (float)-fVar1;
  return 0;
}

