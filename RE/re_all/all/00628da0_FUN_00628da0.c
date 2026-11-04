
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00628da0(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                float *param_6,float *param_7,float *param_8,uint *param_9,float *param_10,
                undefined4 param_11,undefined4 param_12,int *param_13)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float *pfVar12;
  int iVar13;
  float *pfVar14;
  float *pfVar15;
  float *pfVar16;
  float *pfVar17;
  float *pfVar18;
  int iVar19;
  float *pfVar20;
  bool bVar21;
  float *local_174;
  float *local_170;
  float local_16c;
  float *local_168;
  float local_164;
  float *local_160;
  uint local_15c;
  float *local_158;
  float local_154;
  float local_150;
  float local_14c [8];
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float *local_114;
  float *local_110;
  float local_10c;
  float *local_108;
  float *local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4 [4];
  float local_e4;
  float local_e0 [5];
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0 [8];
  float local_a0 [16];
  float local_60 [24];
  
  local_170 = (float *)(param_4[2] - param_1[2]);
  local_14c[4] = 0.0;
  local_14c[5] = 0.0;
  local_14c[6] = 0.0;
  local_158 = (float *)(param_4[1] - param_1[1]);
  local_174 = (float *)0x0;
  local_168 = (float *)(*param_4 - *param_1);
  FUN_005fc500(&local_168,&local_158,&local_170);
  pfVar15 = param_2 + 1;
  pfVar12 = param_2 + 2;
  local_e0[0] = local_14c[1] * param_2[4] + local_14c[2] * param_2[8] + local_14c[0] * *param_2;
  local_e0[1] = local_14c[0] * *pfVar15 + local_14c[2] * param_2[9] + local_14c[1] * param_2[5];
  local_e0[2] = local_14c[0] * *pfVar12 + local_14c[2] * param_2[10] + local_14c[1] * param_2[6];
  local_c0[0] = *param_3 * _DAT_007d589c;
  local_c0[1] = param_3[1] * _DAT_007d589c;
  local_c0[2] = param_3[2] * _DAT_007d589c;
  local_f4[0] = *param_6 * _DAT_007d589c;
  local_f4[1] = param_6[1] * _DAT_007d589c;
  local_f4[2] = param_6[2] * _DAT_007d589c;
  pfVar17 = param_5 + 1;
  pfVar14 = param_5 + 2;
  local_f8 = param_5[4] * param_2[4] + param_2[8] * param_5[8] + *param_2 * *param_5;
  local_100 = *pfVar17 * *param_2 + param_5[5] * param_2[4] + param_5[9] * param_2[8];
  local_fc = *pfVar14 * *param_2 + param_5[6] * param_2[4] + param_5[10] * param_2[8];
  local_110 = (float *)(*param_5 * *pfVar15 + param_2[5] * param_5[4] + param_2[9] * param_5[8]);
  local_118 = *pfVar17 * *pfVar15 + param_2[5] * param_5[5] + param_2[9] * param_5[9];
  local_120 = *pfVar15 * *pfVar14 + param_2[5] * param_5[6] + param_2[9] * param_5[10];
  local_e4 = *pfVar12 * *param_5 + param_2[6] * param_5[4] + param_2[10] * param_5[8];
  local_10c = *pfVar12 * *pfVar17 + param_2[6] * param_5[5] + param_2[10] * param_5[9];
  local_164 = -3.4028235e+38;
  local_104 = (float *)(*pfVar14 * *pfVar12 + param_2[6] * param_5[6] + param_2[10] * param_5[10]);
  local_114 = (float *)ABS(local_f8);
  local_11c = ABS(local_100);
  local_168 = (float *)ABS(local_fc);
  local_108 = (float *)ABS((float)local_110);
  local_124 = ABS(local_118);
  local_160 = (float *)ABS(local_120);
  local_128 = ABS(local_e4);
  local_150 = ABS(local_10c);
  local_12c = ABS((float)local_104);
  fVar6 = ABS(local_e0[0]) -
          ((float)local_114 * local_f4[0] + local_11c * local_f4[1] + (float)local_168 * local_f4[2]
          + local_c0[0]);
  if (_DAT_007d5344 < fVar6) {
    return 0;
  }
  bVar21 = _DAT_007d8c08 < fVar6;
  if (bVar21) {
    local_174 = param_2;
    local_164 = fVar6;
  }
  bVar7 = bVar21 && local_e0[0] < _DAT_007d5344;
  local_15c = (uint)bVar21;
  fVar6 = ABS(local_e0[1]) -
          ((float)local_108 * local_f4[0] + local_124 * local_f4[1] + (float)local_160 * local_f4[2]
          + local_c0[1]);
  if (_DAT_007d5344 < fVar6) {
    return 0;
  }
  if (local_164 < fVar6) {
    bVar7 = local_e0[1] < _DAT_007d5344;
    local_15c = 2;
    local_174 = pfVar15;
    local_164 = fVar6;
  }
  fVar6 = ABS(local_e0[2]) -
          (local_128 * local_f4[0] + local_150 * local_f4[1] + local_12c * local_f4[2] + local_c0[2]
          );
  if (_DAT_007d5344 < fVar6) {
    return 0;
  }
  if (local_164 < fVar6) {
    bVar7 = local_e0[2] < _DAT_007d5344;
    local_15c = 3;
    local_174 = pfVar12;
    local_164 = fVar6;
  }
  fVar6 = local_14c[0] * *param_5 + local_14c[2] * param_5[8] + local_14c[1] * param_5[4];
  fVar1 = ABS(fVar6) -
          ((float)local_114 * local_c0[0] + (float)local_108 * local_c0[1] + local_128 * local_c0[2]
          + local_f4[0]);
  if (_DAT_007d5344 < fVar1) {
    return 0;
  }
  if (local_164 < fVar1) {
    local_174 = param_5;
    bVar7 = fVar6 < _DAT_007d5344;
    local_15c = 4;
    local_164 = fVar1;
  }
  fVar6 = ABS(local_14c[0] * *pfVar17 + local_14c[2] * param_5[9] + local_14c[1] * param_5[5]) -
          (local_11c * local_c0[0] + local_124 * local_c0[1] + local_150 * local_c0[2] + local_f4[1]
          );
  if (_DAT_007d5344 < fVar6) {
    return 0;
  }
  if (local_164 < fVar6) {
    bVar7 = local_14c[0] * *pfVar17 + local_14c[2] * param_5[9] + local_14c[1] * param_5[5] <
            _DAT_007d5344;
    local_15c = 5;
    local_174 = pfVar17;
    local_164 = fVar6;
  }
  fVar6 = ABS(local_14c[0] * *pfVar14 + local_14c[2] * param_5[10] + local_14c[1] * param_5[6]) -
          ((float)local_168 * local_c0[0] + (float)local_160 * local_c0[1] + local_12c * local_c0[2]
          + local_f4[2]);
  if (_DAT_007d5344 < fVar6) {
    return 0;
  }
  if (local_164 < fVar6) {
    local_174 = pfVar14;
    local_164 = fVar6;
    if (_DAT_007d5344 <=
        local_14c[0] * *pfVar14 + local_14c[2] * param_5[10] + local_14c[1] * param_5[6]) {
      bVar7 = false;
      local_15c = 6;
    }
    else {
      bVar7 = true;
      local_15c = 6;
    }
  }
  fVar6 = ABS(local_e0[2] * (float)local_110 - local_e0[1] * local_e4) -
          ((float)local_108 * local_c0[2] +
          local_128 * local_c0[1] + (float)local_168 * local_f4[1] + local_11c * local_f4[2]);
  if (_DAT_007d5344 < fVar6) {
    return 0;
  }
  fVar1 = -local_e4;
  fVar8 = SQRT((float)local_110 * (float)local_110 + fVar1 * fVar1);
  if ((_DAT_007d5344 < fVar8) && (fVar6 = fVar6 / fVar8, local_164 < fVar6 * _DAT_008046ec)) {
    local_174 = (float *)0x0;
    local_14c[4] = _DAT_007d5344 / fVar8;
    local_14c[5] = fVar1 / fVar8;
    local_14c[6] = (float)local_110 / fVar8;
    local_164 = fVar6;
    if (_DAT_007d5344 <= local_e0[2] * (float)local_110 - local_e0[1] * local_e4) {
      bVar7 = false;
      local_15c = 7;
    }
    else {
      bVar7 = true;
      local_15c = 7;
    }
  }
  fVar6 = ABS(local_e0[2] * local_118 - local_e0[1] * local_10c) -
          (local_124 * local_c0[2] +
          local_150 * local_c0[1] + (float)local_168 * local_f4[0] + (float)local_114 * local_f4[2])
  ;
  if (_DAT_007d5344 < fVar6) {
    return 0;
  }
  fVar1 = -local_10c;
  fVar8 = SQRT(local_118 * local_118 + fVar1 * fVar1);
  if ((_DAT_007d5344 < fVar8) && (fVar6 = fVar6 / fVar8, local_164 < fVar6 * _DAT_008046ec)) {
    local_174 = (float *)0x0;
    local_14c[4] = _DAT_007d5344 / fVar8;
    local_14c[5] = fVar1 / fVar8;
    local_14c[6] = local_118 / fVar8;
    local_164 = fVar6;
    if (_DAT_007d5344 <= local_e0[2] * local_118 - local_e0[1] * local_10c) {
      bVar7 = false;
      local_15c = 8;
    }
    else {
      bVar7 = true;
      local_15c = 8;
    }
  }
  fVar6 = ABS(local_e0[2] * local_120 - local_e0[1] * (float)local_104) -
          (local_11c * local_f4[0] +
          (float)local_160 * local_c0[2] + local_12c * local_c0[1] + (float)local_114 * local_f4[1])
  ;
  if (_DAT_007d5344 < fVar6) {
    return 0;
  }
  fVar1 = -(float)local_104;
  fVar8 = SQRT(local_120 * local_120 + fVar1 * fVar1);
  if ((_DAT_007d5344 < fVar8) && (fVar6 = fVar6 / fVar8, local_164 < fVar6 * _DAT_008046ec)) {
    local_174 = (float *)0x0;
    local_14c[4] = _DAT_007d5344 / fVar8;
    local_14c[5] = fVar1 / fVar8;
    local_14c[6] = local_120 / fVar8;
    local_164 = fVar6;
    if (_DAT_007d5344 <= local_e0[2] * local_120 - local_e0[1] * (float)local_104) {
      bVar7 = false;
      local_15c = 9;
    }
    else {
      bVar7 = true;
      local_15c = 9;
    }
  }
  fVar6 = ABS(local_e0[0] * local_e4 - local_e0[2] * local_f8) -
          ((float)local_114 * local_c0[2] +
          local_128 * local_c0[0] + (float)local_160 * local_f4[1] + local_124 * local_f4[2]);
  if (_DAT_007d5344 < fVar6) {
    return 0;
  }
  fVar1 = -local_f8;
  fVar8 = SQRT(local_e4 * local_e4 + fVar1 * fVar1);
  if ((_DAT_007d5344 < fVar8) && (fVar6 = fVar6 / fVar8, local_164 < fVar6 * _DAT_008046ec)) {
    local_174 = (float *)0x0;
    local_14c[4] = local_e4 / fVar8;
    local_14c[5] = _DAT_007d5344 / fVar8;
    local_14c[6] = fVar1 / fVar8;
    local_164 = fVar6;
    if (_DAT_007d5344 <= local_e0[0] * local_e4 - local_e0[2] * local_f8) {
      bVar7 = false;
      local_15c = 10;
    }
    else {
      bVar7 = true;
      local_15c = 10;
    }
  }
  fVar6 = ABS(local_e0[0] * local_10c - local_e0[2] * local_100) -
          (local_11c * local_c0[2] +
          local_150 * local_c0[0] + (float)local_160 * local_f4[0] + (float)local_108 * local_f4[2])
  ;
  if (_DAT_007d5344 < fVar6) {
    return 0;
  }
  fVar1 = -local_100;
  fVar8 = SQRT(local_10c * local_10c + fVar1 * fVar1);
  if ((_DAT_007d5344 < fVar8) && (fVar6 = fVar6 / fVar8, local_164 < fVar6 * _DAT_008046ec)) {
    local_174 = (float *)0x0;
    local_14c[4] = local_10c / fVar8;
    local_14c[5] = _DAT_007d5344 / fVar8;
    local_14c[6] = fVar1 / fVar8;
    local_164 = fVar6;
    if (_DAT_007d5344 <= local_e0[0] * local_10c - local_e0[2] * local_100) {
      bVar7 = false;
      local_15c = 0xb;
    }
    else {
      bVar7 = true;
      local_15c = 0xb;
    }
  }
  fVar6 = ABS(local_e0[0] * (float)local_104 - local_e0[2] * local_fc) -
          ((float)local_168 * local_c0[2] +
          local_12c * local_c0[0] + local_124 * local_f4[0] + (float)local_108 * local_f4[1]);
  if (_DAT_007d5344 < fVar6) {
    return 0;
  }
  fVar1 = -local_fc;
  fVar8 = SQRT(fVar1 * fVar1 + (float)local_104 * (float)local_104);
  if ((_DAT_007d5344 < fVar8) && (fVar6 = fVar6 / fVar8, local_164 < fVar6 * _DAT_008046ec)) {
    local_174 = (float *)0x0;
    local_14c[4] = (float)local_104 / fVar8;
    local_14c[5] = _DAT_007d5344 / fVar8;
    local_14c[6] = fVar1 / fVar8;
    local_164 = fVar6;
    if (_DAT_007d5344 <= local_e0[0] * (float)local_104 - local_e0[2] * local_fc) {
      bVar7 = false;
      local_15c = 0xc;
    }
    else {
      bVar7 = true;
      local_15c = 0xc;
    }
  }
  fVar6 = ABS(local_e0[1] * local_f8 - local_e0[0] * (float)local_110) -
          ((float)local_114 * local_c0[1] +
          (float)local_108 * local_c0[0] + local_12c * local_f4[1] + local_150 * local_f4[2]);
  if (_DAT_007d5344 < fVar6) {
    return 0;
  }
  fVar1 = -(float)local_110;
  fVar8 = SQRT(fVar1 * fVar1 + local_f8 * local_f8);
  if ((_DAT_007d5344 < fVar8) && (fVar6 = fVar6 / fVar8, local_164 < fVar6 * _DAT_008046ec)) {
    local_174 = (float *)0x0;
    local_14c[4] = fVar1 / fVar8;
    local_14c[5] = local_f8 / fVar8;
    local_14c[6] = _DAT_007d5344 / fVar8;
    local_164 = fVar6;
    if (_DAT_007d5344 <= local_e0[1] * local_f8 - local_e0[0] * (float)local_110) {
      bVar7 = false;
      local_15c = 0xd;
    }
    else {
      bVar7 = true;
      local_15c = 0xd;
    }
  }
  fVar6 = ABS(local_e0[1] * local_100 - local_e0[0] * local_118) -
          (local_11c * local_c0[1] +
          local_124 * local_c0[0] + local_12c * local_f4[0] + local_128 * local_f4[2]);
  if (_DAT_007d5344 < fVar6) {
    return 0;
  }
  fVar1 = -local_118;
  fVar8 = SQRT(local_100 * local_100 + fVar1 * fVar1);
  if ((_DAT_007d5344 < fVar8) && (fVar6 = fVar6 / fVar8, local_164 < fVar6 * _DAT_008046ec)) {
    local_174 = (float *)0x0;
    local_14c[4] = fVar1 / fVar8;
    local_14c[5] = local_100 / fVar8;
    local_14c[6] = _DAT_007d5344 / fVar8;
    local_164 = fVar6;
    if (_DAT_007d5344 <= local_e0[1] * local_100 - local_e0[0] * local_118) {
      bVar7 = false;
      local_15c = 0xe;
    }
    else {
      bVar7 = true;
      local_15c = 0xe;
    }
  }
  local_158 = (float *)(local_e0[0] * local_120);
  local_16c = ABS(local_e0[1] * local_fc - (float)local_158) -
              ((float)local_168 * local_c0[1] +
              (float)local_160 * local_c0[0] + local_150 * local_f4[0] + local_128 * local_f4[1]);
  if (_DAT_007d5344 < local_16c) {
    return 0;
  }
  fVar6 = -local_120;
  fVar1 = SQRT(local_fc * local_fc + fVar6 * fVar6);
  if ((fVar1 <= _DAT_007d5344) || ((local_16c / fVar1) * _DAT_008046ec <= local_164)) {
    if (local_15c == 0) {
      return 0;
    }
    if (local_174 == (float *)0x0) goto LAB_00629eda;
    *param_7 = *local_174;
    param_7[1] = local_174[4];
    param_7[2] = local_174[8];
  }
  else {
    local_14c[4] = fVar6 / fVar1;
    local_14c[5] = local_fc / fVar1;
    local_14c[6] = _DAT_007d5344 / fVar1;
    bVar7 = local_e0[1] * local_fc - (float)local_158 < _DAT_007d5344;
    local_15c = 0xf;
    local_164 = local_16c / fVar1;
LAB_00629eda:
    *param_7 = local_14c[6] * *pfVar12 + local_14c[4] * *param_2 + local_14c[5] * *pfVar15;
    param_7[1] = local_14c[4] * param_2[4] + local_14c[5] * param_2[5] + local_14c[6] * param_2[6];
    param_7[2] = local_14c[4] * param_2[8] + local_14c[5] * param_2[9] + local_14c[6] * param_2[10];
  }
  if (bVar7) {
    *param_7 = -*param_7;
    param_7[1] = -param_7[1];
    param_7[2] = -param_7[2];
  }
  *param_8 = -local_164;
  if (6 < local_15c) {
    local_170 = (float *)0x3;
    local_14c[4] = *param_1;
    local_14c[5] = param_1[1];
    local_14c[6] = param_1[2];
    pfVar15 = param_2;
    do {
      if (param_7[1] * pfVar15[4] + *param_7 * *pfVar15 + pfVar15[8] * param_7[2] <= _DAT_007d5344)
      {
        fVar6 = _DAT_007d5340;
      }
      else {
        fVar6 = _DAT_00804108;
      }
      iVar19 = 3;
      pfVar12 = local_14c + 4;
      pfVar17 = pfVar15;
      do {
        fVar1 = *pfVar17;
        pfVar17 = pfVar17 + 4;
        iVar19 = iVar19 + -1;
        *pfVar12 = fVar6 * fVar1 * *(float *)(((int)local_c0 - (int)param_2) + (int)pfVar15) +
                   *pfVar12;
        pfVar12 = pfVar12 + 1;
      } while (iVar19 != 0);
      pfVar15 = pfVar15 + 1;
      local_170 = (float *)((int)local_170 + -1);
    } while (local_170 != (float *)0x0);
    local_14c[0] = *param_4;
    local_14c[1] = param_4[1];
    local_14c[2] = param_4[2];
    local_170 = (float *)0x3;
    pfVar15 = param_5;
    do {
      if (pfVar15[4] * param_7[1] + *param_7 * *pfVar15 + pfVar15[8] * param_7[2] <= _DAT_007d5344)
      {
        fVar6 = _DAT_00804108;
      }
      else {
        fVar6 = _DAT_007d5340;
      }
      iVar19 = 3;
      pfVar12 = local_14c;
      pfVar17 = pfVar15;
      do {
        fVar1 = *pfVar17;
        pfVar17 = pfVar17 + 4;
        iVar19 = iVar19 + -1;
        *pfVar12 = fVar1 * *(float *)(((int)local_f4 - (int)param_5) + (int)pfVar15) * fVar6 +
                   *pfVar12;
        pfVar12 = pfVar12 + 1;
      } while (iVar19 != 0);
      pfVar15 = pfVar15 + 1;
      local_170 = (float *)((int)local_170 + -1);
    } while (local_170 != (float *)0x0);
    pfVar15 = local_c0;
    iVar19 = 3;
    param_2 = param_2 + (int)(local_15c - 7) / 3;
    do {
      fVar6 = *param_2;
      param_2 = param_2 + 4;
      *pfVar15 = fVar6;
      pfVar15 = pfVar15 + 1;
      iVar19 = iVar19 + -1;
    } while (iVar19 != 0);
    pfVar15 = local_f4;
    iVar19 = 3;
    param_5 = param_5 + (int)(local_15c - 7) % 3;
    do {
      fVar6 = *param_5;
      param_5 = param_5 + 4;
      *pfVar15 = fVar6;
      pfVar15 = pfVar15 + 1;
      iVar19 = iVar19 + -1;
    } while (iVar19 != 0);
    FUN_00628ac0(local_14c + 4,local_c0,local_14c,local_f4,&local_170,&local_158);
    iVar19 = 0;
    do {
      iVar13 = iVar19 + 4;
      *(float *)((int)local_14c + iVar19 + 0x10) =
           (float)local_170 * *(float *)((int)local_c0 + iVar19) +
           *(float *)((int)local_14c + iVar19 + 0x10);
      iVar19 = iVar13;
    } while (iVar13 < 0xc);
    iVar19 = 0;
    do {
      iVar13 = iVar19 + 4;
      *(float *)((int)local_14c + iVar19) =
           (float)local_158 * *(float *)((int)local_f4 + iVar19) +
           *(float *)((int)local_14c + iVar19);
      iVar19 = iVar13;
    } while (iVar13 < 0xc);
    local_e0[3] = 0.0;
    local_e0[0] = -*param_7;
    local_e0[1] = -param_7[1];
    local_e0[2] = -param_7[2];
    (**(code **)(*param_13 + 0xc))(local_e0,local_14c,-*param_8);
    *param_6 = (float)local_168;
    return 1;
  }
  if (local_15c < 4) {
    local_158 = param_5;
    local_108 = param_1;
    local_114 = local_c0;
    pfVar15 = local_f4;
    pfVar12 = param_2;
    pfVar17 = param_4;
  }
  else {
    local_158 = param_2;
    local_108 = param_4;
    local_114 = local_f4;
    pfVar15 = local_c0;
    pfVar12 = param_5;
    pfVar17 = param_1;
    param_1 = param_4;
    param_5 = param_2;
  }
  fVar6 = *param_7;
  if (local_15c < 4) {
    fVar1 = param_7[1];
    local_14c[6] = param_7[2];
  }
  else {
    fVar6 = -fVar6;
    fVar1 = -param_7[1];
    local_14c[6] = -param_7[2];
  }
  local_14c[0] = fVar6 * *param_5 + fVar1 * param_5[4] + local_14c[6] * param_5[8];
  local_14c[1] = fVar6 * param_5[1] + fVar1 * param_5[5] + local_14c[6] * param_5[9];
  local_14c[2] = fVar6 * param_5[2] + fVar1 * param_5[6] + local_14c[6] * param_5[10];
  fVar8 = ABS(local_14c[0]);
  local_e0[1] = ABS(local_14c[1]);
  local_e0[2] = ABS(local_14c[2]);
  if (local_e0[1] <= fVar8) {
    if (local_e0[2] < fVar8) {
      iVar19 = 0;
      local_160 = (float *)0x1;
      local_168 = (float *)0x2;
      goto LAB_0062a362;
    }
  }
  else {
    local_160 = (float *)0x0;
    if (local_e0[2] < local_e0[1]) {
      iVar19 = 1;
      local_168 = (float *)0x2;
      goto LAB_0062a362;
    }
  }
  local_160 = (float *)0x0;
  local_168 = (float *)0x1;
  iVar19 = 2;
LAB_0062a362:
  local_108 = param_1;
  if (_DAT_007d5344 <= local_14c[iVar19]) {
    local_170 = (float *)0x3;
    pfVar14 = param_1;
    pfVar20 = param_5 + iVar19;
    do {
      local_170 = (float *)((int)local_170 + -1);
      *(float *)((int)pfVar14 + ((int)local_14c - (int)param_1)) =
           (*(float *)((int)pfVar14 + ((int)pfVar17 - (int)param_1)) - *pfVar14) -
           pfVar15[iVar19] * *pfVar20;
      pfVar14 = pfVar14 + 1;
      pfVar20 = pfVar20 + 4;
    } while (local_170 != (float *)0x0);
  }
  else {
    local_170 = (float *)0x3;
    pfVar14 = param_1;
    pfVar20 = param_5 + iVar19;
    do {
      local_170 = (float *)((int)local_170 + -1);
      *(float *)((int)pfVar14 + ((int)local_14c - (int)param_1)) =
           pfVar15[iVar19] * *pfVar20 +
           (*(float *)(((int)pfVar17 - (int)param_1) + (int)pfVar14) - *pfVar14);
      pfVar14 = pfVar14 + 1;
      pfVar20 = pfVar20 + 4;
    } while (local_170 != (float *)0x0);
  }
  if (local_15c < 4) {
    local_120 = (float)(local_15c - 1);
  }
  else {
    local_120 = (float)(local_15c - 4);
  }
  if (local_120 == 0.0) {
    iVar19 = 1;
    iVar13 = 2;
  }
  else if (local_120 == 1.4013e-45) {
    iVar19 = 0;
    iVar13 = 2;
  }
  else {
    iVar19 = 0;
    iVar13 = 1;
  }
  local_110 = param_5 + (int)local_160;
  local_104 = param_5 + (int)local_168;
  local_11c = local_14c[0] * pfVar12[iVar19] +
              local_14c[2] * pfVar12[iVar19 + 8] + local_14c[1] * pfVar12[iVar19 + 4];
  local_124 = local_14c[0] * pfVar12[iVar13] +
              local_14c[2] * pfVar12[iVar13 + 8] + local_14c[1] * pfVar12[iVar13 + 4];
  fVar10 = *local_110 * pfVar12[iVar19] +
           pfVar12[iVar19 + 4] * local_110[4] + pfVar12[iVar19 + 8] * local_110[8];
  local_150 = pfVar12[iVar19] * *local_104 +
              pfVar12[iVar19 + 4] * local_104[4] + pfVar12[iVar19 + 8] * local_104[8];
  fVar8 = pfVar12[iVar13] * *local_110 +
          pfVar12[iVar13 + 4] * local_110[4] + pfVar12[iVar13 + 8] * local_110[8];
  local_128 = fVar8;
  fVar11 = pfVar12[iVar13] * *local_104 +
           pfVar12[iVar13 + 4] * local_104[4] + pfVar12[iVar13 + 8] * local_104[8];
  fVar2 = fVar10 * pfVar15[(int)local_160];
  fVar9 = fVar8 * pfVar15[(int)local_160];
  fVar4 = local_150 * pfVar15[(int)local_168];
  fVar3 = fVar11 * pfVar15[(int)local_168];
  local_e0[0] = (local_11c - fVar2) - fVar4;
  local_e0[1] = (local_124 - fVar9) - fVar3;
  local_e0[2] = fVar4 + (local_11c - fVar2);
  local_e0[3] = fVar3 + (local_124 - fVar9);
  local_e0[4] = fVar4 + fVar2 + local_11c;
  local_cc = fVar3 + fVar9 + local_124;
  local_c8 = (fVar2 + local_11c) - fVar4;
  local_c4 = (fVar9 + local_124) - fVar3;
  pfVar15 = (float *)0x4;
  local_158 = (float *)local_114[iVar19];
  local_168 = local_e0;
  local_154 = local_114[iVar13];
  iVar19 = 0;
  local_160 = local_a0;
  do {
    local_12c = -NAN;
    pfVar12 = local_160;
    do {
      local_160 = pfVar12;
      pfVar12 = (float *)0x0;
      if (0 < (int)pfVar15) {
        fVar9 = (float)(int)local_12c;
        pfVar17 = local_168;
        pfVar14 = local_160;
        local_170 = pfVar15;
        do {
          pfVar15 = pfVar12;
          pfVar20 = pfVar14;
          if (fVar9 * *(float *)((int)pfVar17 + iVar19) < *(float *)((int)&local_158 + iVar19)) {
            *pfVar14 = *pfVar17;
            pfVar14[1] = pfVar17[1];
            pfVar20 = pfVar14 + 2;
            pfVar15 = (float *)((int)pfVar12 + 1);
            if (((uint)pfVar15 & 8) != 0) {
              local_168 = local_160;
              goto LAB_0062a709;
            }
          }
          pfVar12 = pfVar17 + 2;
          if ((int)local_170 < 2) {
            pfVar12 = local_168;
          }
          pfVar14 = pfVar20;
          if (fVar9 * *(float *)(iVar19 + (int)pfVar12) < *(float *)((int)&local_158 + iVar19) !=
              fVar9 * *(float *)((int)pfVar17 + iVar19) < *(float *)((int)&local_158 + iVar19)) {
            fVar2 = fVar9 * *(float *)((int)&local_158 + iVar19);
            pfVar16 = (float *)((int)pfVar17 + (4 - iVar19));
            pfVar14 = pfVar20 + 2;
            pfVar15 = (float *)((int)pfVar15 + 1);
            *(float *)((int)pfVar20 + (4 - iVar19)) =
                 (fVar2 - *(float *)((int)pfVar17 + iVar19)) *
                 ((*(float *)((int)pfVar12 + (4 - iVar19)) - *pfVar16) /
                 (*(float *)(iVar19 + (int)pfVar12) - *(float *)((int)pfVar17 + iVar19))) + *pfVar16
            ;
            *(float *)((int)pfVar20 + iVar19) = fVar2;
            if (((uint)pfVar15 & 8) != 0) {
              local_168 = local_160;
              goto LAB_0062a709;
            }
          }
          pfVar17 = pfVar17 + 2;
          local_170 = (float *)((int)local_170 - 1);
          pfVar12 = pfVar15;
        } while (0 < (int)local_170);
      }
      pfVar15 = pfVar12;
      pfVar12 = local_60;
      if (local_160 != local_a0) {
        pfVar12 = local_a0;
      }
      local_12c = (float)((int)local_12c + 2);
      local_168 = local_160;
    } while ((int)local_12c < 2);
    iVar19 = iVar19 + 4;
    local_160 = pfVar12;
  } while (iVar19 < 5);
LAB_0062a709:
  if (local_168 != local_a0) {
    pfVar12 = local_a0;
    for (iVar19 = ((uint)pfVar15 & 0x1fffffff) << 1; iVar19 != 0; iVar19 = iVar19 + -1) {
      *pfVar12 = *local_168;
      local_168 = local_168 + 1;
      pfVar12 = pfVar12 + 1;
    }
    for (iVar19 = 0; iVar19 != 0; iVar19 = iVar19 + -1) {
      *(undefined1 *)pfVar12 = *(undefined1 *)local_168;
      local_168 = (float *)((int)local_168 + 1);
      pfVar12 = (float *)((int)pfVar12 + 1);
    }
  }
  if (0 < (int)pfVar15) {
    local_168 = (float *)0x0;
    fVar9 = _DAT_00804108 / (fVar11 * fVar10 - fVar8 * local_150);
    local_118 = fVar9 * fVar10;
    local_150 = fVar9 * local_150;
    local_128 = fVar9 * fVar8;
    local_12c = fVar9 * fVar11;
    if (0 < (int)pfVar15) {
      local_170 = local_a0 + 1;
      local_160 = local_e0;
      pfVar12 = local_a0 + 1;
      pfVar17 = local_60;
      local_158 = pfVar15;
      do {
        fVar2 = pfVar12[-1];
        fVar3 = *pfVar12;
        local_10c = (fVar2 - local_11c) * fVar9 * fVar11 - local_150 * (fVar3 - local_124);
        iVar19 = 3;
        pfVar15 = local_104;
        pfVar14 = pfVar17;
        pfVar20 = local_110;
        pfVar16 = local_14c;
        do {
          fVar4 = *pfVar20;
          fVar5 = *pfVar15;
          pfVar15 = pfVar15 + 4;
          pfVar20 = pfVar20 + 4;
          pfVar18 = pfVar14 + 1;
          iVar19 = iVar19 + -1;
          *pfVar14 = ((fVar3 - local_124) * fVar9 * fVar10 - (fVar2 - local_11c) * fVar9 * fVar8) *
                     fVar5 + local_10c * fVar4 + *pfVar16;
          pfVar14 = pfVar18;
          pfVar16 = pfVar16 + 1;
        } while (iVar19 != 0);
        fVar2 = local_114[(int)local_120] -
                (fVar6 * *pfVar17 + fVar1 * pfVar17[1] + local_14c[6] * pfVar17[2]);
        *local_160 = fVar2;
        if (_DAT_007d5344 <= fVar2) {
          local_170[-1] = pfVar12[-1];
          *local_170 = *pfVar12;
          local_168 = (float *)((int)local_168 + 1);
          local_160 = local_160 + 1;
          local_170 = local_170 + 2;
          pfVar17 = pfVar18;
        }
        pfVar12 = pfVar12 + 2;
        local_158 = (float *)((int)local_158 - 1);
      } while (local_158 != (float *)0x0);
      if (0 < (int)local_168) {
        if ((int)local_168 < (int)param_10) {
          param_10 = local_168;
        }
        if ((int)param_10 < 1) {
          param_10 = (float *)0x1;
        }
        if ((int)param_10 < (int)local_168) {
          iVar13 = 1;
          iVar19 = 0;
          if (1 < (int)local_168) {
            pfVar15 = local_e0;
            fVar6 = local_e0[0];
            do {
              pfVar15 = pfVar15 + 1;
              if (fVar6 < *pfVar15) {
                fVar6 = *pfVar15;
                iVar19 = iVar13;
              }
              iVar13 = iVar13 + 1;
            } while (iVar13 < (int)local_168);
          }
          FUN_00628b90(local_168,local_a0,param_10,iVar19,local_c0);
          if (0 < (int)param_10) {
            pfVar15 = local_c0;
            local_170 = param_10;
            do {
              fVar6 = *pfVar15;
              pfVar12 = local_60 + (int)fVar6 * 3;
              iVar19 = (int)local_108 - (int)(local_14c + 4);
              iVar13 = 3;
              pfVar17 = local_14c + 4;
              do {
                fVar1 = *pfVar12;
                pfVar12 = pfVar12 + 1;
                iVar13 = iVar13 + -1;
                *pfVar17 = *(float *)(iVar19 + (int)pfVar17) + fVar1;
                pfVar17 = pfVar17 + 1;
              } while (iVar13 != 0);
              local_14c[0] = -*param_7;
              local_14c[1] = -param_7[1];
              local_14c[2] = -param_7[2];
              local_14c[3] = 0.0;
              (**(code **)(*param_13 + 0xc))(local_14c,local_14c + 4,-local_e0[(int)fVar6]);
              pfVar15 = pfVar15 + 1;
              local_170 = (float *)((int)local_170 + -1);
            } while (local_170 != (float *)0x0);
          }
          local_168 = param_10;
        }
        else if (0 < (int)local_168) {
          pfVar15 = local_e0;
          pfVar12 = local_60;
          local_170 = local_168;
          do {
            iVar19 = (int)local_108 - (int)(local_14c + 4);
            iVar13 = 3;
            pfVar17 = local_14c + 4;
            do {
              fVar6 = *pfVar12;
              pfVar12 = pfVar12 + 1;
              iVar13 = iVar13 + -1;
              *pfVar17 = *(float *)(iVar19 + (int)pfVar17) + fVar6;
              pfVar17 = pfVar17 + 1;
            } while (iVar13 != 0);
            local_14c[0] = -*param_7;
            local_14c[1] = -param_7[1];
            local_14c[2] = -param_7[2];
            local_14c[3] = 0.0;
            (**(code **)(*param_13 + 0xc))(local_14c,local_14c + 4,-*pfVar15);
            pfVar15 = pfVar15 + 1;
            local_170 = (float *)((int)local_170 + -1);
          } while (local_170 != (float *)0x0);
        }
        *param_9 = local_15c;
        return (int)local_168;
      }
    }
  }
  return 0;
}

