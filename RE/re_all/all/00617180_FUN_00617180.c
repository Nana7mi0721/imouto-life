
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00617180(float *param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  fVar1 = _DAT_0080427c;
  if (_DAT_0080427c < *param_1) {
    fVar1 = *param_1;
    uVar3 = 0;
  }
  if (fVar1 < param_1[1]) {
    fVar1 = param_1[1];
    uVar3 = 1;
  }
  if (fVar1 < param_1[2]) {
    fVar1 = param_1[2];
    uVar3 = 2;
  }
  uVar2 = 3;
  if (param_1[3] <= fVar1) {
    uVar2 = uVar3;
  }
  return uVar2;
}

