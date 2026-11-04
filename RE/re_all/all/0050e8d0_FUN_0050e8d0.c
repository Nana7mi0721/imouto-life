
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0050e8d0(double *param_1,double *param_2)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  int local_8;
  int local_4;
  
  fVar2 = (float10)0;
  fVar1 = (float10)_DAT_00a2d7a0;
  fVar3 = (float10)1;
  if ((!NAN(fVar1) && !NAN(fVar2)) && fVar1 < fVar2 != (fVar1 == fVar2)) {
    _DAT_00a2d7a0 = (double)fVar3;
    fVar1 = fVar3;
  }
  if ((float10)_DAT_00a2d7a8 <= fVar2) {
    _DAT_00a2d7a8 = (double)fVar3;
  }
  if (DAT_00a20c40 == 0) {
    if (param_1 != (double *)0x0) {
      *param_1 = (double)fVar3;
    }
    if (param_2 != (double *)0x0) {
      *param_2 = (double)fVar3;
    }
    return fVar3;
  }
  if (((DAT_00a2d804 == 0) || (DAT_00a2d7b0 != 0)) || (DAT_00a2d7bc != 0)) {
    if (param_1 != (double *)0x0) {
      *param_1 = (double)fVar1;
    }
    if (param_2 != (double *)0x0) {
      *param_2 = _DAT_00a2d7a8;
    }
    return (float10)_DAT_00a2d7a0;
  }
  FUN_005167a0(&local_8,&local_4);
  fVar2 = (float10)((DAT_00a2d810 - DAT_00a2d808) + -1) / (float10)local_8;
  fVar3 = (float10)((DAT_00a2d814 - DAT_00a2d80c) + -1) / (float10)local_4;
  if (fVar2 < fVar3) {
    fVar3 = fVar2;
  }
  if (param_1 != (double *)0x0) {
    *param_1 = (double)fVar3;
  }
  if (param_2 == (double *)0x0) {
    return fVar3;
  }
  *param_2 = (double)fVar3;
  return fVar3;
}

