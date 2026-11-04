
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0061a990(undefined4 *param_1,undefined4 *param_2,float param_3,int param_4,float *param_5)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  float local_30 [8];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar1 = _DAT_007d5344;
  param_1[0x16] = param_3;
  if (fVar1 < param_3) {
    param_1[0x10] = *param_2;
    param_1[0x11] = param_2[1];
    param_1[0x12] = param_2[2];
    param_1[0x13] = param_2[3];
    FUN_0061abb0(&local_10);
    fVar1 = param_5[5] + param_5[10] + *param_5;
    if (fVar1 <= _DAT_007d5344) {
      if (param_5[5] <= *param_5) {
        if (param_5[10] <= *param_5) {
          iVar2 = 0;
        }
        else {
          iVar2 = 2;
        }
      }
      else if (param_5[10] <= param_5[5]) {
        iVar2 = 1;
      }
      else {
        iVar2 = 2;
      }
      uVar3 = (iVar2 + 1U) % 3;
      uVar4 = (iVar2 + 2U) % 3;
      fVar1 = SQRT(((param_5[iVar2 * 5] - param_5[uVar3 * 5]) - param_5[uVar4 * 5]) + _DAT_00804108)
      ;
      local_30[iVar2] = fVar1 * _DAT_007d589c;
      fVar1 = _DAT_007d589c / fVar1;
      local_30[3] = (param_5[uVar3 + uVar4 * 4] - param_5[uVar4 + uVar3 * 4]) * fVar1;
      local_30[uVar3] = (param_5[iVar2 + uVar3 * 4] + param_5[uVar3 + iVar2 * 4]) * fVar1;
      local_30[uVar4] = (param_5[iVar2 + uVar4 * 4] + param_5[uVar4 + iVar2 * 4]) * fVar1;
    }
    else {
      local_30[2] = SQRT(fVar1 + _DAT_00804108);
      local_30[3] = local_30[2] * _DAT_007d589c;
      local_30[2] = _DAT_007d589c / local_30[2];
      local_30[0] = (param_5[9] - param_5[6]) * local_30[2];
      local_30[1] = (param_5[2] - param_5[8]) * local_30[2];
      local_30[2] = (param_5[4] - param_5[1]) * local_30[2];
    }
    param_1[8] = *(undefined4 *)(param_4 + 0x30);
    param_1[9] = *(undefined4 *)(param_4 + 0x34);
    param_1[10] = *(undefined4 *)(param_4 + 0x38);
    param_1[0xb] = *(undefined4 *)(param_4 + 0x3c);
    param_1[0xc] = param_5[0xc];
    param_1[0xd] = param_5[0xd];
    param_1[0xe] = param_5[0xe];
    param_1[0xf] = param_5[0xf];
    *param_1 = local_10;
    param_1[1] = local_c;
    param_1[2] = local_8;
    param_1[3] = local_4;
    param_1[4] = local_30[0];
    param_1[5] = local_30[1];
    param_1[6] = local_30[2];
    param_1[7] = local_30[3];
  }
  return;
}

