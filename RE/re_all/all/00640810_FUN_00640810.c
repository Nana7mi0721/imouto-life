
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00640810(float param_1,float param_2,float param_3)

{
  float10 fVar1;
  float10 fVar2;
  
  if (param_2 < param_3) {
    if (param_1 < param_2) {
      fVar1 = (float10)FUN_006c57aa();
      if ((float10)_DAT_00802ec4 <= fVar1) {
        if ((float10)_DAT_00802ebc < fVar1) {
          fVar1 = fVar1 - (float10)_DAT_00802ec0;
        }
      }
      else {
        fVar1 = fVar1 + (float10)_DAT_00802ec0;
      }
      fVar2 = (float10)FUN_006c57aa();
      if ((float10)_DAT_00802ec4 <= fVar2) {
        if ((float10)_DAT_00802ebc < fVar2) {
          fVar2 = fVar2 - (float10)_DAT_00802ec0;
        }
      }
      else {
        fVar2 = fVar2 + (float10)_DAT_00802ec0;
      }
      if (ABS(fVar2) <= (float10)(float)fVar1) {
        return (float10)param_1 + (float10)_DAT_00802ec0;
      }
    }
    else if (param_3 < param_1) {
      fVar1 = (float10)FUN_006c57aa();
      if ((float10)_DAT_00802ec4 <= fVar1) {
        if ((float10)_DAT_00802ebc < fVar1) {
          fVar1 = fVar1 - (float10)_DAT_00802ec0;
        }
      }
      else {
        fVar1 = fVar1 + (float10)_DAT_00802ec0;
      }
      fVar2 = (float10)FUN_006c57aa();
      if ((float10)_DAT_00802ec4 <= fVar2) {
        if ((float10)_DAT_00802ebc < fVar2) {
          fVar2 = fVar2 - (float10)_DAT_00802ec0;
        }
      }
      else {
        fVar2 = fVar2 + (float10)_DAT_00802ec0;
      }
      if (ABS(fVar2) < (float10)(float)fVar1) {
        return (float10)param_1 - (float10)_DAT_00802ec0;
      }
    }
  }
  return (float10)param_1;
}

