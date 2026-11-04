
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005863d0(float param_1,float param_2,float param_3)

{
  float fVar1;
  float10 fVar2;
  
  fVar1 = param_3 * param_3 + param_1 * param_1 + param_2 * param_2;
  if (fVar1 < (float)_DAT_007d5348) {
    return (float10)0.0;
  }
  fVar2 = (float10)FUN_0056d670(fVar1);
  return (float10)(float)fVar2;
}

