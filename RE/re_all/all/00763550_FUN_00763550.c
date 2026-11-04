
void FUN_00763550(int param_1,uint param_2,int param_3,int param_4,uint param_5,int param_6,
                 int param_7,uint *param_8)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  uint3 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined2 *puVar13;
  ushort uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  byte *pbVar19;
  undefined1 *puVar20;
  uint *puVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  ushort *puVar25;
  int iVar26;
  uint uVar27;
  int local_68;
  uint local_64;
  uint local_60;
  undefined4 local_5c;
  int local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  
  uVar23 = local_5c;
  iVar18 = DAT_00dca3f8;
  iVar4 = DAT_00dca3e8;
  iVar26 = DAT_00dca3e4;
  uVar15 = (uint)(param_7 != 0);
  uVar17 = (uint)(param_8 != (uint *)0x0);
  iVar6 = DAT_00dca3ec + -1;
  iVar10 = DAT_00dca3f0 + -1;
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = *(int *)(*(int *)(param_1 + 0x14) + 0xc);
  local_68 = param_4 * -2 + 3;
  if (param_6 == 0) {
    iVar7 = *(int *)(*(int *)(param_1 + 0x14) + 0x20);
    if (iVar7 == 0) {
      if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
        param_5 = ((param_5 >> 5 & 0x3f) * (DAT_00dca3fc >> 8 & 0xff) & 0xffffff07 |
                  (param_5 & 0x1f) * (DAT_00dca3fc & 0xff) >> 5) >> 3 |
                  (param_5 >> 8 & 0xfffff8) * (DAT_00dca3fc >> 0x10 & 0xff) & 0xfffff800;
      }
      switch(DAT_00dca3f4) {
      case 1:
        if (DAT_00dca3f8 != 0xff) {
          if (DAT_00dca3f8 == 0) {
            return;
          }
          if (uVar17 == 0) {
            uVar23 = iVar6 - DAT_00dca3e4;
            if (((param_2 - param_4) - DAT_00dca3e4 <= uVar23) &&
               ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar10 - DAT_00dca3e8))) {
              puVar25 = (ushort *)(iVar2 * param_3 + iVar1 + (param_2 - param_4) * 2);
              uVar9 = *puVar25;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                   DAT_00dca3f8 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 +
                                   DAT_00dca3f8 * 0x800)) * 0x800 |
                         (uVar9 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + DAT_00dca3f8 * 0x800);
            }
            iVar7 = (param_2 - uVar15) + param_4;
            if (((uint)(iVar7 - iVar26) <= uVar23) &&
               ((uint)(param_3 - iVar4) <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(iVar2 * param_3 + iVar1 + iVar7 * 2);
              uVar9 = *puVar25;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                         * 0x800 | (uVar9 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 +
                                             iVar18 * 0x800);
            }
          }
          if (uVar15 == 0) {
            iVar7 = (param_3 - uVar17) + param_4;
            if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
               ((uint)(iVar7 - iVar4) <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(iVar7 * iVar2 + iVar1 + param_2 * 2);
              uVar9 = *puVar25;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                         * 0x800 | (uVar9 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 +
                                             iVar18 * 0x800);
            }
            if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
               ((uint)((param_3 - param_4) - iVar4) <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)((param_3 - param_4) * iVar2 + iVar1 + param_2 * 2);
              uVar9 = *puVar25;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                         * 0x800 | (uVar9 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 +
                                             iVar18 * 0x800);
            }
          }
          if (-1 < local_68) {
            param_4 = param_4 + -1;
            local_68 = local_68 + param_4 * -4;
          }
          local_68 = local_68 + 6;
          param_1 = 1;
          if (param_4 < 1) {
            return;
          }
          uVar23 = iVar6 - iVar26;
          local_18 = param_4 * 4;
          local_48 = param_3 - iVar4;
          local_34 = local_48 - param_4;
          local_4c = param_2 - iVar26;
          local_54 = local_4c - uVar15;
          local_50 = (param_2 - uVar15) * 2;
          local_28 = (param_3 - param_4) * iVar2;
          local_44 = param_2 * 2;
          local_24 = ((param_4 - iVar4) - uVar17) + param_3;
          local_20 = ((param_4 - uVar17) + param_3) * iVar2;
          local_1c = ((param_4 - iVar26) - uVar15) + param_2;
          param_7 = ((param_4 - uVar15) + param_2) * 2;
          local_30 = local_4c - param_4;
          local_40 = (param_3 + -1) * iVar2;
          local_2c = (param_2 - param_4) * 2;
          local_3c = local_48 - uVar17;
          local_38 = ((param_3 - uVar17) + 1) * iVar2;
          do {
            local_3c = local_3c + 1;
            local_44 = local_44 + -2;
            local_48 = local_48 - 1;
            local_4c = local_4c - 1;
            local_50 = local_50 + 2;
            local_54 = local_54 + 1;
            if ((local_30 <= uVar23) && (local_3c <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(iVar1 + local_2c + local_38);
              uVar9 = *puVar25;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                         * 0x800 | (uVar9 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 +
                                             iVar18 * 0x800);
            }
            if ((local_1c <= uVar23) && (local_3c <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(iVar1 + param_7 + local_38);
              uVar9 = *puVar25;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                         * 0x800 | (uVar9 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 +
                                             iVar18 * 0x800);
            }
            if ((local_30 <= uVar23) && (local_48 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_2c + local_40 + iVar1);
              uVar9 = *puVar25;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                         * 0x800 | (uVar9 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 +
                                             iVar18 * 0x800);
            }
            if ((local_1c <= uVar23) && (local_48 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_40 + param_7 + iVar1);
              uVar9 = *puVar25;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                         * 0x800 | (uVar9 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 +
                                             iVar18 * 0x800);
            }
            if ((local_4c <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_20 + local_44 + iVar1);
              uVar9 = *puVar25;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                         * 0x800 | (uVar9 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 +
                                             iVar18 * 0x800);
            }
            if ((local_54 <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_20 + local_50 + iVar1);
              uVar9 = *puVar25;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                         * 0x800 | (uVar9 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 +
                                             iVar18 * 0x800);
            }
            if ((local_4c <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_44 + local_28 + iVar1);
              uVar9 = *puVar25;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                         * 0x800 | (uVar9 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 +
                                             iVar18 * 0x800);
            }
            if ((local_54 <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_28 + local_50 + iVar1);
              uVar9 = *puVar25;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                         * 0x800 | (uVar9 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 +
                                             iVar18 * 0x800);
            }
            if (-1 < local_68) {
              local_1c = local_1c - 1;
              local_20 = local_20 + -iVar2;
              local_24 = local_24 - 1;
              local_28 = local_28 + iVar2;
              local_30 = local_30 + 1;
              local_34 = local_34 + 1;
              param_7 = param_7 + -2;
              local_2c = local_2c + 2;
              local_18 = local_18 + -4;
              param_4 = param_4 + -1;
              local_68 = local_68 - local_18;
            }
            local_38 = local_38 + iVar2;
            param_1 = param_1 + 1;
            local_40 = local_40 + -iVar2;
            local_68 = local_68 + 2 + param_1 * 4;
          } while (param_1 <= param_4);
          return;
        }
      case 0:
        if (uVar17 == 0) {
          uVar23 = iVar6 - DAT_00dca3e4;
          if (((param_2 - param_4) - DAT_00dca3e4 <= uVar23) &&
             ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar10 - DAT_00dca3e8))) {
            *(ushort *)(iVar2 * param_3 + iVar1 + (param_2 - param_4) * 2) = (ushort)param_5;
          }
          iVar18 = (param_2 - uVar15) + param_4;
          if (((uint)(iVar18 - iVar26) <= uVar23) &&
             ((uint)(param_3 - iVar4) <= (uint)(iVar10 - iVar4))) {
            *(ushort *)(iVar2 * param_3 + iVar1 + iVar18 * 2) = (ushort)param_5;
          }
        }
        if (uVar15 == 0) {
          iVar18 = (param_3 - uVar17) + param_4;
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)(iVar18 - iVar4) <= (uint)(iVar10 - iVar4))) {
            *(ushort *)(iVar18 * iVar2 + iVar1 + param_2 * 2) = (ushort)param_5;
          }
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)((param_3 - param_4) - iVar4) <= (uint)(iVar10 - iVar4))) {
            *(ushort *)((param_3 - param_4) * iVar2 + iVar1 + param_2 * 2) = (ushort)param_5;
          }
        }
        if (-1 < local_68) {
          param_4 = param_4 + -1;
          local_68 = local_68 + param_4 * -4;
        }
        local_68 = local_68 + 6;
        param_1 = 1;
        if (0 < param_4) {
          uVar23 = iVar6 - iVar26;
          local_44 = param_2 - iVar26;
          local_18 = param_4 * 4;
          local_40 = param_3 - iVar4;
          local_30 = local_40 - param_4;
          local_4c = local_44 - uVar15;
          local_48 = (param_2 - uVar15) * 2;
          local_24 = (param_3 - param_4) * iVar2;
          local_3c = param_2 * 2;
          local_20 = ((param_4 - iVar4) - uVar17) + param_3;
          local_1c = ((param_4 - uVar17) + param_3) * iVar2;
          local_38 = local_40 - uVar17;
          param_8 = (uint *)(((param_4 - iVar26) - uVar15) + param_2);
          param_7 = ((param_4 - uVar15) + param_2) * 2;
          local_2c = local_44 - param_4;
          iVar26 = (param_3 + -1) * iVar2;
          local_28 = (param_2 - param_4) * 2;
          local_34 = ((param_3 - uVar17) + 1) * iVar2;
          do {
            local_38 = local_38 + 1;
            local_3c = local_3c + -2;
            local_40 = local_40 - 1;
            local_44 = local_44 - 1;
            local_48 = local_48 + 2;
            local_4c = local_4c + 1;
            if ((local_2c <= uVar23) && (local_38 <= (uint)(iVar10 - iVar4))) {
              *(ushort *)(local_34 + local_28 + iVar1) = (ushort)param_5;
            }
            if ((param_8 <= uVar23) && (local_38 <= (uint)(iVar10 - iVar4))) {
              *(ushort *)(local_34 + param_7 + iVar1) = (ushort)param_5;
            }
            if ((local_2c <= uVar23) && (local_40 <= (uint)(iVar10 - iVar4))) {
              *(ushort *)(local_28 + iVar26 + iVar1) = (ushort)param_5;
            }
            if ((param_8 <= uVar23) && (local_40 <= (uint)(iVar10 - iVar4))) {
              *(ushort *)(param_7 + iVar26 + iVar1) = (ushort)param_5;
            }
            if ((local_44 <= uVar23) && (local_20 <= (uint)(iVar10 - iVar4))) {
              *(ushort *)(local_1c + local_3c + iVar1) = (ushort)param_5;
            }
            if ((local_4c <= uVar23) && (local_20 <= (uint)(iVar10 - iVar4))) {
              *(ushort *)(local_1c + local_48 + iVar1) = (ushort)param_5;
            }
            if ((local_44 <= uVar23) && (local_30 <= (uint)(iVar10 - iVar4))) {
              *(ushort *)(local_3c + local_24 + iVar1) = (ushort)param_5;
            }
            if ((local_4c <= uVar23) && (local_30 <= (uint)(iVar10 - iVar4))) {
              *(ushort *)(local_24 + local_48 + iVar1) = (ushort)param_5;
            }
            if (-1 < local_68) {
              local_1c = local_1c + -iVar2;
              param_7 = param_7 + -2;
              param_8 = (uint *)((int)param_8 - 1);
              local_20 = local_20 - 1;
              local_24 = local_24 + iVar2;
              local_28 = local_28 + 2;
              local_2c = local_2c + 1;
              local_30 = local_30 + 1;
              local_18 = local_18 + -4;
              param_4 = param_4 + -1;
              local_68 = local_68 - local_18;
            }
            local_34 = local_34 + iVar2;
            iVar26 = iVar26 + -iVar2;
            param_1 = param_1 + 1;
            local_68 = local_68 + 2 + param_1 * 4;
          } while (param_1 <= param_4);
          return;
        }
        break;
      case 2:
        if (DAT_00dca3f8 != 0) {
          if (uVar17 == 0) {
            uVar23 = iVar6 - DAT_00dca3e4;
            if (((param_2 - param_4) - DAT_00dca3e4 <= uVar23) &&
               ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar10 - DAT_00dca3e8))) {
              puVar25 = (ushort *)(iVar2 * param_3 + iVar1 + (param_2 - param_4) * 2);
              uVar9 = (*(short *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                      *(short *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_5 >> 5 & 0x3f))) *
                      0x20 + *(short *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_5 & 0x1f));
              uVar8 = (*puVar25 & 0xf7def7df) + (uVar9 & 0xf7def7df);
              uVar27 = uVar8 & 0x8210820;
              *puVar25 = (short)uVar27 - (short)(uVar27 >> 5) | (uVar9 | *puVar25) & 0x820 |
                         (ushort)uVar8;
            }
            iVar7 = (param_2 - uVar15) + param_4;
            if (((uint)(iVar7 - iVar26) <= uVar23) &&
               ((uint)(param_3 - iVar4) <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(iVar2 * param_3 + iVar1 + iVar7 * 2);
              uVar9 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                      *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20 +
                      *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
              uVar23 = (*puVar25 & 0xf7def7df) + (uVar9 & 0xf7def7df);
              uVar8 = uVar23 & 0x8210820;
              *puVar25 = (short)uVar8 - (short)(uVar8 >> 5) | (uVar9 | *puVar25) & 0x820 |
                         (ushort)uVar23;
            }
          }
          if (uVar15 == 0) {
            iVar7 = (param_3 - uVar17) + param_4;
            if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
               ((uint)(iVar7 - iVar4) <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(iVar7 * iVar2 + iVar1 + param_2 * 2);
              uVar9 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                      *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20 +
                      *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
              uVar23 = (*puVar25 & 0xf7def7df) + (uVar9 & 0xf7def7df);
              uVar8 = uVar23 & 0x8210820;
              *puVar25 = (short)uVar8 - (short)(uVar8 >> 5) | (uVar9 | *puVar25) & 0x820 |
                         (ushort)uVar23;
            }
            if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
               ((uint)((param_3 - param_4) - iVar4) <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)((param_3 - param_4) * iVar2 + iVar1 + param_2 * 2);
              uVar9 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                      *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20 +
                      *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
              uVar23 = (*puVar25 & 0xf7def7df) + (uVar9 & 0xf7def7df);
              uVar8 = uVar23 & 0x8210820;
              *puVar25 = (short)uVar8 - (short)(uVar8 >> 5) | (uVar9 | *puVar25) & 0x820 |
                         (ushort)uVar23;
            }
          }
          if (-1 < local_68) {
            param_4 = param_4 + -1;
            local_68 = local_68 + param_4 * -4;
          }
          local_68 = local_68 + 6;
          param_1 = 1;
          if (0 < param_4) {
            uVar23 = iVar6 - iVar26;
            local_18 = param_4 * 4;
            local_4c = param_3 - iVar4;
            local_34 = local_4c - param_4;
            local_50 = param_2 - iVar26;
            local_64 = local_50 - uVar15;
            local_54 = (param_2 - uVar15) * 2;
            local_28 = (param_3 - param_4) * iVar2;
            local_44 = param_2 * 2;
            local_24 = ((param_4 - iVar4) - uVar17) + param_3;
            local_20 = ((param_4 - uVar17) + param_3) * iVar2;
            local_1c = ((param_4 - iVar26) - uVar15) + param_2;
            param_7 = ((param_4 - uVar15) + param_2) * 2;
            local_30 = local_50 - param_4;
            local_40 = (param_3 + -1) * iVar2;
            local_2c = (param_2 - param_4) * 2;
            local_3c = local_4c - uVar17;
            local_38 = ((param_3 - uVar17) + 1) * iVar2;
            do {
              local_3c = local_3c + 1;
              local_44 = local_44 + -2;
              local_4c = local_4c - 1;
              local_50 = local_50 - 1;
              local_54 = local_54 + 2;
              local_64 = local_64 + 1;
              if ((local_30 <= uVar23) && (local_3c <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_38 + local_2c + iVar1);
                uVar14 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
                uVar9 = *puVar25;
                uVar15 = (uVar9 & 0xf7def7df) + (uVar14 & 0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) | (uVar14 | uVar9) & 0x820 |
                           (ushort)uVar15;
              }
              if ((local_1c <= uVar23) && (local_3c <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_38 + param_7 + iVar1);
                uVar14 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
                uVar9 = *puVar25;
                uVar15 = (uVar9 & 0xf7def7df) + (uVar14 & 0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) | (uVar14 | uVar9) & 0x820 |
                           (ushort)uVar15;
              }
              if ((local_30 <= uVar23) && (local_4c <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_2c + local_40 + iVar1);
                uVar14 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
                uVar9 = *puVar25;
                uVar15 = (uVar9 & 0xf7def7df) + (uVar14 & 0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) | (uVar14 | uVar9) & 0x820 |
                           (ushort)uVar15;
              }
              if ((local_1c <= uVar23) && (local_4c <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_40 + param_7 + iVar1);
                uVar14 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
                uVar9 = *puVar25;
                uVar15 = (uVar9 & 0xf7def7df) + (uVar14 & 0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) | (uVar14 | uVar9) & 0x820 |
                           (ushort)uVar15;
              }
              if ((local_50 <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_20 + local_44 + iVar1);
                uVar14 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
                uVar9 = *puVar25;
                uVar15 = (uVar9 & 0xf7def7df) + (uVar14 & 0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) | (uVar14 | uVar9) & 0x820 |
                           (ushort)uVar15;
              }
              if ((local_64 <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_20 + local_54 + iVar1);
                uVar9 = *puVar25;
                uVar14 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
                uVar15 = (uVar9 & 0xf7def7df) + (uVar14 & 0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) | (uVar14 | uVar9) & 0x820 |
                           (ushort)uVar15;
              }
              if ((local_50 <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_44 + local_28 + iVar1);
                uVar9 = *puVar25;
                uVar14 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
                uVar15 = (uVar9 & 0xf7def7df) + (uVar14 & 0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) | (uVar14 | uVar9) & 0x820 |
                           (ushort)uVar15;
              }
              if ((local_64 <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_28 + local_54 + iVar1);
                uVar9 = *puVar25;
                uVar14 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
                uVar15 = (uVar9 & 0xf7def7df) + (uVar14 & 0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) | (uVar14 | uVar9) & 0x820 |
                           (ushort)uVar15;
              }
              if (-1 < local_68) {
                local_20 = local_20 + -iVar2;
                param_7 = param_7 + -2;
                local_1c = local_1c - 1;
                local_28 = local_28 + iVar2;
                local_2c = local_2c + 2;
                local_24 = local_24 - 1;
                local_30 = local_30 + 1;
                local_34 = local_34 + 1;
                local_18 = local_18 + -4;
                param_4 = param_4 + -1;
                local_68 = local_68 - local_18;
              }
              local_38 = local_38 + iVar2;
              param_1 = param_1 + 1;
              local_40 = local_40 + -iVar2;
              local_68 = local_68 + 2 + param_1 * 4;
            } while (param_1 <= param_4);
            return;
          }
        }
        break;
      case 3:
        if (DAT_00dca3f8 != 0) {
          if (uVar17 == 0) {
            uVar23 = iVar6 - DAT_00dca3e4;
            if (((param_2 - param_4) - DAT_00dca3e4 <= uVar23) &&
               ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar10 - DAT_00dca3e8))) {
              puVar25 = (ushort *)(iVar2 * param_3 + iVar1 + (param_2 - param_4) * 2);
              uVar8 = (*puVar25 | 0x8210820) -
                      ((ushort)((*(short *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_5 >> 0xb))
                                 * 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                    DAT_00dca3f8 * 0x100 + (param_5 >> 5 & 0x3f))) *
                                0x20 + *(short *)(&DAT_00d0a2e0 +
                                                 DAT_00dca3f8 * 0x100 + (param_5 & 0x1f))) &
                      0xf7def7df);
              uVar27 = uVar8 & 0x8210820;
              *puVar25 = (short)uVar27 - (short)(uVar27 >> 5) & (ushort)uVar8;
            }
            iVar7 = (param_2 - uVar15) + param_4;
            if (((uint)(iVar7 - iVar26) <= uVar23) &&
               ((uint)(param_3 - iVar4) <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(iVar2 * param_3 + iVar1 + iVar7 * 2);
              uVar23 = (*puVar25 | 0x8210820) -
                       ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                  0x40 + *(short *)(&DAT_00d0a2e0 +
                                                   iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20 +
                                *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                       0xf7def7df);
              uVar8 = uVar23 & 0x8210820;
              *puVar25 = (short)uVar8 - (short)(uVar8 >> 5) & (ushort)uVar23;
            }
          }
          if (uVar15 == 0) {
            iVar7 = (param_3 - uVar17) + param_4;
            if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
               ((uint)(iVar7 - iVar4) <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(iVar7 * iVar2 + iVar1 + param_2 * 2);
              uVar23 = (*puVar25 | 0x8210820) -
                       ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                  0x40 + *(short *)(&DAT_00d0a2e0 +
                                                   iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20 +
                                *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                       0xf7def7df);
              uVar8 = uVar23 & 0x8210820;
              *puVar25 = (short)uVar8 - (short)(uVar8 >> 5) & (ushort)uVar23;
            }
            if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
               ((uint)((param_3 - param_4) - iVar4) <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)((param_3 - param_4) * iVar2 + iVar1 + param_2 * 2);
              uVar23 = (*puVar25 | 0x8210820) -
                       ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                  0x40 + *(short *)(&DAT_00d0a2e0 +
                                                   iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20 +
                                *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                       0xf7def7df);
              uVar8 = uVar23 & 0x8210820;
              *puVar25 = (short)uVar8 - (short)(uVar8 >> 5) & (ushort)uVar23;
            }
          }
          if (-1 < local_68) {
            param_4 = param_4 + -1;
            local_68 = local_68 + param_4 * -4;
          }
          local_68 = local_68 + 6;
          param_1 = 1;
          if (0 < param_4) {
            uVar23 = iVar6 - iVar26;
            local_18 = param_4 * 4;
            local_48 = param_3 - iVar4;
            local_34 = local_48 - param_4;
            local_4c = param_2 - iVar26;
            local_54 = local_4c - uVar15;
            local_50 = (param_2 - uVar15) * 2;
            local_28 = (param_3 - param_4) * iVar2;
            local_44 = param_2 * 2;
            local_24 = ((param_4 - iVar4) - uVar17) + param_3;
            local_20 = ((param_4 - uVar17) + param_3) * iVar2;
            local_1c = ((param_4 - iVar26) - uVar15) + param_2;
            param_7 = ((param_4 - uVar15) + param_2) * 2;
            local_30 = local_4c - param_4;
            local_40 = (param_3 + -1) * iVar2;
            local_2c = (param_2 - param_4) * 2;
            local_3c = local_48 - uVar17;
            local_38 = ((param_3 - uVar17) + 1) * iVar2;
            do {
              local_3c = local_3c + 1;
              local_44 = local_44 + -2;
              local_48 = local_48 - 1;
              local_4c = local_4c - 1;
              local_50 = local_50 + 2;
              local_54 = local_54 + 1;
              if ((local_30 <= uVar23) && (local_3c <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_38 + local_2c + iVar1);
                uVar15 = (*puVar25 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                         0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) & (ushort)uVar15;
              }
              if ((local_1c <= uVar23) && (local_3c <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_38 + param_7 + iVar1);
                uVar15 = (*puVar25 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                         0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) & (ushort)uVar15;
              }
              if ((local_30 <= uVar23) && (local_48 <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_2c + local_40 + iVar1);
                uVar15 = (*puVar25 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                         0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) & (ushort)uVar15;
              }
              if ((local_1c <= uVar23) && (local_48 <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_40 + param_7 + iVar1);
                uVar15 = (*puVar25 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                         0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) & (ushort)uVar15;
              }
              if ((local_4c <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_20 + local_44 + iVar1);
                uVar15 = (*puVar25 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                         0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) & (ushort)uVar15;
              }
              if ((local_54 <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_20 + local_50 + iVar1);
                uVar15 = (*puVar25 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                         0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) & (ushort)uVar15;
              }
              if ((local_4c <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_44 + local_28 + iVar1);
                uVar15 = (*puVar25 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                         0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) & (ushort)uVar15;
              }
              if ((local_54 <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
                puVar25 = (ushort *)(local_28 + local_50 + iVar1);
                uVar15 = (*puVar25 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                         0xf7def7df);
                uVar17 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar17 - (short)(uVar17 >> 5) & (ushort)uVar15;
              }
              if (-1 < local_68) {
                local_20 = local_20 + -iVar2;
                param_7 = param_7 + -2;
                local_1c = local_1c - 1;
                local_28 = local_28 + iVar2;
                local_2c = local_2c + 2;
                local_24 = local_24 - 1;
                local_30 = local_30 + 1;
                local_34 = local_34 + 1;
                local_18 = local_18 + -4;
                param_4 = param_4 + -1;
                local_68 = local_68 - local_18;
              }
              local_38 = local_38 + iVar2;
              param_1 = param_1 + 1;
              local_40 = local_40 + -iVar2;
              local_68 = local_68 + 2 + param_1 * 4;
            } while (param_1 <= param_4);
            return;
          }
        }
        break;
      case 4:
        if (uVar17 == 0) {
          uVar23 = iVar6 - DAT_00dca3e4;
          if (((param_2 - param_4) - DAT_00dca3e4 <= uVar23) &&
             ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar10 - DAT_00dca3e8))) {
            puVar25 = (ushort *)(iVar2 * param_3 + iVar1 + (param_2 - param_4) * 2);
            uVar8 = (uint)*puVar25;
            *puVar25 = (ushort)((uVar8 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                       (ushort)((param_5 & 0xf800) * (uVar8 & 0xf800) >> 0x10) & 0xf800 |
                       (ushort)((uVar8 & 0x1f) * (param_5 & 0x1f) >> 5);
          }
          iVar18 = (param_2 - uVar15) + param_4;
          if (((uint)(iVar18 - iVar26) <= uVar23) &&
             ((uint)(param_3 - iVar4) <= (uint)(iVar10 - iVar4))) {
            puVar25 = (ushort *)(iVar2 * param_3 + iVar1 + iVar18 * 2);
            uVar23 = (uint)*puVar25;
            *puVar25 = (ushort)((uVar23 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                       (ushort)((param_5 & 0xf800) * (uVar23 & 0xf800) >> 0x10) & 0xf800 |
                       (ushort)((uVar23 & 0x1f) * (param_5 & 0x1f) >> 5);
          }
        }
        if (uVar15 == 0) {
          iVar18 = (param_3 - uVar17) + param_4;
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)(iVar18 - iVar4) <= (uint)(iVar10 - iVar4))) {
            puVar25 = (ushort *)(iVar18 * iVar2 + iVar1 + param_2 * 2);
            uVar23 = (uint)*puVar25;
            *puVar25 = (ushort)((uVar23 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                       (ushort)((param_5 & 0xf800) * (uVar23 & 0xf800) >> 0x10) & 0xf800 |
                       (ushort)((uVar23 & 0x1f) * (param_5 & 0x1f) >> 5);
          }
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)((param_3 - param_4) - iVar4) <= (uint)(iVar10 - iVar4))) {
            puVar25 = (ushort *)((param_3 - param_4) * iVar2 + iVar1 + param_2 * 2);
            uVar23 = (uint)*puVar25;
            *puVar25 = (ushort)((uVar23 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                       (ushort)((param_5 & 0xf800) * (uVar23 & 0xf800) >> 0x10) & 0xf800 |
                       (ushort)((uVar23 & 0x1f) * (param_5 & 0x1f) >> 5);
          }
        }
        if (-1 < local_68) {
          param_4 = param_4 + -1;
          local_68 = local_68 + param_4 * -4;
        }
        local_68 = local_68 + 6;
        param_1 = 1;
        if (0 < param_4) {
          uVar23 = iVar6 - iVar26;
          local_4c = param_2 - iVar26;
          local_18 = param_4 * 4;
          local_48 = param_3 - iVar4;
          local_34 = local_48 - param_4;
          local_54 = local_4c - uVar15;
          local_50 = (param_2 - uVar15) * 2;
          local_28 = (param_3 - param_4) * iVar2;
          local_44 = param_2 * 2;
          local_24 = ((param_4 - iVar4) - uVar17) + param_3;
          local_20 = ((param_4 - uVar17) + param_3) * iVar2;
          local_1c = ((param_4 - iVar26) - uVar15) + param_2;
          param_7 = ((param_4 - uVar15) + param_2) * 2;
          local_30 = local_4c - param_4;
          local_40 = (param_3 + -1) * iVar2;
          local_3c = local_48 - uVar17;
          local_2c = (param_2 - param_4) * 2;
          local_38 = ((param_3 - uVar17) + 1) * iVar2;
          do {
            local_3c = local_3c + 1;
            local_44 = local_44 + -2;
            local_48 = local_48 - 1;
            local_4c = local_4c - 1;
            local_50 = local_50 + 2;
            local_54 = local_54 + 1;
            if ((local_30 <= uVar23) && (local_3c <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_38 + local_2c + iVar1);
              uVar15 = (uint)*puVar25;
              *puVar25 = (ushort)((uVar15 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_5 & 0xf800) * (uVar15 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar15 & 0x1f) * (param_5 & 0x1f) >> 5);
            }
            if ((local_1c <= uVar23) && (local_3c <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_38 + param_7 + iVar1);
              uVar15 = (uint)*puVar25;
              *puVar25 = (ushort)((uVar15 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_5 & 0xf800) * (uVar15 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar15 & 0x1f) * (param_5 & 0x1f) >> 5);
            }
            if ((local_30 <= uVar23) && (local_48 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_2c + local_40 + iVar1);
              uVar15 = (uint)*puVar25;
              *puVar25 = (ushort)((uVar15 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_5 & 0xf800) * (uVar15 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar15 & 0x1f) * (param_5 & 0x1f) >> 5);
            }
            if ((local_1c <= uVar23) && (local_48 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_40 + param_7 + iVar1);
              uVar15 = (uint)*puVar25;
              *puVar25 = (ushort)((uVar15 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_5 & 0xf800) * (uVar15 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar15 & 0x1f) * (param_5 & 0x1f) >> 5);
            }
            if ((local_4c <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_20 + local_44 + iVar1);
              uVar15 = (uint)*puVar25;
              *puVar25 = (ushort)((uVar15 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_5 & 0xf800) * (uVar15 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar15 & 0x1f) * (param_5 & 0x1f) >> 5);
            }
            if ((local_54 <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_20 + local_50 + iVar1);
              uVar15 = (uint)*puVar25;
              *puVar25 = (ushort)((uVar15 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_5 & 0xf800) * (uVar15 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar15 & 0x1f) * (param_5 & 0x1f) >> 5);
            }
            if ((local_4c <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_44 + local_28 + iVar1);
              uVar15 = (uint)*puVar25;
              *puVar25 = (ushort)((uVar15 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_5 & 0xf800) * (uVar15 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar15 & 0x1f) * (param_5 & 0x1f) >> 5);
            }
            if ((local_54 <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_28 + local_50 + iVar1);
              uVar15 = (uint)*puVar25;
              *puVar25 = (ushort)((uVar15 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_5 & 0xf800) * (uVar15 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar15 & 0x1f) * (param_5 & 0x1f) >> 5);
            }
            if (-1 < local_68) {
              local_1c = local_1c - 1;
              local_20 = local_20 + -iVar2;
              local_24 = local_24 - 1;
              local_28 = local_28 + iVar2;
              local_30 = local_30 + 1;
              local_34 = local_34 + 1;
              param_7 = param_7 + -2;
              local_2c = local_2c + 2;
              local_18 = local_18 + -4;
              param_4 = param_4 + -1;
              local_68 = local_68 - local_18;
            }
            local_38 = local_38 + iVar2;
            param_1 = param_1 + 1;
            local_40 = local_40 + -iVar2;
            local_68 = local_68 + 2 + param_1 * 4;
          } while (param_1 <= param_4);
          return;
        }
        break;
      case 10:
        if (uVar17 == 0) {
          uVar23 = iVar6 - DAT_00dca3e4;
          if (((param_2 - param_4) - DAT_00dca3e4 <= uVar23) &&
             ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar10 - DAT_00dca3e8))) {
            puVar25 = (ushort *)(iVar2 * param_3 + iVar1 + (param_2 - param_4) * 2);
            uVar9 = *puVar25;
            uVar8 = ~param_5 & 0xffff;
            *puVar25 = ((uVar9 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((uVar8 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                 DAT_00dca3f8 * 0x800)) * 0x20 |
                       ((uVar9 >> 0xb) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((uVar8 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + DAT_00dca3f8 * 0x800)
                       ) * 0x800 |
                       (uVar9 & 0x1f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + DAT_00dca3f8 * 0x800);
          }
          iVar7 = (param_2 - uVar15) + param_4;
          if (((uint)(iVar7 - iVar26) <= uVar23) &&
             ((uint)(param_3 - iVar4) <= (uint)(iVar10 - iVar4))) {
            puVar25 = (ushort *)(iVar2 * param_3 + iVar1 + iVar7 * 2);
            uVar9 = *puVar25;
            uVar23 = ~param_5 & 0xffff;
            *puVar25 = ((uVar9 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((uVar23 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800))
                       * 0x20 | ((uVar9 >> 0xb) +
                                *(short *)(&DAT_00d4a6e0 +
                                          ((uVar23 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 +
                                          iVar18 * 0x800)) * 0x800 |
                       (uVar9 & 0x1f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
          }
        }
        if (uVar15 == 0) {
          iVar7 = (param_3 - uVar17) + param_4;
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)(iVar7 - iVar4) <= (uint)(iVar10 - iVar4))) {
            puVar25 = (ushort *)(iVar7 * iVar2 + iVar1 + param_2 * 2);
            uVar9 = *puVar25;
            uVar23 = ~param_5 & 0xffff;
            *puVar25 = ((uVar9 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((uVar23 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800))
                       * 0x20 | ((uVar9 >> 0xb) +
                                *(short *)(&DAT_00d4a6e0 +
                                          ((uVar23 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 +
                                          iVar18 * 0x800)) * 0x800 |
                       (uVar9 & 0x1f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
          }
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)((param_3 - param_4) - iVar4) <= (uint)(iVar10 - iVar4))) {
            puVar25 = (ushort *)((param_3 - param_4) * iVar2 + iVar1 + param_2 * 2);
            uVar9 = *puVar25;
            uVar23 = ~param_5 & 0xffff;
            *puVar25 = ((uVar9 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((uVar23 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800))
                       * 0x20 | ((uVar9 >> 0xb) +
                                *(short *)(&DAT_00d4a6e0 +
                                          ((uVar23 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 +
                                          iVar18 * 0x800)) * 0x800 |
                       (uVar9 & 0x1f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
          }
        }
        if (-1 < local_68) {
          param_4 = param_4 + -1;
          local_68 = local_68 + param_4 * -4;
        }
        local_68 = local_68 + 6;
        param_1 = 1;
        if (0 < param_4) {
          uVar23 = iVar6 - iVar26;
          local_14 = param_4 * 4;
          local_50 = param_3 - iVar4;
          local_38 = local_50 - param_4;
          local_54 = param_2 - iVar26;
          local_18 = local_54 - uVar15;
          local_64 = (param_2 - uVar15) * 2;
          local_2c = (param_3 - param_4) * iVar2;
          local_4c = param_2 * 2;
          local_28 = ((param_4 - iVar4) - uVar17) + param_3;
          local_24 = ((param_4 - uVar17) + param_3) * iVar2;
          local_20 = ((param_4 - iVar26) - uVar15) + param_2;
          local_1c = ((param_4 - uVar15) + param_2) * 2;
          local_34 = local_54 - param_4;
          local_44 = (param_3 + -1) * iVar2;
          local_30 = (param_2 - param_4) * 2;
          local_40 = local_50 - uVar17;
          local_3c = ((param_3 - uVar17) + 1) * iVar2;
          do {
            local_18 = local_18 + 1;
            local_40 = local_40 + 1;
            local_4c = local_4c + -2;
            local_50 = local_50 - 1;
            local_54 = local_54 - 1;
            local_64 = local_64 + 2;
            if ((local_34 <= uVar23) && (local_40 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_30 + local_3c + iVar1);
              uVar9 = *puVar25;
              uVar15 = ~param_5 & 0xffff;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800
                                   )) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) *
                         0x800 | (uVar9 & 0x1f) +
                                 *(short *)(&DAT_00d4a6e0 +
                                           ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800
                                           );
            }
            if ((local_20 <= uVar23) && (local_40 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_3c + local_1c + iVar1);
              uVar9 = *puVar25;
              uVar15 = ~param_5 & 0xffff;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800
                                   )) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) *
                         0x800 | (uVar9 & 0x1f) +
                                 *(short *)(&DAT_00d4a6e0 +
                                           ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800
                                           );
            }
            if ((local_34 <= uVar23) && (local_50 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_30 + local_44 + iVar1);
              uVar9 = *puVar25;
              uVar15 = ~param_5 & 0xffff;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800
                                   )) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) *
                         0x800 | (uVar9 & 0x1f) +
                                 *(short *)(&DAT_00d4a6e0 +
                                           ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800
                                           );
            }
            if ((local_20 <= uVar23) && (local_50 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_44 + local_1c + iVar1);
              uVar9 = *puVar25;
              uVar15 = ~param_5 & 0xffff;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800
                                   )) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) *
                         0x800 | (uVar9 & 0x1f) +
                                 *(short *)(&DAT_00d4a6e0 +
                                           ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800
                                           );
            }
            if ((local_54 <= uVar23) && (local_28 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_24 + local_4c + iVar1);
              uVar9 = *puVar25;
              uVar15 = ~param_5 & 0xffff;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800
                                   )) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) *
                         0x800 | (uVar9 & 0x1f) +
                                 *(short *)(&DAT_00d4a6e0 +
                                           ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800
                                           );
            }
            if ((local_18 <= uVar23) && (local_28 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_24 + local_64 + iVar1);
              uVar9 = *puVar25;
              uVar15 = ~param_5 & 0xffff;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800
                                   )) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) *
                         0x800 | (uVar9 & 0x1f) +
                                 *(short *)(&DAT_00d4a6e0 +
                                           ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800
                                           );
            }
            if ((local_54 <= uVar23) && (local_38 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_4c + local_2c + iVar1);
              uVar9 = *puVar25;
              uVar15 = ~param_5 & 0xffff;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800
                                   )) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) *
                         0x800 | (uVar9 & 0x1f) +
                                 *(short *)(&DAT_00d4a6e0 +
                                           ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800
                                           );
            }
            if ((local_18 <= uVar23) && (local_38 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_2c + local_64 + iVar1);
              uVar9 = *puVar25;
              uVar15 = ~param_5 & 0xffff;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800
                                   )) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar15 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) *
                         0x800 | (uVar9 & 0x1f) +
                                 *(short *)(&DAT_00d4a6e0 +
                                           ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800
                                           );
            }
            if (-1 < local_68) {
              local_20 = local_20 - 1;
              local_24 = local_24 + -iVar2;
              local_28 = local_28 - 1;
              local_2c = local_2c + iVar2;
              local_34 = local_34 + 1;
              local_38 = local_38 + 1;
              local_1c = local_1c + -2;
              local_30 = local_30 + 2;
              local_14 = local_14 + -4;
              param_4 = param_4 + -1;
              local_68 = local_68 - local_14;
            }
            local_3c = local_3c + iVar2;
            param_1 = param_1 + 1;
            local_44 = local_44 + -iVar2;
            local_68 = local_68 + 2 + param_1 * 4;
          } while (param_1 <= param_4);
        }
        break;
      case 0xb:
        if (uVar17 == 0) {
          uVar23 = iVar6 - DAT_00dca3e4;
          if (((param_2 - param_4) - DAT_00dca3e4 <= uVar23) &&
             ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar10 - DAT_00dca3e8))) {
            puVar25 = (ushort *)(iVar2 * param_3 + iVar1 + (param_2 - param_4) * 2);
            uVar9 = *puVar25;
            uVar8 = uVar9 >> 5 & 0x3f;
            *puVar25 = ((uVar9 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((param_5 >> 5 & 0x3f) * uVar8 >> 6) - uVar8) * 4 +
                                 DAT_00dca3f8 * 0x800)) * 0x20 |
                       ((uVar9 >> 0xb) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                 (uint)(uVar9 >> 0xb)) * 4 + DAT_00dca3f8 * 0x800)) * 0x800 |
                       (uVar9 & 0x1f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((param_5 & 0x1f) * (uVar9 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                                 DAT_00dca3f8 * 0x800);
          }
          iVar7 = (param_2 - uVar15) + param_4;
          if (((uint)(iVar7 - iVar26) <= uVar23) &&
             ((uint)(param_3 - iVar4) <= (uint)(iVar10 - iVar4))) {
            puVar25 = (ushort *)(iVar2 * param_3 + iVar1 + iVar7 * 2);
            uVar9 = *puVar25;
            uVar23 = uVar9 >> 5 & 0x3f;
            *puVar25 = ((uVar9 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((param_5 >> 5 & 0x3f) * uVar23 >> 6) - uVar23) * 4 +
                                 iVar18 * 0x800)) * 0x20 |
                       ((uVar9 >> 0xb) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                 (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                       (uVar9 & 0x1f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((param_5 & 0x1f) * (uVar9 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                                 iVar18 * 0x800);
          }
        }
        if (uVar15 == 0) {
          iVar7 = (param_3 - uVar17) + param_4;
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)(iVar7 - iVar4) <= (uint)(iVar10 - iVar4))) {
            puVar25 = (ushort *)(iVar7 * iVar2 + iVar1 + param_2 * 2);
            uVar9 = *puVar25;
            uVar23 = uVar9 >> 5 & 0x3f;
            *puVar25 = ((uVar9 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((param_5 >> 5 & 0x3f) * uVar23 >> 6) - uVar23) * 4 +
                                 iVar18 * 0x800)) * 0x20 |
                       ((uVar9 >> 0xb) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                 (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                       (uVar9 & 0x1f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((param_5 & 0x1f) * (uVar9 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                                 iVar18 * 0x800);
          }
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)((param_3 - param_4) - iVar4) <= (uint)(iVar10 - iVar4))) {
            puVar25 = (ushort *)((param_3 - param_4) * iVar2 + iVar1 + param_2 * 2);
            uVar9 = *puVar25;
            uVar23 = uVar9 >> 5 & 0x3f;
            *puVar25 = ((uVar9 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((param_5 >> 5 & 0x3f) * uVar23 >> 6) - uVar23) * 4 +
                                 iVar18 * 0x800)) * 0x20 |
                       ((uVar9 >> 0xb) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                 (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                       (uVar9 & 0x1f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 (((param_5 & 0x1f) * (uVar9 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                                 iVar18 * 0x800);
          }
        }
        if (-1 < local_68) {
          param_4 = param_4 + -1;
          local_68 = local_68 + param_4 * -4;
        }
        local_68 = local_68 + 6;
        param_1 = 1;
        if (0 < param_4) {
          uVar23 = iVar6 - iVar26;
          local_18 = param_4 * 4;
          local_48 = param_3 - iVar4;
          local_34 = local_48 - param_4;
          local_4c = param_2 - iVar26;
          local_64 = local_4c - uVar15;
          local_50 = (param_2 - uVar15) * 2;
          local_28 = (param_3 - param_4) * iVar2;
          local_44 = param_2 * 2;
          local_24 = ((param_4 - iVar4) - uVar17) + param_3;
          local_20 = ((param_4 - uVar17) + param_3) * iVar2;
          local_1c = ((param_4 - iVar26) - uVar15) + param_2;
          param_7 = ((param_4 - uVar15) + param_2) * 2;
          local_30 = local_4c - param_4;
          local_40 = (param_3 + -1) * iVar2;
          local_2c = (param_2 - param_4) * 2;
          local_3c = local_48 - uVar17;
          local_38 = ((param_3 - uVar17) + 1) * iVar2;
          do {
            local_3c = local_3c + 1;
            local_44 = local_44 + -2;
            local_48 = local_48 - 1;
            local_4c = local_4c - 1;
            local_50 = local_50 + 2;
            local_64 = local_64 + 1;
            if ((local_30 <= uVar23) && (local_3c <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_2c + local_38 + iVar1);
              uVar9 = *puVar25;
              uVar15 = uVar9 >> 5 & 0x3f;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 5 & 0x3f) * uVar15 >> 6) - uVar15) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                   (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                         (uVar9 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 & 0x1f) * (uVar9 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                                   iVar18 * 0x800);
            }
            if ((local_1c <= uVar23) && (local_3c <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_38 + param_7 + iVar1);
              uVar9 = *puVar25;
              uVar15 = uVar9 >> 5 & 0x3f;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 5 & 0x3f) * uVar15 >> 6) - uVar15) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                   (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                         (uVar9 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 & 0x1f) * (uVar9 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                                   iVar18 * 0x800);
            }
            if ((local_30 <= uVar23) && (local_48 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_2c + local_40 + iVar1);
              uVar9 = *puVar25;
              uVar15 = uVar9 >> 5 & 0x3f;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 5 & 0x3f) * uVar15 >> 6) - uVar15) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                   (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                         (uVar9 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 & 0x1f) * (uVar9 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                                   iVar18 * 0x800);
            }
            if ((local_1c <= uVar23) && (local_48 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_40 + param_7 + iVar1);
              uVar9 = *puVar25;
              uVar15 = uVar9 >> 5 & 0x3f;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 5 & 0x3f) * uVar15 >> 6) - uVar15) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                   (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                         (uVar9 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 & 0x1f) * (uVar9 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                                   iVar18 * 0x800);
            }
            if ((local_4c <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_20 + local_44 + iVar1);
              uVar9 = *puVar25;
              uVar15 = uVar9 >> 5 & 0x3f;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 5 & 0x3f) * uVar15 >> 6) - uVar15) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                   (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                         (uVar9 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 & 0x1f) * (uVar9 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                                   iVar18 * 0x800);
            }
            if ((local_64 <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_20 + local_50 + iVar1);
              uVar9 = *puVar25;
              uVar15 = uVar9 >> 5 & 0x3f;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 5 & 0x3f) * uVar15 >> 6) - uVar15) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                   (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                         (uVar9 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 & 0x1f) * (uVar9 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                                   iVar18 * 0x800);
            }
            if ((local_4c <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_44 + local_28 + iVar1);
              uVar9 = *puVar25;
              uVar15 = uVar9 >> 5 & 0x3f;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 5 & 0x3f) * uVar15 >> 6) - uVar15) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                   (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                         (uVar9 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 & 0x1f) * (uVar9 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                                   iVar18 * 0x800);
            }
            if ((local_64 <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
              puVar25 = (ushort *)(local_28 + local_50 + iVar1);
              uVar9 = *puVar25;
              uVar15 = uVar9 >> 5 & 0x3f;
              *puVar25 = ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 5 & 0x3f) * uVar15 >> 6) - uVar15) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                   (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                         (uVar9 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_5 & 0x1f) * (uVar9 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                                   iVar18 * 0x800);
            }
            if (-1 < local_68) {
              local_1c = local_1c - 1;
              local_20 = local_20 + -iVar2;
              local_24 = local_24 - 1;
              local_28 = local_28 + iVar2;
              local_30 = local_30 + 1;
              local_34 = local_34 + 1;
              param_7 = param_7 + -2;
              local_2c = local_2c + 2;
              local_18 = local_18 + -4;
              param_4 = param_4 + -1;
              local_68 = local_68 - local_18;
            }
            local_38 = local_38 + iVar2;
            param_1 = param_1 + 1;
            local_40 = local_40 + -iVar2;
            local_68 = local_68 + 2 + param_1 * 4;
          } while (param_1 <= param_4);
          return;
        }
      }
    }
    else if (iVar7 == 1) {
      if ((DAT_00dca3fc & 0xffffff) == 0xffffff) {
        uVar8 = (uint)param_5._2_1_;
      }
      else {
        iVar7 = (uint)param_5._2_1_ * (DAT_00dca3fc >> 0x10 & 0xff);
        param_5._0_2_ =
             CONCAT11((char)((param_5 >> 8 & 0xff) * (DAT_00dca3fc >> 8 & 0xff) >> 8),(byte)param_5)
        ;
        uVar27 = (uint)(ushort)param_5;
        uVar8 = iVar7 >> 8;
        param_5._0_3_ = CONCAT12((char)((uint)iVar7 >> 8),(ushort)param_5);
        param_5 = CONCAT31(param_5._1_3_,(char)((uVar27 & 0xff) * (DAT_00dca3fc & 0xff) >> 8));
      }
      switch(DAT_00dca3f4) {
      case 1:
        if (DAT_00dca3f8 != 0xff) {
          if (DAT_00dca3f8 == 0) {
            return;
          }
          if (uVar17 == 0) {
            uVar23 = iVar6 - DAT_00dca3e4;
            if (((param_2 - param_4) - DAT_00dca3e4 <= uVar23) &&
               ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar10 - DAT_00dca3e8))) {
              pbVar19 = (byte *)(iVar2 * param_3 + iVar1 + (param_2 - param_4) * 4);
              *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)((uVar8 - pbVar19[2]) * DAT_00dca3f8 + (uint)pbVar19[2] * 0x100 >>
                                 8);
            }
            iVar18 = (param_2 - uVar15) + param_4;
            if (((uint)(iVar18 - iVar26) <= uVar23) &&
               ((uint)(param_3 - iVar4) <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(iVar2 * param_3 + iVar1 + iVar18 * 4);
              *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)((uVar8 - pbVar19[2]) * DAT_00dca3f8 + (uint)pbVar19[2] * 0x100 >>
                                 8);
            }
          }
          if (uVar15 == 0) {
            iVar18 = (param_3 - uVar17) + param_4;
            if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
               ((uint)(iVar18 - iVar4) <= (uint)(iVar10 - iVar4))) {
              iVar18 = iVar18 * iVar2 + iVar1;
              uVar23 = (uint)*(byte *)(iVar18 + param_2 * 4);
              puVar20 = (undefined1 *)(iVar18 + param_2 * 4);
              *puVar20 = (char)(((param_5 & 0xff) - uVar23) * DAT_00dca3f8 + uVar23 * 0x100 >> 8);
              puVar20[1] = (char)(((uint)param_5._1_1_ - (uint)(byte)puVar20[1]) * DAT_00dca3f8 +
                                  (uint)(byte)puVar20[1] * 0x100 >> 8);
              puVar20[2] = (char)((uVar8 - (byte)puVar20[2]) * DAT_00dca3f8 +
                                  (uint)(byte)puVar20[2] * 0x100 >> 8);
            }
            if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
               ((uint)((param_3 - param_4) - iVar4) <= (uint)(iVar10 - iVar4))) {
              iVar18 = (param_3 - param_4) * iVar2 + iVar1;
              uVar23 = (uint)*(byte *)(iVar18 + param_2 * 4);
              puVar20 = (undefined1 *)(iVar18 + param_2 * 4);
              *puVar20 = (char)(((param_5 & 0xff) - uVar23) * DAT_00dca3f8 + uVar23 * 0x100 >> 8);
              puVar20[1] = (char)(((uint)param_5._1_1_ - (uint)(byte)puVar20[1]) * DAT_00dca3f8 +
                                  (uint)(byte)puVar20[1] * 0x100 >> 8);
              puVar20[2] = (char)((uVar8 - (byte)puVar20[2]) * DAT_00dca3f8 +
                                  (uint)(byte)puVar20[2] * 0x100 >> 8);
            }
          }
          if (-1 < local_68) {
            param_4 = param_4 + -1;
            local_68 = local_68 + param_4 * -4;
          }
          local_68 = local_68 + 6;
          param_1 = 1;
          if (param_4 < 1) {
            return;
          }
          uVar23 = iVar6 - iVar26;
          local_64 = param_2 - iVar26;
          local_18 = param_4 * 4;
          local_60 = param_3 - iVar4;
          local_4c = local_60 - param_4;
          local_2c = local_64 - uVar15;
          local_30 = (param_2 - uVar15) * 4;
          local_40 = (param_3 - param_4) * iVar2;
          local_5c = param_2 * 4;
          local_3c = ((param_4 - iVar4) - uVar17) + param_3;
          local_38 = ((param_4 - uVar17) + param_3) * iVar2;
          local_34 = ((param_4 - iVar26) - uVar15) + param_2;
          param_7 = ((param_4 - uVar15) + param_2) * 4;
          local_44 = (param_2 - param_4) * 4;
          local_48 = local_64 - param_4;
          local_54 = (param_3 + -1) * iVar2;
          local_50 = local_60 - uVar17;
          param_8 = (uint *)(((param_3 - uVar17) + 1) * iVar2);
          do {
            local_2c = local_2c + 1;
            local_30 = local_30 + 4;
            local_50 = local_50 + 1;
            local_5c = local_5c + -4;
            local_60 = local_60 - 1;
            local_64 = local_64 - 1;
            if ((local_48 <= uVar23) && (local_50 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)((int)param_8 + local_44 + iVar1);
              *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)((uVar8 - pbVar19[2]) * DAT_00dca3f8 + (uint)pbVar19[2] * 0x100 >>
                                 8);
            }
            if ((local_34 <= uVar23) && (local_50 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)((int)param_8 + param_7 + iVar1);
              *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)((uVar8 - pbVar19[2]) * DAT_00dca3f8 + (uint)pbVar19[2] * 0x100 >>
                                 8);
            }
            if ((local_48 <= uVar23) && (local_60 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_44 + local_54 + iVar1);
              *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)((uVar8 - pbVar19[2]) * DAT_00dca3f8 + (uint)pbVar19[2] * 0x100 >>
                                 8);
            }
            if ((local_34 <= uVar23) && (local_60 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_54 + param_7 + iVar1);
              *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)((uVar8 - pbVar19[2]) * DAT_00dca3f8 + (uint)pbVar19[2] * 0x100 >>
                                 8);
            }
            if ((local_64 <= uVar23) && (local_3c <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_38 + local_5c + iVar1);
              *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)((uVar8 - pbVar19[2]) * DAT_00dca3f8 + (uint)pbVar19[2] * 0x100 >>
                                 8);
            }
            if ((local_2c <= uVar23) && (local_3c <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_38 + local_30 + iVar1);
              *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)((uVar8 - pbVar19[2]) * DAT_00dca3f8 + (uint)pbVar19[2] * 0x100 >>
                                 8);
            }
            if ((local_64 <= uVar23) && (local_4c <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_5c + local_40 + iVar1);
              *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)((uVar8 - pbVar19[2]) * DAT_00dca3f8 + (uint)pbVar19[2] * 0x100 >>
                                 8);
            }
            if ((local_2c <= uVar23) && (local_4c <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_40 + local_30 + iVar1);
              *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)((uVar8 - pbVar19[2]) * DAT_00dca3f8 + (uint)pbVar19[2] * 0x100 >>
                                 8);
            }
            if (-1 < local_68) {
              local_38 = local_38 + -iVar2;
              local_40 = local_40 + iVar2;
              local_34 = local_34 - 1;
              local_3c = local_3c - 1;
              local_48 = local_48 + 1;
              local_4c = local_4c + 1;
              param_4 = param_4 + -1;
              param_7 = param_7 + -4;
              local_44 = local_44 + 4;
              local_18 = local_18 + -4;
              local_68 = local_68 - local_18;
            }
            local_54 = local_54 + -iVar2;
            param_8 = (uint *)((int)param_8 + iVar2);
            param_1 = param_1 + 1;
            local_68 = local_68 + 2 + param_1 * 4;
          } while (param_1 <= param_4);
          return;
        }
      case 0:
        if (uVar17 == 0) {
          uVar23 = iVar6 - DAT_00dca3e4;
          if (((param_2 - param_4) - DAT_00dca3e4 <= uVar23) &&
             ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar10 - DAT_00dca3e8))) {
            *(uint *)(iVar2 * param_3 + iVar1 + (param_2 - param_4) * 4) = param_5;
          }
          iVar18 = (param_2 - uVar15) + param_4;
          if (((uint)(iVar18 - iVar26) <= uVar23) &&
             ((uint)(param_3 - iVar4) <= (uint)(iVar10 - iVar4))) {
            *(uint *)(iVar2 * param_3 + iVar1 + iVar18 * 4) = param_5;
          }
        }
        if (uVar15 == 0) {
          iVar18 = (param_3 - uVar17) + param_4;
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)(iVar18 - iVar4) <= (uint)(iVar10 - iVar4))) {
            *(uint *)(iVar18 * iVar2 + iVar1 + param_2 * 4) = param_5;
          }
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)((param_3 - param_4) - iVar4) <= (uint)(iVar10 - iVar4))) {
            *(uint *)((param_3 - param_4) * iVar2 + iVar1 + param_2 * 4) = param_5;
          }
        }
        if (-1 < local_68) {
          param_4 = param_4 + -1;
          local_68 = local_68 + param_4 * -4;
        }
        local_68 = local_68 + 6;
        param_1 = 1;
        if (0 < param_4) {
          uVar23 = iVar6 - iVar26;
          local_64 = param_2 - iVar26;
          local_18 = param_4 * 4;
          local_60 = param_3 - iVar4;
          local_50 = local_60 - param_4;
          local_34 = local_64 - uVar15;
          local_38 = (param_2 - uVar15) * 4;
          local_44 = (param_3 - param_4) * iVar2;
          local_5c = param_2 * 4;
          local_40 = ((param_4 - iVar4) - uVar17) + param_3;
          local_3c = ((param_4 - uVar17) + param_3) * iVar2;
          param_7 = ((param_4 - uVar15) + param_2) * 4;
          uVar15 = ((param_4 - iVar26) - uVar15) + param_2;
          local_48 = (param_2 - param_4) * 4;
          local_4c = local_64 - param_4;
          iVar26 = (param_3 + -1) * iVar2;
          local_54 = local_60 - uVar17;
          param_8 = (uint *)(((param_3 - uVar17) + 1) * iVar2);
          do {
            local_34 = local_34 + 1;
            local_38 = local_38 + 4;
            local_54 = local_54 + 1;
            local_5c = local_5c + -4;
            local_60 = local_60 - 1;
            local_64 = local_64 - 1;
            if ((local_4c <= uVar23) && (local_54 <= (uint)(iVar10 - iVar4))) {
              *(uint *)((int)param_8 + local_48 + iVar1) = param_5;
            }
            if ((uVar15 <= uVar23) && (local_54 <= (uint)(iVar10 - iVar4))) {
              *(uint *)((int)param_8 + param_7 + iVar1) = param_5;
            }
            if ((local_4c <= uVar23) && (local_60 <= (uint)(iVar10 - iVar4))) {
              *(uint *)(local_48 + iVar26 + iVar1) = param_5;
            }
            if ((uVar15 <= uVar23) && (local_60 <= (uint)(iVar10 - iVar4))) {
              *(uint *)(param_7 + iVar26 + iVar1) = param_5;
            }
            if ((local_64 <= uVar23) && (local_40 <= (uint)(iVar10 - iVar4))) {
              *(uint *)(local_3c + local_5c + iVar1) = param_5;
            }
            if ((local_34 <= uVar23) && (local_40 <= (uint)(iVar10 - iVar4))) {
              *(uint *)(local_3c + local_38 + iVar1) = param_5;
            }
            if ((local_64 <= uVar23) && (local_50 <= (uint)(iVar10 - iVar4))) {
              *(uint *)(local_5c + local_44 + iVar1) = param_5;
            }
            if ((local_34 <= uVar23) && (local_50 <= (uint)(iVar10 - iVar4))) {
              *(uint *)(local_44 + local_38 + iVar1) = param_5;
            }
            if (-1 < local_68) {
              local_3c = local_3c + -iVar2;
              param_7 = param_7 + -4;
              local_44 = local_44 + iVar2;
              local_48 = local_48 + 4;
              local_40 = local_40 - 1;
              local_4c = local_4c + 1;
              local_50 = local_50 + 1;
              local_18 = local_18 + -4;
              param_4 = param_4 + -1;
              uVar15 = uVar15 - 1;
              local_68 = local_68 - local_18;
            }
            param_1 = param_1 + 1;
            param_8 = (uint *)((int)param_8 + iVar2);
            iVar26 = iVar26 + -iVar2;
            local_68 = local_68 + 2 + param_1 * 4;
          } while (param_1 <= param_4);
          return;
        }
        break;
      case 2:
        if (DAT_00dca3f8 != 0) {
          if (uVar17 == 0) {
            uVar23 = iVar6 - DAT_00dca3e4;
            if ((param_2 - param_4) - DAT_00dca3e4 <= uVar23) {
              if ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar10 - DAT_00dca3e8)) {
                puVar21 = (uint *)(iVar2 * param_3 + iVar1 + (param_2 - param_4) * 4);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)
                               (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)
                               (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_5 & 0xff)));
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)
                               (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (uint)param_5._2_1_),
                              (undefined2)local_5c);
                local_5c = (uint)(uint3)local_5c;
                uVar8 = (local_5c & 0xfefeff) + (*puVar21 & 0xfefeff);
                uVar27 = uVar8 & 0x1010100;
                *puVar21 = uVar27 - (uVar27 >> 8) | (local_5c | *puVar21) & 0x10100 | uVar8;
              }
              uVar8 = (uint)param_5._2_1_;
            }
            iVar7 = (param_2 - uVar15) + param_4;
            if ((uint)(iVar7 - iVar26) <= uVar23) {
              if ((uint)(iVar10 - iVar4) < (uint)(param_3 - iVar4)) {
                uVar8 = (uint)param_5._2_1_;
              }
              else {
                puVar21 = (uint *)(iVar2 * param_3 + iVar1 + iVar7 * 4);
                uVar8 = (uint)param_5._2_1_;
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                local_5c = (uint)(uint3)local_5c;
                uVar23 = (local_5c & 0xfefeff) + (*puVar21 & 0xfefeff);
                uVar27 = uVar23 & 0x1010100;
                *puVar21 = uVar27 - (uVar27 >> 8) | (local_5c | *puVar21) & 0x10100 | uVar23;
              }
            }
          }
          if (uVar15 == 0) {
            iVar7 = (param_3 - uVar17) + param_4;
            if (param_2 - iVar26 <= (uint)(iVar6 - iVar26)) {
              if ((uint)(iVar7 - iVar4) <= (uint)(iVar10 - iVar4)) {
                puVar21 = (uint *)(iVar7 * iVar2 + iVar1 + param_2 * 4);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                              (undefined2)local_5c);
                local_5c = (uint)(uint3)local_5c;
                uVar23 = (local_5c & 0xfefeff) + (*puVar21 & 0xfefeff);
                uVar8 = uVar23 & 0x1010100;
                *puVar21 = uVar8 - (uVar8 >> 8) | (local_5c | *puVar21) & 0x10100 | uVar23;
              }
              uVar8 = (uint)param_5._2_1_;
            }
            if (param_2 - iVar26 <= (uint)(iVar6 - iVar26)) {
              if ((uint)(iVar10 - iVar4) < (uint)((param_3 - param_4) - iVar4)) {
                uVar8 = (uint)param_5._2_1_;
              }
              else {
                puVar21 = (uint *)((param_3 - param_4) * iVar2 + iVar1 + param_2 * 4);
                uVar8 = (uint)param_5._2_1_;
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                local_5c = (uint)(uint3)local_5c;
                uVar23 = (local_5c & 0xfefeff) + (*puVar21 & 0xfefeff);
                uVar27 = uVar23 & 0x1010100;
                *puVar21 = uVar27 - (uVar27 >> 8) | (local_5c | *puVar21) & 0x10100 | uVar23;
              }
            }
          }
          if (-1 < local_68) {
            param_4 = param_4 + -1;
            local_68 = local_68 + param_4 * -4;
          }
          local_68 = local_68 + 6;
          param_1 = 1;
          if (0 < param_4) {
            uVar23 = iVar6 - iVar26;
            local_24 = param_2 - iVar26;
            local_18 = param_4 * 4;
            local_28 = param_3 - iVar4;
            local_44 = local_28 - param_4;
            local_1c = local_24 - uVar15;
            local_20 = (param_2 - uVar15) * 4;
            local_38 = (param_3 - param_4) * iVar2;
            local_64 = param_2 * 4;
            local_34 = ((param_4 - iVar4) - uVar17) + param_3;
            local_30 = ((param_4 - uVar17) + param_3) * iVar2;
            local_2c = ((param_4 - iVar26) - uVar15) + param_2;
            param_7 = ((param_4 - uVar15) + param_2) * 4;
            local_40 = local_24 - param_4;
            local_50 = (param_3 + -1) * iVar2;
            local_3c = (param_2 - param_4) * 4;
            local_4c = local_28 - uVar17;
            local_48 = ((param_3 - uVar17) + 1) * iVar2;
            do {
              local_1c = local_1c + 1;
              local_20 = local_20 + 4;
              local_24 = local_24 - 1;
              local_28 = local_28 - 1;
              local_4c = local_4c + 1;
              local_64 = local_64 + -4;
              if ((local_40 <= uVar23) && (local_4c <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_48 + local_3c + iVar1);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                local_5c = (uint)(uint3)local_5c;
                uVar15 = *puVar21;
                uVar17 = (local_5c & 0xfefeff) + (uVar15 & 0xfefeff);
                uVar27 = uVar17 & 0x1010100;
                *puVar21 = uVar27 - (uVar27 >> 8) | (local_5c | uVar15) & 0x10100 | uVar17;
              }
              if ((local_2c <= uVar23) && (local_4c <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_48 + param_7 + iVar1);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                local_5c = (uint)(uint3)local_5c;
                uVar15 = *puVar21;
                uVar17 = (local_5c & 0xfefeff) + (uVar15 & 0xfefeff);
                uVar27 = uVar17 & 0x1010100;
                *puVar21 = uVar27 - (uVar27 >> 8) | (local_5c | uVar15) & 0x10100 | uVar17;
              }
              if ((local_40 <= uVar23) && (local_28 <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_3c + local_50 + iVar1);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                local_5c = (uint)(uint3)local_5c;
                uVar15 = *puVar21;
                uVar17 = (local_5c & 0xfefeff) + (uVar15 & 0xfefeff);
                uVar27 = uVar17 & 0x1010100;
                *puVar21 = uVar27 - (uVar27 >> 8) | (local_5c | uVar15) & 0x10100 | uVar17;
              }
              if ((local_2c <= uVar23) && (local_28 <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_50 + param_7 + iVar1);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                local_5c = (uint)(uint3)local_5c;
                uVar15 = *puVar21;
                uVar17 = (local_5c & 0xfefeff) + (uVar15 & 0xfefeff);
                uVar27 = uVar17 & 0x1010100;
                *puVar21 = uVar27 - (uVar27 >> 8) | (local_5c | uVar15) & 0x10100 | uVar17;
              }
              if ((local_24 <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_30 + local_64 + iVar1);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                local_5c = (uint)(uint3)local_5c;
                uVar15 = *puVar21;
                uVar17 = (local_5c & 0xfefeff) + (uVar15 & 0xfefeff);
                uVar27 = uVar17 & 0x1010100;
                *puVar21 = uVar27 - (uVar27 >> 8) | (local_5c | uVar15) & 0x10100 | uVar17;
              }
              if ((local_1c <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_30 + local_20 + iVar1);
                uVar15 = *puVar21;
                uVar17 = (uint)CONCAT21(CONCAT11(*(undefined1 *)
                                                  (&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                                                 *(undefined1 *)
                                                  (&DAT_00d0a2e0 +
                                                  iVar18 * 0x100 + (uint)param_5._1_1_)),
                                        *(undefined1 *)
                                         (&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                uVar27 = (uVar17 & 0xfefeff) + (uVar15 & 0xfefeff);
                uVar16 = uVar27 & 0x1010100;
                *puVar21 = uVar16 - (uVar16 >> 8) | (uVar17 | uVar15) & 0x10100 | uVar27;
              }
              if ((local_24 <= uVar23) && (local_44 <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_64 + local_38 + iVar1);
                uVar15 = *puVar21;
                uVar17 = (uint)CONCAT21(CONCAT11(*(undefined1 *)
                                                  (&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                                                 *(undefined1 *)
                                                  (&DAT_00d0a2e0 +
                                                  iVar18 * 0x100 + (uint)param_5._1_1_)),
                                        *(undefined1 *)
                                         (&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                uVar27 = (uVar17 & 0xfefeff) + (uVar15 & 0xfefeff);
                uVar16 = uVar27 & 0x1010100;
                *puVar21 = uVar16 - (uVar16 >> 8) | (uVar17 | uVar15) & 0x10100 | uVar27;
              }
              if ((local_1c <= uVar23) && (local_44 <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_38 + local_20 + iVar1);
                uVar15 = *puVar21;
                uVar17 = (uint)CONCAT21(CONCAT11(*(undefined1 *)
                                                  (&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                                                 *(undefined1 *)
                                                  (&DAT_00d0a2e0 +
                                                  iVar18 * 0x100 + (uint)param_5._1_1_)),
                                        *(undefined1 *)
                                         (&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                uVar27 = (uVar17 & 0xfefeff) + (uVar15 & 0xfefeff);
                uVar16 = uVar27 & 0x1010100;
                *puVar21 = uVar16 - (uVar16 >> 8) | (uVar17 | uVar15) & 0x10100 | uVar27;
              }
              if (-1 < local_68) {
                local_30 = local_30 + -iVar2;
                param_7 = param_7 + -4;
                local_2c = local_2c - 1;
                local_38 = local_38 + iVar2;
                local_3c = local_3c + 4;
                local_34 = local_34 - 1;
                local_40 = local_40 + 1;
                local_44 = local_44 + 1;
                local_18 = local_18 + -4;
                param_4 = param_4 + -1;
                local_68 = local_68 - local_18;
              }
              local_48 = local_48 + iVar2;
              param_1 = param_1 + 1;
              local_50 = local_50 + -iVar2;
              local_68 = local_68 + 2 + param_1 * 4;
            } while (param_1 <= param_4);
            return;
          }
        }
        break;
      case 3:
        if (DAT_00dca3f8 != 0) {
          if (uVar17 == 0) {
            uVar27 = iVar6 - DAT_00dca3e4;
            if ((param_2 - param_4) - DAT_00dca3e4 <= uVar27) {
              if ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar10 - DAT_00dca3e8)) {
                puVar21 = (uint *)(iVar2 * param_3 + iVar1 + (param_2 - param_4) * 4);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)
                               (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)
                               (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_5 & 0xff)));
                local_5c._3_1_ = SUB41(uVar23,3);
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)
                               (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (uint)param_5._2_1_),
                              (undefined2)local_5c);
                uVar23 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                uVar8 = uVar23 & 0x1010100;
                *puVar21 = uVar8 - (uVar8 >> 8) & uVar23;
              }
              uVar8 = (uint)param_5._2_1_;
            }
            uVar23 = local_5c;
            iVar7 = (param_2 - uVar15) + param_4;
            if ((uint)(iVar7 - iVar26) <= uVar27) {
              if ((uint)(iVar10 - iVar4) < (uint)(param_3 - iVar4)) {
                uVar8 = (uint)param_5._2_1_;
              }
              else {
                puVar21 = (uint *)(iVar2 * param_3 + iVar1 + iVar7 * 4);
                uVar8 = (uint)param_5._2_1_;
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._3_1_ = SUB41(uVar23,3);
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                uVar23 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                uVar27 = uVar23 & 0x1010100;
                *puVar21 = uVar27 - (uVar27 >> 8) & uVar23;
              }
            }
          }
          uVar23 = local_5c;
          if (uVar15 == 0) {
            iVar7 = (param_3 - uVar17) + param_4;
            if (param_2 - iVar26 <= (uint)(iVar6 - iVar26)) {
              if ((uint)(iVar7 - iVar4) <= (uint)(iVar10 - iVar4)) {
                puVar21 = (uint *)(iVar7 * iVar2 + iVar1 + param_2 * 4);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._3_1_ = SUB41(uVar23,3);
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                              (undefined2)local_5c);
                uVar23 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                uVar8 = uVar23 & 0x1010100;
                *puVar21 = uVar8 - (uVar8 >> 8) & uVar23;
              }
              uVar8 = (uint)param_5._2_1_;
            }
            uVar23 = local_5c;
            if (param_2 - iVar26 <= (uint)(iVar6 - iVar26)) {
              if ((uint)(iVar10 - iVar4) < (uint)((param_3 - param_4) - iVar4)) {
                uVar8 = (uint)param_5._2_1_;
              }
              else {
                puVar21 = (uint *)((param_3 - param_4) * iVar2 + iVar1 + param_2 * 4);
                uVar8 = (uint)param_5._2_1_;
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._3_1_ = SUB41(uVar23,3);
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                uVar23 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                uVar27 = uVar23 & 0x1010100;
                *puVar21 = uVar27 - (uVar27 >> 8) & uVar23;
              }
            }
          }
          if (-1 < local_68) {
            param_4 = param_4 + -1;
            local_68 = local_68 + param_4 * -4;
          }
          local_68 = local_68 + 6;
          param_1 = 1;
          if (0 < param_4) {
            uVar23 = iVar6 - iVar26;
            local_4c = param_2 - iVar26;
            local_18 = param_4 * 4;
            local_48 = param_3 - iVar4;
            local_34 = local_48 - param_4;
            local_54 = local_4c - uVar15;
            local_50 = (param_2 - uVar15) * 4;
            local_28 = (param_3 - param_4) * iVar2;
            local_44 = param_2 * 4;
            local_24 = ((param_4 - iVar4) - uVar17) + param_3;
            local_20 = ((param_4 - uVar17) + param_3) * iVar2;
            local_1c = ((param_4 - iVar26) - uVar15) + param_2;
            param_7 = ((param_4 - uVar15) + param_2) * 4;
            local_30 = local_4c - param_4;
            local_40 = (param_3 + -1) * iVar2;
            local_2c = (param_2 - param_4) * 4;
            local_3c = local_48 - uVar17;
            local_38 = ((param_3 - uVar17) + 1) * iVar2;
            do {
              uVar15 = local_5c;
              local_3c = local_3c + 1;
              local_44 = local_44 + -4;
              local_48 = local_48 - 1;
              local_4c = local_4c - 1;
              local_50 = local_50 + 4;
              local_54 = local_54 + 1;
              if ((local_30 <= uVar23) && (local_3c <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_38 + local_2c + iVar1);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._3_1_ = SUB41(uVar15,3);
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                uVar15 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                uVar17 = uVar15 & 0x1010100;
                *puVar21 = uVar17 - (uVar17 >> 8) & uVar15;
              }
              uVar15 = local_5c;
              if ((local_1c <= uVar23) && (local_3c <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_38 + param_7 + iVar1);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._3_1_ = SUB41(uVar15,3);
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                uVar15 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                uVar17 = uVar15 & 0x1010100;
                *puVar21 = uVar17 - (uVar17 >> 8) & uVar15;
              }
              uVar15 = local_5c;
              if ((local_30 <= uVar23) && (local_48 <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_2c + local_40 + iVar1);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._3_1_ = SUB41(uVar15,3);
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                uVar15 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                uVar17 = uVar15 & 0x1010100;
                *puVar21 = uVar17 - (uVar17 >> 8) & uVar15;
              }
              uVar15 = local_5c;
              if ((local_1c <= uVar23) && (local_48 <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_40 + param_7 + iVar1);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._3_1_ = SUB41(uVar15,3);
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                uVar15 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                uVar17 = uVar15 & 0x1010100;
                *puVar21 = uVar17 - (uVar17 >> 8) & uVar15;
              }
              uVar15 = local_5c;
              if ((local_4c <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_20 + local_44 + iVar1);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._3_1_ = SUB41(uVar15,3);
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                uVar15 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                uVar17 = uVar15 & 0x1010100;
                *puVar21 = uVar17 - (uVar17 >> 8) & uVar15;
              }
              uVar15 = local_5c;
              if ((local_54 <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_20 + local_50 + iVar1);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._3_1_ = SUB41(uVar15,3);
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                uVar15 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                uVar17 = uVar15 & 0x1010100;
                *puVar21 = uVar17 - (uVar17 >> 8) & uVar15;
              }
              uVar15 = local_5c;
              if ((local_4c <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_44 + local_28 + iVar1);
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._3_1_ = SUB41(uVar15,3);
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                              (undefined2)local_5c);
                uVar15 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                uVar17 = uVar15 & 0x1010100;
                *puVar21 = uVar17 - (uVar17 >> 8) & uVar15;
              }
              if ((local_54 <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
                puVar21 = (uint *)(local_28 + local_50 + iVar1);
                local_5c = CONCAT31(CONCAT12(local_5c._3_1_,
                                             CONCAT11(*(undefined1 *)
                                                       (&DAT_00d0a2e0 + iVar18 * 0x100 + uVar8),
                                                      *(undefined1 *)
                                                       (&DAT_00d0a2e0 +
                                                       iVar18 * 0x100 + (uint)param_5._1_1_))),
                                    *(undefined1 *)
                                     (&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                uVar17 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                uVar15 = uVar17 & 0x1010100;
                *puVar21 = uVar15 - (uVar15 >> 8) & uVar17;
              }
              if (-1 < local_68) {
                local_20 = local_20 + -iVar2;
                param_7 = param_7 + -4;
                local_1c = local_1c - 1;
                local_28 = local_28 + iVar2;
                local_2c = local_2c + 4;
                local_24 = local_24 - 1;
                local_30 = local_30 + 1;
                local_34 = local_34 + 1;
                local_18 = local_18 + -4;
                param_4 = param_4 + -1;
                local_68 = local_68 - local_18;
              }
              local_38 = local_38 + iVar2;
              param_1 = param_1 + 1;
              local_40 = local_40 + -iVar2;
              local_68 = local_68 + 2 + param_1 * 4;
            } while (param_1 <= param_4);
            return;
          }
        }
        break;
      case 4:
        if (uVar17 == 0) {
          uVar23 = iVar6 - DAT_00dca3e4;
          if (((param_2 - param_4) - DAT_00dca3e4 <= uVar23) &&
             ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar10 - DAT_00dca3e8))) {
            pbVar19 = (byte *)(iVar2 * param_3 + iVar1 + (param_2 - param_4) * 4);
            *pbVar19 = (byte)((uint)*pbVar19 * (param_5 & 0xff) >> 8);
            pbVar19[1] = (byte)((uint)pbVar19[1] * (uint)param_5._1_1_ >> 8);
            uVar8 = (uint)param_5._2_1_;
            pbVar19[2] = (byte)(uVar8 * pbVar19[2] >> 8);
          }
          iVar18 = (param_2 - uVar15) + param_4;
          if (((uint)(iVar18 - iVar26) <= uVar23) &&
             ((uint)(param_3 - iVar4) <= (uint)(iVar10 - iVar4))) {
            pbVar19 = (byte *)(iVar2 * param_3 + iVar1 + iVar18 * 4);
            *pbVar19 = (byte)((uint)*pbVar19 * (param_5 & 0xff) >> 8);
            pbVar19[1] = (byte)((uint)pbVar19[1] * (uint)param_5._1_1_ >> 8);
            uVar8 = (uint)param_5._2_1_;
            pbVar19[2] = (byte)(uVar8 * pbVar19[2] >> 8);
          }
        }
        if (uVar15 == 0) {
          iVar18 = (param_3 - uVar17) + param_4;
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)(iVar18 - iVar4) <= (uint)(iVar10 - iVar4))) {
            pbVar19 = (byte *)(iVar18 * iVar2 + iVar1 + param_2 * 4);
            *pbVar19 = (byte)((uint)*pbVar19 * (param_5 & 0xff) >> 8);
            pbVar19[1] = (byte)((uint)pbVar19[1] * (uint)param_5._1_1_ >> 8);
            uVar8 = (uint)param_5._2_1_;
            pbVar19[2] = (byte)(uVar8 * pbVar19[2] >> 8);
          }
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)((param_3 - param_4) - iVar4) <= (uint)(iVar10 - iVar4))) {
            pbVar19 = (byte *)((param_3 - param_4) * iVar2 + iVar1 + param_2 * 4);
            *pbVar19 = (byte)((uint)*pbVar19 * (param_5 & 0xff) >> 8);
            pbVar19[1] = (byte)((uint)pbVar19[1] * (uint)param_5._1_1_ >> 8);
            uVar8 = (uint)param_5._2_1_;
            pbVar19[2] = (byte)(uVar8 * pbVar19[2] >> 8);
          }
        }
        if (-1 < local_68) {
          param_4 = param_4 + -1;
          local_68 = local_68 + param_4 * -4;
        }
        local_68 = local_68 + 6;
        param_1 = 1;
        if (0 < param_4) {
          uVar23 = iVar6 - iVar26;
          local_48 = param_2 - iVar26;
          local_18 = param_4 * 4;
          local_44 = param_3 - iVar4;
          local_34 = local_44 - param_4;
          local_50 = local_48 - uVar15;
          local_4c = (param_2 - uVar15) * 4;
          local_28 = (param_3 - param_4) * iVar2;
          local_40 = param_2 * 4;
          local_24 = ((param_4 - iVar4) - uVar17) + param_3;
          local_20 = ((param_4 - uVar17) + param_3) * iVar2;
          local_1c = ((param_4 - iVar26) - uVar15) + param_2;
          param_7 = ((param_4 - uVar15) + param_2) * 4;
          local_30 = local_48 - param_4;
          local_3c = (param_3 + -1) * iVar2;
          local_38 = local_44 - uVar17;
          local_2c = (param_2 - param_4) * 4;
          param_8 = (uint *)(((param_3 - uVar17) + 1) * iVar2);
          do {
            local_38 = local_38 + 1;
            local_40 = local_40 + -4;
            local_44 = local_44 - 1;
            local_48 = local_48 - 1;
            local_4c = local_4c + 4;
            local_50 = local_50 + 1;
            if ((local_30 <= uVar23) && (local_38 <= (uint)(iVar10 - iVar4))) {
              puVar20 = (undefined1 *)(local_2c + (int)param_8 + iVar1);
              *puVar20 = (char)((uint)*(byte *)(local_2c + (int)param_8 + iVar1) * (param_5 & 0xff)
                               >> 8);
              puVar20[1] = (char)((uint)(byte)puVar20[1] * (uint)param_5._1_1_ >> 8);
              puVar20[2] = (char)(uVar8 * (byte)puVar20[2] >> 8);
            }
            if ((local_1c <= uVar23) && (local_38 <= (uint)(iVar10 - iVar4))) {
              puVar20 = (undefined1 *)(param_7 + (int)param_8 + iVar1);
              *puVar20 = (char)((uint)*(byte *)(param_7 + (int)param_8 + iVar1) * (param_5 & 0xff)
                               >> 8);
              puVar20[1] = (char)((uint)(byte)puVar20[1] * (uint)param_5._1_1_ >> 8);
              puVar20[2] = (char)(uVar8 * (byte)puVar20[2] >> 8);
            }
            if ((local_30 <= uVar23) && (local_44 <= (uint)(iVar10 - iVar4))) {
              puVar20 = (undefined1 *)(local_3c + local_2c + iVar1);
              *puVar20 = (char)((uint)*(byte *)(local_3c + local_2c + iVar1) * (param_5 & 0xff) >> 8
                               );
              puVar20[1] = (char)((uint)(byte)puVar20[1] * (uint)param_5._1_1_ >> 8);
              puVar20[2] = (char)(uVar8 * (byte)puVar20[2] >> 8);
            }
            if ((local_1c <= uVar23) && (local_44 <= (uint)(iVar10 - iVar4))) {
              puVar20 = (undefined1 *)(param_7 + local_3c + iVar1);
              *puVar20 = (char)((uint)*(byte *)(param_7 + local_3c + iVar1) * (param_5 & 0xff) >> 8)
              ;
              puVar20[1] = (char)((uint)(byte)puVar20[1] * (uint)param_5._1_1_ >> 8);
              puVar20[2] = (char)(uVar8 * (byte)puVar20[2] >> 8);
            }
            if ((local_48 <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
              puVar20 = (undefined1 *)(local_40 + local_20 + iVar1);
              *puVar20 = (char)((uint)*(byte *)(local_40 + local_20 + iVar1) * (param_5 & 0xff) >> 8
                               );
              puVar20[1] = (char)((uint)(byte)puVar20[1] * (uint)param_5._1_1_ >> 8);
              puVar20[2] = (char)(uVar8 * (byte)puVar20[2] >> 8);
            }
            if ((local_50 <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
              puVar20 = (undefined1 *)(local_4c + local_20 + iVar1);
              *puVar20 = (char)((uint)*(byte *)(local_4c + local_20 + iVar1) * (param_5 & 0xff) >> 8
                               );
              puVar20[1] = (char)((uint)(byte)puVar20[1] * (uint)param_5._1_1_ >> 8);
              puVar20[2] = (char)(uVar8 * (byte)puVar20[2] >> 8);
            }
            if ((local_48 <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
              puVar20 = (undefined1 *)(local_28 + local_40 + iVar1);
              *puVar20 = (char)((uint)*(byte *)(local_28 + local_40 + iVar1) * (param_5 & 0xff) >> 8
                               );
              puVar20[1] = (char)((uint)(byte)puVar20[1] * (uint)param_5._1_1_ >> 8);
              puVar20[2] = (char)(uVar8 * (byte)puVar20[2] >> 8);
            }
            if ((local_50 <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
              puVar20 = (undefined1 *)(local_4c + local_28 + iVar1);
              *puVar20 = (char)((uint)*(byte *)(local_4c + local_28 + iVar1) * (param_5 & 0xff) >> 8
                               );
              puVar20[1] = (char)((uint)(byte)puVar20[1] * (uint)param_5._1_1_ >> 8);
              puVar20[2] = (char)(uVar8 * (byte)puVar20[2] >> 8);
            }
            if (-1 < local_68) {
              local_20 = local_20 + -iVar2;
              local_1c = local_1c - 1;
              local_24 = local_24 - 1;
              local_28 = local_28 + iVar2;
              local_30 = local_30 + 1;
              local_34 = local_34 + 1;
              param_7 = param_7 + -4;
              local_2c = local_2c + 4;
              local_18 = local_18 + -4;
              param_4 = param_4 + -1;
              local_68 = local_68 - local_18;
            }
            param_8 = (uint *)((int)param_8 + iVar2);
            param_1 = param_1 + 1;
            local_3c = local_3c + -iVar2;
            local_68 = local_68 + 2 + param_1 * 4;
          } while (param_1 <= param_4);
          return;
        }
        break;
      case 10:
        bVar3 = (byte)uVar8;
        if (uVar17 == 0) {
          uVar23 = iVar6 - DAT_00dca3e4;
          if (((param_2 - param_4) - DAT_00dca3e4 <= uVar23) &&
             ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar10 - DAT_00dca3e8))) {
            pbVar19 = (byte *)(iVar2 * param_3 + iVar1 + (param_2 - param_4) * 4);
            *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                              (uint)*pbVar19 * 0x100 >> 8);
            pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                (uint)pbVar19[1] * 0x100 >> 8);
            pbVar19[2] = (byte)(((uint)(byte)~bVar3 - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                (uint)pbVar19[2] * 0x100 >> 8);
          }
          iVar18 = (param_2 - uVar15) + param_4;
          if (((uint)(iVar18 - iVar26) <= uVar23) &&
             ((uint)(param_3 - iVar4) <= (uint)(iVar10 - iVar4))) {
            pbVar19 = (byte *)(iVar2 * param_3 + iVar1 + iVar18 * 4);
            *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                              (uint)*pbVar19 * 0x100 >> 8);
            pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                (uint)pbVar19[1] * 0x100 >> 8);
            pbVar19[2] = (byte)(((uint)(byte)~bVar3 - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                (uint)pbVar19[2] * 0x100 >> 8);
          }
        }
        if (uVar15 == 0) {
          iVar18 = (param_3 - uVar17) + param_4;
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)(iVar18 - iVar4) <= (uint)(iVar10 - iVar4))) {
            iVar18 = iVar18 * iVar2 + iVar1;
            uVar23 = (uint)*(byte *)(iVar18 + param_2 * 4);
            puVar20 = (undefined1 *)(iVar18 + param_2 * 4);
            *puVar20 = (char)(((byte)~(byte)param_5 - uVar23) * DAT_00dca3f8 + uVar23 * 0x100 >> 8);
            puVar20[1] = (char)(((uint)(byte)~param_5._1_1_ - (uint)(byte)puVar20[1]) * DAT_00dca3f8
                                + (uint)(byte)puVar20[1] * 0x100 >> 8);
            puVar20[2] = (char)(((uint)(byte)~bVar3 - (uint)(byte)puVar20[2]) * DAT_00dca3f8 +
                                (uint)(byte)puVar20[2] * 0x100 >> 8);
          }
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)((param_3 - param_4) - iVar4) <= (uint)(iVar10 - iVar4))) {
            iVar18 = (param_3 - param_4) * iVar2 + iVar1;
            uVar23 = (uint)*(byte *)(iVar18 + param_2 * 4);
            puVar20 = (undefined1 *)(iVar18 + param_2 * 4);
            *puVar20 = (char)(((byte)~(byte)param_5 - uVar23) * DAT_00dca3f8 + uVar23 * 0x100 >> 8);
            puVar20[1] = (char)(((uint)(byte)~param_5._1_1_ - (uint)(byte)puVar20[1]) * DAT_00dca3f8
                                + (uint)(byte)puVar20[1] * 0x100 >> 8);
            puVar20[2] = (char)(((uint)(byte)~bVar3 - (uint)(byte)puVar20[2]) * DAT_00dca3f8 +
                                (uint)(byte)puVar20[2] * 0x100 >> 8);
          }
        }
        if (-1 < local_68) {
          param_4 = param_4 + -1;
          local_68 = local_68 + param_4 * -4;
        }
        local_68 = local_68 + 6;
        param_1 = 1;
        if (0 < param_4) {
          uVar23 = iVar6 - iVar26;
          local_48 = param_2 - iVar26;
          local_18 = param_4 * 4;
          local_44 = param_3 - iVar4;
          local_34 = local_44 - param_4;
          local_50 = local_48 - uVar15;
          local_4c = (param_2 - uVar15) * 4;
          local_28 = (param_3 - param_4) * iVar2;
          local_40 = param_2 * 4;
          local_24 = ((param_4 - iVar4) - uVar17) + param_3;
          local_20 = ((param_4 - uVar17) + param_3) * iVar2;
          local_1c = ((param_4 - iVar26) - uVar15) + param_2;
          param_7 = ((param_4 - uVar15) + param_2) * 4;
          local_2c = (param_2 - param_4) * 4;
          local_30 = local_48 - param_4;
          local_3c = (param_3 + -1) * iVar2;
          local_38 = local_44 - uVar17;
          param_8 = (uint *)(((param_3 - uVar17) + 1) * iVar2);
          do {
            local_38 = local_38 + 1;
            local_40 = local_40 + -4;
            local_44 = local_44 - 1;
            local_48 = local_48 - 1;
            local_4c = local_4c + 4;
            local_50 = local_50 + 1;
            if ((local_30 <= uVar23) && (local_38 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)((int)param_8 + local_2c + iVar1);
              *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)(((uint)(byte)~bVar3 - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                  (uint)pbVar19[2] * 0x100 >> 8);
            }
            if ((local_1c <= uVar23) && (local_38 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)((int)param_8 + param_7 + iVar1);
              *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)(((uint)(byte)~bVar3 - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                  (uint)pbVar19[2] * 0x100 >> 8);
            }
            if ((local_30 <= uVar23) && (local_44 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_2c + local_3c + iVar1);
              *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)(((uint)(byte)~bVar3 - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                  (uint)pbVar19[2] * 0x100 >> 8);
            }
            if ((local_1c <= uVar23) && (local_44 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_3c + param_7 + iVar1);
              *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)(((uint)(byte)~bVar3 - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                  (uint)pbVar19[2] * 0x100 >> 8);
            }
            if ((local_48 <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_20 + local_40 + iVar1);
              *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)(((uint)(byte)~bVar3 - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                  (uint)pbVar19[2] * 0x100 >> 8);
            }
            if ((local_50 <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_20 + local_4c + iVar1);
              *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)(((uint)(byte)~bVar3 - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                  (uint)pbVar19[2] * 0x100 >> 8);
            }
            if ((local_48 <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_40 + local_28 + iVar1);
              *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)(((uint)(byte)~bVar3 - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                  (uint)pbVar19[2] * 0x100 >> 8);
            }
            if ((local_50 <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_28 + local_4c + iVar1);
              *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)(((uint)(byte)~bVar3 - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                  (uint)pbVar19[2] * 0x100 >> 8);
            }
            if (-1 < local_68) {
              local_20 = local_20 + -iVar2;
              local_28 = local_28 + iVar2;
              local_1c = local_1c - 1;
              local_24 = local_24 - 1;
              local_30 = local_30 + 1;
              local_34 = local_34 + 1;
              param_4 = param_4 + -1;
              param_7 = param_7 + -4;
              local_2c = local_2c + 4;
              local_18 = local_18 + -4;
              local_68 = local_68 - local_18;
            }
            local_3c = local_3c + -iVar2;
            param_8 = (uint *)((int)param_8 + iVar2);
            param_1 = param_1 + 1;
            local_68 = local_68 + 2 + param_1 * 4;
          } while (param_1 <= param_4);
          return;
        }
        break;
      case 0xb:
        if (uVar17 == 0) {
          uVar23 = iVar6 - DAT_00dca3e4;
          if (((param_2 - param_4) - DAT_00dca3e4 <= uVar23) &&
             ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar10 - DAT_00dca3e8))) {
            pbVar19 = (byte *)(iVar2 * param_3 + iVar1 + (param_2 - param_4) * 4);
            uVar27 = (uint)*pbVar19;
            *pbVar19 = (byte)((((int)((param_5 & 0xff) * uVar27) >> 8) - uVar27) * DAT_00dca3f8 +
                              uVar27 * 0x100 >> 8);
            uVar27 = (uint)pbVar19[1];
            pbVar19[1] = (byte)((((int)(param_5._1_1_ * uVar27) >> 8) - uVar27) * DAT_00dca3f8 +
                                uVar27 * 0x100 >> 8);
            uVar27 = (uint)pbVar19[2];
            pbVar19[2] = (byte)((((int)(uVar8 * uVar27) >> 8) - uVar27) * DAT_00dca3f8 +
                                uVar27 * 0x100 >> 8);
          }
          iVar18 = (param_2 - uVar15) + param_4;
          if (((uint)(iVar18 - iVar26) <= uVar23) &&
             ((uint)(param_3 - iVar4) <= (uint)(iVar10 - iVar4))) {
            pbVar19 = (byte *)(iVar2 * param_3 + iVar1 + iVar18 * 4);
            uVar23 = (uint)*pbVar19;
            *pbVar19 = (byte)((((int)((param_5 & 0xff) * uVar23) >> 8) - uVar23) * DAT_00dca3f8 +
                              uVar23 * 0x100 >> 8);
            uVar23 = (uint)pbVar19[1];
            pbVar19[1] = (byte)((((int)(param_5._1_1_ * uVar23) >> 8) - uVar23) * DAT_00dca3f8 +
                                uVar23 * 0x100 >> 8);
            uVar23 = (uint)pbVar19[2];
            pbVar19[2] = (byte)((((int)(uVar8 * uVar23) >> 8) - uVar23) * DAT_00dca3f8 +
                                uVar23 * 0x100 >> 8);
          }
        }
        if (uVar15 == 0) {
          iVar18 = (param_3 - uVar17) + param_4;
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)(iVar18 - iVar4) <= (uint)(iVar10 - iVar4))) {
            iVar18 = iVar18 * iVar2 + iVar1;
            uVar23 = (uint)*(byte *)(iVar18 + param_2 * 4);
            puVar20 = (undefined1 *)(iVar18 + param_2 * 4);
            *puVar20 = (char)((((int)((param_5 & 0xff) * uVar23) >> 8) - uVar23) * DAT_00dca3f8 +
                              uVar23 * 0x100 >> 8);
            uVar23 = (uint)(byte)puVar20[1];
            puVar20[1] = (char)((((int)(param_5._1_1_ * uVar23) >> 8) - uVar23) * DAT_00dca3f8 +
                                uVar23 * 0x100 >> 8);
            uVar23 = (uint)(byte)puVar20[2];
            puVar20[2] = (char)((((int)(uVar8 * uVar23) >> 8) - uVar23) * DAT_00dca3f8 +
                                uVar23 * 0x100 >> 8);
          }
          if ((param_2 - iVar26 <= (uint)(iVar6 - iVar26)) &&
             ((uint)((param_3 - param_4) - iVar4) <= (uint)(iVar10 - iVar4))) {
            iVar18 = (param_3 - param_4) * iVar2 + iVar1;
            uVar23 = (uint)*(byte *)(iVar18 + param_2 * 4);
            puVar20 = (undefined1 *)(iVar18 + param_2 * 4);
            *puVar20 = (char)((((int)((param_5 & 0xff) * uVar23) >> 8) - uVar23) * DAT_00dca3f8 +
                              uVar23 * 0x100 >> 8);
            uVar23 = (uint)(byte)puVar20[1];
            puVar20[1] = (char)((((int)(param_5._1_1_ * uVar23) >> 8) - uVar23) * DAT_00dca3f8 +
                                uVar23 * 0x100 >> 8);
            uVar23 = (uint)(byte)puVar20[2];
            puVar20[2] = (char)((((int)(uVar8 * uVar23) >> 8) - uVar23) * DAT_00dca3f8 +
                                uVar23 * 0x100 >> 8);
          }
        }
        if (-1 < local_68) {
          param_4 = param_4 + -1;
          local_68 = local_68 + param_4 * -4;
        }
        local_68 = local_68 + 6;
        param_1 = 1;
        if (0 < param_4) {
          uVar23 = iVar6 - iVar26;
          local_48 = param_2 - iVar26;
          local_18 = param_4 * 4;
          local_44 = param_3 - iVar4;
          local_34 = local_44 - param_4;
          local_50 = local_48 - uVar15;
          local_4c = (param_2 - uVar15) * 4;
          local_28 = (param_3 - param_4) * iVar2;
          local_40 = param_2 * 4;
          local_24 = ((param_4 - iVar4) - uVar17) + param_3;
          local_20 = ((param_4 - uVar17) + param_3) * iVar2;
          local_1c = ((param_4 - iVar26) - uVar15) + param_2;
          param_7 = ((param_4 - uVar15) + param_2) * 4;
          local_2c = (param_2 - param_4) * 4;
          local_30 = local_48 - param_4;
          local_3c = (param_3 + -1) * iVar2;
          local_38 = local_44 - uVar17;
          param_8 = (uint *)(((param_3 - uVar17) + 1) * iVar2);
          do {
            local_38 = local_38 + 1;
            local_40 = local_40 + -4;
            local_44 = local_44 - 1;
            local_48 = local_48 - 1;
            local_4c = local_4c + 4;
            local_50 = local_50 + 1;
            if ((local_30 <= uVar23) && (local_38 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)((int)param_8 + local_2c + iVar1);
              uVar15 = (uint)*pbVar19;
              *pbVar19 = (byte)((((int)((param_5 & 0xff) * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[1];
              pbVar19[1] = (byte)((((int)(param_5._1_1_ * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[2];
              pbVar19[2] = (byte)((((int)(uVar8 * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
            }
            if ((local_1c <= uVar23) && (local_38 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)((int)param_8 + param_7 + iVar1);
              uVar15 = (uint)*pbVar19;
              *pbVar19 = (byte)((((int)((param_5 & 0xff) * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[1];
              pbVar19[1] = (byte)((((int)(param_5._1_1_ * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[2];
              pbVar19[2] = (byte)((((int)(uVar8 * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
            }
            if ((local_30 <= uVar23) && (local_44 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_2c + local_3c + iVar1);
              uVar15 = (uint)*pbVar19;
              *pbVar19 = (byte)((((int)((param_5 & 0xff) * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[1];
              pbVar19[1] = (byte)((((int)(param_5._1_1_ * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[2];
              pbVar19[2] = (byte)((((int)(uVar8 * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
            }
            if ((local_1c <= uVar23) && (local_44 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_3c + param_7 + iVar1);
              uVar15 = (uint)*pbVar19;
              *pbVar19 = (byte)((((int)((param_5 & 0xff) * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[1];
              pbVar19[1] = (byte)((((int)(param_5._1_1_ * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[2];
              pbVar19[2] = (byte)((((int)(uVar8 * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
            }
            if ((local_48 <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_20 + local_40 + iVar1);
              uVar15 = (uint)*pbVar19;
              *pbVar19 = (byte)((((int)((param_5 & 0xff) * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[1];
              pbVar19[1] = (byte)((((int)(param_5._1_1_ * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[2];
              pbVar19[2] = (byte)((((int)(uVar8 * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
            }
            if ((local_50 <= uVar23) && (local_24 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_20 + local_4c + iVar1);
              uVar15 = (uint)*pbVar19;
              *pbVar19 = (byte)((((int)((param_5 & 0xff) * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[1];
              pbVar19[1] = (byte)((((int)(param_5._1_1_ * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[2];
              pbVar19[2] = (byte)((((int)(uVar8 * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
            }
            if ((local_48 <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_40 + local_28 + iVar1);
              uVar15 = (uint)*pbVar19;
              *pbVar19 = (byte)((((int)((param_5 & 0xff) * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[1];
              pbVar19[1] = (byte)((((int)(param_5._1_1_ * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[2];
              pbVar19[2] = (byte)((((int)(uVar8 * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
            }
            if ((local_50 <= uVar23) && (local_34 <= (uint)(iVar10 - iVar4))) {
              pbVar19 = (byte *)(local_28 + local_4c + iVar1);
              uVar15 = (uint)*pbVar19;
              *pbVar19 = (byte)((((int)((param_5 & 0xff) * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[1];
              pbVar19[1] = (byte)((((int)(param_5._1_1_ * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
              uVar15 = (uint)pbVar19[2];
              pbVar19[2] = (byte)((((int)(uVar8 * uVar15) >> 8) - uVar15) * DAT_00dca3f8 +
                                  uVar15 * 0x100 >> 8);
            }
            if (-1 < local_68) {
              local_20 = local_20 + -iVar2;
              local_28 = local_28 + iVar2;
              local_1c = local_1c - 1;
              local_24 = local_24 - 1;
              local_30 = local_30 + 1;
              local_34 = local_34 + 1;
              param_4 = param_4 + -1;
              param_7 = param_7 + -4;
              local_2c = local_2c + 4;
              local_18 = local_18 + -4;
              local_68 = local_68 - local_18;
            }
            local_3c = local_3c + -iVar2;
            param_8 = (uint *)((int)param_8 + iVar2);
            param_1 = param_1 + 1;
            local_68 = local_68 + 2 + param_1 * 4;
          } while (param_1 <= param_4);
          return;
        }
      }
    }
    return;
  }
  iVar7 = FUN_0056e050(DAT_00dca3f0,
                       "..\\..\\..\\..\\Source\\Library\\Main\\DxMemImgDrawFunction3.cpp",0x539);
  if (iVar7 == 0) {
    return;
  }
  iVar22 = *(int *)(*(int *)(param_1 + 0x14) + 0x20);
  if (iVar22 == 0) {
    if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
      param_5 = ((param_5 >> 5 & 0x3f) * (DAT_00dca3fc >> 8 & 0xff) & 0xffffff07 |
                (param_5 & 0x1f) * (DAT_00dca3fc & 0xff) >> 5) >> 3 |
                (param_5 >> 8 & 0xfffff8) * (DAT_00dca3fc >> 0x10 & 0xff) & 0xfffff800;
    }
    switch(DAT_00dca3f4) {
    case 1:
      if (DAT_00dca3f8 != 0xff) {
        if (DAT_00dca3f8 != 0) {
          if (uVar17 == 0) {
            param_1 = param_2 - param_4;
            iVar22 = (param_2 - uVar15) + param_4;
            if ((((iVar26 <= iVar22 && iVar4 <= param_3) && param_1 < iVar6) && param_3 < iVar10) &&
                *(char *)(iVar7 + param_3) == '\0') {
              if (param_1 < iVar26) {
                param_1 = iVar26;
              }
              if (iVar6 < iVar22) {
                iVar22 = iVar6;
              }
              *(undefined1 *)(iVar7 + param_3) = 1;
              param_8 = (uint *)(iVar2 * param_3 + iVar1 + param_1 * 2);
              param_1 = (iVar22 - param_1) + 1;
              do {
                uVar9 = *(ushort *)param_8;
                *(ushort *)param_8 =
                     ((uVar9 >> 5 & 0x3f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800))
                     * 0x20 | ((uVar9 >> 0xb) +
                              *(short *)(&DAT_00d4a6e0 +
                                        ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 +
                                        iVar18 * 0x800)) * 0x800 |
                     (uVar9 & 0x1f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
                param_8 = (uint *)((int)param_8 + 2);
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
          }
          if (-1 < local_68) {
            iVar22 = param_2 - uVar15;
            iVar24 = (param_3 - uVar17) + param_4;
            if ((((iVar4 <= iVar24 && iVar26 <= iVar22) && iVar24 < iVar10) &&
                *(char *)(iVar24 + iVar7) == '\0') && (int)param_2 < iVar6) {
              iVar12 = iVar26;
              if (iVar26 <= (int)param_2) {
                iVar12 = param_2;
              }
              iVar11 = iVar22;
              if (iVar6 < iVar22) {
                iVar11 = iVar6;
              }
              *(undefined1 *)(iVar24 + iVar7) = 1;
              param_1 = (iVar11 - iVar12) + 1;
              param_8 = (uint *)(iVar24 * iVar2 + iVar1 + iVar12 * 2);
              do {
                uVar9 = *(ushort *)param_8;
                *(ushort *)param_8 =
                     ((uVar9 >> 5 & 0x3f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800))
                     * 0x20 | ((uVar9 >> 0xb) +
                              *(short *)(&DAT_00d4a6e0 +
                                        ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 +
                                        iVar18 * 0x800)) * 0x800 |
                     (uVar9 & 0x1f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
                param_8 = (uint *)((int)param_8 + 2);
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            iVar24 = param_3 - param_4;
            if ((((iVar4 <= iVar24 && iVar26 <= iVar22) && iVar24 < iVar10) &&
                *(char *)(iVar24 + iVar7) == '\0') && (int)param_2 < iVar6) {
              iVar12 = iVar26;
              if (iVar26 <= (int)param_2) {
                iVar12 = param_2;
              }
              if (iVar6 < iVar22) {
                iVar22 = iVar6;
              }
              *(undefined1 *)(iVar24 + iVar7) = 1;
              param_1 = (iVar22 - iVar12) + 1;
              param_8 = (uint *)(iVar24 * iVar2 + iVar1 + iVar12 * 2);
              do {
                uVar9 = *(ushort *)param_8;
                *(ushort *)param_8 =
                     ((uVar9 >> 5 & 0x3f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800))
                     * 0x20 | ((uVar9 >> 0xb) +
                              *(short *)(&DAT_00d4a6e0 +
                                        ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 +
                                        iVar18 * 0x800)) * 0x800 |
                     (uVar9 & 0x1f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
                param_8 = (uint *)((int)param_8 + 2);
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            param_4 = param_4 + -1;
            local_68 = local_68 + param_4 * -4;
          }
          local_68 = local_68 + 6;
          if (0 < param_4) {
            local_30 = param_4 * 4;
            local_40 = param_2 - uVar15;
            local_38 = 4;
            local_3c = (param_4 - uVar17) + param_3;
            local_54 = param_2 - param_4;
            local_44 = (param_4 - uVar15) + param_2;
            local_1c = (param_3 - param_4) * iVar2;
            local_18 = local_3c * iVar2;
            local_24 = (param_3 + -1) * iVar2;
            local_34 = (param_3 - uVar17) + 1;
            local_20 = local_34 * iVar2;
            iVar22 = param_3 - param_2;
            do {
              local_40 = local_40 + 1;
              local_58 = param_2 + -1;
              if ((((iVar4 <= (int)local_34 && (int)local_34 < iVar10) &&
                   *(char *)(local_34 + iVar7) == '\0') && (int)local_54 < iVar6) &&
                  iVar26 <= (int)local_44) {
                uVar23 = iVar26;
                if (iVar26 <= (int)local_54) {
                  uVar23 = local_54;
                }
                uVar15 = iVar6;
                if ((int)local_44 <= iVar6) {
                  uVar15 = local_44;
                }
                *(undefined1 *)(local_34 + iVar7) = 1;
                param_1 = (uVar15 - uVar23) + 1;
                param_8 = (uint *)(local_20 + uVar23 * 2 + iVar1);
                do {
                  uVar9 = *(ushort *)param_8;
                  *(ushort *)param_8 =
                       ((uVar9 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800)
                       ) * 0x20 |
                       ((uVar9 >> 0xb) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) *
                       0x800 | (uVar9 & 0x1f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
                  param_8 = (uint *)((int)param_8 + 2);
                  param_1 = param_1 + -1;
                } while (param_1 != 0);
              }
              iVar24 = local_58 + iVar22;
              if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
                  (int)local_54 < iVar6) && iVar26 <= (int)local_44) {
                uVar23 = iVar26;
                if (iVar26 <= (int)local_54) {
                  uVar23 = local_54;
                }
                uVar15 = iVar6;
                if ((int)local_44 <= iVar6) {
                  uVar15 = local_44;
                }
                param_1 = (uVar15 - uVar23) + 1;
                *(undefined1 *)(iVar24 + iVar7) = 1;
                param_8 = (uint *)(local_24 + uVar23 * 2 + iVar1);
                do {
                  uVar9 = *(ushort *)param_8;
                  *(ushort *)param_8 =
                       ((uVar9 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800)
                       ) * 0x20 |
                       ((uVar9 >> 0xb) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) *
                       0x800 | (uVar9 & 0x1f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
                  param_8 = (uint *)((int)param_8 + 2);
                  param_1 = param_1 + -1;
                } while (param_1 != 0);
              }
              if (-1 < local_68) {
                if ((((iVar4 <= (int)local_3c && (int)local_3c < iVar10) &&
                     *(char *)(local_3c + iVar7) == '\0') && local_58 < iVar6) &&
                    iVar26 <= (int)local_40) {
                  iVar24 = iVar26;
                  if (iVar26 <= local_58) {
                    iVar24 = local_58;
                  }
                  uVar23 = iVar6;
                  if ((int)local_40 <= iVar6) {
                    uVar23 = local_40;
                  }
                  param_1 = (uVar23 - iVar24) + 1;
                  *(undefined1 *)(local_3c + iVar7) = 1;
                  param_8 = (uint *)(local_18 + iVar24 * 2 + iVar1);
                  do {
                    uVar9 = *(ushort *)param_8;
                    *(ushort *)param_8 =
                         ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                         * 0x800 | (uVar9 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 +
                                             iVar18 * 0x800);
                    param_8 = (uint *)((int)param_8 + 2);
                    param_1 = param_1 + -1;
                  } while (param_1 != 0);
                }
                iVar24 = local_54 + iVar22;
                if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
                    local_58 < iVar6) && iVar26 <= (int)local_40) {
                  iVar12 = iVar26;
                  if (iVar26 <= local_58) {
                    iVar12 = local_58;
                  }
                  uVar23 = iVar6;
                  if ((int)local_40 <= iVar6) {
                    uVar23 = local_40;
                  }
                  param_1 = (uVar23 - iVar12) + 1;
                  *(undefined1 *)(iVar24 + iVar7) = 1;
                  param_8 = (uint *)(local_1c + iVar12 * 2 + iVar1);
                  do {
                    uVar9 = *(ushort *)param_8;
                    *(ushort *)param_8 =
                         ((uVar9 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 +
                                   iVar18 * 0x800)) * 0x20 |
                         ((uVar9 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_5 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                         * 0x800 | (uVar9 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 +
                                             iVar18 * 0x800);
                    param_8 = (uint *)((int)param_8 + 2);
                    param_1 = param_1 + -1;
                  } while (param_1 != 0);
                }
                local_18 = local_18 + -iVar2;
                local_1c = local_1c + iVar2;
                local_44 = local_44 + -1;
                local_3c = local_3c + -1;
                local_54 = local_54 + 1;
                local_30 = local_30 + -4;
                param_4 = param_4 + -1;
                local_68 = local_68 - local_30;
              }
              local_20 = local_20 + iVar2;
              local_34 = local_34 + 1;
              local_24 = local_24 + -iVar2;
              local_38 = local_38 + 4;
              local_68 = local_68 + 2 + local_38;
              param_2 = local_58;
            } while ((int)((uVar17 - param_3) + local_34) <= param_4);
            FUN_0056e1d0(iVar7);
            return;
          }
        }
        break;
      }
    case 0:
      if (uVar17 == 0) {
        iVar22 = param_2 - param_4;
        iVar18 = (param_2 - uVar15) + param_4;
        if ((((iVar26 <= iVar18 && iVar4 <= param_3) && iVar22 < iVar6) && param_3 < iVar10) &&
            *(char *)(iVar7 + param_3) == '\0') {
          if (iVar22 < iVar26) {
            iVar22 = iVar26;
          }
          if (iVar6 < iVar18) {
            iVar18 = iVar6;
          }
          iVar18 = (iVar18 - iVar22) + 1;
          *(undefined1 *)(iVar7 + param_3) = 1;
          puVar13 = (undefined2 *)(iVar2 * param_3 + iVar1 + iVar22 * 2);
          do {
            *puVar13 = (ushort)param_5;
            puVar13 = puVar13 + 1;
            iVar18 = iVar18 + -1;
          } while (iVar18 != 0);
        }
      }
      if (-1 < local_68) {
        iVar18 = param_2 - uVar15;
        iVar22 = (param_3 - uVar17) + param_4;
        if ((((iVar4 <= iVar22 && iVar26 <= iVar18) && iVar22 < iVar10) &&
            *(char *)(iVar7 + iVar22) == '\0') && (int)param_2 < iVar6) {
          iVar24 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar24 = param_2;
          }
          iVar12 = iVar6;
          if (iVar18 <= iVar6) {
            iVar12 = iVar18;
          }
          *(undefined1 *)(iVar7 + iVar22) = 1;
          iVar12 = (iVar12 - iVar24) + 1;
          puVar13 = (undefined2 *)(iVar22 * iVar2 + iVar1 + iVar24 * 2);
          do {
            *puVar13 = (ushort)param_5;
            puVar13 = puVar13 + 1;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        iVar22 = param_3 - param_4;
        if ((((iVar4 <= iVar22 && iVar26 <= iVar18) && iVar22 < iVar10) &&
            *(char *)(iVar7 + iVar22) == '\0') && (int)param_2 < iVar6) {
          iVar24 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar24 = param_2;
          }
          iVar12 = iVar6;
          if (iVar18 <= iVar6) {
            iVar12 = iVar18;
          }
          *(undefined1 *)(iVar7 + iVar22) = 1;
          iVar18 = (iVar12 - iVar24) + 1;
          puVar13 = (undefined2 *)(iVar22 * iVar2 + iVar1 + iVar24 * 2);
          do {
            *puVar13 = (ushort)param_5;
            puVar13 = puVar13 + 1;
            iVar18 = iVar18 + -1;
          } while (iVar18 != 0);
        }
        param_4 = param_4 + -1;
        local_68 = local_68 + param_4 * -4;
      }
      local_68 = local_68 + 6;
      if (0 < param_4) {
        local_30 = param_4 * 4;
        local_40 = param_2 - uVar15;
        local_34 = 4;
        local_3c = (param_4 - uVar17) + param_3;
        param_8 = (uint *)(param_2 - param_4);
        local_44 = (param_4 - uVar15) + param_2;
        local_4c = (param_3 - uVar17) + 1;
        local_1c = (param_3 - param_4) * iVar2;
        local_18 = local_3c * iVar2;
        local_24 = (param_3 + -1) * iVar2;
        local_20 = local_4c * iVar2;
        iVar18 = param_3 - param_2;
        do {
          local_40 = local_40 + 1;
          param_6 = param_2 + -1;
          if ((((iVar4 <= (int)local_4c && (int)local_4c < iVar10) &&
               *(char *)(local_4c + iVar7) == '\0') && iVar26 <= (int)local_44) &&
              (int)param_8 < iVar6) {
            iVar22 = iVar26;
            if (iVar26 <= (int)param_8) {
              iVar22 = (int)param_8;
            }
            uVar23 = local_44;
            if (iVar6 < (int)local_44) {
              uVar23 = iVar6;
            }
            iVar24 = (uVar23 - iVar22) + 1;
            puVar13 = (undefined2 *)(local_20 + iVar22 * 2 + iVar1);
            *(undefined1 *)(local_4c + iVar7) = 1;
            do {
              *puVar13 = (ushort)param_5;
              puVar13 = puVar13 + 1;
              iVar24 = iVar24 + -1;
            } while (iVar24 != 0);
          }
          param_1 = (int)param_8;
          iVar22 = param_6 + iVar18;
          if ((((iVar4 <= iVar22 && iVar22 < iVar10) && *(char *)(iVar22 + iVar7) == '\0') &&
              iVar26 <= (int)local_44) && (int)param_8 < iVar6) {
            if ((int)param_8 < iVar26) {
              param_1 = iVar26;
            }
            uVar23 = local_44;
            if (iVar6 < (int)local_44) {
              uVar23 = iVar6;
            }
            iVar24 = (uVar23 - param_1) + 1;
            puVar13 = (undefined2 *)(local_24 + param_1 * 2 + iVar1);
            *(undefined1 *)(iVar22 + iVar7) = 1;
            do {
              *puVar13 = (ushort)param_5;
              puVar13 = puVar13 + 1;
              iVar24 = iVar24 + -1;
            } while (iVar24 != 0);
          }
          if (-1 < local_68) {
            if ((((iVar4 <= (int)local_3c && (int)local_3c < iVar10) &&
                 *(char *)(local_3c + iVar7) == '\0') && param_6 < iVar6) && iVar26 <= (int)local_40
               ) {
              iVar22 = param_6;
              if (param_6 < iVar26) {
                iVar22 = iVar26;
              }
              uVar23 = local_40;
              if (iVar6 < (int)local_40) {
                uVar23 = iVar6;
              }
              iVar24 = (uVar23 - iVar22) + 1;
              puVar13 = (undefined2 *)(local_18 + iVar22 * 2 + iVar1);
              *(undefined1 *)(local_3c + iVar7) = 1;
              do {
                *puVar13 = (ushort)param_5;
                puVar13 = puVar13 + 1;
                iVar24 = iVar24 + -1;
              } while (iVar24 != 0);
            }
            iVar22 = iVar18 + (int)param_8;
            if ((((iVar4 <= iVar22 && iVar22 < iVar10) && *(char *)(iVar22 + iVar7) == '\0') &&
                param_6 < iVar6) && iVar26 <= (int)local_40) {
              iVar24 = param_6;
              if (param_6 < iVar26) {
                iVar24 = iVar26;
              }
              uVar23 = local_40;
              if (iVar6 < (int)local_40) {
                uVar23 = iVar6;
              }
              *(undefined1 *)(iVar22 + iVar7) = 1;
              iVar22 = (uVar23 - iVar24) + 1;
              puVar13 = (undefined2 *)(local_1c + iVar24 * 2 + iVar1);
              do {
                *puVar13 = (ushort)param_5;
                puVar13 = puVar13 + 1;
                iVar22 = iVar22 + -1;
              } while (iVar22 != 0);
            }
            local_18 = local_18 + -iVar2;
            local_44 = local_44 + -1;
            local_3c = local_3c + -1;
            param_8 = (uint *)((int)param_8 + 1);
            local_1c = local_1c + iVar2;
            param_4 = param_4 + -1;
            local_30 = local_30 + -4;
            local_68 = local_68 - local_30;
          }
          local_20 = local_20 + iVar2;
          local_24 = local_24 + -iVar2;
          local_4c = local_4c + 1;
          local_34 = local_34 + 4;
          local_68 = local_68 + 2 + local_34;
          param_2 = param_6;
        } while ((int)(local_4c + (uVar17 - param_3)) <= param_4);
        FUN_0056e1d0(iVar7);
        return;
      }
      break;
    case 2:
      if (DAT_00dca3f8 != 0) {
        if (uVar17 == 0) {
          param_1 = param_2 - param_4;
          iVar22 = (param_2 - uVar15) + param_4;
          if ((((iVar26 <= iVar22 && iVar4 <= param_3) && param_1 < iVar6) && param_3 < iVar10) &&
              *(char *)(iVar7 + param_3) == '\0') {
            if (param_1 < iVar26) {
              param_1 = iVar26;
            }
            if (iVar6 < iVar22) {
              iVar22 = iVar6;
            }
            *(undefined1 *)(iVar7 + param_3) = 1;
            iVar24 = param_1 * 2;
            param_1 = (iVar22 - param_1) + 1;
            param_8 = (uint *)(iVar2 * param_3 + iVar1 + iVar24);
            do {
              uVar9 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                      *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20 +
                      *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
              uVar23 = (*(ushort *)param_8 & 0xf7def7df) + (uVar9 & 0xf7def7df);
              uVar8 = uVar23 & 0x8210820;
              param_1 = param_1 + -1;
              *(ushort *)param_8 =
                   (short)uVar8 - (short)(uVar8 >> 5) | (uVar9 | *(ushort *)param_8) & 0x820 |
                   (ushort)uVar23;
              param_8 = (uint *)((int)param_8 + 2);
            } while (param_1 != 0);
          }
        }
        if (-1 < local_68) {
          iVar22 = param_2 - uVar15;
          iVar24 = (param_3 - uVar17) + param_4;
          if ((((iVar4 <= iVar24 && iVar26 <= iVar22) && iVar24 < iVar10) &&
              *(char *)(iVar24 + iVar7) == '\0') && (int)param_2 < iVar6) {
            iVar12 = iVar26;
            if (iVar26 <= (int)param_2) {
              iVar12 = param_2;
            }
            iVar11 = iVar22;
            if (iVar6 < iVar22) {
              iVar11 = iVar6;
            }
            *(undefined1 *)(iVar24 + iVar7) = 1;
            param_1 = (iVar11 - iVar12) + 1;
            param_8 = (uint *)(iVar24 * iVar2 + iVar1 + iVar12 * 2);
            do {
              uVar9 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                      *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20 +
                      *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
              uVar8 = (*(ushort *)param_8 & 0xf7def7df) + (uVar9 & 0xf7def7df);
              uVar23 = uVar8 & 0x8210820;
              *(ushort *)param_8 =
                   (short)uVar23 - (short)(uVar23 >> 5) | (uVar9 | *(ushort *)param_8) & 0x820 |
                   (ushort)uVar8;
              param_8 = (uint *)((int)param_8 + 2);
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          iVar24 = param_3 - param_4;
          if ((((iVar4 <= iVar24 && iVar26 <= iVar22) && iVar24 < iVar10) &&
              *(char *)(iVar24 + iVar7) == '\0') && (int)param_2 < iVar6) {
            iVar12 = iVar26;
            if (iVar26 <= (int)param_2) {
              iVar12 = param_2;
            }
            if (iVar6 < iVar22) {
              iVar22 = iVar6;
            }
            *(undefined1 *)(iVar24 + iVar7) = 1;
            param_1 = (iVar22 - iVar12) + 1;
            param_8 = (uint *)(iVar24 * iVar2 + iVar1 + iVar12 * 2);
            do {
              uVar9 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                      *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20 +
                      *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
              uVar8 = (*(ushort *)param_8 & 0xf7def7df) + (uVar9 & 0xf7def7df);
              uVar23 = uVar8 & 0x8210820;
              *(ushort *)param_8 =
                   (short)uVar23 - (short)(uVar23 >> 5) | (uVar9 | *(ushort *)param_8) & 0x820 |
                   (ushort)uVar8;
              param_8 = (uint *)((int)param_8 + 2);
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          param_4 = param_4 + -1;
          local_68 = local_68 + param_4 * -4;
        }
        local_68 = local_68 + 6;
        if (0 < param_4) {
          local_30 = param_4 * 4;
          local_40 = param_2 - uVar15;
          local_38 = 4;
          local_3c = (param_4 - uVar17) + param_3;
          local_54 = param_2 - param_4;
          local_44 = (param_4 - uVar15) + param_2;
          local_1c = (param_3 - param_4) * iVar2;
          local_18 = local_3c * iVar2;
          local_24 = (param_3 + -1) * iVar2;
          local_34 = (param_3 - uVar17) + 1;
          local_20 = local_34 * iVar2;
          iVar22 = param_3 - param_2;
          do {
            local_40 = local_40 + 1;
            local_58 = param_2 + -1;
            if ((((iVar4 <= (int)local_34 && (int)local_34 < iVar10) &&
                 *(char *)(local_34 + iVar7) == '\0') && (int)local_54 < iVar6) &&
                iVar26 <= (int)local_44) {
              uVar23 = iVar26;
              if (iVar26 <= (int)local_54) {
                uVar23 = local_54;
              }
              uVar15 = iVar6;
              if ((int)local_44 <= iVar6) {
                uVar15 = local_44;
              }
              param_1 = (uVar15 - uVar23) + 1;
              *(undefined1 *)(local_34 + iVar7) = 1;
              param_8 = (uint *)(local_20 + uVar23 * 2 + iVar1);
              do {
                uVar9 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                        *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20 +
                        *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
                uVar15 = (*(ushort *)param_8 & 0xf7def7df) + (uVar9 & 0xf7def7df);
                uVar23 = uVar15 & 0x8210820;
                *(ushort *)param_8 =
                     (short)uVar23 - (short)(uVar23 >> 5) | (uVar9 | *(ushort *)param_8) & 0x820 |
                     (ushort)uVar15;
                param_8 = (uint *)((int)param_8 + 2);
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            iVar24 = local_58 + iVar22;
            if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
                (int)local_54 < iVar6) && iVar26 <= (int)local_44) {
              uVar23 = iVar26;
              if (iVar26 <= (int)local_54) {
                uVar23 = local_54;
              }
              uVar15 = iVar6;
              if ((int)local_44 <= iVar6) {
                uVar15 = local_44;
              }
              param_1 = (uVar15 - uVar23) + 1;
              *(undefined1 *)(iVar24 + iVar7) = 1;
              param_8 = (uint *)(local_24 + uVar23 * 2 + iVar1);
              do {
                uVar9 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                        *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20 +
                        *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
                uVar15 = (*(ushort *)param_8 & 0xf7def7df) + (uVar9 & 0xf7def7df);
                uVar23 = uVar15 & 0x8210820;
                *(ushort *)param_8 =
                     (short)uVar23 - (short)(uVar23 >> 5) | (uVar9 | *(ushort *)param_8) & 0x820 |
                     (ushort)uVar15;
                param_8 = (uint *)((int)param_8 + 2);
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            if (-1 < local_68) {
              if ((((iVar4 <= (int)local_3c && (int)local_3c < iVar10) &&
                   *(char *)(local_3c + iVar7) == '\0') && local_58 < iVar6) &&
                  iVar26 <= (int)local_40) {
                iVar24 = iVar26;
                if (iVar26 <= local_58) {
                  iVar24 = local_58;
                }
                uVar23 = iVar6;
                if ((int)local_40 <= iVar6) {
                  uVar23 = local_40;
                }
                param_1 = (uVar23 - iVar24) + 1;
                *(undefined1 *)(local_3c + iVar7) = 1;
                param_8 = (uint *)(local_18 + iVar24 * 2 + iVar1);
                do {
                  uVar9 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                          *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                          + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
                  uVar15 = (*(ushort *)param_8 & 0xf7def7df) + (uVar9 & 0xf7def7df);
                  uVar23 = uVar15 & 0x8210820;
                  *(ushort *)param_8 =
                       (short)uVar23 - (short)(uVar23 >> 5) | (uVar9 | *(ushort *)param_8) & 0x820 |
                       (ushort)uVar15;
                  param_8 = (uint *)((int)param_8 + 2);
                  param_1 = param_1 + -1;
                } while (param_1 != 0);
              }
              iVar24 = local_54 + iVar22;
              if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar7 + iVar24) == '\0') &&
                  local_58 < iVar6) && iVar26 <= (int)local_40) {
                iVar12 = iVar26;
                if (iVar26 <= local_58) {
                  iVar12 = local_58;
                }
                uVar23 = iVar6;
                if ((int)local_40 <= iVar6) {
                  uVar23 = local_40;
                }
                param_1 = (uVar23 - iVar12) + 1;
                *(undefined1 *)(iVar7 + iVar24) = 1;
                param_8 = (uint *)(local_1c + iVar12 * 2 + iVar1);
                do {
                  uVar9 = (*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) * 0x40 +
                          *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                          + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f));
                  uVar15 = (*(ushort *)param_8 & 0xf7def7df) + (uVar9 & 0xf7def7df);
                  uVar23 = uVar15 & 0x8210820;
                  *(ushort *)param_8 =
                       (short)uVar23 - (short)(uVar23 >> 5) | (uVar9 | *(ushort *)param_8) & 0x820 |
                       (ushort)uVar15;
                  param_8 = (uint *)((int)param_8 + 2);
                  param_1 = param_1 + -1;
                } while (param_1 != 0);
              }
              local_18 = local_18 + -iVar2;
              local_1c = local_1c + iVar2;
              local_44 = local_44 + -1;
              local_3c = local_3c + -1;
              local_54 = local_54 + 1;
              local_30 = local_30 + -4;
              param_4 = param_4 + -1;
              local_68 = local_68 - local_30;
            }
            local_20 = local_20 + iVar2;
            local_34 = local_34 + 1;
            local_24 = local_24 + -iVar2;
            local_38 = local_38 + 4;
            local_68 = local_68 + 2 + local_38;
            param_2 = local_58;
          } while ((int)((uVar17 - param_3) + local_34) <= param_4);
          FUN_0056e1d0(iVar7);
          return;
        }
      }
      break;
    case 3:
      if (DAT_00dca3f8 != 0) {
        if (uVar17 == 0) {
          iVar22 = (param_2 - uVar15) + param_4;
          param_1 = param_2 - param_4;
          if ((((iVar26 <= iVar22 && iVar4 <= param_3) && param_1 < iVar6) && param_3 < iVar10) &&
              *(char *)(iVar7 + param_3) == '\0') {
            if (param_1 < iVar26) {
              param_1 = iVar26;
            }
            if (iVar6 < iVar22) {
              iVar22 = iVar6;
            }
            *(undefined1 *)(iVar7 + param_3) = 1;
            param_8 = (uint *)(iVar2 * param_3 + iVar1 + param_1 * 2);
            param_1 = (iVar22 - param_1) + 1;
            do {
              uVar23 = (*(ushort *)param_8 | 0x8210820) -
                       ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                  0x40 + *(short *)(&DAT_00d0a2e0 +
                                                   iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20 +
                                *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                       0xf7def7df);
              uVar8 = uVar23 & 0x8210820;
              *(ushort *)param_8 = (short)uVar8 - (short)(uVar8 >> 5) & (ushort)uVar23;
              param_8 = (uint *)((int)param_8 + 2);
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
        }
        if (-1 < local_68) {
          iVar22 = param_2 - uVar15;
          iVar24 = (param_3 - uVar17) + param_4;
          if ((((iVar4 <= iVar24 && iVar26 <= iVar22) && iVar24 < iVar10) &&
              *(char *)(iVar24 + iVar7) == '\0') && (int)param_2 < iVar6) {
            iVar12 = iVar26;
            if (iVar26 <= (int)param_2) {
              iVar12 = param_2;
            }
            iVar11 = iVar22;
            if (iVar6 < iVar22) {
              iVar11 = iVar6;
            }
            *(undefined1 *)(iVar24 + iVar7) = 1;
            param_1 = (iVar11 - iVar12) + 1;
            puVar25 = (ushort *)(iVar24 * iVar2 + iVar1 + iVar12 * 2);
            do {
              uVar8 = (*puVar25 | 0x8210820) -
                      ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                  iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20 +
                               *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                      0xf7def7df);
              uVar23 = uVar8 & 0x8210820;
              *puVar25 = (short)uVar23 - (short)(uVar23 >> 5) & (ushort)uVar8;
              puVar25 = puVar25 + 1;
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          iVar24 = param_3 - param_4;
          if ((((iVar4 <= iVar24 && iVar26 <= iVar22) && iVar24 < iVar10) &&
              *(char *)(iVar24 + iVar7) == '\0') && (int)param_2 < iVar6) {
            iVar12 = iVar26;
            if (iVar26 <= (int)param_2) {
              iVar12 = param_2;
            }
            iVar11 = iVar6;
            if (iVar22 <= iVar6) {
              iVar11 = iVar22;
            }
            *(undefined1 *)(iVar24 + iVar7) = 1;
            param_1 = (iVar11 - iVar12) + 1;
            param_8 = (uint *)(iVar24 * iVar2 + iVar1 + iVar12 * 2);
            do {
              uVar8 = (*(ushort *)param_8 | 0x8210820) -
                      ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                  iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20 +
                               *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                      0xf7def7df);
              uVar23 = uVar8 & 0x8210820;
              *(ushort *)param_8 = (short)uVar23 - (short)(uVar23 >> 5) & (ushort)uVar8;
              param_8 = (uint *)((int)param_8 + 2);
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          param_4 = param_4 + -1;
          local_68 = local_68 + param_4 * -4;
        }
        local_68 = local_68 + 6;
        if (0 < param_4) {
          local_30 = param_4 * 4;
          local_40 = param_2 - uVar15;
          local_34 = 4;
          local_3c = (param_4 - uVar17) + param_3;
          local_54 = param_2 - param_4;
          local_44 = (param_4 - uVar15) + param_2;
          local_5c = (param_3 - uVar17) + 1;
          local_1c = (param_3 - param_4) * iVar2;
          local_18 = local_3c * iVar2;
          local_24 = (param_3 + -1) * iVar2;
          local_20 = local_5c * iVar2;
          iVar22 = param_3 - param_2;
          do {
            local_40 = local_40 + 1;
            local_58 = param_2 + -1;
            if ((((iVar4 <= (int)local_5c && (int)local_5c < iVar10) &&
                 *(char *)(local_5c + iVar7) == '\0') && (int)local_54 < iVar6) &&
                iVar26 <= (int)local_44) {
              uVar23 = iVar26;
              if (iVar26 <= (int)local_54) {
                uVar23 = local_54;
              }
              uVar15 = iVar6;
              if ((int)local_44 <= iVar6) {
                uVar15 = local_44;
              }
              param_1 = (uVar15 - uVar23) + 1;
              *(undefined1 *)(local_5c + iVar7) = 1;
              puVar25 = (ushort *)(local_20 + uVar23 * 2 + iVar1);
              do {
                uVar15 = (*puVar25 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                         0xf7def7df);
                uVar23 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar23 - (short)(uVar23 >> 5) & (ushort)uVar15;
                puVar25 = puVar25 + 1;
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            iVar24 = local_58 + iVar22;
            if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
                (int)local_54 < iVar6) && iVar26 <= (int)local_44) {
              uVar23 = iVar26;
              if (iVar26 <= (int)local_54) {
                uVar23 = local_54;
              }
              uVar15 = iVar6;
              if ((int)local_44 <= iVar6) {
                uVar15 = local_44;
              }
              param_1 = (uVar15 - uVar23) + 1;
              puVar25 = (ushort *)(local_24 + uVar23 * 2 + iVar1);
              *(undefined1 *)(iVar24 + iVar7) = 1;
              do {
                uVar15 = (*puVar25 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0x1f))) &
                         0xf7def7df);
                uVar23 = uVar15 & 0x8210820;
                *puVar25 = (short)uVar23 - (short)(uVar23 >> 5) & (ushort)uVar15;
                puVar25 = puVar25 + 1;
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            if (-1 < local_68) {
              if ((((iVar4 <= (int)local_3c && (int)local_3c < iVar10) &&
                   *(char *)(local_3c + iVar7) == '\0') && local_58 < iVar6) &&
                  iVar26 <= (int)local_40) {
                iVar24 = iVar26;
                if (iVar26 <= local_58) {
                  iVar24 = local_58;
                }
                uVar23 = iVar6;
                if ((int)local_40 <= iVar6) {
                  uVar23 = local_40;
                }
                param_1 = (uVar23 - iVar24) + 1;
                puVar25 = (ushort *)(local_18 + iVar24 * 2 + iVar1);
                *(undefined1 *)(local_3c + iVar7) = 1;
                do {
                  uVar15 = (*puVar25 | 0x8210820) -
                           ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb))
                                      * 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                         iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) *
                                     0x20 + *(short *)(&DAT_00d0a2e0 +
                                                      iVar18 * 0x100 + (param_5 & 0x1f))) &
                           0xf7def7df);
                  uVar23 = uVar15 & 0x8210820;
                  *puVar25 = (short)uVar23 - (short)(uVar23 >> 5) & (ushort)uVar15;
                  puVar25 = puVar25 + 1;
                  param_1 = param_1 + -1;
                } while (param_1 != 0);
              }
              iVar24 = local_54 + iVar22;
              if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
                  local_58 < iVar6) && iVar26 <= (int)local_40) {
                iVar12 = iVar26;
                if (iVar26 <= local_58) {
                  iVar12 = local_58;
                }
                uVar23 = iVar6;
                if ((int)local_40 <= iVar6) {
                  uVar23 = local_40;
                }
                param_1 = (uVar23 - iVar12) + 1;
                puVar25 = (ushort *)(local_1c + iVar12 * 2 + iVar1);
                *(undefined1 *)(iVar24 + iVar7) = 1;
                do {
                  uVar15 = (*puVar25 | 0x8210820) -
                           ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 >> 0xb))
                                      * 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                         iVar18 * 0x100 + (param_5 >> 5 & 0x3f))) *
                                     0x20 + *(short *)(&DAT_00d0a2e0 +
                                                      iVar18 * 0x100 + (param_5 & 0x1f))) &
                           0xf7def7df);
                  uVar23 = uVar15 & 0x8210820;
                  *puVar25 = (short)uVar23 - (short)(uVar23 >> 5) & (ushort)uVar15;
                  puVar25 = puVar25 + 1;
                  param_1 = param_1 + -1;
                } while (param_1 != 0);
              }
              local_18 = local_18 + -iVar2;
              local_44 = local_44 + -1;
              local_3c = local_3c + -1;
              local_54 = local_54 + 1;
              local_1c = local_1c + iVar2;
              param_4 = param_4 + -1;
              local_30 = local_30 + -4;
              local_68 = local_68 - local_30;
            }
            local_20 = local_20 + iVar2;
            local_24 = local_24 + -iVar2;
            local_34 = local_34 + 4;
            local_68 = local_68 + 2 + local_34;
            local_5c = local_5c + 1;
            param_2 = local_58;
          } while ((int)(local_5c + (uVar17 - param_3)) <= param_4);
          FUN_0056e1d0(iVar7);
          return;
        }
      }
      break;
    case 4:
      if (uVar17 == 0) {
        iVar22 = param_2 - param_4;
        iVar18 = (param_2 - uVar15) + param_4;
        if ((((iVar26 <= iVar18 && iVar4 <= param_3) && iVar22 < iVar6) && param_3 < iVar10) &&
            *(char *)(iVar7 + param_3) == '\0') {
          if (iVar22 < iVar26) {
            iVar22 = iVar26;
          }
          if (iVar6 < iVar18) {
            iVar18 = iVar6;
          }
          param_1 = (iVar18 - iVar22) + 1;
          *(undefined1 *)(iVar7 + param_3) = 1;
          param_8 = (uint *)(iVar2 * param_3 + iVar1 + iVar22 * 2);
          do {
            uVar23 = (uint)*(ushort *)param_8;
            *(ushort *)param_8 =
                 (ushort)((uVar23 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                 (ushort)((uVar23 & 0xf800) * (param_5 & 0xf800) >> 0x10) & 0xf800 |
                 (ushort)((uVar23 & 0x1f) * (param_5 & 0x1f) >> 5);
            param_8 = (uint *)((int)param_8 + 2);
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
      }
      if (-1 < local_68) {
        iVar22 = (param_3 - uVar17) + param_4;
        iVar18 = param_2 - uVar15;
        if ((((iVar4 <= iVar22 && iVar26 <= iVar18) && iVar22 < iVar10) &&
            *(char *)(iVar7 + iVar22) == '\0') && (int)param_2 < iVar6) {
          iVar24 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar24 = param_2;
          }
          iVar12 = iVar18;
          if (iVar6 < iVar18) {
            iVar12 = iVar6;
          }
          *(undefined1 *)(iVar7 + iVar22) = 1;
          param_1 = (iVar12 - iVar24) + 1;
          param_8 = (uint *)(iVar22 * iVar2 + iVar1 + iVar24 * 2);
          do {
            uVar23 = (uint)*(ushort *)param_8;
            *(ushort *)param_8 =
                 (ushort)((uVar23 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                 (ushort)((uVar23 & 0xf800) * (param_5 & 0xf800) >> 0x10) & 0xf800 |
                 (ushort)((uVar23 & 0x1f) * (param_5 & 0x1f) >> 5);
            param_8 = (uint *)((int)param_8 + 2);
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
        iVar22 = param_3 - param_4;
        if ((((iVar4 <= iVar22 && iVar26 <= iVar18) && iVar22 < iVar10) &&
            *(char *)(iVar7 + iVar22) == '\0') && (int)param_2 < iVar6) {
          iVar24 = param_2;
          if ((int)param_2 < iVar26) {
            iVar24 = iVar26;
          }
          if (iVar6 < iVar18) {
            iVar18 = iVar6;
          }
          *(undefined1 *)(iVar7 + iVar22) = 1;
          param_1 = (iVar18 - iVar24) + 1;
          param_8 = (uint *)(iVar22 * iVar2 + iVar1 + iVar24 * 2);
          do {
            uVar23 = (uint)*(ushort *)param_8;
            *(ushort *)param_8 =
                 (ushort)((uVar23 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                 (ushort)((uVar23 & 0xf800) * (param_5 & 0xf800) >> 0x10) & 0xf800 |
                 (ushort)((uVar23 & 0x1f) * (param_5 & 0x1f) >> 5);
            param_8 = (uint *)((int)param_8 + 2);
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
        param_4 = param_4 + -1;
        local_68 = local_68 + param_4 * -4;
      }
      local_68 = local_68 + 6;
      if (0 < param_4) {
        local_30 = param_4 * 4;
        local_5c = param_2 - uVar15;
        local_34 = 4;
        local_40 = (param_4 - uVar17) + param_3;
        local_50 = param_2 - param_4;
        local_58 = (param_3 - uVar17) + 1;
        local_44 = (param_4 - uVar15) + param_2;
        local_1c = (param_3 - param_4) * iVar2;
        local_18 = local_40 * iVar2;
        local_24 = (param_3 + -1) * iVar2;
        local_20 = local_58 * iVar2;
        iVar18 = param_3 - param_2;
        do {
          local_54 = param_2 + -1;
          local_5c = local_5c + 1;
          if ((((iVar4 <= local_58 && local_58 < iVar10) && *(char *)(local_58 + iVar7) == '\0') &&
              (int)local_50 < iVar6) && iVar26 <= (int)local_44) {
            uVar23 = iVar26;
            if (iVar26 <= (int)local_50) {
              uVar23 = local_50;
            }
            uVar15 = iVar6;
            if ((int)local_44 <= iVar6) {
              uVar15 = local_44;
            }
            param_1 = (uVar15 - uVar23) + 1;
            param_8 = (uint *)(local_20 + uVar23 * 2 + iVar1);
            *(undefined1 *)(local_58 + iVar7) = 1;
            do {
              uVar23 = (uint)*(ushort *)param_8;
              *(ushort *)param_8 =
                   (ushort)((uVar23 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                   (ushort)((uVar23 & 0xf800) * (param_5 & 0xf800) >> 0x10) & 0xf800 |
                   (ushort)((uVar23 & 0x1f) * (param_5 & 0x1f) >> 5);
              param_8 = (uint *)((int)param_8 + 2);
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          iVar22 = iVar18 + local_54;
          if ((((iVar4 <= iVar22 && iVar22 < iVar10) && *(char *)(iVar22 + iVar7) == '\0') &&
              (int)local_50 < iVar6) && iVar26 <= (int)local_44) {
            uVar23 = iVar26;
            if (iVar26 <= (int)local_50) {
              uVar23 = local_50;
            }
            uVar15 = iVar6;
            if ((int)local_44 <= iVar6) {
              uVar15 = local_44;
            }
            param_1 = (uVar15 - uVar23) + 1;
            param_8 = (uint *)(local_24 + uVar23 * 2 + iVar1);
            *(undefined1 *)(iVar22 + iVar7) = 1;
            do {
              uVar23 = (uint)*(ushort *)param_8;
              *(ushort *)param_8 =
                   (ushort)((uVar23 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                   (ushort)((uVar23 & 0xf800) * (param_5 & 0xf800) >> 0x10) & 0xf800 |
                   (ushort)((uVar23 & 0x1f) * (param_5 & 0x1f) >> 5);
              param_8 = (uint *)((int)param_8 + 2);
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          if (-1 < local_68) {
            if ((((iVar4 <= (int)local_40 && (int)local_40 < iVar10) &&
                 *(char *)(local_40 + iVar7) == '\0') && (int)local_54 < iVar6) &&
                iVar26 <= (int)local_5c) {
              uVar23 = iVar26;
              if (iVar26 <= (int)local_54) {
                uVar23 = local_54;
              }
              iVar22 = iVar6;
              if ((int)local_5c <= iVar6) {
                iVar22 = local_5c;
              }
              param_1 = (iVar22 - uVar23) + 1;
              param_8 = (uint *)(local_18 + uVar23 * 2 + iVar1);
              *(undefined1 *)(local_40 + iVar7) = 1;
              do {
                uVar23 = (uint)*(ushort *)param_8;
                *(ushort *)param_8 =
                     (ushort)((uVar23 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                     (ushort)((uVar23 & 0xf800) * (param_5 & 0xf800) >> 0x10) & 0xf800 |
                     (ushort)((uVar23 & 0x1f) * (param_5 & 0x1f) >> 5);
                param_8 = (uint *)((int)param_8 + 2);
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            iVar22 = iVar18 + local_50;
            if ((((iVar4 <= iVar22 && iVar22 < iVar10) && *(char *)(iVar22 + iVar7) == '\0') &&
                (int)local_54 < iVar6) && iVar26 <= (int)local_5c) {
              uVar23 = iVar26;
              if (iVar26 <= (int)local_54) {
                uVar23 = local_54;
              }
              iVar24 = iVar6;
              if ((int)local_5c <= iVar6) {
                iVar24 = local_5c;
              }
              param_1 = (iVar24 - uVar23) + 1;
              param_8 = (uint *)(local_1c + uVar23 * 2 + iVar1);
              *(undefined1 *)(iVar22 + iVar7) = 1;
              do {
                uVar23 = (uint)*(ushort *)param_8;
                *(ushort *)param_8 =
                     (ushort)((uVar23 & 0x7e0) * (param_5 & 0x7e0) >> 0xb) & 0x7e0 |
                     (ushort)((uVar23 & 0xf800) * (param_5 & 0xf800) >> 0x10) & 0xf800 |
                     (ushort)((uVar23 & 0x1f) * (param_5 & 0x1f) >> 5);
                param_8 = (uint *)((int)param_8 + 2);
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            local_18 = local_18 + -iVar2;
            local_1c = local_1c + iVar2;
            local_44 = local_44 + -1;
            local_40 = local_40 + -1;
            local_50 = local_50 + 1;
            local_30 = local_30 + -4;
            param_4 = param_4 + -1;
            local_68 = local_68 - local_30;
          }
          local_20 = local_20 + iVar2;
          local_24 = local_24 + -iVar2;
          local_34 = local_34 + 4;
          local_68 = local_68 + 2 + local_34;
          local_58 = local_58 + 1;
          param_2 = local_54;
        } while ((int)((uVar17 - param_3) + local_58) <= param_4);
        FUN_0056e1d0(iVar7);
        return;
      }
      break;
    case 10:
      if (uVar17 == 0) {
        param_1 = param_2 - param_4;
        iVar22 = (param_2 - uVar15) + param_4;
        if ((((iVar26 <= iVar22 && iVar4 <= param_3) && param_1 < iVar6) && param_3 < iVar10) &&
            *(char *)(iVar7 + param_3) == '\0') {
          if (param_1 < iVar26) {
            param_1 = iVar26;
          }
          if (iVar6 < iVar22) {
            iVar22 = iVar6;
          }
          *(undefined1 *)(iVar7 + param_3) = 1;
          param_8 = (uint *)(iVar2 * param_3 + iVar1 + param_1 * 2);
          uVar23 = ~param_5 & 0xffff;
          param_1 = (iVar22 - param_1) + 1;
          do {
            uVar9 = *(ushort *)param_8;
            *(ushort *)param_8 =
                 ((uVar9 >> 5 & 0x3f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((uVar23 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800)) *
                 0x20 | ((uVar9 >> 0xb) +
                        *(short *)(&DAT_00d4a6e0 +
                                  ((uVar23 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) *
                        0x800 |
                 (uVar9 & 0x1f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
            param_8 = (uint *)((int)param_8 + 2);
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
      }
      if (-1 < local_68) {
        iVar22 = param_2 - uVar15;
        iVar24 = (param_3 - uVar17) + param_4;
        if ((((iVar4 <= iVar24 && iVar26 <= iVar22) && iVar24 < iVar10) &&
            *(char *)(iVar24 + iVar7) == '\0') && (int)param_2 < iVar6) {
          iVar12 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar12 = param_2;
          }
          iVar11 = iVar22;
          if (iVar6 < iVar22) {
            iVar11 = iVar6;
          }
          *(undefined1 *)(iVar24 + iVar7) = 1;
          param_1 = (iVar11 - iVar12) + 1;
          uVar23 = ~param_5 & 0xffff;
          param_8 = (uint *)(iVar24 * iVar2 + iVar1 + iVar12 * 2);
          do {
            uVar9 = *(ushort *)param_8;
            *(ushort *)param_8 =
                 ((uVar9 >> 5 & 0x3f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((uVar23 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800)) *
                 0x20 | ((uVar9 >> 0xb) +
                        *(short *)(&DAT_00d4a6e0 +
                                  ((uVar23 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) *
                        0x800 |
                 (uVar9 & 0x1f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
            param_8 = (uint *)((int)param_8 + 2);
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
        iVar24 = param_3 - param_4;
        if ((((iVar4 <= iVar24 && iVar26 <= iVar22) && iVar24 < iVar10) &&
            *(char *)(iVar24 + iVar7) == '\0') && (int)param_2 < iVar6) {
          iVar12 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar12 = param_2;
          }
          if (iVar6 < iVar22) {
            iVar22 = iVar6;
          }
          *(undefined1 *)(iVar24 + iVar7) = 1;
          param_1 = (iVar22 - iVar12) + 1;
          param_8 = (uint *)(iVar24 * iVar2 + iVar1 + iVar12 * 2);
          uVar23 = ~param_5 & 0xffff;
          do {
            uVar9 = *(ushort *)param_8;
            *(ushort *)param_8 =
                 ((uVar9 >> 5 & 0x3f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((uVar23 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800)) *
                 0x20 | ((uVar9 >> 0xb) +
                        *(short *)(&DAT_00d4a6e0 +
                                  ((uVar23 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) *
                        0x800 |
                 (uVar9 & 0x1f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
            param_8 = (uint *)((int)param_8 + 2);
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
        param_4 = param_4 + -1;
        local_68 = local_68 + param_4 * -4;
      }
      local_68 = local_68 + 6;
      if (0 < param_4) {
        local_30 = param_4 * 4;
        local_40 = param_2 - uVar15;
        local_38 = 4;
        local_3c = (param_4 - uVar17) + param_3;
        local_54 = param_2 - param_4;
        local_44 = (param_4 - uVar15) + param_2;
        local_1c = (param_3 - param_4) * iVar2;
        local_18 = local_3c * iVar2;
        local_24 = (param_3 + -1) * iVar2;
        local_34 = (param_3 - uVar17) + 1;
        local_20 = local_34 * iVar2;
        iVar22 = param_3 - param_2;
        do {
          local_40 = local_40 + 1;
          local_58 = param_2 + -1;
          if ((((iVar4 <= (int)local_34 && (int)local_34 < iVar10) &&
               *(char *)(local_34 + iVar7) == '\0') && (int)local_54 < iVar6) &&
              iVar26 <= (int)local_44) {
            uVar23 = iVar26;
            if (iVar26 <= (int)local_54) {
              uVar23 = local_54;
            }
            uVar15 = iVar6;
            if ((int)local_44 <= iVar6) {
              uVar15 = local_44;
            }
            param_1 = (uVar15 - uVar23) + 1;
            *(undefined1 *)(local_34 + iVar7) = 1;
            param_8 = (uint *)(local_20 + uVar23 * 2 + iVar1);
            uVar23 = ~param_5 & 0xffff;
            do {
              uVar9 = *(ushort *)param_8;
              *(ushort *)param_8 =
                   ((uVar9 >> 5 & 0x3f) +
                   *(short *)(&DAT_00d4a6e0 +
                             ((uVar23 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800)) *
                   0x20 | ((uVar9 >> 0xb) +
                          *(short *)(&DAT_00d4a6e0 +
                                    ((uVar23 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                          * 0x800 |
                   (uVar9 & 0x1f) +
                   *(short *)(&DAT_00d4a6e0 +
                             ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
              param_8 = (uint *)((int)param_8 + 2);
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          iVar24 = local_58 + iVar22;
          if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
              (int)local_54 < iVar6) && iVar26 <= (int)local_44) {
            uVar23 = iVar26;
            if (iVar26 <= (int)local_54) {
              uVar23 = local_54;
            }
            uVar15 = iVar6;
            if ((int)local_44 <= iVar6) {
              uVar15 = local_44;
            }
            param_1 = (uVar15 - uVar23) + 1;
            param_8 = (uint *)(local_24 + uVar23 * 2 + iVar1);
            *(undefined1 *)(iVar24 + iVar7) = 1;
            uVar23 = ~param_5 & 0xffff;
            do {
              uVar9 = *(ushort *)param_8;
              *(ushort *)param_8 =
                   ((uVar9 >> 5 & 0x3f) +
                   *(short *)(&DAT_00d4a6e0 +
                             ((uVar23 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800)) *
                   0x20 | ((uVar9 >> 0xb) +
                          *(short *)(&DAT_00d4a6e0 +
                                    ((uVar23 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800))
                          * 0x800 |
                   (uVar9 & 0x1f) +
                   *(short *)(&DAT_00d4a6e0 +
                             ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
              param_8 = (uint *)((int)param_8 + 2);
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          if (-1 < local_68) {
            if ((((iVar4 <= (int)local_3c && (int)local_3c < iVar10) &&
                 *(char *)(local_3c + iVar7) == '\0') && local_58 < iVar6) &&
                iVar26 <= (int)local_40) {
              iVar24 = iVar26;
              if (iVar26 <= local_58) {
                iVar24 = local_58;
              }
              uVar23 = iVar6;
              if ((int)local_40 <= iVar6) {
                uVar23 = local_40;
              }
              param_1 = (uVar23 - iVar24) + 1;
              param_8 = (uint *)(local_18 + iVar24 * 2 + iVar1);
              *(undefined1 *)(local_3c + iVar7) = 1;
              uVar23 = ~param_5 & 0xffff;
              do {
                uVar9 = *(ushort *)param_8;
                *(ushort *)param_8 =
                     ((uVar9 >> 5 & 0x3f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((uVar23 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800)) *
                     0x20 | ((uVar9 >> 0xb) +
                            *(short *)(&DAT_00d4a6e0 +
                                      ((uVar23 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)
                            ) * 0x800 |
                     (uVar9 & 0x1f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
                param_8 = (uint *)((int)param_8 + 2);
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            iVar24 = local_54 + iVar22;
            if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
                local_58 < iVar6) && iVar26 <= (int)local_40) {
              iVar12 = iVar26;
              if (iVar26 <= local_58) {
                iVar12 = local_58;
              }
              uVar23 = iVar6;
              if ((int)local_40 <= iVar6) {
                uVar23 = local_40;
              }
              param_1 = (uVar23 - iVar12) + 1;
              param_8 = (uint *)(local_1c + iVar12 * 2 + iVar1);
              *(undefined1 *)(iVar24 + iVar7) = 1;
              uVar23 = ~param_5 & 0xffff;
              do {
                uVar9 = *(ushort *)param_8;
                *(ushort *)param_8 =
                     ((uVar9 >> 5 & 0x3f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((uVar23 >> 5 & 0x3f) - (uVar9 >> 5 & 0x3f)) * 4 + iVar18 * 0x800)) *
                     0x20 | ((uVar9 >> 0xb) +
                            *(short *)(&DAT_00d4a6e0 +
                                      ((uVar23 >> 0xb) - (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)
                            ) * 0x800 |
                     (uVar9 & 0x1f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((~param_5 & 0x1f) - (uVar9 & 0x1f)) * 4 + iVar18 * 0x800);
                param_8 = (uint *)((int)param_8 + 2);
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            local_18 = local_18 + -iVar2;
            local_1c = local_1c + iVar2;
            local_44 = local_44 + -1;
            local_3c = local_3c + -1;
            local_54 = local_54 + 1;
            local_30 = local_30 + -4;
            param_4 = param_4 + -1;
            local_68 = local_68 - local_30;
          }
          local_20 = local_20 + iVar2;
          local_34 = local_34 + 1;
          local_24 = local_24 + -iVar2;
          local_38 = local_38 + 4;
          local_68 = local_68 + 2 + local_38;
          param_2 = local_58;
        } while ((int)((uVar17 - param_3) + local_34) <= param_4);
      }
      break;
    case 0xb:
      if (uVar17 == 0) {
        param_1 = param_2 - param_4;
        iVar22 = (param_2 - uVar15) + param_4;
        if ((((iVar26 <= iVar22 && iVar4 <= param_3) && param_1 < iVar6) && param_3 < iVar10) &&
            *(char *)(iVar7 + param_3) == '\0') {
          if (param_1 < iVar26) {
            param_1 = iVar26;
          }
          if (iVar6 < iVar22) {
            iVar22 = iVar6;
          }
          *(undefined1 *)(iVar7 + param_3) = 1;
          param_8 = (uint *)(iVar2 * param_3 + iVar1 + param_1 * 2);
          param_1 = (iVar22 - param_1) + 1;
          do {
            uVar9 = *(ushort *)param_8;
            uVar23 = uVar9 >> 5 & 0x3f;
            *(ushort *)param_8 =
                 ((uVar9 >> 5 & 0x3f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((uVar23 * (param_5 >> 5 & 0x3f) >> 6) - uVar23) * 4 + iVar18 * 0x800)) *
                 0x20 | ((uVar9 >> 0xb) +
                        *(short *)(&DAT_00d4a6e0 +
                                  (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                  (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                 (uVar9 & 0x1f) +
                 *(short *)(&DAT_00d4a6e0 +
                           (((uVar9 & 0x1f) * (param_5 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                           iVar18 * 0x800);
            param_8 = (uint *)((int)param_8 + 2);
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
      }
      if (-1 < local_68) {
        iVar22 = param_2 - uVar15;
        iVar24 = (param_3 - uVar17) + param_4;
        if ((((iVar4 <= iVar24 && iVar26 <= iVar22) && iVar24 < iVar10) &&
            *(char *)(iVar24 + iVar7) == '\0') && (int)param_2 < iVar6) {
          iVar12 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar12 = param_2;
          }
          iVar11 = iVar22;
          if (iVar6 < iVar22) {
            iVar11 = iVar6;
          }
          *(undefined1 *)(iVar24 + iVar7) = 1;
          param_1 = (iVar11 - iVar12) + 1;
          param_8 = (uint *)(iVar24 * iVar2 + iVar1 + iVar12 * 2);
          do {
            uVar9 = *(ushort *)param_8;
            uVar23 = uVar9 >> 5 & 0x3f;
            *(ushort *)param_8 =
                 ((uVar9 >> 5 & 0x3f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((uVar23 * (param_5 >> 5 & 0x3f) >> 6) - uVar23) * 4 + iVar18 * 0x800)) *
                 0x20 | ((uVar9 >> 0xb) +
                        *(short *)(&DAT_00d4a6e0 +
                                  (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                  (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                 (uVar9 & 0x1f) +
                 *(short *)(&DAT_00d4a6e0 +
                           (((uVar9 & 0x1f) * (param_5 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                           iVar18 * 0x800);
            param_8 = (uint *)((int)param_8 + 2);
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
        iVar24 = param_3 - param_4;
        if ((((iVar4 <= iVar24 && iVar26 <= iVar22) && iVar24 < iVar10) &&
            *(char *)(iVar24 + iVar7) == '\0') && (int)param_2 < iVar6) {
          iVar12 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar12 = param_2;
          }
          if (iVar6 < iVar22) {
            iVar22 = iVar6;
          }
          *(undefined1 *)(iVar24 + iVar7) = 1;
          param_1 = (iVar22 - iVar12) + 1;
          param_8 = (uint *)(iVar24 * iVar2 + iVar1 + iVar12 * 2);
          do {
            uVar9 = *(ushort *)param_8;
            uVar23 = uVar9 >> 5 & 0x3f;
            *(ushort *)param_8 =
                 ((uVar9 >> 5 & 0x3f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((uVar23 * (param_5 >> 5 & 0x3f) >> 6) - uVar23) * 4 + iVar18 * 0x800)) *
                 0x20 | ((uVar9 >> 0xb) +
                        *(short *)(&DAT_00d4a6e0 +
                                  (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                  (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                 (uVar9 & 0x1f) +
                 *(short *)(&DAT_00d4a6e0 +
                           (((uVar9 & 0x1f) * (param_5 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                           iVar18 * 0x800);
            param_8 = (uint *)((int)param_8 + 2);
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
        param_4 = param_4 + -1;
        local_68 = local_68 + param_4 * -4;
      }
      local_68 = local_68 + 6;
      if (0 < param_4) {
        local_30 = param_4 * 4;
        local_40 = param_2 - uVar15;
        local_38 = 4;
        local_3c = (param_4 - uVar17) + param_3;
        local_58 = param_2 - param_4;
        local_44 = (param_4 - uVar15) + param_2;
        local_1c = (param_3 - param_4) * iVar2;
        local_18 = local_3c * iVar2;
        local_24 = (param_3 + -1) * iVar2;
        local_34 = (param_3 - uVar17) + 1;
        local_20 = local_34 * iVar2;
        iVar22 = param_3 - param_2;
        do {
          local_40 = local_40 + 1;
          local_5c = param_2 + -1;
          if ((((iVar4 <= (int)local_34 && (int)local_34 < iVar10) &&
               *(char *)(local_34 + iVar7) == '\0') && local_58 < iVar6) && iVar26 <= (int)local_44)
          {
            iVar24 = iVar26;
            if (iVar26 <= local_58) {
              iVar24 = local_58;
            }
            uVar23 = iVar6;
            if ((int)local_44 <= iVar6) {
              uVar23 = local_44;
            }
            param_1 = (uVar23 - iVar24) + 1;
            *(undefined1 *)(local_34 + iVar7) = 1;
            param_8 = (uint *)(local_20 + iVar24 * 2 + iVar1);
            do {
              uVar9 = *(ushort *)param_8;
              uVar23 = uVar9 >> 5 & 0x3f;
              *(ushort *)param_8 =
                   ((uVar9 >> 5 & 0x3f) +
                   *(short *)(&DAT_00d4a6e0 +
                             ((uVar23 * (param_5 >> 5 & 0x3f) >> 6) - uVar23) * 4 + iVar18 * 0x800))
                   * 0x20 | ((uVar9 >> 0xb) +
                            *(short *)(&DAT_00d4a6e0 +
                                      (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                      (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                   (uVar9 & 0x1f) +
                   *(short *)(&DAT_00d4a6e0 +
                             (((uVar9 & 0x1f) * (param_5 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                             iVar18 * 0x800);
              param_8 = (uint *)((int)param_8 + 2);
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          iVar24 = local_5c + iVar22;
          if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
              local_58 < iVar6) && iVar26 <= (int)local_44) {
            iVar12 = iVar26;
            if (iVar26 <= local_58) {
              iVar12 = local_58;
            }
            uVar23 = iVar6;
            if ((int)local_44 <= iVar6) {
              uVar23 = local_44;
            }
            param_1 = (uVar23 - iVar12) + 1;
            param_8 = (uint *)(local_24 + iVar12 * 2 + iVar1);
            *(undefined1 *)(iVar24 + iVar7) = 1;
            do {
              uVar9 = *(ushort *)param_8;
              uVar23 = uVar9 >> 5 & 0x3f;
              *(ushort *)param_8 =
                   ((uVar9 >> 5 & 0x3f) +
                   *(short *)(&DAT_00d4a6e0 +
                             ((uVar23 * (param_5 >> 5 & 0x3f) >> 6) - uVar23) * 4 + iVar18 * 0x800))
                   * 0x20 | ((uVar9 >> 0xb) +
                            *(short *)(&DAT_00d4a6e0 +
                                      (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                                      (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                   (uVar9 & 0x1f) +
                   *(short *)(&DAT_00d4a6e0 +
                             (((uVar9 & 0x1f) * (param_5 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                             iVar18 * 0x800);
              param_8 = (uint *)((int)param_8 + 2);
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          if (-1 < local_68) {
            if ((((iVar4 <= (int)local_3c && (int)local_3c < iVar10) &&
                 *(char *)(local_3c + iVar7) == '\0') && (int)local_5c < iVar6) &&
                iVar26 <= (int)local_40) {
              iVar24 = iVar26;
              if (iVar26 <= (int)local_5c) {
                iVar24 = local_5c;
              }
              uVar23 = iVar6;
              if ((int)local_40 <= iVar6) {
                uVar23 = local_40;
              }
              param_1 = (uVar23 - iVar24) + 1;
              param_8 = (uint *)(local_18 + iVar24 * 2 + iVar1);
              *(undefined1 *)(local_3c + iVar7) = 1;
              do {
                uVar9 = *(ushort *)param_8;
                uVar23 = uVar9 >> 5 & 0x3f;
                *(ushort *)param_8 =
                     ((uVar9 >> 5 & 0x3f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((uVar23 * (param_5 >> 5 & 0x3f) >> 6) - uVar23) * 4 + iVar18 * 0x800
                               )) * 0x20 |
                     ((uVar9 >> 0xb) +
                     *(short *)(&DAT_00d4a6e0 +
                               (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                               (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                     (uVar9 & 0x1f) +
                     *(short *)(&DAT_00d4a6e0 +
                               (((uVar9 & 0x1f) * (param_5 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                               iVar18 * 0x800);
                param_8 = (uint *)((int)param_8 + 2);
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            iVar24 = local_58 + iVar22;
            if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
                (int)local_5c < iVar6) && iVar26 <= (int)local_40) {
              iVar12 = iVar26;
              if (iVar26 <= (int)local_5c) {
                iVar12 = local_5c;
              }
              uVar23 = iVar6;
              if ((int)local_40 <= iVar6) {
                uVar23 = local_40;
              }
              param_1 = (uVar23 - iVar12) + 1;
              param_8 = (uint *)(local_1c + iVar12 * 2 + iVar1);
              *(undefined1 *)(iVar24 + iVar7) = 1;
              do {
                uVar9 = *(ushort *)param_8;
                uVar23 = uVar9 >> 5 & 0x3f;
                *(ushort *)param_8 =
                     ((uVar9 >> 5 & 0x3f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((uVar23 * (param_5 >> 5 & 0x3f) >> 6) - uVar23) * 4 + iVar18 * 0x800
                               )) * 0x20 |
                     ((uVar9 >> 0xb) +
                     *(short *)(&DAT_00d4a6e0 +
                               (((param_5 >> 0xb) * (uint)(uVar9 >> 0xb) >> 5) -
                               (uint)(uVar9 >> 0xb)) * 4 + iVar18 * 0x800)) * 0x800 |
                     (uVar9 & 0x1f) +
                     *(short *)(&DAT_00d4a6e0 +
                               (((uVar9 & 0x1f) * (param_5 & 0x1f) >> 5) - (uVar9 & 0x1f)) * 4 +
                               iVar18 * 0x800);
                param_8 = (uint *)((int)param_8 + 2);
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            local_18 = local_18 + -iVar2;
            local_1c = local_1c + iVar2;
            local_44 = local_44 + -1;
            local_3c = local_3c + -1;
            local_58 = local_58 + 1;
            local_30 = local_30 + -4;
            param_4 = param_4 + -1;
            local_68 = local_68 - local_30;
          }
          local_20 = local_20 + iVar2;
          local_34 = local_34 + 1;
          local_24 = local_24 + -iVar2;
          local_38 = local_38 + 4;
          local_68 = local_68 + 2 + local_38;
          param_2 = local_5c;
        } while ((int)((uVar17 - param_3) + local_34) <= param_4);
        FUN_0056e1d0(iVar7);
        return;
      }
    }
  }
  else if (iVar22 == 1) {
    if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
      param_5._0_2_ =
           CONCAT11((char)((param_5 >> 8 & 0xff) * (DAT_00dca3fc >> 8 & 0xff) >> 8),(byte)param_5);
      param_5 = CONCAT22(CONCAT11(param_5._3_1_,
                                  (char)((uint)param_5._2_1_ * (DAT_00dca3fc >> 0x10 & 0xff) >> 8)),
                         (ushort)param_5);
      uVar23 = (uint)(ushort)param_5;
      param_5 = CONCAT31(param_5._1_3_,(char)((uVar23 & 0xff) * (DAT_00dca3fc & 0xff) >> 8));
    }
    switch(DAT_00dca3f4) {
    case 1:
      if (DAT_00dca3f8 != 0xff) {
        if (DAT_00dca3f8 != 0) {
          if (uVar17 == 0) {
            iVar18 = (param_2 - uVar15) + param_4;
            iVar22 = param_2 - param_4;
            if ((((iVar26 <= iVar18 && iVar4 <= param_3) && iVar22 < iVar6) && param_3 < iVar10) &&
                *(char *)(iVar7 + param_3) == '\0') {
              if (iVar22 < iVar26) {
                iVar22 = iVar26;
              }
              if (iVar6 < iVar18) {
                iVar18 = iVar6;
              }
              iVar18 = (iVar18 - iVar22) + 1;
              *(undefined1 *)(iVar7 + param_3) = 1;
              pbVar19 = (byte *)(iVar2 * param_3 + iVar1 + iVar22 * 4);
              do {
                *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                  (uint)*pbVar19 * 0x100 >> 8);
                pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                    (uint)pbVar19[1] * 0x100 >> 8);
                pbVar19[2] = (byte)(((uint)param_5._2_1_ - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                    (uint)pbVar19[2] * 0x100 >> 8);
                pbVar19 = pbVar19 + 4;
                iVar18 = iVar18 + -1;
              } while (iVar18 != 0);
            }
          }
          if (-1 < local_68) {
            iVar22 = (param_3 - uVar17) + param_4;
            iVar18 = param_2 - uVar15;
            if ((((iVar4 <= iVar22 && iVar26 <= iVar18) && iVar22 < iVar10) &&
                *(char *)(iVar7 + iVar22) == '\0') && (int)param_2 < iVar6) {
              iVar24 = iVar26;
              if (iVar26 <= (int)param_2) {
                iVar24 = param_2;
              }
              iVar12 = iVar18;
              if (iVar6 < iVar18) {
                iVar12 = iVar6;
              }
              *(undefined1 *)(iVar7 + iVar22) = 1;
              iVar12 = (iVar12 - iVar24) + 1;
              pbVar19 = (byte *)(iVar22 * iVar2 + iVar1 + iVar24 * 4);
              do {
                *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                  (uint)*pbVar19 * 0x100 >> 8);
                pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                    (uint)pbVar19[1] * 0x100 >> 8);
                pbVar19[2] = (byte)(((uint)param_5._2_1_ - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                    (uint)pbVar19[2] * 0x100 >> 8);
                pbVar19 = pbVar19 + 4;
                iVar12 = iVar12 + -1;
              } while (iVar12 != 0);
            }
            iVar22 = param_3 - param_4;
            if ((((iVar4 <= iVar22 && iVar26 <= iVar18) && iVar22 < iVar10) &&
                *(char *)(iVar7 + iVar22) == '\0') && (int)param_2 < iVar6) {
              iVar24 = iVar26;
              if (iVar26 <= (int)param_2) {
                iVar24 = param_2;
              }
              if (iVar6 < iVar18) {
                iVar18 = iVar6;
              }
              *(undefined1 *)(iVar7 + iVar22) = 1;
              iVar18 = (iVar18 - iVar24) + 1;
              pbVar19 = (byte *)(iVar22 * iVar2 + iVar1 + iVar24 * 4);
              do {
                *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                  (uint)*pbVar19 * 0x100 >> 8);
                pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                    (uint)pbVar19[1] * 0x100 >> 8);
                pbVar19[2] = (byte)(((uint)param_5._2_1_ - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                    (uint)pbVar19[2] * 0x100 >> 8);
                pbVar19 = pbVar19 + 4;
                iVar18 = iVar18 + -1;
              } while (iVar18 != 0);
            }
            param_4 = param_4 + -1;
            local_68 = local_68 + param_4 * -4;
          }
          local_68 = local_68 + 6;
          if (0 < param_4) {
            local_34 = param_4 * 4;
            local_58 = param_2 - uVar15;
            local_40 = (param_4 - uVar17) + param_3;
            local_50 = param_2 - param_4;
            local_54 = (param_3 - uVar17) + 1;
            local_1c = (param_3 - param_4) * iVar2;
            local_18 = local_40 * iVar2;
            local_24 = (param_3 + -1) * iVar2;
            local_20 = local_54 * iVar2;
            iVar18 = (param_4 - uVar15) + param_2;
            iVar22 = param_3 - param_2;
            local_38 = 4;
            local_30 = iVar18;
            do {
              local_4c = param_2 + -1;
              local_58 = local_58 + 1;
              if ((((iVar4 <= (int)local_54 && (int)local_54 < iVar10) &&
                   *(char *)(local_54 + iVar7) == '\0') && (int)local_50 < iVar6) &&
                  iVar26 <= iVar18) {
                uVar23 = iVar26;
                if (iVar26 <= (int)local_50) {
                  uVar23 = local_50;
                }
                iVar24 = iVar18;
                if (iVar6 < iVar18) {
                  iVar24 = iVar6;
                }
                iVar24 = (iVar24 - uVar23) + 1;
                *(undefined1 *)(local_54 + iVar7) = 1;
                pbVar19 = (byte *)(local_20 + uVar23 * 4 + iVar1);
                do {
                  *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                    (uint)*pbVar19 * 0x100 >> 8);
                  pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                      (uint)pbVar19[1] * 0x100 >> 8);
                  pbVar19[2] = (byte)(((uint)param_5._2_1_ - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                      (uint)pbVar19[2] * 0x100 >> 8);
                  pbVar19 = pbVar19 + 4;
                  iVar24 = iVar24 + -1;
                } while (iVar24 != 0);
              }
              iVar24 = iVar22 + local_4c;
              if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
                  (int)local_50 < iVar6) && iVar26 <= iVar18) {
                uVar23 = iVar26;
                if (iVar26 <= (int)local_50) {
                  uVar23 = local_50;
                }
                iVar12 = iVar18;
                if (iVar6 < iVar18) {
                  iVar12 = iVar6;
                }
                iVar12 = (iVar12 - uVar23) + 1;
                *(undefined1 *)(iVar24 + iVar7) = 1;
                pbVar19 = (byte *)(local_24 + uVar23 * 4 + iVar1);
                do {
                  *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                    (uint)*pbVar19 * 0x100 >> 8);
                  pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                      (uint)pbVar19[1] * 0x100 >> 8);
                  pbVar19[2] = (byte)(((uint)param_5._2_1_ - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                      (uint)pbVar19[2] * 0x100 >> 8);
                  pbVar19 = pbVar19 + 4;
                  iVar12 = iVar12 + -1;
                } while (iVar12 != 0);
              }
              if (-1 < local_68) {
                if ((((iVar4 <= (int)local_40 && (int)local_40 < iVar10) &&
                     *(char *)(local_40 + iVar7) == '\0') && (int)local_4c < iVar6) &&
                    iVar26 <= local_58) {
                  uVar23 = local_4c;
                  if ((int)local_4c < iVar26) {
                    uVar23 = iVar26;
                  }
                  iVar18 = local_58;
                  if (iVar6 < local_58) {
                    iVar18 = iVar6;
                  }
                  *(undefined1 *)(local_40 + iVar7) = 1;
                  iVar18 = (iVar18 - uVar23) + 1;
                  pbVar19 = (byte *)(local_18 + uVar23 * 4 + iVar1);
                  do {
                    *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                      (uint)*pbVar19 * 0x100 >> 8);
                    pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                        (uint)pbVar19[1] * 0x100 >> 8);
                    pbVar19[2] = (byte)(((uint)param_5._2_1_ - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                        (uint)pbVar19[2] * 0x100 >> 8);
                    pbVar19 = pbVar19 + 4;
                    iVar18 = iVar18 + -1;
                  } while (iVar18 != 0);
                }
                iVar18 = iVar22 + local_50;
                if ((((iVar4 <= iVar18 && iVar18 < iVar10) && *(char *)(iVar18 + iVar7) == '\0') &&
                    (int)local_4c < iVar6) && iVar26 <= local_58) {
                  uVar23 = local_4c;
                  if ((int)local_4c < iVar26) {
                    uVar23 = iVar26;
                  }
                  iVar24 = local_58;
                  if (iVar6 < local_58) {
                    iVar24 = iVar6;
                  }
                  iVar24 = (iVar24 - uVar23) + 1;
                  pbVar19 = (byte *)(local_1c + uVar23 * 4 + iVar1);
                  *(undefined1 *)(iVar18 + iVar7) = 1;
                  do {
                    *pbVar19 = (byte)(((param_5 & 0xff) - (uint)*pbVar19) * DAT_00dca3f8 +
                                      (uint)*pbVar19 * 0x100 >> 8);
                    pbVar19[1] = (byte)(((uint)param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                        (uint)pbVar19[1] * 0x100 >> 8);
                    pbVar19[2] = (byte)(((uint)param_5._2_1_ - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                        (uint)pbVar19[2] * 0x100 >> 8);
                    pbVar19 = pbVar19 + 4;
                    iVar24 = iVar24 + -1;
                  } while (iVar24 != 0);
                }
                local_18 = local_18 + -iVar2;
                local_1c = local_1c + iVar2;
                local_40 = local_40 + -1;
                local_50 = local_50 + 1;
                iVar18 = local_30 + -1;
                param_4 = param_4 + -1;
                local_34 = local_34 + -4;
                local_68 = local_68 - local_34;
                local_30 = iVar18;
              }
              local_20 = local_20 + iVar2;
              local_24 = local_24 + -iVar2;
              local_54 = local_54 + 1;
              local_38 = local_38 + 4;
              local_68 = local_68 + 2 + local_38;
              param_2 = local_4c;
            } while ((int)(local_54 + (uVar17 - param_3)) <= param_4);
            FUN_0056e1d0(iVar7);
            return;
          }
        }
        break;
      }
    case 0:
      if (uVar17 == 0) {
        iVar22 = param_2 - param_4;
        iVar18 = (param_2 - uVar15) + param_4;
        if ((((iVar26 <= iVar18 && iVar4 <= param_3) && iVar22 < iVar6) && param_3 < iVar10) &&
            *(char *)(iVar7 + param_3) == '\0') {
          if (iVar22 < iVar26) {
            iVar22 = iVar26;
          }
          if (iVar6 < iVar18) {
            iVar18 = iVar6;
          }
          iVar18 = (iVar18 - iVar22) + 1;
          *(undefined1 *)(iVar7 + param_3) = 1;
          puVar21 = (uint *)(iVar2 * param_3 + iVar1 + iVar22 * 4);
          do {
            *puVar21 = param_5;
            puVar21 = puVar21 + 1;
            iVar18 = iVar18 + -1;
          } while (iVar18 != 0);
        }
      }
      if (-1 < local_68) {
        iVar18 = param_2 - uVar15;
        iVar22 = (param_3 - uVar17) + param_4;
        if ((((iVar4 <= iVar22 && iVar26 <= iVar18) && iVar22 < iVar10) &&
            *(char *)(iVar7 + iVar22) == '\0') && (int)param_2 < iVar6) {
          iVar24 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar24 = param_2;
          }
          iVar12 = iVar6;
          if (iVar18 <= iVar6) {
            iVar12 = iVar18;
          }
          *(undefined1 *)(iVar7 + iVar22) = 1;
          iVar12 = (iVar12 - iVar24) + 1;
          puVar21 = (uint *)(iVar22 * iVar2 + iVar1 + iVar24 * 4);
          do {
            *puVar21 = param_5;
            puVar21 = puVar21 + 1;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        iVar22 = param_3 - param_4;
        if ((((iVar4 <= iVar22 && iVar26 <= iVar18) && iVar22 < iVar10) &&
            *(char *)(iVar7 + iVar22) == '\0') && (int)param_2 < iVar6) {
          iVar24 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar24 = param_2;
          }
          iVar12 = iVar6;
          if (iVar18 <= iVar6) {
            iVar12 = iVar18;
          }
          *(undefined1 *)(iVar7 + iVar22) = 1;
          iVar18 = (iVar12 - iVar24) + 1;
          puVar21 = (uint *)(iVar22 * iVar2 + iVar1 + iVar24 * 4);
          do {
            *puVar21 = param_5;
            puVar21 = puVar21 + 1;
            iVar18 = iVar18 + -1;
          } while (iVar18 != 0);
        }
        param_4 = param_4 + -1;
        local_68 = local_68 + param_4 * -4;
      }
      local_68 = local_68 + 6;
      if (0 < param_4) {
        local_30 = param_4 * 4;
        local_44 = param_2 - uVar15;
        local_34 = 4;
        local_40 = (param_4 - uVar17) + param_3;
        param_8 = (uint *)(param_2 - param_4);
        local_4c = (param_4 - uVar15) + param_2;
        local_50 = (param_3 - uVar17) + 1;
        local_1c = (param_3 - param_4) * iVar2;
        local_18 = local_40 * iVar2;
        local_24 = (param_3 + -1) * iVar2;
        local_20 = local_50 * iVar2;
        iVar18 = param_3 - param_2;
        do {
          local_44 = local_44 + 1;
          param_6 = param_2 + -1;
          if ((((iVar4 <= (int)local_50 && (int)local_50 < iVar10) &&
               *(char *)(local_50 + iVar7) == '\0') && (int)param_8 < iVar6) &&
              iVar26 <= (int)local_4c) {
            iVar22 = iVar26;
            if (iVar26 <= (int)param_8) {
              iVar22 = (int)param_8;
            }
            uVar23 = local_4c;
            if (iVar6 < (int)local_4c) {
              uVar23 = iVar6;
            }
            iVar24 = (uVar23 - iVar22) + 1;
            puVar21 = (uint *)(local_20 + iVar22 * 4 + iVar1);
            *(undefined1 *)(local_50 + iVar7) = 1;
            do {
              *puVar21 = param_5;
              puVar21 = puVar21 + 1;
              iVar24 = iVar24 + -1;
            } while (iVar24 != 0);
          }
          param_1 = (int)param_8;
          iVar22 = param_6 + iVar18;
          if ((((iVar4 <= iVar22 && iVar22 < iVar10) && *(char *)(iVar22 + iVar7) == '\0') &&
              (int)param_8 < iVar6) && iVar26 <= (int)local_4c) {
            if ((int)param_8 < iVar26) {
              param_1 = iVar26;
            }
            uVar23 = local_4c;
            if (iVar6 < (int)local_4c) {
              uVar23 = iVar6;
            }
            iVar24 = (uVar23 - param_1) + 1;
            puVar21 = (uint *)(local_24 + param_1 * 4 + iVar1);
            *(undefined1 *)(iVar22 + iVar7) = 1;
            do {
              *puVar21 = param_5;
              puVar21 = puVar21 + 1;
              iVar24 = iVar24 + -1;
            } while (iVar24 != 0);
          }
          if (-1 < local_68) {
            if ((((iVar4 <= (int)local_40 && (int)local_40 < iVar10) &&
                 *(char *)(local_40 + iVar7) == '\0') && param_6 < iVar6) && iVar26 <= (int)local_44
               ) {
              iVar22 = param_6;
              if (param_6 < iVar26) {
                iVar22 = iVar26;
              }
              uVar23 = local_44;
              if (iVar6 < (int)local_44) {
                uVar23 = iVar6;
              }
              iVar24 = (uVar23 - iVar22) + 1;
              puVar21 = (uint *)(local_18 + iVar22 * 4 + iVar1);
              *(undefined1 *)(local_40 + iVar7) = 1;
              do {
                *puVar21 = param_5;
                puVar21 = puVar21 + 1;
                iVar24 = iVar24 + -1;
              } while (iVar24 != 0);
            }
            iVar22 = iVar18 + (int)param_8;
            if ((((iVar4 <= iVar22 && iVar22 < iVar10) && *(char *)(iVar22 + iVar7) == '\0') &&
                param_6 < iVar6) && iVar26 <= (int)local_44) {
              iVar24 = param_6;
              if (param_6 < iVar26) {
                iVar24 = iVar26;
              }
              uVar23 = local_44;
              if (iVar6 < (int)local_44) {
                uVar23 = iVar6;
              }
              iVar12 = (uVar23 - iVar24) + 1;
              puVar21 = (uint *)(local_1c + iVar24 * 4 + iVar1);
              *(undefined1 *)(iVar22 + iVar7) = 1;
              do {
                *puVar21 = param_5;
                puVar21 = puVar21 + 1;
                iVar12 = iVar12 + -1;
              } while (iVar12 != 0);
            }
            local_18 = local_18 + -iVar2;
            local_1c = local_1c + iVar2;
            local_4c = local_4c + -1;
            local_40 = local_40 + -1;
            param_8 = (uint *)((int)param_8 + 1);
            param_4 = param_4 + -1;
            local_30 = local_30 + -4;
            local_68 = local_68 - local_30;
          }
          local_20 = local_20 + iVar2;
          local_24 = local_24 + -iVar2;
          local_50 = local_50 + 1;
          local_34 = local_34 + 4;
          local_68 = local_68 + 2 + local_34;
          param_2 = param_6;
        } while ((int)(local_50 + (uVar17 - param_3)) <= param_4);
        FUN_0056e1d0(iVar7);
        return;
      }
      break;
    case 2:
      if (DAT_00dca3f8 != 0) {
        if (uVar17 == 0) {
          param_1 = param_2 - param_4;
          iVar22 = (param_2 - uVar15) + param_4;
          if ((((iVar26 <= iVar22 && iVar4 <= param_3) && param_1 < iVar6) && param_3 < iVar10) &&
              *(char *)(iVar7 + param_3) == '\0') {
            if (param_1 < iVar26) {
              param_1 = iVar26;
            }
            if (iVar6 < iVar22) {
              iVar22 = iVar6;
            }
            *(undefined1 *)(iVar7 + param_3) = 1;
            iVar24 = param_1 * 4;
            param_1 = (iVar22 - param_1) + 1;
            param_8 = (uint *)(iVar2 * param_3 + iVar1 + iVar24);
            do {
              local_5c._0_2_ =
                   CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                            *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
              local_5c._0_3_ =
                   CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                            (undefined2)local_5c);
              uVar5 = (uint3)local_5c;
              local_5c = (uint)(uint3)local_5c;
              uVar23 = (uVar5 & 0xfefeff) + (*param_8 & 0xfefeff);
              uVar8 = uVar23 & 0x1010100;
              param_1 = param_1 + -1;
              *param_8 = uVar8 - (uVar8 >> 8) | (local_5c | *param_8) & 0x10100 | uVar23;
              param_8 = param_8 + 1;
            } while (param_1 != 0);
          }
        }
        if (-1 < local_68) {
          iVar22 = param_2 - uVar15;
          iVar24 = (param_3 - uVar17) + param_4;
          if ((((iVar4 <= iVar24 && iVar26 <= iVar22) && iVar24 < iVar10) &&
              *(char *)(iVar24 + iVar7) == '\0') && (int)param_2 < iVar6) {
            iVar12 = iVar26;
            if (iVar26 <= (int)param_2) {
              iVar12 = param_2;
            }
            iVar11 = iVar22;
            if (iVar6 < iVar22) {
              iVar11 = iVar6;
            }
            *(undefined1 *)(iVar24 + iVar7) = 1;
            param_1 = (iVar11 - iVar12) + 1;
            param_8 = (uint *)(iVar24 * iVar2 + iVar1 + iVar12 * 4);
            do {
              local_5c._0_2_ =
                   CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                            *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
              local_5c._0_3_ =
                   CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                            (undefined2)local_5c);
              uVar5 = (uint3)local_5c;
              local_5c = (uint)(uint3)local_5c;
              uVar8 = (uVar5 & 0xfefeff) + (*param_8 & 0xfefeff);
              uVar23 = uVar8 & 0x1010100;
              *param_8 = uVar23 - (uVar23 >> 8) | (local_5c | *param_8) & 0x10100 | uVar8;
              param_8 = param_8 + 1;
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          iVar24 = param_3 - param_4;
          if ((((iVar4 <= iVar24 && iVar26 <= iVar22) && iVar24 < iVar10) &&
              *(char *)(iVar24 + iVar7) == '\0') && (int)param_2 < iVar6) {
            iVar12 = iVar26;
            if (iVar26 <= (int)param_2) {
              iVar12 = param_2;
            }
            if (iVar6 < iVar22) {
              iVar22 = iVar6;
            }
            *(undefined1 *)(iVar24 + iVar7) = 1;
            param_1 = (iVar22 - iVar12) + 1;
            param_8 = (uint *)(iVar24 * iVar2 + iVar1 + iVar12 * 4);
            do {
              local_5c._0_2_ =
                   CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                            *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
              local_5c._0_3_ =
                   CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                            (undefined2)local_5c);
              uVar5 = (uint3)local_5c;
              local_5c = (uint)(uint3)local_5c;
              uVar8 = (uVar5 & 0xfefeff) + (*param_8 & 0xfefeff);
              uVar23 = uVar8 & 0x1010100;
              *param_8 = uVar23 - (uVar23 >> 8) | (local_5c | *param_8) & 0x10100 | uVar8;
              param_8 = param_8 + 1;
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          param_4 = param_4 + -1;
          local_68 = local_68 + param_4 * -4;
        }
        local_68 = local_68 + 6;
        if (0 < param_4) {
          local_30 = param_4 * 4;
          local_40 = param_2 - uVar15;
          local_38 = 4;
          local_3c = (param_4 - uVar17) + param_3;
          local_58 = param_2 - param_4;
          local_60 = (param_4 - uVar15) + param_2;
          local_1c = (param_3 - param_4) * iVar2;
          local_18 = local_3c * iVar2;
          local_24 = (param_3 + -1) * iVar2;
          local_34 = (param_3 - uVar17) + 1;
          local_20 = local_34 * iVar2;
          iVar22 = param_3 - param_2;
          do {
            local_40 = local_40 + 1;
            local_44 = param_2 + -1;
            if ((((iVar4 <= (int)local_34 && (int)local_34 < iVar10) &&
                 *(char *)(local_34 + iVar7) == '\0') && local_58 < iVar6) &&
                iVar26 <= (int)local_60) {
              iVar24 = iVar26;
              if (iVar26 <= local_58) {
                iVar24 = local_58;
              }
              uVar23 = iVar6;
              if ((int)local_60 <= iVar6) {
                uVar23 = local_60;
              }
              *(undefined1 *)(local_34 + iVar7) = 1;
              param_1 = (uVar23 - iVar24) + 1;
              param_8 = (uint *)(local_20 + iVar24 * 4 + iVar1);
              do {
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                              (undefined2)local_5c);
                uVar5 = (uint3)local_5c;
                local_5c = (uint)(uint3)local_5c;
                uVar15 = (uVar5 & 0xfefeff) + (*param_8 & 0xfefeff);
                uVar23 = uVar15 & 0x1010100;
                *param_8 = uVar23 - (uVar23 >> 8) | (local_5c | *param_8) & 0x10100 | uVar15;
                param_8 = param_8 + 1;
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            iVar24 = local_44 + iVar22;
            if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
                local_58 < iVar6) && iVar26 <= (int)local_60) {
              iVar12 = iVar26;
              if (iVar26 <= local_58) {
                iVar12 = local_58;
              }
              uVar23 = iVar6;
              if ((int)local_60 <= iVar6) {
                uVar23 = local_60;
              }
              param_1 = (uVar23 - iVar12) + 1;
              param_8 = (uint *)(local_24 + iVar12 * 4 + iVar1);
              *(undefined1 *)(iVar24 + iVar7) = 1;
              do {
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                              (undefined2)local_5c);
                uVar5 = (uint3)local_5c;
                local_5c = (uint)(uint3)local_5c;
                uVar15 = (uVar5 & 0xfefeff) + (*param_8 & 0xfefeff);
                uVar23 = uVar15 & 0x1010100;
                *param_8 = uVar23 - (uVar23 >> 8) | (local_5c | *param_8) & 0x10100 | uVar15;
                param_8 = param_8 + 1;
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            if (-1 < local_68) {
              if ((((iVar4 <= (int)local_3c && (int)local_3c < iVar10) &&
                   *(char *)(local_3c + iVar7) == '\0') && (int)local_44 < iVar6) &&
                  iVar26 <= (int)local_40) {
                uVar23 = iVar26;
                if (iVar26 <= (int)local_44) {
                  uVar23 = local_44;
                }
                uVar15 = iVar6;
                if ((int)local_40 <= iVar6) {
                  uVar15 = local_40;
                }
                param_1 = (uVar15 - uVar23) + 1;
                param_8 = (uint *)(local_18 + uVar23 * 4 + iVar1);
                *(undefined1 *)(local_3c + iVar7) = 1;
                do {
                  local_5c._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                                *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                  local_5c._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                                (undefined2)local_5c);
                  uVar5 = (uint3)local_5c;
                  local_5c = (uint)(uint3)local_5c;
                  uVar15 = (uVar5 & 0xfefeff) + (*param_8 & 0xfefeff);
                  uVar23 = uVar15 & 0x1010100;
                  *param_8 = uVar23 - (uVar23 >> 8) | (local_5c | *param_8) & 0x10100 | uVar15;
                  param_8 = param_8 + 1;
                  param_1 = param_1 + -1;
                } while (param_1 != 0);
              }
              iVar24 = local_58 + iVar22;
              if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
                  (int)local_44 < iVar6) && iVar26 <= (int)local_40) {
                uVar23 = iVar26;
                if (iVar26 <= (int)local_44) {
                  uVar23 = local_44;
                }
                uVar15 = iVar6;
                if ((int)local_40 <= iVar6) {
                  uVar15 = local_40;
                }
                param_1 = (uVar15 - uVar23) + 1;
                param_8 = (uint *)(local_1c + uVar23 * 4 + iVar1);
                *(undefined1 *)(iVar24 + iVar7) = 1;
                do {
                  local_5c._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                                *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                  local_5c._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                                (undefined2)local_5c);
                  uVar5 = (uint3)local_5c;
                  local_5c = (uint)(uint3)local_5c;
                  uVar15 = (uVar5 & 0xfefeff) + (*param_8 & 0xfefeff);
                  uVar23 = uVar15 & 0x1010100;
                  *param_8 = uVar23 - (uVar23 >> 8) | (local_5c | *param_8) & 0x10100 | uVar15;
                  param_8 = param_8 + 1;
                  param_1 = param_1 + -1;
                } while (param_1 != 0);
              }
              local_1c = local_1c + iVar2;
              local_18 = local_18 + -iVar2;
              local_60 = local_60 + -1;
              local_3c = local_3c + -1;
              local_58 = local_58 + 1;
              local_30 = local_30 + -4;
              param_4 = param_4 + -1;
              local_68 = local_68 - local_30;
            }
            local_20 = local_20 + iVar2;
            local_34 = local_34 + 1;
            local_24 = local_24 + -iVar2;
            local_38 = local_38 + 4;
            local_68 = local_68 + 2 + local_38;
            param_2 = local_44;
          } while ((int)((uVar17 - param_3) + local_34) <= param_4);
          FUN_0056e1d0(iVar7);
          return;
        }
      }
      break;
    case 3:
      if (DAT_00dca3f8 != 0) {
        if (uVar17 == 0) {
          iVar22 = (param_2 - uVar15) + param_4;
          param_1 = param_2 - param_4;
          if ((((iVar26 <= iVar22 && iVar4 <= param_3) && param_1 < iVar6) && param_3 < iVar10) &&
              *(char *)(iVar7 + param_3) == '\0') {
            if (param_1 < iVar26) {
              param_1 = iVar26;
            }
            if (iVar6 < iVar22) {
              iVar22 = iVar6;
            }
            *(undefined1 *)(iVar7 + param_3) = 1;
            param_8 = (uint *)(iVar2 * param_3 + iVar1 + param_1 * 4);
            param_1 = (iVar22 - param_1) + 1;
            do {
              uVar23 = local_5c;
              local_5c._0_2_ =
                   CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                            *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
              local_5c._3_1_ = SUB41(uVar23,3);
              local_5c._0_3_ =
                   CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                            (undefined2)local_5c);
              uVar23 = (*param_8 | 0x1010100) - (local_5c & 0xfefefeff);
              uVar8 = uVar23 & 0x1010100;
              *param_8 = uVar8 - (uVar8 >> 8) & uVar23;
              param_8 = param_8 + 1;
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
        }
        if (-1 < local_68) {
          iVar22 = param_2 - uVar15;
          iVar24 = (param_3 - uVar17) + param_4;
          if ((((iVar4 <= iVar24 && iVar26 <= iVar22) && iVar24 < iVar10) &&
              *(char *)(iVar24 + iVar7) == '\0') && (int)param_2 < iVar6) {
            iVar12 = iVar26;
            if (iVar26 <= (int)param_2) {
              iVar12 = param_2;
            }
            iVar11 = iVar22;
            if (iVar6 < iVar22) {
              iVar11 = iVar6;
            }
            *(undefined1 *)(iVar24 + iVar7) = 1;
            param_1 = (iVar11 - iVar12) + 1;
            puVar21 = (uint *)(iVar24 * iVar2 + iVar1 + iVar12 * 4);
            do {
              uVar23 = local_5c;
              local_5c._0_2_ =
                   CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                            *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
              local_5c._3_1_ = SUB41(uVar23,3);
              local_5c._0_3_ =
                   CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                            (undefined2)local_5c);
              uVar8 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
              uVar23 = uVar8 & 0x1010100;
              *puVar21 = uVar23 - (uVar23 >> 8) & uVar8;
              puVar21 = puVar21 + 1;
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          iVar24 = param_3 - param_4;
          if ((((iVar4 <= iVar24 && iVar26 <= iVar22) && iVar24 < iVar10) &&
              *(char *)(iVar24 + iVar7) == '\0') && (int)param_2 < iVar6) {
            iVar12 = iVar26;
            if (iVar26 <= (int)param_2) {
              iVar12 = param_2;
            }
            iVar11 = iVar6;
            if (iVar22 <= iVar6) {
              iVar11 = iVar22;
            }
            param_1 = (iVar11 - iVar12) + 1;
            *(undefined1 *)(iVar24 + iVar7) = 1;
            param_8 = (uint *)(iVar24 * iVar2 + iVar1 + iVar12 * 4);
            do {
              uVar23 = local_5c;
              local_5c._0_2_ =
                   CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                            *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
              local_5c._3_1_ = SUB41(uVar23,3);
              local_5c._0_3_ =
                   CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                            (undefined2)local_5c);
              uVar8 = (*param_8 | 0x1010100) - (local_5c & 0xfefefeff);
              uVar23 = uVar8 & 0x1010100;
              *param_8 = uVar23 - (uVar23 >> 8) & uVar8;
              param_8 = param_8 + 1;
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          param_4 = param_4 + -1;
          local_68 = local_68 + param_4 * -4;
        }
        local_68 = local_68 + 6;
        if (0 < param_4) {
          local_30 = param_4 * 4;
          local_40 = param_2 - uVar15;
          local_34 = 4;
          local_3c = (param_4 - uVar17) + param_3;
          local_54 = param_2 - param_4;
          local_44 = (param_4 - uVar15) + param_2;
          local_60 = (param_3 - uVar17) + 1;
          local_1c = (param_3 - param_4) * iVar2;
          local_18 = local_3c * iVar2;
          local_24 = (param_3 + -1) * iVar2;
          local_20 = local_60 * iVar2;
          iVar22 = param_3 - param_2;
          do {
            local_40 = local_40 + 1;
            local_58 = param_2 + -1;
            if ((((iVar4 <= (int)local_60 && (int)local_60 < iVar10) &&
                 *(char *)(local_60 + iVar7) == '\0') && (int)local_54 < iVar6) &&
                iVar26 <= (int)local_44) {
              uVar23 = iVar26;
              if (iVar26 <= (int)local_54) {
                uVar23 = local_54;
              }
              uVar15 = iVar6;
              if ((int)local_44 <= iVar6) {
                uVar15 = local_44;
              }
              param_1 = (uVar15 - uVar23) + 1;
              *(undefined1 *)(local_60 + iVar7) = 1;
              puVar21 = (uint *)(local_20 + uVar23 * 4 + iVar1);
              do {
                uVar23 = local_5c;
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._3_1_ = SUB41(uVar23,3);
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                              (undefined2)local_5c);
                uVar15 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                uVar23 = uVar15 & 0x1010100;
                *puVar21 = uVar23 - (uVar23 >> 8) & uVar15;
                puVar21 = puVar21 + 1;
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            iVar24 = local_58 + iVar22;
            if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
                (int)local_54 < iVar6) && iVar26 <= (int)local_44) {
              uVar23 = iVar26;
              if (iVar26 <= (int)local_54) {
                uVar23 = local_54;
              }
              uVar15 = iVar6;
              if ((int)local_44 <= iVar6) {
                uVar15 = local_44;
              }
              param_1 = (uVar15 - uVar23) + 1;
              puVar21 = (uint *)(local_24 + uVar23 * 4 + iVar1);
              *(undefined1 *)(iVar24 + iVar7) = 1;
              do {
                uVar23 = local_5c;
                local_5c._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                local_5c._3_1_ = SUB41(uVar23,3);
                local_5c._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                              (undefined2)local_5c);
                uVar15 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                uVar23 = uVar15 & 0x1010100;
                *puVar21 = uVar23 - (uVar23 >> 8) & uVar15;
                puVar21 = puVar21 + 1;
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            if (-1 < local_68) {
              if ((((iVar4 <= (int)local_3c && (int)local_3c < iVar10) &&
                   *(char *)(local_3c + iVar7) == '\0') && local_58 < iVar6) &&
                  iVar26 <= (int)local_40) {
                iVar24 = iVar26;
                if (iVar26 <= local_58) {
                  iVar24 = local_58;
                }
                uVar23 = iVar6;
                if ((int)local_40 <= iVar6) {
                  uVar23 = local_40;
                }
                param_1 = (uVar23 - iVar24) + 1;
                puVar21 = (uint *)(local_18 + iVar24 * 4 + iVar1);
                *(undefined1 *)(local_3c + iVar7) = 1;
                do {
                  uVar23 = local_5c;
                  local_5c._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                                *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                  local_5c._3_1_ = SUB41(uVar23,3);
                  local_5c._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                                (undefined2)local_5c);
                  uVar15 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                  uVar23 = uVar15 & 0x1010100;
                  *puVar21 = uVar23 - (uVar23 >> 8) & uVar15;
                  puVar21 = puVar21 + 1;
                  param_1 = param_1 + -1;
                } while (param_1 != 0);
              }
              iVar24 = local_54 + iVar22;
              if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
                  local_58 < iVar6) && iVar26 <= (int)local_40) {
                iVar12 = iVar26;
                if (iVar26 <= local_58) {
                  iVar12 = local_58;
                }
                uVar23 = iVar6;
                if ((int)local_40 <= iVar6) {
                  uVar23 = local_40;
                }
                param_1 = (uVar23 - iVar12) + 1;
                puVar21 = (uint *)(local_1c + iVar12 * 4 + iVar1);
                *(undefined1 *)(iVar24 + iVar7) = 1;
                do {
                  uVar23 = local_5c;
                  local_5c._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._1_1_),
                                *(undefined1 *)(&DAT_00d0a2e0 + iVar18 * 0x100 + (param_5 & 0xff)));
                  local_5c._3_1_ = SUB41(uVar23,3);
                  local_5c._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar18 * 0x100 + (uint)param_5._2_1_),
                                (undefined2)local_5c);
                  uVar15 = (*puVar21 | 0x1010100) - (local_5c & 0xfefefeff);
                  uVar23 = uVar15 & 0x1010100;
                  *puVar21 = uVar23 - (uVar23 >> 8) & uVar15;
                  puVar21 = puVar21 + 1;
                  param_1 = param_1 + -1;
                } while (param_1 != 0);
              }
              local_18 = local_18 + -iVar2;
              local_44 = local_44 + -1;
              local_3c = local_3c + -1;
              local_54 = local_54 + 1;
              local_1c = local_1c + iVar2;
              param_4 = param_4 + -1;
              local_30 = local_30 + -4;
              local_68 = local_68 - local_30;
            }
            local_20 = local_20 + iVar2;
            local_24 = local_24 + -iVar2;
            local_34 = local_34 + 4;
            local_68 = local_68 + 2 + local_34;
            local_60 = local_60 + 1;
            param_2 = local_58;
          } while ((int)(local_60 + (uVar17 - param_3)) <= param_4);
          FUN_0056e1d0(iVar7);
          return;
        }
      }
      break;
    case 4:
      if (uVar17 == 0) {
        iVar22 = param_2 - param_4;
        iVar18 = (param_2 - uVar15) + param_4;
        if ((((iVar26 <= iVar18 && iVar4 <= param_3) && iVar22 < iVar6) && param_3 < iVar10) &&
            *(char *)(iVar7 + param_3) == '\0') {
          if (iVar22 < iVar26) {
            iVar22 = iVar26;
          }
          if (iVar6 < iVar18) {
            iVar18 = iVar6;
          }
          param_1 = (iVar18 - iVar22) + 1;
          *(undefined1 *)(iVar7 + param_3) = 1;
          pbVar19 = (byte *)(iVar2 * param_3 + iVar1 + iVar22 * 4);
          do {
            *pbVar19 = (byte)((uint)*pbVar19 * (param_5 & 0xff) >> 8);
            pbVar19[1] = (byte)((uint)pbVar19[1] * (uint)param_5._1_1_ >> 8);
            pbVar19[2] = (byte)((uint)pbVar19[2] * (uint)param_5._2_1_ >> 8);
            pbVar19 = pbVar19 + 4;
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
      }
      if (-1 < local_68) {
        iVar18 = param_2 - uVar15;
        iVar22 = (param_3 - uVar17) + param_4;
        if ((((iVar4 <= iVar22 && iVar26 <= iVar18) && iVar22 < iVar10) &&
            *(char *)(iVar7 + iVar22) == '\0') && (int)param_2 < iVar6) {
          iVar24 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar24 = param_2;
          }
          iVar12 = iVar6;
          if (iVar18 <= iVar6) {
            iVar12 = iVar18;
          }
          *(undefined1 *)(iVar7 + iVar22) = 1;
          param_1 = (iVar12 - iVar24) + 1;
          pbVar19 = (byte *)(iVar22 * iVar2 + iVar1 + iVar24 * 4);
          do {
            *pbVar19 = (byte)((uint)*pbVar19 * (param_5 & 0xff) >> 8);
            pbVar19[1] = (byte)((uint)pbVar19[1] * (uint)param_5._1_1_ >> 8);
            pbVar19[2] = (byte)((uint)pbVar19[2] * (uint)param_5._2_1_ >> 8);
            pbVar19 = pbVar19 + 4;
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
        iVar22 = param_3 - param_4;
        if ((((iVar4 <= iVar22 && iVar26 <= iVar18) && iVar22 < iVar10) &&
            *(char *)(iVar7 + iVar22) == '\0') && (int)param_2 < iVar6) {
          iVar24 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar24 = param_2;
          }
          iVar12 = iVar6;
          if (iVar18 <= iVar6) {
            iVar12 = iVar18;
          }
          *(undefined1 *)(iVar7 + iVar22) = 1;
          param_1 = (iVar12 - iVar24) + 1;
          pbVar19 = (byte *)(iVar22 * iVar2 + iVar1 + iVar24 * 4);
          do {
            *pbVar19 = (byte)((uint)*pbVar19 * (param_5 & 0xff) >> 8);
            pbVar19[1] = (byte)((uint)pbVar19[1] * (uint)param_5._1_1_ >> 8);
            pbVar19[2] = (byte)((uint)pbVar19[2] * (uint)param_5._2_1_ >> 8);
            pbVar19 = pbVar19 + 4;
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
        param_4 = param_4 + -1;
        local_68 = local_68 + param_4 * -4;
      }
      local_68 = local_68 + 6;
      if (0 < param_4) {
        local_2c = param_4 * 4;
        local_44 = param_2 - uVar15;
        local_30 = 4;
        local_3c = (param_4 - uVar17) + param_3;
        param_8 = (uint *)(param_2 - param_4);
        local_40 = (param_4 - uVar15) + param_2;
        local_4c = (param_3 - uVar17) + 1;
        local_1c = (param_3 - param_4) * iVar2;
        local_18 = local_3c * iVar2;
        local_24 = (param_3 + -1) * iVar2;
        local_20 = local_4c * iVar2;
        iVar18 = param_3 - param_2;
        do {
          local_44 = local_44 + 1;
          param_6 = param_2 + -1;
          if ((((iVar4 <= (int)local_4c && (int)local_4c < iVar10) &&
               *(char *)(local_4c + iVar7) == '\0') && (int)param_8 < iVar6) &&
              iVar26 <= (int)local_40) {
            iVar22 = iVar26;
            if (iVar26 <= (int)param_8) {
              iVar22 = (int)param_8;
            }
            uVar23 = local_40;
            if (iVar6 < (int)local_40) {
              uVar23 = iVar6;
            }
            *(undefined1 *)(local_4c + iVar7) = 1;
            iVar24 = (uVar23 - iVar22) + 1;
            pbVar19 = (byte *)(local_20 + iVar22 * 4 + iVar1);
            do {
              *pbVar19 = (byte)((uint)*pbVar19 * (param_5 & 0xff) >> 8);
              pbVar19[1] = (byte)((uint)pbVar19[1] * (uint)param_5._1_1_ >> 8);
              pbVar19[2] = (byte)((uint)pbVar19[2] * (uint)param_5._2_1_ >> 8);
              pbVar19 = pbVar19 + 4;
              iVar24 = iVar24 + -1;
            } while (iVar24 != 0);
          }
          iVar22 = iVar18 + param_6;
          if ((((iVar4 <= iVar22 && iVar22 < iVar10) && *(char *)(iVar22 + iVar7) == '\0') &&
              (int)param_8 < iVar6) && iVar26 <= (int)local_40) {
            iVar24 = (int)param_8;
            if ((int)param_8 < iVar26) {
              iVar24 = iVar26;
            }
            uVar23 = local_40;
            if (iVar6 < (int)local_40) {
              uVar23 = iVar6;
            }
            *(undefined1 *)(iVar22 + iVar7) = 1;
            iVar22 = (uVar23 - iVar24) + 1;
            pbVar19 = (byte *)(local_24 + iVar24 * 4 + iVar1);
            do {
              *pbVar19 = (byte)((uint)*pbVar19 * (param_5 & 0xff) >> 8);
              pbVar19[1] = (byte)((uint)pbVar19[1] * (uint)param_5._1_1_ >> 8);
              pbVar19[2] = (byte)((uint)pbVar19[2] * (uint)param_5._2_1_ >> 8);
              pbVar19 = pbVar19 + 4;
              iVar22 = iVar22 + -1;
            } while (iVar22 != 0);
          }
          if (-1 < local_68) {
            if ((((iVar4 <= (int)local_3c && (int)local_3c < iVar10) &&
                 *(char *)(local_3c + iVar7) == '\0') && param_6 < iVar6) && iVar26 <= (int)local_44
               ) {
              iVar22 = param_6;
              if (param_6 < iVar26) {
                iVar22 = iVar26;
              }
              uVar23 = local_44;
              if (iVar6 < (int)local_44) {
                uVar23 = iVar6;
              }
              *(undefined1 *)(local_3c + iVar7) = 1;
              iVar24 = (uVar23 - iVar22) + 1;
              pbVar19 = (byte *)(local_18 + iVar22 * 4 + iVar1);
              do {
                *pbVar19 = (byte)((uint)*pbVar19 * (param_5 & 0xff) >> 8);
                pbVar19[1] = (byte)((uint)pbVar19[1] * (uint)param_5._1_1_ >> 8);
                pbVar19[2] = (byte)((uint)pbVar19[2] * (uint)param_5._2_1_ >> 8);
                pbVar19 = pbVar19 + 4;
                iVar24 = iVar24 + -1;
              } while (iVar24 != 0);
            }
            iVar22 = iVar18 + (int)param_8;
            if ((((iVar4 <= iVar22 && iVar22 < iVar10) && *(char *)(iVar22 + iVar7) == '\0') &&
                param_6 < iVar6) && iVar26 <= (int)local_44) {
              iVar24 = param_6;
              if (param_6 < iVar26) {
                iVar24 = iVar26;
              }
              uVar23 = local_44;
              if (iVar6 < (int)local_44) {
                uVar23 = iVar6;
              }
              *(undefined1 *)(iVar22 + iVar7) = 1;
              iVar22 = (uVar23 - iVar24) + 1;
              pbVar19 = (byte *)(local_1c + iVar24 * 4 + iVar1);
              do {
                *pbVar19 = (byte)((uint)*pbVar19 * (param_5 & 0xff) >> 8);
                pbVar19[1] = (byte)((uint)pbVar19[1] * (uint)param_5._1_1_ >> 8);
                pbVar19[2] = (byte)((uint)pbVar19[2] * (uint)param_5._2_1_ >> 8);
                pbVar19 = pbVar19 + 4;
                iVar22 = iVar22 + -1;
              } while (iVar22 != 0);
            }
            local_18 = local_18 + -iVar2;
            local_1c = local_1c + iVar2;
            local_40 = local_40 + -1;
            local_3c = local_3c + -1;
            param_8 = (uint *)((int)param_8 + 1);
            local_2c = local_2c + -4;
            param_4 = param_4 + -1;
            local_68 = local_68 - local_2c;
          }
          local_20 = local_20 + iVar2;
          local_24 = local_24 + -iVar2;
          local_30 = local_30 + 4;
          local_68 = local_68 + 2 + local_30;
          local_4c = local_4c + 1;
          param_2 = param_6;
        } while ((int)(local_4c + (uVar17 - param_3)) <= param_4);
        FUN_0056e1d0(iVar7);
        return;
      }
      break;
    case 10:
      if (uVar17 == 0) {
        iVar18 = (param_2 - uVar15) + param_4;
        iVar22 = param_2 - param_4;
        if ((((iVar26 <= iVar18 && iVar4 <= param_3) && iVar22 < iVar6) && param_3 < iVar10) &&
            *(char *)(iVar7 + param_3) == '\0') {
          if (iVar22 < iVar26) {
            iVar22 = iVar26;
          }
          if (iVar6 < iVar18) {
            iVar18 = iVar6;
          }
          iVar18 = (iVar18 - iVar22) + 1;
          *(undefined1 *)(iVar7 + param_3) = 1;
          pbVar19 = (byte *)(iVar2 * param_3 + iVar1 + iVar22 * 4);
          do {
            *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                              (uint)*pbVar19 * 0x100 >> 8);
            pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                (uint)pbVar19[1] * 0x100 >> 8);
            pbVar19[2] = (byte)(((uint)(byte)~param_5._2_1_ - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                (uint)pbVar19[2] * 0x100 >> 8);
            pbVar19 = pbVar19 + 4;
            iVar18 = iVar18 + -1;
          } while (iVar18 != 0);
        }
      }
      if (-1 < local_68) {
        iVar18 = param_2 - uVar15;
        iVar22 = (param_3 - uVar17) + param_4;
        if ((((iVar4 <= iVar22 && iVar26 <= iVar18) && iVar22 < iVar10) &&
            *(char *)(iVar7 + iVar22) == '\0') && (int)param_2 < iVar6) {
          iVar24 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar24 = param_2;
          }
          iVar12 = iVar18;
          if (iVar6 < iVar18) {
            iVar12 = iVar6;
          }
          *(undefined1 *)(iVar7 + iVar22) = 1;
          iVar12 = (iVar12 - iVar24) + 1;
          pbVar19 = (byte *)(iVar22 * iVar2 + iVar1 + iVar24 * 4);
          do {
            *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                              (uint)*pbVar19 * 0x100 >> 8);
            pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                (uint)pbVar19[1] * 0x100 >> 8);
            pbVar19[2] = (byte)(((uint)(byte)~param_5._2_1_ - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                (uint)pbVar19[2] * 0x100 >> 8);
            pbVar19 = pbVar19 + 4;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        iVar22 = param_3 - param_4;
        if ((((iVar4 <= iVar22 && iVar26 <= iVar18) && iVar22 < iVar10) &&
            *(char *)(iVar7 + iVar22) == '\0') && (int)param_2 < iVar6) {
          iVar24 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar24 = param_2;
          }
          if (iVar6 < iVar18) {
            iVar18 = iVar6;
          }
          *(undefined1 *)(iVar7 + iVar22) = 1;
          iVar18 = (iVar18 - iVar24) + 1;
          pbVar19 = (byte *)(iVar22 * iVar2 + iVar1 + iVar24 * 4);
          do {
            *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                              (uint)*pbVar19 * 0x100 >> 8);
            pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                (uint)pbVar19[1] * 0x100 >> 8);
            pbVar19[2] = (byte)(((uint)(byte)~param_5._2_1_ - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                (uint)pbVar19[2] * 0x100 >> 8);
            pbVar19 = pbVar19 + 4;
            iVar18 = iVar18 + -1;
          } while (iVar18 != 0);
        }
        param_4 = param_4 + -1;
        local_68 = local_68 + param_4 * -4;
      }
      local_68 = local_68 + 6;
      if (0 < param_4) {
        local_50 = param_2 - uVar15;
        local_34 = param_4 * 4;
        local_44 = param_2 - param_4;
        local_40 = (param_3 - uVar17) + 1;
        local_1c = (param_3 - param_4) * iVar2;
        local_3c = (param_4 - uVar17) + param_3;
        local_18 = local_3c * iVar2;
        local_24 = (param_3 + -1) * iVar2;
        local_20 = local_40 * iVar2;
        iVar18 = (param_4 - uVar15) + param_2;
        iVar22 = param_3 - param_2;
        local_38 = 4;
        local_30 = iVar18;
        do {
          local_4c = param_2 + -1;
          local_50 = local_50 + 1;
          if ((((iVar4 <= (int)local_40 && (int)local_40 < iVar10) &&
               *(char *)(local_40 + iVar7) == '\0') && (int)local_44 < iVar6) && iVar26 <= iVar18) {
            uVar23 = iVar26;
            if (iVar26 <= (int)local_44) {
              uVar23 = local_44;
            }
            iVar24 = iVar18;
            if (iVar6 < iVar18) {
              iVar24 = iVar6;
            }
            iVar24 = (iVar24 - uVar23) + 1;
            *(undefined1 *)(local_40 + iVar7) = 1;
            pbVar19 = (byte *)(local_20 + uVar23 * 4 + iVar1);
            do {
              *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)(((uint)(byte)~param_5._2_1_ - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                  (uint)pbVar19[2] * 0x100 >> 8);
              pbVar19 = pbVar19 + 4;
              iVar24 = iVar24 + -1;
            } while (iVar24 != 0);
          }
          iVar24 = iVar22 + local_4c;
          if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
              (int)local_44 < iVar6) && iVar26 <= iVar18) {
            uVar23 = iVar26;
            if (iVar26 <= (int)local_44) {
              uVar23 = local_44;
            }
            iVar12 = iVar18;
            if (iVar6 < iVar18) {
              iVar12 = iVar6;
            }
            iVar12 = (iVar12 - uVar23) + 1;
            *(undefined1 *)(iVar24 + iVar7) = 1;
            pbVar19 = (byte *)(local_24 + uVar23 * 4 + iVar1);
            do {
              *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                                (uint)*pbVar19 * 0x100 >> 8);
              pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                  (uint)pbVar19[1] * 0x100 >> 8);
              pbVar19[2] = (byte)(((uint)(byte)~param_5._2_1_ - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                  (uint)pbVar19[2] * 0x100 >> 8);
              pbVar19 = pbVar19 + 4;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
          }
          if (-1 < local_68) {
            if ((((iVar4 <= (int)local_3c && (int)local_3c < iVar10) &&
                 *(char *)(local_3c + iVar7) == '\0') && (int)local_4c < iVar6) &&
                iVar26 <= (int)local_50) {
              uVar23 = local_4c;
              if ((int)local_4c < iVar26) {
                uVar23 = iVar26;
              }
              uVar15 = local_50;
              if (iVar6 < (int)local_50) {
                uVar15 = iVar6;
              }
              *(undefined1 *)(local_3c + iVar7) = 1;
              iVar18 = (uVar15 - uVar23) + 1;
              pbVar19 = (byte *)(local_18 + uVar23 * 4 + iVar1);
              do {
                *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                                  (uint)*pbVar19 * 0x100 >> 8);
                pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                    (uint)pbVar19[1] * 0x100 >> 8);
                pbVar19[2] = (byte)(((uint)(byte)~param_5._2_1_ - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                    (uint)pbVar19[2] * 0x100 >> 8);
                pbVar19 = pbVar19 + 4;
                iVar18 = iVar18 + -1;
              } while (iVar18 != 0);
            }
            iVar18 = iVar22 + local_44;
            if ((((iVar4 <= iVar18 && iVar18 < iVar10) && *(char *)(iVar18 + iVar7) == '\0') &&
                (int)local_4c < iVar6) && iVar26 <= (int)local_50) {
              uVar23 = local_4c;
              if ((int)local_4c < iVar26) {
                uVar23 = iVar26;
              }
              uVar15 = local_50;
              if (iVar6 < (int)local_50) {
                uVar15 = iVar6;
              }
              iVar24 = (uVar15 - uVar23) + 1;
              *(undefined1 *)(iVar18 + iVar7) = 1;
              pbVar19 = (byte *)(local_1c + uVar23 * 4 + iVar1);
              do {
                *pbVar19 = (byte)(((uint)(byte)~(byte)param_5 - (uint)*pbVar19) * DAT_00dca3f8 +
                                  (uint)*pbVar19 * 0x100 >> 8);
                pbVar19[1] = (byte)(((uint)(byte)~param_5._1_1_ - (uint)pbVar19[1]) * DAT_00dca3f8 +
                                    (uint)pbVar19[1] * 0x100 >> 8);
                pbVar19[2] = (byte)(((uint)(byte)~param_5._2_1_ - (uint)pbVar19[2]) * DAT_00dca3f8 +
                                    (uint)pbVar19[2] * 0x100 >> 8);
                pbVar19 = pbVar19 + 4;
                iVar24 = iVar24 + -1;
              } while (iVar24 != 0);
            }
            local_18 = local_18 + -iVar2;
            local_1c = local_1c + iVar2;
            local_3c = local_3c + -1;
            local_44 = local_44 + 1;
            iVar18 = local_30 + -1;
            param_4 = param_4 + -1;
            local_34 = local_34 + -4;
            local_68 = local_68 - local_34;
            local_30 = iVar18;
          }
          local_20 = local_20 + iVar2;
          local_24 = local_24 + -iVar2;
          local_40 = local_40 + 1;
          local_38 = local_38 + 4;
          local_68 = local_68 + 2 + local_38;
          param_2 = local_4c;
        } while ((int)(local_40 + (uVar17 - param_3)) <= param_4);
        FUN_0056e1d0(iVar7);
        return;
      }
      break;
    case 0xb:
      if (uVar17 == 0) {
        iVar18 = (param_2 - uVar15) + param_4;
        iVar22 = param_2 - param_4;
        if ((((iVar26 <= iVar18 && iVar4 <= param_3) && iVar22 < iVar6) && param_3 < iVar10) &&
            *(char *)(iVar7 + param_3) == '\0') {
          if (iVar22 < iVar26) {
            iVar22 = iVar26;
          }
          if (iVar6 < iVar18) {
            iVar18 = iVar6;
          }
          param_1 = (iVar18 - iVar22) + 1;
          *(undefined1 *)(iVar7 + param_3) = 1;
          pbVar19 = (byte *)(iVar2 * param_3 + iVar1 + iVar22 * 4);
          do {
            uVar23 = (uint)*pbVar19;
            *pbVar19 = (byte)((((int)(uVar23 * (param_5 & 0xff)) >> 8) - uVar23) * DAT_00dca3f8 +
                              uVar23 * 0x100 >> 8);
            uVar23 = (uint)pbVar19[1];
            pbVar19[1] = (byte)((((int)(uVar23 * param_5._1_1_) >> 8) - uVar23) * DAT_00dca3f8 +
                                uVar23 * 0x100 >> 8);
            uVar23 = (uint)pbVar19[2];
            pbVar19[2] = (byte)((((int)(uVar23 * param_5._2_1_) >> 8) - uVar23) * DAT_00dca3f8 +
                                uVar23 * 0x100 >> 8);
            pbVar19 = pbVar19 + 4;
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
      }
      if (-1 < local_68) {
        iVar18 = param_2 - uVar15;
        iVar22 = (param_3 - uVar17) + param_4;
        if ((((iVar4 <= iVar22 && iVar26 <= iVar18) && iVar22 < iVar10) &&
            *(char *)(iVar7 + iVar22) == '\0') && (int)param_2 < iVar6) {
          iVar24 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar24 = param_2;
          }
          iVar12 = iVar18;
          if (iVar6 < iVar18) {
            iVar12 = iVar6;
          }
          *(undefined1 *)(iVar7 + iVar22) = 1;
          param_1 = (iVar12 - iVar24) + 1;
          pbVar19 = (byte *)(iVar22 * iVar2 + iVar1 + iVar24 * 4);
          do {
            uVar23 = (uint)*pbVar19;
            *pbVar19 = (byte)((((int)(uVar23 * (param_5 & 0xff)) >> 8) - uVar23) * DAT_00dca3f8 +
                              uVar23 * 0x100 >> 8);
            uVar23 = (uint)pbVar19[1];
            pbVar19[1] = (byte)((((int)(uVar23 * param_5._1_1_) >> 8) - uVar23) * DAT_00dca3f8 +
                                uVar23 * 0x100 >> 8);
            uVar23 = (uint)pbVar19[2];
            pbVar19[2] = (byte)((((int)(uVar23 * param_5._2_1_) >> 8) - uVar23) * DAT_00dca3f8 +
                                uVar23 * 0x100 >> 8);
            pbVar19 = pbVar19 + 4;
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
        iVar22 = param_3 - param_4;
        if ((((iVar4 <= iVar22 && iVar26 <= iVar18) && iVar22 < iVar10) &&
            *(char *)(iVar7 + iVar22) == '\0') && (int)param_2 < iVar6) {
          iVar24 = iVar26;
          if (iVar26 <= (int)param_2) {
            iVar24 = param_2;
          }
          if (iVar6 < iVar18) {
            iVar18 = iVar6;
          }
          *(undefined1 *)(iVar7 + iVar22) = 1;
          param_1 = (iVar18 - iVar24) + 1;
          pbVar19 = (byte *)(iVar22 * iVar2 + iVar1 + iVar24 * 4);
          do {
            uVar23 = (uint)*pbVar19;
            *pbVar19 = (byte)((((int)(uVar23 * (param_5 & 0xff)) >> 8) - uVar23) * DAT_00dca3f8 +
                              uVar23 * 0x100 >> 8);
            uVar23 = (uint)pbVar19[1];
            pbVar19[1] = (byte)((((int)(uVar23 * param_5._1_1_) >> 8) - uVar23) * DAT_00dca3f8 +
                                uVar23 * 0x100 >> 8);
            uVar23 = (uint)pbVar19[2];
            pbVar19[2] = (byte)((((int)(uVar23 * param_5._2_1_) >> 8) - uVar23) * DAT_00dca3f8 +
                                uVar23 * 0x100 >> 8);
            pbVar19 = pbVar19 + 4;
            param_1 = param_1 + -1;
          } while (param_1 != 0);
        }
        param_4 = param_4 + -1;
        local_68 = local_68 + param_4 * -4;
      }
      local_68 = local_68 + 6;
      if (0 < param_4) {
        local_34 = param_4 * 4;
        local_54 = param_2 - uVar15;
        local_3c = (param_4 - uVar17) + param_3;
        local_50 = param_2 - param_4;
        local_40 = (param_3 - uVar17) + 1;
        local_1c = (param_3 - param_4) * iVar2;
        local_18 = local_3c * iVar2;
        local_24 = (param_3 + -1) * iVar2;
        local_20 = local_40 * iVar2;
        iVar18 = (param_4 - uVar15) + param_2;
        iVar22 = param_3 - param_2;
        local_38 = 4;
        local_30 = iVar18;
        do {
          local_4c = param_2 + -1;
          local_54 = local_54 + 1;
          if ((((iVar4 <= (int)local_40 && (int)local_40 < iVar10) &&
               *(char *)(local_40 + iVar7) == '\0') && (int)local_50 < iVar6) && iVar26 <= iVar18) {
            uVar23 = iVar26;
            if (iVar26 <= (int)local_50) {
              uVar23 = local_50;
            }
            iVar24 = iVar18;
            if (iVar6 < iVar18) {
              iVar24 = iVar6;
            }
            param_1 = (iVar24 - uVar23) + 1;
            pbVar19 = (byte *)(local_20 + uVar23 * 4 + iVar1);
            *(undefined1 *)(local_40 + iVar7) = 1;
            do {
              uVar23 = (uint)*pbVar19;
              *pbVar19 = (byte)((((int)(uVar23 * (param_5 & 0xff)) >> 8) - uVar23) * DAT_00dca3f8 +
                                uVar23 * 0x100 >> 8);
              uVar23 = (uint)pbVar19[1];
              pbVar19[1] = (byte)((((int)(uVar23 * param_5._1_1_) >> 8) - uVar23) * DAT_00dca3f8 +
                                  uVar23 * 0x100 >> 8);
              uVar23 = (uint)pbVar19[2];
              pbVar19[2] = (byte)((((int)(uVar23 * param_5._2_1_) >> 8) - uVar23) * DAT_00dca3f8 +
                                  uVar23 * 0x100 >> 8);
              pbVar19 = pbVar19 + 4;
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          iVar24 = iVar22 + local_4c;
          if ((((iVar4 <= iVar24 && iVar24 < iVar10) && *(char *)(iVar24 + iVar7) == '\0') &&
              (int)local_50 < iVar6) && iVar26 <= iVar18) {
            uVar23 = iVar26;
            if (iVar26 <= (int)local_50) {
              uVar23 = local_50;
            }
            iVar12 = iVar18;
            if (iVar6 < iVar18) {
              iVar12 = iVar6;
            }
            param_1 = (iVar12 - uVar23) + 1;
            pbVar19 = (byte *)(local_24 + uVar23 * 4 + iVar1);
            *(undefined1 *)(iVar24 + iVar7) = 1;
            do {
              uVar23 = (uint)*pbVar19;
              *pbVar19 = (byte)((((int)(uVar23 * (param_5 & 0xff)) >> 8) - uVar23) * DAT_00dca3f8 +
                                uVar23 * 0x100 >> 8);
              uVar23 = (uint)pbVar19[1];
              pbVar19[1] = (byte)((((int)(uVar23 * param_5._1_1_) >> 8) - uVar23) * DAT_00dca3f8 +
                                  uVar23 * 0x100 >> 8);
              uVar23 = (uint)pbVar19[2];
              pbVar19[2] = (byte)((((int)(uVar23 * param_5._2_1_) >> 8) - uVar23) * DAT_00dca3f8 +
                                  uVar23 * 0x100 >> 8);
              pbVar19 = pbVar19 + 4;
              param_1 = param_1 + -1;
            } while (param_1 != 0);
          }
          if (-1 < local_68) {
            if ((((iVar4 <= (int)local_3c && (int)local_3c < iVar10) &&
                 *(char *)(local_3c + iVar7) == '\0') && (int)local_4c < iVar6) &&
                iVar26 <= (int)local_54) {
              uVar23 = local_4c;
              if ((int)local_4c < iVar26) {
                uVar23 = iVar26;
              }
              uVar15 = local_54;
              if (iVar6 < (int)local_54) {
                uVar15 = iVar6;
              }
              *(undefined1 *)(local_3c + iVar7) = 1;
              iVar18 = (uVar15 - uVar23) + 1;
              pbVar19 = (byte *)(local_18 + uVar23 * 4 + iVar1);
              do {
                uVar23 = (uint)*pbVar19;
                *pbVar19 = (byte)((((int)(uVar23 * (param_5 & 0xff)) >> 8) - uVar23) * DAT_00dca3f8
                                  + uVar23 * 0x100 >> 8);
                uVar23 = (uint)pbVar19[1];
                pbVar19[1] = (byte)((((int)(uVar23 * param_5._1_1_) >> 8) - uVar23) * DAT_00dca3f8 +
                                    uVar23 * 0x100 >> 8);
                uVar23 = (uint)pbVar19[2];
                pbVar19[2] = (byte)((((int)(uVar23 * param_5._2_1_) >> 8) - uVar23) * DAT_00dca3f8 +
                                    uVar23 * 0x100 >> 8);
                pbVar19 = pbVar19 + 4;
                iVar18 = iVar18 + -1;
              } while (iVar18 != 0);
            }
            iVar18 = iVar22 + local_50;
            if ((((iVar4 <= iVar18 && iVar18 < iVar10) && *(char *)(iVar18 + iVar7) == '\0') &&
                (int)local_4c < iVar6) && iVar26 <= (int)local_54) {
              uVar23 = local_4c;
              if ((int)local_4c < iVar26) {
                uVar23 = iVar26;
              }
              uVar15 = local_54;
              if (iVar6 < (int)local_54) {
                uVar15 = iVar6;
              }
              iVar24 = (uVar15 - uVar23) + 1;
              pbVar19 = (byte *)(local_1c + uVar23 * 4 + iVar1);
              *(undefined1 *)(iVar18 + iVar7) = 1;
              do {
                uVar23 = (uint)*pbVar19;
                *pbVar19 = (byte)((((int)(uVar23 * (param_5 & 0xff)) >> 8) - uVar23) * DAT_00dca3f8
                                  + uVar23 * 0x100 >> 8);
                uVar23 = (uint)pbVar19[1];
                pbVar19[1] = (byte)((((int)(uVar23 * param_5._1_1_) >> 8) - uVar23) * DAT_00dca3f8 +
                                    uVar23 * 0x100 >> 8);
                uVar23 = (uint)pbVar19[2];
                pbVar19[2] = (byte)((((int)(uVar23 * param_5._2_1_) >> 8) - uVar23) * DAT_00dca3f8 +
                                    uVar23 * 0x100 >> 8);
                pbVar19 = pbVar19 + 4;
                iVar24 = iVar24 + -1;
              } while (iVar24 != 0);
            }
            local_18 = local_18 + -iVar2;
            local_1c = local_1c + iVar2;
            local_3c = local_3c + -1;
            local_50 = local_50 + 1;
            iVar18 = local_30 + -1;
            local_34 = local_34 + -4;
            param_4 = param_4 + -1;
            local_68 = local_68 - local_34;
            local_30 = iVar18;
          }
          local_20 = local_20 + iVar2;
          local_24 = local_24 + -iVar2;
          local_40 = local_40 + 1;
          local_38 = local_38 + 4;
          local_68 = local_68 + 2 + local_38;
          param_2 = local_4c;
        } while ((int)(local_40 + (uVar17 - param_3)) <= param_4);
        FUN_0056e1d0(iVar7);
        return;
      }
    }
  }
  FUN_0056e1d0(iVar7);
  return;
}

