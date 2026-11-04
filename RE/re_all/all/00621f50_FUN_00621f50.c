
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00621f50(int param_1,int param_2,int *param_3,undefined4 param_4)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  float fVar5;
  bool bVar6;
  char cVar7;
  undefined4 uVar8;
  float10 fVar9;
  float local_1a4;
  float local_1a0;
  float local_19c;
  float local_198;
  float local_194;
  undefined4 local_190;
  float local_18c;
  float local_188;
  float local_184;
  float local_180;
  float local_17c;
  float local_178;
  undefined4 local_174;
  float local_170;
  float local_16c;
  float local_168;
  undefined4 uStack_164;
  float local_160;
  float local_15c;
  float local_158;
  undefined4 uStack_154;
  float local_150;
  float local_14c;
  float local_148;
  undefined4 uStack_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  float fStack_128;
  float local_120;
  float local_11c;
  float local_118;
  undefined4 uStack_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  undefined4 uStack_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  undefined1 local_c0 [48];
  float local_90;
  float local_8c;
  float local_88;
  undefined4 local_84;
  undefined1 local_80 [48];
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  *(undefined4 *)(param_1 + 0x38) = 0;
  local_1a4 = 0.0;
  local_180 = 0.0;
  local_17c = 0.0;
  local_178 = 0.0;
  local_174 = 0;
  FUN_005fc5f0(param_2);
  local_90 = *(float *)(param_2 + 0x30);
  local_8c = *(float *)(param_2 + 0x34);
  local_88 = *(float *)(param_2 + 0x38);
  local_84 = *(undefined4 *)(param_2 + 0x3c);
  FUN_005fc5f0(param_2 + 0x40);
  local_50 = *(float *)(param_2 + 0x70);
  local_4c = *(float *)(param_2 + 0x74);
  local_48 = *(float *)(param_2 + 0x78);
  local_110 = local_48 + local_88;
  local_44 = *(undefined4 *)(param_2 + 0x7c);
  local_134 = local_4c + local_8c;
  local_1a0 = local_50 + local_90;
  FUN_005fc500(&local_1a0,&local_134,&local_110);
  local_188 = local_fc * _DAT_007d589c;
  local_184 = local_100 * _DAT_007d589c;
  local_18c = local_104 * _DAT_007d589c;
  FUN_005fc500(&local_18c,&local_184,&local_188);
  local_90 = local_90 - local_e8;
  local_8c = local_8c - local_e4;
  local_88 = local_88 - local_e0;
  local_50 = local_50 - local_e8;
  local_4c = local_4c - local_e4;
  local_48 = local_48 - local_e0;
  iVar2 = *(int *)(*(int *)(param_1 + 0x1c) + 4);
  if (((iVar2 == 0x11) || (iVar2 == 0x12)) &&
     ((iVar2 = *(int *)(*(int *)(param_1 + 0x20) + 4), iVar2 == 0x11 || (iVar2 == 0x12)))) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  local_188 = *(float *)(param_1 + 0x30);
  local_184 = *(float *)(param_1 + 0x2c);
  DAT_00f3f80c = DAT_00f3f80c + 1;
  if (*(char *)(param_1 + 0x34) != '\0') {
    local_184 = 0.0;
    local_188 = 0.0;
  }
  local_134 = local_188 + local_184;
  *(undefined4 *)(param_1 + 0x40) = 0;
  pfVar1 = (float *)(param_1 + 4);
  local_18c = 1e+18;
  *pfVar1 = 0.0;
  *(undefined4 *)(param_1 + 8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  bVar6 = false;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
  FUN_0062bbc0();
  do {
    local_1a0 = -*(float *)(param_1 + 0xc);
    local_10c = -*(float *)(param_1 + 8);
    local_108 = -*pfVar1;
    FUN_005fc500(&local_108,&local_10c,&local_1a0);
    fVar9 = (float10)FUN_005fccf0(local_40);
    local_d0 = (float)fVar9;
    fVar9 = (float10)FUN_005fccd0(local_40);
    local_d8 = (float)fVar9;
    fVar9 = (float10)FUN_005fccb0(local_40);
    local_f0 = (float)fVar9;
    FUN_005fc500(&local_f0,&local_d8,&local_d0);
    fVar9 = (float10)FUN_005fccf0(pfVar1);
    local_c8 = (float)fVar9;
    fVar9 = (float10)FUN_005fccd0(pfVar1);
    local_ec = (float)fVar9;
    fVar9 = (float10)FUN_005fccb0(pfVar1);
    local_cc = (float)fVar9;
    FUN_005fc500(&local_cc,&local_ec,&local_c8);
    FUN_00611c90(local_30,local_10);
    FUN_00611c90(&local_130,local_20);
    fVar9 = (float10)FUN_005fcc30(local_30);
    local_c4 = (float)(fVar9 + (float10)local_88);
    fVar9 = (float10)FUN_005fcc30(local_30);
    local_d4 = (float)(fVar9 + (float10)local_8c);
    fVar9 = (float10)FUN_005fcc30(local_30);
    local_f4 = (float)(fVar9 + (float10)local_90);
    FUN_005fc500(&local_f4,&local_d4,&local_c4);
    fVar9 = (float10)FUN_005fcc30(&local_130);
    local_140 = (float)(fVar9 + (float10)local_48);
    fVar9 = (float10)FUN_005fcc30(&local_130);
    local_138 = (float)(fVar9 + (float10)local_4c);
    fVar9 = (float10)FUN_005fcc30(&local_130);
    local_13c = (float)(fVar9 + (float10)local_50);
    FUN_005fc500(&local_13c,&local_138,&local_140);
    if (bVar4) {
      local_168 = 0.0;
      local_148 = 0.0;
    }
    local_108 = local_168 - local_148;
    local_10c = local_16c - local_14c;
    local_1a0 = local_170 - local_150;
    FUN_005fc500(&local_1a0,&local_10c,&local_108);
    local_1a0 = local_104 * *pfVar1 +
                local_100 * *(float *)(param_1 + 8) + local_fc * *(float *)(param_1 + 0xc);
    if ((_DAT_007d5344 < local_1a0) &&
       (local_18c * *(float *)(param_2 + 0x80) < local_1a0 * local_1a0)) {
      *(undefined4 *)(param_1 + 0x44) = 10;
LAB_006225bd:
      FUN_0062cc40(&local_120,&local_160);
      local_19c = local_120 - local_160;
      local_190 = 0;
      local_198 = local_11c - local_15c;
      local_194 = local_118 - local_158;
      local_174 = 0;
      fVar3 = *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0xc) +
              *(float *)(param_1 + 8) * *(float *)(param_1 + 8) + *pfVar1 * *pfVar1;
      if (fVar3 < (float)_DAT_00804678) {
        *(undefined4 *)(param_1 + 0x44) = 5;
      }
      if (_DAT_0080410c < fVar3) {
        bVar6 = true;
        fVar5 = _DAT_00804108 / SQRT(fVar3);
        local_180 = local_19c * fVar5;
        local_17c = local_198 * fVar5;
        local_178 = local_194 * fVar5;
        fVar3 = local_184 / SQRT(local_18c);
        local_120 = local_120 - fVar3 * *pfVar1;
        local_11c = local_11c - fVar3 * *(float *)(param_1 + 8);
        local_118 = local_118 - fVar3 * *(float *)(param_1 + 0xc);
        fVar3 = local_188 / SQRT(local_18c);
        local_130 = fVar3 * *pfVar1;
        local_12c = fVar3 * *(float *)(param_1 + 8);
        local_160 = local_130 + local_160;
        *(undefined4 *)(param_1 + 0x3c) = 1;
        local_15c = local_12c + local_15c;
        local_158 = fVar3 * *(float *)(param_1 + 0xc) + local_158;
        local_1a4 = _DAT_00804108 / fVar5 - local_134;
      }
      else {
        *(undefined4 *)(param_1 + 0x3c) = 2;
        local_180 = local_19c;
        local_17c = local_198;
        local_178 = local_194;
      }
      goto LAB_006227f5;
    }
    cVar7 = FUN_0062cb60(&local_104);
    if (cVar7 != '\0') {
      *(undefined4 *)(param_1 + 0x44) = 1;
      goto LAB_006225bd;
    }
    if (local_18c - local_1a0 <= local_18c * _DAT_007d5924) {
      if (_DAT_007d5344 < local_18c - local_1a0) {
        *(undefined4 *)(param_1 + 0x44) = 0xb;
      }
      else {
        *(undefined4 *)(param_1 + 0x44) = 2;
      }
      goto LAB_006225bd;
    }
    FUN_0062bc40(&local_104,&local_170,&local_150);
    cVar7 = FUN_0062ca30(&local_19c);
    if (cVar7 == '\0') {
      *(undefined4 *)(param_1 + 0x44) = 3;
      goto LAB_006225bd;
    }
    fVar3 = local_194 * local_194 + local_198 * local_198 + local_19c * local_19c;
    if (fVar3 < _DAT_007d5924) {
      *(undefined4 *)(param_1 + 0x44) = 6;
      *pfVar1 = local_19c;
      *(float *)(param_1 + 8) = local_198;
      *(float *)(param_1 + 0xc) = local_194;
      *(undefined4 *)(param_1 + 0x10) = local_190;
      goto LAB_006225bd;
    }
    local_110 = local_18c;
    fVar5 = local_18c * _DAT_00804520;
    *pfVar1 = local_19c;
    *(float *)(param_1 + 8) = local_198;
    *(float *)(param_1 + 0xc) = local_194;
    *(undefined4 *)(param_1 + 0x10) = local_190;
    if (local_18c - fVar3 <= fVar5) {
      local_18c = fVar3;
      FUN_0062cc00(pfVar1);
      *(undefined4 *)(param_1 + 0x44) = 0xc;
      goto LAB_006225bd;
    }
    iVar2 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x40) = iVar2 + 1;
    local_18c = fVar3;
    if (1000 < iVar2) goto LAB_006227f5;
  } while (**(int **)(param_1 + 0x18) != 4);
  FUN_0062cc00(pfVar1);
  *(undefined4 *)(param_1 + 0x44) = 0xd;
LAB_006227f5:
  if ((((*(int *)(param_1 + 0x48) == 0) || (*(int *)(param_1 + 0x14) == 0)) ||
      (*(int *)(param_1 + 0x44) == 0)) || ((float)_DAT_008044f8 <= local_134 + local_1a4)) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  if (((!bVar6) || (bVar4)) && (*(int *)(param_1 + 0x14) != 0)) {
    DAT_00f3f808 = DAT_00f3f808 + 1;
    *pfVar1 = 0.0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    cVar7 = (**(code **)(**(int **)(param_1 + 0x14) + 4))
                      (*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),
                       *(undefined4 *)(param_1 + 0x20),local_c0,local_80,pfVar1,&local_150,
                       &local_19c,param_4,*(undefined4 *)(param_2 + 0x84));
    if (cVar7 == '\0') {
      if (_DAT_007d5344 <
          *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0xc) +
          *(float *)(param_1 + 8) * *(float *)(param_1 + 8) + *pfVar1 * *pfVar1) {
        local_13c = local_148 - local_194;
        local_138 = local_14c - local_198;
        local_140 = local_150 - local_19c;
        FUN_005fc500(&local_140,&local_138,&local_13c);
        fVar9 = (float10)FUN_005fcc30(&local_130);
        if ((!bVar6) || (SQRT(fVar9) - (float10)local_134 < (float10)local_1a4)) {
          local_1a4 = (float)(SQRT(fVar9) - (float10)local_134);
          local_12c = local_184 * *(float *)(param_1 + 8);
          fStack_128 = local_184 * *(float *)(param_1 + 0xc);
          local_120 = local_150 - local_184 * *pfVar1;
          uStack_114 = uStack_144;
          local_160 = local_19c;
          local_15c = local_198;
          local_158 = local_194;
          local_11c = local_14c - local_12c;
          uStack_154 = local_190;
          local_118 = local_148 - fStack_128;
          local_13c = local_188 * *(float *)(param_1 + 0xc);
          local_138 = local_188 * *(float *)(param_1 + 8);
          local_140 = local_188 * *pfVar1;
          FUN_005fc500(&local_140,&local_138,&local_13c);
          local_160 = local_130 + local_160;
          local_180 = *pfVar1;
          local_15c = local_12c + local_15c;
          local_17c = *(float *)(param_1 + 8);
          local_178 = *(float *)(param_1 + 0xc);
          local_158 = fStack_128 + local_158;
          local_174 = *(undefined4 *)(param_1 + 0x10);
          fVar9 = (float10)FUN_005fcc30(&local_180);
          fVar9 = (float10)_DAT_00804108 / SQRT(fVar9);
          *(undefined4 *)(param_1 + 0x3c) = 6;
          local_180 = (float)(fVar9 * (float10)local_180);
          local_17c = (float)((float10)local_17c * fVar9);
          local_178 = (float)((float10)local_178 * fVar9);
          goto LAB_006229e3;
        }
        *(undefined4 *)(param_1 + 0x3c) = 5;
      }
    }
    else {
      local_170 = local_19c - local_150;
      uStack_164 = 0;
      local_16c = local_198 - local_14c;
      local_168 = local_194 - local_148;
      fVar3 = local_170 * local_170 + local_16c * local_16c + local_168 * local_168;
      if (_DAT_0080410c < fVar3) {
        uVar8 = 0;
      }
      else {
        local_170 = *pfVar1;
        local_16c = *(float *)(param_1 + 8);
        fVar3 = *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0xc) +
                *(float *)(param_1 + 8) * *(float *)(param_1 + 8) + *pfVar1 * *pfVar1;
        local_168 = *(float *)(param_1 + 0xc);
        uVar8 = *(undefined4 *)(param_1 + 0x10);
        if (fVar3 <= _DAT_0080410c) {
          *(undefined4 *)(param_1 + 0x3c) = 9;
          goto LAB_006229db;
        }
      }
      uStack_f8 = 0;
      fVar3 = _DAT_00804108 / SQRT(fVar3);
      local_170 = local_170 * fVar3;
      local_16c = local_16c * fVar3;
      local_168 = local_168 * fVar3;
      local_104 = local_150 - local_19c;
      local_100 = local_14c - local_198;
      local_fc = local_148 - local_194;
      fVar9 = (float10)FUN_005fcc30(&local_104);
      if ((!bVar6) || (-SQRT(fVar9) < (float10)local_1a4)) {
        local_120 = local_150;
        local_11c = local_14c;
        local_118 = local_148;
        uStack_114 = uStack_144;
        local_160 = local_19c;
        local_15c = local_198;
        local_158 = local_194;
        uStack_154 = local_190;
        local_180 = local_170;
        local_1a4 = (float)-SQRT(fVar9);
        local_17c = local_16c;
        local_178 = local_168;
        *(undefined4 *)(param_1 + 0x3c) = 3;
        local_174 = uVar8;
        goto LAB_006229e3;
      }
      *(undefined4 *)(param_1 + 0x3c) = 8;
    }
  }
LAB_006229db:
  if (!bVar6) {
    return;
  }
LAB_006229e3:
  if ((local_1a4 < _DAT_007d5344) || (local_1a4 * local_1a4 < *(float *)(param_2 + 0x80))) {
    *pfVar1 = local_180;
    *(float *)(param_1 + 8) = local_17c;
    *(float *)(param_1 + 0xc) = local_178;
    *(undefined4 *)(param_1 + 0x10) = local_174;
    *(float *)(param_1 + 0x38) = local_1a4;
    iVar2 = *param_3;
    uVar8 = FUN_0060f480(local_20,&local_160,&local_e8,local_1a4);
    (**(code **)(iVar2 + 0xc))(&local_180,uVar8);
  }
  return;
}

