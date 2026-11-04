
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a1580(float *param_1,int param_2,float param_3)

{
  undefined1 *puVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  undefined4 *puVar5;
  float fVar6;
  float *pfVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  undefined4 *puVar12;
  float *pfVar13;
  float fVar14;
  short *psVar15;
  int iVar16;
  int iVar17;
  float fVar18;
  int iVar19;
  float afStack_11c0 [5];
  int aiStack_11ac [3];
  float afStack_11a0 [2];
  int aiStack_1198 [2];
  float afStack_1190 [1011];
  float afStack_1c4 [3];
  int aiStack_1b8 [2];
  float afStack_1b0 [5];
  undefined4 uStack_19c;
  int *piStack_198;
  float afStack_194 [2];
  undefined4 local_180 [24];
  undefined4 local_120 [24];
  float local_c0;
  float local_bc [24];
  int local_5c [5];
  float *local_48;
  float local_44;
  int local_40;
  float local_3c;
  undefined4 *local_38;
  float local_34;
  float local_30;
  int local_2c;
  int local_28;
  float local_24;
  float local_20;
  float local_1c;
  float *local_18;
  float *local_14;
  float local_10;
  float *local_c;
  float *local_8;
  
  pfVar4 = param_1;
  local_20 = *param_1;
  fVar18 = param_1[2];
  local_28 = *(int *)((int)local_20 + 4);
  local_40 = *(int *)((int)local_20 + 0x20);
  local_34 = (float)(*(int *)((int)local_20 + 4) + 0x800);
  local_18 = *(float **)((int)local_20 + 8);
  iVar10 = 0;
  local_44 = fVar18;
  local_8 = (float *)((int)local_34 * 4);
  local_5c[4] = (0x800 - param_2) * 4;
  pfVar13 = param_1 + 0x15;
  do {
    local_5c[iVar10 + 2] = (int)pfVar13;
    local_5c[iVar10] = (int)(pfVar13 + (0x800 - param_2));
    pfVar11 = local_18;
    iVar10 = iVar10 + 1;
    pfVar13 = (float *)((int)pfVar13 + (int)local_8);
  } while (iVar10 < (int)fVar18);
  local_c = param_1 + (int)local_34 * (int)fVar18 + 0x15;
  pfVar13 = local_c + (int)fVar18 * 0x18;
  local_8 = pfVar13 + (int)local_18 * 6;
  local_3c = param_1[0xc];
  local_10 = param_1[5];
  if (((int)local_3c < 5) && (local_10 == 0.0)) {
    local_34 = 1.0;
    if (local_3c == 0.0) {
      afStack_194[1] = param_1[8];
      piStack_198 = local_5c + 2;
      uStack_19c = 0x7a184b;
      afStack_194[0] = fVar18;
      param_3 = (float)FUN_007a1d10();
      param_1[0xb] = param_3;
    }
    else {
      param_3 = param_1[0xb];
      local_34 = 0.8;
    }
    iVar10 = local_28;
    afStack_194[1] = 1.1212701e-38;
    local_48 = afStack_194 + (2 - local_28);
    afStack_194[1 - local_28] = 1.121272e-38;
    local_38 = afStack_1190 + (1 - iVar10);
    local_2c = 0;
    local_24 = *(float *)((int)local_20 + 0x3c);
    local_18 = (float *)(local_5c + 2);
    local_14 = local_c;
    do {
      local_10 = 0.0;
      iVar17 = (int)*local_18;
      iVar19 = 0x400;
      puVar8 = (undefined4 *)(iVar17 + 0x1000);
      puVar12 = local_38;
      do {
        *puVar12 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar12 = puVar12 + 1;
        iVar19 = iVar19 + -1;
      } while (iVar19 != 0);
      if (local_3c == 0.0) {
        afStack_1190[-iVar10] = param_1[8];
        aiStack_1198[1 - iVar10] = 0x400;
        aiStack_1198[-iVar10] = 0x18;
        afStack_11a0[1 - iVar10] = (float)local_28;
        afStack_11a0[-iVar10] = local_24;
        aiStack_11ac[2 - iVar10] = (int)&local_c0;
        aiStack_11ac[1 - iVar10] = (int)local_38;
        aiStack_11ac[-iVar10] = 0x7a18f2;
        FUN_007a64a0();
        pfVar11 = (float *)0x1;
        local_8 = (float *)0x1;
        local_c0 = local_c0 * _DAT_00838aa0;
        pfVar13 = local_bc;
        do {
          fVar18 = (float)(int)local_8;
          pfVar11 = (float *)((int)pfVar11 + 1);
          local_8 = pfVar11;
          *pfVar13 = *pfVar13 - fVar18 * fVar18 * *pfVar13 * _DAT_00838a9c;
          pfVar13 = pfVar13 + 1;
        } while ((int)pfVar11 < 0x19);
        afStack_1190[-iVar10] = 3.36312e-44;
        aiStack_1198[1 - iVar10] = (int)&local_c0;
        aiStack_1198[-iVar10] = (int)local_14;
        afStack_11a0[1 - iVar10] = 1.1213004e-38;
        FUN_007a5bc0();
      }
      iVar19 = (int)param_3 * 2;
      if (0x3ff < iVar19) {
        iVar19 = 0x400;
      }
      puVar8 = local_180;
      iVar16 = 0x18;
      puVar12 = (undefined4 *)(iVar17 + 0x1ffc + iVar19 * -4);
      do {
        *puVar8 = *puVar12;
        puVar5 = local_38;
        puVar12 = puVar12 + -1;
        puVar8 = puVar8 + 1;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      afStack_1190[-iVar10] = param_1[8];
      aiStack_1198[1 - iVar10] = (int)local_180;
      aiStack_1198[-iVar10] = 0x18;
      afStack_11a0[1 - iVar10] = (float)iVar19;
      afStack_11a0[-iVar10] = (float)(local_38 + (0x400 - iVar19));
      aiStack_11ac[2 - iVar10] = (int)local_14;
      aiStack_11ac[1 - iVar10] = (int)(local_38 + (0x400 - iVar19));
      aiStack_11ac[-iVar10] = 0x7a19aa;
      FUN_007a5ca0();
      iVar19 = iVar19 >> 1;
      local_20 = _DAT_00804108;
      if (iVar19 < 1) {
LAB_007a1a19:
        fVar18 = local_20;
      }
      else {
        iVar16 = 0;
        local_c = (float *)(iVar19 * 4);
        pfVar13 = (float *)(puVar5 + (0x200 - iVar19) * 2);
        local_8 = (float *)iVar19;
        fVar18 = _DAT_00804108;
        do {
          iVar9 = iVar16 + iVar19 * -4;
          iVar16 = iVar16 + 4;
          fVar6 = *(float *)(iVar9 + 0x1000 + (int)puVar5);
          local_8 = (float *)((int)local_8 + -1);
          fVar18 = fVar6 * fVar6 + fVar18;
          local_20 = *pfVar13 * *pfVar13 + local_20;
          pfVar13 = pfVar13 + 1;
        } while (local_8 != (float *)0x0);
        if (local_20 <= fVar18) goto LAB_007a1a19;
      }
      afStack_1190[-iVar10] = (float)(param_2 * -4 + 0x2000);
      aiStack_1198[1 - iVar10] = param_2 * 4 + iVar17;
      aiStack_1198[-iVar10] = iVar17;
      local_8 = (float *)SQRT(fVar18 / local_20);
      afStack_11a0[1 - iVar10] = 1.1213364e-38;
      _memmove((void *)aiStack_1198[-iVar10],(void *)aiStack_1198[1 - iVar10],
               (size_t)afStack_1190[-iVar10]);
      fVar18 = (float)local_8 * local_34;
      iVar19 = param_2 + local_28;
      local_c = (float *)(0x400 - (int)param_3);
      local_1c = 0.0;
      if (0 < iVar19) {
        iVar16 = 0;
        local_20 = 0.0;
        pfVar13 = (float *)(local_38 + (int)local_c);
        local_30 = (float)iVar19;
        do {
          iVar9 = iVar16;
          if ((int)param_3 <= (int)local_1c) {
            fVar18 = fVar18 * (float)local_8;
            local_1c = (float)((int)local_1c - (int)param_3);
            iVar9 = iVar16 + (int)param_3 * -4;
            pfVar13 = pfVar13 + -(int)param_3;
          }
          fVar6 = *pfVar13;
          pfVar13 = pfVar13 + 1;
          *(float *)((int)local_20 + param_2 * -4 + 0x2000 + iVar17) = fVar6 * fVar18;
          iVar16 = iVar9 + 4;
          fVar6 = *(float *)(iVar9 + param_2 * -4 + (int)local_c * 4 + 0x1000 + iVar17);
          local_20 = (float)((int)local_20 + 4);
          local_1c = (float)((int)local_1c + 1);
          local_10 = fVar6 * fVar6 + local_10;
          local_30 = (float)((int)local_30 + -1);
        } while (local_30 != 0.0);
        local_30 = 0.0;
      }
      iVar16 = 0x1ffc;
      puVar8 = local_120;
      local_40 = iVar19;
      do {
        iVar9 = iVar16 + -4;
        *puVar8 = *(undefined4 *)(iVar16 + param_2 * -4 + iVar17);
        iVar16 = iVar9;
        puVar8 = puVar8 + 1;
      } while (0x1f9c < iVar9);
      afStack_1190[-iVar10] = param_1[8];
      aiStack_1198[1 - iVar10] = (int)local_120;
      aiStack_1198[-iVar10] = 0x18;
      afStack_11a0[1 - iVar10] = (float)iVar19;
      afStack_11a0[-iVar10] = (float)(local_5c[4] + iVar17);
      aiStack_11ac[2 - iVar10] = (int)local_14;
      aiStack_11ac[1 - iVar10] = local_5c[4] + iVar17;
      aiStack_11ac[-iVar10] = 0x7a1b3b;
      FUN_007a6090();
      pfVar13 = local_48;
      fVar18 = _DAT_007d5344;
      if (0 < iVar19) {
        iVar16 = 0;
        iVar9 = iVar19;
        do {
          iVar9 = iVar9 + -1;
          fVar6 = *(float *)(iVar16 + param_2 * -4 + 0x2000 + iVar17);
          fVar18 = fVar6 * fVar6 + fVar18;
          iVar16 = iVar16 + 4;
        } while (iVar9 != 0);
      }
      if (fVar18 * _DAT_00838a98 < local_10) {
        if (local_10 < fVar18) {
          local_30 = SQRT((local_10 + _DAT_00804108) / (fVar18 + _DAT_00804108));
          if (0 < local_28) {
            fVar18 = _DAT_00804108 - local_30;
            iVar16 = 0;
            local_8 = (float *)local_28;
            do {
              pfVar11 = (float *)(iVar16 + (int)local_24);
              iVar9 = iVar16 + param_2 * -4;
              iVar16 = iVar16 + 4;
              *(float *)(iVar9 + 0x2000 + iVar17) =
                   (_DAT_00804108 - *pfVar11 * fVar18) * *(float *)(iVar9 + 0x2000 + iVar17);
              local_8 = (float *)((int)local_8 + -1);
            } while (local_8 != (float *)0x0);
            local_8 = (float *)0x0;
          }
          if (local_28 < iVar19) {
            iVar16 = local_28 * 4;
            iVar19 = iVar19 - local_28;
            do {
              iVar9 = iVar16 + param_2 * -4;
              iVar16 = iVar16 + 4;
              iVar19 = iVar19 + -1;
              *(float *)(iVar17 + 0x2000 + iVar9) = *(float *)(iVar17 + 0x2000 + iVar9) * local_30;
            } while (iVar19 != 0);
          }
        }
      }
      else if (0 < iVar19) {
        iVar16 = 0;
        do {
          iVar19 = iVar19 + -1;
          *(undefined4 *)(iVar16 + param_2 * -4 + 0x2000 + iVar17) = 0;
          iVar16 = iVar16 + 4;
        } while (iVar19 != 0);
      }
      fVar6 = param_1[0x11];
      fVar18 = param_1[0xf];
      afStack_1190[-iVar10] = param_1[8];
      aiStack_1198[1 - iVar10] = 0;
      local_c = (float *)-fVar18;
      fVar18 = param_1[0xd];
      aiStack_1198[-iVar10] = 0;
      afStack_11a0[1 - iVar10] = fVar6;
      afStack_11a0[-iVar10] = fVar6;
      aiStack_11ac[2 - iVar10] = (int)local_c;
      aiStack_11ac[1 - iVar10] = (int)local_c;
      aiStack_11ac[-iVar10] = local_28;
      afStack_11c0[4 - iVar10] = fVar18;
      afStack_11c0[3 - iVar10] = fVar18;
      afStack_11c0[2 - iVar10] = (float)(iVar17 + 0x2000);
      afStack_11c0[1 - iVar10] = (float)local_48;
      afStack_11c0[-iVar10] = 1.1214168e-38;
      FUN_007a2710();
      iVar19 = local_28 / 2;
      if (0 < iVar19) {
        pfVar11 = (float *)(local_28 * 4 + -4 + (int)local_24);
        local_c = (float *)((int)pfVar13 - (int)local_24);
        iVar16 = (int)local_24 - (int)pfVar13;
        pfVar7 = (float *)(iVar17 + 0x2000);
        do {
          pfVar2 = (float *)(iVar16 + (int)pfVar13);
          pfVar3 = (float *)((int)local_c + (int)pfVar11);
          fVar18 = *pfVar11;
          fVar6 = *pfVar13;
          pfVar11 = pfVar11 + -1;
          pfVar13 = pfVar13 + 1;
          iVar19 = iVar19 + -1;
          *pfVar7 = fVar18 * fVar6 + *pfVar2 * *pfVar3;
          pfVar7 = pfVar7 + 1;
        } while (iVar19 != 0);
      }
      local_2c = local_2c + 1;
      local_18 = local_18 + 1;
      local_14 = local_14 + 0x18;
    } while (local_2c < (int)local_44);
    goto LAB_007a1cfa;
  }
  local_14 = (float *)param_1[6];
  fVar6 = *(float *)((int)local_20 + 0xc);
  fVar14 = (float)local_14;
  if ((int)fVar6 <= (int)local_14) {
    fVar14 = fVar6;
  }
  if ((int)fVar14 < (int)local_10) {
    fVar6 = local_10;
LAB_007a1644:
    local_1c = fVar6;
  }
  else {
    local_1c = (float)local_14;
    if ((int)fVar6 <= (int)local_14) goto LAB_007a1644;
  }
  iVar10 = (int)fVar18 * param_2;
  afStack_194[1] = 1.1211949e-38;
  local_38 = afStack_194 + (2 - iVar10);
  if ((int)local_3c < 5) {
    if (local_3c == 0.0) {
      fVar6 = _DAT_00832624;
    }
    else {
      fVar6 = _DAT_007d589c;
    }
    local_2c = 0;
    local_18 = pfVar13 + (int)local_10;
    do {
      if ((int)local_10 < (int)local_14) {
        iVar17 = (int)local_14 - (int)local_10;
        pfVar7 = local_18;
        do {
          iVar17 = iVar17 + -1;
          *pfVar7 = *pfVar7 - fVar6;
          pfVar7 = pfVar7 + 1;
        } while (iVar17 != 0);
      }
      local_2c = local_2c + 1;
      local_18 = local_18 + (int)pfVar11;
    } while (local_2c < (int)fVar18);
    local_8 = pfVar13;
  }
  else {
  }
  local_24 = param_1[9];
  if (0 < (int)fVar18) {
    local_14 = (float *)0x0;
    local_34 = fVar18;
    do {
      if ((int)local_10 < (int)local_1c) {
        psVar15 = (short *)(local_40 + (int)local_10 * 2);
        local_30 = (float)((int)local_1c - (int)local_10);
        do {
          iVar19 = ((int)*psVar15 << (SUB41(param_3,0) & 0x1f)) + (int)local_14;
          iVar17 = (int)psVar15[1] - (int)*psVar15 << (SUB41(param_3,0) & 0x1f);
          if (0 < iVar17) {
            local_18 = (float *)((int)local_38 + iVar19 * 4);
            local_2c = iVar17;
            do {
              afStack_194[1 - iVar10] = local_24;
              afStack_194[-iVar10] = 1.1212272e-38;
              local_24 = (float)FUN_007a2ae0();
              local_c = (float *)((int)local_24 >> 0x14);
              pfVar13 = local_18 + 1;
              *local_18 = (float)(int)local_c;
              local_18 = pfVar13;
              local_2c = local_2c + -1;
            } while (local_2c != 0);
          }
          puVar1 = (undefined1 *)((int)local_38 + iVar19 * 4);
          afStack_194[1 - iVar10] = param_1[8];
          afStack_194[-iVar10] = 1.0;
          afStack_194[-1 - iVar10] = (float)iVar17;
          afStack_1b0[5 - iVar10] = (float)puVar1;
          afStack_1b0[4 - iVar10] = 1.1212358e-38;
          FUN_007a6bb0();
          psVar15 = psVar15 + 1;
          local_30 = (float)((int)local_30 + -1);
        } while (local_30 != 0.0);
        fVar18 = local_44;
      }
      local_34 = (float)((int)local_34 + -1);
      local_14 = (float *)((int)local_14 + param_2);
    } while (local_34 != 0.0);
  }
  param_1[9] = local_24;
  iVar17 = 0;
  param_1 = (float *)(local_5c + 2);
  local_c = (float *)(((local_28 >> 1) + param_2 * 0x3fffffff) * 4 + 0x2000);
  do {
    afStack_194[1 - iVar10] = (float)local_c;
    iVar19 = (int)*param_1;
    afStack_194[-iVar10] = (float)(iVar19 + param_2 * 4);
    afStack_194[-1 - iVar10] = (float)iVar19;
    afStack_1b0[5 - iVar10] = 1.1212509e-38;
    _memmove((void *)afStack_194[-1 - iVar10],(void *)afStack_194[-iVar10],
             (size_t)afStack_194[1 - iVar10]);
    iVar17 = iVar17 + 1;
    param_1 = param_1 + 1;
  } while (iVar17 < (int)fVar18);
  fVar6 = pfVar4[4];
  afStack_194[1 - iVar10] = pfVar4[8];
  fVar14 = local_1c;
  afStack_194[-iVar10] = 0.0;
  afStack_194[-1 - iVar10] = fVar6;
  fVar6 = local_10;
  afStack_1b0[5 - iVar10] = param_3;
  pfVar13 = local_8;
  afStack_1b0[4 - iVar10] = 0.0;
  afStack_1b0[3 - iVar10] = fVar18;
  afStack_1b0[2 - iVar10] = fVar18;
  afStack_1b0[1 - iVar10] = fVar14;
  afStack_1b0[-iVar10] = fVar6;
  puVar8 = local_38;
  aiStack_1b8[1 - iVar10] = (int)pfVar13;
  fVar18 = local_20;
  aiStack_1b8[-iVar10] = (int)local_5c;
  afStack_1c4[2 - iVar10] = (float)puVar8;
  afStack_1c4[1 - iVar10] = fVar18;
  afStack_1c4[-iVar10] = 1.1212599e-38;
  FUN_007a10c0();
LAB_007a1cfa:
  pfVar4[0xc] = (float)((int)local_3c + 1);
  return;
}

