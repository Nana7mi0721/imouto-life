
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * __thiscall FUN_00611c90(int *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  float10 fVar11;
  float local_d4;
  float local_d0;
  float local_cc [7];
  int local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  undefined4 local_a0;
  float local_9c [4];
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c [4];
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  float local_10;
  float local_c;
  float local_8;
  
  switch(param_1[1]) {
  case 0:
    fVar3 = (float)param_1[9];
    if (param_3[2] < _DAT_007d5344) {
      fVar3 = -fVar3;
    }
    fVar1 = (float)param_1[8];
    if (param_3[1] < _DAT_007d5344) {
      fVar1 = -fVar1;
    }
    fVar2 = (float)param_1[7];
    if (*param_3 < _DAT_007d5344) {
      fVar2 = -fVar2;
    }
    *param_2 = fVar2;
    param_2[3] = 0.0;
    param_2[1] = fVar1;
    param_2[2] = fVar3;
    return param_2;
  case 1:
    fVar3 = *param_3;
    fVar1 = param_3[1];
    fVar2 = param_3[2];
    fVar5 = fVar3 * (float)param_1[0xd] + fVar2 * (float)param_1[0xf] + fVar1 * (float)param_1[0xe];
    fVar4 = fVar3 * (float)param_1[0x11] +
            fVar2 * (float)param_1[0x13] + fVar1 * (float)param_1[0x12];
    fVar3 = fVar3 * (float)param_1[0x15] +
            fVar2 * (float)param_1[0x17] + fVar1 * (float)param_1[0x16];
    if (fVar4 <= fVar5) {
      if (fVar3 <= fVar5) {
        iVar6 = 0;
      }
      else {
        iVar6 = 2;
      }
    }
    else if (fVar3 <= fVar4) {
      iVar6 = 1;
    }
    else {
      iVar6 = 2;
    }
    pfVar9 = (float *)(param_1 + 0xd + iVar6 * 4);
    fVar3 = pfVar9[1];
    fVar1 = pfVar9[2];
    *param_2 = *pfVar9;
    param_2[1] = fVar3;
    param_2[2] = fVar1;
    param_2[3] = 0.0;
    return param_2;
  default:
    (**(code **)(*param_1 + 0x30))(param_2,param_3);
    return param_2;
  case 4:
    iVar6 = param_1[0x19];
    iVar7 = param_1[0x17];
    local_80 = (float)param_1[5] * param_3[2];
    local_8c = (float)param_1[4] * param_3[1];
    local_84 = (float)param_1[3] * *param_3;
    FUN_005fc500(&local_84,&local_8c,&local_80);
    iVar8 = -1;
    iVar10 = 0;
    local_d0 = -1e+18;
    if (0 < iVar7) {
      pfVar9 = (float *)(iVar6 + 4);
      do {
        fVar3 = local_cc[5] * *pfVar9 + local_cc[4] * pfVar9[-1] + local_cc[6] * pfVar9[1];
        if (local_d0 < fVar3) {
          iVar8 = iVar10;
          local_d0 = fVar3;
        }
        iVar10 = iVar10 + 1;
        pfVar9 = pfVar9 + 4;
      } while (iVar10 < iVar7);
    }
    FUN_005fc560(&local_6c,iVar8 * 0x10 + iVar6,param_1 + 3);
    *param_2 = local_6c;
    param_2[1] = local_68;
    param_2[2] = local_64;
    param_2[3] = local_60;
    return param_2;
  case 5:
    local_d0 = (float)param_1[0x16];
    iVar6 = param_1[0x17];
    local_80 = (float)param_1[5] * param_3[2];
    local_8c = (float)param_1[4] * param_3[1];
    local_84 = *param_3 * (float)param_1[3];
    FUN_005fc500(&local_84,&local_8c,&local_80);
    iVar7 = -1;
    iVar8 = 0;
    local_88 = -1e+18;
    if (0 < iVar6) {
      local_d4 = local_d0;
      do {
        fVar11 = (float10)FUN_005fcc30(local_d4);
        if ((float10)local_88 < fVar11) {
          local_88 = (float)fVar11;
          iVar7 = iVar8;
        }
        iVar8 = iVar8 + 1;
        local_d4 = (float)((int)local_d4 + 0x10);
      } while (iVar8 < iVar6);
    }
    FUN_005fc560(&local_6c,iVar7 * 0x10 + (int)local_d0,param_1 + 3);
    *param_2 = local_6c;
    param_2[1] = local_68;
    param_2[2] = local_64;
    param_2[3] = local_60;
    return param_2;
  case 8:
    *param_2 = 0.0;
    param_2[1] = 0.0;
    param_2[2] = 0.0;
    param_2[3] = 0.0;
    return param_2;
  case 10:
    iVar6 = param_1[0xd];
    local_cc[3] = 0.0;
    local_9c[0] = 0.0;
    local_cc[0] = *param_3;
    local_cc[1] = param_3[1];
    local_cc[2] = param_3[2];
    local_54 = (float)param_1[iVar6 + 7];
    local_9c[1] = 0.0;
    local_9c[2] = 0.0;
    local_88 = -1e+18;
    local_d4 = (float)param_1[(iVar6 + 2) % 3 + 7];
    local_a0 = 0;
    fVar3 = local_cc[1] * local_cc[1] + local_cc[2] * local_cc[2] + local_cc[0] * local_cc[0];
    if (_DAT_008298b0 <= fVar3) {
      local_a4 = _DAT_00804108 / SQRT(fVar3);
      local_ac = local_cc[0] * local_a4;
      local_a8 = local_cc[1] * local_a4;
      local_a4 = local_cc[2] * local_a4;
    }
    else {
      local_ac = 1.0;
      local_a8 = 0.0;
      local_a4 = 0.0;
    }
    local_7c[0] = 0.0;
    local_7c[1] = 0.0;
    local_7c[2] = 0.0;
    local_7c[iVar6] = local_54;
    local_cc[6] = (float)param_1[0xb];
    local_cc[4] = local_ac * local_cc[6];
    local_cc[5] = local_a8 * local_cc[6];
    local_cc[6] = local_a4 * local_cc[6];
    local_68 = local_a8 * (float)param_1[4];
    local_64 = local_a4 * (float)param_1[5];
    local_d0 = local_7c[2] + local_64 * local_d4;
    local_4c = local_7c[1] + local_68 * local_d4;
    local_5c = local_ac * (float)param_1[3] * local_d4 + local_7c[0];
    FUN_005fc500(&local_5c,&local_4c,&local_d0);
    local_48 = local_38 - local_cc[6];
    local_58 = local_3c - local_cc[5];
    local_50 = local_40 - local_cc[4];
    FUN_005fc500(&local_50,&local_58,&local_48);
    fVar3 = local_cc[1] * local_a8 + local_cc[2] * local_a4 + local_cc[0] * local_ac;
    if (_DAT_0080427c < fVar3) {
      local_9c[0] = local_cc[0];
      local_9c[1] = local_cc[1];
      local_9c[2] = local_cc[2];
      local_9c[3] = local_cc[3];
      local_88 = fVar3;
    }
    local_cc[4] = 0.0;
    local_cc[5] = 0.0;
    local_cc[6] = 0.0;
    local_cc[iVar6 + 4] = -local_54;
    local_64 = (float)param_1[0xb];
    local_6c = local_ac * local_64;
    local_68 = local_a8 * local_64;
    local_64 = local_a4 * local_64;
    local_54 = local_a4 * (float)param_1[5];
    local_50 = local_a8 * (float)param_1[4];
    local_58 = local_ac * (float)param_1[3];
    FUN_005fc500(&local_58,&local_50,&local_54);
    local_48 = local_18 * local_d4;
    local_5c = local_1c * local_d4;
    local_4c = local_20 * local_d4;
    FUN_005fc500(&local_4c,&local_5c,&local_48);
    local_d0 = local_28 + local_cc[6];
    local_d4 = local_2c + local_cc[5];
    local_44 = local_30 + local_cc[4];
    FUN_005fc500(&local_44,&local_d4,&local_d0);
    local_84 = local_8 - local_64;
    local_8c = local_c - local_68;
    local_80 = local_10 - local_6c;
    FUN_005fc500(&local_80,&local_8c,&local_84);
    if (local_88 < local_7c[1] * local_a8 + local_7c[2] * local_a4 + local_7c[0] * local_ac) {
      local_9c[0] = local_7c[0];
      local_9c[1] = local_7c[1];
      local_9c[2] = local_7c[2];
    }
    *param_2 = local_9c[0];
    param_2[1] = local_9c[1];
    param_2[2] = local_9c[2];
    param_2[3] = 0.0;
    return param_2;
  case 0xd:
    break;
  }
  iVar6 = param_1[0xd];
  iVar10 = 2;
  local_cc[4] = (float)param_1[7];
  local_cc[5] = (float)param_1[8];
  local_cc[6] = (float)param_1[9];
  local_b0 = param_1[10];
  local_cc[1] = param_3[1];
  local_cc[2] = param_3[2];
  iVar8 = 0;
  local_cc[0] = *param_3;
  iVar7 = 1;
  if (iVar6 == 0) {
    iVar7 = 1;
    iVar8 = 0;
  }
  else {
    if (iVar6 != 1) {
      if (iVar6 == 2) {
        iVar8 = 2;
        iVar7 = 0;
        iVar10 = 1;
      }
      goto LAB_00611e9b;
    }
    iVar7 = 0;
    iVar8 = 1;
  }
  iVar10 = 2;
LAB_00611e9b:
  fVar3 = local_cc[iVar6 + 4];
  fVar1 = SQRT(local_cc[iVar10] * local_cc[iVar10] + local_cc[iVar7] * local_cc[iVar7]);
  if (fVar1 == _DAT_007d5344) {
    local_9c[iVar7] = local_cc[iVar7 + 4];
    if (local_cc[iVar8] < (float)_DAT_007d0a60) {
      fVar3 = -fVar3;
    }
    local_9c[iVar8] = fVar3;
    local_9c[iVar10] = 0.0;
  }
  else {
    fVar1 = local_cc[iVar7 + 4] / fVar1;
    local_9c[iVar7] = fVar1 * local_cc[iVar7];
    if (local_cc[iVar8] < (float)_DAT_007d0a60) {
      fVar3 = -fVar3;
    }
    local_9c[iVar8] = fVar3;
    local_9c[iVar10] = fVar1 * local_cc[iVar10];
  }
  *param_2 = local_9c[0];
  param_2[3] = 0.0;
  param_2[1] = local_9c[1];
  param_2[2] = local_9c[2];
  return param_2;
}

