
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_007929c0(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  float *pfVar4;
  double *pdVar5;
  ushort *puVar6;
  float *pfVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  uint *puVar11;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  float fStack_c8;
  int local_c4;
  int local_c0;
  ushort *local_bc;
  int local_b8;
  int iStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float afStack_90 [4];
  int local_80;
  int local_7c;
  int local_78;
  int local_74 [2];
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [16];
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [16];
  undefined1 auStack_18 [20];
  
  local_7c = 2;
  local_78 = 2;
  local_c0 = param_4 + -1;
  local_d4 = -1;
  local_b8 = 0;
  local_5c = 0;
  local_d0 = 0;
  local_80 = 0;
  local_74[0] = 0;
  local_74[1] = 0;
  if (param_3 <= local_c0) {
    local_cc = (param_4 + 1) * 0x10;
    local_c4 = param_1;
    do {
      iVar10 = *(int *)(local_c4 + 0x88);
      uVar3 = *(uint *)(iVar10 + -0x14 + local_cc);
      local_bc = (ushort *)(iVar10 + -0x20 + local_cc);
      if ((int)uVar3 < 0) {
        iVar1 = *(int *)(iVar10 + -4 + local_cc);
        iStack_b4 = iVar10 + -0x10 + local_cc;
        iVar8 = local_cc;
        if (iVar1 < 0) {
          iVar8 = ((local_c0 - iVar1) + 1) * 0x10;
        }
        iVar8 = iVar8 + iVar10;
        fStack_e8 = (float)(iStack_b4 - iVar8);
        fStack_fc = 4.2039e-45;
        puVar6 = (ushort *)(iVar8 + 6);
        iStack_b4 = iStack_b4 - (int)local_bc;
        puVar9 = local_bc;
        do {
          uVar2 = *(ushort *)(iStack_b4 + (int)puVar9);
          *puVar9 = uVar2;
          if (puVar6[-3] < uVar2) {
            *puVar9 = puVar6[-3];
          }
          uVar2 = *(ushort *)((int)fStack_e8 + (int)puVar6);
          *(ushort *)(((int)local_bc - iVar8) + (int)puVar6) = uVar2;
          if (uVar2 < *puVar6) {
            *(ushort *)(((int)local_bc - iVar8) + (int)puVar6) = *puVar6;
          }
          puVar9 = puVar9 + 1;
          puVar6 = puVar6 + 1;
          fStack_fc = (float)((int)fStack_fc + -1);
        } while (fStack_fc != 0.0);
      }
      else {
        iVar10 = (int)uVar3 >> 0x15;
        if (iVar10 != local_d4) {
          if (-1 < local_d4) {
            (**(code **)(*param_2 + 0x14))(local_d4);
          }
          (**(code **)(*param_2 + 0xc))
                    (&local_b8,&local_5c,&local_7c,&local_d0,&local_80,local_74,local_74 + 1,
                     &local_78,iVar10);
          local_d4 = iVar10;
        }
        pfVar7 = afStack_90;
        iVar10 = (uVar3 & 0x1fffff) * local_74[0] + local_80;
        fStack_fc = 4.2039e-45;
        puVar11 = (uint *)(iVar10 + 8);
        puVar6 = (ushort *)(iVar10 + 4);
        do {
          if (local_78 == 3) {
            uVar3 = (uint)*puVar6;
          }
          else {
            uVar3 = *puVar11;
          }
          if (local_7c == 0) {
            uStack_4c = 0;
            pfVar4 = (float *)(uVar3 * local_d0 + local_b8);
            fStack_58 = *pfVar4 * (float)param_2[1];
            fStack_54 = pfVar4[1] * (float)param_2[2];
            fStack_50 = pfVar4[2] * (float)param_2[3];
            *pfVar7 = fStack_58;
            pfVar7[1] = fStack_54;
            pfVar7[2] = fStack_50;
          }
          else {
            uStack_60 = 0;
            pdVar5 = (double *)(uVar3 * local_d0 + local_b8);
            fStack_6c = (float)param_2[1] * (float)*pdVar5;
            fStack_68 = (float)param_2[2] * (float)pdVar5[1];
            fStack_64 = (float)param_2[3] * (float)pdVar5[2];
            *pfVar7 = fStack_6c;
            pfVar7[1] = fStack_68;
            pfVar7[2] = fStack_64;
          }
          pfVar7[3] = 0.0;
          puVar6 = puVar6 + -1;
          puVar11 = puVar11 + -1;
          pfVar7 = pfVar7 + -4;
          fStack_fc = (float)((int)fStack_fc + -1);
        } while (fStack_fc != 0.0);
        fStack_e4 = 1e+18;
        fStack_e0 = 1e+18;
        fStack_d8 = 0.0;
        fStack_f8 = -1e+18;
        fStack_f4 = -1e+18;
        fStack_f0 = -1e+18;
        fStack_ec = 0.0;
        if (fStack_b0 < _DAT_008048f0) {
          fStack_e4 = fStack_b0;
        }
        if (fStack_ac < _DAT_008048f0) {
          fStack_e0 = fStack_ac;
        }
        fStack_fc = _DAT_008048f0;
        if (fStack_a8 < _DAT_008048f0) {
          fStack_fc = fStack_a8;
        }
        if (fStack_a4 < _DAT_007d5344) {
          fStack_d8 = fStack_a4;
        }
        if (_DAT_0080427c < fStack_b0) {
          fStack_f8 = fStack_b0;
        }
        if (_DAT_0080427c < fStack_ac) {
          fStack_f4 = fStack_ac;
        }
        if (_DAT_0080427c < fStack_a8) {
          fStack_f0 = fStack_a8;
        }
        if (_DAT_007d5344 < fStack_a4) {
          fStack_ec = fStack_a4;
        }
        if (fStack_a0 < fStack_e4) {
          fStack_e4 = fStack_a0;
        }
        if (fStack_9c < fStack_e0) {
          fStack_e0 = fStack_9c;
        }
        if (fStack_98 < fStack_fc) {
          fStack_fc = fStack_98;
        }
        if (fStack_94 < fStack_d8) {
          fStack_d8 = fStack_94;
        }
        if (fStack_f8 < fStack_a0) {
          fStack_f8 = fStack_a0;
        }
        if (fStack_f4 < fStack_9c) {
          fStack_f4 = fStack_9c;
        }
        if (fStack_f0 < fStack_98) {
          fStack_f0 = fStack_98;
        }
        if (fStack_ec < fStack_94) {
          fStack_ec = fStack_94;
        }
        if (afStack_90[0] < fStack_e4) {
          fStack_e4 = afStack_90[0];
        }
        if (afStack_90[1] < fStack_e0) {
          fStack_e0 = afStack_90[1];
        }
        if (afStack_90[2] < fStack_fc) {
          fStack_fc = afStack_90[2];
        }
        if (fStack_f8 < afStack_90[0]) {
          fStack_f8 = afStack_90[0];
        }
        if (fStack_f4 < afStack_90[1]) {
          fStack_f4 = afStack_90[1];
        }
        if (fStack_f0 < afStack_90[2]) {
          fStack_f0 = afStack_90[2];
        }
        fStack_fc = fStack_fc - *(float *)(local_c4 + 0xc);
        fStack_c8 = fStack_e0 - *(float *)(local_c4 + 8);
        fStack_e8 = fStack_e4 - *(float *)(local_c4 + 4);
        FUN_005fc500(&fStack_e8,&fStack_c8,&fStack_fc);
        iVar10 = local_c4;
        iStack_b4 = local_c4 + 0x24;
        FUN_005fc560(auStack_38,auStack_18,iStack_b4);
        uVar2 = __ftol();
        puVar6 = local_bc;
        *local_bc = uVar2 & 0xfffe;
        uVar2 = __ftol();
        puVar6[1] = uVar2 & 0xfffe;
        uVar2 = __ftol();
        puVar6[2] = uVar2 & 0xfffe;
        fStack_e8 = fStack_f0 - *(float *)(iVar10 + 0xc);
        fStack_c8 = fStack_f4 - *(float *)(iVar10 + 8);
        fStack_fc = fStack_f8 - *(float *)(iVar10 + 4);
        FUN_005fc500(&fStack_fc,&fStack_c8,&fStack_e8);
        FUN_005fc560(auStack_48,auStack_28,iStack_b4);
        uVar2 = __ftol();
        puVar6[3] = uVar2 | 1;
        uVar2 = __ftol();
        puVar6[4] = uVar2 | 1;
        uVar2 = __ftol();
        puVar6[5] = uVar2 | 1;
      }
      local_c0 = local_c0 + -1;
      local_cc = local_cc + -0x10;
    } while (param_3 <= local_c0);
    if (-1 < local_d4) {
      (**(code **)(*param_2 + 0x14))(local_d4);
    }
  }
  return;
}

