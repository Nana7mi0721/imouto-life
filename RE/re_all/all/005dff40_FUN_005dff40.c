
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005dff40(int *param_1,char param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  byte bVar5;
  float *pfVar6;
  float *pfVar7;
  float *unaff_EBX;
  float *pfVar8;
  uint uVar9;
  float *pfVar10;
  bool bVar11;
  ushort in_FPUControlWord;
  float10 fVar12;
  uint local_2c4;
  undefined1 local_2c0 [4];
  ushort local_2bc;
  ushort local_2b8;
  int *local_2b4;
  float local_2b0;
  byte local_2ac;
  byte local_2ab;
  byte local_2aa;
  byte local_2a9;
  byte local_2a8;
  byte local_2a7;
  byte local_2a6;
  byte local_2a5;
  float local_2a4;
  char local_29e;
  char local_29d;
  float local_29c;
  float local_298;
  float local_294;
  float local_290;
  float local_288;
  int local_284;
  float local_280;
  float local_27c;
  float local_278;
  float local_274;
  float local_270;
  float local_26c;
  float local_264;
  float local_260 [8];
  float local_240 [8];
  float local_220;
  float local_21c;
  float local_218;
  float local_214;
  float local_210;
  float local_20c;
  float local_208;
  float local_200 [2];
  ushort local_1f8;
  ushort local_1e8;
  ushort local_1d8;
  float local_1c8 [2];
  float local_1c0 [2];
  ushort local_1b8;
  float local_1a8;
  ushort local_1a0;
  ushort local_194;
  ushort local_190;
  ushort local_18c;
  ushort local_188;
  ushort local_184;
  ushort local_17c;
  float local_178;
  float local_174;
  float local_170;
  ushort local_16c;
  ushort local_168;
  ushort local_164;
  ushort local_160;
  ushort local_15c;
  ushort local_158;
  ushort local_150;
  ushort local_14c;
  ushort local_148;
  ushort local_140;
  float local_13c;
  float local_138;
  float local_134;
  float local_12c;
  float local_128;
  float local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  int local_108;
  float local_104;
  float local_100;
  float local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  uint local_84;
  float local_80;
  float local_7c;
  float local_78;
  int local_74;
  float local_70;
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
  int local_34;
  float local_30;
  float local_2c;
  undefined1 local_24 [12];
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  local_29e = *(int *)(*param_1 + 0x18) != 0;
  local_29d = *(int *)(*param_1 + 0x1c) != 0;
  iVar1 = (int)ROUND(_DAT_00dfb3f0 * (float)_DAT_0081ec30);
  if (iVar1 < 0x100) {
    local_2aa = (iVar1 < 0) - 1U & (byte)iVar1;
  }
  else {
    local_2aa = 0xff;
  }
  iVar1 = (int)ROUND(_DAT_00dfb3f4 * (float)_DAT_0081ec30);
  if (iVar1 < 0x100) {
    local_2ab = (iVar1 < 0) - 1U & (byte)iVar1;
  }
  else {
    local_2ab = 0xff;
  }
  iVar1 = (int)ROUND(_DAT_00dfb3f8 * (float)_DAT_0081ec30);
  if (iVar1 < 0x100) {
    local_2ac = (iVar1 < 0) - 1U & (byte)iVar1;
  }
  else {
    local_2ac = 0xff;
  }
  iVar1 = (int)ROUND(_DAT_00dfb3fc * (float)_DAT_0081ec30);
  if (iVar1 < 0x100) {
    local_2a9 = (iVar1 < 0) - 1U & (byte)iVar1;
  }
  else {
    local_2a9 = 0xff;
  }
  iVar1 = (int)ROUND(_DAT_00dfb400 * (float)_DAT_0081ec30);
  if (iVar1 < 0x100) {
    local_2a6 = (iVar1 < 0) - 1U & (byte)iVar1;
  }
  else {
    local_2a6 = 0xff;
  }
  iVar1 = (int)ROUND(_DAT_00dfb404 * (float)_DAT_0081ec30);
  if (iVar1 < 0x100) {
    local_2a7 = (iVar1 < 0) - 1U & (byte)iVar1;
  }
  else {
    local_2a7 = 0xff;
  }
  iVar1 = (int)ROUND(_DAT_00dfb408 * (float)_DAT_0081ec30);
  if (iVar1 < 0x100) {
    local_2a8 = (iVar1 < 0) - 1U & (byte)iVar1;
  }
  else {
    local_2a8 = 0xff;
  }
  local_2bc = in_FPUControlWord | 0xc00;
  local_2b4 = (int *)(int)ROUND(_DAT_00dfb40c * (float)_DAT_0081ec30);
  if ((int)local_2b4 < 0x100) {
    local_2a5 = ((int)local_2b4 < 0) - 1U & (byte)local_2b4;
  }
  else {
    local_2a5 = 0xff;
  }
  uVar9 = 0;
  local_2b8 = in_FPUControlWord;
  if (DAT_00a3ce50 != 0) {
    pfVar10 = (float *)&DAT_00e79d00;
    do {
      local_2b0 = pfVar10[1] * (float)_DAT_00804a60;
      FUN_0056d4d0(local_2b0,local_2c0,local_240 + uVar9);
      local_2b0 = *pfVar10 * (float)_DAT_00804a60;
      FUN_0056d4d0(local_2b0,local_2c0,local_260 + uVar9);
      uVar9 = uVar9 + 1;
      pfVar10 = pfVar10 + 0x1a;
    } while (uVar9 < DAT_00a3ce50);
  }
  iVar1 = *param_1;
  bVar11 = *(int *)(*(int *)(iVar1 + 4) + 8) == 2;
  local_2bc = CONCAT11(local_2bc._1_1_,bVar11);
  if (bVar11) {
    local_2b8 = CONCAT11(local_2b8._1_1_,1);
    if (-1 < *(int *)(*(int *)(iVar1 + 4) + 500)) goto LAB_005e0276;
  }
  local_2b8 = local_2b8 & 0xff00;
LAB_005e0276:
  local_84 = (uint)*(ushort *)(param_1 + 2);
  local_2b0 = (float)param_1[3];
  pfVar10 = (float *)param_1[0x3e];
  local_34 = *(int *)(iVar1 + 0x5c);
  local_74 = *(int *)(iVar1 + 0x58);
  local_2b4 = (int *)param_1[0x3c];
  if (local_2b0 == 0.0) {
    return;
  }
  do {
    local_284 = *local_2b4 * local_74 + local_34;
    if (unaff_EBX == (float *)0x0) {
      local_178 = *pfVar10;
      local_174 = pfVar10[1];
      local_170 = pfVar10[2];
      local_280 = pfVar10[3];
      local_27c = pfVar10[4];
      local_278 = pfVar10[5];
    }
    else {
      local_178 = pfVar10[2] * unaff_EBX[8] + pfVar10[1] * unaff_EBX[4] + *pfVar10 * *unaff_EBX +
                  unaff_EBX[0xc];
      local_174 = unaff_EBX[9] * pfVar10[2] + unaff_EBX[1] * *pfVar10 + pfVar10[1] * unaff_EBX[5] +
                  unaff_EBX[0xd];
      local_170 = unaff_EBX[10] * pfVar10[2] + *pfVar10 * unaff_EBX[2] + pfVar10[1] * unaff_EBX[6] +
                  unaff_EBX[0xe];
      local_4c = pfVar10[5] * unaff_EBX[8] + pfVar10[3] * *unaff_EBX + unaff_EBX[4] * pfVar10[4];
      local_48 = unaff_EBX[9] * pfVar10[5] + pfVar10[3] * unaff_EBX[1] + pfVar10[4] * unaff_EBX[5];
      local_44 = unaff_EBX[10] * pfVar10[5] + pfVar10[3] * unaff_EBX[2] + unaff_EBX[6] * pfVar10[4];
      local_64 = local_178;
      local_60 = local_174;
      local_5c = local_170;
      pfVar6 = (float *)FUN_00586310(local_c,local_4c,local_48,local_44);
      local_280 = *pfVar6;
      local_27c = pfVar6[1];
      local_278 = pfVar6[2];
    }
    if (param_2 != '\0') {
      fVar12 = (float10)FUN_0056d670(local_278 * local_278 +
                                     local_280 * local_280 + local_27c * local_27c);
      fVar2 = (float)((float10)1 / fVar12);
      local_280 = fVar2 * local_280;
      local_27c = local_27c * fVar2;
      local_278 = fVar2 * local_278;
    }
    local_298 = 0.0;
    local_2c4 = 0;
    local_294 = 0.0;
    local_290 = 0.0;
    local_274 = 0.0;
    local_270 = 0.0;
    local_26c = 0.0;
    local_210 = 0.0;
    local_20c = 0.0;
    local_208 = 0.0;
    local_13c = 0.0;
    local_138 = 0.0;
    local_134 = 0.0;
    local_29c = 0.0;
    if (DAT_00a3ce50 != 0) {
      pfVar8 = (float *)&DAT_00e79cd8;
      pfVar6 = (float *)&DAT_00dfb460;
      do {
        if (pfVar8[-0xe] == 4.2039e-45) {
          local_12c = pfVar8[2];
          local_128 = pfVar8[3];
          local_124 = pfVar8[4];
          local_288 = -local_124 * local_278 + -local_12c * local_280 + -local_128 * local_27c;
          if (local_288 < 0.0) {
            local_288 = 0.0;
          }
          if ((char)local_2bc == '\0') {
            local_220 = pfVar6[-8] * local_288;
            local_21c = pfVar6[-7] * local_288;
            local_218 = local_288 * pfVar6[-6];
            local_13c = local_220 + local_13c;
            local_138 = local_21c + local_138;
            local_134 = local_218 + local_134;
            local_298 = local_220 + *pfVar6 + local_298;
            local_294 = pfVar6[1] + local_21c + local_294;
            local_290 = pfVar6[2] + local_218 + local_290;
          }
          else {
            local_29c = local_288 + local_29c;
            local_298 = pfVar6[-8] + local_298;
            local_294 = pfVar6[-7] + local_294;
            local_290 = pfVar6[-6] + local_290;
            local_210 = *pfVar6 + local_210;
            local_20c = pfVar6[1] + local_20c;
            local_208 = pfVar6[2] + local_208;
          }
        }
        else {
          local_c0 = pfVar8[-1];
          local_bc = *pfVar8;
          local_b8 = pfVar8[1];
          local_104 = local_c0 - local_178;
          local_100 = local_bc - local_174;
          local_fc = local_b8 - local_170;
          fVar12 = (float10)FUN_005863d0(local_104,local_100,local_fc);
          fVar2 = (float)fVar12;
          local_a8 = local_104 / fVar2;
          local_a4 = local_100 / fVar2;
          local_a0 = local_fc / fVar2;
          local_12c = -local_a8;
          local_128 = -local_a4;
          local_124 = -local_a0;
          local_1a8 = 1.0 / (pfVar6[8] * fVar2 * fVar2 + pfVar6[6] + pfVar6[7] * fVar2);
          if (pfVar8[-0xe] == 2.8026e-45) {
            pfVar7 = local_240 + local_2c4;
            local_2a4 = -pfVar8[4] * local_a0 - (local_a4 * pfVar8[3] + pfVar8[2] * local_a8);
            if (*pfVar7 <= local_2a4) {
              if (local_260[local_2c4] < local_2a4) goto LAB_005e085e;
              local_264 = (local_2a4 - *pfVar7) / (local_260[local_2c4] - *pfVar7);
            }
            else {
              local_264 = 0.0;
            }
          }
          else {
LAB_005e085e:
            local_264 = 1.0;
          }
          local_288 = --local_a8 * local_280 + local_27c * --local_a4 + local_278 * --local_a0;
          if (local_288 < 0.0) {
            local_288 = 0.0;
          }
          if ((char)local_2bc == '\0') {
            local_2a4 = local_264 * local_1a8 * local_288;
            local_13c = pfVar6[-8] * local_2a4 + local_13c;
            local_138 = pfVar6[-7] * local_2a4 + local_138;
            local_134 = pfVar6[-6] * local_2a4 + local_134;
            fVar2 = (pfVar6[-8] * local_288 + pfVar6[1]) * local_1a8 * local_264;
            fVar3 = (pfVar6[-6] * local_288 + pfVar6[2]) * local_1a8 * local_264;
            fVar4 = fVar2;
          }
          else {
            local_29c = local_288 * local_1a8 * local_264 + local_29c;
            fVar2 = pfVar6[-8];
            fVar3 = pfVar6[-6];
            local_210 = *pfVar6 + local_210;
            local_20c = pfVar6[1] + local_20c;
            local_208 = pfVar6[2] + local_208;
            fVar4 = pfVar6[-7];
          }
          local_290 = fVar3 + local_290;
          local_294 = fVar4 + local_294;
          local_298 = fVar2 + local_298;
        }
        local_b4 = local_170 * _DAT_00a383f8 + local_174 * _DAT_00a383e8 + local_178 * DAT_00a383d8
                   + _DAT_00a38408;
        local_b0 = local_170 * _DAT_00a383fc + local_174 * _DAT_00a383ec + local_178 * DAT_00a383dc
                   + _DAT_00a3840c;
        local_ac = local_170 * _DAT_00a38400 + local_174 * _DAT_00a383f0 + local_178 * _DAT_00a383e0
                   + _DAT_00a38410;
        local_58 = local_278 * _DAT_00a383f8 + local_280 * DAT_00a383d8 + local_27c * _DAT_00a383e8;
        local_54 = local_278 * _DAT_00a383fc + local_280 * DAT_00a383dc + local_27c * _DAT_00a383ec;
        local_50 = _DAT_00a383f0 * local_27c + _DAT_00a383e0 * local_280 + _DAT_00a38400 * local_278
        ;
        local_90 = local_124 * _DAT_00a383f8 + local_12c * DAT_00a383d8 + local_128 * _DAT_00a383e8;
        local_8c = local_124 * _DAT_00a383fc + local_12c * DAT_00a383dc + local_128 * _DAT_00a383ec;
        local_88 = local_124 * _DAT_00a38400 + _DAT_00a383f0 * local_128 + local_12c * _DAT_00a383e0
        ;
        local_94 = (float)_DAT_00805148;
        local_9c = local_b4 * local_94;
        local_98 = local_b0 * local_94;
        local_94 = local_94 * local_ac;
        pfVar7 = (float *)FUN_00586310(local_24,local_9c,local_98,local_94);
        local_70 = *pfVar7;
        local_6c = pfVar7[1];
        local_68 = pfVar7[2];
        local_40 = local_70 - local_90;
        local_3c = local_6c - local_8c;
        local_38 = local_68 - local_88;
        pfVar7 = (float *)FUN_00586310(local_18,local_40,local_3c,local_38);
        local_7c = pfVar7[1];
        local_80 = *pfVar7;
        local_78 = pfVar7[2];
        local_2a4 = local_78 * local_50 + local_80 * local_58 + local_7c * local_54;
        fVar12 = (float10)FUN_0056d500(local_2a4,_DAT_00dfb410);
        local_2a4 = (float)fVar12;
        if (local_2a4 < 0.0) {
          local_2a4 = 0.0;
        }
        if (pfVar8[-0xe] == 4.2039e-45) {
          fVar2 = pfVar6[-4] * local_2a4;
        }
        else {
          local_2a4 = local_264 * local_1a8 * local_2a4;
          fVar2 = local_2a4 * pfVar6[-4];
        }
        local_274 = fVar2 + local_274;
        local_2c4 = local_2c4 + 1;
        pfVar8 = pfVar8 + 0x1a;
        local_270 = pfVar6[-3] * local_2a4 + local_270;
        local_26c = local_2a4 * pfVar6[-2] + local_26c;
        pfVar6 = pfVar6 + 0x1c;
      } while (local_2c4 < DAT_00a3ce50);
    }
    fVar2 = (float)_DAT_008023d8;
    fVar3 = 0.0;
    if ((char)local_2bc == '\0') {
      local_298 = _DAT_00dfb350 + local_298;
      local_294 = _DAT_00dfb354 + local_294;
      local_290 = _DAT_00dfb358 + local_290;
      FUN_005dfcb0(local_13c,local_138,local_134,local_1c8,local_1c0,local_200);
      iVar1 = local_284;
      if (local_29e == '\0') {
        local_160 = in_FPUControlWord | 0xc00;
        local_f4 = (int)ROUND((float)local_2aa * local_1c8[0]);
        *(undefined1 *)((int)pfVar10 + 0x1a) = (undefined1)local_f4;
        local_18c = in_FPUControlWord | 0xc00;
        local_e8 = (int)ROUND((float)local_2ab * local_1c0[0]);
        *(undefined1 *)((int)pfVar10 + 0x19) = (undefined1)local_e8;
        local_140 = in_FPUControlWord | 0xc00;
        local_110 = (int)ROUND((float)local_2ac * local_200[0]);
        *(undefined1 *)(pfVar10 + 6) = (undefined1)local_110;
        *(byte *)((int)pfVar10 + 0x1b) = local_2a9;
      }
      else {
        local_190 = in_FPUControlWord | 0xc00;
        local_cc = (int)ROUND((float)*(byte *)(local_284 + 10) * local_1c8[0]);
        *(undefined1 *)((int)pfVar10 + 0x1a) = (undefined1)local_cc;
        local_164 = in_FPUControlWord | 0xc00;
        local_c4 = (int)ROUND((float)*(byte *)(local_284 + 9) * local_1c0[0]);
        *(undefined1 *)((int)pfVar10 + 0x19) = (undefined1)local_c4;
        local_194 = in_FPUControlWord | 0xc00;
        local_118 = (int)ROUND((float)*(byte *)(local_284 + 8) * local_200[0]);
        *(undefined1 *)(pfVar10 + 6) = (undefined1)local_118;
        *(undefined1 *)((int)pfVar10 + 0x1b) = *(undefined1 *)(local_284 + 0xb);
      }
      FUN_005dfcb0(local_274,local_270,local_26c,local_1c8,local_1c0,local_200);
      if (local_29d == '\0') {
        local_148 = in_FPUControlWord | 0xc00;
        local_f8 = (int)ROUND((float)local_2a6 * local_1c8[0]);
        *(undefined1 *)((int)pfVar10 + 0x1e) = (undefined1)local_f8;
        local_16c = in_FPUControlWord | 0xc00;
        local_d0 = (int)ROUND((float)local_2a7 * local_1c0[0]);
        *(undefined1 *)((int)pfVar10 + 0x1d) = (undefined1)local_d0;
        local_168 = in_FPUControlWord | 0xc00;
        local_f0 = (int)ROUND((float)local_2a8 * local_200[0]);
        *(undefined1 *)(pfVar10 + 7) = (undefined1)local_f0;
        *(byte *)((int)pfVar10 + 0x1f) = local_2a5;
      }
      else {
        local_184 = in_FPUControlWord | 0xc00;
        local_c8 = (int)ROUND((float)*(byte *)(iVar1 + 0xe) * local_1c8[0]);
        *(undefined1 *)((int)pfVar10 + 0x1e) = (undefined1)local_c8;
        local_158 = in_FPUControlWord | 0xc00;
        local_108 = (int)ROUND((float)*(byte *)(iVar1 + 0xd) * local_1c0[0]);
        *(undefined1 *)((int)pfVar10 + 0x1d) = (undefined1)local_108;
        local_17c = in_FPUControlWord | 0xc00;
        local_e0 = (int)ROUND((float)*(byte *)(iVar1 + 0xc) * local_200[0]);
        *(undefined1 *)(pfVar10 + 7) = (undefined1)local_e0;
        *(undefined1 *)((int)pfVar10 + 0x1f) = *(undefined1 *)(iVar1 + 0xf);
      }
      if (local_298 <= local_294) {
        fVar2 = local_294;
      }
      else {
        fVar2 = local_298;
      }
      if (fVar2 <= local_290) {
        fVar2 = local_290;
      }
      else {
      }
      if (local_274 <= local_270) {
        local_29c = local_270;
      }
      else {
        local_29c = local_274;
      }
      if (local_29c <= local_26c) {
        local_29c = local_26c;
      }
      else {
      }
      pfVar10[0xc] = fVar2;
      pfVar10[0xd] = fVar2;
      pfVar10[0x10] = local_29c;
      fVar2 = local_29c;
LAB_005e18a1:
      pfVar10[0x11] = fVar2;
    }
    else {
      local_210 = _DAT_00dfb350 + local_210;
      local_20c = _DAT_00dfb354 + local_20c;
      local_208 = _DAT_00dfb358 + local_208;
      if (local_29e == '\0') {
        fVar4 = (float)_DAT_0081ec30;
        local_220 = (float)local_2aa * local_298 + local_210 * fVar4;
        local_21c = local_20c * fVar4 + (float)local_2ab * local_294;
        local_218 = (float)local_2ac * local_290 + local_208 * fVar4;
        bVar5 = local_2a9;
      }
      else {
        fVar4 = (float)_DAT_0081ec30;
        local_220 = (float)*(byte *)(local_284 + 10) * local_298 + local_210 * fVar4;
        local_21c = local_20c * fVar4 + (float)*(byte *)(local_284 + 9) * local_294;
        local_218 = (float)*(byte *)(local_284 + 8) * local_290 + local_208 * fVar4;
        bVar5 = *(byte *)(local_284 + 0xb);
      }
      local_214 = (float)bVar5;
      if (local_220 <= fVar2) {
        if (local_220 < 0.0) {
          local_220 = fVar3;
        }
      }
      else {
        local_220 = _DAT_008023d0;
      }
      if (local_21c <= fVar2) {
        if (local_21c < 0.0) {
          local_21c = fVar3;
        }
      }
      else {
        local_21c = _DAT_008023d0;
      }
      if (local_218 <= fVar2) {
        if (local_218 < 0.0) {
          local_218 = fVar3;
        }
      }
      else {
        local_218 = _DAT_008023d0;
      }
      if (local_274 <= fVar2) {
        if (local_274 < 0.0) {
          local_274 = fVar3;
        }
      }
      else {
        local_274 = _DAT_008023d0;
      }
      if (local_270 <= fVar2) {
        if (local_270 < 0.0) {
          local_270 = fVar3;
        }
      }
      else {
        local_270 = _DAT_008023d0;
      }
      if (local_26c <= fVar2) {
        if (local_26c < 0.0) {
          local_26c = fVar3;
        }
      }
      else {
        local_26c = _DAT_008023d0;
      }
      local_1f8 = in_FPUControlWord | 0xc00;
      local_e4 = (int)ROUND(local_220);
      *(undefined1 *)((int)pfVar10 + 0x1a) = (undefined1)local_e4;
      local_1e8 = in_FPUControlWord | 0xc00;
      local_d8 = (int)ROUND(local_21c);
      *(undefined1 *)((int)pfVar10 + 0x19) = (undefined1)local_d8;
      local_1d8 = in_FPUControlWord | 0xc00;
      local_11c = (int)ROUND(local_218);
      *(undefined1 *)(pfVar10 + 6) = (undefined1)local_11c;
      if (local_29e == '\0') {
        bVar5 = local_2a9;
      }
      else {
        bVar5 = *(byte *)(local_284 + 0xb);
      }
      *(byte *)((int)pfVar10 + 0x1b) = bVar5;
      if (local_29d == '\0') {
        local_15c = in_FPUControlWord | 0xc00;
        local_120 = (int)ROUND((float)local_2a6 * local_274);
        *(undefined1 *)((int)pfVar10 + 0x1e) = (undefined1)local_120;
        local_14c = in_FPUControlWord | 0xc00;
        local_dc = (int)ROUND((float)local_2a7 * local_270);
        *(undefined1 *)((int)pfVar10 + 0x1d) = (undefined1)local_dc;
        local_150 = in_FPUControlWord | 0xc00;
        local_d4 = (int)ROUND((float)local_2a8 * local_26c);
        *(undefined1 *)(pfVar10 + 7) = (undefined1)local_d4;
        *(byte *)((int)pfVar10 + 0x1f) = local_2a5;
      }
      else {
        local_1b8 = in_FPUControlWord | 0xc00;
        local_114 = (int)ROUND((float)*(byte *)(local_284 + 0xe) * local_274);
        *(undefined1 *)((int)pfVar10 + 0x1e) = (undefined1)local_114;
        local_1a0 = in_FPUControlWord | 0xc00;
        local_10c = (int)ROUND((float)*(byte *)(local_284 + 0xd) * local_270);
        *(undefined1 *)((int)pfVar10 + 0x1d) = (undefined1)local_10c;
        local_188 = in_FPUControlWord | 0xc00;
        local_ec = (int)ROUND((float)*(byte *)(local_284 + 0xc) * local_26c);
        *(undefined1 *)(pfVar10 + 7) = (undefined1)local_ec;
        *(undefined1 *)((int)pfVar10 + 0x1f) = *(undefined1 *)(local_284 + 0xf);
      }
      pfVar10[0xc] = local_29c;
      pfVar10[0xd] = local_29c;
      if ((char)local_2b8 != '\0') {
        local_30 = local_278 * _DAT_00a383f8 + local_280 * DAT_00a383d8 + local_27c * _DAT_00a383e8;
        local_2c = local_278 * _DAT_00a383fc + local_280 * DAT_00a383dc + _DAT_00a383ec * local_27c;
        fVar2 = (float)_DAT_00804a60;
        pfVar10[0x10] = local_30 * fVar2 + fVar2;
        fVar2 = fVar2 - local_2c * fVar2;
        goto LAB_005e18a1;
      }
    }
    pfVar10 = (float *)((int)pfVar10 + local_84);
    local_2b4 = local_2b4 + 1;
    local_2b0 = (float)((int)local_2b0 + -1);
    if (local_2b0 == 0.0) {
      return;
    }
  } while( true );
}

