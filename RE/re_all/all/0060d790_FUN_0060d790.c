
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0060d790(int param_1,ushort *param_2,float *param_3,ushort param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  ushort uVar4;
  
  fVar1 = (*param_3 - *(float *)(param_1 + 8)) * *(float *)(param_1 + 0x28);
  fVar2 = (param_3[1] - *(float *)(param_1 + 0xc)) * *(float *)(param_1 + 0x2c);
  fVar3 = (param_3[2] - *(float *)(param_1 + 0x10)) * *(float *)(param_1 + 0x30);
  uVar4 = param_4;
  if (_DAT_007d5344 < fVar1) {
    uVar4 = *(ushort *)(param_1 + 6);
    if (fVar1 < (float)uVar4) {
      uVar4 = __ftol();
    }
    uVar4 = *(ushort *)(param_1 + 4) & uVar4 | param_4;
  }
  fVar1 = _DAT_007d5344;
  *param_2 = uVar4;
  uVar4 = param_4;
  if (fVar1 < fVar2) {
    uVar4 = *(ushort *)(param_1 + 6);
    if (fVar2 < (float)uVar4) {
      uVar4 = __ftol();
    }
    uVar4 = *(ushort *)(param_1 + 4) & uVar4 | param_4;
  }
  fVar1 = _DAT_007d5344;
  param_2[1] = uVar4;
  if (fVar1 < fVar3) {
    if (fVar3 < (float)*(ushort *)(param_1 + 6)) {
      uVar4 = __ftol();
      param_2[2] = *(ushort *)(param_1 + 4) & uVar4 | param_4;
      return;
    }
    param_2[2] = *(ushort *)(param_1 + 4) & *(ushort *)(param_1 + 6) | param_4;
    return;
  }
  param_2[2] = param_4;
  return;
}

