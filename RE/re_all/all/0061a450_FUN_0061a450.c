
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0061a450(float *param_1,float *param_2)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  float local_20 [8];
  
  fVar1 = param_1[5] + *param_1 + param_1[10];
  if (fVar1 <= _DAT_007d5344) {
    if (param_1[5] <= *param_1) {
      if (param_1[10] <= *param_1) {
        iVar4 = 0;
      }
      else {
        iVar4 = 2;
      }
    }
    else if (param_1[10] <= param_1[5]) {
      iVar4 = 1;
    }
    else {
      iVar4 = 2;
    }
    uVar2 = (iVar4 + 1U) % 3;
    uVar3 = (iVar4 + 2U) % 3;
    fVar1 = SQRT(((param_1[iVar4 * 5] - param_1[uVar2 * 5]) - param_1[uVar3 * 5]) + _DAT_00804108);
    local_20[iVar4] = fVar1 * _DAT_007d589c;
    fVar1 = _DAT_007d589c / fVar1;
    local_20[3] = (param_1[uVar2 + uVar3 * 4] - param_1[uVar3 + uVar2 * 4]) * fVar1;
    local_20[uVar2] = (param_1[iVar4 + uVar2 * 4] + param_1[uVar2 + iVar4 * 4]) * fVar1;
    local_20[uVar3] = (param_1[iVar4 + uVar3 * 4] + param_1[uVar3 + iVar4 * 4]) * fVar1;
  }
  else {
    fVar1 = SQRT(fVar1 + _DAT_00804108);
    local_20[3] = fVar1 * _DAT_007d589c;
    fVar1 = _DAT_007d589c / fVar1;
    local_20[0] = (param_1[9] - param_1[6]) * fVar1;
    local_20[1] = (param_1[2] - param_1[8]) * fVar1;
    local_20[2] = (param_1[4] - param_1[1]) * fVar1;
  }
  *param_2 = local_20[0];
  param_2[1] = local_20[1];
  param_2[2] = local_20[2];
  param_2[3] = local_20[3];
  return;
}

