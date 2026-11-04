
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_0079ddc0(int *param_1,int param_2,undefined4 *param_3,int *param_4,undefined4 param_5)

{
  uint *puVar1;
  uint *puVar2;
  short sVar3;
  int iVar4;
  uint *puVar5;
  longlong lVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  int *piVar10;
  uint uVar11;
  byte bVar12;
  int iVar13;
  uint uVar14;
  int *piVar15;
  uint *puVar16;
  int iVar17;
  undefined2 uVar18;
  int iVar19;
  uint uVar20;
  int *piVar21;
  short *psVar22;
  int iVar23;
  undefined4 *puVar24;
  undefined4 *puVar25;
  int aiStack_a4 [7];
  short local_7c;
  short local_7a;
  short local_78;
  short local_76;
  short local_74;
  short local_72;
  short local_70;
  short local_6e;
  short local_6c;
  short local_6a;
  short local_68;
  short local_66;
  short local_64;
  short local_62;
  short local_60;
  short local_5e;
  int *local_5c;
  int local_58;
  int local_54;
  undefined4 *local_50;
  uint local_4c;
  int local_48;
  undefined4 *local_44;
  uint local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  undefined1 *local_30;
  undefined4 *local_2c;
  uint local_28;
  uint *local_24;
  int *local_20;
  int *local_1c;
  undefined1 *local_18;
  int *local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar17 = param_1[0x248];
  aiStack_a4[6] = 0x79dddf;
  iVar19 = -(iVar17 * 2 + 3U & 0xfffffffc);
  local_30 = (undefined1 *)((int)aiStack_a4 + iVar19 + 0x1c);
  iVar13 = param_1[0x246];
  *(undefined4 *)((int)aiStack_a4 + iVar19 + 0x18) = 0x79ddf8;
  iVar19 = iVar19 + -0x88;
  iVar23 = (iVar13 + iVar17) * -4;
  local_18 = (undefined1 *)((int)aiStack_a4 + iVar23 + iVar19 + 0xa4);
  iVar8 = iVar23 + iVar19;
  iVar17 = param_1[0x247];
  *(undefined4 *)((int)aiStack_a4 + iVar23 + iVar19 + 0xa0) = 0x79de12;
  iVar7 = iVar17 * -4;
  local_34 = (int *)((int)aiStack_a4 + iVar7 + iVar23 + iVar19 + 0xa4);
  iVar4 = iVar7 + iVar8;
  *(undefined4 *)((int)aiStack_a4 + iVar7 + iVar23 + iVar19 + 0xa0) = 0x79de26;
  iVar17 = -(iVar17 * 4 + 0x40);
  local_14 = (int *)((int)aiStack_a4 + iVar17 + iVar4 + 0xa4);
  local_8 = 0;
  sVar3 = *(short *)((int)&PTR_DAT_008377d4 +
                    ((int)*(char *)((int)param_1 + 0xace) +
                    ((int)*(char *)((int)param_1 + 0xacd) >> 1) * 2) * 2);
  iVar19 = (int)*(char *)((int)param_1 + 0xad2);
  local_4c = (uint)(*(char *)((int)param_1 + 0xacf) < '\x04');
  if (0 < iVar13) {
    piVar15 = param_1;
    do {
      piVar15 = piVar15 + 1;
      iVar13 = *(short *)param_4 * 0x4000;
      iVar19 = iVar19 * 0xbb38435 + 0x3619636b;
      *piVar15 = iVar13;
      if (iVar13 < 1) {
        if (iVar13 < 0) {
          iVar13 = iVar13 + 0x500;
          goto LAB_0079de98;
        }
      }
      else {
        iVar13 = iVar13 + -0x500;
LAB_0079de98:
        *piVar15 = iVar13;
      }
      iVar13 = *piVar15 + sVar3 * 0x10;
      *piVar15 = iVar13;
      if (iVar19 < 0) {
        *piVar15 = -iVar13;
      }
      iVar19 = iVar19 + *(short *)param_4;
      local_8 = local_8 + 1;
      param_4 = (int *)((int)param_4 + 2);
    } while ((int)local_8 < param_1[0x246]);
  }
  piVar15 = param_1 + 0x141;
  piVar10 = piVar15;
  piVar21 = (int *)((int)aiStack_a4 + iVar17 + iVar4 + 0xa4);
  for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
    *piVar21 = *piVar10;
    piVar10 = piVar10 + 1;
    piVar21 = piVar21 + 1;
  }
  local_1c = param_1 + 1;
  local_c = param_1[0x248];
  local_2c = param_3;
  local_10 = 0;
  local_5c = piVar15;
  piVar15 = (int *)((int)aiStack_a4 + iVar17 + iVar4 + 0xa4);
  if (0 < param_1[0x245]) {
    do {
      local_14 = piVar15;
      iVar13 = local_10;
      local_3c = local_34;
      local_50 = (undefined4 *)(((local_10 >> 1) + 1) * 0x20 + param_2);
      uVar20 = param_1[0x249];
      puVar24 = local_50;
      psVar22 = &local_7c;
      for (uVar14 = (uVar20 & 0x7fffffff) >> 1; uVar14 != 0; uVar14 = uVar14 - 1) {
        *(undefined4 *)psVar22 = *puVar24;
        puVar24 = puVar24 + 1;
        psVar22 = psVar22 + 2;
      }
      for (iVar19 = (uVar20 & 1) << 1; iVar19 != 0; iVar19 = iVar19 + -1) {
        *(undefined1 *)psVar22 = *(undefined1 *)puVar24;
        puVar24 = (undefined4 *)((int)puVar24 + 1);
        psVar22 = (short *)((int)psVar22 + 1);
      }
      iVar19 = *(int *)(param_2 + 0x10 + iVar13 * 4);
      psVar22 = (short *)(param_2 + 0x60 + iVar13 * 10);
      local_48 = (int)*(char *)((int)param_1 + 0xacd);
      local_54 = iVar19 >> 6;
      iVar13 = iVar19;
      if (iVar19 < 1) {
        iVar13 = -iVar19;
      }
      if (iVar13 == 0) {
        iVar13 = 0x20;
      }
      else {
        *(int *)((int)aiStack_a4 + iVar17 + iVar7 + iVar8 + 0xa0) = iVar13;
        *(undefined4 *)((int)aiStack_a4 + iVar17 + iVar7 + iVar8 + 0x9c) = 0x79df68;
        iVar13 = FUN_007a22e0();
        iVar13 = 0x20 - iVar13;
      }
      local_44 = (undefined4 *)(iVar13 + -1);
      uVar20 = iVar19 << ((byte)local_44 & 0x1f);
      iVar23 = (int)uVar20 >> 0x10;
      lVar6 = 0x1fffffff / (longlong)iVar23;
      iVar13 = (int)lVar6;
      iVar19 = (int)(short)lVar6;
      uVar20 = (((int)((uVar20 & 0xffff) * iVar19) >> 0x10) + iVar19 * iVar23) * -8;
      iVar23 = 0xe - (int)local_44;
      iVar13 = ((iVar13 >> 0xf) + 1 >> 1) * uVar20 + ((int)((uVar20 & 0xffff) * iVar19) >> 0x10) +
               ((int)uVar20 >> 0x10) * iVar19 + iVar13 * 0x10000;
      if (iVar23 < 1) {
        bVar12 = -(byte)iVar23;
        iVar19 = -0x80000000 >> (bVar12 & 0x1f);
        iVar23 = 0x7fffffff >> (bVar12 & 0x1f);
        if (iVar23 < iVar19) {
          if (iVar19 < iVar13) {
LAB_0079e013:
            iVar13 = iVar19;
            goto LAB_0079e015;
          }
          if (iVar23 <= iVar13) goto LAB_0079e015;
          local_8 = iVar23 << (bVar12 & 0x1f);
        }
        else if (iVar23 < iVar13) {
          local_8 = iVar23 << (bVar12 & 0x1f);
        }
        else {
          if (iVar13 < iVar19) goto LAB_0079e013;
LAB_0079e015:
          local_8 = iVar13 << (bVar12 & 0x1f);
        }
      }
      else if (iVar23 < 0x20) {
        local_8 = iVar13 >> ((byte)iVar23 & 0x1f);
      }
      else {
        local_8 = 0;
      }
      iVar13 = *param_1;
      iVar19 = *(int *)(param_2 + 0x10 + local_10 * 4);
      if (iVar19 == iVar13) {
        uVar20 = 0x10000;
      }
      else {
        iVar23 = iVar13;
        if (iVar13 < 1) {
          iVar23 = -iVar13;
        }
        if (iVar23 == 0) {
          iVar23 = 0x20;
        }
        else {
          *(int *)((int)aiStack_a4 + iVar17 + iVar7 + iVar8 + 0xa0) = iVar23;
          *(undefined4 *)((int)aiStack_a4 + iVar17 + iVar7 + iVar8 + 0x9c) = 0x79e055;
          iVar23 = FUN_007a22e0();
          iVar23 = 0x20 - iVar23;
        }
        local_40 = iVar23 - 1;
        uVar20 = iVar13 << ((byte)local_40 & 0x1f);
        iVar13 = iVar19;
        if (iVar19 < 1) {
          iVar13 = -iVar19;
        }
        if (iVar13 == 0) {
          iVar13 = 0x20;
        }
        else {
          *(int *)((int)aiStack_a4 + iVar17 + iVar7 + iVar8 + 0xa0) = iVar13;
          *(undefined4 *)((int)aiStack_a4 + iVar17 + iVar7 + iVar8 + 0x9c) = 0x79e07e;
          iVar13 = FUN_007a22e0();
          iVar13 = 0x20 - iVar13;
        }
        piVar15 = (int *)(iVar13 + -1);
        puVar24 = (undefined4 *)(iVar19 << ((byte)piVar15 & 0x1f));
        iVar19 = (int)(short)(0x1fffffff / (longlong)((int)puVar24 >> 0x10));
        iVar13 = ((int)((uVar20 & 0xffff) * iVar19) >> 0x10) + ((int)uVar20 >> 0x10) * iVar19;
        uVar20 = uVar20 + (int)((ulonglong)((longlong)iVar13 * (longlong)(int)puVar24) >> 0x20) * -8
        ;
        iVar19 = ((int)uVar20 >> 0x10) * iVar19 + iVar13 +
                 ((int)((uVar20 & 0xffff) * iVar19) >> 0x10);
        iVar13 = (local_40 - (int)piVar15) + 0xd;
        if (iVar13 < 0) {
          bVar12 = -(byte)iVar13;
          iVar13 = -0x80000000 >> (bVar12 & 0x1f);
          iVar23 = 0x7fffffff >> (bVar12 & 0x1f);
          if (iVar23 < iVar13) {
            if (iVar13 < iVar19) goto LAB_0079e128;
            if (iVar23 <= iVar19) goto LAB_0079e126;
            uVar20 = iVar23 << (bVar12 & 0x1f);
          }
          else if (iVar23 < iVar19) {
            uVar20 = iVar23 << (bVar12 & 0x1f);
          }
          else {
            if (iVar13 <= iVar19) {
LAB_0079e126:
              iVar13 = iVar19;
            }
LAB_0079e128:
            uVar20 = iVar13 << (bVar12 & 0x1f);
          }
        }
        else if (iVar13 < 0x20) {
          uVar20 = iVar19 >> ((byte)iVar13 & 0x1f);
        }
        else {
          uVar20 = 0;
        }
        local_28 = 0x10;
        piVar10 = local_14;
        while( true ) {
          *piVar10 = ((*piVar10 >> 0xf) + 1 >> 1) * uVar20 +
                     ((int)(uVar20 & 0xffff) * (int)(short)*piVar10 >> 0x10) +
                     ((int)uVar20 >> 0x10) * (int)(short)*piVar10;
          local_28 = local_28 + -1;
          if (local_28 == 0) break;
          piVar10 = piVar10 + 1;
        }
        local_28 = 0;
        local_44 = puVar24;
        local_38 = piVar15;
        local_24 = (uint *)((int)uVar20 >> 0x10);
        local_20 = (int *)(uVar20 & 0xffff);
      }
      iVar13 = local_10;
      *param_1 = *(int *)(param_2 + 0x10 + local_10 * 4);
      if ((((param_1[0x410] == 0) || (param_1[0x411] != 2)) ||
          (*(char *)((int)param_1 + 0xacd) == '\x02')) || (1 < local_10)) {
        if (local_48 == 2) goto LAB_0079e1e9;
        local_3c = local_1c;
      }
      else {
        psVar22[0] = 0;
        psVar22[1] = 0;
        psVar22[2] = 0;
        psVar22[3] = 0;
        psVar22[4] = 0;
        psVar22[2] = 0x1000;
        *(int *)(param_2 + local_10 * 4) = param_1[0x241];
LAB_0079e1e9:
        uVar14 = *(uint *)(param_2 + local_10 * 4);
        local_28 = uVar14;
        if ((local_10 == 0) || ((local_10 == 2 && (local_4c != 0)))) {
          iVar19 = ((param_1[0x248] - param_1[0x249]) - uVar14) + -2;
          if (local_10 == 2) {
            puVar24 = param_3;
            puVar25 = (undefined4 *)((int)param_1 + param_1[0x248] * 2 + 0x544);
            for (uVar20 = param_1[0x247] & 0x3fffffff; uVar20 != 0; uVar20 = uVar20 - 1) {
              *puVar25 = *puVar24;
              puVar24 = puVar24 + 1;
              puVar25 = puVar25 + 1;
            }
            for (iVar23 = 0; iVar23 != 0; iVar23 = iVar23 + -1) {
              *(undefined1 *)puVar25 = *(undefined1 *)puVar24;
              puVar24 = (undefined4 *)((int)puVar24 + 1);
              puVar25 = (undefined4 *)((int)puVar25 + 1);
            }
          }
          iVar23 = param_1[0x249];
          *(undefined4 *)((int)aiStack_a4 + iVar17 + iVar7 + iVar8 + 0xa0) = param_5;
          iVar4 = param_1[0x248];
          *(int *)((int)aiStack_a4 + iVar17 + iVar7 + iVar8 + 0x9c) = iVar23;
          puVar24 = local_50;
          *(int *)((int)aiStack_a4 + iVar17 + iVar7 + iVar8 + 0x98) = iVar4 - iVar19;
          iVar23 = param_1[0x247];
          *(undefined4 **)((int)aiStack_a4 + iVar17 + iVar7 + iVar8 + 0x94) = puVar24;
          puVar9 = local_30;
          *(int *)((int)aiStack_a4 + iVar17 + iVar7 + iVar8 + 0x90) =
               (int)param_1 + (iVar23 * iVar13 + iVar19) * 2 + 0x544;
          *(undefined1 **)((int)aiStack_a4 + iVar17 + iVar7 + iVar8 + 0x8c) = puVar9 + iVar19 * 2;
          *(undefined4 *)((int)aiStack_a4 + iVar17 + iVar7 + iVar8 + 0x88) = 0x79e2e8;
          FUN_0079efc0();
          if (iVar13 == 0) {
            local_8 = (((int)((local_8 & 0xffff) * (int)*(short *)(param_2 + 0x88)) >> 0x10) +
                      ((int)local_8 >> 0x10) * (int)*(short *)(param_2 + 0x88)) * 4;
          }
          iVar13 = 0;
          if (0 < (int)(uVar14 + 2)) {
            piVar15 = (int *)(local_18 + local_c * 4 + -4);
            while( true ) {
              iVar19 = param_1[0x248] - iVar13;
              iVar13 = iVar13 + 1;
              *piVar15 = ((int)((int)*(short *)(local_30 + iVar19 * 2 + -2) * (local_8 & 0xffff)) >>
                         0x10) + (int)*(short *)(local_30 + iVar19 * 2 + -2) *
                                 ((int)local_8 >> 0x10);
              uVar14 = local_28;
              if ((int)(local_28 + 2) <= iVar13) break;
              piVar15 = piVar15 + -1;
            }
          }
        }
        else if (uVar20 != 0x10000) {
          local_8 = uVar14 + 2;
          if (0 < (int)local_8) {
            piVar15 = (int *)(local_18 + local_c * 4 + -4);
            while( true ) {
              *piVar15 = ((*piVar15 >> 0xf) + 1 >> 1) * uVar20 +
                         ((int)(uVar20 & 0xffff) * (int)(short)*piVar15 >> 0x10) +
                         ((int)uVar20 >> 0x10) * (int)(short)*piVar15;
              local_8 = local_8 + -1;
              if (local_8 == 0) break;
              piVar15 = piVar15 + -1;
            }
            local_20 = (int *)(uVar20 & 0xffff);
          }
        }
        puVar16 = (uint *)(local_18 + (local_c - uVar14) * 4 + 8);
        local_8 = 0;
        local_24 = puVar16;
        if (0 < param_1[0x247]) {
          local_20 = (int *)(local_18 + local_c * 4);
          local_44 = (undefined4 *)((int)local_1c - (int)local_34);
          local_38 = local_34;
          do {
            puVar5 = puVar16 + -4;
            puVar1 = puVar16 + -3;
            local_28 = puVar16[-1];
            puVar2 = puVar16 + -2;
            uVar20 = *puVar16;
            puVar16 = local_24 + 1;
            local_c = local_c + 1;
            iVar13 = *(int *)((int)local_44 + (int)local_38) +
                     (((int)((uVar20 & 0xffff) * (int)*psVar22) >> 0x10) +
                      ((int)((*puVar1 & 0xffff) * (int)psVar22[3]) >> 0x10) +
                      ((int)((local_28 & 0xffff) * (int)psVar22[1]) >> 0x10) +
                      ((int)((*puVar2 & 0xffff) * (int)psVar22[2]) >> 0x10) +
                      ((int)((*puVar5 & 0xffff) * (int)psVar22[4]) >> 0x10) +
                      ((int)uVar20 >> 0x10) * (int)*psVar22 +
                      ((int)*puVar1 >> 0x10) * (int)psVar22[3] +
                      ((int)local_28 >> 0x10) * (int)psVar22[1] +
                      ((int)*puVar2 >> 0x10) * (int)psVar22[2] + 2 +
                     ((int)*puVar5 >> 0x10) * (int)psVar22[4]) * 2;
            local_24 = puVar16;
            *local_38 = iVar13;
            *local_20 = iVar13 * 2;
            local_20 = local_20 + 1;
            local_38 = local_38 + 1;
            local_8 = local_8 + 1;
          } while ((int)local_8 < param_1[0x247]);
        }
      }
      local_8 = 0;
      if (0 < param_1[0x247]) {
        local_44 = local_2c;
        local_58 = (local_54 >> 0xf) + 1 >> 1;
        param_4 = local_3c;
        puVar16 = (uint *)(local_14 + 7);
        do {
          local_40 = puVar16[1];
          piVar15 = (int *)puVar16[2];
          puVar5 = (uint *)puVar16[3];
          uVar20 = puVar16[4];
          local_38 = (int *)puVar16[5];
          iVar13 = ((int)((puVar16[8] & 0xffff) * (int)local_7c) >> 0x10) +
                   ((int)((puVar16[7] & 0xffff) * (int)local_7a) >> 0x10) +
                   ((int)((puVar16[6] & 0xffff) * (int)local_78) >> 0x10) +
                   ((int)(((uint)local_38 & 0xffff) * (int)local_76) >> 0x10) +
                   ((int)((uVar20 & 0xffff) * (int)local_74) >> 0x10) +
                   ((int)(((uint)puVar5 & 0xffff) * (int)local_72) >> 0x10) +
                   ((int)(((uint)piVar15 & 0xffff) * (int)local_70) >> 0x10) +
                   ((int)((local_40 & 0xffff) * (int)local_6e) >> 0x10) +
                   ((int)((puVar16[-1] & 0xffff) * (int)local_6a) >> 0x10) +
                   ((int)((*puVar16 & 0xffff) * (int)local_6c) >> 0x10) +
                   ((int)puVar16[8] >> 0x10) * (int)local_7c +
                   ((int)puVar16[7] >> 0x10) * (int)local_7a +
                   ((int)puVar16[6] >> 0x10) * (int)local_78 +
                   ((int)local_38 >> 0x10) * (int)local_76 + ((int)uVar20 >> 0x10) * (int)local_74 +
                   ((int)puVar5 >> 0x10) * (int)local_72 + ((int)piVar15 >> 0x10) * (int)local_70 +
                   ((int)local_40 >> 0x10) * (int)local_6e +
                   ((int)puVar16[-1] >> 0x10) * (int)local_6a +
                   ((int)*puVar16 >> 0x10) * (int)local_6c + (param_1[0x249] >> 1);
          if (param_1[0x249] == 0x10) {
            local_38 = (int *)puVar16[-5];
            local_40 = puVar16[-3];
            iVar13 = ((int)puVar16[-6] >> 0x10) * (int)local_60 + iVar13 +
                     ((int)((puVar16[-7] & 0xffff) * (int)local_5e) >> 0x10) +
                     ((int)((puVar16[-2] & 0xffff) * (int)local_68) >> 0x10) +
                     ((int)((local_40 & 0xffff) * (int)local_66) >> 0x10) +
                     ((int)((puVar16[-4] & 0xffff) * (int)local_64) >> 0x10) +
                     ((int)(((uint)local_38 & 0xffff) * (int)local_62) >> 0x10) +
                     ((int)((puVar16[-6] & 0xffff) * (int)local_60) >> 0x10) +
                     ((int)puVar16[-7] >> 0x10) * (int)local_5e +
                     ((int)puVar16[-2] >> 0x10) * (int)local_68 +
                     ((int)local_40 >> 0x10) * (int)local_66 +
                     ((int)puVar16[-4] >> 0x10) * (int)local_64 +
                     ((int)local_38 >> 0x10) * (int)local_62;
          }
          uVar14 = iVar13 * 0x10 + *param_4;
          puVar16[9] = uVar14;
          uVar14 = ((int)(((int)((uVar14 & 0xffff) * (int)(short)local_54) >> 0x10) +
                          ((int)uVar14 >> 0x10) * (int)(short)local_54 + local_58 * uVar14) >> 7) +
                   1;
          uVar11 = uVar14 & 0xfffffffe;
          if ((int)uVar11 < 0xffff) {
            if ((int)uVar11 < -0x10000) {
              uVar18 = 0x8000;
            }
            else {
              uVar18 = (undefined2)((int)uVar14 >> 1);
            }
          }
          else {
            uVar18 = 0x7fff;
          }
          local_8 = local_8 + 1;
          puVar16 = puVar16 + 1;
          *(undefined2 *)local_44 = uVar18;
          param_4 = param_4 + 1;
          local_44 = (undefined4 *)((int)local_44 + 2);
          local_28 = uVar20;
          local_24 = puVar5;
          local_20 = piVar15;
        } while ((int)local_8 < param_1[0x247]);
      }
      piVar15 = local_14 + param_1[0x247];
      piVar10 = local_14;
      for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
        *piVar10 = *piVar15;
        piVar15 = piVar15 + 1;
        piVar10 = piVar10 + 1;
      }
      local_1c = local_1c + param_1[0x247];
      local_2c = (undefined4 *)((int)local_2c + param_1[0x247] * 2);
      local_10 = local_10 + 1;
      piVar15 = local_14;
    } while (local_10 < param_1[0x245]);
  }
  for (iVar17 = 0x10; iVar17 != 0; iVar17 = iVar17 + -1) {
    *local_5c = *local_14;
    local_14 = local_14 + 1;
    local_5c = local_5c + 1;
  }
  return;
}

