
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006b4170(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  undefined *puVar10;
  code *pcVar11;
  int iVar12;
  float fVar13;
  float fVar14;
  int *piVar15;
  int iVar16;
  undefined4 *puVar17;
  int *piVar18;
  int iVar19;
  undefined4 uVar20;
  int iVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  float *pfVar24;
  int iVar25;
  undefined4 *puVar26;
  int iVar27;
  float *pfVar28;
  int iVar29;
  int *piVar30;
  undefined1 *puVar31;
  undefined1 *puVar32;
  undefined1 *puVar33;
  int iVar34;
  int aiStack_c4 [14];
  float afStack_8c [4];
  int iStack_7c;
  undefined4 *local_58;
  int local_50;
  int *local_40;
  undefined4 *local_3c;
  int *local_34;
  float local_30;
  int local_28;
  undefined4 *local_24;
  float *local_10;
  
  piVar15 = param_1;
  iVar1 = *(int *)(param_1[0x10] + 4);
  iVar2 = *(int *)(param_1[0x10] + 0x68);
  iVar25 = param_1[0x1a];
  iVar3 = *(int *)(iVar1 + 4);
  iVar4 = *(int *)(iVar1 + 0x1c);
  iVar21 = param_1[9];
  iStack_7c = 0x6b41af;
  iVar12 = iVar3 * -4;
  afStack_8c[4 - iVar3] = (float)(iVar3 * 4);
  afStack_8c[3 - iVar3] = (float)param_1;
  afStack_8c[2 - iVar3] = 9.849975e-39;
  iVar16 = FUN_006ac620();
  afStack_8c[2 - iVar3] = (float)(*(int *)(iVar1 + 4) << 2);
  afStack_8c[1 - iVar3] = (float)param_1;
  afStack_8c[-iVar3] = 9.849997e-39;
  puVar17 = (undefined4 *)FUN_006ac620();
  afStack_8c[-iVar3] = (float)(*(int *)(iVar1 + 4) << 2);
  aiStack_c4[0xd - iVar3] = (int)param_1;
  aiStack_c4[0xc - iVar3] = 0x6b41d9;
  piVar18 = (int *)FUN_006ac620();
  iVar5 = *(int *)(iVar1 + 4);
  local_30 = *(float *)(iVar25 + 4);
  afStack_8c[4 - iVar3] = 9.850063e-39;
  local_10 = afStack_8c + (-iVar3 - iVar5) + 5;
  iVar6 = param_1[7];
  piVar7 = *(int **)(iVar4 + 0x220 + iVar6 * 4);
  iVar19 = *(int *)(iVar25 + 8);
  iVar8 = *(int *)(iVar2 + 0x38);
  param_1[10] = iVar6;
  iVar8 = iVar8 + ((-(uint)(iVar6 != 0) & 2) + iVar19) * 0x34;
  param_1 = (int *)0x0;
  if (0 < *(int *)(iVar1 + 4)) {
    iVar19 = iVar21 / 2 << 2;
    fVar13 = ((float)(uint)ABS(_DAT_008298e4 / (float)iVar21) * _DAT_008298e0 - _DAT_008298dc) +
             (float)_DAT_008318a8;
    do {
      iVar27 = *piVar15;
      afStack_8c[(-iVar3 - iVar5) + 4] = (float)iVar19;
      afStack_8c[(-iVar3 - iVar5) + 3] = (float)piVar15;
      pfVar28 = *(float **)(iVar27 + (int)param_1 * 4);
      puVar26 = (undefined4 *)((iVar16 - (int)(afStack_8c + (-iVar3 - iVar5) + 5)) + (int)local_10);
      afStack_8c[(-iVar3 - iVar5) + 2] = 9.850331e-39;
      uVar20 = FUN_006ac620();
      *(undefined4 *)((int)puVar26 + ((int)puVar17 - iVar16)) = uVar20;
      afStack_8c[(-iVar3 - iVar5) + 2] = (float)iVar19;
      afStack_8c[(1 - iVar5) - iVar3] = (float)piVar15;
      afStack_8c[-iVar3 - iVar5] = 9.850357e-39;
      uVar20 = FUN_006ac620();
      *puVar26 = uVar20;
      iVar27 = piVar15[7];
      iVar34 = piVar15[6];
      afStack_8c[-iVar3 - iVar5] = (float)piVar15[8];
      aiStack_c4[(0xd - iVar5) - iVar3] = iVar27;
      aiStack_c4[(0xc - iVar5) - iVar3] = iVar34;
      aiStack_c4[(0xb - iVar5) - iVar3] = iVar4;
      aiStack_c4[(10 - iVar5) - iVar3] = iVar2 + 4;
      aiStack_c4[(9 - iVar5) - iVar3] = (int)pfVar28;
      aiStack_c4[(8 - iVar5) - iVar3] = 0x6b42ec;
      FUN_006b3ce0();
      iVar27 = piVar15[7];
      aiStack_c4[(8 - iVar5) - iVar3] = *puVar26;
      aiStack_c4[(7 - iVar5) - iVar3] = (int)pfVar28;
      aiStack_c4[(6 - iVar5) - iVar3] = **(undefined4 **)(iVar2 + 0xc + iVar27 * 4);
      aiStack_c4[(5 - iVar5) - iVar3] = 0x6b4305;
      FUN_006b3850();
      iVar27 = piVar15[7];
      aiStack_c4[(5 - iVar5) - iVar3] = (int)pfVar28;
      aiStack_c4[(4 - iVar5) - iVar3] = iVar2 + 0x14 + iVar27 * 0xc;
      aiStack_c4[(3 - iVar5) - iVar3] = 0x6b4319;
      FUN_006b1480();
      iVar27 = 1;
      fVar14 = ((float)(uint)ABS(*pfVar28) * _DAT_008298e0 - _DAT_008298dc) + fVar13 +
               (float)_DAT_008318a8;
      *pfVar28 = fVar14;
      *local_10 = fVar14;
      if (1 < iVar21 + -1) {
        pfVar24 = pfVar28 + 1;
        do {
          fVar14 = ((float)(uint)ABS(*pfVar24 * *pfVar24 + pfVar24[1] * pfVar24[1]) * _DAT_008298e0
                   - _DAT_008298dc) * _DAT_007d589c + fVar13 + (float)_DAT_008318a8;
          pfVar28[iVar27 + 1 >> 1] = fVar14;
          if (*local_10 < fVar14) {
            *local_10 = fVar14;
          }
          iVar27 = iVar27 + 2;
          pfVar24 = pfVar24 + 2;
        } while (iVar27 < iVar21 + -1);
      }
      if (_DAT_007d5344 < *local_10) {
        *local_10 = 0.0;
      }
      if (local_30 < *local_10) {
        local_30 = *local_10;
      }
      local_10 = local_10 + 1;
      param_1 = (int *)((int)param_1 + 1);
    } while ((int)param_1 < *(int *)(iVar1 + 4));
  }
  iVar21 = iVar21 / 2;
  afStack_8c[(-iVar3 - iVar5) + 4] = (float)(iVar21 * 4);
  afStack_8c[(-iVar3 - iVar5) + 3] = (float)piVar15;
  afStack_8c[(-iVar3 - iVar5) + 2] = 9.850863e-39;
  uVar20 = FUN_006ac620();
  afStack_8c[(-iVar3 - iVar5) + 2] = (float)(iVar21 * 4);
  afStack_8c[(1 - iVar5) - iVar3] = (float)piVar15;
  afStack_8c[-iVar3 - iVar5] = 9.850877e-39;
  uVar22 = FUN_006ac620();
  param_1 = (int *)0x0;
  if (0 < *(int *)(iVar1 + 4)) {
    iVar19 = (int)afStack_8c + ((iVar5 * -4 + iVar12) - (int)piVar18) + 0x14;
    piVar30 = piVar18;
    local_40 = piVar7;
    do {
      local_40 = local_40 + 1;
      afStack_8c[(-iVar3 - iVar5) + 4] = 8.40779e-44;
      afStack_8c[(-iVar3 - iVar5) + 3] = (float)piVar15;
      iVar27 = *local_40;
      iVar34 = *(int *)((int)piVar30 + (iVar16 - (int)(afStack_8c + (-iVar3 - iVar5) + 5)) + iVar19)
      ;
      iVar9 = *(int *)(*piVar15 + (int)param_1 * 4);
      pfVar28 = (float *)(iVar21 * 4 + iVar9);
      piVar15[10] = iVar6;
      afStack_8c[(-iVar3 - iVar5) + 2] = 9.851037e-39;
      puVar26 = (undefined4 *)FUN_006ac620();
      *piVar30 = (int)puVar26;
      for (iVar29 = 0xf; iVar29 != 0; iVar29 = iVar29 + -1) {
        *puVar26 = 0;
        puVar26 = puVar26 + 1;
      }
      if (0 < iVar21) {
        pfVar24 = pfVar28;
        local_50 = iVar21;
        do {
          local_50 = local_50 + -1;
          *pfVar24 = ((float)(*(uint *)((iVar34 - (int)pfVar28) + (int)pfVar24) & 0x7fffffff) *
                      _DAT_008298e0 - _DAT_008298dc) + (float)_DAT_008318a8;
          pfVar24 = pfVar24 + 1;
        } while (local_50 != 0);
      }
      afStack_8c[(-iVar3 - iVar5) + 4] = (float)uVar20;
      afStack_8c[(-iVar3 - iVar5) + 3] = (float)pfVar28;
      afStack_8c[(-iVar3 - iVar5) + 2] = (float)iVar8;
      afStack_8c[(1 - iVar5) - iVar3] = 9.851193e-39;
      FUN_006ae420();
      afStack_8c[(1 - iVar5) - iVar3] = (float)*(undefined4 *)(iVar19 + (int)piVar30);
      afStack_8c[-iVar3 - iVar5] = local_30;
      aiStack_c4[(0xd - iVar5) - iVar3] = uVar22;
      aiStack_c4[(0xc - iVar5) - iVar3] = iVar9;
      aiStack_c4[(0xb - iVar5) - iVar3] = iVar8;
      aiStack_c4[(10 - iVar5) - iVar3] = 0x6b453c;
      FUN_006aeaf0();
      aiStack_c4[(10 - iVar5) - iVar3] = (int)pfVar28;
      aiStack_c4[(9 - iVar5) - iVar3] = iVar34;
      aiStack_c4[(8 - iVar5) - iVar3] = iVar9;
      aiStack_c4[(7 - iVar5) - iVar3] = 1;
      aiStack_c4[(6 - iVar5) - iVar3] = uVar22;
      aiStack_c4[(5 - iVar5) - iVar3] = uVar20;
      aiStack_c4[(4 - iVar5) - iVar3] = iVar8;
      aiStack_c4[(3 - iVar5) - iVar3] = 0x6b4558;
      FUN_006aefe0();
      iVar29 = piVar7[iVar27 + 0x101];
      if (*(int *)(iVar4 + 800 + iVar29 * 4) != 1) {
        return 0xffffffff;
      }
      afStack_8c[(-iVar3 - iVar5) + 4] = (float)iVar9;
      afStack_8c[(-iVar3 - iVar5) + 3] = (float)pfVar28;
      afStack_8c[(-iVar3 - iVar5) + 2] = (float)*(undefined4 *)(*(int *)(iVar2 + 0x30) + iVar29 * 4)
      ;
      afStack_8c[(1 - iVar5) - iVar3] = (float)piVar15;
      afStack_8c[-iVar3 - iVar5] = 9.85135e-39;
      uVar23 = FUN_006b69b0();
      iVar29 = *piVar30;
      afStack_8c[-iVar3 - iVar5] = (float)piVar15;
      *(undefined4 *)(iVar29 + 0x1c) = uVar23;
      aiStack_c4[(0xd - iVar5) - iVar3] = 0x6b4599;
      iVar29 = FUN_006b1400();
      if ((iVar29 != 0) && (*(int *)(*piVar30 + 0x1c) != 0)) {
        afStack_8c[(-iVar3 - iVar5) + 4] = (float)pfVar28;
        afStack_8c[(-iVar3 - iVar5) + 3] = (float)iVar34;
        afStack_8c[(-iVar3 - iVar5) + 2] = (float)iVar9;
        afStack_8c[(1 - iVar5) - iVar3] = 2.8026e-45;
        afStack_8c[-iVar3 - iVar5] = (float)uVar22;
        aiStack_c4[(0xd - iVar5) - iVar3] = uVar20;
        aiStack_c4[(0xc - iVar5) - iVar3] = iVar8;
        aiStack_c4[(0xb - iVar5) - iVar3] = 0x6b45cd;
        FUN_006aefe0();
        aiStack_c4[(0xb - iVar5) - iVar3] = iVar9;
        aiStack_c4[(10 - iVar5) - iVar3] = (int)pfVar28;
        aiStack_c4[(9 - iVar5) - iVar3] =
             *(undefined4 *)(*(int *)(iVar2 + 0x30) + piVar7[iVar27 + 0x101] * 4);
        aiStack_c4[(8 - iVar5) - iVar3] = (int)piVar15;
        aiStack_c4[(7 - iVar5) - iVar3] = 0x6b45ef;
        uVar23 = FUN_006b69b0();
        iVar29 = *piVar30;
        aiStack_c4[(7 - iVar5) - iVar3] = (int)pfVar28;
        aiStack_c4[(6 - iVar5) - iVar3] = iVar34;
        *(undefined4 *)(iVar29 + 0x38) = uVar23;
        aiStack_c4[(5 - iVar5) - iVar3] = iVar9;
        aiStack_c4[(4 - iVar5) - iVar3] = 0;
        aiStack_c4[(3 - iVar5) - iVar3] = uVar22;
        aiStack_c4[(2 - iVar5) - iVar3] = uVar20;
        aiStack_c4[(1 - iVar5) - iVar3] = iVar8;
        aiStack_c4[-iVar3 - iVar5] = 0x6b4610;
        FUN_006aefe0();
        afStack_8c[(-iVar3 - iVar5) + 4] = (float)iVar9;
        iVar34 = piVar7[iVar27 + 0x101];
        afStack_8c[(-iVar3 - iVar5) + 3] = (float)pfVar28;
        afStack_8c[(-iVar3 - iVar5) + 2] =
             (float)*(undefined4 *)(*(int *)(iVar2 + 0x30) + iVar34 * 4);
        afStack_8c[(1 - iVar5) - iVar3] = (float)piVar15;
        afStack_8c[-iVar3 - iVar5] = 9.851584e-39;
        uVar23 = FUN_006b69b0();
        local_50 = 4;
        iVar34 = 0x10000;
        *(undefined4 *)*piVar30 = uVar23;
        do {
          puVar26 = (undefined4 *)*piVar30;
          uVar23 = *puVar26;
          afStack_8c[(-iVar3 - iVar5) + 4] = (float)(iVar34 / 7);
          afStack_8c[(-iVar3 - iVar5) + 3] = (float)puVar26[7];
          afStack_8c[(-iVar3 - iVar5) + 2] = (float)uVar23;
          afStack_8c[(1 - iVar5) - iVar3] =
               (float)*(undefined4 *)(*(int *)(iVar2 + 0x30) + piVar7[iVar27 + 0x101] * 4);
          afStack_8c[-iVar3 - iVar5] = (float)piVar15;
          aiStack_c4[(0xd - iVar5) - iVar3] = 0x6b4682;
          uVar23 = FUN_006b75b0();
          iVar34 = iVar34 + 0x10000;
          *(undefined4 *)(*piVar30 + local_50) = uVar23;
          local_50 = local_50 + 4;
        } while (iVar34 < 0x70000);
        local_50 = 0x20;
        iVar34 = 0x10000;
        do {
          iVar9 = *piVar30;
          uVar23 = *(undefined4 *)(iVar9 + 0x1c);
          afStack_8c[(-iVar3 - iVar5) + 4] = (float)(iVar34 / 7);
          afStack_8c[(-iVar3 - iVar5) + 3] = (float)*(undefined4 *)(iVar9 + 0x38);
          afStack_8c[(-iVar3 - iVar5) + 2] = (float)uVar23;
          afStack_8c[(1 - iVar5) - iVar3] =
               (float)*(undefined4 *)(*(int *)(iVar2 + 0x30) + piVar7[iVar27 + 0x101] * 4);
          afStack_8c[-iVar3 - iVar5] = (float)piVar15;
          aiStack_c4[(0xd - iVar5) - iVar3] = 0x6b46e8;
          uVar23 = FUN_006b75b0();
          iVar34 = iVar34 + 0x10000;
          *(undefined4 *)(*piVar30 + local_50) = uVar23;
          local_50 = local_50 + 4;
        } while (iVar34 < 0x70000);
      }
      param_1 = (int *)((int)param_1 + 1);
      piVar30 = piVar30 + 1;
    } while ((int)param_1 < *(int *)(iVar1 + 4));
  }
  *(float *)(iVar25 + 4) = local_30;
  iVar21 = *(int *)(iVar1 + 4);
  afStack_8c[(-iVar3 - iVar5) + 4] = 9.851962e-39;
  afStack_8c[((-iVar5 - iVar21) - iVar3) + 4] = 9.851983e-39;
  afStack_8c[((iVar21 * -2 - iVar5) - iVar3) + 4] = (float)piVar15;
  afStack_8c[((iVar21 * -2 - iVar5) - iVar3) + 3] = 9.851996e-39;
  iVar19 = FUN_006b1400();
  afStack_8c[((iVar21 * -2 - iVar5) - iVar3) + 3] = (float)piVar15;
  local_28 = (-(uint)(iVar19 != 0) & 0xfffffff9) + 7;
  afStack_8c[((iVar21 * -2 - iVar5) - iVar3) + 2] = 9.852025e-39;
  iVar19 = FUN_006b1400();
  if (local_28 <= (int)((-(uint)(iVar19 != 0) & 7) + 7)) {
    local_24 = (undefined4 *)(iVar25 + 0xc + local_28 * 4);
    pfVar28 = afStack_8c + ((iVar21 * -2 - iVar5) - iVar3) + 5;
    do {
      *(undefined4 *)((int)pfVar28 + -4) = 1;
      *(undefined4 *)((int)pfVar28 + -8) = 0;
      uVar20 = *local_24;
      *(undefined4 *)((int)pfVar28 + -0xc) = uVar20;
      *(undefined4 *)((int)pfVar28 + -0x10) = 0x6b47a1;
      FUN_00797570();
      *(undefined4 *)((int)pfVar28 + -0x10) = *(undefined4 *)(iVar2 + 0x2c);
      *(int *)((int)pfVar28 + -0x14) = iVar6;
      *(undefined4 *)((int)pfVar28 + -0x18) = uVar20;
      *(undefined4 *)((int)pfVar28 + -0x1c) = 0x6b47b5;
      FUN_00797570();
      if (piVar15[7] != 0) {
        iVar25 = piVar15[6];
        *(undefined4 *)((int)pfVar28 + -4) = 1;
        *(int *)((int)pfVar28 + -8) = iVar25;
        *(undefined4 *)((int)pfVar28 + -0xc) = uVar20;
        *(undefined4 *)((int)pfVar28 + -0x10) = 0x6b47ce;
        FUN_00797570();
        iVar25 = piVar15[8];
        *(undefined4 *)((int)pfVar28 + -0x10) = 1;
        *(int *)((int)pfVar28 + -0x14) = iVar25;
        *(undefined4 *)((int)pfVar28 + -0x18) = uVar20;
        *(undefined4 *)((int)pfVar28 + -0x1c) = 0x6b47dd;
        FUN_00797570();
      }
      param_1 = (int *)0x0;
      if (0 < *(int *)(iVar1 + 4)) {
        piVar30 = piVar18;
        local_40 = piVar7;
        do {
          local_40 = local_40 + 1;
          *(undefined4 *)((int)pfVar28 + -4) =
               *(undefined4 *)(((int)puVar17 - (int)piVar18) + (int)piVar30);
          iVar25 = *local_40;
          *(undefined4 *)((int)pfVar28 + -8) = *(undefined4 *)(*piVar30 + local_28 * 4);
          *(undefined4 *)((int)pfVar28 + -0xc) =
               *(undefined4 *)(*(int *)(iVar2 + 0x30) + piVar7[iVar25 + 0x101] * 4);
          *(int **)((int)pfVar28 + -0x10) = piVar15;
          *(undefined4 *)((int)pfVar28 + -0x14) = uVar20;
          *(undefined4 *)((int)pfVar28 + -0x18) = 0x6b4852;
          uVar22 = FUN_006b7660();
          *(undefined4 *)((int)afStack_8c + (iVar12 - (int)piVar18) + 0x14 + (int)piVar30) = uVar22;
          param_1 = (int *)((int)param_1 + 1);
          piVar30 = piVar30 + 1;
        } while ((int)param_1 < *(int *)(iVar1 + 4));
      }
      *(undefined4 *)((int)pfVar28 + -4) = *(undefined4 *)(iVar1 + 4);
      *(undefined4 *)((int)pfVar28 + -8) =
           *(undefined4 *)(iVar4 + (local_28 + (piVar15[7] + 0x36) * 0xf) * 4);
      *(float **)((int)pfVar28 + -0xc) = afStack_8c + (5 - iVar3);
      *(undefined4 **)((int)pfVar28 + -0x10) = puVar17;
      *(int *)((int)pfVar28 + -0x14) = iVar16;
      *(int **)((int)pfVar28 + -0x18) = piVar7;
      *(int *)((int)pfVar28 + -0x1c) = iVar8;
      *(int *)((int)pfVar28 + -0x20) = iVar4 + 0xb34;
      *(int *)((int)pfVar28 + -0x24) = local_28;
      *(undefined4 *)((int)pfVar28 + -0x28) = 0x6b48b2;
      FUN_006af0f0();
      param_1 = (int *)0x0;
      puVar33 = (undefined1 *)pfVar28;
      if (0 < *piVar7) {
        local_34 = piVar7 + 0x111;
        do {
          iVar25 = *local_34;
          local_10 = (float *)0x0;
          local_58 = (undefined4 *)0x0;
          if (0 < *(int *)(iVar1 + 4)) {
            pfVar24 = afStack_8c + ((iVar21 * -2 - iVar5) - iVar3) + 5;
            puVar26 = puVar17;
            local_40 = piVar7;
            do {
              local_40 = local_40 + 1;
              if ((int *)*local_40 == param_1) {
                *pfVar24 = 0.0;
                if (*(int *)((int)afStack_8c + (iVar12 - (int)puVar17) + 0x14 + (int)puVar26) != 0)
                {
                  *pfVar24 = 1.4013e-45;
                }
                pfVar24[iVar21] = (float)*puVar26;
                local_10 = (float *)((int)local_10 + 1);
                pfVar24 = pfVar24 + 1;
              }
              local_58 = (undefined4 *)((int)local_58 + 1);
              puVar26 = puVar26 + 1;
            } while ((int)local_58 < *(int *)(iVar1 + 4));
          }
          iVar19 = *(int *)(iVar4 + 0x520 + iVar25 * 4);
          *(float **)((int)pfVar28 + -4) = local_10;
          puVar10 = (&PTR_DAT_008298cc)[iVar19];
          *(float **)((int)pfVar28 + -8) = afStack_8c + ((iVar21 * -2 - iVar5) - iVar3) + 5;
          *(float **)((int)pfVar28 + -0xc) = afStack_8c + ((-iVar5 - iVar21) - iVar3) + 5;
          *(undefined4 *)((int)pfVar28 + -0x10) =
               *(undefined4 *)(*(int *)(iVar2 + 0x34) + iVar25 * 4);
          *(int **)((int)pfVar28 + -0x14) = piVar15;
          pcVar11 = *(code **)(puVar10 + 0x14);
          puVar31 = (undefined1 *)((int)pfVar28 + -0x18);
          *(undefined4 *)((int)pfVar28 + -0x18) = 0x6b4987;
          uVar22 = (*pcVar11)();
          iVar19 = 0;
          local_10 = (float *)0x0;
          if (0 < *(int *)(iVar1 + 4)) {
            local_58 = afStack_8c + ((-iVar5 - iVar21) - iVar3) + 5;
            local_3c = puVar17;
            local_40 = piVar7;
            do {
              local_40 = local_40 + 1;
              if ((int *)*local_40 == param_1) {
                *local_58 = *local_3c;
                local_10 = (float *)((int)local_10 + 1);
                local_58 = local_58 + 1;
              }
              iVar19 = iVar19 + 1;
              local_3c = local_3c + 1;
            } while (iVar19 < *(int *)(iVar1 + 4));
          }
          iVar19 = *(int *)(iVar4 + 0x520 + iVar25 * 4);
          *(int **)(puVar31 + 0x10) = param_1;
          puVar10 = (&PTR_DAT_008298cc)[iVar19];
          *(undefined4 *)(puVar31 + 0xc) = uVar22;
          *(float **)(puVar31 + 8) = local_10;
          *(float **)(puVar31 + 4) = afStack_8c + ((iVar21 * -2 - iVar5) - iVar3) + 5;
          *(float **)puVar31 = afStack_8c + ((-iVar5 - iVar21) - iVar3) + 5;
          *(undefined4 *)(puVar31 + -4) = *(undefined4 *)(*(int *)(iVar2 + 0x34) + iVar25 * 4);
          *(int **)(puVar31 + -8) = piVar15;
          *(undefined4 *)(puVar31 + -0xc) = uVar20;
          pcVar11 = *(code **)(puVar10 + 0x18);
          puVar32 = puVar31 + -0x10;
          *(undefined4 *)(puVar31 + -0x10) = 0x6b4a25;
          (*pcVar11)();
          pfVar28 = (float *)(puVar32 + 0x20);
          puVar33 = puVar32 + 0x20;
          param_1 = (int *)((int)param_1 + 1);
          local_34 = local_34 + 1;
        } while ((int)param_1 < *piVar7);
      }
      local_28 = local_28 + 1;
      local_24 = local_24 + 1;
      *(int **)(puVar33 + -4) = piVar15;
      *(undefined4 *)(puVar33 + -8) = 0x6b4a5b;
      iVar25 = FUN_006b1400();
      pfVar28 = (float *)puVar33;
    } while (local_28 <= (int)((-(uint)(iVar25 != 0) & 7) + 7));
  }
  return 0;
}

