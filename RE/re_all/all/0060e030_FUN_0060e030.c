
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0060e030(int param_1,uint *param_2,float *param_3,uint param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  
  fVar1 = (*param_3 - *(float *)(param_1 + 0xc)) * *(float *)(param_1 + 0x2c);
  fVar2 = (param_3[1] - *(float *)(param_1 + 0x10)) * *(float *)(param_1 + 0x30);
  fVar3 = (param_3[2] - *(float *)(param_1 + 0x14)) * *(float *)(param_1 + 0x34);
  if (_DAT_007d5344 < fVar1) {
    uVar4 = *(uint *)(param_1 + 8);
    if (fVar1 < (float)uVar4) {
      uVar4 = __ftol();
    }
    uVar4 = *(uint *)(param_1 + 4) & uVar4 | param_4;
  }
  else {
    uVar4 = param_4;
  }
  fVar1 = _DAT_007d5344;
  *param_2 = uVar4;
  if (fVar1 < fVar2) {
    if (fVar2 < (float)*(uint *)(param_1 + 8)) {
      uVar4 = __ftol();
      uVar4 = *(uint *)(param_1 + 4) & uVar4;
    }
    else {
      uVar4 = *(uint *)(param_1 + 4) & *(uint *)(param_1 + 8);
    }
    uVar4 = uVar4 | param_4;
  }
  else {
    uVar4 = param_4;
  }
  fVar1 = _DAT_007d5344;
  param_2[1] = uVar4;
  if (fVar3 <= fVar1) {
    param_2[2] = param_4;
    return;
  }
  if ((float)*(uint *)(param_1 + 8) <= fVar3) {
    param_2[2] = *(uint *)(param_1 + 4) & *(uint *)(param_1 + 8) | param_4;
    return;
  }
  uVar4 = __ftol();
  param_2[2] = *(uint *)(param_1 + 4) & uVar4 | param_4;
  return;
}

