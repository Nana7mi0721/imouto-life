
void FUN_007748d0(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
                 int param_7,int param_8,int param_9)

{
  undefined1 *puVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint3 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  byte bVar11;
  ushort uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined2 *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  byte *pbVar24;
  int iVar25;
  ushort *puVar26;
  uint uVar27;
  ushort uVar28;
  uint *puVar29;
  uint uVar30;
  uint uVar31;
  undefined4 local_78;
  int local_74;
  int local_70;
  uint *local_68;
  uint local_5c;
  int local_58;
  int local_50;
  int local_4c;
  int local_48;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  iVar23 = DAT_00dca3f8;
  iVar5 = DAT_00dca3e8;
  iVar25 = DAT_00dca3e4;
  if (param_4 == 0 || param_5 == 0) {
    return;
  }
  iVar7 = DAT_00dca3ec + -1;
  iVar13 = DAT_00dca3f0 + -1;
  if (param_4 < 0) {
    param_4 = -param_4;
  }
  if (param_5 < 0) {
    param_5 = -param_5;
  }
  iVar20 = *(int *)(param_1 + 0xc);
  iVar8 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(iVar8 + 0xc);
  if (param_7 == 0) {
    if (param_4 < param_5) {
      iVar22 = (param_5 * param_5) / param_4;
      iVar15 = param_5 * -2;
      local_70 = iVar15 + 3;
      iVar4 = param_5 * -4;
      local_74 = iVar4 + 3;
      uVar21 = 0;
      iVar10 = 0;
      local_48 = 0;
      if (*(int *)(iVar8 + 0x20) == 0) {
        if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
          param_6 = ((param_6 >> 5 & 0x3f) * (DAT_00dca3fc >> 8 & 0xff) & 0xffffff07 |
                    (param_6 & 0x1f) * (DAT_00dca3fc & 0xff) >> 5) >> 3 |
                    (param_6 >> 8 & 0xfffff8) * (DAT_00dca3fc >> 0x10 & 0xff) & 0xfffff800;
        }
        iVar8 = 0;
        switch(DAT_00dca3f4) {
        case 1:
          if (DAT_00dca3f8 != 0xff) {
            if (DAT_00dca3f8 == 0) {
              return;
            }
            if (param_9 == 0) {
              uVar17 = param_2 - DAT_00dca3e4;
              uVar31 = iVar7 - DAT_00dca3e4;
              if ((uVar17 <= uVar31) &&
                 ((uint)((param_3 - param_5) - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
                puVar26 = (ushort *)((param_3 - param_5) * iVar2 + iVar20 + param_2 * 2);
                uVar12 = *puVar26;
                *puVar26 = ((uVar12 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                     DAT_00dca3f8 * 0x800)) * 0x20 |
                           ((uVar12 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                     DAT_00dca3f8 * 0x800)) * 0x800 |
                           (uVar12 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + DAT_00dca3f8 * 0x800
                                     );
              }
              if ((uVar17 <= uVar31) &&
                 ((uint)((param_3 + param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar26 = (ushort *)((param_3 + param_5) * iVar2 + iVar20 + param_2 * 2);
                uVar12 = *puVar26;
                *puVar26 = ((uVar12 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                     iVar23 * 0x800)) * 0x20 |
                           ((uVar12 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800
                                     )) * 0x800 |
                           (uVar12 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
              }
            }
            if (local_70 < 0) {
              local_48 = param_4;
              bVar3 = iVar22 <= param_4;
              if (bVar3) {
                local_48 = param_4 - iVar22;
              }
              uVar21 = (uint)bVar3;
              local_74 = local_74 + uVar21 * 4;
              local_70 = iVar15 + 5 + uVar21 * 4;
            }
            else {
              param_5 = param_5 + -1;
              bVar3 = true;
              if (local_74 < 0) {
                local_48 = param_4;
                if (iVar22 <= param_4) {
                  local_48 = param_4 - iVar22;
                }
                bVar3 = true;
                uVar21 = (uint)(iVar22 <= param_4);
                local_74 = (uVar21 - param_5) * 4;
                local_70 = iVar15 + 5 + local_74;
                local_74 = iVar4 + 5 + local_74;
              }
              else {
                local_70 = local_70 + param_5 * -4;
                local_74 = local_74 + param_5 * -4 + 2;
              }
            }
            if (0 < param_5) {
              local_14 = param_5 * 4;
              local_2c = ((param_5 - iVar5) - param_9) + param_3;
              local_3c = (param_2 - iVar25) - uVar21;
              local_28 = ((param_5 - param_9) + param_3) * iVar2;
              local_24 = (param_3 - iVar5) - param_5;
              local_38 = (param_2 - uVar21) * 2;
              local_20 = (param_3 - param_5) * iVar2;
              local_34 = ((uVar21 - iVar25) - param_8) + param_2;
              local_30 = ((uVar21 - param_8) + param_2) * 2;
              iVar8 = local_48;
              do {
                if (bVar3) {
                  uVar17 = iVar7 - iVar25;
                  if ((local_34 <= uVar17) && (local_24 <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_30 + local_20 + iVar20);
                    uVar12 = *puVar26;
                    *puVar26 = ((uVar12 >> 5 & 0x3f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                         iVar23 * 0x800)) * 0x20 |
                               ((uVar12 >> 0xb) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                         iVar23 * 0x800)) * 0x800 |
                               (uVar12 & 0x1f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                    iVar8 = local_48;
                  }
                  if ((local_34 <= uVar17) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_30 + local_28 + iVar20);
                    uVar12 = *puVar26;
                    *puVar26 = ((uVar12 >> 5 & 0x3f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                         iVar23 * 0x800)) * 0x20 |
                               ((uVar12 >> 0xb) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                         iVar23 * 0x800)) * 0x800 |
                               (uVar12 & 0x1f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                    iVar8 = local_48;
                  }
                  if ((local_3c <= uVar17) && (local_24 <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_20 + local_38 + iVar20);
                    uVar12 = *puVar26;
                    *puVar26 = ((uVar12 >> 5 & 0x3f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                         iVar23 * 0x800)) * 0x20 |
                               ((uVar12 >> 0xb) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                         iVar23 * 0x800)) * 0x800 |
                               (uVar12 & 0x1f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                    iVar8 = local_48;
                  }
                  if ((local_3c <= uVar17) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_38 + local_28 + iVar20);
                    uVar12 = *puVar26;
                    *puVar26 = ((uVar12 >> 5 & 0x3f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                         iVar23 * 0x800)) * 0x20 |
                               ((uVar12 >> 0xb) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                         iVar23 * 0x800)) * 0x800 |
                               (uVar12 & 0x1f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                    iVar8 = local_48;
                  }
                }
                if (local_70 < 0) {
                  local_48 = iVar8 + param_4;
                  bVar3 = iVar22 <= local_48;
                  if (bVar3) {
                    local_30 = local_30 + 2;
                    local_34 = local_34 + 1;
                    local_38 = local_38 + -2;
                    local_3c = local_3c - 1;
                    uVar21 = uVar21 + 1;
                    local_48 = local_48 - iVar22;
                  }
                  local_74 = local_74 + uVar21 * 4;
                  local_70 = local_70 + 2 + uVar21 * 4;
                  iVar8 = local_48;
                }
                else {
                  local_20 = local_20 + iVar2;
                  local_24 = local_24 + 1;
                  local_2c = local_2c - 1;
                  local_28 = local_28 - iVar2;
                  param_5 = param_5 + -1;
                  bVar3 = true;
                  if (local_74 < 0) {
                    local_48 = iVar8 + param_4;
                    local_14 = local_14 + -4;
                    if (iVar22 <= local_48) {
                      local_30 = local_30 + 2;
                      local_34 = local_34 + 1;
                      local_38 = local_38 + -2;
                      local_3c = local_3c - 1;
                      uVar21 = uVar21 + 1;
                      local_48 = local_48 - iVar22;
                    }
                    bVar3 = true;
                    iVar8 = (uVar21 - param_5) * 4;
                    local_70 = local_70 + 2 + iVar8;
                    local_74 = local_74 + 2 + iVar8;
                    iVar8 = local_48;
                  }
                  else {
                    local_14 = local_14 + -4;
                    local_70 = local_70 - local_14;
                    local_74 = local_74 + (2 - local_14);
                  }
                }
              } while (0 < param_5);
            }
            if (param_8 != 0) {
              return;
            }
            if (((param_2 - uVar21) - iVar25 <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)((param_5 + param_3) * iVar2 + iVar20 + (param_2 - uVar21) * 2);
              uVar12 = *puVar26;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800))
                         * 0x800 | (uVar12 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 +
                                             iVar23 * 0x800);
            }
            if ((uint)(iVar7 - iVar25) < (uVar21 + param_2) - iVar25) {
              return;
            }
            if ((uint)(iVar13 - iVar5) < (uint)((param_3 - param_5) - iVar5)) {
              return;
            }
            puVar26 = (ushort *)((param_3 - param_5) * iVar2 + iVar20 + (uVar21 + param_2) * 2);
            uVar12 = *puVar26;
            *puVar26 = ((uVar12 >> 5 & 0x3f) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 + iVar23 * 0x800
                                 )) * 0x20 |
                       ((uVar12 >> 0xb) +
                       *(short *)(&DAT_00d4a6e0 +
                                 ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) *
                       0x800 | (uVar12 & 0x1f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
            return;
          }
        case 0:
          if (param_9 == 0) {
            uVar31 = param_2 - DAT_00dca3e4;
            uVar17 = iVar7 - DAT_00dca3e4;
            if ((uVar31 <= uVar17) &&
               ((uint)((param_3 - param_5) - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              *(ushort *)((param_3 - param_5) * iVar2 + iVar20 + param_2 * 2) = (ushort)param_6;
            }
            if ((uVar31 <= uVar17) &&
               ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
              *(ushort *)((param_5 + param_3) * iVar2 + iVar20 + param_2 * 2) = (ushort)param_6;
            }
          }
          if (local_70 < 0) {
            bVar3 = iVar22 <= param_4;
            iVar8 = param_4;
            if (bVar3) {
              iVar8 = param_4 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_5 = param_5 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              iVar8 = param_4;
              if (iVar22 <= param_4) {
                iVar8 = param_4 - iVar22;
              }
              bVar3 = true;
              uVar21 = (uint)(iVar22 <= param_4);
              local_74 = (uVar21 - param_5) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_5 * -4;
              local_74 = local_74 + param_5 * -4 + 2;
            }
          }
          if (0 < param_5) {
            local_14 = param_5 * 4;
            local_28 = ((param_5 - iVar5) - param_9) + param_3;
            local_38 = (param_2 - iVar25) - uVar21;
            iVar23 = ((param_5 - param_9) + param_3) * iVar2;
            local_24 = (param_3 - iVar5) - param_5;
            local_34 = (param_2 - uVar21) * 2;
            local_20 = (param_3 - param_5) * iVar2;
            local_30 = ((uVar21 - iVar25) - param_8) + param_2;
            local_2c = ((uVar21 - param_8) + param_2) * 2;
            do {
              if (bVar3) {
                uVar17 = iVar7 - iVar25;
                if ((local_30 <= uVar17) && (local_24 <= (uint)(iVar13 - iVar5))) {
                  *(ushort *)(local_2c + local_20 + iVar20) = (ushort)param_6;
                }
                if ((local_30 <= uVar17) && (local_28 <= (uint)(iVar13 - iVar5))) {
                  *(ushort *)(local_2c + iVar23 + iVar20) = (ushort)param_6;
                }
                if ((local_38 <= uVar17) && (local_24 <= (uint)(iVar13 - iVar5))) {
                  *(ushort *)(local_20 + local_34 + iVar20) = (ushort)param_6;
                }
                if ((local_38 <= uVar17) && (local_28 <= (uint)(iVar13 - iVar5))) {
                  *(ushort *)(local_34 + iVar23 + iVar20) = (ushort)param_6;
                }
              }
              if (local_70 < 0) {
                iVar8 = iVar8 + param_4;
                bVar3 = iVar22 <= iVar8;
                if (bVar3) {
                  local_2c = local_2c + 2;
                  local_30 = local_30 + 1;
                  local_34 = local_34 + -2;
                  local_38 = local_38 - 1;
                  uVar21 = uVar21 + 1;
                  iVar8 = iVar8 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
              }
              else {
                iVar23 = iVar23 - iVar2;
                local_20 = local_20 + iVar2;
                param_5 = param_5 + -1;
                bVar3 = true;
                if (local_74 < 0) {
                  iVar8 = iVar8 + param_4;
                  local_14 = local_14 + -4;
                  local_24 = local_24 + 1;
                  local_28 = local_28 - 1;
                  if (iVar22 <= iVar8) {
                    local_2c = local_2c + 2;
                    local_30 = local_30 + 1;
                    local_34 = local_34 + -2;
                    local_38 = local_38 - 1;
                    uVar21 = uVar21 + 1;
                    iVar8 = iVar8 - iVar22;
                  }
                  bVar3 = true;
                  iVar15 = (uVar21 - param_5) * 4;
                  local_70 = local_70 + 2 + iVar15;
                  local_74 = local_74 + 2 + iVar15;
                }
                else {
                  local_24 = local_24 + 1;
                  local_28 = local_28 - 1;
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_5);
          }
          if (param_8 == 0) {
            if (((param_2 - uVar21) - iVar25 <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
              *(ushort *)((param_5 + param_3) * iVar2 + iVar20 + (param_2 - uVar21) * 2) =
                   (ushort)param_6;
            }
            if (((uVar21 + param_2) - iVar25 <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_3 - param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
              *(ushort *)((param_3 - param_5) * iVar2 + iVar20 + (uVar21 + param_2) * 2) =
                   (ushort)param_6;
              return;
            }
          }
          break;
        case 2:
          if (DAT_00dca3f8 != 0) {
            if (param_9 == 0) {
              uVar17 = param_2 - DAT_00dca3e4;
              uVar31 = iVar7 - DAT_00dca3e4;
              if ((uVar17 <= uVar31) &&
                 ((uint)((param_3 - param_5) - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
                puVar26 = (ushort *)((param_3 - param_5) * iVar2 + iVar20 + param_2 * 2);
                uVar28 = (*(short *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_6 >> 0xb)) * 0x40
                         + *(short *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_6 >> 5 & 0x3f)))
                         * 0x20 + *(short *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_6 & 0x1f)
                                            );
                uVar12 = *puVar26;
                uVar27 = (uVar12 & 0xf7def7df) + (uVar28 & 0xf7def7df);
                uVar30 = uVar27 & 0x8210820;
                *puVar26 = (short)uVar30 - (short)(uVar30 >> 5) | (uVar12 | uVar28) & 0x820 |
                           (ushort)uVar27;
              }
              if ((uVar17 <= uVar31) &&
                 ((uint)((param_3 + param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar26 = (ushort *)((param_3 + param_5) * iVar2 + iVar20 + param_2 * 2);
                uVar28 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                uVar12 = *puVar26;
                uVar17 = (uVar12 & 0xf7def7df) + (uVar28 & 0xf7def7df);
                uVar31 = uVar17 & 0x8210820;
                *puVar26 = (short)uVar31 - (short)(uVar31 >> 5) | (uVar12 | uVar28) & 0x820 |
                           (ushort)uVar17;
              }
            }
            iVar8 = 0;
            if (local_70 < 0) {
              bVar3 = iVar22 <= param_4;
              iVar8 = param_4;
              if (bVar3) {
                iVar8 = param_4 - iVar22;
              }
              uVar21 = (uint)bVar3;
              local_74 = local_74 + uVar21 * 4;
              local_70 = iVar15 + 5 + uVar21 * 4;
            }
            else {
              param_5 = param_5 + -1;
              bVar3 = true;
              if (local_74 < 0) {
                iVar8 = param_4;
                if (iVar22 <= param_4) {
                  iVar8 = param_4 - iVar22;
                }
                bVar3 = true;
                uVar21 = (uint)(iVar22 <= param_4);
                local_74 = (uVar21 - param_5) * 4;
                local_70 = iVar15 + 5 + local_74;
                local_74 = iVar4 + 5 + local_74;
              }
              else {
                local_70 = local_70 + param_5 * -4;
                local_74 = local_74 + param_5 * -4 + 2;
              }
            }
            if (0 < param_5) {
              local_14 = param_5 * 4;
              local_2c = ((param_5 - iVar5) - param_9) + param_3;
              local_3c = (param_2 - iVar25) - uVar21;
              local_28 = ((param_5 - param_9) + param_3) * iVar2;
              local_24 = (param_3 - iVar5) - param_5;
              local_38 = (param_2 - uVar21) * 2;
              local_20 = (param_3 - param_5) * iVar2;
              local_34 = ((uVar21 - iVar25) - param_8) + param_2;
              local_30 = ((uVar21 - param_8) + param_2) * 2;
              do {
                if (bVar3) {
                  uVar17 = iVar7 - iVar25;
                  if ((local_34 <= uVar17) && (local_24 <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_30 + local_20 + iVar20);
                    uVar28 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                             *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) *
                             0x20 + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                    uVar12 = *puVar26;
                    uVar31 = (uVar12 & 0xf7def7df) + (uVar28 & 0xf7def7df);
                    uVar27 = uVar31 & 0x8210820;
                    *puVar26 = (short)uVar27 - (short)(uVar27 >> 5) | (uVar12 | uVar28) & 0x820 |
                               (ushort)uVar31;
                  }
                  if ((local_34 <= uVar17) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_30 + local_28 + iVar20);
                    uVar28 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                             *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) *
                             0x20 + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                    uVar12 = *puVar26;
                    uVar31 = (uVar12 & 0xf7def7df) + (uVar28 & 0xf7def7df);
                    uVar27 = uVar31 & 0x8210820;
                    *puVar26 = (short)uVar27 - (short)(uVar27 >> 5) | (uVar12 | uVar28) & 0x820 |
                               (ushort)uVar31;
                  }
                  if ((local_3c <= uVar17) && (local_24 <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_20 + local_38 + iVar20);
                    uVar28 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                             *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) *
                             0x20 + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                    uVar12 = *puVar26;
                    uVar31 = (uVar12 & 0xf7def7df) + (uVar28 & 0xf7def7df);
                    uVar27 = uVar31 & 0x8210820;
                    *puVar26 = (short)uVar27 - (short)(uVar27 >> 5) | (uVar12 | uVar28) & 0x820 |
                               (ushort)uVar31;
                  }
                  if ((local_3c <= uVar17) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_38 + local_28 + iVar20);
                    uVar28 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                             *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) *
                             0x20 + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                    uVar12 = *puVar26;
                    uVar17 = (uVar12 & 0xf7def7df) + (uVar28 & 0xf7def7df);
                    uVar31 = uVar17 & 0x8210820;
                    *puVar26 = (short)uVar31 - (short)(uVar31 >> 5) | (uVar12 | uVar28) & 0x820 |
                               (ushort)uVar17;
                  }
                }
                if (local_70 < 0) {
                  iVar8 = iVar8 + param_4;
                  bVar3 = iVar22 <= iVar8;
                  if (bVar3) {
                    local_30 = local_30 + 2;
                    local_34 = local_34 + 1;
                    local_38 = local_38 + -2;
                    local_3c = local_3c - 1;
                    uVar21 = uVar21 + 1;
                    iVar8 = iVar8 - iVar22;
                  }
                  local_74 = local_74 + uVar21 * 4;
                  local_70 = local_70 + 2 + uVar21 * 4;
                }
                else {
                  local_20 = local_20 + iVar2;
                  local_24 = local_24 + 1;
                  local_2c = local_2c - 1;
                  local_28 = local_28 - iVar2;
                  param_5 = param_5 + -1;
                  bVar3 = true;
                  if (local_74 < 0) {
                    iVar8 = iVar8 + param_4;
                    local_14 = local_14 + -4;
                    if (iVar22 <= iVar8) {
                      local_30 = local_30 + 2;
                      local_34 = local_34 + 1;
                      local_38 = local_38 + -2;
                      local_3c = local_3c - 1;
                      uVar21 = uVar21 + 1;
                      iVar8 = iVar8 - iVar22;
                    }
                    bVar3 = true;
                    iVar15 = (uVar21 - param_5) * 4;
                    local_70 = local_70 + 2 + iVar15;
                    local_74 = local_74 + 2 + iVar15;
                  }
                  else {
                    local_14 = local_14 + -4;
                    local_70 = local_70 - local_14;
                    local_74 = local_74 + (2 - local_14);
                  }
                }
              } while (0 < param_5);
            }
            if (param_8 == 0) {
              if (((param_2 - uVar21) - iVar25 <= (uint)(iVar7 - iVar25)) &&
                 ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar26 = (ushort *)((param_5 + param_3) * iVar2 + iVar20 + (param_2 - uVar21) * 2);
                uVar28 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                uVar12 = *puVar26;
                uVar17 = (uVar12 & 0xf7def7df) + (uVar28 & 0xf7def7df);
                uVar31 = uVar17 & 0x8210820;
                *puVar26 = (short)uVar31 - (short)(uVar31 >> 5) | (uVar12 | uVar28) & 0x820 |
                           (ushort)uVar17;
              }
              if (((uVar21 + param_2) - iVar25 <= (uint)(iVar7 - iVar25)) &&
                 ((uint)((param_3 - param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar26 = (ushort *)((param_3 - param_5) * iVar2 + iVar20 + (uVar21 + param_2) * 2);
                uVar12 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                goto LAB_0078992c;
              }
            }
          }
          break;
        case 3:
          if (DAT_00dca3f8 != 0) {
            if (param_9 == 0) {
              uVar17 = param_2 - DAT_00dca3e4;
              uVar31 = iVar7 - DAT_00dca3e4;
              if ((uVar17 <= uVar31) &&
                 ((uint)((param_3 - param_5) - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
                puVar26 = (ushort *)((param_3 - param_5) * iVar2 + iVar20 + param_2 * 2);
                uVar30 = (*puVar26 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                              DAT_00dca3f8 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                                   *(short *)(&DAT_00d0a2e0 +
                                             DAT_00dca3f8 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20 +
                                  *(short *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_6 & 0x1f)
                                            )) & 0xf7def7df);
                uVar27 = uVar30 & 0x8210820;
                *puVar26 = (short)uVar27 - (short)(uVar27 >> 5) & (ushort)uVar30;
              }
              if ((uVar17 <= uVar31) &&
                 ((uint)((param_3 + param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar26 = (ushort *)((param_3 + param_5) * iVar2 + iVar20 + param_2 * 2);
                uVar31 = (*puVar26 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f))) &
                         0xf7def7df);
                uVar17 = uVar31 & 0x8210820;
                *puVar26 = (short)uVar17 - (short)(uVar17 >> 5) & (ushort)uVar31;
              }
            }
            iVar8 = 0;
            if (local_70 < 0) {
              bVar3 = iVar22 <= param_4;
              iVar8 = param_4;
              if (bVar3) {
                iVar8 = param_4 - iVar22;
              }
              uVar21 = (uint)bVar3;
              local_74 = local_74 + uVar21 * 4;
              local_70 = iVar15 + 5 + uVar21 * 4;
            }
            else {
              param_5 = param_5 + -1;
              bVar3 = true;
              if (local_74 < 0) {
                iVar8 = param_4;
                if (iVar22 <= param_4) {
                  iVar8 = param_4 - iVar22;
                }
                bVar3 = true;
                uVar21 = (uint)(iVar22 <= param_4);
                local_74 = (uVar21 - param_5) * 4;
                local_70 = iVar15 + 5 + local_74;
                local_74 = iVar4 + 5 + local_74;
              }
              else {
                local_70 = local_70 + param_5 * -4;
                local_74 = local_74 + param_5 * -4 + 2;
              }
            }
            if (0 < param_5) {
              local_14 = param_5 * 4;
              local_2c = ((param_5 - iVar5) - param_9) + param_3;
              local_3c = (param_2 - iVar25) - uVar21;
              local_28 = ((param_5 - param_9) + param_3) * iVar2;
              local_24 = (param_3 - iVar5) - param_5;
              local_38 = (param_2 - uVar21) * 2;
              local_20 = (param_3 - param_5) * iVar2;
              local_34 = ((uVar21 - iVar25) - param_8) + param_2;
              local_30 = ((uVar21 - param_8) + param_2) * 2;
              do {
                if (bVar3) {
                  uVar17 = iVar7 - iVar25;
                  if ((local_34 <= uVar17) && (local_24 <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_30 + local_20 + iVar20);
                    uVar31 = (*puVar26 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)
                                                  ) * 0x40 +
                                       *(short *)(&DAT_00d0a2e0 +
                                                 iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20 +
                                      *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f)))
                             & 0xf7def7df);
                    uVar27 = uVar31 & 0x8210820;
                    *puVar26 = (short)uVar27 - (short)(uVar27 >> 5) & (ushort)uVar31;
                  }
                  if ((local_34 <= uVar17) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_30 + local_28 + iVar20);
                    uVar31 = (*puVar26 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)
                                                  ) * 0x40 +
                                       *(short *)(&DAT_00d0a2e0 +
                                                 iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20 +
                                      *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f)))
                             & 0xf7def7df);
                    uVar27 = uVar31 & 0x8210820;
                    *puVar26 = (short)uVar27 - (short)(uVar27 >> 5) & (ushort)uVar31;
                  }
                  if ((local_3c <= uVar17) && (local_24 <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_20 + local_38 + iVar20);
                    uVar31 = (*puVar26 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)
                                                  ) * 0x40 +
                                       *(short *)(&DAT_00d0a2e0 +
                                                 iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20 +
                                      *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f)))
                             & 0xf7def7df);
                    uVar27 = uVar31 & 0x8210820;
                    *puVar26 = (short)uVar27 - (short)(uVar27 >> 5) & (ushort)uVar31;
                  }
                  if ((local_3c <= uVar17) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_38 + local_28 + iVar20);
                    uVar17 = (*puVar26 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)
                                                  ) * 0x40 +
                                       *(short *)(&DAT_00d0a2e0 +
                                                 iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20 +
                                      *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f)))
                             & 0xf7def7df);
                    uVar31 = uVar17 & 0x8210820;
                    *puVar26 = (short)uVar31 - (short)(uVar31 >> 5) & (ushort)uVar17;
                  }
                }
                if (local_70 < 0) {
                  iVar8 = iVar8 + param_4;
                  bVar3 = iVar22 <= iVar8;
                  if (bVar3) {
                    local_30 = local_30 + 2;
                    local_34 = local_34 + 1;
                    local_38 = local_38 + -2;
                    local_3c = local_3c - 1;
                    uVar21 = uVar21 + 1;
                    iVar8 = iVar8 - iVar22;
                  }
                  local_74 = local_74 + uVar21 * 4;
                  local_70 = local_70 + 2 + uVar21 * 4;
                }
                else {
                  local_20 = local_20 + iVar2;
                  local_24 = local_24 + 1;
                  local_2c = local_2c - 1;
                  local_28 = local_28 - iVar2;
                  param_5 = param_5 + -1;
                  bVar3 = true;
                  if (local_74 < 0) {
                    iVar8 = iVar8 + param_4;
                    local_14 = local_14 + -4;
                    if (iVar22 <= iVar8) {
                      local_30 = local_30 + 2;
                      local_34 = local_34 + 1;
                      local_38 = local_38 + -2;
                      local_3c = local_3c - 1;
                      uVar21 = uVar21 + 1;
                      iVar8 = iVar8 - iVar22;
                    }
                    bVar3 = true;
                    iVar15 = (uVar21 - param_5) * 4;
                    local_70 = local_70 + 2 + iVar15;
                    local_74 = local_74 + 2 + iVar15;
                  }
                  else {
                    local_14 = local_14 + -4;
                    local_70 = local_70 - local_14;
                    local_74 = local_74 + (2 - local_14);
                  }
                }
              } while (0 < param_5);
            }
            if (param_8 == 0) {
              if (((param_2 - uVar21) - iVar25 <= (uint)(iVar7 - iVar25)) &&
                 ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar26 = (ushort *)((param_5 + param_3) * iVar2 + iVar20 + (param_2 - uVar21) * 2);
                uVar31 = (*puVar26 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f))) &
                         0xf7def7df);
                uVar17 = uVar31 & 0x8210820;
                *puVar26 = (short)uVar17 - (short)(uVar17 >> 5) & (ushort)uVar31;
              }
              if (((uVar21 + param_2) - iVar25 <= (uint)(iVar7 - iVar25)) &&
                 ((uint)((param_3 - param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar26 = (ushort *)((param_3 - param_5) * iVar2 + iVar20 + (uVar21 + param_2) * 2);
                goto LAB_0078a0a1;
              }
            }
          }
          break;
        case 4:
          if (param_9 == 0) {
            uVar17 = param_2 - DAT_00dca3e4;
            uVar31 = iVar7 - DAT_00dca3e4;
            if ((uVar17 <= uVar31) &&
               ((uint)((param_3 - param_5) - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              puVar26 = (ushort *)((param_3 - param_5) * iVar2 + iVar20 + param_2 * 2);
              uVar27 = (uint)*puVar26;
              *puVar26 = (ushort)((uVar27 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_6 & 0xf800) * (uVar27 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar27 & 0x1f) * (param_6 & 0x1f) >> 5);
            }
            if ((uVar17 <= uVar31) &&
               ((uint)((param_3 + param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)((param_3 + param_5) * iVar2 + iVar20 + param_2 * 2);
              uVar17 = (uint)*puVar26;
              *puVar26 = (ushort)((uVar17 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_6 & 0xf800) * (uVar17 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar17 & 0x1f) * (param_6 & 0x1f) >> 5);
            }
          }
          if (local_70 < 0) {
            bVar3 = iVar22 <= param_4;
            iVar8 = param_4;
            if (bVar3) {
              iVar8 = param_4 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_5 = param_5 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              iVar8 = param_4;
              if (iVar22 <= param_4) {
                iVar8 = param_4 - iVar22;
              }
              uVar21 = (uint)(iVar22 <= param_4);
              local_74 = (uVar21 - param_5) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_5 * -4;
              local_74 = local_74 + param_5 * -4 + 2;
            }
          }
          if (0 < param_5) {
            local_14 = param_5 * 4;
            local_2c = ((param_5 - iVar5) - param_9) + param_3;
            local_3c = (param_2 - iVar25) - uVar21;
            local_28 = ((param_5 - param_9) + param_3) * iVar2;
            local_24 = (param_3 - iVar5) - param_5;
            local_38 = (param_2 - uVar21) * 2;
            local_20 = (param_3 - param_5) * iVar2;
            local_34 = ((uVar21 - iVar25) - param_8) + param_2;
            local_30 = ((uVar21 - param_8) + param_2) * 2;
            do {
              if (bVar3) {
                uVar17 = iVar7 - iVar25;
                if (local_34 <= uVar17) {
                  if (local_24 <= (uint)(iVar13 - iVar5)) {
                    puVar26 = (ushort *)(local_30 + local_20 + iVar20);
                    uVar31 = (uint)*puVar26;
                    *puVar26 = (ushort)((uVar31 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                               (ushort)((param_6 & 0xf800) * (uVar31 & 0xf800) >> 0x10) & 0xf800 |
                               (ushort)((uVar31 & 0x1f) * (param_6 & 0x1f) >> 5);
                  }
                  if ((local_34 <= uVar17) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_30 + local_28 + iVar20);
                    uVar31 = (uint)*puVar26;
                    *puVar26 = (ushort)((uVar31 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                               (ushort)((param_6 & 0xf800) * (uVar31 & 0xf800) >> 0x10) & 0xf800 |
                               (ushort)((uVar31 & 0x1f) * (param_6 & 0x1f) >> 5);
                  }
                }
                if (local_3c <= uVar17) {
                  if (local_24 <= (uint)(iVar13 - iVar5)) {
                    puVar26 = (ushort *)(local_20 + local_38 + iVar20);
                    uVar31 = (uint)*puVar26;
                    *puVar26 = (ushort)((uVar31 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                               (ushort)((param_6 & 0xf800) * (uVar31 & 0xf800) >> 0x10) & 0xf800 |
                               (ushort)((uVar31 & 0x1f) * (param_6 & 0x1f) >> 5);
                  }
                  if ((local_3c <= uVar17) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_28 + local_38 + iVar20);
                    uVar17 = (uint)*puVar26;
                    *puVar26 = (ushort)((uVar17 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                               (ushort)((param_6 & 0xf800) * (uVar17 & 0xf800) >> 0x10) & 0xf800 |
                               (ushort)((uVar17 & 0x1f) * (param_6 & 0x1f) >> 5);
                  }
                }
              }
              if (local_70 < 0) {
                iVar8 = iVar8 + param_4;
                bVar3 = iVar22 <= iVar8;
                if (bVar3) {
                  local_30 = local_30 + 2;
                  local_34 = local_34 + 1;
                  local_38 = local_38 + -2;
                  local_3c = local_3c - 1;
                  uVar21 = uVar21 + 1;
                  iVar8 = iVar8 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
              }
              else {
                local_20 = local_20 + iVar2;
                local_28 = local_28 - iVar2;
                bVar3 = true;
                local_24 = local_24 + 1;
                param_5 = param_5 + -1;
                if (local_74 < 0) {
                  iVar8 = iVar8 + param_4;
                  local_14 = local_14 + -4;
                  local_2c = local_2c - 1;
                  if (iVar22 <= iVar8) {
                    local_34 = local_34 + 1;
                    local_3c = local_3c - 1;
                    local_30 = local_30 + 2;
                    local_38 = local_38 + -2;
                    uVar21 = uVar21 + 1;
                    iVar8 = iVar8 - iVar22;
                  }
                  bVar3 = true;
                  iVar23 = (uVar21 - param_5) * 4;
                  local_70 = local_70 + 2 + iVar23;
                  local_74 = local_74 + 2 + iVar23;
                }
                else {
                  local_2c = local_2c - 1;
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_5);
          }
          if (param_8 == 0) {
            if (((param_2 - uVar21) - iVar25 <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_3 + param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)((param_3 + param_5) * iVar2 + iVar20 + (param_2 - uVar21) * 2);
              uVar17 = (uint)*puVar26;
              *puVar26 = (ushort)((uVar17 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_6 & 0xf800) * (uVar17 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar17 & 0x1f) * (param_6 & 0x1f) >> 5);
            }
            if (((uVar21 + param_2) - iVar25 <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_3 - param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)((param_3 - param_5) * iVar2 + iVar20 + (uVar21 + param_2) * 2);
              goto LAB_0078a7f0;
            }
          }
          break;
        case 10:
          if (param_9 == 0) {
            uVar17 = param_2 - DAT_00dca3e4;
            uVar31 = iVar7 - DAT_00dca3e4;
            if ((uVar17 <= uVar31) &&
               ((uint)((param_3 - param_5) - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              puVar26 = (ushort *)((param_3 - param_5) * iVar2 + iVar20 + param_2 * 2);
              uVar12 = *puVar26;
              uVar27 = ~param_6 & 0xffff;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar27 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                   DAT_00dca3f8 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar27 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                   DAT_00dca3f8 * 0x800)) * 0x800 |
                         (uVar12 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + DAT_00dca3f8 * 0x800)
              ;
            }
            if ((uVar17 <= uVar31) &&
               ((uint)((param_3 + param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)((param_3 + param_5) * iVar2 + iVar20 + param_2 * 2);
              uVar12 = *puVar26;
              uVar17 = ~param_6 & 0xffff;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar17 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar17 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800))
                         * 0x800 | (uVar12 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 +
                                             iVar23 * 0x800);
            }
          }
          if (local_70 < 0) {
            local_48 = param_4;
            bVar3 = iVar22 <= param_4;
            if (bVar3) {
              local_48 = param_4 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_5 = param_5 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              local_48 = param_4;
              if (iVar22 <= param_4) {
                local_48 = param_4 - iVar22;
              }
              bVar3 = true;
              uVar21 = (uint)(iVar22 <= param_4);
              local_74 = (uVar21 - param_5) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_5 * -4;
              local_74 = local_74 + param_5 * -4 + 2;
            }
          }
          if (0 < param_5) {
            local_14 = param_5 * 4;
            local_2c = ((param_5 - iVar5) - param_9) + param_3;
            local_40 = (param_2 - iVar25) - uVar21;
            local_28 = ((param_5 - param_9) + param_3) * iVar2;
            local_24 = (param_3 - iVar5) - param_5;
            local_3c = (param_2 - uVar21) * 2;
            local_20 = (param_3 - param_5) * iVar2;
            local_34 = ((uVar21 - iVar25) - param_8) + param_2;
            local_30 = ((uVar21 - param_8) + param_2) * 2;
            iVar8 = local_48;
            do {
              if (bVar3) {
                uVar17 = iVar7 - iVar25;
                if ((local_34 <= uVar17) && (local_24 <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_30 + local_20 + iVar20);
                  uVar12 = *puVar26;
                  uVar31 = ~param_6 & 0xffff;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar31 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar31 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                       iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
                if ((local_34 <= uVar17) && (local_2c <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_30 + local_28 + iVar20);
                  uVar12 = *puVar26;
                  uVar31 = ~param_6 & 0xffff;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar31 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar31 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                       iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
                if ((local_40 <= uVar17) && (local_24 <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_20 + local_3c + iVar20);
                  uVar12 = *puVar26;
                  uVar31 = ~param_6 & 0xffff;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar31 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar31 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                       iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
                if ((local_40 <= uVar17) && (local_2c <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_3c + local_28 + iVar20);
                  uVar12 = *puVar26;
                  uVar17 = ~param_6 & 0xffff;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar17 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar17 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                       iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
              }
              if (local_70 < 0) {
                local_48 = iVar8 + param_4;
                bVar3 = iVar22 <= local_48;
                if (bVar3) {
                  local_30 = local_30 + 2;
                  local_34 = local_34 + 1;
                  local_3c = local_3c + -2;
                  local_40 = local_40 - 1;
                  uVar21 = uVar21 + 1;
                  local_48 = local_48 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
                iVar8 = local_48;
              }
              else {
                local_20 = local_20 + iVar2;
                local_24 = local_24 + 1;
                local_2c = local_2c - 1;
                local_28 = local_28 - iVar2;
                param_5 = param_5 + -1;
                bVar3 = true;
                if (local_74 < 0) {
                  local_48 = iVar8 + param_4;
                  local_14 = local_14 + -4;
                  if (iVar22 <= local_48) {
                    local_30 = local_30 + 2;
                    local_34 = local_34 + 1;
                    local_3c = local_3c + -2;
                    local_40 = local_40 - 1;
                    uVar21 = uVar21 + 1;
                    local_48 = local_48 - iVar22;
                  }
                  bVar3 = true;
                  iVar8 = (uVar21 - param_5) * 4;
                  local_70 = local_70 + 2 + iVar8;
                  local_74 = local_74 + 2 + iVar8;
                  iVar8 = local_48;
                }
                else {
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_5);
          }
          if (param_8 == 0) {
            if (((param_2 - uVar21) - iVar25 <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)((param_5 + param_3) * iVar2 + iVar20 + (param_2 - uVar21) * 2);
              uVar12 = *puVar26;
              uVar17 = ~param_6 & 0xffff;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar17 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar17 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800))
                         * 0x800 | (uVar12 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 +
                                             iVar23 * 0x800);
            }
            if (((uVar21 + param_2) - iVar25 <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_3 - param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)((param_3 - param_5) * iVar2 + iVar20 + (uVar21 + param_2) * 2);
              uVar12 = *puVar26;
              uVar21 = ~param_6 & 0xffff;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar21 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar21 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800))
                         * 0x800 | (uVar12 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 +
                                             iVar23 * 0x800);
            }
          }
          break;
        case 0xb:
          if (param_9 == 0) {
            uVar17 = param_2 - DAT_00dca3e4;
            uVar31 = iVar7 - DAT_00dca3e4;
            if ((uVar17 <= uVar31) &&
               ((uint)((param_3 - param_5) - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              puVar26 = (ushort *)((param_3 - param_5) * iVar2 + iVar20 + param_2 * 2);
              uVar12 = *puVar26;
              uVar27 = uVar12 >> 5 & 0x3f;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 >> 5 & 0x3f) * uVar27 >> 6) - uVar27) * 4 +
                                   DAT_00dca3f8 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                   (uint)(uVar12 >> 0xb)) * 4 + DAT_00dca3f8 * 0x800)) * 0x800 |
                         (uVar12 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f)) * 4
                                   + DAT_00dca3f8 * 0x800);
            }
            if ((uVar17 <= uVar31) &&
               ((uint)((param_3 + param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)((param_3 + param_5) * iVar2 + iVar20 + param_2 * 2);
              uVar12 = *puVar26;
              uVar17 = uVar12 >> 5 & 0x3f;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 >> 5 & 0x3f) * uVar17 >> 6) - uVar17) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                   (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                         (uVar12 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f)) * 4
                                   + iVar23 * 0x800);
            }
          }
          if (local_70 < 0) {
            local_48 = param_4;
            bVar3 = iVar22 <= param_4;
            if (bVar3) {
              local_48 = param_4 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_5 = param_5 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              local_48 = param_4;
              if (iVar22 <= param_4) {
                local_48 = param_4 - iVar22;
              }
              bVar3 = true;
              uVar21 = (uint)(iVar22 <= param_4);
              local_74 = (uVar21 - param_5) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_5 * -4;
              local_74 = local_74 + param_5 * -4 + 2;
            }
          }
          if (0 < param_5) {
            local_14 = param_5 * 4;
            local_2c = ((param_5 - iVar5) - param_9) + param_3;
            local_40 = (param_2 - iVar25) - uVar21;
            local_28 = ((param_5 - param_9) + param_3) * iVar2;
            local_24 = (param_3 - iVar5) - param_5;
            local_3c = (param_2 - uVar21) * 2;
            local_20 = (param_3 - param_5) * iVar2;
            local_34 = ((uVar21 - iVar25) - param_8) + param_2;
            local_30 = ((uVar21 - param_8) + param_2) * 2;
            iVar8 = local_48;
            do {
              if (bVar3) {
                uVar17 = iVar7 - iVar25;
                if ((local_34 <= uVar17) && (local_24 <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_30 + local_20 + iVar20);
                  uVar12 = *puVar26;
                  uVar31 = uVar12 >> 5 & 0x3f;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 5 & 0x3f) * uVar31 >> 6) - uVar31) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                       (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f))
                                       * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
                if ((local_34 <= uVar17) && (local_2c <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_30 + local_28 + iVar20);
                  uVar12 = *puVar26;
                  uVar31 = uVar12 >> 5 & 0x3f;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 5 & 0x3f) * uVar31 >> 6) - uVar31) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                       (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f))
                                       * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
                if ((local_40 <= uVar17) && (local_24 <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_20 + local_3c + iVar20);
                  uVar12 = *puVar26;
                  uVar31 = uVar12 >> 5 & 0x3f;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 5 & 0x3f) * uVar31 >> 6) - uVar31) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                       (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f))
                                       * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
                if ((local_40 <= uVar17) && (local_2c <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_3c + local_28 + iVar20);
                  uVar12 = *puVar26;
                  uVar17 = uVar12 >> 5 & 0x3f;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 5 & 0x3f) * uVar17 >> 6) - uVar17) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                       (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f))
                                       * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
              }
              if (local_70 < 0) {
                local_48 = iVar8 + param_4;
                bVar3 = iVar22 <= local_48;
                if (bVar3) {
                  local_30 = local_30 + 2;
                  local_34 = local_34 + 1;
                  local_3c = local_3c + -2;
                  local_40 = local_40 - 1;
                  uVar21 = uVar21 + 1;
                  local_48 = local_48 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
                iVar8 = local_48;
              }
              else {
                local_20 = local_20 + iVar2;
                local_24 = local_24 + 1;
                local_2c = local_2c - 1;
                local_28 = local_28 - iVar2;
                param_5 = param_5 + -1;
                bVar3 = true;
                if (local_74 < 0) {
                  local_48 = iVar8 + param_4;
                  local_14 = local_14 + -4;
                  if (iVar22 <= local_48) {
                    local_30 = local_30 + 2;
                    local_34 = local_34 + 1;
                    local_3c = local_3c + -2;
                    local_40 = local_40 - 1;
                    uVar21 = uVar21 + 1;
                    local_48 = local_48 - iVar22;
                  }
                  bVar3 = true;
                  iVar8 = (uVar21 - param_5) * 4;
                  local_70 = local_70 + 2 + iVar8;
                  local_74 = local_74 + 2 + iVar8;
                  iVar8 = local_48;
                }
                else {
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_5);
          }
          if (param_8 == 0) {
            if (((param_2 - uVar21) - iVar25 <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)((param_5 + param_3) * iVar2 + iVar20 + (param_2 - uVar21) * 2);
              uVar12 = *puVar26;
              uVar17 = uVar12 >> 5 & 0x3f;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 >> 5 & 0x3f) * uVar17 >> 6) - uVar17) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                   (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                         (uVar12 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f)) * 4
                                   + iVar23 * 0x800);
            }
            if (((uVar21 + param_2) - iVar25 <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_3 - param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
              local_68 = (uint *)((param_3 - param_5) * iVar2 + iVar20 + (uVar21 + param_2) * 2);
              uVar12 = *(ushort *)local_68;
              goto LAB_0078b155;
            }
          }
        }
      }
      else if (*(int *)(iVar8 + 0x20) == 1) {
        if ((DAT_00dca3fc & 0xffffff) == 0xffffff) {
          uVar17 = (uint)param_6._2_1_;
        }
        else {
          iVar8 = (uint)param_6._2_1_ * (DAT_00dca3fc >> 0x10 & 0xff);
          param_6._0_2_ =
               CONCAT11((char)((uint)param_6._1_1_ * (DAT_00dca3fc >> 8 & 0xff) >> 8),(byte)param_6)
          ;
          uVar31 = (uint)(ushort)param_6;
          uVar17 = iVar8 >> 8;
          param_6._0_3_ = CONCAT12((char)((uint)iVar8 >> 8),(ushort)param_6);
          param_6 = CONCAT31(param_6._1_3_,(char)((uVar31 & 0xff) * (DAT_00dca3fc & 0xff) >> 8));
        }
        switch(DAT_00dca3f4) {
        case 1:
          if (DAT_00dca3f8 != 0xff) {
            if (DAT_00dca3f8 == 0) {
              return;
            }
            if (param_9 == 0) {
              uVar27 = param_2 - DAT_00dca3e4;
              uVar31 = iVar7 - DAT_00dca3e4;
              if ((uVar27 <= uVar31) &&
                 ((uint)((param_3 - param_5) - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
                iVar23 = (param_3 - param_5) * iVar2 + iVar20;
                uVar30 = (uint)*(byte *)(iVar23 + param_2 * 4);
                puVar1 = (undefined1 *)(iVar23 + param_2 * 4);
                *puVar1 = (char)(((param_6 & 0xff) - uVar30) * DAT_00dca3f8 + uVar30 * 0x100 >> 8);
                puVar1[1] = (char)(((uint)param_6._1_1_ - (uint)(byte)puVar1[1]) * DAT_00dca3f8 +
                                   (uint)(byte)puVar1[1] * 0x100 >> 8);
                puVar1[2] = (char)((uVar17 - (byte)puVar1[2]) * DAT_00dca3f8 +
                                   (uint)(byte)puVar1[2] * 0x100 >> 8);
              }
              if ((uVar27 <= uVar31) &&
                 ((uint)((param_3 + param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
                iVar23 = (param_3 + param_5) * iVar2 + iVar20;
                uVar31 = (uint)*(byte *)(iVar23 + param_2 * 4);
                puVar1 = (undefined1 *)(iVar23 + param_2 * 4);
                *puVar1 = (char)(((param_6 & 0xff) - uVar31) * DAT_00dca3f8 + uVar31 * 0x100 >> 8);
                puVar1[1] = (char)(((uint)param_6._1_1_ - (uint)(byte)puVar1[1]) * DAT_00dca3f8 +
                                   (uint)(byte)puVar1[1] * 0x100 >> 8);
                puVar1[2] = (char)((uVar17 - (byte)puVar1[2]) * DAT_00dca3f8 +
                                   (uint)(byte)puVar1[2] * 0x100 >> 8);
              }
            }
            if (local_70 < 0) {
              bVar3 = iVar22 <= param_4;
              iVar10 = param_4;
              if (bVar3) {
                iVar10 = param_4 - iVar22;
              }
              uVar21 = (uint)bVar3;
              local_74 = local_74 + uVar21 * 4;
              local_70 = iVar15 + 5 + uVar21 * 4;
            }
            else {
              param_5 = param_5 + -1;
              bVar3 = true;
              if (local_74 < 0) {
                iVar10 = param_4;
                if (iVar22 <= param_4) {
                  iVar10 = param_4 - iVar22;
                }
                uVar21 = (uint)(iVar22 <= param_4);
                local_74 = (uVar21 - param_5) * 4;
                local_70 = iVar15 + 5 + local_74;
                local_74 = iVar4 + 5 + local_74;
              }
              else {
                local_70 = local_70 + param_5 * -4;
                local_74 = local_74 + param_5 * -4 + 2;
              }
            }
            if (0 < param_5) {
              local_14 = param_5 * 4;
              local_2c = ((param_5 - iVar5) - param_9) + param_3;
              local_3c = (param_2 - iVar25) - uVar21;
              local_28 = ((param_5 - param_9) + param_3) * iVar2;
              local_24 = (param_3 - iVar5) - param_5;
              local_38 = (param_2 - uVar21) * 4;
              local_20 = (param_3 - param_5) * iVar2;
              local_34 = ((uVar21 - iVar25) - param_8) + param_2;
              local_30 = ((uVar21 - param_8) + param_2) * 4;
              do {
                if (bVar3) {
                  uVar31 = iVar7 - iVar25;
                  if (local_34 <= uVar31) {
                    if (local_24 <= (uint)(iVar13 - iVar5)) {
                      pbVar24 = (byte *)(local_20 + local_30 + iVar20);
                      *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                        (uint)*pbVar24 * 0x100 >> 8);
                      pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                          (uint)pbVar24[1] * 0x100 >> 8);
                      pbVar24[2] = (byte)((uVar17 - pbVar24[2]) * DAT_00dca3f8 +
                                          (uint)pbVar24[2] * 0x100 >> 8);
                    }
                    if ((local_34 <= uVar31) && (local_2c <= (uint)(iVar13 - iVar5))) {
                      pbVar24 = (byte *)(local_28 + local_30 + iVar20);
                      *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                        (uint)*pbVar24 * 0x100 >> 8);
                      pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                          (uint)pbVar24[1] * 0x100 >> 8);
                      pbVar24[2] = (byte)((uVar17 - pbVar24[2]) * DAT_00dca3f8 +
                                          (uint)pbVar24[2] * 0x100 >> 8);
                    }
                  }
                  if (local_3c <= uVar31) {
                    if (local_24 <= (uint)(iVar13 - iVar5)) {
                      pbVar24 = (byte *)(local_38 + local_20 + iVar20);
                      *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                        (uint)*pbVar24 * 0x100 >> 8);
                      pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                          (uint)pbVar24[1] * 0x100 >> 8);
                      pbVar24[2] = (byte)((uVar17 - pbVar24[2]) * DAT_00dca3f8 +
                                          (uint)pbVar24[2] * 0x100 >> 8);
                    }
                    if ((local_3c <= uVar31) && (local_2c <= (uint)(iVar13 - iVar5))) {
                      pbVar24 = (byte *)(local_38 + local_28 + iVar20);
                      *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                        (uint)*pbVar24 * 0x100 >> 8);
                      pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                          (uint)pbVar24[1] * 0x100 >> 8);
                      pbVar24[2] = (byte)((uVar17 - pbVar24[2]) * DAT_00dca3f8 +
                                          (uint)pbVar24[2] * 0x100 >> 8);
                    }
                  }
                }
                if (local_70 < 0) {
                  iVar10 = iVar10 + param_4;
                  bVar3 = iVar22 <= iVar10;
                  if (bVar3) {
                    local_30 = local_30 + 4;
                    local_34 = local_34 + 1;
                    local_38 = local_38 + -4;
                    local_3c = local_3c - 1;
                    uVar21 = uVar21 + 1;
                    iVar10 = iVar10 - iVar22;
                  }
                  local_74 = local_74 + uVar21 * 4;
                  local_70 = local_70 + 2 + uVar21 * 4;
                }
                else {
                  local_20 = local_20 + iVar2;
                  local_28 = local_28 - iVar2;
                  bVar3 = true;
                  local_24 = local_24 + 1;
                  param_5 = param_5 + -1;
                  if (local_74 < 0) {
                    iVar10 = iVar10 + param_4;
                    local_14 = local_14 + -4;
                    local_2c = local_2c - 1;
                    if (iVar22 <= iVar10) {
                      local_34 = local_34 + 1;
                      local_3c = local_3c - 1;
                      local_30 = local_30 + 4;
                      local_38 = local_38 + -4;
                      uVar21 = uVar21 + 1;
                      iVar10 = iVar10 - iVar22;
                    }
                    bVar3 = true;
                    iVar23 = (uVar21 - param_5) * 4;
                    local_70 = local_70 + 2 + iVar23;
                    local_74 = local_74 + 2 + iVar23;
                  }
                  else {
                    local_2c = local_2c - 1;
                    local_14 = local_14 + -4;
                    local_70 = local_70 - local_14;
                    local_74 = local_74 + (2 - local_14);
                  }
                }
              } while (0 < param_5);
            }
            if (param_8 != 0) {
              return;
            }
            iVar23 = param_2 - uVar21;
            if (((uint)(iVar23 - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
              iVar8 = (param_5 + param_3) * iVar2 + iVar20;
              uVar31 = (uint)*(byte *)(iVar8 + iVar23 * 4);
              puVar1 = (undefined1 *)(iVar8 + iVar23 * 4);
              *puVar1 = (char)(((param_6 & 0xff) - uVar31) * DAT_00dca3f8 + uVar31 * 0x100 >> 8);
              puVar1[1] = (char)(((uint)param_6._1_1_ - (uint)(byte)puVar1[1]) * DAT_00dca3f8 +
                                 (uint)(byte)puVar1[1] * 0x100 >> 8);
              puVar1[2] = (char)((uVar17 - (byte)puVar1[2]) * DAT_00dca3f8 +
                                 (uint)(byte)puVar1[2] * 0x100 >> 8);
            }
            param_2 = uVar21 + param_2;
            if ((uint)(iVar7 - iVar25) < (uint)(param_2 - iVar25)) {
              return;
            }
            if ((uint)(iVar13 - iVar5) < (uint)((param_3 - param_5) - iVar5)) {
              return;
            }
            iVar20 = (param_3 - param_5) * iVar2 + iVar20;
            uVar21 = (uint)*(byte *)(iVar20 + param_2 * 4);
            puVar1 = (undefined1 *)(iVar20 + param_2 * 4);
            *puVar1 = (char)(((param_6 & 0xff) - uVar21) * DAT_00dca3f8 + uVar21 * 0x100 >> 8);
            puVar1[1] = (char)(((uint)param_6._1_1_ - (uint)(byte)puVar1[1]) * DAT_00dca3f8 +
                               (uint)(byte)puVar1[1] * 0x100 >> 8);
            puVar1[2] = (char)((uVar17 - (byte)puVar1[2]) * DAT_00dca3f8 +
                               (uint)(byte)puVar1[2] * 0x100 >> 8);
            return;
          }
        case 0:
          if (param_9 == 0) {
            uVar31 = param_2 - DAT_00dca3e4;
            uVar17 = iVar7 - DAT_00dca3e4;
            if ((uVar31 <= uVar17) &&
               ((uint)((param_3 - param_5) - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              *(uint *)((param_3 - param_5) * iVar2 + iVar20 + param_2 * 4) = param_6;
            }
            if ((uVar31 <= uVar17) &&
               ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
              *(uint *)((param_5 + param_3) * iVar2 + iVar20 + param_2 * 4) = param_6;
            }
          }
          if (local_70 < 0) {
            bVar3 = iVar22 <= param_4;
            iVar10 = param_4;
            if (bVar3) {
              iVar10 = param_4 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_5 = param_5 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              iVar10 = param_4;
              if (iVar22 <= param_4) {
                iVar10 = param_4 - iVar22;
              }
              bVar3 = true;
              uVar21 = (uint)(iVar22 <= param_4);
              local_74 = (uVar21 - param_5) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_5 * -4;
              local_74 = local_74 + param_5 * -4 + 2;
            }
          }
          if (0 < param_5) {
            local_14 = param_5 * 4;
            local_28 = ((param_5 - iVar5) - param_9) + param_3;
            local_38 = (param_2 - iVar25) - uVar21;
            iVar23 = ((param_5 - param_9) + param_3) * iVar2;
            local_24 = (param_3 - iVar5) - param_5;
            local_34 = (param_2 - uVar21) * 4;
            local_20 = (param_3 - param_5) * iVar2;
            local_30 = ((uVar21 - iVar25) - param_8) + param_2;
            local_2c = ((uVar21 - param_8) + param_2) * 4;
            do {
              if (bVar3) {
                uVar17 = iVar7 - iVar25;
                if ((local_30 <= uVar17) && (local_24 <= (uint)(iVar13 - iVar5))) {
                  *(uint *)(local_2c + local_20 + iVar20) = param_6;
                }
                if ((local_30 <= uVar17) && (local_28 <= (uint)(iVar13 - iVar5))) {
                  *(uint *)(local_2c + iVar23 + iVar20) = param_6;
                }
                if ((local_38 <= uVar17) && (local_24 <= (uint)(iVar13 - iVar5))) {
                  *(uint *)(local_20 + local_34 + iVar20) = param_6;
                }
                if ((local_38 <= uVar17) && (local_28 <= (uint)(iVar13 - iVar5))) {
                  *(uint *)(local_34 + iVar23 + iVar20) = param_6;
                }
              }
              if (local_70 < 0) {
                iVar10 = iVar10 + param_4;
                bVar3 = iVar22 <= iVar10;
                if (bVar3) {
                  local_2c = local_2c + 4;
                  local_30 = local_30 + 1;
                  local_34 = local_34 + -4;
                  local_38 = local_38 - 1;
                  uVar21 = uVar21 + 1;
                  iVar10 = iVar10 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
              }
              else {
                iVar23 = iVar23 - iVar2;
                local_20 = local_20 + iVar2;
                param_5 = param_5 + -1;
                bVar3 = true;
                if (local_74 < 0) {
                  iVar10 = iVar10 + param_4;
                  local_14 = local_14 + -4;
                  local_24 = local_24 + 1;
                  local_28 = local_28 - 1;
                  if (iVar22 <= iVar10) {
                    local_2c = local_2c + 4;
                    local_30 = local_30 + 1;
                    local_34 = local_34 + -4;
                    local_38 = local_38 - 1;
                    uVar21 = uVar21 + 1;
                    iVar10 = iVar10 - iVar22;
                  }
                  bVar3 = true;
                  iVar8 = (uVar21 - param_5) * 4;
                  local_70 = local_70 + 2 + iVar8;
                  local_74 = local_74 + 2 + iVar8;
                }
                else {
                  local_24 = local_24 + 1;
                  local_28 = local_28 - 1;
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_5);
          }
          if (param_8 == 0) {
            if (((param_2 - uVar21) - iVar25 <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
              *(uint *)((param_5 + param_3) * iVar2 + iVar20 + (param_2 - uVar21) * 4) = param_6;
            }
            if (((uVar21 + param_2) - iVar25 <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_3 - param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
              *(uint *)((param_3 - param_5) * iVar2 + iVar20 + (uVar21 + param_2) * 4) = param_6;
              return;
            }
          }
          break;
        case 2:
          if (DAT_00dca3f8 != 0) {
            if (param_9 == 0) {
              uVar27 = iVar7 - DAT_00dca3e4;
              uVar31 = param_2 - DAT_00dca3e4;
              if ((uVar31 <= uVar27) &&
                 (uVar17 = (uint)param_6._2_1_,
                 (uint)((param_3 - param_5) - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
                puVar29 = (uint *)((param_3 - param_5) * iVar2 + iVar20 + param_2 * 4);
                local_78._0_2_ =
                     CONCAT11(*(undefined1 *)
                               (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (uint)param_6._1_1_),
                              *(undefined1 *)
                               (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_6 & 0xff)));
                local_78._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + uVar17),
                              (undefined2)local_78);
                local_78 = (uint)(uint3)local_78;
                uVar30 = *puVar29;
                uVar19 = (uVar30 & 0xfefeff) + (local_78 & 0xfefeff);
                uVar18 = uVar19 & 0x1010100;
                *puVar29 = uVar18 - (uVar18 >> 8) | (uVar30 | local_78) & 0x10100 | uVar19;
              }
              if ((uVar31 <= uVar27) &&
                 (uVar17 = (uint)param_6._2_1_,
                 (uint)((param_3 + param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar29 = (uint *)((param_3 + param_5) * iVar2 + iVar20 + param_2 * 4);
                local_78._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                local_78._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                              (undefined2)local_78);
                local_78 = (uint)(uint3)local_78;
                uVar31 = *puVar29;
                uVar27 = (uVar31 & 0xfefeff) + (local_78 & 0xfefeff);
                uVar30 = uVar27 & 0x1010100;
                *puVar29 = uVar30 - (uVar30 >> 8) | (uVar31 | local_78) & 0x10100 | uVar27;
              }
            }
            if (local_70 < 0) {
              bVar3 = iVar22 <= param_4;
              iVar10 = param_4;
              if (bVar3) {
                iVar10 = param_4 - iVar22;
              }
              uVar21 = (uint)bVar3;
              local_74 = local_74 + uVar21 * 4;
              local_70 = iVar15 + 5 + uVar21 * 4;
            }
            else {
              param_5 = param_5 + -1;
              bVar3 = true;
              if (local_74 < 0) {
                iVar10 = param_4;
                if (iVar22 <= param_4) {
                  iVar10 = param_4 - iVar22;
                }
                bVar3 = true;
                uVar21 = (uint)(iVar22 <= param_4);
                local_74 = (uVar21 - param_5) * 4;
                local_70 = iVar15 + 5 + local_74;
                local_74 = iVar4 + 5 + local_74;
              }
              else {
                local_70 = local_70 + param_5 * -4;
                local_74 = local_74 + param_5 * -4 + 2;
              }
            }
            if (0 < param_5) {
              local_14 = param_5 * 4;
              local_2c = ((param_5 - iVar5) - param_9) + param_3;
              local_40 = (param_2 - iVar25) - uVar21;
              local_28 = ((param_5 - param_9) + param_3) * iVar2;
              local_24 = (param_3 - iVar5) - param_5;
              local_3c = (param_2 - uVar21) * 4;
              local_20 = (param_3 - param_5) * iVar2;
              local_38 = ((uVar21 - iVar25) - param_8) + param_2;
              local_34 = ((uVar21 - param_8) + param_2) * 4;
              do {
                if (bVar3) {
                  uVar31 = iVar7 - iVar25;
                  if ((local_38 <= uVar31) && (local_24 <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_20 + local_34 + iVar20);
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78._0_3_ =
                         CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                  (undefined2)local_78);
                    local_78 = (uint)(uint3)local_78;
                    uVar27 = *puVar29;
                    uVar30 = (uVar27 & 0xfefeff) + (local_78 & 0xfefeff);
                    uVar19 = uVar30 & 0x1010100;
                    *puVar29 = uVar19 - (uVar19 >> 8) | (uVar27 | local_78) & 0x10100 | uVar30;
                  }
                  if ((local_38 <= uVar31) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_28 + local_34 + iVar20);
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78._0_3_ =
                         CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                  (undefined2)local_78);
                    local_78 = (uint)(uint3)local_78;
                    uVar27 = *puVar29;
                    uVar30 = (uVar27 & 0xfefeff) + (local_78 & 0xfefeff);
                    uVar19 = uVar30 & 0x1010100;
                    uVar17 = (uint)param_6._2_1_;
                    *puVar29 = uVar19 - (uVar19 >> 8) | (uVar27 | local_78) & 0x10100 | uVar30;
                  }
                  if ((local_40 <= uVar31) && (local_24 <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_3c + local_20 + iVar20);
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78._0_3_ =
                         CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                  (undefined2)local_78);
                    local_78 = (uint)(uint3)local_78;
                    uVar27 = *puVar29;
                    uVar30 = (uVar27 & 0xfefeff) + (local_78 & 0xfefeff);
                    uVar19 = uVar30 & 0x1010100;
                    uVar17 = (uint)param_6._2_1_;
                    *puVar29 = uVar19 - (uVar19 >> 8) | (uVar27 | local_78) & 0x10100 | uVar30;
                  }
                  if ((local_40 <= uVar31) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_28 + local_3c + iVar20);
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78._0_3_ =
                         CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                  (undefined2)local_78);
                    local_78 = (uint)(uint3)local_78;
                    uVar31 = *puVar29;
                    uVar27 = (uVar31 & 0xfefeff) + (local_78 & 0xfefeff);
                    uVar30 = uVar27 & 0x1010100;
                    uVar17 = (uint)param_6._2_1_;
                    *puVar29 = uVar30 - (uVar30 >> 8) | (uVar31 | local_78) & 0x10100 | uVar27;
                  }
                }
                if (local_70 < 0) {
                  iVar10 = iVar10 + param_4;
                  bVar3 = iVar22 <= iVar10;
                  if (bVar3) {
                    local_34 = local_34 + 4;
                    local_38 = local_38 + 1;
                    local_3c = local_3c + -4;
                    local_40 = local_40 - 1;
                    uVar21 = uVar21 + 1;
                    iVar10 = iVar10 - iVar22;
                  }
                  local_74 = local_74 + uVar21 * 4;
                  local_70 = local_70 + 2 + uVar21 * 4;
                }
                else {
                  local_20 = local_20 + iVar2;
                  local_24 = local_24 + 1;
                  local_2c = local_2c - 1;
                  local_28 = local_28 - iVar2;
                  param_5 = param_5 + -1;
                  bVar3 = true;
                  if (local_74 < 0) {
                    iVar10 = iVar10 + param_4;
                    local_14 = local_14 + -4;
                    if (iVar22 <= iVar10) {
                      local_34 = local_34 + 4;
                      local_38 = local_38 + 1;
                      local_3c = local_3c + -4;
                      local_40 = local_40 - 1;
                      uVar21 = uVar21 + 1;
                      iVar10 = iVar10 - iVar22;
                    }
                    bVar3 = true;
                    iVar8 = (uVar21 - param_5) * 4;
                    local_70 = local_70 + 2 + iVar8;
                    local_74 = local_74 + 2 + iVar8;
                  }
                  else {
                    local_14 = local_14 + -4;
                    local_70 = local_70 - local_14;
                    local_74 = local_74 + (2 - local_14);
                  }
                }
              } while (0 < param_5);
            }
            if (param_8 == 0) {
              if (((param_2 - uVar21) - iVar25 <= (uint)(iVar7 - iVar25)) &&
                 ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar29 = (uint *)((param_5 + param_3) * iVar2 + iVar20 + (param_2 - uVar21) * 4);
                local_78._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                local_78._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                              (undefined2)local_78);
                local_78 = (uint)(uint3)local_78;
                uVar31 = *puVar29;
                uVar27 = (uVar31 & 0xfefeff) + (local_78 & 0xfefeff);
                uVar30 = uVar27 & 0x1010100;
                *puVar29 = uVar30 - (uVar30 >> 8) | (uVar31 | local_78) & 0x10100 | uVar27;
              }
              if (((uVar21 + param_2) - iVar25 <= (uint)(iVar7 - iVar25)) &&
                 ((uint)((param_3 - param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar29 = (uint *)((param_3 - param_5) * iVar2 + iVar20 + (uVar21 + param_2) * 4);
                uVar21 = *puVar29;
                local_78._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                local_78._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                              (undefined2)local_78);
                local_78 = (uint)(uint3)local_78;
                uVar31 = (uVar21 & 0xfefeff) + (local_78 & 0xfefeff);
                uVar17 = uVar31 & 0x1010100;
                *puVar29 = uVar17 - (uVar17 >> 8) | (uVar21 | local_78) & 0x10100 | uVar31;
                return;
              }
            }
          }
          break;
        case 3:
          if (DAT_00dca3f8 != 0) {
            if (param_9 == 0) {
              uVar31 = param_2 - DAT_00dca3e4;
              uVar27 = iVar7 - DAT_00dca3e4;
              if ((uVar31 <= uVar27) &&
                 (uVar17 = (uint)param_6._2_1_,
                 (uint)((param_3 - param_5) - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
                puVar29 = (uint *)((param_3 - param_5) * iVar2 + iVar20 + param_2 * 4);
                local_78._0_2_ =
                     CONCAT11(*(undefined1 *)
                               (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (uint)param_6._1_1_),
                              *(undefined1 *)
                               (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_6 & 0xff)));
                local_78._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + uVar17),
                              (undefined2)local_78);
                uVar30 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                uVar19 = uVar30 & 0x1010100;
                *puVar29 = uVar19 - (uVar19 >> 8) & uVar30;
              }
              uVar30 = local_78;
              if ((uVar31 <= uVar27) &&
                 (uVar17 = (uint)param_6._2_1_,
                 (uint)((param_3 + param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar29 = (uint *)((param_3 + param_5) * iVar2 + iVar20 + param_2 * 4);
                local_78._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                local_78._3_1_ = SUB41(uVar30,3);
                local_78._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                              (undefined2)local_78);
                uVar31 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                uVar27 = uVar31 & 0x1010100;
                *puVar29 = uVar27 - (uVar27 >> 8) & uVar31;
              }
            }
            if (local_70 < 0) {
              bVar3 = iVar22 <= param_4;
              iVar10 = param_4;
              if (bVar3) {
                iVar10 = param_4 - iVar22;
              }
              uVar21 = (uint)bVar3;
              local_74 = local_74 + uVar21 * 4;
              local_70 = iVar15 + 5 + uVar21 * 4;
            }
            else {
              param_5 = param_5 + -1;
              bVar3 = true;
              if (local_74 < 0) {
                iVar10 = param_4;
                if (iVar22 <= param_4) {
                  iVar10 = param_4 - iVar22;
                }
                bVar3 = true;
                uVar21 = (uint)(iVar22 <= param_4);
                local_74 = (uVar21 - param_5) * 4;
                local_70 = iVar15 + 5 + local_74;
                local_74 = iVar4 + 5 + local_74;
              }
              else {
                local_70 = local_70 + param_5 * -4;
                local_74 = local_74 + param_5 * -4 + 2;
              }
            }
            if (0 < param_5) {
              local_14 = param_5 * 4;
              local_2c = ((param_5 - iVar5) - param_9) + param_3;
              local_3c = (param_2 - iVar25) - uVar21;
              local_28 = ((param_5 - param_9) + param_3) * iVar2;
              local_24 = (param_3 - iVar5) - param_5;
              local_38 = (param_2 - uVar21) * 4;
              local_20 = (param_3 - param_5) * iVar2;
              local_34 = ((uVar21 - iVar25) - param_8) + param_2;
              local_30 = ((uVar21 - param_8) + param_2) * 4;
              do {
                uVar31 = local_78;
                if (bVar3) {
                  uVar27 = iVar7 - iVar25;
                  if ((local_34 <= uVar27) && (local_24 <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_20 + local_30 + iVar20);
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78._3_1_ = SUB41(uVar31,3);
                    local_78._0_3_ =
                         CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                  (undefined2)local_78);
                    uVar31 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                    uVar30 = uVar31 & 0x1010100;
                    *puVar29 = uVar30 - (uVar30 >> 8) & uVar31;
                  }
                  uVar31 = local_78;
                  if ((local_34 <= uVar27) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_28 + local_30 + iVar20);
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78._3_1_ = SUB41(uVar31,3);
                    local_78._0_3_ =
                         CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                  (undefined2)local_78);
                    uVar31 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                    uVar30 = uVar31 & 0x1010100;
                    *puVar29 = uVar30 - (uVar30 >> 8) & uVar31;
                  }
                  uVar31 = local_78;
                  if ((local_3c <= uVar27) && (local_24 <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_38 + local_20 + iVar20);
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78._3_1_ = SUB41(uVar31,3);
                    local_78._0_3_ =
                         CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                  (undefined2)local_78);
                    uVar31 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                    uVar30 = uVar31 & 0x1010100;
                    *puVar29 = uVar30 - (uVar30 >> 8) & uVar31;
                  }
                  uVar31 = local_78;
                  if ((local_3c <= uVar27) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_28 + local_38 + iVar20);
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78._3_1_ = SUB41(uVar31,3);
                    local_78._0_3_ =
                         CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                  (undefined2)local_78);
                    uVar31 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                    uVar27 = uVar31 & 0x1010100;
                    *puVar29 = uVar27 - (uVar27 >> 8) & uVar31;
                  }
                }
                if (local_70 < 0) {
                  iVar10 = iVar10 + param_4;
                  bVar3 = iVar22 <= iVar10;
                  if (bVar3) {
                    local_30 = local_30 + 4;
                    local_34 = local_34 + 1;
                    local_38 = local_38 + -4;
                    local_3c = local_3c - 1;
                    uVar21 = uVar21 + 1;
                    iVar10 = iVar10 - iVar22;
                  }
                  local_74 = local_74 + uVar21 * 4;
                  local_70 = local_70 + 2 + uVar21 * 4;
                }
                else {
                  local_20 = local_20 + iVar2;
                  local_24 = local_24 + 1;
                  local_2c = local_2c - 1;
                  local_28 = local_28 - iVar2;
                  param_5 = param_5 + -1;
                  bVar3 = true;
                  if (local_74 < 0) {
                    iVar10 = iVar10 + param_4;
                    local_14 = local_14 + -4;
                    if (iVar22 <= iVar10) {
                      local_30 = local_30 + 4;
                      local_34 = local_34 + 1;
                      local_38 = local_38 + -4;
                      local_3c = local_3c - 1;
                      uVar21 = uVar21 + 1;
                      iVar10 = iVar10 - iVar22;
                    }
                    bVar3 = true;
                    iVar8 = (uVar21 - param_5) * 4;
                    local_70 = local_70 + 2 + iVar8;
                    local_74 = local_74 + 2 + iVar8;
                  }
                  else {
                    local_14 = local_14 + -4;
                    local_70 = local_70 - local_14;
                    local_74 = local_74 + (2 - local_14);
                  }
                }
              } while (0 < param_5);
            }
            if (param_8 == 0) {
              if ((param_2 - uVar21) - iVar25 <= (uint)(iVar7 - iVar25)) {
                if ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5)) {
                  puVar29 = (uint *)((param_5 + param_3) * iVar2 + iVar20 + (param_2 - uVar21) * 4);
                  local_78._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                  local_78._0_3_ =
                       CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                (undefined2)local_78);
                  uVar27 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                  uVar31 = uVar27 & 0x1010100;
                  *puVar29 = uVar31 - (uVar31 >> 8) & uVar27;
                }
              }
              if (((uVar21 + param_2) - iVar25 <= (uint)(iVar7 - iVar25)) &&
                 ((uint)((param_3 - param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar29 = (uint *)((param_3 - param_5) * iVar2 + iVar20 + (uVar21 + param_2) * 4);
                local_78._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                local_78._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                              (undefined2)local_78);
                uVar17 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                uVar21 = uVar17 & 0x1010100;
                *puVar29 = uVar21 - (uVar21 >> 8) & uVar17;
                return;
              }
            }
          }
          break;
        case 4:
          if (param_9 == 0) {
            uVar27 = iVar7 - DAT_00dca3e4;
            uVar31 = param_2 - DAT_00dca3e4;
            if ((uVar31 <= uVar27) &&
               ((uint)((param_3 - param_5) - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              pbVar24 = (byte *)((param_3 - param_5) * iVar2 + iVar20 + param_2 * 4);
              uVar17 = (uint)param_6._2_1_;
              *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
              pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
              pbVar24[2] = (byte)(pbVar24[2] * uVar17 >> 8);
            }
            if ((uVar31 <= uVar27) &&
               ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
              pbVar24 = (byte *)((param_5 + param_3) * iVar2 + iVar20 + param_2 * 4);
              uVar17 = (uint)param_6._2_1_;
              *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
              pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
              pbVar24[2] = (byte)(pbVar24[2] * uVar17 >> 8);
            }
          }
          if (local_70 < 0) {
            bVar3 = iVar22 <= param_4;
            iVar10 = param_4;
            if (bVar3) {
              iVar10 = param_4 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_5 = param_5 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              iVar10 = param_4;
              if (iVar22 <= param_4) {
                iVar10 = param_4 - iVar22;
              }
              bVar3 = true;
              uVar21 = (uint)(iVar22 <= param_4);
              local_74 = (uVar21 - param_5) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_5 * -4;
              local_74 = local_74 + param_5 * -4 + 2;
            }
          }
          if (0 < param_5) {
            local_14 = param_5 * 4;
            local_28 = ((param_5 - iVar5) - param_9) + param_3;
            local_38 = (param_2 - iVar25) - uVar21;
            iVar23 = ((param_5 - param_9) + param_3) * iVar2;
            local_24 = (param_3 - iVar5) - param_5;
            local_34 = (param_2 - uVar21) * 4;
            local_20 = (param_3 - param_5) * iVar2;
            local_30 = ((uVar21 - iVar25) - param_8) + param_2;
            local_2c = ((uVar21 - param_8) + param_2) * 4;
            local_18 = iVar23;
            do {
              if (bVar3) {
                uVar31 = iVar7 - iVar25;
                if ((local_30 <= uVar31) && (local_24 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_20 + local_2c + iVar20);
                  *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
                  uVar17 = (uint)param_6._2_1_;
                  pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
                  pbVar24[2] = (byte)(pbVar24[2] * uVar17 >> 8);
                }
                if ((local_30 <= uVar31) && (local_28 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_2c + iVar23 + iVar20);
                  *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
                  uVar17 = (uint)param_6._2_1_;
                  pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
                  pbVar24[2] = (byte)(pbVar24[2] * uVar17 >> 8);
                }
                if ((local_38 <= uVar31) && (local_24 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_34 + local_20 + iVar20);
                  *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
                  uVar17 = (uint)param_6._2_1_;
                  pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
                  pbVar24[2] = (byte)(pbVar24[2] * uVar17 >> 8);
                }
                if ((local_38 <= uVar31) && (local_28 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_34 + iVar23 + iVar20);
                  uVar17 = (uint)param_6._2_1_;
                  *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
                  pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
                  pbVar24[2] = (byte)(pbVar24[2] * uVar17 >> 8);
                  iVar23 = local_18;
                }
              }
              if (local_70 < 0) {
                iVar10 = iVar10 + param_4;
                bVar3 = iVar22 <= iVar10;
                if (bVar3) {
                  local_2c = local_2c + 4;
                  local_30 = local_30 + 1;
                  local_34 = local_34 + -4;
                  local_38 = local_38 - 1;
                  uVar21 = uVar21 + 1;
                  iVar10 = iVar10 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
              }
              else {
                iVar23 = iVar23 - iVar2;
                local_20 = local_20 + iVar2;
                param_5 = param_5 + -1;
                bVar3 = true;
                local_18 = iVar23;
                if (local_74 < 0) {
                  iVar10 = iVar10 + param_4;
                  local_14 = local_14 + -4;
                  local_24 = local_24 + 1;
                  local_28 = local_28 - 1;
                  if (iVar22 <= iVar10) {
                    local_2c = local_2c + 4;
                    local_30 = local_30 + 1;
                    local_34 = local_34 + -4;
                    local_38 = local_38 - 1;
                    uVar21 = uVar21 + 1;
                    iVar10 = iVar10 - iVar22;
                  }
                  bVar3 = true;
                  iVar8 = (uVar21 - param_5) * 4;
                  local_70 = local_70 + 2 + iVar8;
                  local_74 = local_74 + 2 + iVar8;
                }
                else {
                  local_24 = local_24 + 1;
                  local_28 = local_28 - 1;
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_5);
          }
          if (param_8 == 0) {
            iVar23 = param_2 - uVar21;
            if (((uint)(iVar23 - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
              iVar8 = (param_5 + param_3) * iVar2 + iVar20;
              puVar1 = (undefined1 *)(iVar8 + iVar23 * 4);
              *puVar1 = (char)((uint)*(byte *)(iVar8 + iVar23 * 4) * (param_6 & 0xff) >> 8);
              puVar1[1] = (char)((uint)(byte)puVar1[1] * (uint)param_6._1_1_ >> 8);
              puVar1[2] = (char)((byte)puVar1[2] * uVar17 >> 8);
            }
            param_2 = uVar21 + param_2;
            if (((uint)(param_2 - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_3 - param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
              iVar20 = (param_3 - param_5) * iVar2 + iVar20;
              puVar1 = (undefined1 *)(iVar20 + param_2 * 4);
              *puVar1 = (char)((uint)*(byte *)(iVar20 + param_2 * 4) * (param_6 & 0xff) >> 8);
              puVar1[1] = (char)((uint)(byte)puVar1[1] * (uint)param_6._1_1_ >> 8);
              puVar1[2] = (char)((byte)puVar1[2] * uVar17 >> 8);
              return;
            }
          }
          break;
        case 10:
          bVar11 = (byte)uVar17;
          if (param_9 == 0) {
            uVar31 = param_2 - DAT_00dca3e4;
            uVar17 = iVar7 - DAT_00dca3e4;
            if ((uVar31 <= uVar17) &&
               ((uint)((param_3 - param_5) - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              iVar23 = (param_3 - param_5) * iVar2 + iVar20;
              uVar27 = (uint)*(byte *)(iVar23 + param_2 * 4);
              puVar1 = (undefined1 *)(iVar23 + param_2 * 4);
              *puVar1 = (char)(((byte)~(byte)param_6 - uVar27) * DAT_00dca3f8 + uVar27 * 0x100 >> 8)
              ;
              puVar1[1] = (char)(((uint)(byte)~param_6._1_1_ - (uint)(byte)puVar1[1]) * DAT_00dca3f8
                                 + (uint)(byte)puVar1[1] * 0x100 >> 8);
              puVar1[2] = (char)(((uint)(byte)~bVar11 - (uint)(byte)puVar1[2]) * DAT_00dca3f8 +
                                 (uint)(byte)puVar1[2] * 0x100 >> 8);
            }
            if ((uVar31 <= uVar17) &&
               ((uint)((param_3 + param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
              iVar23 = (param_3 + param_5) * iVar2 + iVar20;
              uVar17 = (uint)*(byte *)(iVar23 + param_2 * 4);
              puVar1 = (undefined1 *)(iVar23 + param_2 * 4);
              *puVar1 = (char)(((byte)~(byte)param_6 - uVar17) * DAT_00dca3f8 + uVar17 * 0x100 >> 8)
              ;
              puVar1[1] = (char)(((uint)(byte)~param_6._1_1_ - (uint)(byte)puVar1[1]) * DAT_00dca3f8
                                 + (uint)(byte)puVar1[1] * 0x100 >> 8);
              puVar1[2] = (char)(((uint)(byte)~bVar11 - (uint)(byte)puVar1[2]) * DAT_00dca3f8 +
                                 (uint)(byte)puVar1[2] * 0x100 >> 8);
            }
          }
          if (local_70 < 0) {
            bVar3 = iVar22 <= param_4;
            iVar10 = param_4;
            if (bVar3) {
              iVar10 = param_4 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_5 = param_5 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              iVar10 = param_4;
              if (iVar22 <= param_4) {
                iVar10 = param_4 - iVar22;
              }
              uVar21 = (uint)(iVar22 <= param_4);
              local_74 = (uVar21 - param_5) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_5 * -4;
              local_74 = local_74 + param_5 * -4 + 2;
            }
          }
          if (0 < param_5) {
            local_14 = param_5 * 4;
            local_2c = ((param_5 - iVar5) - param_9) + param_3;
            local_3c = (param_2 - iVar25) - uVar21;
            local_28 = ((param_5 - param_9) + param_3) * iVar2;
            local_24 = (param_3 - iVar5) - param_5;
            local_38 = (param_2 - uVar21) * 4;
            local_20 = (param_3 - param_5) * iVar2;
            local_34 = ((uVar21 - iVar25) - param_8) + param_2;
            local_30 = ((uVar21 - param_8) + param_2) * 4;
            do {
              if (bVar3) {
                uVar17 = iVar7 - iVar25;
                if (local_34 <= uVar17) {
                  if (local_24 <= (uint)(iVar13 - iVar5)) {
                    pbVar24 = (byte *)(local_20 + local_30 + iVar20);
                    *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                      (uint)*pbVar24 * 0x100 >> 8);
                    pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) *
                                        DAT_00dca3f8 + (uint)pbVar24[1] * 0x100 >> 8);
                    pbVar24[2] = (byte)(((uint)(byte)~bVar11 - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                        (uint)pbVar24[2] * 0x100 >> 8);
                  }
                  if ((local_34 <= uVar17) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    pbVar24 = (byte *)(local_28 + local_30 + iVar20);
                    *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                      (uint)*pbVar24 * 0x100 >> 8);
                    pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) *
                                        DAT_00dca3f8 + (uint)pbVar24[1] * 0x100 >> 8);
                    pbVar24[2] = (byte)(((uint)(byte)~bVar11 - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                        (uint)pbVar24[2] * 0x100 >> 8);
                  }
                }
                if (local_3c <= uVar17) {
                  if (local_24 <= (uint)(iVar13 - iVar5)) {
                    pbVar24 = (byte *)(local_38 + local_20 + iVar20);
                    *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                      (uint)*pbVar24 * 0x100 >> 8);
                    pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) *
                                        DAT_00dca3f8 + (uint)pbVar24[1] * 0x100 >> 8);
                    pbVar24[2] = (byte)(((uint)(byte)~bVar11 - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                        (uint)pbVar24[2] * 0x100 >> 8);
                  }
                  if ((local_3c <= uVar17) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    pbVar24 = (byte *)(local_38 + local_28 + iVar20);
                    *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                      (uint)*pbVar24 * 0x100 >> 8);
                    pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) *
                                        DAT_00dca3f8 + (uint)pbVar24[1] * 0x100 >> 8);
                    pbVar24[2] = (byte)(((uint)(byte)~bVar11 - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                        (uint)pbVar24[2] * 0x100 >> 8);
                  }
                }
              }
              if (local_70 < 0) {
                iVar10 = iVar10 + param_4;
                bVar3 = iVar22 <= iVar10;
                if (bVar3) {
                  local_30 = local_30 + 4;
                  local_34 = local_34 + 1;
                  local_38 = local_38 + -4;
                  local_3c = local_3c - 1;
                  uVar21 = uVar21 + 1;
                  iVar10 = iVar10 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
              }
              else {
                local_20 = local_20 + iVar2;
                local_28 = local_28 - iVar2;
                bVar3 = true;
                local_24 = local_24 + 1;
                param_5 = param_5 + -1;
                if (local_74 < 0) {
                  iVar10 = iVar10 + param_4;
                  local_14 = local_14 + -4;
                  local_2c = local_2c - 1;
                  if (iVar22 <= iVar10) {
                    local_34 = local_34 + 1;
                    local_3c = local_3c - 1;
                    local_30 = local_30 + 4;
                    local_38 = local_38 + -4;
                    uVar21 = uVar21 + 1;
                    iVar10 = iVar10 - iVar22;
                  }
                  bVar3 = true;
                  iVar23 = (uVar21 - param_5) * 4;
                  local_70 = local_70 + 2 + iVar23;
                  local_74 = local_74 + 2 + iVar23;
                }
                else {
                  local_2c = local_2c - 1;
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_5);
          }
          if (param_8 == 0) {
            iVar23 = param_2 - uVar21;
            if (((uint)(iVar23 - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
              iVar8 = (param_5 + param_3) * iVar2 + iVar20;
              uVar17 = (uint)*(byte *)(iVar8 + iVar23 * 4);
              puVar1 = (undefined1 *)(iVar8 + iVar23 * 4);
              *puVar1 = (char)(((byte)~(byte)param_6 - uVar17) * DAT_00dca3f8 + uVar17 * 0x100 >> 8)
              ;
              puVar1[1] = (char)(((uint)(byte)~param_6._1_1_ - (uint)(byte)puVar1[1]) * DAT_00dca3f8
                                 + (uint)(byte)puVar1[1] * 0x100 >> 8);
              puVar1[2] = (char)(((uint)(byte)~bVar11 - (uint)(byte)puVar1[2]) * DAT_00dca3f8 +
                                 (uint)(byte)puVar1[2] * 0x100 >> 8);
            }
            param_2 = uVar21 + param_2;
            if (((uint)(param_2 - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_3 - param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
              iVar20 = (param_3 - param_5) * iVar2 + iVar20;
              uVar21 = (uint)*(byte *)(iVar20 + param_2 * 4);
              puVar1 = (undefined1 *)(iVar20 + param_2 * 4);
              *puVar1 = (char)(((byte)~(byte)param_6 - uVar21) * DAT_00dca3f8 + uVar21 * 0x100 >> 8)
              ;
              puVar1[1] = (char)(((uint)(byte)~param_6._1_1_ - (uint)(byte)puVar1[1]) * DAT_00dca3f8
                                 + (uint)(byte)puVar1[1] * 0x100 >> 8);
              puVar1[2] = (char)(((uint)(byte)~bVar11 - (uint)(byte)puVar1[2]) * DAT_00dca3f8 +
                                 (uint)(byte)puVar1[2] * 0x100 >> 8);
              return;
            }
          }
          break;
        case 0xb:
          if (param_9 == 0) {
            uVar27 = param_2 - DAT_00dca3e4;
            uVar31 = iVar7 - DAT_00dca3e4;
            if ((uVar27 <= uVar31) &&
               ((uint)((param_3 - param_5) - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              iVar23 = (param_3 - param_5) * iVar2 + iVar20;
              uVar30 = (uint)*(byte *)(iVar23 + param_2 * 4);
              puVar1 = (undefined1 *)(iVar23 + param_2 * 4);
              *puVar1 = (char)((((int)((param_6 & 0xff) * uVar30) >> 8) - uVar30) * DAT_00dca3f8 +
                               uVar30 * 0x100 >> 8);
              uVar30 = (uint)(byte)puVar1[1];
              puVar1[1] = (char)((((int)(param_6._1_1_ * uVar30) >> 8) - uVar30) * DAT_00dca3f8 +
                                 uVar30 * 0x100 >> 8);
              uVar30 = (uint)(byte)puVar1[2];
              puVar1[2] = (char)((((int)(uVar17 * uVar30) >> 8) - uVar30) * DAT_00dca3f8 +
                                 uVar30 * 0x100 >> 8);
            }
            if ((uVar27 <= uVar31) &&
               ((uint)((param_3 + param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
              iVar23 = (param_3 + param_5) * iVar2 + iVar20;
              uVar31 = (uint)*(byte *)(iVar23 + param_2 * 4);
              puVar1 = (undefined1 *)(iVar23 + param_2 * 4);
              *puVar1 = (char)((((int)((param_6 & 0xff) * uVar31) >> 8) - uVar31) * DAT_00dca3f8 +
                               uVar31 * 0x100 >> 8);
              uVar31 = (uint)(byte)puVar1[1];
              puVar1[1] = (char)((((int)(param_6._1_1_ * uVar31) >> 8) - uVar31) * DAT_00dca3f8 +
                                 uVar31 * 0x100 >> 8);
              uVar31 = (uint)(byte)puVar1[2];
              puVar1[2] = (char)((((int)(uVar17 * uVar31) >> 8) - uVar31) * DAT_00dca3f8 +
                                 uVar31 * 0x100 >> 8);
            }
          }
          if (local_70 < 0) {
            bVar3 = iVar22 <= param_4;
            iVar10 = param_4;
            if (bVar3) {
              iVar10 = param_4 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_5 = param_5 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              iVar10 = param_4;
              if (iVar22 <= param_4) {
                iVar10 = param_4 - iVar22;
              }
              uVar21 = (uint)(iVar22 <= param_4);
              local_74 = (uVar21 - param_5) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_5 * -4;
              local_74 = local_74 + param_5 * -4 + 2;
            }
          }
          if (0 < param_5) {
            local_14 = param_5 * 4;
            local_2c = ((param_5 - iVar5) - param_9) + param_3;
            local_3c = (param_2 - iVar25) - uVar21;
            local_28 = ((param_5 - param_9) + param_3) * iVar2;
            local_24 = (param_3 - iVar5) - param_5;
            local_38 = (param_2 - uVar21) * 4;
            local_20 = (param_3 - param_5) * iVar2;
            local_34 = ((uVar21 - iVar25) - param_8) + param_2;
            local_30 = ((uVar21 - param_8) + param_2) * 4;
            do {
              if (bVar3) {
                uVar31 = iVar7 - iVar25;
                if (local_34 <= uVar31) {
                  if (local_24 <= (uint)(iVar13 - iVar5)) {
                    pbVar24 = (byte *)(local_20 + local_30 + iVar20);
                    uVar27 = (uint)*pbVar24;
                    *pbVar24 = (byte)((((int)((param_6 & 0xff) * uVar27) >> 8) - uVar27) *
                                      DAT_00dca3f8 + uVar27 * 0x100 >> 8);
                    uVar27 = (uint)pbVar24[1];
                    pbVar24[1] = (byte)((((int)(param_6._1_1_ * uVar27) >> 8) - uVar27) *
                                        DAT_00dca3f8 + uVar27 * 0x100 >> 8);
                    uVar27 = (uint)pbVar24[2];
                    pbVar24[2] = (byte)((((int)(uVar17 * uVar27) >> 8) - uVar27) * DAT_00dca3f8 +
                                        uVar27 * 0x100 >> 8);
                  }
                  if ((local_34 <= uVar31) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    pbVar24 = (byte *)(local_28 + local_30 + iVar20);
                    uVar27 = (uint)*pbVar24;
                    *pbVar24 = (byte)((((int)((param_6 & 0xff) * uVar27) >> 8) - uVar27) *
                                      DAT_00dca3f8 + uVar27 * 0x100 >> 8);
                    uVar27 = (uint)pbVar24[1];
                    pbVar24[1] = (byte)((((int)(param_6._1_1_ * uVar27) >> 8) - uVar27) *
                                        DAT_00dca3f8 + uVar27 * 0x100 >> 8);
                    uVar27 = (uint)pbVar24[2];
                    pbVar24[2] = (byte)((((int)(uVar17 * uVar27) >> 8) - uVar27) * DAT_00dca3f8 +
                                        uVar27 * 0x100 >> 8);
                  }
                }
                if (local_3c <= uVar31) {
                  if (local_24 <= (uint)(iVar13 - iVar5)) {
                    pbVar24 = (byte *)(local_38 + local_20 + iVar20);
                    uVar27 = (uint)*pbVar24;
                    *pbVar24 = (byte)((((int)((param_6 & 0xff) * uVar27) >> 8) - uVar27) *
                                      DAT_00dca3f8 + uVar27 * 0x100 >> 8);
                    uVar27 = (uint)pbVar24[1];
                    pbVar24[1] = (byte)((((int)(param_6._1_1_ * uVar27) >> 8) - uVar27) *
                                        DAT_00dca3f8 + uVar27 * 0x100 >> 8);
                    uVar27 = (uint)pbVar24[2];
                    pbVar24[2] = (byte)((((int)(uVar17 * uVar27) >> 8) - uVar27) * DAT_00dca3f8 +
                                        uVar27 * 0x100 >> 8);
                  }
                  if ((local_3c <= uVar31) && (local_2c <= (uint)(iVar13 - iVar5))) {
                    pbVar24 = (byte *)(local_38 + local_28 + iVar20);
                    uVar31 = (uint)*pbVar24;
                    *pbVar24 = (byte)((((int)((param_6 & 0xff) * uVar31) >> 8) - uVar31) *
                                      DAT_00dca3f8 + uVar31 * 0x100 >> 8);
                    uVar31 = (uint)pbVar24[1];
                    pbVar24[1] = (byte)((((int)(param_6._1_1_ * uVar31) >> 8) - uVar31) *
                                        DAT_00dca3f8 + uVar31 * 0x100 >> 8);
                    uVar31 = (uint)pbVar24[2];
                    pbVar24[2] = (byte)((((int)(uVar17 * uVar31) >> 8) - uVar31) * DAT_00dca3f8 +
                                        uVar31 * 0x100 >> 8);
                  }
                }
              }
              if (local_70 < 0) {
                iVar10 = iVar10 + param_4;
                bVar3 = iVar22 <= iVar10;
                if (bVar3) {
                  local_30 = local_30 + 4;
                  local_34 = local_34 + 1;
                  local_38 = local_38 + -4;
                  local_3c = local_3c - 1;
                  uVar21 = uVar21 + 1;
                  iVar10 = iVar10 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
              }
              else {
                local_20 = local_20 + iVar2;
                local_28 = local_28 - iVar2;
                bVar3 = true;
                local_24 = local_24 + 1;
                param_5 = param_5 + -1;
                if (local_74 < 0) {
                  iVar10 = iVar10 + param_4;
                  local_14 = local_14 + -4;
                  local_2c = local_2c - 1;
                  if (iVar22 <= iVar10) {
                    local_34 = local_34 + 1;
                    local_3c = local_3c - 1;
                    local_30 = local_30 + 4;
                    local_38 = local_38 + -4;
                    uVar21 = uVar21 + 1;
                    iVar10 = iVar10 - iVar22;
                  }
                  bVar3 = true;
                  iVar23 = (uVar21 - param_5) * 4;
                  local_70 = local_70 + 2 + iVar23;
                  local_74 = local_74 + 2 + iVar23;
                }
                else {
                  local_2c = local_2c - 1;
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_5);
          }
          if (param_8 == 0) {
            iVar23 = param_2 - uVar21;
            if (((uint)(iVar23 - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_5 + param_3) - iVar5) <= (uint)(iVar13 - iVar5))) {
              iVar8 = (param_5 + param_3) * iVar2 + iVar20;
              uVar31 = (uint)*(byte *)(iVar8 + iVar23 * 4);
              puVar1 = (undefined1 *)(iVar8 + iVar23 * 4);
              *puVar1 = (char)((((int)((param_6 & 0xff) * uVar31) >> 8) - uVar31) * DAT_00dca3f8 +
                               uVar31 * 0x100 >> 8);
              uVar31 = (uint)(byte)puVar1[1];
              puVar1[1] = (char)((((int)(param_6._1_1_ * uVar31) >> 8) - uVar31) * DAT_00dca3f8 +
                                 uVar31 * 0x100 >> 8);
              uVar31 = (uint)(byte)puVar1[2];
              puVar1[2] = (char)((((int)(uVar17 * uVar31) >> 8) - uVar31) * DAT_00dca3f8 +
                                 uVar31 * 0x100 >> 8);
            }
            param_2 = uVar21 + param_2;
            if (((uint)(param_2 - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)((param_3 - param_5) - iVar5) <= (uint)(iVar13 - iVar5))) {
              iVar20 = (param_3 - param_5) * iVar2 + iVar20;
              uVar21 = (uint)*(byte *)(iVar20 + param_2 * 4);
              puVar1 = (undefined1 *)(iVar20 + param_2 * 4);
              *puVar1 = (char)((((int)((param_6 & 0xff) * uVar21) >> 8) - uVar21) * DAT_00dca3f8 +
                               uVar21 * 0x100 >> 8);
              uVar21 = (uint)(byte)puVar1[1];
              puVar1[1] = (char)((((int)(param_6._1_1_ * uVar21) >> 8) - uVar21) * DAT_00dca3f8 +
                                 uVar21 * 0x100 >> 8);
              uVar21 = (uint)(byte)puVar1[2];
              puVar1[2] = (char)((((int)(uVar17 * uVar21) >> 8) - uVar21) * DAT_00dca3f8 +
                                 uVar21 * 0x100 >> 8);
              return;
            }
          }
        }
      }
    }
    else {
      iVar22 = (param_4 * param_4) / param_5;
      iVar15 = param_4 * -2;
      local_70 = iVar15 + 3;
      iVar4 = param_4 * -4;
      local_74 = iVar4 + 3;
      uVar21 = 0;
      iVar10 = 0;
      local_48 = 0;
      if (*(int *)(iVar8 + 0x20) == 0) {
        if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
          param_6 = ((param_6 >> 5 & 0x3f) * (DAT_00dca3fc >> 8 & 0xff) & 0xffffff07 |
                    (param_6 & 0x1f) * (DAT_00dca3fc & 0xff) >> 5) >> 3 |
                    (param_6 >> 8 & 0xfffff8) * (DAT_00dca3fc >> 0x10 & 0xff) & 0xfffff800;
        }
        iVar8 = 0;
        switch(DAT_00dca3f4) {
        case 1:
          if (DAT_00dca3f8 != 0xff) {
            if (DAT_00dca3f8 == 0) {
              return;
            }
            if (param_9 == 0) {
              uVar17 = iVar7 - DAT_00dca3e4;
              if (((uint)((param_2 - param_4) - DAT_00dca3e4) <= uVar17) &&
                 ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
                puVar26 = (ushort *)(iVar2 * param_3 + iVar20 + (param_2 - param_4) * 2);
                uVar12 = *puVar26;
                *puVar26 = ((uVar12 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                     DAT_00dca3f8 * 0x800)) * 0x20 |
                           ((uVar12 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                     DAT_00dca3f8 * 0x800)) * 0x800 |
                           (uVar12 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + DAT_00dca3f8 * 0x800
                                     );
              }
              iVar8 = (param_2 - param_8) + param_4;
              if (((uint)(iVar8 - iVar25) <= uVar17) &&
                 ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar26 = (ushort *)(iVar2 * param_3 + iVar20 + iVar8 * 2);
                uVar12 = *puVar26;
                *puVar26 = ((uVar12 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                     iVar23 * 0x800)) * 0x20 |
                           ((uVar12 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800
                                     )) * 0x800 |
                           (uVar12 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
              }
            }
            if (local_70 < 0) {
              local_48 = param_5;
              bVar3 = iVar22 <= param_5;
              if (bVar3) {
                local_48 = param_5 - iVar22;
              }
              uVar21 = (uint)bVar3;
              local_74 = local_74 + uVar21 * 4;
              local_70 = iVar15 + 5 + uVar21 * 4;
            }
            else {
              param_4 = param_4 + -1;
              bVar3 = true;
              if (local_74 < 0) {
                local_48 = param_5;
                if (iVar22 <= param_5) {
                  local_48 = param_5 - iVar22;
                }
                uVar21 = (uint)(iVar22 <= param_5);
                local_74 = (uVar21 - param_4) * 4;
                local_70 = iVar15 + 5 + local_74;
                local_74 = iVar4 + 5 + local_74;
              }
              else {
                local_70 = local_70 + param_4 * -4;
                local_74 = local_74 + param_4 * -4 + 2;
              }
            }
            if (0 < param_4) {
              local_14 = param_4 * 4;
              local_3c = (param_3 - iVar5) - uVar21;
              local_2c = ((param_4 - iVar25) - param_8) + param_2;
              local_28 = ((param_4 - param_8) + param_2) * 2;
              local_24 = (param_2 - iVar25) - param_4;
              local_38 = (param_3 - uVar21) * iVar2;
              local_20 = (param_2 - param_4) * 2;
              local_34 = ((uVar21 - iVar5) - param_9) + param_3;
              local_30 = ((uVar21 - param_9) + param_3) * iVar2;
              iVar8 = local_48;
              do {
                if (bVar3) {
                  uVar17 = iVar7 - iVar25;
                  if ((local_24 <= uVar17) && (local_34 <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_30 + local_20 + iVar20);
                    uVar12 = *puVar26;
                    *puVar26 = ((uVar12 >> 5 & 0x3f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                         iVar23 * 0x800)) * 0x20 |
                               ((uVar12 >> 0xb) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                         iVar23 * 0x800)) * 0x800 |
                               (uVar12 & 0x1f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                    iVar8 = local_48;
                  }
                  if ((local_2c <= uVar17) && (local_34 <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_30 + local_28 + iVar20);
                    uVar12 = *puVar26;
                    *puVar26 = ((uVar12 >> 5 & 0x3f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                         iVar23 * 0x800)) * 0x20 |
                               ((uVar12 >> 0xb) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                         iVar23 * 0x800)) * 0x800 |
                               (uVar12 & 0x1f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                    iVar8 = local_48;
                  }
                  if ((local_24 <= uVar17) && (local_3c <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_20 + local_38 + iVar20);
                    uVar12 = *puVar26;
                    *puVar26 = ((uVar12 >> 5 & 0x3f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                         iVar23 * 0x800)) * 0x20 |
                               ((uVar12 >> 0xb) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                         iVar23 * 0x800)) * 0x800 |
                               (uVar12 & 0x1f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                    iVar8 = local_48;
                  }
                  if ((local_2c <= uVar17) && (local_3c <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_38 + local_28 + iVar20);
                    uVar12 = *puVar26;
                    *puVar26 = ((uVar12 >> 5 & 0x3f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                         iVar23 * 0x800)) * 0x20 |
                               ((uVar12 >> 0xb) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                         iVar23 * 0x800)) * 0x800 |
                               (uVar12 & 0x1f) +
                               *(short *)(&DAT_00d4a6e0 +
                                         ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                    iVar8 = local_48;
                  }
                }
                if (local_70 < 0) {
                  local_48 = iVar8 + param_5;
                  bVar3 = iVar22 <= local_48;
                  if (bVar3) {
                    local_30 = local_30 + iVar2;
                    local_38 = local_38 + -iVar2;
                    local_34 = local_34 + 1;
                    local_3c = local_3c - 1;
                    uVar21 = uVar21 + 1;
                    local_48 = local_48 - iVar22;
                  }
                  local_74 = local_74 + uVar21 * 4;
                  local_70 = local_70 + 2 + uVar21 * 4;
                  iVar8 = local_48;
                }
                else {
                  local_24 = local_24 + 1;
                  local_2c = local_2c - 1;
                  local_20 = local_20 + 2;
                  local_28 = local_28 + -2;
                  param_4 = param_4 + -1;
                  bVar3 = true;
                  if (local_74 < 0) {
                    local_48 = iVar8 + param_5;
                    local_14 = local_14 + -4;
                    if (iVar22 <= local_48) {
                      local_30 = local_30 + iVar2;
                      local_34 = local_34 + 1;
                      local_38 = local_38 + -iVar2;
                      local_3c = local_3c - 1;
                      uVar21 = uVar21 + 1;
                      local_48 = local_48 - iVar22;
                    }
                    iVar8 = (uVar21 - param_4) * 4;
                    local_70 = local_70 + 2 + iVar8;
                    local_74 = local_74 + 2 + iVar8;
                    iVar8 = local_48;
                  }
                  else {
                    local_14 = local_14 + -4;
                    local_70 = local_70 - local_14;
                    local_74 = local_74 + (2 - local_14);
                  }
                }
              } while (0 < param_4);
            }
            if (param_8 != 0) {
              return;
            }
            if (((uint)((param_2 + param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((param_3 - uVar21) - iVar5 <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)((param_3 - uVar21) * iVar2 + iVar20 + (param_2 + param_4) * 2);
              uVar12 = *puVar26;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800))
                         * 0x800 | (uVar12 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 +
                                             iVar23 * 0x800);
            }
            param_2 = param_2 - param_4;
            param_3 = (uVar21 - param_9) + param_3;
            if ((uint)(iVar7 - iVar25) < (uint)(param_2 - iVar25)) {
              return;
            }
            if ((uint)(iVar13 - iVar5) < (uint)(param_3 - iVar5)) {
              return;
            }
            iVar20 = param_3 * iVar2 + iVar20;
            uVar12 = *(ushort *)(iVar20 + param_2 * 2);
            *(ushort *)(iVar20 + param_2 * 2) =
                 ((uVar12 >> 5 & 0x3f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 + iVar23 * 0x800)) *
                 0x20 | ((uVar12 >> 0xb) +
                        *(short *)(&DAT_00d4a6e0 +
                                  ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800))
                        * 0x800 |
                 (uVar12 & 0x1f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
            return;
          }
        case 0:
          if (param_9 == 0) {
            uVar17 = iVar7 - DAT_00dca3e4;
            if (((uint)((param_2 - param_4) - DAT_00dca3e4) <= uVar17) &&
               ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              *(ushort *)(iVar2 * param_3 + iVar20 + (param_2 - param_4) * 2) = (ushort)param_6;
            }
            iVar23 = (param_2 - param_8) + param_4;
            if (((uint)(iVar23 - iVar25) <= uVar17) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              *(ushort *)(iVar2 * param_3 + iVar20 + iVar23 * 2) = (ushort)param_6;
            }
          }
          if (local_70 < 0) {
            bVar3 = iVar22 <= param_5;
            iVar8 = param_5;
            if (bVar3) {
              iVar8 = param_5 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_4 = param_4 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              iVar8 = param_5;
              if (iVar22 <= param_5) {
                iVar8 = param_5 - iVar22;
              }
              uVar21 = (uint)(iVar22 <= param_5);
              local_74 = (uVar21 - param_4) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_4 * -4;
              local_74 = local_74 + param_4 * -4 + 2;
            }
          }
          if (0 < param_4) {
            local_14 = param_4 * 4;
            local_38 = (param_3 - iVar5) - uVar21;
            local_28 = ((param_4 - iVar25) - param_8) + param_2;
            local_24 = (param_2 - iVar25) - param_4;
            local_34 = (param_3 - uVar21) * iVar2;
            local_20 = (param_2 - param_4) * 2;
            iVar23 = ((param_4 - param_8) + param_2) * 2;
            local_30 = ((uVar21 - iVar5) - param_9) + param_3;
            local_2c = ((uVar21 - param_9) + param_3) * iVar2;
            do {
              if (bVar3) {
                uVar17 = iVar7 - iVar25;
                if ((local_24 <= uVar17) && (local_30 <= (uint)(iVar13 - iVar5))) {
                  *(ushort *)(local_2c + local_20 + iVar20) = (ushort)param_6;
                }
                if ((local_28 <= uVar17) && (local_30 <= (uint)(iVar13 - iVar5))) {
                  *(ushort *)(local_2c + iVar23 + iVar20) = (ushort)param_6;
                }
                if ((local_24 <= uVar17) && (local_38 <= (uint)(iVar13 - iVar5))) {
                  *(ushort *)(local_20 + local_34 + iVar20) = (ushort)param_6;
                }
                if ((local_28 <= uVar17) && (local_38 <= (uint)(iVar13 - iVar5))) {
                  *(ushort *)(local_34 + iVar23 + iVar20) = (ushort)param_6;
                }
              }
              if (local_70 < 0) {
                iVar8 = iVar8 + param_5;
                bVar3 = iVar22 <= iVar8;
                if (bVar3) {
                  local_2c = local_2c + iVar2;
                  local_34 = local_34 + -iVar2;
                  local_30 = local_30 + 1;
                  local_38 = local_38 - 1;
                  uVar21 = uVar21 + 1;
                  iVar8 = iVar8 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
              }
              else {
                local_20 = local_20 + 2;
                bVar3 = true;
                local_24 = local_24 + 1;
                local_28 = local_28 - 1;
                iVar23 = iVar23 + -2;
                if (local_74 < 0) {
                  iVar8 = iVar8 + param_5;
                  local_14 = local_14 + -4;
                  param_4 = param_4 + -1;
                  if (iVar22 <= iVar8) {
                    local_2c = local_2c + iVar2;
                    local_30 = local_30 + 1;
                    local_34 = local_34 + -iVar2;
                    local_38 = local_38 - 1;
                    uVar21 = uVar21 + 1;
                    iVar8 = iVar8 - iVar22;
                  }
                  iVar15 = (uVar21 - param_4) * 4;
                  local_70 = local_70 + 2 + iVar15;
                  local_74 = local_74 + 2 + iVar15;
                }
                else {
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  param_4 = param_4 + -1;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_4);
          }
          if (param_8 == 0) {
            if (((uint)((param_2 + param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((param_3 - uVar21) - iVar5 <= (uint)(iVar13 - iVar5))) {
              *(ushort *)((param_3 - uVar21) * iVar2 + iVar20 + (param_2 + param_4) * 2) =
                   (ushort)param_6;
            }
            param_3 = (uVar21 - param_9) + param_3;
            if (((uint)((param_2 - param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              *(ushort *)(param_3 * iVar2 + iVar20 + (param_2 - param_4) * 2) = (ushort)param_6;
              return;
            }
          }
          break;
        case 2:
          if (DAT_00dca3f8 != 0) {
            if (param_9 == 0) {
              uVar17 = iVar7 - DAT_00dca3e4;
              if (((uint)((param_2 - param_4) - DAT_00dca3e4) <= uVar17) &&
                 ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
                puVar26 = (ushort *)(iVar2 * param_3 + iVar20 + (param_2 - param_4) * 2);
                uVar28 = (*(short *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_6 >> 0xb)) * 0x40
                         + *(short *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_6 >> 5 & 0x3f)))
                         * 0x20 + *(short *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_6 & 0x1f)
                                            );
                uVar12 = *puVar26;
                uVar31 = (uVar12 & 0xf7def7df) + (uVar28 & 0xf7def7df);
                uVar27 = uVar31 & 0x8210820;
                *puVar26 = (short)uVar27 - (short)(uVar27 >> 5) | (uVar12 | uVar28) & 0x820 |
                           (ushort)uVar31;
              }
              iVar8 = (param_2 - param_8) + param_4;
              if (((uint)(iVar8 - iVar25) <= uVar17) &&
                 ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar26 = (ushort *)(iVar2 * param_3 + iVar20 + iVar8 * 2);
                uVar28 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                uVar12 = *puVar26;
                uVar17 = (uVar12 & 0xf7def7df) + (uVar28 & 0xf7def7df);
                uVar31 = uVar17 & 0x8210820;
                *puVar26 = (short)uVar31 - (short)(uVar31 >> 5) | (uVar12 | uVar28) & 0x820 |
                           (ushort)uVar17;
              }
            }
            iVar8 = 0;
            if (local_70 < 0) {
              bVar3 = iVar22 <= param_5;
              iVar8 = param_5;
              if (bVar3) {
                iVar8 = param_5 - iVar22;
              }
              uVar21 = (uint)bVar3;
              local_74 = local_74 + uVar21 * 4;
              local_70 = iVar15 + 5 + uVar21 * 4;
            }
            else {
              param_4 = param_4 + -1;
              bVar3 = true;
              if (local_74 < 0) {
                iVar8 = param_5;
                if (iVar22 <= param_5) {
                  iVar8 = param_5 - iVar22;
                }
                uVar21 = (uint)(iVar22 <= param_5);
                local_74 = (uVar21 - param_4) * 4;
                local_70 = iVar15 + 5 + local_74;
                local_74 = iVar4 + 5 + local_74;
              }
              else {
                local_70 = local_70 + param_4 * -4;
                local_74 = local_74 + param_4 * -4 + 2;
              }
            }
            if (0 < param_4) {
              local_14 = param_4 * 4;
              local_3c = (param_3 - iVar5) - uVar21;
              local_2c = ((param_4 - iVar25) - param_8) + param_2;
              local_28 = ((param_4 - param_8) + param_2) * 2;
              local_24 = (param_2 - iVar25) - param_4;
              local_38 = (param_3 - uVar21) * iVar2;
              local_20 = (param_2 - param_4) * 2;
              local_34 = ((uVar21 - iVar5) - param_9) + param_3;
              local_30 = ((uVar21 - param_9) + param_3) * iVar2;
              do {
                if (bVar3) {
                  uVar17 = iVar7 - iVar25;
                  if ((local_24 <= uVar17) && (local_34 <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_30 + local_20 + iVar20);
                    uVar28 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                             *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) *
                             0x20 + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                    uVar12 = *puVar26;
                    uVar31 = (uVar12 & 0xf7def7df) + (uVar28 & 0xf7def7df);
                    uVar27 = uVar31 & 0x8210820;
                    *puVar26 = (short)uVar27 - (short)(uVar27 >> 5) | (uVar12 | uVar28) & 0x820 |
                               (ushort)uVar31;
                  }
                  if ((local_2c <= uVar17) && (local_34 <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_30 + local_28 + iVar20);
                    uVar28 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                             *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) *
                             0x20 + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                    uVar12 = *puVar26;
                    uVar31 = (uVar12 & 0xf7def7df) + (uVar28 & 0xf7def7df);
                    uVar27 = uVar31 & 0x8210820;
                    *puVar26 = (short)uVar27 - (short)(uVar27 >> 5) | (uVar12 | uVar28) & 0x820 |
                               (ushort)uVar31;
                  }
                  if ((local_24 <= uVar17) && (local_3c <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_20 + local_38 + iVar20);
                    uVar28 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                             *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) *
                             0x20 + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                    uVar12 = *puVar26;
                    uVar31 = (uVar12 & 0xf7def7df) + (uVar28 & 0xf7def7df);
                    uVar27 = uVar31 & 0x8210820;
                    *puVar26 = (short)uVar27 - (short)(uVar27 >> 5) | (uVar12 | uVar28) & 0x820 |
                               (ushort)uVar31;
                  }
                  if ((local_2c <= uVar17) && (local_3c <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_38 + local_28 + iVar20);
                    uVar28 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                             *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) *
                             0x20 + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                    uVar12 = *puVar26;
                    uVar17 = (uVar12 & 0xf7def7df) + (uVar28 & 0xf7def7df);
                    uVar31 = uVar17 & 0x8210820;
                    *puVar26 = (short)uVar31 - (short)(uVar31 >> 5) | (uVar12 | uVar28) & 0x820 |
                               (ushort)uVar17;
                  }
                }
                if (local_70 < 0) {
                  iVar8 = iVar8 + param_5;
                  bVar3 = iVar22 <= iVar8;
                  if (bVar3) {
                    local_30 = local_30 + iVar2;
                    local_38 = local_38 + -iVar2;
                    local_34 = local_34 + 1;
                    local_3c = local_3c - 1;
                    uVar21 = uVar21 + 1;
                    iVar8 = iVar8 - iVar22;
                  }
                  local_74 = local_74 + uVar21 * 4;
                  local_70 = local_70 + 2 + uVar21 * 4;
                }
                else {
                  local_24 = local_24 + 1;
                  local_2c = local_2c - 1;
                  local_20 = local_20 + 2;
                  local_28 = local_28 + -2;
                  param_4 = param_4 + -1;
                  bVar3 = true;
                  if (local_74 < 0) {
                    iVar8 = iVar8 + param_5;
                    local_14 = local_14 + -4;
                    if (iVar22 <= iVar8) {
                      local_30 = local_30 + iVar2;
                      local_34 = local_34 + 1;
                      local_38 = local_38 + -iVar2;
                      local_3c = local_3c - 1;
                      uVar21 = uVar21 + 1;
                      iVar8 = iVar8 - iVar22;
                    }
                    iVar15 = (uVar21 - param_4) * 4;
                    local_70 = local_70 + 2 + iVar15;
                    local_74 = local_74 + 2 + iVar15;
                  }
                  else {
                    local_14 = local_14 + -4;
                    local_70 = local_70 - local_14;
                    local_74 = local_74 + (2 - local_14);
                  }
                }
              } while (0 < param_4);
            }
            if (param_8 == 0) {
              if (((uint)((param_2 + param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
                 ((param_3 - uVar21) - iVar5 <= (uint)(iVar13 - iVar5))) {
                puVar26 = (ushort *)((param_3 - uVar21) * iVar2 + iVar20 + (param_2 + param_4) * 2);
                uVar28 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                uVar12 = *puVar26;
                uVar17 = (uVar12 & 0xf7def7df) + (uVar28 & 0xf7def7df);
                uVar31 = uVar17 & 0x8210820;
                *puVar26 = (short)uVar31 - (short)(uVar31 >> 5) | (uVar12 | uVar28) & 0x820 |
                           (ushort)uVar17;
              }
              param_3 = (uVar21 - param_9) + param_3;
              if (((uint)((param_2 - param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
                 ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar26 = (ushort *)(param_3 * iVar2 + iVar20 + (param_2 - param_4) * 2);
                uVar12 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
LAB_0078992c:
                uVar17 = (*puVar26 & 0xf7def7df) + (uVar12 & 0xf7def7df);
                uVar21 = uVar17 & 0x8210820;
                *puVar26 = (short)uVar21 - (short)(uVar21 >> 5) | (*puVar26 | uVar12) & 0x820 |
                           (ushort)uVar17;
                return;
              }
            }
          }
          break;
        case 3:
          if (DAT_00dca3f8 != 0) {
            if (param_9 == 0) {
              uVar17 = iVar7 - DAT_00dca3e4;
              if (((uint)((param_2 - param_4) - DAT_00dca3e4) <= uVar17) &&
                 ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
                puVar26 = (ushort *)(iVar2 * param_3 + iVar20 + (param_2 - param_4) * 2);
                uVar27 = (*puVar26 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 +
                                              DAT_00dca3f8 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                                   *(short *)(&DAT_00d0a2e0 +
                                             DAT_00dca3f8 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20 +
                                  *(short *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_6 & 0x1f)
                                            )) & 0xf7def7df);
                uVar31 = uVar27 & 0x8210820;
                *puVar26 = (short)uVar31 - (short)(uVar31 >> 5) & (ushort)uVar27;
              }
              iVar8 = (param_2 - param_8) + param_4;
              if (((uint)(iVar8 - iVar25) <= uVar17) &&
                 ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar26 = (ushort *)(iVar2 * param_3 + iVar20 + iVar8 * 2);
                uVar31 = (*puVar26 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f))) &
                         0xf7def7df);
                uVar17 = uVar31 & 0x8210820;
                *puVar26 = (short)uVar17 - (short)(uVar17 >> 5) & (ushort)uVar31;
              }
            }
            iVar8 = 0;
            if (local_70 < 0) {
              bVar3 = iVar22 <= param_5;
              iVar8 = param_5;
              if (bVar3) {
                iVar8 = param_5 - iVar22;
              }
              uVar21 = (uint)bVar3;
              local_74 = local_74 + uVar21 * 4;
              local_70 = iVar15 + 5 + uVar21 * 4;
            }
            else {
              param_4 = param_4 + -1;
              bVar3 = true;
              if (local_74 < 0) {
                iVar8 = param_5;
                if (iVar22 <= param_5) {
                  iVar8 = param_5 - iVar22;
                }
                uVar21 = (uint)(iVar22 <= param_5);
                local_74 = (uVar21 - param_4) * 4;
                local_70 = iVar15 + 5 + local_74;
                local_74 = iVar4 + 5 + local_74;
              }
              else {
                local_70 = local_70 + param_4 * -4;
                local_74 = local_74 + param_4 * -4 + 2;
              }
            }
            if (0 < param_4) {
              local_14 = param_4 * 4;
              local_3c = (param_3 - iVar5) - uVar21;
              local_2c = ((param_4 - iVar25) - param_8) + param_2;
              local_28 = ((param_4 - param_8) + param_2) * 2;
              local_24 = (param_2 - iVar25) - param_4;
              local_38 = (param_3 - uVar21) * iVar2;
              local_20 = (param_2 - param_4) * 2;
              local_34 = ((uVar21 - iVar5) - param_9) + param_3;
              local_30 = ((uVar21 - param_9) + param_3) * iVar2;
              do {
                if (bVar3) {
                  uVar17 = iVar7 - iVar25;
                  if ((local_24 <= uVar17) && (local_34 <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_30 + local_20 + iVar20);
                    uVar31 = (*puVar26 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)
                                                  ) * 0x40 +
                                       *(short *)(&DAT_00d0a2e0 +
                                                 iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20 +
                                      *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f)))
                             & 0xf7def7df);
                    uVar27 = uVar31 & 0x8210820;
                    *puVar26 = (short)uVar27 - (short)(uVar27 >> 5) & (ushort)uVar31;
                  }
                  if ((local_2c <= uVar17) && (local_34 <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_30 + local_28 + iVar20);
                    uVar31 = (*puVar26 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)
                                                  ) * 0x40 +
                                       *(short *)(&DAT_00d0a2e0 +
                                                 iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20 +
                                      *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f)))
                             & 0xf7def7df);
                    uVar27 = uVar31 & 0x8210820;
                    *puVar26 = (short)uVar27 - (short)(uVar27 >> 5) & (ushort)uVar31;
                  }
                  if ((local_24 <= uVar17) && (local_3c <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_20 + local_38 + iVar20);
                    uVar31 = (*puVar26 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)
                                                  ) * 0x40 +
                                       *(short *)(&DAT_00d0a2e0 +
                                                 iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20 +
                                      *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f)))
                             & 0xf7def7df);
                    uVar27 = uVar31 & 0x8210820;
                    *puVar26 = (short)uVar27 - (short)(uVar27 >> 5) & (ushort)uVar31;
                  }
                  if ((local_2c <= uVar17) && (local_3c <= (uint)(iVar13 - iVar5))) {
                    puVar26 = (ushort *)(local_38 + local_28 + iVar20);
                    uVar17 = (*puVar26 | 0x8210820) -
                             ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)
                                                  ) * 0x40 +
                                       *(short *)(&DAT_00d0a2e0 +
                                                 iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20 +
                                      *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f)))
                             & 0xf7def7df);
                    uVar31 = uVar17 & 0x8210820;
                    *puVar26 = (short)uVar31 - (short)(uVar31 >> 5) & (ushort)uVar17;
                  }
                }
                if (local_70 < 0) {
                  iVar8 = iVar8 + param_5;
                  bVar3 = iVar22 <= iVar8;
                  if (bVar3) {
                    local_30 = local_30 + iVar2;
                    local_38 = local_38 + -iVar2;
                    local_34 = local_34 + 1;
                    local_3c = local_3c - 1;
                    uVar21 = uVar21 + 1;
                    iVar8 = iVar8 - iVar22;
                  }
                  local_74 = local_74 + uVar21 * 4;
                  local_70 = local_70 + 2 + uVar21 * 4;
                }
                else {
                  local_24 = local_24 + 1;
                  local_2c = local_2c - 1;
                  local_20 = local_20 + 2;
                  local_28 = local_28 + -2;
                  param_4 = param_4 + -1;
                  bVar3 = true;
                  if (local_74 < 0) {
                    iVar8 = iVar8 + param_5;
                    local_14 = local_14 + -4;
                    if (iVar22 <= iVar8) {
                      local_34 = local_34 + 1;
                      local_3c = local_3c - 1;
                      uVar21 = uVar21 + 1;
                      local_30 = local_30 + iVar2;
                      local_38 = local_38 + -iVar2;
                      iVar8 = iVar8 - iVar22;
                    }
                    iVar15 = (uVar21 - param_4) * 4;
                    local_70 = local_70 + 2 + iVar15;
                    local_74 = local_74 + 2 + iVar15;
                  }
                  else {
                    local_14 = local_14 + -4;
                    local_70 = local_70 - local_14;
                    local_74 = local_74 + (2 - local_14);
                  }
                }
              } while (0 < param_4);
            }
            if (param_8 == 0) {
              if (((uint)((param_2 + param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
                 ((param_3 - uVar21) - iVar5 <= (uint)(iVar13 - iVar5))) {
                puVar26 = (ushort *)((param_3 - uVar21) * iVar2 + iVar20 + (param_2 + param_4) * 2);
                uVar31 = (*puVar26 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f))) &
                         0xf7def7df);
                uVar17 = uVar31 & 0x8210820;
                *puVar26 = (short)uVar17 - (short)(uVar17 >> 5) & (ushort)uVar31;
              }
              param_3 = (uVar21 - param_9) + param_3;
              if (((uint)((param_2 - param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
                 ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar26 = (ushort *)(param_3 * iVar2 + iVar20 + (param_2 - param_4) * 2);
LAB_0078a0a1:
                uVar17 = (*puVar26 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f))) &
                         0xf7def7df);
                uVar21 = uVar17 & 0x8210820;
                *puVar26 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar17;
                return;
              }
            }
          }
          break;
        case 4:
          if (param_9 == 0) {
            uVar17 = iVar7 - DAT_00dca3e4;
            if (((uint)((param_2 - param_4) - DAT_00dca3e4) <= uVar17) &&
               ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              puVar26 = (ushort *)(iVar2 * param_3 + iVar20 + (param_2 - param_4) * 2);
              uVar31 = (uint)*puVar26;
              *puVar26 = (ushort)((uVar31 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_6 & 0xf800) * (uVar31 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar31 & 0x1f) * (param_6 & 0x1f) >> 5);
            }
            iVar23 = (param_2 - param_8) + param_4;
            if (((uint)(iVar23 - iVar25) <= uVar17) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)(iVar2 * param_3 + iVar20 + iVar23 * 2);
              uVar17 = (uint)*puVar26;
              *puVar26 = (ushort)((uVar17 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_6 & 0xf800) * (uVar17 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar17 & 0x1f) * (param_6 & 0x1f) >> 5);
            }
          }
          if (local_70 < 0) {
            bVar3 = iVar22 <= param_5;
            iVar8 = param_5;
            if (bVar3) {
              iVar8 = param_5 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_4 = param_4 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              iVar8 = param_5;
              if (iVar22 <= param_5) {
                iVar8 = param_5 - iVar22;
              }
              uVar21 = (uint)(iVar22 <= param_5);
              local_74 = (uVar21 - param_4) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_4 * -4;
              local_74 = local_74 + param_4 * -4 + 2;
            }
          }
          if (0 < param_4) {
            local_14 = param_4 * 4;
            local_3c = (param_3 - iVar5) - uVar21;
            local_2c = ((param_4 - iVar25) - param_8) + param_2;
            local_28 = ((param_4 - param_8) + param_2) * 2;
            local_24 = (param_2 - iVar25) - param_4;
            local_38 = (param_3 - uVar21) * iVar2;
            local_20 = (param_2 - param_4) * 2;
            local_34 = ((uVar21 - iVar5) - param_9) + param_3;
            local_30 = ((uVar21 - param_9) + param_3) * iVar2;
            do {
              if (bVar3) {
                uVar17 = iVar7 - iVar25;
                if ((local_24 <= uVar17) && (local_34 <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(iVar20 + local_30 + local_20);
                  uVar31 = (uint)*puVar26;
                  *puVar26 = (ushort)((uVar31 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                             (ushort)((param_6 & 0xf800) * (uVar31 & 0xf800) >> 0x10) & 0xf800 |
                             (ushort)((uVar31 & 0x1f) * (param_6 & 0x1f) >> 5);
                }
                if ((local_2c <= uVar17) && (local_34 <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(iVar20 + local_28 + local_30);
                  uVar31 = (uint)*puVar26;
                  *puVar26 = (ushort)((uVar31 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                             (ushort)((param_6 & 0xf800) * (uVar31 & 0xf800) >> 0x10) & 0xf800 |
                             (ushort)((uVar31 & 0x1f) * (param_6 & 0x1f) >> 5);
                }
                if ((local_24 <= uVar17) && (local_3c <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(iVar20 + local_38 + local_20);
                  uVar31 = (uint)*puVar26;
                  *puVar26 = (ushort)((uVar31 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                             (ushort)((param_6 & 0xf800) * (uVar31 & 0xf800) >> 0x10) & 0xf800 |
                             (ushort)((uVar31 & 0x1f) * (param_6 & 0x1f) >> 5);
                }
                if ((local_2c <= uVar17) && (local_3c <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_38 + local_28 + iVar20);
                  uVar17 = (uint)*puVar26;
                  *puVar26 = (ushort)((uVar17 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                             (ushort)((param_6 & 0xf800) * (uVar17 & 0xf800) >> 0x10) & 0xf800 |
                             (ushort)((uVar17 & 0x1f) * (param_6 & 0x1f) >> 5);
                }
              }
              if (local_70 < 0) {
                iVar8 = iVar8 + param_5;
                bVar3 = iVar22 <= iVar8;
                if (bVar3) {
                  local_30 = local_30 + iVar2;
                  local_38 = local_38 + -iVar2;
                  local_34 = local_34 + 1;
                  local_3c = local_3c - 1;
                  uVar21 = uVar21 + 1;
                  iVar8 = iVar8 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
              }
              else {
                bVar3 = true;
                local_24 = local_24 + 1;
                local_2c = local_2c - 1;
                if (local_74 < 0) {
                  iVar8 = iVar8 + param_5;
                  local_14 = local_14 + -4;
                  local_20 = local_20 + 2;
                  local_28 = local_28 + -2;
                  param_4 = param_4 + -1;
                  if (iVar22 <= iVar8) {
                    local_30 = local_30 + iVar2;
                    local_34 = local_34 + 1;
                    local_38 = local_38 + -iVar2;
                    local_3c = local_3c - 1;
                    uVar21 = uVar21 + 1;
                    iVar8 = iVar8 - iVar22;
                  }
                  iVar23 = (uVar21 - param_4) * 4;
                  local_70 = local_70 + 2 + iVar23;
                  local_74 = local_74 + 2 + iVar23;
                }
                else {
                  local_20 = local_20 + 2;
                  local_28 = local_28 + -2;
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  param_4 = param_4 + -1;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_4);
          }
          if (param_8 == 0) {
            if (((uint)((param_2 + param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((param_3 - uVar21) - iVar5 <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)((param_3 - uVar21) * iVar2 + iVar20 + (param_2 + param_4) * 2);
              uVar17 = (uint)*puVar26;
              *puVar26 = (ushort)((uVar17 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_6 & 0xf800) * (uVar17 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar17 & 0x1f) * (param_6 & 0x1f) >> 5);
            }
            param_3 = (uVar21 - param_9) + param_3;
            if (((uint)((param_2 - param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)(param_3 * iVar2 + iVar20 + (param_2 - param_4) * 2);
LAB_0078a7f0:
              uVar21 = (uint)*puVar26;
              *puVar26 = (ushort)((uVar21 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                         (ushort)((param_6 & 0xf800) * (uVar21 & 0xf800) >> 0x10) & 0xf800 |
                         (ushort)((uVar21 & 0x1f) * (param_6 & 0x1f) >> 5);
              return;
            }
          }
          break;
        case 10:
          if (param_9 == 0) {
            uVar17 = iVar7 - DAT_00dca3e4;
            if (((uint)((param_2 - param_4) - DAT_00dca3e4) <= uVar17) &&
               ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              puVar26 = (ushort *)(iVar2 * param_3 + iVar20 + (param_2 - param_4) * 2);
              uVar12 = *puVar26;
              uVar31 = ~param_6 & 0xffff;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar31 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                   DAT_00dca3f8 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar31 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                   DAT_00dca3f8 * 0x800)) * 0x800 |
                         (uVar12 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + DAT_00dca3f8 * 0x800)
              ;
            }
            iVar8 = (param_2 - param_8) + param_4;
            if (((uint)(iVar8 - iVar25) <= uVar17) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)(iVar2 * param_3 + iVar20 + iVar8 * 2);
              uVar12 = *puVar26;
              uVar17 = ~param_6 & 0xffff;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar17 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar17 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800))
                         * 0x800 | (uVar12 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 +
                                             iVar23 * 0x800);
            }
          }
          if (local_70 < 0) {
            local_48 = param_5;
            bVar3 = iVar22 <= param_5;
            if (bVar3) {
              local_48 = param_5 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_4 = param_4 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              local_48 = param_5;
              if (iVar22 <= param_5) {
                local_48 = param_5 - iVar22;
              }
              uVar21 = (uint)(iVar22 <= param_5);
              local_74 = (uVar21 - param_4) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_4 * -4;
              local_74 = local_74 + param_4 * -4 + 2;
            }
          }
          if (0 < param_4) {
            local_14 = param_4 * 4;
            local_40 = (param_3 - iVar5) - uVar21;
            local_2c = ((param_4 - iVar25) - param_8) + param_2;
            local_28 = ((param_4 - param_8) + param_2) * 2;
            local_24 = (param_2 - iVar25) - param_4;
            local_3c = (param_3 - uVar21) * iVar2;
            local_20 = (param_2 - param_4) * 2;
            local_34 = ((uVar21 - iVar5) - param_9) + param_3;
            local_30 = ((uVar21 - param_9) + param_3) * iVar2;
            iVar8 = local_48;
            do {
              if (bVar3) {
                uVar17 = iVar7 - iVar25;
                if ((local_24 <= uVar17) && (local_34 <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_30 + local_20 + iVar20);
                  uVar12 = *puVar26;
                  uVar31 = ~param_6 & 0xffff;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar31 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar31 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                       iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
                if ((local_2c <= uVar17) && (local_34 <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_30 + local_28 + iVar20);
                  uVar12 = *puVar26;
                  uVar31 = ~param_6 & 0xffff;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar31 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar31 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                       iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
                if ((local_24 <= uVar17) && (local_40 <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_20 + local_3c + iVar20);
                  uVar12 = *puVar26;
                  uVar31 = ~param_6 & 0xffff;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar31 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar31 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                       iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
                if ((local_2c <= uVar17) && (local_40 <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_3c + local_28 + iVar20);
                  uVar12 = *puVar26;
                  uVar17 = ~param_6 & 0xffff;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar17 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((uVar17 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                       iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
              }
              if (local_70 < 0) {
                local_48 = iVar8 + param_5;
                bVar3 = iVar22 <= local_48;
                if (bVar3) {
                  local_30 = local_30 + iVar2;
                  local_3c = local_3c + -iVar2;
                  local_34 = local_34 + 1;
                  local_40 = local_40 - 1;
                  uVar21 = uVar21 + 1;
                  local_48 = local_48 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
                iVar8 = local_48;
              }
              else {
                local_24 = local_24 + 1;
                local_2c = local_2c - 1;
                local_20 = local_20 + 2;
                local_28 = local_28 + -2;
                param_4 = param_4 + -1;
                bVar3 = true;
                if (local_74 < 0) {
                  local_48 = iVar8 + param_5;
                  local_14 = local_14 + -4;
                  if (iVar22 <= local_48) {
                    local_30 = local_30 + iVar2;
                    local_34 = local_34 + 1;
                    local_3c = local_3c + -iVar2;
                    local_40 = local_40 - 1;
                    uVar21 = uVar21 + 1;
                    local_48 = local_48 - iVar22;
                  }
                  iVar8 = (uVar21 - param_4) * 4;
                  local_70 = local_70 + 2 + iVar8;
                  local_74 = local_74 + 2 + iVar8;
                  iVar8 = local_48;
                }
                else {
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_4);
          }
          if (param_8 == 0) {
            if (((uint)((param_2 + param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((param_3 - uVar21) - iVar5 <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)((param_3 - uVar21) * iVar2 + iVar20 + (param_2 + param_4) * 2);
              uVar12 = *puVar26;
              uVar17 = ~param_6 & 0xffff;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar17 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((uVar17 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800))
                         * 0x800 | (uVar12 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 +
                                             iVar23 * 0x800);
            }
            param_2 = param_2 - param_4;
            param_3 = (uVar21 - param_9) + param_3;
            if (((uint)(param_2 - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              iVar20 = param_3 * iVar2 + iVar20;
              uVar12 = *(ushort *)(iVar20 + param_2 * 2);
              uVar21 = ~param_6 & 0xffff;
              *(ushort *)(iVar20 + param_2 * 2) =
                   ((uVar12 >> 5 & 0x3f) +
                   *(short *)(&DAT_00d4a6e0 +
                             ((uVar21 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 + iVar23 * 0x800)) *
                   0x20 | ((uVar12 >> 0xb) +
                          *(short *)(&DAT_00d4a6e0 +
                                    ((uVar21 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800))
                          * 0x800 |
                   (uVar12 & 0x1f) +
                   *(short *)(&DAT_00d4a6e0 +
                             ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
              return;
            }
          }
          break;
        case 0xb:
          if (param_9 == 0) {
            uVar17 = iVar7 - DAT_00dca3e4;
            if (((uint)((param_2 - param_4) - DAT_00dca3e4) <= uVar17) &&
               ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              puVar26 = (ushort *)(iVar2 * param_3 + iVar20 + (param_2 - param_4) * 2);
              uVar12 = *puVar26;
              uVar31 = uVar12 >> 5 & 0x3f;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 >> 5 & 0x3f) * uVar31 >> 6) - uVar31) * 4 +
                                   DAT_00dca3f8 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                   (uint)(uVar12 >> 0xb)) * 4 + DAT_00dca3f8 * 0x800)) * 0x800 |
                         (uVar12 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f)) * 4
                                   + DAT_00dca3f8 * 0x800);
            }
            iVar8 = (param_2 - param_8) + param_4;
            if (((uint)(iVar8 - iVar25) <= uVar17) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)(iVar2 * param_3 + iVar20 + iVar8 * 2);
              uVar12 = *puVar26;
              uVar17 = uVar12 >> 5 & 0x3f;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 >> 5 & 0x3f) * uVar17 >> 6) - uVar17) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                   (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                         (uVar12 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f)) * 4
                                   + iVar23 * 0x800);
            }
          }
          if (local_70 < 0) {
            local_48 = param_5;
            bVar3 = iVar22 <= param_5;
            if (bVar3) {
              local_48 = param_5 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_4 = param_4 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              local_48 = param_5;
              if (iVar22 <= param_5) {
                local_48 = param_5 - iVar22;
              }
              uVar21 = (uint)(iVar22 <= param_5);
              local_74 = (uVar21 - param_4) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_4 * -4;
              local_74 = local_74 + param_4 * -4 + 2;
            }
          }
          if (0 < param_4) {
            local_14 = param_4 * 4;
            local_40 = (param_3 - iVar5) - uVar21;
            local_2c = ((param_4 - iVar25) - param_8) + param_2;
            local_28 = ((param_4 - param_8) + param_2) * 2;
            local_24 = (param_2 - iVar25) - param_4;
            local_3c = (param_3 - uVar21) * iVar2;
            local_20 = (param_2 - param_4) * 2;
            local_34 = ((uVar21 - iVar5) - param_9) + param_3;
            local_30 = ((uVar21 - param_9) + param_3) * iVar2;
            iVar8 = local_48;
            do {
              if (bVar3) {
                uVar17 = iVar7 - iVar25;
                if ((local_24 <= uVar17) && (local_34 <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_30 + local_20 + iVar20);
                  uVar12 = *puVar26;
                  uVar31 = uVar12 >> 5 & 0x3f;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 5 & 0x3f) * uVar31 >> 6) - uVar31) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                       (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f))
                                       * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
                if ((local_2c <= uVar17) && (local_34 <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_30 + local_28 + iVar20);
                  uVar12 = *puVar26;
                  uVar31 = uVar12 >> 5 & 0x3f;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 5 & 0x3f) * uVar31 >> 6) - uVar31) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                       (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f))
                                       * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
                if ((local_24 <= uVar17) && (local_40 <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_20 + local_3c + iVar20);
                  uVar12 = *puVar26;
                  uVar31 = uVar12 >> 5 & 0x3f;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 5 & 0x3f) * uVar31 >> 6) - uVar31) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                       (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f))
                                       * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
                if ((local_2c <= uVar17) && (local_40 <= (uint)(iVar13 - iVar5))) {
                  puVar26 = (ushort *)(local_3c + local_28 + iVar20);
                  uVar12 = *puVar26;
                  uVar17 = uVar12 >> 5 & 0x3f;
                  *puVar26 = ((uVar12 >> 5 & 0x3f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 5 & 0x3f) * uVar17 >> 6) - uVar17) * 4 +
                                       iVar23 * 0x800)) * 0x20 |
                             ((uVar12 >> 0xb) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                       (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                             (uVar12 & 0x1f) +
                             *(short *)(&DAT_00d4a6e0 +
                                       (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f))
                                       * 4 + iVar23 * 0x800);
                  iVar8 = local_48;
                }
              }
              if (local_70 < 0) {
                local_48 = iVar8 + param_5;
                bVar3 = iVar22 <= local_48;
                if (bVar3) {
                  local_30 = local_30 + iVar2;
                  local_3c = local_3c + -iVar2;
                  local_34 = local_34 + 1;
                  local_40 = local_40 - 1;
                  uVar21 = uVar21 + 1;
                  local_48 = local_48 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
                iVar8 = local_48;
              }
              else {
                local_24 = local_24 + 1;
                local_2c = local_2c - 1;
                local_20 = local_20 + 2;
                local_28 = local_28 + -2;
                param_4 = param_4 + -1;
                bVar3 = true;
                if (local_74 < 0) {
                  local_48 = iVar8 + param_5;
                  local_14 = local_14 + -4;
                  if (iVar22 <= local_48) {
                    local_30 = local_30 + iVar2;
                    local_34 = local_34 + 1;
                    local_3c = local_3c + -iVar2;
                    local_40 = local_40 - 1;
                    uVar21 = uVar21 + 1;
                    local_48 = local_48 - iVar22;
                  }
                  iVar8 = (uVar21 - param_4) * 4;
                  local_70 = local_70 + 2 + iVar8;
                  local_74 = local_74 + 2 + iVar8;
                  iVar8 = local_48;
                }
                else {
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_4);
          }
          if (param_8 == 0) {
            if (((uint)((param_2 + param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((param_3 - uVar21) - iVar5 <= (uint)(iVar13 - iVar5))) {
              puVar26 = (ushort *)((param_3 - uVar21) * iVar2 + iVar20 + (param_2 + param_4) * 2);
              uVar12 = *puVar26;
              uVar17 = uVar12 >> 5 & 0x3f;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 >> 5 & 0x3f) * uVar17 >> 6) - uVar17) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                   (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                         (uVar12 & 0x1f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f)) * 4
                                   + iVar23 * 0x800);
            }
            param_2 = param_2 - param_4;
            param_3 = (uVar21 - param_9) + param_3;
            if (((uint)(param_2 - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              iVar20 = param_3 * iVar2 + iVar20;
              uVar12 = *(ushort *)(iVar20 + param_2 * 2);
              local_68 = (uint *)(iVar20 + param_2 * 2);
LAB_0078b155:
              uVar21 = uVar12 >> 5 & 0x3f;
              *(ushort *)local_68 =
                   ((uVar12 >> 5 & 0x3f) +
                   *(short *)(&DAT_00d4a6e0 +
                             (((param_6 >> 5 & 0x3f) * uVar21 >> 6) - uVar21) * 4 + iVar23 * 0x800))
                   * 0x20 | ((uVar12 >> 0xb) +
                            *(short *)(&DAT_00d4a6e0 +
                                      (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                      (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                   (uVar12 & 0x1f) +
                   *(short *)(&DAT_00d4a6e0 +
                             (((param_6 & 0x1f) * (uVar12 & 0x1f) >> 5) - (uVar12 & 0x1f)) * 4 +
                             iVar23 * 0x800);
              return;
            }
          }
        }
      }
      else if (*(int *)(iVar8 + 0x20) == 1) {
        if ((DAT_00dca3fc & 0xffffff) == 0xffffff) {
          uVar17 = (uint)param_6._2_1_;
        }
        else {
          iVar8 = (uint)param_6._2_1_ * (DAT_00dca3fc >> 0x10 & 0xff);
          uVar17 = iVar8 >> 8;
          param_6 = CONCAT31(CONCAT12(param_6._3_1_,
                                      CONCAT11((char)((uint)iVar8 >> 8),
                                               (char)((uint)param_6._1_1_ *
                                                      (DAT_00dca3fc >> 8 & 0xff) >> 8))),
                             (char)((param_6 & 0xff) * (DAT_00dca3fc & 0xff) >> 8));
        }
        switch(DAT_00dca3f4) {
        case 1:
          if (DAT_00dca3f8 != 0xff) {
            if (DAT_00dca3f8 == 0) {
              return;
            }
            if (param_9 == 0) {
              uVar31 = iVar7 - DAT_00dca3e4;
              if (((uint)((param_2 - param_4) - DAT_00dca3e4) <= uVar31) &&
                 ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
                pbVar24 = (byte *)(iVar2 * param_3 + iVar20 + (param_2 - param_4) * 4);
                *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                  (uint)*pbVar24 * 0x100 >> 8);
                pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                    (uint)pbVar24[1] * 0x100 >> 8);
                pbVar24[2] = (byte)((uVar17 - pbVar24[2]) * DAT_00dca3f8 + (uint)pbVar24[2] * 0x100
                                   >> 8);
              }
              iVar23 = (param_2 - param_8) + param_4;
              if (((uint)(iVar23 - iVar25) <= uVar31) &&
                 ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
                pbVar24 = (byte *)(iVar2 * param_3 + iVar20 + iVar23 * 4);
                *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                  (uint)*pbVar24 * 0x100 >> 8);
                pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                    (uint)pbVar24[1] * 0x100 >> 8);
                pbVar24[2] = (byte)((uVar17 - pbVar24[2]) * DAT_00dca3f8 + (uint)pbVar24[2] * 0x100
                                   >> 8);
              }
            }
            if (local_70 < 0) {
              bVar3 = iVar22 <= param_5;
              iVar10 = param_5;
              if (bVar3) {
                iVar10 = param_5 - iVar22;
              }
              uVar21 = (uint)bVar3;
              local_74 = local_74 + uVar21 * 4;
              local_70 = iVar15 + 5 + uVar21 * 4;
            }
            else {
              param_4 = param_4 + -1;
              bVar3 = true;
              if (local_74 < 0) {
                iVar10 = param_5;
                if (iVar22 <= param_5) {
                  iVar10 = param_5 - iVar22;
                }
                uVar21 = (uint)(iVar22 <= param_5);
                local_74 = (uVar21 - param_4) * 4;
                local_70 = iVar15 + 5 + local_74;
                local_74 = iVar4 + 5 + local_74;
              }
              else {
                local_70 = local_70 + param_4 * -4;
                local_74 = local_74 + param_4 * -4 + 2;
              }
            }
            if (0 < param_4) {
              local_14 = param_4 * 4;
              local_24 = (param_2 - iVar25) - param_4;
              local_34 = (param_3 - uVar21) * iVar2;
              local_38 = (param_3 - iVar5) - uVar21;
              local_28 = ((param_4 - iVar25) - param_8) + param_2;
              local_20 = (param_2 - param_4) * 4;
              local_30 = ((uVar21 - iVar5) - param_9) + param_3;
              iVar23 = ((param_4 - param_8) + param_2) * 4;
              local_2c = ((uVar21 - param_9) + param_3) * iVar2;
              local_18 = iVar23;
              do {
                if (bVar3) {
                  uVar31 = iVar7 - iVar25;
                  if ((local_24 <= uVar31) && (local_30 <= (uint)(iVar13 - iVar5))) {
                    pbVar24 = (byte *)(local_2c + local_20 + iVar20);
                    *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                      (uint)*pbVar24 * 0x100 >> 8);
                    pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                        (uint)pbVar24[1] * 0x100 >> 8);
                    pbVar24[2] = (byte)((uVar17 - pbVar24[2]) * DAT_00dca3f8 +
                                        (uint)pbVar24[2] * 0x100 >> 8);
                  }
                  if ((local_28 <= uVar31) && (local_30 <= (uint)(iVar13 - iVar5))) {
                    pbVar24 = (byte *)(local_2c + iVar23 + iVar20);
                    *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                      (uint)*pbVar24 * 0x100 >> 8);
                    pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                        (uint)pbVar24[1] * 0x100 >> 8);
                    pbVar24[2] = (byte)((uVar17 - pbVar24[2]) * DAT_00dca3f8 +
                                        (uint)pbVar24[2] * 0x100 >> 8);
                    iVar23 = local_18;
                  }
                  if ((local_24 <= uVar31) && (local_38 <= (uint)(iVar13 - iVar5))) {
                    pbVar24 = (byte *)(local_20 + local_34 + iVar20);
                    *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                      (uint)*pbVar24 * 0x100 >> 8);
                    pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                        (uint)pbVar24[1] * 0x100 >> 8);
                    pbVar24[2] = (byte)((uVar17 - pbVar24[2]) * DAT_00dca3f8 +
                                        (uint)pbVar24[2] * 0x100 >> 8);
                    iVar23 = local_18;
                  }
                  if ((local_28 <= uVar31) && (local_38 <= (uint)(iVar13 - iVar5))) {
                    pbVar24 = (byte *)(local_34 + iVar23 + iVar20);
                    *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                      (uint)*pbVar24 * 0x100 >> 8);
                    pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                        (uint)pbVar24[1] * 0x100 >> 8);
                    pbVar24[2] = (byte)((uVar17 - pbVar24[2]) * DAT_00dca3f8 +
                                        (uint)pbVar24[2] * 0x100 >> 8);
                    iVar23 = local_18;
                  }
                }
                if (local_70 < 0) {
                  iVar10 = iVar10 + param_5;
                  bVar3 = iVar22 <= iVar10;
                  if (bVar3) {
                    local_2c = local_2c + iVar2;
                    local_30 = local_30 + 1;
                    local_34 = local_34 + -iVar2;
                    local_38 = local_38 - 1;
                    uVar21 = uVar21 + 1;
                    iVar10 = iVar10 - iVar22;
                  }
                  local_74 = local_74 + uVar21 * 4;
                  local_70 = local_70 + 2 + uVar21 * 4;
                }
                else {
                  local_20 = local_20 + 4;
                  iVar23 = iVar23 + -4;
                  bVar3 = true;
                  local_18 = iVar23;
                  if (local_74 < 0) {
                    iVar10 = iVar10 + param_5;
                    local_24 = local_24 + 1;
                    local_28 = local_28 - 1;
                    local_14 = local_14 + -4;
                    param_4 = param_4 + -1;
                    if (iVar22 <= iVar10) {
                      local_2c = local_2c + iVar2;
                      local_30 = local_30 + 1;
                      local_38 = local_38 - 1;
                      local_34 = local_34 + -iVar2;
                      uVar21 = uVar21 + 1;
                      iVar10 = iVar10 - iVar22;
                    }
                    iVar8 = (uVar21 - param_4) * 4;
                    local_70 = local_70 + 2 + iVar8;
                    local_74 = local_74 + 2 + iVar8;
                  }
                  else {
                    local_24 = local_24 + 1;
                    local_28 = local_28 - 1;
                    param_4 = param_4 + -1;
                    local_14 = local_14 + -4;
                    local_70 = local_70 - local_14;
                    local_74 = local_74 + (2 - local_14);
                  }
                }
              } while (0 < param_4);
            }
            if (param_8 != 0) {
              return;
            }
            if (((uint)((param_2 + param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((param_3 - uVar21) - iVar5 <= (uint)(iVar13 - iVar5))) {
              pbVar24 = (byte *)((param_3 - uVar21) * iVar2 + iVar20 + (param_2 + param_4) * 4);
              *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                (uint)*pbVar24 * 0x100 >> 8);
              pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                  (uint)pbVar24[1] * 0x100 >> 8);
              pbVar24[2] = (byte)((uVar17 - pbVar24[2]) * DAT_00dca3f8 + (uint)pbVar24[2] * 0x100 >>
                                 8);
            }
            param_3 = (uVar21 - param_9) + param_3;
            if ((uint)(iVar7 - iVar25) < (uint)((param_2 - param_4) - iVar25)) {
              return;
            }
            if ((uint)(iVar13 - iVar5) < (uint)(param_3 - iVar5)) {
              return;
            }
            pbVar24 = (byte *)(param_3 * iVar2 + iVar20 + (param_2 - param_4) * 4);
            *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                              (uint)*pbVar24 * 0x100 >> 8);
            pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                (uint)pbVar24[1] * 0x100 >> 8);
            pbVar24[2] = (byte)((uVar17 - pbVar24[2]) * DAT_00dca3f8 + (uint)pbVar24[2] * 0x100 >> 8
                               );
            return;
          }
        case 0:
          if (param_9 == 0) {
            uVar17 = iVar7 - DAT_00dca3e4;
            if (((uint)((param_2 - param_4) - DAT_00dca3e4) <= uVar17) &&
               ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              *(uint *)(iVar2 * param_3 + iVar20 + (param_2 - param_4) * 4) = param_6;
            }
            iVar23 = (param_2 - param_8) + param_4;
            if (((uint)(iVar23 - iVar25) <= uVar17) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              *(uint *)(iVar2 * param_3 + iVar20 + iVar23 * 4) = param_6;
            }
          }
          if (local_70 < 0) {
            bVar3 = iVar22 <= param_5;
            iVar10 = param_5;
            if (bVar3) {
              iVar10 = param_5 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_4 = param_4 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              iVar10 = param_5;
              if (iVar22 <= param_5) {
                iVar10 = param_5 - iVar22;
              }
              uVar21 = (uint)(iVar22 <= param_5);
              local_74 = (uVar21 - param_4) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_4 * -4;
              local_74 = local_74 + param_4 * -4 + 2;
            }
          }
          if (0 < param_4) {
            local_14 = param_4 * 4;
            local_38 = (param_3 - iVar5) - uVar21;
            local_28 = ((param_4 - iVar25) - param_8) + param_2;
            local_24 = (param_2 - iVar25) - param_4;
            local_34 = (param_3 - uVar21) * iVar2;
            local_20 = (param_2 - param_4) * 4;
            iVar23 = ((param_4 - param_8) + param_2) * 4;
            local_30 = ((uVar21 - iVar5) - param_9) + param_3;
            local_2c = ((uVar21 - param_9) + param_3) * iVar2;
            do {
              if (bVar3) {
                uVar17 = iVar7 - iVar25;
                if ((local_24 <= uVar17) && (local_30 <= (uint)(iVar13 - iVar5))) {
                  *(uint *)(local_2c + local_20 + iVar20) = param_6;
                }
                if ((local_28 <= uVar17) && (local_30 <= (uint)(iVar13 - iVar5))) {
                  *(uint *)(local_2c + iVar23 + iVar20) = param_6;
                }
                if ((local_24 <= uVar17) && (local_38 <= (uint)(iVar13 - iVar5))) {
                  *(uint *)(local_20 + local_34 + iVar20) = param_6;
                }
                if ((local_28 <= uVar17) && (local_38 <= (uint)(iVar13 - iVar5))) {
                  *(uint *)(local_34 + iVar23 + iVar20) = param_6;
                }
              }
              if (local_70 < 0) {
                iVar10 = iVar10 + param_5;
                bVar3 = iVar22 <= iVar10;
                if (bVar3) {
                  local_2c = local_2c + iVar2;
                  local_34 = local_34 + -iVar2;
                  local_30 = local_30 + 1;
                  local_38 = local_38 - 1;
                  uVar21 = uVar21 + 1;
                  iVar10 = iVar10 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
              }
              else {
                bVar3 = true;
                local_24 = local_24 + 1;
                local_28 = local_28 - 1;
                param_4 = param_4 + -1;
                if (local_74 < 0) {
                  iVar10 = iVar10 + param_5;
                  local_20 = local_20 + 4;
                  local_14 = local_14 + -4;
                  iVar23 = iVar23 + -4;
                  if (iVar22 <= iVar10) {
                    local_2c = local_2c + iVar2;
                    local_30 = local_30 + 1;
                    local_34 = local_34 + -iVar2;
                    local_38 = local_38 - 1;
                    uVar21 = uVar21 + 1;
                    iVar10 = iVar10 - iVar22;
                  }
                  iVar8 = (uVar21 - param_4) * 4;
                  local_70 = local_70 + 2 + iVar8;
                  local_74 = local_74 + 2 + iVar8;
                }
                else {
                  local_20 = local_20 + 4;
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  iVar23 = iVar23 + -4;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_4);
          }
          if (param_8 == 0) {
            if (((uint)((param_2 + param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((param_3 - uVar21) - iVar5 <= (uint)(iVar13 - iVar5))) {
              *(uint *)((param_3 - uVar21) * iVar2 + iVar20 + (param_2 + param_4) * 4) = param_6;
            }
            param_3 = (uVar21 - param_9) + param_3;
            if (((uint)((param_2 - param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              *(uint *)(param_3 * iVar2 + iVar20 + (param_2 - param_4) * 4) = param_6;
              return;
            }
          }
          break;
        case 2:
          if (DAT_00dca3f8 != 0) {
            if (param_9 == 0) {
              uVar31 = iVar7 - DAT_00dca3e4;
              if ((uint)((param_2 - param_4) - DAT_00dca3e4) <= uVar31) {
                if ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8)) {
                  puVar29 = (uint *)(iVar2 * param_3 + iVar20 + (param_2 - param_4) * 4);
                  local_78._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (uint)param_6._1_1_),
                                *(undefined1 *)
                                 (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_6 & 0xff)));
                  uVar17 = *puVar29;
                  local_78._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (uint)param_6._2_1_),
                                (undefined2)local_78);
                  local_78 = (uint)(uint3)local_78;
                  uVar27 = (uVar17 & 0xfefeff) + (local_78 & 0xfefeff);
                  uVar30 = uVar27 & 0x1010100;
                  *puVar29 = uVar30 - (uVar30 >> 8) | (uVar17 | local_78) & 0x10100 | uVar27;
                }
                uVar17 = (uint)param_6._2_1_;
              }
              iVar8 = (param_2 - param_8) + param_4;
              if ((uint)(iVar8 - iVar25) <= uVar31) {
                if ((uint)(iVar13 - iVar5) < (uint)(param_3 - iVar5)) {
                  uVar17 = (uint)param_6._2_1_;
                }
                else {
                  puVar29 = (uint *)(iVar2 * param_3 + iVar20 + iVar8 * 4);
                  local_78._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                  uVar17 = (uint)param_6._2_1_;
                  uVar31 = *puVar29;
                  local_78._0_3_ =
                       CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                (undefined2)local_78);
                  local_78 = (uint)(uint3)local_78;
                  uVar27 = (uVar31 & 0xfefeff) + (local_78 & 0xfefeff);
                  uVar30 = uVar27 & 0x1010100;
                  *puVar29 = uVar30 - (uVar30 >> 8) | (uVar31 | local_78) & 0x10100 | uVar27;
                }
              }
            }
            if (local_70 < 0) {
              bVar3 = iVar22 <= param_5;
              iVar10 = param_5;
              if (bVar3) {
                iVar10 = param_5 - iVar22;
              }
              uVar21 = (uint)bVar3;
              local_74 = local_74 + uVar21 * 4;
              local_70 = iVar15 + 5 + uVar21 * 4;
            }
            else {
              param_4 = param_4 + -1;
              bVar3 = true;
              if (local_74 < 0) {
                iVar10 = param_5;
                if (iVar22 <= param_5) {
                  iVar10 = param_5 - iVar22;
                }
                uVar21 = (uint)(iVar22 <= param_5);
                local_74 = (uVar21 - param_4) * 4;
                local_70 = iVar15 + 5 + local_74;
                local_74 = iVar4 + 5 + local_74;
              }
              else {
                local_70 = local_70 + param_4 * -4;
                local_74 = local_74 + param_4 * -4 + 2;
              }
            }
            if (0 < param_4) {
              local_14 = param_4 * 4;
              local_3c = (param_3 - iVar5) - uVar21;
              local_30 = ((param_4 - iVar25) - param_8) + param_2;
              local_28 = ((param_4 - param_8) + param_2) * 4;
              local_24 = (param_2 - iVar25) - param_4;
              local_38 = (param_3 - uVar21) * iVar2;
              local_20 = (param_2 - param_4) * 4;
              local_34 = ((uVar21 - iVar5) - param_9) + param_3;
              local_2c = ((uVar21 - param_9) + param_3) * iVar2;
              do {
                if (bVar3) {
                  uVar31 = iVar7 - iVar25;
                  if ((local_24 <= uVar31) && (local_34 <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_2c + local_20 + iVar20);
                    uVar27 = *puVar29;
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78 = (uint)CONCAT12(*(undefined1 *)
                                               (&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                              (undefined2)local_78);
                    uVar17 = (uVar27 & 0xfefeff) + (local_78 & 0xfefeff);
                    uVar30 = uVar17 & 0x1010100;
                    *puVar29 = uVar30 - (uVar30 >> 8) | (uVar27 | local_78) & 0x10100 | uVar17;
                    uVar17 = (uint)param_6._2_1_;
                  }
                  if ((local_30 <= uVar31) && (local_34 <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_2c + local_28 + iVar20);
                    uVar27 = *puVar29;
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78 = (uint)CONCAT12(*(undefined1 *)
                                               (&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                              (undefined2)local_78);
                    uVar17 = (uVar27 & 0xfefeff) + (local_78 & 0xfefeff);
                    uVar30 = uVar17 & 0x1010100;
                    *puVar29 = uVar30 - (uVar30 >> 8) | (uVar27 | local_78) & 0x10100 | uVar17;
                    uVar17 = (uint)param_6._2_1_;
                  }
                  if ((local_24 <= uVar31) && (local_3c <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_20 + local_38 + iVar20);
                    uVar27 = *puVar29;
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78 = (uint)CONCAT12(*(undefined1 *)
                                               (&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                              (undefined2)local_78);
                    uVar17 = (uVar27 & 0xfefeff) + (local_78 & 0xfefeff);
                    uVar30 = uVar17 & 0x1010100;
                    *puVar29 = uVar30 - (uVar30 >> 8) | (uVar27 | local_78) & 0x10100 | uVar17;
                    uVar17 = (uint)param_6._2_1_;
                  }
                  if ((local_30 <= uVar31) && (local_3c <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_38 + local_28 + iVar20);
                    uVar31 = *puVar29;
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78 = (uint)CONCAT12(*(undefined1 *)
                                               (&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                              (undefined2)local_78);
                    uVar17 = (uVar31 & 0xfefeff) + (local_78 & 0xfefeff);
                    uVar27 = uVar17 & 0x1010100;
                    *puVar29 = uVar27 - (uVar27 >> 8) | (uVar31 | local_78) & 0x10100 | uVar17;
                    uVar17 = (uint)param_6._2_1_;
                  }
                }
                if (local_70 < 0) {
                  iVar10 = iVar10 + param_5;
                  bVar3 = iVar22 <= iVar10;
                  if (bVar3) {
                    local_2c = local_2c + iVar2;
                    local_34 = local_34 + 1;
                    local_38 = local_38 + -iVar2;
                    local_3c = local_3c - 1;
                    uVar21 = uVar21 + 1;
                    iVar10 = iVar10 - iVar22;
                  }
                  local_74 = local_74 + uVar21 * 4;
                  local_70 = local_70 + 2 + uVar21 * 4;
                }
                else {
                  bVar3 = true;
                  if (local_74 < 0) {
                    iVar10 = iVar10 + param_5;
                    local_20 = local_20 + 4;
                    local_24 = local_24 + 1;
                    local_28 = local_28 + -4;
                    local_30 = local_30 - 1;
                    local_14 = local_14 + -4;
                    param_4 = param_4 + -1;
                    if (iVar22 <= iVar10) {
                      local_2c = local_2c + iVar2;
                      local_34 = local_34 + 1;
                      local_3c = local_3c - 1;
                      local_38 = local_38 + -iVar2;
                      uVar21 = uVar21 + 1;
                      iVar10 = iVar10 - iVar22;
                    }
                    iVar8 = (uVar21 - param_4) * 4;
                    local_70 = local_70 + 2 + iVar8;
                    local_74 = local_74 + 2 + iVar8;
                  }
                  else {
                    local_24 = local_24 + 1;
                    local_30 = local_30 - 1;
                    param_4 = param_4 + -1;
                    local_20 = local_20 + 4;
                    local_28 = local_28 + -4;
                    local_14 = local_14 + -4;
                    local_70 = local_70 - local_14;
                    local_74 = local_74 + (2 - local_14);
                  }
                }
              } while (0 < param_4);
            }
            if (param_8 == 0) {
              if (((uint)((param_2 + param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
                 ((param_3 - uVar21) - iVar5 <= (uint)(iVar13 - iVar5))) {
                puVar29 = (uint *)((param_3 - uVar21) * iVar2 + iVar20 + (param_2 + param_4) * 4);
                local_78._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                local_78._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                              (undefined2)local_78);
                local_78 = (uint)(uint3)local_78;
                uVar31 = *puVar29;
                uVar27 = (uVar31 & 0xfefeff) + (local_78 & 0xfefeff);
                uVar30 = uVar27 & 0x1010100;
                *puVar29 = uVar30 - (uVar30 >> 8) | (uVar31 | local_78) & 0x10100 | uVar27;
              }
              param_3 = (uVar21 - param_9) + param_3;
              if (((uint)((param_2 - param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
                 ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar29 = (uint *)(param_3 * iVar2 + iVar20 + (param_2 - param_4) * 4);
                uVar21 = *puVar29;
                local_78._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                local_78._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                              (undefined2)local_78);
                local_78 = (uint)(uint3)local_78;
                uVar31 = (uVar21 & 0xfefeff) + (local_78 & 0xfefeff);
                uVar17 = uVar31 & 0x1010100;
                *puVar29 = uVar17 - (uVar17 >> 8) | (uVar21 | local_78) & 0x10100 | uVar31;
                return;
              }
            }
          }
          break;
        case 3:
          if (DAT_00dca3f8 != 0) {
            if (param_9 == 0) {
              uVar31 = iVar7 - DAT_00dca3e4;
              if ((uint)((param_2 - param_4) - DAT_00dca3e4) <= uVar31) {
                if ((uint)(iVar13 - DAT_00dca3e8) < (uint)(param_3 - DAT_00dca3e8)) {
                  uVar17 = (uint)param_6._2_1_;
                }
                else {
                  puVar29 = (uint *)(iVar2 * param_3 + iVar20 + (param_2 - param_4) * 4);
                  local_78._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (uint)param_6._1_1_),
                                *(undefined1 *)
                                 (&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + (param_6 & 0xff)));
                  uVar17 = (uint)param_6._2_1_;
                  local_78._0_3_ =
                       CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + DAT_00dca3f8 * 0x100 + uVar17),
                                (undefined2)local_78);
                  uVar27 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                  uVar30 = uVar27 & 0x1010100;
                  *puVar29 = uVar30 - (uVar30 >> 8) & uVar27;
                }
              }
              uVar27 = local_78;
              iVar8 = (param_2 - param_8) + param_4;
              if ((uint)(iVar8 - iVar25) <= uVar31) {
                if ((uint)(iVar13 - iVar5) < (uint)(param_3 - iVar5)) {
                  uVar17 = (uint)param_6._2_1_;
                }
                else {
                  puVar29 = (uint *)(iVar2 * param_3 + iVar20 + iVar8 * 4);
                  local_78._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                  uVar17 = (uint)param_6._2_1_;
                  local_78._3_1_ = SUB41(uVar27,3);
                  local_78._0_3_ =
                       CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                (undefined2)local_78);
                  uVar31 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                  uVar27 = uVar31 & 0x1010100;
                  *puVar29 = uVar27 - (uVar27 >> 8) & uVar31;
                }
              }
            }
            if (local_70 < 0) {
              bVar3 = iVar22 <= param_5;
              iVar10 = param_5;
              if (bVar3) {
                iVar10 = param_5 - iVar22;
              }
              uVar21 = (uint)bVar3;
              local_74 = local_74 + uVar21 * 4;
              local_70 = iVar15 + 5 + uVar21 * 4;
            }
            else {
              param_4 = param_4 + -1;
              bVar3 = true;
              if (local_74 < 0) {
                iVar10 = param_5;
                if (iVar22 <= param_5) {
                  iVar10 = param_5 - iVar22;
                }
                uVar21 = (uint)(iVar22 <= param_5);
                local_74 = (uVar21 - param_4) * 4;
                local_70 = iVar15 + 5 + local_74;
                local_74 = iVar4 + 5 + local_74;
              }
              else {
                local_70 = local_70 + param_4 * -4;
                local_74 = local_74 + param_4 * -4 + 2;
              }
            }
            if (0 < param_4) {
              local_14 = param_4 * 4;
              local_3c = (param_3 - iVar5) - uVar21;
              local_2c = ((param_4 - iVar25) - param_8) + param_2;
              local_28 = ((param_4 - param_8) + param_2) * 4;
              local_24 = (param_2 - iVar25) - param_4;
              local_38 = (param_3 - uVar21) * iVar2;
              local_20 = (param_2 - param_4) * 4;
              local_34 = ((uVar21 - iVar5) - param_9) + param_3;
              local_30 = ((uVar21 - param_9) + param_3) * iVar2;
              do {
                uVar31 = local_78;
                if (bVar3) {
                  uVar27 = iVar7 - iVar25;
                  if ((local_24 <= uVar27) && (local_34 <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_30 + local_20 + iVar20);
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78._3_1_ = SUB41(uVar31,3);
                    local_78._0_3_ =
                         CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                  (undefined2)local_78);
                    uVar31 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                    uVar30 = uVar31 & 0x1010100;
                    *puVar29 = uVar30 - (uVar30 >> 8) & uVar31;
                  }
                  uVar31 = local_78;
                  if ((local_2c <= uVar27) && (local_34 <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_30 + local_28 + iVar20);
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78._3_1_ = SUB41(uVar31,3);
                    local_78._0_3_ =
                         CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                  (undefined2)local_78);
                    uVar31 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                    uVar30 = uVar31 & 0x1010100;
                    *puVar29 = uVar30 - (uVar30 >> 8) & uVar31;
                  }
                  uVar31 = local_78;
                  if ((local_24 <= uVar27) && (local_3c <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_20 + local_38 + iVar20);
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78._3_1_ = SUB41(uVar31,3);
                    local_78._0_3_ =
                         CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                  (undefined2)local_78);
                    uVar31 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                    uVar30 = uVar31 & 0x1010100;
                    *puVar29 = uVar30 - (uVar30 >> 8) & uVar31;
                  }
                  uVar31 = local_78;
                  if ((local_2c <= uVar27) && (local_3c <= (uint)(iVar13 - iVar5))) {
                    puVar29 = (uint *)(local_38 + local_28 + iVar20);
                    local_78._0_2_ =
                         CONCAT11(*(undefined1 *)
                                   (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                  *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff))
                                 );
                    local_78._3_1_ = SUB41(uVar31,3);
                    local_78._0_3_ =
                         CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                  (undefined2)local_78);
                    uVar31 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                    uVar27 = uVar31 & 0x1010100;
                    *puVar29 = uVar27 - (uVar27 >> 8) & uVar31;
                  }
                }
                if (local_70 < 0) {
                  iVar10 = iVar10 + param_5;
                  bVar3 = iVar22 <= iVar10;
                  if (bVar3) {
                    local_30 = local_30 + iVar2;
                    local_38 = local_38 + -iVar2;
                    local_34 = local_34 + 1;
                    local_3c = local_3c - 1;
                    uVar21 = uVar21 + 1;
                    iVar10 = iVar10 - iVar22;
                  }
                  local_74 = local_74 + uVar21 * 4;
                  local_70 = local_70 + 2 + uVar21 * 4;
                }
                else {
                  local_20 = local_20 + 4;
                  local_28 = local_28 + -4;
                  local_24 = local_24 + 1;
                  local_2c = local_2c - 1;
                  param_4 = param_4 + -1;
                  bVar3 = true;
                  if (local_74 < 0) {
                    iVar10 = iVar10 + param_5;
                    local_14 = local_14 + -4;
                    if (iVar22 <= iVar10) {
                      local_34 = local_34 + 1;
                      local_3c = local_3c - 1;
                      uVar21 = uVar21 + 1;
                      local_30 = local_30 + iVar2;
                      local_38 = local_38 + -iVar2;
                      iVar10 = iVar10 - iVar22;
                    }
                    iVar8 = (uVar21 - param_4) * 4;
                    local_70 = local_70 + 2 + iVar8;
                    local_74 = local_74 + 2 + iVar8;
                  }
                  else {
                    local_14 = local_14 + -4;
                    local_70 = local_70 - local_14;
                    local_74 = local_74 + (2 - local_14);
                  }
                }
              } while (0 < param_4);
            }
            if (param_8 == 0) {
              if ((uint)((param_2 + param_4) - iVar25) <= (uint)(iVar7 - iVar25)) {
                if ((param_3 - uVar21) - iVar5 <= (uint)(iVar13 - iVar5)) {
                  puVar29 = (uint *)((param_3 - uVar21) * iVar2 + iVar20 + (param_2 + param_4) * 4);
                  local_78._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                  local_78._0_3_ =
                       CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                                (undefined2)local_78);
                  uVar27 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                  uVar31 = uVar27 & 0x1010100;
                  *puVar29 = uVar31 - (uVar31 >> 8) & uVar27;
                }
              }
              param_3 = (uVar21 - param_9) + param_3;
              if (((uint)((param_2 - param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
                 ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
                puVar29 = (uint *)(param_3 * iVar2 + iVar20 + (param_2 - param_4) * 4);
                local_78._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                local_78._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + uVar17),
                              (undefined2)local_78);
                uVar17 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                uVar21 = uVar17 & 0x1010100;
                *puVar29 = uVar21 - (uVar21 >> 8) & uVar17;
                return;
              }
            }
          }
          break;
        case 4:
          if (param_9 == 0) {
            uVar31 = iVar7 - DAT_00dca3e4;
            if (((uint)((param_2 - param_4) - DAT_00dca3e4) <= uVar31) &&
               ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              pbVar24 = (byte *)(iVar2 * param_3 + iVar20 + (param_2 - param_4) * 4);
              *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
              pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
              uVar17 = (uint)param_6._2_1_;
              pbVar24[2] = (byte)(pbVar24[2] * uVar17 >> 8);
            }
            iVar23 = (param_2 - param_8) + param_4;
            if (((uint)(iVar23 - iVar25) <= uVar31) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              pbVar24 = (byte *)(iVar2 * param_3 + iVar20 + iVar23 * 4);
              *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
              pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
              uVar17 = (uint)param_6._2_1_;
              pbVar24[2] = (byte)(pbVar24[2] * uVar17 >> 8);
            }
          }
          if (local_70 < 0) {
            bVar3 = iVar22 <= param_5;
            iVar10 = param_5;
            if (bVar3) {
              iVar10 = param_5 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_4 = param_4 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              iVar10 = param_5;
              if (iVar22 <= param_5) {
                iVar10 = param_5 - iVar22;
              }
              uVar21 = (uint)(iVar22 <= param_5);
              local_74 = (uVar21 - param_4) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_4 * -4;
              local_74 = local_74 + param_4 * -4 + 2;
            }
          }
          if (0 < param_4) {
            local_14 = param_4 * 4;
            local_38 = (param_3 - iVar5) - uVar21;
            local_24 = (param_2 - iVar25) - param_4;
            local_28 = ((param_4 - iVar25) - param_8) + param_2;
            local_34 = (param_3 - uVar21) * iVar2;
            local_20 = (param_2 - param_4) * 4;
            local_30 = ((uVar21 - iVar5) - param_9) + param_3;
            iVar23 = ((param_4 - param_8) + param_2) * 4;
            local_2c = ((uVar21 - param_9) + param_3) * iVar2;
            local_18 = iVar23;
            do {
              if (bVar3) {
                uVar31 = iVar7 - iVar25;
                if ((local_24 <= uVar31) && (local_30 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_20 + local_2c + iVar20);
                  *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
                  pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
                  uVar17 = (uint)param_6._2_1_;
                  pbVar24[2] = (byte)(pbVar24[2] * uVar17 >> 8);
                }
                if ((local_28 <= uVar31) && (local_30 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_2c + iVar23 + iVar20);
                  *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
                  pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
                  uVar17 = (uint)param_6._2_1_;
                  pbVar24[2] = (byte)(pbVar24[2] * uVar17 >> 8);
                }
                if ((local_24 <= uVar31) && (local_38 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_34 + local_20 + iVar20);
                  *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
                  pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
                  uVar17 = (uint)param_6._2_1_;
                  pbVar24[2] = (byte)(pbVar24[2] * uVar17 >> 8);
                }
                if ((local_28 <= uVar31) && (local_38 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_34 + iVar23 + iVar20);
                  *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
                  pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
                  uVar17 = (uint)param_6._2_1_;
                  pbVar24[2] = (byte)(pbVar24[2] * uVar17 >> 8);
                  iVar23 = local_18;
                }
              }
              if (local_70 < 0) {
                iVar10 = iVar10 + param_5;
                bVar3 = iVar22 <= iVar10;
                if (bVar3) {
                  local_2c = local_2c + iVar2;
                  local_30 = local_30 + 1;
                  local_34 = local_34 + -iVar2;
                  local_38 = local_38 - 1;
                  uVar21 = uVar21 + 1;
                  iVar10 = iVar10 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
              }
              else {
                local_20 = local_20 + 4;
                iVar23 = iVar23 + -4;
                bVar3 = true;
                local_18 = iVar23;
                if (local_74 < 0) {
                  iVar10 = iVar10 + param_5;
                  local_24 = local_24 + 1;
                  local_28 = local_28 - 1;
                  local_14 = local_14 + -4;
                  param_4 = param_4 + -1;
                  if (iVar22 <= iVar10) {
                    local_2c = local_2c + iVar2;
                    local_30 = local_30 + 1;
                    local_38 = local_38 - 1;
                    local_34 = local_34 + -iVar2;
                    uVar21 = uVar21 + 1;
                    iVar10 = iVar10 - iVar22;
                  }
                  iVar8 = (uVar21 - param_4) * 4;
                  local_70 = local_70 + 2 + iVar8;
                  local_74 = local_74 + 2 + iVar8;
                }
                else {
                  local_24 = local_24 + 1;
                  local_28 = local_28 - 1;
                  param_4 = param_4 + -1;
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_4);
          }
          if (param_8 == 0) {
            if (((uint)((param_2 + param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((param_3 - uVar21) - iVar5 <= (uint)(iVar13 - iVar5))) {
              pbVar24 = (byte *)((param_3 - uVar21) * iVar2 + iVar20 + (param_2 + param_4) * 4);
              *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
              pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
              pbVar24[2] = (byte)(pbVar24[2] * uVar17 >> 8);
            }
            param_3 = (uVar21 - param_9) + param_3;
            if (((uint)((param_2 - param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              pbVar24 = (byte *)(param_3 * iVar2 + iVar20 + (param_2 - param_4) * 4);
              *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
              pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
              pbVar24[2] = (byte)(pbVar24[2] * uVar17 >> 8);
              return;
            }
          }
          break;
        case 10:
          bVar11 = (byte)uVar17;
          if (param_9 == 0) {
            uVar17 = iVar7 - DAT_00dca3e4;
            if (((uint)((param_2 - param_4) - DAT_00dca3e4) <= uVar17) &&
               ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              pbVar24 = (byte *)(iVar2 * param_3 + iVar20 + (param_2 - param_4) * 4);
              *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                (uint)*pbVar24 * 0x100 >> 8);
              pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                  (uint)pbVar24[1] * 0x100 >> 8);
              pbVar24[2] = (byte)(((uint)(byte)~bVar11 - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                  (uint)pbVar24[2] * 0x100 >> 8);
            }
            iVar23 = (param_2 - param_8) + param_4;
            if (((uint)(iVar23 - iVar25) <= uVar17) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              pbVar24 = (byte *)(iVar2 * param_3 + iVar20 + iVar23 * 4);
              *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                (uint)*pbVar24 * 0x100 >> 8);
              pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                  (uint)pbVar24[1] * 0x100 >> 8);
              pbVar24[2] = (byte)(((uint)(byte)~bVar11 - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                  (uint)pbVar24[2] * 0x100 >> 8);
            }
          }
          if (local_70 < 0) {
            bVar3 = iVar22 <= param_5;
            iVar10 = param_5;
            if (bVar3) {
              iVar10 = param_5 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_4 = param_4 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              iVar10 = param_5;
              if (iVar22 <= param_5) {
                iVar10 = param_5 - iVar22;
              }
              uVar21 = (uint)(iVar22 <= param_5);
              local_74 = (uVar21 - param_4) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_4 * -4;
              local_74 = local_74 + param_4 * -4 + 2;
            }
          }
          if (0 < param_4) {
            local_14 = param_4 * 4;
            local_24 = (param_2 - iVar25) - param_4;
            local_34 = (param_3 - uVar21) * iVar2;
            local_38 = (param_3 - iVar5) - uVar21;
            local_28 = ((param_4 - iVar25) - param_8) + param_2;
            local_20 = (param_2 - param_4) * 4;
            local_30 = ((uVar21 - iVar5) - param_9) + param_3;
            iVar23 = ((param_4 - param_8) + param_2) * 4;
            local_2c = ((uVar21 - param_9) + param_3) * iVar2;
            local_18 = iVar23;
            do {
              if (bVar3) {
                uVar17 = iVar7 - iVar25;
                if ((local_24 <= uVar17) && (local_30 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_2c + local_20 + iVar20);
                  *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                    (uint)*pbVar24 * 0x100 >> 8);
                  pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8
                                      + (uint)pbVar24[1] * 0x100 >> 8);
                  pbVar24[2] = (byte)(((uint)(byte)~bVar11 - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                      (uint)pbVar24[2] * 0x100 >> 8);
                }
                if ((local_28 <= uVar17) && (local_30 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_2c + iVar23 + iVar20);
                  *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                    (uint)*pbVar24 * 0x100 >> 8);
                  pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8
                                      + (uint)pbVar24[1] * 0x100 >> 8);
                  pbVar24[2] = (byte)(((uint)(byte)~bVar11 - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                      (uint)pbVar24[2] * 0x100 >> 8);
                  iVar23 = local_18;
                }
                if ((local_24 <= uVar17) && (local_38 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_20 + local_34 + iVar20);
                  *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                    (uint)*pbVar24 * 0x100 >> 8);
                  pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8
                                      + (uint)pbVar24[1] * 0x100 >> 8);
                  pbVar24[2] = (byte)(((uint)(byte)~bVar11 - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                      (uint)pbVar24[2] * 0x100 >> 8);
                  iVar23 = local_18;
                }
                if ((local_28 <= uVar17) && (local_38 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_34 + iVar23 + iVar20);
                  *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                    (uint)*pbVar24 * 0x100 >> 8);
                  pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8
                                      + (uint)pbVar24[1] * 0x100 >> 8);
                  pbVar24[2] = (byte)(((uint)(byte)~bVar11 - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                      (uint)pbVar24[2] * 0x100 >> 8);
                  iVar23 = local_18;
                }
              }
              if (local_70 < 0) {
                iVar10 = iVar10 + param_5;
                bVar3 = iVar22 <= iVar10;
                if (bVar3) {
                  local_2c = local_2c + iVar2;
                  local_30 = local_30 + 1;
                  local_34 = local_34 + -iVar2;
                  local_38 = local_38 - 1;
                  uVar21 = uVar21 + 1;
                  iVar10 = iVar10 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
              }
              else {
                local_20 = local_20 + 4;
                iVar23 = iVar23 + -4;
                bVar3 = true;
                local_18 = iVar23;
                if (local_74 < 0) {
                  iVar10 = iVar10 + param_5;
                  local_24 = local_24 + 1;
                  local_28 = local_28 - 1;
                  local_14 = local_14 + -4;
                  param_4 = param_4 + -1;
                  if (iVar22 <= iVar10) {
                    local_2c = local_2c + iVar2;
                    local_30 = local_30 + 1;
                    local_38 = local_38 - 1;
                    local_34 = local_34 + -iVar2;
                    uVar21 = uVar21 + 1;
                    iVar10 = iVar10 - iVar22;
                  }
                  iVar8 = (uVar21 - param_4) * 4;
                  local_70 = local_70 + 2 + iVar8;
                  local_74 = local_74 + 2 + iVar8;
                }
                else {
                  local_24 = local_24 + 1;
                  local_28 = local_28 - 1;
                  param_4 = param_4 + -1;
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_4);
          }
          if (param_8 == 0) {
            if (((uint)((param_2 + param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((param_3 - uVar21) - iVar5 <= (uint)(iVar13 - iVar5))) {
              pbVar24 = (byte *)((param_3 - uVar21) * iVar2 + iVar20 + (param_2 + param_4) * 4);
              *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                (uint)*pbVar24 * 0x100 >> 8);
              pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                  (uint)pbVar24[1] * 0x100 >> 8);
              pbVar24[2] = (byte)(((uint)(byte)~bVar11 - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                  (uint)pbVar24[2] * 0x100 >> 8);
            }
            param_3 = (uVar21 - param_9) + param_3;
            if (((uint)((param_2 - param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              pbVar24 = (byte *)(param_3 * iVar2 + iVar20 + (param_2 - param_4) * 4);
              *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                (uint)*pbVar24 * 0x100 >> 8);
              pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                  (uint)pbVar24[1] * 0x100 >> 8);
              pbVar24[2] = (byte)(((uint)(byte)~bVar11 - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                  (uint)pbVar24[2] * 0x100 >> 8);
              return;
            }
          }
          break;
        case 0xb:
          if (param_9 == 0) {
            uVar31 = iVar7 - DAT_00dca3e4;
            if (((uint)((param_2 - param_4) - DAT_00dca3e4) <= uVar31) &&
               ((uint)(param_3 - DAT_00dca3e8) <= (uint)(iVar13 - DAT_00dca3e8))) {
              pbVar24 = (byte *)(iVar2 * param_3 + iVar20 + (param_2 - param_4) * 4);
              uVar27 = (uint)*pbVar24;
              *pbVar24 = (byte)((((int)((param_6 & 0xff) * uVar27) >> 8) - uVar27) * DAT_00dca3f8 +
                                uVar27 * 0x100 >> 8);
              uVar27 = (uint)pbVar24[1];
              pbVar24[1] = (byte)((((int)(param_6._1_1_ * uVar27) >> 8) - uVar27) * DAT_00dca3f8 +
                                  uVar27 * 0x100 >> 8);
              uVar27 = (uint)pbVar24[2];
              pbVar24[2] = (byte)((((int)(uVar17 * uVar27) >> 8) - uVar27) * DAT_00dca3f8 +
                                  uVar27 * 0x100 >> 8);
            }
            iVar23 = (param_2 - param_8) + param_4;
            if (((uint)(iVar23 - iVar25) <= uVar31) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              pbVar24 = (byte *)(iVar2 * param_3 + iVar20 + iVar23 * 4);
              uVar31 = (uint)*pbVar24;
              *pbVar24 = (byte)((((int)((param_6 & 0xff) * uVar31) >> 8) - uVar31) * DAT_00dca3f8 +
                                uVar31 * 0x100 >> 8);
              uVar31 = (uint)pbVar24[1];
              pbVar24[1] = (byte)((((int)(param_6._1_1_ * uVar31) >> 8) - uVar31) * DAT_00dca3f8 +
                                  uVar31 * 0x100 >> 8);
              uVar31 = (uint)pbVar24[2];
              pbVar24[2] = (byte)((((int)(uVar17 * uVar31) >> 8) - uVar31) * DAT_00dca3f8 +
                                  uVar31 * 0x100 >> 8);
            }
          }
          if (local_70 < 0) {
            bVar3 = iVar22 <= param_5;
            iVar10 = param_5;
            if (bVar3) {
              iVar10 = param_5 - iVar22;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar15 + 5 + uVar21 * 4;
          }
          else {
            param_4 = param_4 + -1;
            bVar3 = true;
            if (local_74 < 0) {
              iVar10 = param_5;
              if (iVar22 <= param_5) {
                iVar10 = param_5 - iVar22;
              }
              uVar21 = (uint)(iVar22 <= param_5);
              local_74 = (uVar21 - param_4) * 4;
              local_70 = iVar15 + 5 + local_74;
              local_74 = iVar4 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_4 * -4;
              local_74 = local_74 + param_4 * -4 + 2;
            }
          }
          if (0 < param_4) {
            local_14 = param_4 * 4;
            local_38 = (param_3 - iVar5) - uVar21;
            local_28 = ((param_4 - iVar25) - param_8) + param_2;
            local_24 = (param_2 - iVar25) - param_4;
            local_34 = (param_3 - uVar21) * iVar2;
            local_20 = (param_2 - param_4) * 4;
            local_30 = ((uVar21 - iVar5) - param_9) + param_3;
            iVar23 = ((param_4 - param_8) + param_2) * 4;
            local_2c = ((uVar21 - param_9) + param_3) * iVar2;
            local_18 = iVar23;
            do {
              if (bVar3) {
                uVar31 = iVar7 - iVar25;
                if ((local_24 <= uVar31) && (local_30 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_2c + local_20 + iVar20);
                  uVar27 = (uint)*pbVar24;
                  *pbVar24 = (byte)((((int)((param_6 & 0xff) * uVar27) >> 8) - uVar27) *
                                    DAT_00dca3f8 + uVar27 * 0x100 >> 8);
                  uVar27 = (uint)pbVar24[1];
                  pbVar24[1] = (byte)((((int)(param_6._1_1_ * uVar27) >> 8) - uVar27) * DAT_00dca3f8
                                      + uVar27 * 0x100 >> 8);
                  uVar27 = (uint)pbVar24[2];
                  pbVar24[2] = (byte)((((int)(uVar17 * uVar27) >> 8) - uVar27) * DAT_00dca3f8 +
                                      uVar27 * 0x100 >> 8);
                }
                if ((local_28 <= uVar31) && (local_30 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_2c + iVar23 + iVar20);
                  uVar27 = (uint)*pbVar24;
                  *pbVar24 = (byte)((((int)((param_6 & 0xff) * uVar27) >> 8) - uVar27) *
                                    DAT_00dca3f8 + uVar27 * 0x100 >> 8);
                  uVar27 = (uint)pbVar24[1];
                  pbVar24[1] = (byte)((((int)(param_6._1_1_ * uVar27) >> 8) - uVar27) * DAT_00dca3f8
                                      + uVar27 * 0x100 >> 8);
                  uVar27 = (uint)pbVar24[2];
                  pbVar24[2] = (byte)((((int)(uVar17 * uVar27) >> 8) - uVar27) * DAT_00dca3f8 +
                                      uVar27 * 0x100 >> 8);
                  iVar23 = local_18;
                }
                if ((local_24 <= uVar31) && (local_38 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_20 + local_34 + iVar20);
                  uVar27 = (uint)*pbVar24;
                  *pbVar24 = (byte)((((int)((param_6 & 0xff) * uVar27) >> 8) - uVar27) *
                                    DAT_00dca3f8 + uVar27 * 0x100 >> 8);
                  uVar27 = (uint)pbVar24[1];
                  pbVar24[1] = (byte)((((int)(param_6._1_1_ * uVar27) >> 8) - uVar27) * DAT_00dca3f8
                                      + uVar27 * 0x100 >> 8);
                  uVar27 = (uint)pbVar24[2];
                  pbVar24[2] = (byte)((((int)(uVar17 * uVar27) >> 8) - uVar27) * DAT_00dca3f8 +
                                      uVar27 * 0x100 >> 8);
                  iVar23 = local_18;
                }
                if ((local_28 <= uVar31) && (local_38 <= (uint)(iVar13 - iVar5))) {
                  pbVar24 = (byte *)(local_34 + iVar23 + iVar20);
                  uVar31 = (uint)*pbVar24;
                  *pbVar24 = (byte)((((int)((param_6 & 0xff) * uVar31) >> 8) - uVar31) *
                                    DAT_00dca3f8 + uVar31 * 0x100 >> 8);
                  uVar31 = (uint)pbVar24[1];
                  pbVar24[1] = (byte)((((int)(param_6._1_1_ * uVar31) >> 8) - uVar31) * DAT_00dca3f8
                                      + uVar31 * 0x100 >> 8);
                  uVar31 = (uint)pbVar24[2];
                  pbVar24[2] = (byte)((((int)(uVar17 * uVar31) >> 8) - uVar31) * DAT_00dca3f8 +
                                      uVar31 * 0x100 >> 8);
                  iVar23 = local_18;
                }
              }
              if (local_70 < 0) {
                iVar10 = iVar10 + param_5;
                bVar3 = iVar22 <= iVar10;
                if (bVar3) {
                  local_2c = local_2c + iVar2;
                  local_30 = local_30 + 1;
                  local_34 = local_34 + -iVar2;
                  local_38 = local_38 - 1;
                  uVar21 = uVar21 + 1;
                  iVar10 = iVar10 - iVar22;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
              }
              else {
                local_20 = local_20 + 4;
                iVar23 = iVar23 + -4;
                bVar3 = true;
                local_18 = iVar23;
                if (local_74 < 0) {
                  iVar10 = iVar10 + param_5;
                  local_24 = local_24 + 1;
                  local_28 = local_28 - 1;
                  local_14 = local_14 + -4;
                  param_4 = param_4 + -1;
                  if (iVar22 <= iVar10) {
                    local_2c = local_2c + iVar2;
                    local_30 = local_30 + 1;
                    local_38 = local_38 - 1;
                    local_34 = local_34 + -iVar2;
                    uVar21 = uVar21 + 1;
                    iVar10 = iVar10 - iVar22;
                  }
                  iVar8 = (uVar21 - param_4) * 4;
                  local_70 = local_70 + 2 + iVar8;
                  local_74 = local_74 + 2 + iVar8;
                }
                else {
                  local_24 = local_24 + 1;
                  local_28 = local_28 - 1;
                  param_4 = param_4 + -1;
                  local_14 = local_14 + -4;
                  local_70 = local_70 - local_14;
                  local_74 = local_74 + (2 - local_14);
                }
              }
            } while (0 < param_4);
          }
          if (param_8 == 0) {
            if (((uint)((param_2 + param_4) - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((param_3 - uVar21) - iVar5 <= (uint)(iVar13 - iVar5))) {
              iVar23 = (param_3 - uVar21) * iVar2 + iVar20;
              uVar31 = (uint)*(byte *)(iVar23 + (param_2 + param_4) * 4);
              puVar1 = (undefined1 *)(iVar23 + (param_2 + param_4) * 4);
              *puVar1 = (char)((((int)((param_6 & 0xff) * uVar31) >> 8) - uVar31) * DAT_00dca3f8 +
                               uVar31 * 0x100 >> 8);
              uVar31 = (uint)(byte)puVar1[1];
              puVar1[1] = (char)((((int)(param_6._1_1_ * uVar31) >> 8) - uVar31) * DAT_00dca3f8 +
                                 uVar31 * 0x100 >> 8);
              uVar31 = (uint)(byte)puVar1[2];
              puVar1[2] = (char)((((int)(uVar17 * uVar31) >> 8) - uVar31) * DAT_00dca3f8 +
                                 uVar31 * 0x100 >> 8);
            }
            param_2 = param_2 - param_4;
            param_3 = (uVar21 - param_9) + param_3;
            if (((uint)(param_2 - iVar25) <= (uint)(iVar7 - iVar25)) &&
               ((uint)(param_3 - iVar5) <= (uint)(iVar13 - iVar5))) {
              iVar20 = param_3 * iVar2 + iVar20;
              uVar21 = (uint)*(byte *)(iVar20 + param_2 * 4);
              puVar1 = (undefined1 *)(iVar20 + param_2 * 4);
              *puVar1 = (char)((((int)((param_6 & 0xff) * uVar21) >> 8) - uVar21) * DAT_00dca3f8 +
                               uVar21 * 0x100 >> 8);
              uVar21 = (uint)(byte)puVar1[1];
              puVar1[1] = (char)((((int)(param_6._1_1_ * uVar21) >> 8) - uVar21) * DAT_00dca3f8 +
                                 uVar21 * 0x100 >> 8);
              uVar21 = (uint)(byte)puVar1[2];
              puVar1[2] = (char)((((int)(uVar17 * uVar21) >> 8) - uVar21) * DAT_00dca3f8 +
                                 uVar21 * 0x100 >> 8);
              return;
            }
          }
        }
      }
    }
    return;
  }
  iVar8 = FUN_0056e050(DAT_00dca3f0,
                       "..\\..\\..\\..\\Source\\Library\\Main\\DxMemImgDrawFunction3.cpp",0x7d2);
  if (iVar8 == 0) {
    return;
  }
  if (param_4 < param_5) {
    iVar9 = (param_5 * param_5) / param_4;
    iVar22 = 0;
    local_48 = 0;
    local_5c = 0;
    iVar4 = param_5 * -2;
    local_70 = iVar4 + 3;
    iVar10 = param_5 * -4;
    local_74 = iVar10 + 3;
    iVar15 = *(int *)(*(int *)(param_1 + 0x14) + 0x20);
    if (iVar15 != 0) {
      if (iVar15 != 1) goto switchD_00774a8e_caseD_5;
      if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
        param_6._0_2_ =
             CONCAT11((char)((uint)param_6._1_1_ * (DAT_00dca3fc >> 8 & 0xff) >> 8),(byte)param_6);
        param_6 = CONCAT22(CONCAT11(param_6._3_1_,
                                    (char)((uint)param_6._2_1_ * (DAT_00dca3fc >> 0x10 & 0xff) >> 8)
                                   ),(ushort)param_6);
        uVar21 = (uint)(ushort)param_6;
        param_6 = CONCAT31(param_6._1_3_,(char)((uVar21 & 0xff) * (DAT_00dca3fc & 0xff) >> 8));
      }
      switch(DAT_00dca3f4) {
      case 0:
        goto switchD_0077a912_caseD_0;
      case 1:
        goto switchD_0077a912_caseD_1;
      case 2:
        if (DAT_00dca3f8 == 0) goto switchD_00774a8e_caseD_5;
        if (local_70 < 0) {
          local_48 = param_4;
          if (iVar9 <= param_4) {
            local_48 = param_4 - iVar9;
          }
          local_5c = (uint)(iVar9 <= param_4);
          local_70 = local_5c * 4;
          local_74 = local_74 + local_70;
LAB_0077b0ee:
          local_70 = iVar4 + 5 + local_70;
        }
        else {
          param_5 = param_5 + -1;
          if (local_74 < 0) {
            local_48 = param_4;
            if (iVar9 <= param_4) {
              local_48 = param_4 - iVar9;
            }
            local_5c = (uint)(iVar9 <= param_4);
            local_70 = (local_5c - param_5) * 4;
            local_74 = iVar10 + 5 + local_70;
            goto LAB_0077b0ee;
          }
          local_70 = local_70 + param_5 * -4;
          local_74 = local_74 + param_5 * -4 + 2;
        }
        if (-1 < param_5) {
          local_14 = param_5 * 4;
          local_2c = (param_5 - param_9) + param_3;
          local_28 = (local_5c - param_8) + param_2;
          local_24 = param_2 - local_5c;
          local_20 = param_3 - param_5;
          local_1c = local_2c * iVar2;
          local_18 = local_20 * iVar2;
          iVar15 = local_48;
          do {
            if (local_70 < 0) {
              local_48 = iVar15 + param_4;
              if (iVar9 <= local_48) {
                local_5c = local_5c + 1;
                local_24 = local_24 + -1;
                local_28 = local_28 + 1;
                local_48 = local_48 - iVar9;
              }
              iVar15 = local_5c * 4;
              local_74 = local_74 + iVar15;
LAB_0077b49c:
              local_70 = local_70 + 2 + iVar15;
              iVar15 = local_48;
            }
            else {
              local_58 = local_24;
              local_50 = local_28;
              if ((((iVar5 <= local_20 && iVar25 <= (int)local_28) && local_20 < iVar13) &&
                  (int)local_24 < iVar7) && *(char *)(local_20 + iVar8) == '\0') {
                local_58 = iVar25;
                if (iVar25 <= (int)local_24) {
                  local_58 = local_24;
                }
                if (iVar7 < (int)local_28) {
                  local_50 = iVar7;
                }
                *(undefined1 *)(local_20 + iVar8) = 1;
                local_4c = (local_50 - local_58) + 1;
                puVar29 = (uint *)(local_18 + local_58 * 4 + iVar20);
                do {
                  local_78._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                  local_78._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._2_1_),
                                (undefined2)local_78);
                  uVar6 = (uint3)local_78;
                  local_78 = (uint)(uint3)local_78;
                  uVar17 = (*puVar29 & 0xfefeff) + (uVar6 & 0xfefeff);
                  uVar21 = uVar17 & 0x1010100;
                  *puVar29 = uVar21 - (uVar21 >> 8) | (*puVar29 | local_78) & 0x10100 | uVar17;
                  puVar29 = puVar29 + 1;
                  local_4c = local_4c + -1;
                } while (local_4c != 0);
                iVar15 = local_48;
              }
              if ((((iVar5 <= (int)local_2c && (int)local_2c < iVar13) && iVar25 <= local_50) &&
                  local_58 < iVar7) && *(char *)(local_2c + iVar8) == '\0') {
                if (local_58 < iVar25) {
                  local_58 = iVar25;
                }
                if (iVar7 < local_50) {
                  local_50 = iVar7;
                }
                *(undefined1 *)(local_2c + iVar8) = 1;
                local_4c = (local_50 - local_58) + 1;
                puVar29 = (uint *)(local_1c + local_58 * 4 + iVar20);
                do {
                  local_78._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                  local_78._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._2_1_),
                                (undefined2)local_78);
                  uVar6 = (uint3)local_78;
                  local_78 = (uint)(uint3)local_78;
                  uVar17 = (*puVar29 & 0xfefeff) + (uVar6 & 0xfefeff);
                  uVar21 = uVar17 & 0x1010100;
                  *puVar29 = uVar21 - (uVar21 >> 8) | (*puVar29 | local_78) & 0x10100 | uVar17;
                  puVar29 = puVar29 + 1;
                  local_4c = local_4c + -1;
                } while (local_4c != 0);
                iVar15 = local_48;
              }
              local_20 = local_20 + 1;
              local_2c = local_2c + -1;
              local_18 = local_18 + iVar2;
              param_5 = param_5 + -1;
              local_1c = local_1c - iVar2;
              if (local_74 < 0) {
                local_48 = iVar15 + param_4;
                local_14 = local_14 + -4;
                if (iVar9 <= local_48) {
                  local_5c = local_5c + 1;
                  local_24 = local_24 + -1;
                  local_28 = local_28 + 1;
                  local_48 = local_48 - iVar9;
                }
                iVar15 = (local_5c - param_5) * 4;
                local_74 = local_74 + 2 + iVar15;
                goto LAB_0077b49c;
              }
              local_14 = local_14 + -4;
              local_70 = local_70 - local_14;
              local_74 = local_74 + (2 - local_14);
            }
            if (param_5 < 0) {
              FUN_0056e1d0(iVar8);
              return;
            }
          } while( true );
        }
        goto switchD_00774a8e_caseD_5;
      case 3:
        if (DAT_00dca3f8 == 0) goto switchD_00774a8e_caseD_5;
        if (local_70 < 0) {
          iVar22 = param_4;
          if (iVar9 <= param_4) {
            iVar22 = param_4 - iVar9;
          }
          local_5c = (uint)(iVar9 <= param_4);
          local_70 = local_5c * 4;
          local_74 = local_74 + local_70;
LAB_0077b53d:
          local_70 = iVar4 + 5 + local_70;
        }
        else {
          param_5 = param_5 + -1;
          if (local_74 < 0) {
            iVar22 = param_4;
            if (iVar9 <= param_4) {
              iVar22 = param_4 - iVar9;
            }
            local_5c = (uint)(iVar9 <= param_4);
            local_70 = (local_5c - param_5) * 4;
            local_74 = iVar10 + 5 + local_70;
            goto LAB_0077b53d;
          }
          local_70 = local_70 + param_5 * -4;
          local_74 = local_74 + param_5 * -4 + 2;
        }
        if (-1 < param_5) {
          local_14 = param_5 * 4;
          local_2c = (param_5 - param_9) + param_3;
          local_28 = (local_5c - param_8) + param_2;
          local_24 = param_2 - local_5c;
          local_20 = param_3 - param_5;
          local_1c = local_2c * iVar2;
          local_18 = local_20 * iVar2;
          do {
            if (local_70 < 0) {
              iVar22 = iVar22 + param_4;
              if (iVar9 <= iVar22) {
                local_5c = local_5c + 1;
                local_24 = local_24 + -1;
                local_28 = local_28 + 1;
                iVar22 = iVar22 - iVar9;
              }
              iVar15 = local_5c * 4;
              local_74 = local_74 + iVar15;
LAB_0077b8a3:
              local_70 = local_70 + 2 + iVar15;
            }
            else {
              local_58 = local_24;
              local_50 = local_28;
              if ((((iVar5 <= local_20 && iVar25 <= (int)local_28) && local_20 < iVar13) &&
                  (int)local_24 < iVar7) && *(char *)(local_20 + iVar8) == '\0') {
                local_58 = iVar25;
                if (iVar25 <= (int)local_24) {
                  local_58 = local_24;
                }
                if (iVar7 < (int)local_28) {
                  local_50 = iVar7;
                }
                *(undefined1 *)(local_20 + iVar8) = 1;
                local_4c = (local_50 - local_58) + 1;
                puVar29 = (uint *)(local_18 + local_58 * 4 + iVar20);
                do {
                  uVar21 = local_78;
                  local_78._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                  local_78._3_1_ = SUB41(uVar21,3);
                  local_78._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._2_1_),
                                (undefined2)local_78);
                  uVar17 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                  uVar21 = uVar17 & 0x1010100;
                  *puVar29 = uVar21 - (uVar21 >> 8) & uVar17;
                  puVar29 = puVar29 + 1;
                  local_4c = local_4c + -1;
                } while (local_4c != 0);
              }
              if ((((iVar5 <= (int)local_2c && (int)local_2c < iVar13) && iVar25 <= local_50) &&
                  local_58 < iVar7) && *(char *)(local_2c + iVar8) == '\0') {
                if (local_58 < iVar25) {
                  local_58 = iVar25;
                }
                if (iVar7 < local_50) {
                  local_50 = iVar7;
                }
                *(undefined1 *)(local_2c + iVar8) = 1;
                local_4c = (local_50 - local_58) + 1;
                puVar29 = (uint *)(local_1c + local_58 * 4 + iVar20);
                do {
                  uVar21 = local_78;
                  local_78._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                  local_78._3_1_ = SUB41(uVar21,3);
                  local_78._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._2_1_),
                                (undefined2)local_78);
                  uVar17 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                  uVar21 = uVar17 & 0x1010100;
                  *puVar29 = uVar21 - (uVar21 >> 8) & uVar17;
                  puVar29 = puVar29 + 1;
                  local_4c = local_4c + -1;
                } while (local_4c != 0);
              }
              local_18 = local_18 + iVar2;
              local_20 = local_20 + 1;
              local_2c = local_2c + -1;
              local_1c = local_1c - iVar2;
              param_5 = param_5 + -1;
              if (local_74 < 0) {
                iVar22 = iVar22 + param_4;
                local_14 = local_14 + -4;
                if (iVar9 <= iVar22) {
                  local_5c = local_5c + 1;
                  local_24 = local_24 + -1;
                  local_28 = local_28 + 1;
                  iVar22 = iVar22 - iVar9;
                }
                iVar15 = (local_5c - param_5) * 4;
                local_74 = local_74 + 2 + iVar15;
                goto LAB_0077b8a3;
              }
              local_14 = local_14 + -4;
              local_70 = local_70 - local_14;
              local_74 = local_74 + (2 - local_14);
            }
            if (param_5 < 0) {
              FUN_0056e1d0(iVar8);
              return;
            }
          } while( true );
        }
        goto switchD_00774a8e_caseD_5;
      case 4:
        if (local_70 < 0) {
          iVar22 = param_4;
          if (iVar9 <= param_4) {
            iVar22 = param_4 - iVar9;
          }
          local_5c = (uint)(iVar9 <= param_4);
          local_70 = local_5c * 4;
          local_74 = local_74 + local_70;
LAB_0077b937:
          local_70 = iVar4 + 5 + local_70;
        }
        else {
          param_5 = param_5 + -1;
          if (local_74 < 0) {
            iVar22 = param_4;
            if (iVar9 <= param_4) {
              iVar22 = param_4 - iVar9;
            }
            local_5c = (uint)(iVar9 <= param_4);
            local_70 = (local_5c - param_5) * 4;
            local_74 = iVar10 + 5 + local_70;
            goto LAB_0077b937;
          }
          local_70 = local_70 + param_5 * -4;
          local_74 = local_74 + param_5 * -4 + 2;
        }
        if (-1 < param_5) {
          local_28 = param_5 * 4;
          local_3c = (param_5 - param_9) + param_3;
          local_50 = (local_5c - param_8) + param_2;
          local_24 = param_2 - local_5c;
          local_20 = param_3 - param_5;
          local_14 = local_3c * iVar2;
          local_18 = local_20 * iVar2;
          local_1c = local_50;
          do {
            if (local_70 < 0) {
              iVar22 = iVar22 + param_4;
              if (iVar9 <= iVar22) {
                local_5c = local_5c + 1;
                local_24 = local_24 + -1;
                local_50 = local_50 + 1;
                iVar22 = iVar22 - iVar9;
                local_1c = local_50;
              }
              iVar23 = local_5c * 4;
              local_74 = local_74 + iVar23;
LAB_0077bc5e:
              local_70 = local_70 + 2 + iVar23;
            }
            else {
              local_58 = local_24;
              if ((((local_20 < iVar13 && (int)local_24 < iVar7) && iVar5 <= local_20) &&
                  iVar25 <= local_50) && *(char *)(local_20 + iVar8) == '\0') {
                local_58 = iVar25;
                if (iVar25 <= (int)local_24) {
                  local_58 = local_24;
                }
                if (iVar7 < local_50) {
                  local_50 = iVar7;
                }
                *(undefined1 *)(local_20 + iVar8) = 1;
                iVar23 = (local_50 - local_58) + 1;
                pbVar24 = (byte *)(local_18 + local_58 * 4 + iVar20);
                do {
                  *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
                  pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
                  pbVar24[2] = (byte)((uint)pbVar24[2] * (uint)param_6._2_1_ >> 8);
                  pbVar24 = pbVar24 + 4;
                  iVar23 = iVar23 + -1;
                } while (iVar23 != 0);
              }
              if (((((int)local_3c < iVar13 && iVar25 <= local_50) && iVar5 <= (int)local_3c) &&
                  local_58 < iVar7) && *(char *)(local_3c + iVar8) == '\0') {
                if (local_58 < iVar25) {
                  local_58 = iVar25;
                }
                if (iVar7 < local_50) {
                  local_50 = iVar7;
                }
                local_4c = (local_50 - local_58) + 1;
                *(undefined1 *)(local_3c + iVar8) = 1;
                pbVar24 = (byte *)(local_14 + local_58 * 4 + iVar20);
                do {
                  *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
                  pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
                  pbVar24[2] = (byte)((uint)pbVar24[2] * (uint)param_6._2_1_ >> 8);
                  pbVar24 = pbVar24 + 4;
                  local_4c = local_4c + -1;
                } while (local_4c != 0);
              }
              local_14 = local_14 - iVar2;
              local_18 = local_18 + iVar2;
              if (local_74 < 0) {
                iVar22 = iVar22 + param_4;
                local_20 = local_20 + 1;
                local_3c = local_3c + -1;
                local_28 = local_28 + -4;
                param_5 = param_5 + -1;
                if (iVar9 <= iVar22) {
                  local_5c = local_5c + 1;
                  local_24 = local_24 + -1;
                  local_1c = local_1c + 1;
                  iVar22 = iVar22 - iVar9;
                }
                iVar23 = (local_5c - param_5) * 4;
                local_74 = local_74 + 2 + iVar23;
                local_50 = local_1c;
                goto LAB_0077bc5e;
              }
              local_20 = local_20 + 1;
              local_3c = local_3c + -1;
              param_5 = param_5 + -1;
              local_28 = local_28 + -4;
              local_70 = local_70 - local_28;
              local_74 = local_74 + (2 - local_28);
              local_50 = local_1c;
            }
            if (param_5 < 0) {
              FUN_0056e1d0(iVar8);
              return;
            }
          } while( true );
        }
      default:
        goto switchD_00774a8e_caseD_5;
      case 10:
        if (local_70 < 0) {
          local_48 = param_4;
          if (param_4 < iVar9) {
            local_24 = 0;
            local_70 = 0;
          }
          else {
            local_24 = 1;
            local_48 = param_4 - iVar9;
            local_70 = 4;
            local_5c = 1;
            local_74 = iVar10 + 7;
          }
LAB_0077c16d:
          local_70 = iVar4 + 5 + local_70;
        }
        else {
          param_5 = param_5 + -1;
          if (local_74 < 0) {
            local_48 = param_4;
            bVar3 = param_4 < iVar9;
            if (!bVar3) {
              local_48 = param_4 - iVar9;
            }
            local_5c = (uint)!bVar3;
            local_24 = (uint)!bVar3;
            local_70 = (local_24 - param_5) * 4;
            local_74 = iVar10 + 5 + local_70;
            goto LAB_0077c16d;
          }
          local_24 = 0;
          local_70 = local_70 + param_5 * -4;
          local_74 = local_74 + param_5 * -4 + 2;
        }
        if (-1 < param_5) {
          local_34 = param_5 * 4;
          local_2c = (param_5 - param_9) + param_3;
          local_50 = (local_24 - param_8) + param_2;
          local_24 = param_2 - local_24;
          local_28 = param_3 - param_5;
          local_14 = local_2c * iVar2;
          local_18 = local_28 * iVar2;
          iVar23 = local_48;
          local_1c = local_50;
          do {
            if (local_70 < 0) {
              local_48 = iVar23 + param_4;
              if (iVar9 <= local_48) {
                local_5c = local_5c + 1;
                local_24 = local_24 + -1;
                local_50 = local_50 + 1;
                local_48 = local_48 - iVar9;
                local_1c = local_50;
              }
              iVar23 = local_5c * 4;
              local_74 = local_74 + iVar23;
LAB_0077c4f1:
              local_70 = local_70 + 2 + iVar23;
              iVar23 = local_48;
            }
            else {
              local_58 = local_24;
              if ((((iVar5 <= (int)local_28 && iVar25 <= local_50) && (int)local_28 < iVar13) &&
                  (int)local_24 < iVar7) && *(char *)(local_28 + iVar8) == '\0') {
                local_58 = iVar25;
                if (iVar25 <= (int)local_24) {
                  local_58 = local_24;
                }
                if (iVar7 < local_50) {
                  local_50 = iVar7;
                }
                *(undefined1 *)(local_28 + iVar8) = 1;
                iVar23 = (local_50 - local_58) + 1;
                pbVar24 = (byte *)(local_18 + local_58 * 4 + iVar20);
                do {
                  *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                    (uint)*pbVar24 * 0x100 >> 8);
                  pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8
                                      + (uint)pbVar24[1] * 0x100 >> 8);
                  pbVar24[2] = (byte)(((uint)(byte)~param_6._2_1_ - (uint)pbVar24[2]) * DAT_00dca3f8
                                      + (uint)pbVar24[2] * 0x100 >> 8);
                  pbVar24 = pbVar24 + 4;
                  iVar23 = iVar23 + -1;
                } while (iVar23 != 0);
                iVar23 = local_48;
              }
              if (!(((((int)local_2c < iVar5 || iVar13 <= (int)local_2c) || local_50 < iVar25) ||
                    iVar7 <= local_58) || *(char *)(local_2c + iVar8) != '\0')) {
                if (local_58 < iVar25) {
                  local_58 = iVar25;
                }
                if (iVar7 < local_50) {
                  local_50 = iVar7;
                }
                iVar23 = (local_50 - local_58) + 1;
                *(undefined1 *)(local_2c + iVar8) = 1;
                pbVar24 = (byte *)(local_14 + local_58 * 4 + iVar20);
                do {
                  *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                    (uint)*pbVar24 * 0x100 >> 8);
                  pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8
                                      + (uint)pbVar24[1] * 0x100 >> 8);
                  pbVar24[2] = (byte)(((uint)(byte)~param_6._2_1_ - (uint)pbVar24[2]) * DAT_00dca3f8
                                      + (uint)pbVar24[2] * 0x100 >> 8);
                  pbVar24 = pbVar24 + 4;
                  iVar23 = iVar23 + -1;
                } while (iVar23 != 0);
                iVar23 = local_48;
              }
              local_14 = local_14 - iVar2;
              local_28 = local_28 + 1;
              local_18 = local_18 + iVar2;
              param_5 = param_5 + -1;
              if (local_74 < 0) {
                local_48 = iVar23 + param_4;
                local_34 = local_34 + -4;
                local_2c = local_2c + -1;
                if (iVar9 <= local_48) {
                  local_5c = local_5c + 1;
                  local_24 = local_24 + -1;
                  local_1c = local_1c + 1;
                  local_48 = local_48 - iVar9;
                }
                iVar23 = (local_5c - param_5) * 4;
                local_74 = local_74 + 2 + iVar23;
                local_50 = local_1c;
                goto LAB_0077c4f1;
              }
              local_2c = local_2c + -1;
              local_34 = local_34 + -4;
              local_70 = local_70 - local_34;
              local_74 = local_74 + (2 - local_34);
              local_50 = local_1c;
            }
            if (param_5 < 0) {
              FUN_0056e1d0(iVar8);
              return;
            }
          } while( true );
        }
        goto switchD_00774a8e_caseD_5;
      case 0xb:
        if (local_70 < 0) {
          local_48 = param_4;
          if (param_4 < iVar9) {
            local_24 = 0;
            local_70 = 0;
          }
          else {
            local_24 = 1;
            local_48 = param_4 - iVar9;
            local_70 = 4;
            local_5c = 1;
            local_74 = iVar10 + 7;
          }
LAB_0077bd16:
          local_70 = iVar4 + 5 + local_70;
        }
        else {
          param_5 = param_5 + -1;
          if (local_74 < 0) {
            local_48 = param_4;
            bVar3 = param_4 < iVar9;
            if (!bVar3) {
              local_48 = param_4 - iVar9;
            }
            local_5c = (uint)!bVar3;
            local_24 = (uint)!bVar3;
            local_70 = (local_24 - param_5) * 4;
            local_74 = iVar10 + 5 + local_70;
            goto LAB_0077bd16;
          }
          local_24 = 0;
          local_70 = local_70 + param_5 * -4;
          local_74 = local_74 + param_5 * -4 + 2;
        }
        if (-1 < param_5) {
          local_2c = param_5 * 4;
          local_20 = (param_5 - param_9) + param_3;
          local_50 = (local_24 - param_8) + param_2;
          local_24 = param_2 - local_24;
          local_28 = param_3 - param_5;
          local_14 = local_20 * iVar2;
          local_18 = local_28 * iVar2;
          iVar23 = local_48;
          local_1c = local_50;
          do {
            if (local_70 < 0) {
              local_48 = iVar23 + param_4;
              if (iVar9 <= local_48) {
                local_5c = local_5c + 1;
                local_24 = local_24 + -1;
                local_50 = local_50 + 1;
                local_48 = local_48 - iVar9;
                local_1c = local_50;
              }
              iVar23 = local_5c * 4;
              local_74 = local_74 + iVar23;
LAB_0077c0b1:
              local_70 = local_70 + 2 + iVar23;
              iVar23 = local_48;
            }
            else {
              local_58 = local_24;
              if ((((iVar5 <= (int)local_28 && iVar25 <= local_50) && (int)local_28 < iVar13) &&
                  (int)local_24 < iVar7) && *(char *)(local_28 + iVar8) == '\0') {
                local_58 = iVar25;
                if (iVar25 <= (int)local_24) {
                  local_58 = local_24;
                }
                if (iVar7 < local_50) {
                  local_50 = iVar7;
                }
                *(undefined1 *)(local_28 + iVar8) = 1;
                iVar23 = (local_50 - local_58) + 1;
                pbVar24 = (byte *)(local_18 + local_58 * 4 + iVar20);
                do {
                  uVar21 = (uint)*pbVar24;
                  *pbVar24 = (byte)((((int)(uVar21 * (param_6 & 0xff)) >> 8) - uVar21) *
                                    DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                  uVar21 = (uint)pbVar24[1];
                  pbVar24[1] = (byte)((((int)(uVar21 * param_6._1_1_) >> 8) - uVar21) * DAT_00dca3f8
                                      + uVar21 * 0x100 >> 8);
                  uVar21 = (uint)pbVar24[2];
                  pbVar24[2] = (byte)((((int)(uVar21 * param_6._2_1_) >> 8) - uVar21) * DAT_00dca3f8
                                      + uVar21 * 0x100 >> 8);
                  pbVar24 = pbVar24 + 4;
                  iVar23 = iVar23 + -1;
                } while (iVar23 != 0);
                iVar23 = local_48;
              }
              if (!((((local_20 < iVar5 || iVar13 <= local_20) || local_50 < iVar25) ||
                    iVar7 <= local_58) || *(char *)(local_20 + iVar8) != '\0')) {
                if (local_58 < iVar25) {
                  local_58 = iVar25;
                }
                if (iVar7 < local_50) {
                  local_50 = iVar7;
                }
                *(undefined1 *)(local_20 + iVar8) = 1;
                iVar23 = (local_50 - local_58) + 1;
                pbVar24 = (byte *)(local_14 + local_58 * 4 + iVar20);
                do {
                  uVar21 = (uint)*pbVar24;
                  *pbVar24 = (byte)((((int)(uVar21 * (param_6 & 0xff)) >> 8) - uVar21) *
                                    DAT_00dca3f8 + uVar21 * 0x100 >> 8);
                  uVar21 = (uint)pbVar24[1];
                  pbVar24[1] = (byte)((((int)(uVar21 * param_6._1_1_) >> 8) - uVar21) * DAT_00dca3f8
                                      + uVar21 * 0x100 >> 8);
                  uVar21 = (uint)pbVar24[2];
                  pbVar24[2] = (byte)((((int)(uVar21 * param_6._2_1_) >> 8) - uVar21) * DAT_00dca3f8
                                      + uVar21 * 0x100 >> 8);
                  pbVar24 = pbVar24 + 4;
                  iVar23 = iVar23 + -1;
                } while (iVar23 != 0);
                iVar23 = local_48;
              }
              local_14 = local_14 - iVar2;
              local_28 = local_28 + 1;
              local_18 = local_18 + iVar2;
              param_5 = param_5 + -1;
              if (local_74 < 0) {
                local_48 = iVar23 + param_4;
                local_2c = local_2c + -4;
                local_20 = local_20 + -1;
                if (iVar9 <= local_48) {
                  local_5c = local_5c + 1;
                  local_24 = local_24 + -1;
                  local_1c = local_1c + 1;
                  local_48 = local_48 - iVar9;
                }
                iVar23 = (local_5c - param_5) * 4;
                local_74 = local_74 + 2 + iVar23;
                local_50 = local_1c;
                goto LAB_0077c0b1;
              }
              local_20 = local_20 + -1;
              local_2c = local_2c + -4;
              local_70 = local_70 - local_2c;
              local_74 = local_74 + (2 - local_2c);
              local_50 = local_1c;
            }
            if (param_5 < 0) {
              FUN_0056e1d0(iVar8);
              return;
            }
          } while( true );
        }
        goto switchD_00774a8e_caseD_5;
      }
    }
    if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
      param_6 = ((param_6 >> 5 & 0x3f) * (DAT_00dca3fc >> 8 & 0xff) & 0xffffff07 |
                (param_6 & 0x1f) * (DAT_00dca3fc & 0xff) >> 5) >> 3 |
                (param_6 >> 8 & 0xfffff8) * (DAT_00dca3fc >> 0x10 & 0xff) & 0xfffff800;
    }
    local_40 = param_5;
    switch(DAT_00dca3f4) {
    case 0:
      goto switchD_0077c5b0_caseD_0;
    case 1:
      goto switchD_0077c5b0_caseD_1;
    case 2:
      if (DAT_00dca3f8 == 0) goto switchD_00774a8e_caseD_5;
      if (local_70 < 0) {
        local_48 = param_4;
        if (iVar9 <= param_4) {
          local_48 = param_4 - iVar9;
        }
        local_5c = (uint)(iVar9 <= param_4);
        local_70 = local_5c * 4;
        local_74 = local_74 + local_70;
LAB_0077cdd2:
        local_70 = iVar4 + 5 + local_70;
      }
      else {
        param_5 = param_5 + -1;
        if (local_74 < 0) {
          local_48 = param_4;
          if (iVar9 <= param_4) {
            local_48 = param_4 - iVar9;
          }
          local_5c = (uint)(iVar9 <= param_4);
          local_70 = (local_5c - param_5) * 4;
          local_74 = iVar10 + 5 + local_70;
          goto LAB_0077cdd2;
        }
        local_70 = local_70 + param_5 * -4;
        local_74 = local_74 + param_5 * -4 + 2;
      }
      if (-1 < param_5) {
        local_14 = param_5 * 4;
        local_2c = (param_5 - param_9) + param_3;
        local_28 = (local_5c - param_8) + param_2;
        local_24 = param_2 - local_5c;
        local_20 = param_3 - param_5;
        local_1c = local_2c * iVar2;
        local_18 = local_20 * iVar2;
        iVar15 = local_48;
        do {
          if (local_70 < 0) {
            local_48 = iVar15 + param_4;
            if (iVar9 <= local_48) {
              local_5c = local_5c + 1;
              local_24 = local_24 + -1;
              local_28 = local_28 + 1;
              local_48 = local_48 - iVar9;
            }
            iVar15 = local_5c * 4;
            local_74 = local_74 + iVar15;
LAB_0077d180:
            local_70 = local_70 + 2 + iVar15;
            iVar15 = local_48;
          }
          else {
            local_58 = local_24;
            local_50 = local_28;
            if ((((iVar5 <= local_20 && iVar25 <= (int)local_28) && local_20 < iVar13) &&
                (int)local_24 < iVar7) && *(char *)(local_20 + iVar8) == '\0') {
              local_58 = iVar25;
              if (iVar25 <= (int)local_24) {
                local_58 = local_24;
              }
              if (iVar7 < (int)local_28) {
                local_50 = iVar7;
              }
              *(undefined1 *)(local_20 + iVar8) = 1;
              local_4c = (local_50 - local_58) + 1;
              puVar26 = (ushort *)(local_18 + local_58 * 2 + iVar20);
              do {
                uVar12 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                uVar17 = (*puVar26 & 0xf7def7df) + (uVar12 & 0xf7def7df);
                uVar21 = uVar17 & 0x8210820;
                local_4c = local_4c + -1;
                *puVar26 = (short)uVar21 - (short)(uVar21 >> 5) | (*puVar26 | uVar12) & 0x820 |
                           (ushort)uVar17;
                puVar26 = puVar26 + 1;
              } while (local_4c != 0);
              iVar15 = local_48;
            }
            if ((((iVar5 <= (int)local_2c && (int)local_2c < iVar13) && iVar25 <= local_50) &&
                local_58 < iVar7) && *(char *)(local_2c + iVar8) == '\0') {
              if (local_58 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_50) {
                local_50 = iVar7;
              }
              local_4c = (local_50 - local_58) + 1;
              *(undefined1 *)(local_2c + iVar8) = 1;
              puVar26 = (ushort *)(local_1c + local_58 * 2 + iVar20);
              do {
                uVar12 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                         *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                         + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                uVar17 = (*puVar26 & 0xf7def7df) + (uVar12 & 0xf7def7df);
                uVar21 = uVar17 & 0x8210820;
                *puVar26 = (short)uVar21 - (short)(uVar21 >> 5) | (*puVar26 | uVar12) & 0x820 |
                           (ushort)uVar17;
                local_4c = local_4c + -1;
                puVar26 = puVar26 + 1;
              } while (local_4c != 0);
              iVar15 = local_48;
            }
            local_20 = local_20 + 1;
            local_2c = local_2c + -1;
            local_18 = local_18 + iVar2;
            param_5 = param_5 + -1;
            local_1c = local_1c - iVar2;
            if (local_74 < 0) {
              local_48 = iVar15 + param_4;
              local_14 = local_14 + -4;
              if (iVar9 <= local_48) {
                local_5c = local_5c + 1;
                local_24 = local_24 + -1;
                local_28 = local_28 + 1;
                local_48 = local_48 - iVar9;
              }
              iVar15 = (local_5c - param_5) * 4;
              local_74 = local_74 + 2 + iVar15;
              goto LAB_0077d180;
            }
            local_14 = local_14 + -4;
            local_70 = local_70 - local_14;
            local_74 = local_74 + (2 - local_14);
          }
          if (param_5 < 0) {
            FUN_0056e1d0(iVar8);
            return;
          }
        } while( true );
      }
      goto switchD_00774a8e_caseD_5;
    case 3:
      if (DAT_00dca3f8 == 0) goto switchD_00774a8e_caseD_5;
      if (local_70 < 0) {
        iVar22 = param_4;
        if (iVar9 <= param_4) {
          iVar22 = param_4 - iVar9;
        }
        local_5c = (uint)(iVar9 <= param_4);
        local_70 = local_5c * 4;
        local_74 = local_74 + local_70;
LAB_0077d221:
        local_70 = iVar4 + 5 + local_70;
      }
      else {
        param_5 = param_5 + -1;
        if (local_74 < 0) {
          iVar22 = param_4;
          if (iVar9 <= param_4) {
            iVar22 = param_4 - iVar9;
          }
          local_5c = (uint)(iVar9 <= param_4);
          local_70 = (local_5c - param_5) * 4;
          local_74 = iVar10 + 5 + local_70;
          goto LAB_0077d221;
        }
        local_70 = local_70 + param_5 * -4;
        local_74 = local_74 + param_5 * -4 + 2;
      }
      if (-1 < param_5) {
        local_14 = param_5 * 4;
        local_2c = (param_5 - param_9) + param_3;
        local_28 = (local_5c - param_8) + param_2;
        local_24 = param_2 - local_5c;
        local_20 = param_3 - param_5;
        local_1c = local_2c * iVar2;
        local_18 = local_20 * iVar2;
        do {
          if (local_70 < 0) {
            iVar22 = iVar22 + param_4;
            if (iVar9 <= iVar22) {
              local_5c = local_5c + 1;
              local_24 = local_24 + -1;
              local_28 = local_28 + 1;
              iVar22 = iVar22 - iVar9;
            }
            iVar15 = local_5c * 4;
            local_74 = local_74 + iVar15;
LAB_0077d584:
            local_70 = local_70 + 2 + iVar15;
          }
          else {
            local_58 = local_24;
            local_50 = local_28;
            if ((((iVar5 <= local_20 && iVar25 <= (int)local_28) && local_20 < iVar13) &&
                (int)local_24 < iVar7) && *(char *)(local_20 + iVar8) == '\0') {
              local_58 = iVar25;
              if (iVar25 <= (int)local_24) {
                local_58 = local_24;
              }
              if (iVar7 < (int)local_28) {
                local_50 = iVar7;
              }
              *(undefined1 *)(local_20 + iVar8) = 1;
              local_4c = (local_50 - local_58) + 1;
              puVar26 = (ushort *)(local_18 + local_58 * 2 + iVar20);
              do {
                uVar17 = (*puVar26 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f))) &
                         0xf7def7df);
                uVar21 = uVar17 & 0x8210820;
                local_4c = local_4c + -1;
                *puVar26 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar17;
                puVar26 = puVar26 + 1;
              } while (local_4c != 0);
            }
            if ((((iVar5 <= (int)local_2c && (int)local_2c < iVar13) && iVar25 <= local_50) &&
                local_58 < iVar7) && *(char *)(local_2c + iVar8) == '\0') {
              if (local_58 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_50) {
                local_50 = iVar7;
              }
              local_4c = (local_50 - local_58) + 1;
              *(undefined1 *)(local_2c + iVar8) = 1;
              puVar26 = (ushort *)(local_1c + local_58 * 2 + iVar20);
              do {
                uVar17 = (*puVar26 | 0x8210820) -
                         ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) *
                                    0x40 + *(short *)(&DAT_00d0a2e0 +
                                                     iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20
                                  + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f))) &
                         0xf7def7df);
                uVar21 = uVar17 & 0x8210820;
                *puVar26 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar17;
                local_4c = local_4c + -1;
                puVar26 = puVar26 + 1;
              } while (local_4c != 0);
            }
            local_18 = local_18 + iVar2;
            local_20 = local_20 + 1;
            local_2c = local_2c + -1;
            local_1c = local_1c - iVar2;
            param_5 = param_5 + -1;
            if (local_74 < 0) {
              iVar22 = iVar22 + param_4;
              local_14 = local_14 + -4;
              if (iVar9 <= iVar22) {
                local_5c = local_5c + 1;
                local_24 = local_24 + -1;
                local_28 = local_28 + 1;
                iVar22 = iVar22 - iVar9;
              }
              iVar15 = (local_5c - param_5) * 4;
              local_74 = local_74 + 2 + iVar15;
              goto LAB_0077d584;
            }
            local_14 = local_14 + -4;
            local_70 = local_70 - local_14;
            local_74 = local_74 + (2 - local_14);
          }
          if (param_5 < 0) {
            FUN_0056e1d0(iVar8);
            return;
          }
        } while( true );
      }
      goto switchD_00774a8e_caseD_5;
    case 4:
      if (local_70 < 0) {
        iVar22 = param_4;
        if (iVar9 <= param_4) {
          iVar22 = param_4 - iVar9;
        }
        local_5c = (uint)(iVar9 <= param_4);
        local_70 = local_5c * 4;
        local_74 = local_74 + local_70;
LAB_0077d618:
        local_70 = iVar4 + 5 + local_70;
      }
      else {
        param_5 = param_5 + -1;
        if (local_74 < 0) {
          iVar22 = param_4;
          if (iVar9 <= param_4) {
            iVar22 = param_4 - iVar9;
          }
          local_5c = (uint)(iVar9 <= param_4);
          local_70 = (local_5c - param_5) * 4;
          local_74 = iVar10 + 5 + local_70;
          goto LAB_0077d618;
        }
        local_70 = local_70 + param_5 * -4;
        local_74 = local_74 + param_5 * -4 + 2;
      }
      if (-1 < param_5) {
        local_1c = param_5 * 4;
        local_24 = (param_5 - param_9) + param_3;
        local_50 = (local_5c - param_8) + param_2;
        local_28 = param_2 - local_5c;
        local_20 = param_3 - param_5;
        local_18 = local_24 * iVar2;
        iVar23 = local_20 * iVar2;
        local_2c = local_50;
        local_14 = iVar23;
        do {
          if (local_70 < 0) {
            iVar22 = iVar22 + param_4;
            if (iVar9 <= iVar22) {
              local_5c = local_5c + 1;
              local_28 = local_28 + -1;
              local_50 = local_50 + 1;
              iVar22 = iVar22 - iVar9;
              local_2c = local_50;
            }
            iVar15 = local_5c * 4;
            local_74 = local_74 + iVar15;
LAB_0077d966:
            local_70 = local_70 + 2 + iVar15;
          }
          else {
            local_58 = local_28;
            if ((((iVar5 <= local_20 && iVar25 <= local_50) && local_20 < iVar13) &&
                (int)local_28 < iVar7) && *(char *)(local_20 + iVar8) == '\0') {
              local_58 = iVar25;
              if (iVar25 <= (int)local_28) {
                local_58 = local_28;
              }
              if (iVar7 < (int)local_2c) {
                local_50 = iVar7;
              }
              local_4c = (local_50 - local_58) + 1;
              *(undefined1 *)(local_20 + iVar8) = 1;
              puVar26 = (ushort *)(iVar23 + local_58 * 2 + iVar20);
              do {
                uVar21 = (uint)*puVar26;
                *puVar26 = (ushort)((uVar21 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                           (ushort)((uVar21 & 0xf800) * (param_6 & 0xf800) >> 0x10) & 0xf800 |
                           (ushort)((uVar21 & 0x1f) * (param_6 & 0x1f) >> 5);
                puVar26 = puVar26 + 1;
                local_4c = local_4c + -1;
              } while (local_4c != 0);
            }
            if ((((iVar5 <= (int)local_24 && (int)local_24 < iVar13) && iVar25 <= local_50) &&
                local_58 < iVar7) && *(char *)(local_24 + iVar8) == '\0') {
              if (local_58 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_50) {
                local_50 = iVar7;
              }
              local_4c = (local_50 - local_58) + 1;
              puVar26 = (ushort *)(local_18 + local_58 * 2 + iVar20);
              *(undefined1 *)(local_24 + iVar8) = 1;
              do {
                uVar21 = (uint)*puVar26;
                *puVar26 = (ushort)((uVar21 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                           (ushort)((uVar21 & 0xf800) * (param_6 & 0xf800) >> 0x10) & 0xf800 |
                           (ushort)((uVar21 & 0x1f) * (param_6 & 0x1f) >> 5);
                puVar26 = puVar26 + 1;
                local_4c = local_4c + -1;
              } while (local_4c != 0);
            }
            local_20 = local_20 + 1;
            iVar23 = local_14 + iVar2;
            local_24 = local_24 + -1;
            param_5 = param_5 + -1;
            local_18 = local_18 - iVar2;
            local_14 = iVar23;
            if (local_74 < 0) {
              iVar22 = iVar22 + param_4;
              local_1c = local_1c + -4;
              if (iVar9 <= iVar22) {
                local_5c = local_5c + 1;
                local_28 = local_28 + -1;
                local_2c = local_2c + 1;
                iVar22 = iVar22 - iVar9;
              }
              iVar15 = (local_5c - param_5) * 4;
              local_74 = local_74 + 2 + iVar15;
              local_50 = local_2c;
              goto LAB_0077d966;
            }
            local_1c = local_1c + -4;
            local_70 = local_70 - local_1c;
            local_74 = local_74 + (2 - local_1c);
            local_50 = local_2c;
          }
          if (param_5 < 0) {
            FUN_0056e1d0(iVar8);
            return;
          }
        } while( true );
      }
    default:
      goto switchD_00774a8e_caseD_5;
    case 10:
      if (local_70 < 0) {
        local_48 = param_4;
        if (iVar9 <= param_4) {
          local_48 = param_4 - iVar9;
        }
        local_5c = (uint)(iVar9 <= param_4);
        local_70 = local_5c * 4;
        local_74 = local_74 + local_70;
LAB_0077de76:
        local_70 = iVar4 + 5 + local_70;
      }
      else {
        local_40 = param_5 + -1;
        if (local_74 < 0) {
          local_48 = param_4;
          if (iVar9 <= param_4) {
            local_48 = param_4 - iVar9;
          }
          local_5c = (uint)(iVar9 <= param_4);
          local_70 = (local_5c - local_40) * 4;
          local_74 = iVar10 + 5 + local_70;
          goto LAB_0077de76;
        }
        local_70 = local_70 + local_40 * -4;
        local_74 = local_74 + local_40 * -4 + 2;
      }
      if (-1 < (int)local_40) {
        local_14 = local_40 * 4;
        local_2c = (local_40 - param_9) + param_3;
        local_28 = (local_5c - param_8) + param_2;
        local_24 = param_2 - local_5c;
        local_20 = param_3 - local_40;
        local_1c = local_2c * iVar2;
        local_18 = local_20 * iVar2;
        uVar21 = local_40;
        iVar15 = local_48;
        do {
          if (local_70 < 0) {
            local_48 = iVar15 + param_4;
            if (iVar9 <= local_48) {
              local_5c = local_5c + 1;
              local_24 = local_24 + -1;
              local_28 = local_28 + 1;
              local_48 = local_48 - iVar9;
            }
            iVar15 = local_5c * 4;
            local_74 = local_74 + iVar15;
LAB_0077e22e:
            local_70 = local_70 + 2 + iVar15;
            iVar15 = local_48;
          }
          else {
            local_58 = local_24;
            local_50 = local_28;
            if ((((iVar5 <= local_20 && iVar25 <= (int)local_28) && local_20 < iVar13) &&
                (int)local_24 < iVar7) && *(char *)(local_20 + iVar8) == '\0') {
              local_58 = iVar25;
              if (iVar25 <= (int)local_24) {
                local_58 = local_24;
              }
              if (iVar7 < (int)local_28) {
                local_50 = iVar7;
              }
              *(undefined1 *)(local_20 + iVar8) = 1;
              local_4c = (local_50 - local_58) + 1;
              uVar21 = ~param_6 & 0xffff;
              puVar26 = (ushort *)(local_18 + local_58 * 2 + iVar20);
              while( true ) {
                uVar12 = *puVar26;
                local_4c = local_4c + -1;
                *puVar26 = ((uVar12 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uVar21 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                     iVar23 * 0x800)) * 0x20 |
                           ((uVar12 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uVar21 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)
                           ) * 0x800 |
                           (uVar12 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                if (local_4c == 0) break;
                puVar26 = puVar26 + 1;
              }
              uVar21 = local_40;
              iVar15 = local_48;
            }
            if ((((iVar5 <= (int)local_2c && iVar25 <= local_50) && (int)local_2c < iVar13) &&
                local_58 < iVar7) && *(char *)(local_2c + iVar8) == '\0') {
              if (local_58 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_50) {
                local_50 = iVar7;
              }
              local_4c = (local_50 - local_58) + 1;
              *(undefined1 *)(local_2c + iVar8) = 1;
              uVar21 = ~param_6 & 0xffff;
              puVar26 = (ushort *)(local_1c + local_58 * 2 + iVar20);
              while( true ) {
                uVar12 = *puVar26;
                local_4c = local_4c + -1;
                *puVar26 = ((uVar12 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uVar21 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                     iVar23 * 0x800)) * 0x20 |
                           ((uVar12 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uVar21 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)
                           ) * 0x800 |
                           (uVar12 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                if (local_4c == 0) break;
                puVar26 = puVar26 + 1;
              }
              uVar21 = local_40;
              iVar15 = local_48;
            }
            local_18 = local_18 + iVar2;
            local_20 = local_20 + 1;
            local_2c = local_2c + -1;
            local_1c = local_1c - iVar2;
            uVar21 = uVar21 + -1;
            local_40 = uVar21;
            if (local_74 < 0) {
              local_48 = iVar15 + param_4;
              local_14 = local_14 + -4;
              if (iVar9 <= local_48) {
                local_5c = local_5c + 1;
                local_24 = local_24 + -1;
                local_28 = local_28 + 1;
                local_48 = local_48 - iVar9;
              }
              iVar15 = (local_5c - uVar21) * 4;
              local_74 = local_74 + 2 + iVar15;
              goto LAB_0077e22e;
            }
            local_14 = local_14 + -4;
            local_70 = local_70 - local_14;
            local_74 = local_74 + (2 - local_14);
          }
        } while (-1 < (int)uVar21);
      }
      goto switchD_00774a8e_caseD_5;
    case 0xb:
      if (local_70 < 0) {
        local_48 = param_4;
        if (iVar9 <= param_4) {
          local_48 = param_4 - iVar9;
        }
        local_5c = (uint)(iVar9 <= param_4);
        local_70 = local_5c * 4;
        local_74 = local_74 + local_70;
LAB_0077da0e:
        local_70 = iVar4 + 5 + local_70;
      }
      else {
        local_40 = param_5 + -1;
        if (local_74 < 0) {
          local_48 = param_4;
          if (iVar9 <= param_4) {
            local_48 = param_4 - iVar9;
          }
          local_5c = (uint)(iVar9 <= param_4);
          local_70 = (local_5c - local_40) * 4;
          local_74 = iVar10 + 5 + local_70;
          goto LAB_0077da0e;
        }
        local_70 = local_70 + local_40 * -4;
        local_74 = local_74 + local_40 * -4 + 2;
      }
      if (-1 < (int)local_40) {
        local_14 = local_40 * 4;
        local_24 = (local_40 - param_9) + param_3;
        local_2c = (local_5c - param_8) + param_2;
        local_28 = param_2 - local_5c;
        local_20 = param_3 - local_40;
        local_1c = local_24 * iVar2;
        local_18 = local_20 * iVar2;
        uVar21 = local_40;
        iVar15 = local_48;
        do {
          if (local_70 < 0) {
            local_48 = iVar15 + param_4;
            if (iVar9 <= local_48) {
              local_5c = local_5c + 1;
              local_28 = local_28 + -1;
              local_2c = local_2c + 1;
              local_48 = local_48 - iVar9;
            }
            iVar15 = local_5c * 4;
            local_74 = local_74 + iVar15;
LAB_0077ddce:
            local_70 = local_70 + 2 + iVar15;
            iVar15 = local_48;
          }
          else {
            local_50 = local_2c;
            local_58 = local_28;
            if ((((local_20 < iVar13 && (int)local_28 < iVar7) && iVar5 <= local_20) &&
                iVar25 <= (int)local_2c) && *(char *)(local_20 + iVar8) == '\0') {
              local_58 = iVar25;
              if (iVar25 <= (int)local_28) {
                local_58 = local_28;
              }
              if (iVar7 < (int)local_2c) {
                local_50 = iVar7;
              }
              *(undefined1 *)(local_20 + iVar8) = 1;
              local_4c = (local_50 - local_58) + 1;
              puVar26 = (ushort *)(local_18 + local_58 * 2 + iVar20);
              do {
                uVar12 = *puVar26;
                uVar21 = uVar12 >> 5 & 0x3f;
                local_4c = local_4c + -1;
                *puVar26 = ((uVar12 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uVar21 * (param_6 >> 5 & 0x3f) >> 6) - uVar21) * 4 +
                                     iVar23 * 0x800)) * 0x20 |
                           ((uVar12 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                     (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                           (uVar12 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((uVar12 & 0x1f) * (param_6 & 0x1f) >> 5) - (uVar12 & 0x1f)) *
                                     4 + iVar23 * 0x800);
                puVar26 = puVar26 + 1;
              } while (local_4c != 0);
              uVar21 = local_40;
              iVar15 = local_48;
            }
            if (((((int)local_24 < iVar13 && iVar25 <= local_50) && local_58 < iVar7) &&
                iVar5 <= (int)local_24) && *(char *)(local_24 + iVar8) == '\0') {
              if (local_58 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_50) {
                local_50 = iVar7;
              }
              local_4c = (local_50 - local_58) + 1;
              *(undefined1 *)(local_24 + iVar8) = 1;
              puVar26 = (ushort *)(local_1c + local_58 * 2 + iVar20);
              do {
                uVar12 = *puVar26;
                uVar21 = uVar12 >> 5 & 0x3f;
                local_4c = local_4c + -1;
                *puVar26 = ((uVar12 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uVar21 * (param_6 >> 5 & 0x3f) >> 6) - uVar21) * 4 +
                                     iVar23 * 0x800)) * 0x20 |
                           ((uVar12 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                     (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                           (uVar12 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((uVar12 & 0x1f) * (param_6 & 0x1f) >> 5) - (uVar12 & 0x1f)) *
                                     4 + iVar23 * 0x800);
                puVar26 = puVar26 + 1;
              } while (local_4c != 0);
              uVar21 = local_40;
              iVar15 = local_48;
            }
            local_18 = local_18 + iVar2;
            local_20 = local_20 + 1;
            local_24 = local_24 + -1;
            local_1c = local_1c - iVar2;
            uVar21 = uVar21 + -1;
            local_40 = uVar21;
            if (local_74 < 0) {
              local_48 = iVar15 + param_4;
              local_14 = local_14 + -4;
              if (iVar9 <= local_48) {
                local_5c = local_5c + 1;
                local_28 = local_28 + -1;
                local_2c = local_2c + 1;
                local_48 = local_48 - iVar9;
              }
              iVar15 = (local_5c - uVar21) * 4;
              local_74 = local_74 + 2 + iVar15;
              goto LAB_0077ddce;
            }
            local_14 = local_14 + -4;
            local_70 = local_70 - local_14;
            local_74 = local_74 + (2 - local_14);
          }
          if ((int)uVar21 < 0) {
            FUN_0056e1d0(iVar8);
            return;
          }
        } while( true );
      }
      goto switchD_00774a8e_caseD_5;
    }
  }
  iVar9 = (param_4 * param_4) / param_5;
  uVar21 = 0;
  iVar22 = 0;
  local_48 = 0;
  local_40 = 0;
  iVar4 = param_4 * -2;
  local_70 = iVar4 + 3;
  iVar10 = param_4 * -4;
  local_74 = iVar10 + 3;
  iVar15 = *(int *)(*(int *)(param_1 + 0x14) + 0x20);
  local_5c = param_4;
  if (iVar15 == 0) {
    if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
      param_6 = ((param_6 >> 5 & 0x3f) * (DAT_00dca3fc >> 8 & 0xff) & 0xffffff07 |
                (param_6 & 0x1f) * (DAT_00dca3fc & 0xff) >> 5) >> 3 |
                (param_6 >> 8 & 0xfffff8) * (DAT_00dca3fc >> 0x10 & 0xff) & 0xfffff800;
    }
    uVar21 = 0;
    switch(DAT_00dca3f4) {
    case 1:
      if (DAT_00dca3f8 != 0xff) {
        if (DAT_00dca3f8 != 0) {
          if (param_9 == 0) {
            iVar22 = param_2 - param_4;
            iVar15 = (param_2 - param_8) + param_4;
            if ((((iVar25 <= iVar15 && iVar5 <= param_3) && iVar22 < iVar7) && param_3 < iVar13) &&
                *(char *)(param_3 + iVar8) == '\0') {
              if (iVar22 < iVar25) {
                iVar22 = iVar25;
              }
              if (iVar7 < iVar15) {
                iVar15 = iVar7;
              }
              local_4c = (iVar15 - iVar22) + 1;
              *(undefined1 *)(param_3 + iVar8) = 1;
              local_68 = (uint *)(iVar2 * param_3 + iVar20 + iVar22 * 2);
              do {
                uVar12 = (ushort)*local_68;
                *(ushort *)local_68 =
                     ((uVar12 >> 5 & 0x3f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 + iVar23 * 0x800))
                     * 0x20 | ((uVar12 >> 0xb) +
                              *(short *)(&DAT_00d4a6e0 +
                                        ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                        iVar23 * 0x800)) * 0x800 |
                     (uVar12 & 0x1f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                local_68 = (uint *)((int)local_68 + 2);
                local_4c = local_4c + -1;
              } while (local_4c != 0);
            }
          }
          uVar21 = 0;
          bVar3 = false;
          if (local_70 < 0) {
            local_48 = param_5;
            bVar3 = iVar9 <= param_5;
            if (bVar3) {
              local_48 = param_5 - iVar9;
            }
            local_40 = (uint)bVar3;
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar4 + 5 + uVar21 * 4;
          }
          else {
            local_5c = param_4 + -1;
            if (local_74 < 0) {
              local_48 = param_5;
              bVar3 = iVar9 <= param_5;
              if (bVar3) {
                local_48 = param_5 - iVar9;
              }
              local_40 = (uint)bVar3;
              uVar21 = (uint)bVar3;
              local_74 = (uVar21 - local_5c) * 4;
              local_70 = iVar4 + 5 + local_74;
              local_74 = iVar10 + 5 + local_74;
            }
            else {
              local_70 = local_70 + local_5c * -4;
              local_74 = local_74 + local_5c * -4 + 2;
            }
          }
          uVar17 = local_5c;
          if (-1 < (int)local_5c) {
            local_18 = local_5c * 4;
            local_20 = param_3 - uVar21;
            local_2c = (uVar21 - param_9) + param_3;
            local_24 = (local_5c - param_8) + param_2;
            local_28 = param_2 - local_5c;
            local_1c = local_20 * iVar2;
            local_38 = local_2c * iVar2;
            iVar15 = local_48;
            do {
              if (bVar3) {
                local_58 = local_28;
                local_50 = local_24;
                if ((((iVar5 <= (int)local_2c && iVar25 <= (int)local_24) && (int)local_28 < iVar7)
                    && (int)local_2c < iVar13) && *(char *)(local_2c + iVar8) == '\0') {
                  local_58 = iVar25;
                  if (iVar25 <= (int)local_28) {
                    local_58 = local_28;
                  }
                  if (iVar7 < (int)local_24) {
                    local_50 = iVar7;
                  }
                  local_4c = (local_50 - local_58) + 1;
                  *(undefined1 *)(local_2c + iVar8) = 1;
                  local_68 = (uint *)(local_38 + local_58 * 2 + iVar20);
                  do {
                    uVar12 = (ushort)*local_68;
                    *(ushort *)local_68 =
                         ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800))
                         * 0x800 | (uVar12 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 +
                                             iVar23 * 0x800);
                    local_68 = (uint *)((int)local_68 + 2);
                    local_4c = local_4c + -1;
                  } while (local_4c != 0);
                  uVar17 = local_5c;
                }
                if ((((iVar5 <= local_20 && local_20 < iVar13) && iVar25 <= local_50) &&
                    local_58 < iVar7) && *(char *)(local_20 + iVar8) == '\0') {
                  if (local_58 < iVar25) {
                    local_58 = iVar25;
                  }
                  if (iVar7 < local_50) {
                    local_50 = iVar7;
                  }
                  local_4c = (local_50 - local_58) + 1;
                  *(undefined1 *)(local_20 + iVar8) = 1;
                  local_68 = (uint *)(local_1c + local_58 * 2 + iVar20);
                  do {
                    uVar12 = (ushort)*local_68;
                    *(ushort *)local_68 =
                         ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800))
                         * 0x800 | (uVar12 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 +
                                             iVar23 * 0x800);
                    local_68 = (uint *)((int)local_68 + 2);
                    local_4c = local_4c + -1;
                  } while (local_4c != 0);
                  uVar17 = local_5c;
                }
                uVar21 = local_40;
                iVar15 = local_48;
              }
              bVar3 = false;
              if (local_70 < 0) {
                local_48 = iVar15 + param_5;
                bVar3 = iVar9 <= local_48;
                if (bVar3) {
                  local_38 = local_38 + iVar2;
                  local_1c = local_1c + -iVar2;
                  local_2c = local_2c + 1;
                  local_20 = local_20 + -1;
                  uVar21 = uVar21 + 1;
                  local_48 = local_48 - iVar9;
                  local_40 = uVar21;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
                iVar15 = local_48;
              }
              else {
                local_28 = local_28 + 1;
                local_24 = local_24 + -1;
                uVar17 = uVar17 + -1;
                local_5c = uVar17;
                if (local_74 < 0) {
                  local_48 = iVar15 + param_5;
                  local_18 = local_18 + -4;
                  bVar3 = iVar9 <= local_48;
                  if (bVar3) {
                    local_2c = local_2c + 1;
                    uVar21 = uVar21 + 1;
                    local_38 = local_38 + iVar2;
                    local_1c = local_1c + -iVar2;
                    local_20 = local_20 + -1;
                    local_48 = local_48 - iVar9;
                    local_40 = uVar21;
                  }
                  iVar15 = (uVar21 - uVar17) * 4;
                  local_70 = local_70 + 2 + iVar15;
                  local_74 = local_74 + 2 + iVar15;
                  iVar15 = local_48;
                }
                else {
                  local_18 = local_18 + -4;
                  local_70 = local_70 - local_18;
                  local_74 = local_74 + (2 - local_18);
                }
              }
            } while (-1 < (int)uVar17);
          }
          iVar15 = param_2 - uVar17;
          param_2 = (uVar17 - param_8) + param_2;
          param_3 = param_3 - uVar21;
          if ((((iVar5 <= param_3 && iVar25 <= param_2) && param_3 < iVar13) && iVar15 < iVar7) &&
              *(char *)(param_3 + iVar8) == '\0') {
            if (iVar15 < iVar25) {
              iVar15 = iVar25;
            }
            if (iVar7 < param_2) {
              param_2 = iVar7;
            }
            *(undefined1 *)(param_3 + iVar8) = 1;
            local_4c = (param_2 - iVar15) + 1;
            puVar26 = (ushort *)(param_3 * iVar2 + iVar20 + iVar15 * 2);
            while( true ) {
              uVar12 = *puVar26;
              local_4c = local_4c + -1;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800))
                         * 0x800 | (uVar12 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 +
                                             iVar23 * 0x800);
              if (local_4c == 0) break;
              puVar26 = puVar26 + 1;
            }
            FUN_0056e1d0(iVar8);
            return;
          }
        }
        break;
      }
    case 0:
      if (param_9 == 0) {
        iVar15 = param_2 - param_4;
        iVar23 = (param_2 - param_8) + param_4;
        if ((((iVar25 <= iVar23 && iVar5 <= param_3) && iVar15 < iVar7) && param_3 < iVar13) &&
            *(char *)(iVar8 + param_3) == '\0') {
          if (iVar15 < iVar25) {
            iVar15 = iVar25;
          }
          if (iVar7 < iVar23) {
            iVar23 = iVar7;
          }
          *(undefined1 *)(iVar8 + param_3) = 1;
          iVar23 = (iVar23 - iVar15) + 1;
          puVar16 = (undefined2 *)(iVar2 * param_3 + iVar20 + iVar15 * 2);
          do {
            *puVar16 = (ushort)param_6;
            puVar16 = puVar16 + 1;
            iVar23 = iVar23 + -1;
          } while (iVar23 != 0);
        }
      }
      bVar3 = false;
      if (local_70 < 0) {
        bVar3 = iVar9 <= param_5;
        iVar22 = param_5;
        if (bVar3) {
          iVar22 = param_5 - iVar9;
        }
        uVar21 = (uint)bVar3;
        local_74 = local_74 + uVar21 * 4;
        local_70 = iVar4 + 5 + uVar21 * 4;
      }
      else {
        param_4 = param_4 + -1;
        if (local_74 < 0) {
          bVar3 = iVar9 <= param_5;
          iVar22 = param_5;
          if (bVar3) {
            iVar22 = param_5 - iVar9;
          }
          uVar21 = (uint)bVar3;
          local_74 = (uVar21 - param_4) * 4;
          local_70 = iVar4 + 5 + local_74;
          local_74 = iVar10 + 5 + local_74;
        }
        else {
          local_70 = local_70 + param_4 * -4;
          local_74 = local_74 + param_4 * -4 + 2;
        }
      }
      if (-1 < param_4) {
        local_18 = param_4 * 4;
        local_34 = param_3 - uVar21;
        local_30 = (uVar21 - param_9) + param_3;
        local_2c = param_2 - param_4;
        local_28 = local_34 * iVar2;
        local_50 = (param_4 - param_8) + param_2;
        local_24 = local_30 * iVar2;
        local_20 = local_50;
        do {
          if (bVar3) {
            local_58 = local_2c;
            if ((((iVar5 <= (int)local_30 && iVar25 <= local_20) && (int)local_2c < iVar7) &&
                (int)local_30 < iVar13) && *(char *)(local_30 + iVar8) == '\0') {
              local_58 = iVar25;
              if (iVar25 <= (int)local_2c) {
                local_58 = local_2c;
              }
              if (iVar7 < local_20) {
                local_50 = iVar7;
              }
              *(undefined1 *)(local_30 + iVar8) = 1;
              iVar23 = (local_50 - local_58) + 1;
              puVar16 = (undefined2 *)(local_24 + local_58 * 2 + iVar20);
              do {
                *puVar16 = (ushort)param_6;
                puVar16 = puVar16 + 1;
                iVar23 = iVar23 + -1;
              } while (iVar23 != 0);
            }
            if ((((iVar5 <= (int)local_34 && (int)local_34 < iVar13) && iVar25 <= local_50) &&
                local_58 < iVar7) && *(char *)(local_34 + iVar8) == '\0') {
              if (local_58 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_50) {
                local_50 = iVar7;
              }
              iVar23 = (local_50 - local_58) + 1;
              *(undefined1 *)(local_34 + iVar8) = 1;
              puVar16 = (undefined2 *)(local_28 + local_58 * 2 + iVar20);
              do {
                *puVar16 = (ushort)param_6;
                puVar16 = puVar16 + 1;
                iVar23 = iVar23 + -1;
              } while (iVar23 != 0);
            }
            local_50 = local_20;
          }
          bVar3 = false;
          if (local_70 < 0) {
            iVar22 = iVar22 + param_5;
            bVar3 = iVar9 <= iVar22;
            if (bVar3) {
              local_24 = local_24 + iVar2;
              local_28 = local_28 + -iVar2;
              local_30 = local_30 + 1;
              local_34 = local_34 + -1;
              uVar21 = uVar21 + 1;
              iVar22 = iVar22 - iVar9;
            }
            local_74 = local_74 + uVar21 * 4;
            local_70 = local_70 + 2 + uVar21 * 4;
          }
          else {
            local_2c = local_2c + 1;
            local_50 = local_50 + -1;
            param_4 = param_4 + -1;
            local_20 = local_50;
            if (local_74 < 0) {
              iVar22 = iVar22 + param_5;
              local_18 = local_18 + -4;
              bVar3 = iVar9 <= iVar22;
              if (bVar3) {
                local_24 = local_24 + iVar2;
                local_28 = local_28 + -iVar2;
                local_30 = local_30 + 1;
                local_34 = local_34 + -1;
                uVar21 = uVar21 + 1;
                iVar22 = iVar22 - iVar9;
              }
              iVar23 = (uVar21 - param_4) * 4;
              local_70 = local_70 + 2 + iVar23;
              local_74 = local_74 + 2 + iVar23;
            }
            else {
              local_18 = local_18 + -4;
              local_70 = local_70 - local_18;
              local_74 = local_74 + (2 - local_18);
            }
          }
        } while (-1 < param_4);
      }
      iVar23 = param_2 - param_4;
      param_3 = param_3 - uVar21;
      param_2 = (param_4 - param_8) + param_2;
      if ((((iVar5 <= param_3 && iVar25 <= param_2) && param_3 < iVar13) && iVar23 < iVar7) &&
          *(char *)(param_3 + iVar8) == '\0') {
        if (iVar23 < iVar25) {
          iVar23 = iVar25;
        }
        if (iVar7 < param_2) {
          param_2 = iVar7;
        }
        *(undefined1 *)(param_3 + iVar8) = 1;
        iVar25 = (param_2 - iVar23) + 1;
        puVar16 = (undefined2 *)(param_3 * iVar2 + iVar20 + iVar23 * 2);
        do {
          *puVar16 = (ushort)param_6;
          puVar16 = puVar16 + 1;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        FUN_0056e1d0(iVar8);
        return;
      }
      break;
    case 2:
      if (DAT_00dca3f8 != 0) {
        if (param_9 == 0) {
          iVar22 = param_2 - param_4;
          iVar15 = (param_2 - param_8) + param_4;
          if ((((iVar25 <= iVar15 && iVar5 <= param_3) && iVar22 < iVar7) && param_3 < iVar13) &&
              *(char *)(param_3 + iVar8) == '\0') {
            if (iVar22 < iVar25) {
              iVar22 = iVar25;
            }
            if (iVar7 < iVar15) {
              iVar15 = iVar7;
            }
            local_4c = (iVar15 - iVar22) + 1;
            *(undefined1 *)(param_3 + iVar8) = 1;
            local_68 = (uint *)(iVar2 * param_3 + iVar20 + iVar22 * 2);
            do {
              uVar12 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                       *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20 +
                       *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
              uVar17 = ((ushort)*local_68 & 0xf7def7df) + (uVar12 & 0xf7def7df);
              uVar21 = uVar17 & 0x8210820;
              *(ushort *)local_68 =
                   (short)uVar21 - (short)(uVar21 >> 5) | ((ushort)*local_68 | uVar12) & 0x820 |
                   (ushort)uVar17;
              local_68 = (uint *)((int)local_68 + 2);
              local_4c = local_4c + -1;
            } while (local_4c != 0);
          }
        }
        uVar21 = 0;
        bVar3 = false;
        if (local_70 < 0) {
          local_48 = param_5;
          bVar3 = iVar9 <= param_5;
          if (bVar3) {
            local_48 = param_5 - iVar9;
          }
          local_40 = (uint)bVar3;
          uVar21 = (uint)bVar3;
          local_74 = local_74 + uVar21 * 4;
          local_70 = iVar4 + 5 + uVar21 * 4;
        }
        else {
          param_4 = param_4 + -1;
          if (local_74 < 0) {
            local_48 = param_5;
            bVar3 = iVar9 <= param_5;
            if (bVar3) {
              local_48 = param_5 - iVar9;
            }
            local_40 = (uint)bVar3;
            uVar21 = (uint)bVar3;
            local_74 = (uVar21 - param_4) * 4;
            local_70 = iVar4 + 5 + local_74;
            local_74 = iVar10 + 5 + local_74;
          }
          else {
            local_70 = local_70 + param_4 * -4;
            local_74 = local_74 + param_4 * -4 + 2;
          }
        }
        if (-1 < param_4) {
          local_18 = param_4 * 4;
          local_24 = param_3 - uVar21;
          local_2c = (uVar21 - param_9) + param_3;
          local_20 = (param_4 - param_8) + param_2;
          local_28 = param_2 - param_4;
          local_30 = local_24 * iVar2;
          local_1c = local_2c * iVar2;
          iVar15 = local_48;
          do {
            if (bVar3) {
              local_50 = local_20;
              local_58 = local_28;
              if (((((int)local_28 < iVar7 && (int)local_2c < iVar13) && iVar5 <= (int)local_2c) &&
                  iVar25 <= local_20) && *(char *)(iVar8 + local_2c) == '\0') {
                local_58 = iVar25;
                if (iVar25 <= (int)local_28) {
                  local_58 = local_28;
                }
                if (iVar7 < local_20) {
                  local_50 = iVar7;
                }
                *(undefined1 *)(iVar8 + local_2c) = 1;
                local_4c = (local_50 - local_58) + 1;
                local_68 = (uint *)(local_1c + local_58 * 2 + iVar20);
                do {
                  uVar12 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                           *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) *
                           0x20 + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                  uVar17 = ((ushort)*local_68 & 0xf7def7df) + (uVar12 & 0xf7def7df);
                  uVar21 = uVar17 & 0x8210820;
                  *(ushort *)local_68 =
                       (short)uVar21 - (short)(uVar21 >> 5) | ((ushort)*local_68 | uVar12) & 0x820 |
                       (ushort)uVar17;
                  local_68 = (uint *)((int)local_68 + 2);
                  local_4c = local_4c + -1;
                } while (local_4c != 0);
              }
              if (((((int)local_24 < iVar13 && iVar25 <= local_50) && iVar5 <= (int)local_24) &&
                  local_58 < iVar7) && *(char *)(iVar8 + local_24) == '\0') {
                if (local_58 < iVar25) {
                  local_58 = iVar25;
                }
                if (iVar7 < local_50) {
                  local_50 = iVar7;
                }
                local_4c = (local_50 - local_58) + 1;
                local_68 = (uint *)(local_30 + local_58 * 2 + iVar20);
                *(undefined1 *)(iVar8 + local_24) = 1;
                do {
                  uVar12 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                           *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) *
                           0x20 + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
                  uVar17 = ((ushort)*local_68 & 0xf7def7df) + (uVar12 & 0xf7def7df);
                  uVar21 = uVar17 & 0x8210820;
                  *(ushort *)local_68 =
                       (short)uVar21 - (short)(uVar21 >> 5) | ((ushort)*local_68 | uVar12) & 0x820 |
                       (ushort)uVar17;
                  local_68 = (uint *)((int)local_68 + 2);
                  local_4c = local_4c + -1;
                } while (local_4c != 0);
              }
              uVar21 = local_40;
              iVar15 = local_48;
            }
            bVar3 = false;
            if (local_70 < 0) {
              local_48 = iVar15 + param_5;
              bVar3 = iVar9 <= local_48;
              if (bVar3) {
                local_2c = local_2c + 1;
                uVar21 = uVar21 + 1;
                local_1c = local_1c + iVar2;
                local_30 = local_30 + -iVar2;
                local_24 = local_24 + -1;
                local_48 = local_48 - iVar9;
                local_40 = uVar21;
              }
              local_74 = local_74 + uVar21 * 4;
              local_70 = local_70 + 2 + uVar21 * 4;
              iVar15 = local_48;
            }
            else {
              local_28 = local_28 + 1;
              local_20 = local_20 + -1;
              param_4 = param_4 + -1;
              if (local_74 < 0) {
                local_48 = iVar15 + param_5;
                local_18 = local_18 + -4;
                bVar3 = iVar9 <= local_48;
                if (bVar3) {
                  local_2c = local_2c + 1;
                  uVar21 = uVar21 + 1;
                  local_1c = local_1c + iVar2;
                  local_30 = local_30 + -iVar2;
                  local_24 = local_24 + -1;
                  local_48 = local_48 - iVar9;
                  local_40 = uVar21;
                }
                iVar15 = (uVar21 - param_4) * 4;
                local_70 = local_70 + 2 + iVar15;
                local_74 = local_74 + 2 + iVar15;
                iVar15 = local_48;
              }
              else {
                local_18 = local_18 + -4;
                local_70 = local_70 - local_18;
                local_74 = local_74 + (2 - local_18);
              }
            }
          } while (-1 < param_4);
        }
        iVar15 = param_2 - param_4;
        param_2 = (param_4 - param_8) + param_2;
        param_3 = param_3 - uVar21;
        if ((((iVar5 <= param_3 && iVar25 <= param_2) && param_3 < iVar13) && iVar15 < iVar7) &&
            *(char *)(param_3 + iVar8) == '\0') {
          if (iVar15 < iVar25) {
            iVar15 = iVar25;
          }
          if (iVar7 < param_2) {
            param_2 = iVar7;
          }
          *(undefined1 *)(param_3 + iVar8) = 1;
          puVar26 = (ushort *)(param_3 * iVar2 + iVar20 + iVar15 * 2);
          iVar25 = (param_2 - iVar15) + 1;
          do {
            uVar12 = (*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40 +
                     *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20 +
                     *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f));
            uVar17 = (*puVar26 & 0xf7def7df) + (uVar12 & 0xf7def7df);
            uVar21 = uVar17 & 0x8210820;
            *puVar26 = (short)uVar21 - (short)(uVar21 >> 5) | (*puVar26 | uVar12) & 0x820 |
                       (ushort)uVar17;
            puVar26 = puVar26 + 1;
            iVar25 = iVar25 + -1;
          } while (iVar25 != 0);
          FUN_0056e1d0(iVar8);
          return;
        }
      }
      break;
    case 3:
      if (DAT_00dca3f8 != 0) {
        if (param_9 == 0) {
          iVar22 = param_2 - param_4;
          iVar15 = (param_2 - param_8) + param_4;
          if ((((iVar25 <= iVar15 && iVar5 <= param_3) && iVar22 < iVar7) && param_3 < iVar13) &&
              *(char *)(param_3 + iVar8) == '\0') {
            if (iVar22 < iVar25) {
              iVar22 = iVar25;
            }
            if (iVar7 < iVar15) {
              iVar15 = iVar7;
            }
            local_4c = (iVar15 - iVar22) + 1;
            *(undefined1 *)(param_3 + iVar8) = 1;
            puVar26 = (ushort *)(iVar2 * param_3 + iVar20 + iVar22 * 2);
            do {
              uVar17 = (*puVar26 | 0x8210820) -
                       ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) *
                                  0x40 + *(short *)(&DAT_00d0a2e0 +
                                                   iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) * 0x20 +
                                *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f))) &
                       0xf7def7df);
              uVar21 = uVar17 & 0x8210820;
              *puVar26 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar17;
              puVar26 = puVar26 + 1;
              local_4c = local_4c + -1;
            } while (local_4c != 0);
          }
        }
        uVar21 = 0;
        bVar3 = false;
        if (local_70 < 0) {
          local_48 = param_5;
          bVar3 = iVar9 <= param_5;
          if (bVar3) {
            local_48 = param_5 - iVar9;
          }
          local_40 = (uint)bVar3;
          uVar21 = (uint)bVar3;
          local_74 = local_74 + uVar21 * 4;
          local_70 = iVar4 + 5 + uVar21 * 4;
        }
        else {
          param_4 = param_4 + -1;
          if (local_74 < 0) {
            local_48 = param_5;
            bVar3 = iVar9 <= param_5;
            if (bVar3) {
              local_48 = param_5 - iVar9;
            }
            local_40 = (uint)bVar3;
            uVar21 = (uint)bVar3;
            local_74 = (uVar21 - param_4) * 4;
            local_70 = iVar4 + 5 + local_74;
            local_74 = iVar10 + 5 + local_74;
          }
          else {
            local_70 = local_70 + param_4 * -4;
            local_74 = local_74 + param_4 * -4 + 2;
          }
        }
        if (-1 < param_4) {
          local_18 = param_4 * 4;
          local_28 = param_3 - uVar21;
          local_2c = (uVar21 - param_9) + param_3;
          local_24 = (param_4 - param_8) + param_2;
          local_20 = param_2 - param_4;
          local_30 = local_28 * iVar2;
          local_1c = local_2c * iVar2;
          iVar15 = local_48;
          do {
            if (bVar3) {
              local_58 = local_20;
              local_50 = local_24;
              if ((((iVar5 <= (int)local_2c && iVar25 <= (int)local_24) && local_20 < iVar7) &&
                  (int)local_2c < iVar13) && *(char *)(iVar8 + local_2c) == '\0') {
                local_58 = iVar25;
                if (iVar25 <= local_20) {
                  local_58 = local_20;
                }
                if (iVar7 < (int)local_24) {
                  local_50 = iVar7;
                }
                *(undefined1 *)(iVar8 + local_2c) = 1;
                local_4c = (local_50 - local_58) + 1;
                puVar26 = (ushort *)(local_1c + local_58 * 2 + iVar20);
                do {
                  uVar17 = (*puVar26 | 0x8210820) -
                           ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb))
                                      * 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                         iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) *
                                     0x20 + *(short *)(&DAT_00d0a2e0 +
                                                      iVar23 * 0x100 + (param_6 & 0x1f))) &
                           0xf7def7df);
                  uVar21 = uVar17 & 0x8210820;
                  *puVar26 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar17;
                  puVar26 = puVar26 + 1;
                  local_4c = local_4c + -1;
                } while (local_4c != 0);
              }
              if ((((iVar5 <= (int)local_28 && iVar25 <= local_50) && (int)local_28 < iVar13) &&
                  local_58 < iVar7) && *(char *)(iVar8 + local_28) == '\0') {
                if (local_58 < iVar25) {
                  local_58 = iVar25;
                }
                if (iVar7 < local_50) {
                  local_50 = iVar7;
                }
                local_4c = (local_50 - local_58) + 1;
                *(undefined1 *)(iVar8 + local_28) = 1;
                puVar26 = (ushort *)(local_30 + local_58 * 2 + iVar20);
                do {
                  uVar17 = (*puVar26 | 0x8210820) -
                           ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb))
                                      * 0x40 + *(short *)(&DAT_00d0a2e0 +
                                                         iVar23 * 0x100 + (param_6 >> 5 & 0x3f))) *
                                     0x20 + *(short *)(&DAT_00d0a2e0 +
                                                      iVar23 * 0x100 + (param_6 & 0x1f))) &
                           0xf7def7df);
                  uVar21 = uVar17 & 0x8210820;
                  *puVar26 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar17;
                  puVar26 = puVar26 + 1;
                  local_4c = local_4c + -1;
                } while (local_4c != 0);
              }
              uVar21 = local_40;
              iVar15 = local_48;
            }
            bVar3 = false;
            if (local_70 < 0) {
              local_48 = iVar15 + param_5;
              bVar3 = iVar9 <= local_48;
              if (bVar3) {
                local_2c = local_2c + 1;
                uVar21 = uVar21 + 1;
                local_1c = local_1c + iVar2;
                local_30 = local_30 + -iVar2;
                local_28 = local_28 + -1;
                local_48 = local_48 - iVar9;
                local_40 = uVar21;
              }
              local_74 = local_74 + uVar21 * 4;
              local_70 = local_70 + 2 + uVar21 * 4;
              iVar15 = local_48;
            }
            else {
              local_20 = local_20 + 1;
              local_24 = local_24 + -1;
              param_4 = param_4 + -1;
              if (local_74 < 0) {
                local_48 = iVar15 + param_5;
                local_18 = local_18 + -4;
                bVar3 = iVar9 <= local_48;
                if (bVar3) {
                  local_2c = local_2c + 1;
                  uVar21 = uVar21 + 1;
                  local_1c = local_1c + iVar2;
                  local_30 = local_30 + -iVar2;
                  local_28 = local_28 + -1;
                  local_48 = local_48 - iVar9;
                  local_40 = uVar21;
                }
                iVar15 = (uVar21 - param_4) * 4;
                local_70 = local_70 + 2 + iVar15;
                local_74 = local_74 + 2 + iVar15;
                iVar15 = local_48;
              }
              else {
                local_18 = local_18 + -4;
                local_70 = local_70 - local_18;
                local_74 = local_74 + (2 - local_18);
              }
            }
          } while (-1 < param_4);
        }
        iVar15 = param_2 - param_4;
        param_2 = (param_4 - param_8) + param_2;
        param_3 = param_3 - uVar21;
        if ((((iVar5 <= param_3 && iVar25 <= param_2) && param_3 < iVar13) && iVar15 < iVar7) &&
            *(char *)(param_3 + iVar8) == '\0') {
          if (iVar15 < iVar25) {
            iVar15 = iVar25;
          }
          if (iVar7 < param_2) {
            param_2 = iVar7;
          }
          *(undefined1 *)(param_3 + iVar8) = 1;
          iVar25 = (param_2 - iVar15) + 1;
          puVar26 = (ushort *)(param_3 * iVar2 + iVar20 + iVar15 * 2);
          do {
            uVar17 = (*puVar26 | 0x8210820) -
                     ((ushort)((*(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 0xb)) * 0x40
                               + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 >> 5 & 0x3f)))
                               * 0x20 + *(short *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0x1f)
                                                  )) & 0xf7def7df);
            uVar21 = uVar17 & 0x8210820;
            iVar25 = iVar25 + -1;
            *puVar26 = (short)uVar21 - (short)(uVar21 >> 5) & (ushort)uVar17;
            puVar26 = puVar26 + 1;
          } while (iVar25 != 0);
          FUN_0056e1d0(iVar8);
          return;
        }
      }
      break;
    case 4:
      if (param_9 == 0) {
        iVar23 = param_2 - param_4;
        iVar15 = (param_2 - param_8) + param_4;
        if ((((iVar25 <= iVar15 && iVar5 <= param_3) && iVar23 < iVar7) && param_3 < iVar13) &&
            *(char *)(param_3 + iVar8) == '\0') {
          if (iVar23 < iVar25) {
            iVar23 = iVar25;
          }
          if (iVar7 < iVar15) {
            iVar15 = iVar7;
          }
          local_4c = (iVar15 - iVar23) + 1;
          *(undefined1 *)(param_3 + iVar8) = 1;
          puVar26 = (ushort *)(iVar2 * param_3 + iVar20 + iVar23 * 2);
          do {
            uVar21 = (uint)*puVar26;
            *puVar26 = (ushort)((uVar21 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                       (ushort)((uVar21 & 0xf800) * (param_6 & 0xf800) >> 0x10) & 0xf800 |
                       (ushort)((uVar21 & 0x1f) * (param_6 & 0x1f) >> 5);
            puVar26 = puVar26 + 1;
            local_4c = local_4c + -1;
          } while (local_4c != 0);
        }
      }
      uVar21 = 0;
      bVar3 = false;
      if (local_70 < 0) {
        local_48 = param_5;
        bVar3 = iVar9 <= param_5;
        if (bVar3) {
          local_48 = param_5 - iVar9;
        }
        local_40 = (uint)bVar3;
        uVar21 = (uint)bVar3;
        local_74 = local_74 + uVar21 * 4;
        local_70 = iVar4 + 5 + uVar21 * 4;
      }
      else {
        param_4 = param_4 + -1;
        if (local_74 < 0) {
          local_48 = param_5;
          bVar3 = iVar9 <= param_5;
          if (bVar3) {
            local_48 = param_5 - iVar9;
          }
          local_40 = (uint)bVar3;
          uVar21 = (uint)bVar3;
          local_74 = (uVar21 - param_4) * 4;
          local_70 = iVar4 + 5 + local_74;
          local_74 = iVar10 + 5 + local_74;
        }
        else {
          local_70 = local_70 + param_4 * -4;
          local_74 = local_74 + param_4 * -4 + 2;
        }
      }
      if (-1 < param_4) {
        local_18 = param_4 * 4;
        local_28 = param_3 - uVar21;
        local_30 = (uVar21 - param_9) + param_3;
        local_24 = (param_4 - param_8) + param_2;
        local_20 = param_2 - param_4;
        local_1c = local_28 * iVar2;
        uVar17 = local_30 * iVar2;
        iVar23 = local_48;
        local_2c = uVar17;
        do {
          if (bVar3) {
            local_50 = local_24;
            local_58 = local_20;
            if ((((iVar5 <= (int)local_30 && iVar25 <= (int)local_24) && local_20 < iVar7) &&
                (int)local_30 < iVar13) && *(char *)(local_30 + iVar8) == '\0') {
              if (local_20 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < (int)local_24) {
                local_50 = iVar7;
              }
              *(undefined1 *)(local_30 + iVar8) = 1;
              local_4c = (local_50 - local_58) + 1;
              puVar26 = (ushort *)(uVar17 + local_58 * 2 + iVar20);
              do {
                uVar21 = (uint)*puVar26;
                *puVar26 = (ushort)((uVar21 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                           (ushort)((uVar21 & 0xf800) * (param_6 & 0xf800) >> 0x10) & 0xf800 |
                           (ushort)((uVar21 & 0x1f) * (param_6 & 0x1f) >> 5);
                puVar26 = puVar26 + 1;
                local_4c = local_4c + -1;
              } while (local_4c != 0);
              uVar17 = local_2c;
            }
            if ((((iVar5 <= (int)local_28 && (int)local_28 < iVar13) && iVar25 <= local_50) &&
                local_58 < iVar7) && *(char *)(local_28 + iVar8) == '\0') {
              if (local_58 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_50) {
                local_50 = iVar7;
              }
              local_4c = (local_50 - local_58) + 1;
              *(undefined1 *)(local_28 + iVar8) = 1;
              puVar26 = (ushort *)(local_1c + local_58 * 2 + iVar20);
              do {
                uVar21 = (uint)*puVar26;
                *puVar26 = (ushort)((uVar21 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                           (ushort)((uVar21 & 0xf800) * (param_6 & 0xf800) >> 0x10) & 0xf800 |
                           (ushort)((uVar21 & 0x1f) * (param_6 & 0x1f) >> 5);
                puVar26 = puVar26 + 1;
                local_4c = local_4c + -1;
              } while (local_4c != 0);
              uVar17 = local_2c;
            }
            uVar21 = local_40;
            iVar23 = local_48;
          }
          bVar3 = false;
          if (local_70 < 0) {
            local_48 = iVar23 + param_5;
            bVar3 = iVar9 <= local_48;
            if (bVar3) {
              local_1c = local_1c + -iVar2;
              uVar17 = uVar17 + iVar2;
              local_30 = local_30 + 1;
              local_28 = local_28 + -1;
              uVar21 = uVar21 + 1;
              local_48 = local_48 - iVar9;
              local_40 = uVar21;
              local_2c = uVar17;
            }
            local_74 = local_74 + uVar21 * 4;
            local_70 = local_70 + 2 + uVar21 * 4;
            iVar23 = local_48;
          }
          else {
            local_20 = local_20 + 1;
            local_24 = local_24 + -1;
            param_4 = param_4 + -1;
            if (local_74 < 0) {
              local_48 = iVar23 + param_5;
              local_18 = local_18 + -4;
              bVar3 = iVar9 <= local_48;
              if (bVar3) {
                local_30 = local_30 + 1;
                uVar17 = uVar17 + iVar2;
                uVar21 = uVar21 + 1;
                local_1c = local_1c + -iVar2;
                local_28 = local_28 + -1;
                local_48 = local_48 - iVar9;
                local_40 = uVar21;
                local_2c = uVar17;
              }
              iVar23 = (uVar21 - param_4) * 4;
              local_70 = local_70 + 2 + iVar23;
              local_74 = local_74 + 2 + iVar23;
              iVar23 = local_48;
            }
            else {
              local_18 = local_18 + -4;
              local_70 = local_70 - local_18;
              local_74 = local_74 + (2 - local_18);
            }
          }
        } while (-1 < param_4);
      }
      iVar23 = param_2 - param_4;
      param_3 = param_3 - uVar21;
      param_2 = (param_4 - param_8) + param_2;
      if ((((iVar5 <= param_3 && iVar25 <= param_2) && param_3 < iVar13) && iVar23 < iVar7) &&
          *(char *)(param_3 + iVar8) == '\0') {
        if (iVar23 < iVar25) {
          iVar23 = iVar25;
        }
        if (iVar7 < param_2) {
          param_2 = iVar7;
        }
        *(undefined1 *)(param_3 + iVar8) = 1;
        local_4c = (param_2 - iVar23) + 1;
        puVar26 = (ushort *)(param_3 * iVar2 + iVar20 + iVar23 * 2);
        do {
          uVar21 = (uint)*puVar26;
          *puVar26 = (ushort)((uVar21 & 0x7e0) * (param_6 & 0x7e0) >> 0xb) & 0x7e0 |
                     (ushort)((uVar21 & 0xf800) * (param_6 & 0xf800) >> 0x10) & 0xf800 |
                     (ushort)((uVar21 & 0x1f) * (param_6 & 0x1f) >> 5);
          puVar26 = puVar26 + 1;
          local_4c = local_4c + -1;
        } while (local_4c != 0);
        FUN_0056e1d0(iVar8);
        return;
      }
      break;
    case 10:
      if (param_9 == 0) {
        iVar22 = param_2 - param_4;
        iVar15 = (param_2 - param_8) + param_4;
        if ((((iVar25 <= iVar15 && iVar5 <= param_3) && iVar22 < iVar7) && param_3 < iVar13) &&
            *(char *)(param_3 + iVar8) == '\0') {
          if (iVar22 < iVar25) {
            iVar22 = iVar25;
          }
          if (iVar7 < iVar15) {
            iVar15 = iVar7;
          }
          local_4c = (iVar15 - iVar22) + 1;
          *(undefined1 *)(param_3 + iVar8) = 1;
          local_68 = (uint *)(iVar2 * param_3 + iVar20 + iVar22 * 2);
          uVar21 = ~param_6 & 0xffff;
          do {
            uVar12 = (ushort)*local_68;
            *(ushort *)local_68 =
                 ((uVar12 >> 5 & 0x3f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((uVar21 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 + iVar23 * 0x800)) *
                 0x20 | ((uVar12 >> 0xb) +
                        *(short *)(&DAT_00d4a6e0 +
                                  ((uVar21 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) *
                        0x800 |
                 (uVar12 & 0x1f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
            local_68 = (uint *)((int)local_68 + 2);
            local_4c = local_4c + -1;
          } while (local_4c != 0);
        }
      }
      uVar21 = 0;
      bVar3 = false;
      if (local_70 < 0) {
        local_48 = param_5;
        bVar3 = iVar9 <= param_5;
        if (bVar3) {
          local_48 = param_5 - iVar9;
        }
        local_40 = (uint)bVar3;
        uVar21 = (uint)bVar3;
        local_74 = local_74 + uVar21 * 4;
        local_70 = iVar4 + 5 + uVar21 * 4;
      }
      else {
        local_5c = param_4 + -1;
        if (local_74 < 0) {
          local_48 = param_5;
          bVar3 = iVar9 <= param_5;
          if (bVar3) {
            local_48 = param_5 - iVar9;
          }
          local_40 = (uint)bVar3;
          uVar21 = (uint)bVar3;
          local_74 = (uVar21 - local_5c) * 4;
          local_70 = iVar4 + 5 + local_74;
          local_74 = iVar10 + 5 + local_74;
        }
        else {
          local_70 = local_70 + local_5c * -4;
          local_74 = local_74 + local_5c * -4 + 2;
        }
      }
      uVar17 = local_5c;
      if (-1 < (int)local_5c) {
        local_14 = local_5c * 4;
        local_28 = param_3 - uVar21;
        local_2c = (uVar21 - param_9) + param_3;
        local_24 = (local_5c - param_8) + param_2;
        local_20 = param_2 - local_5c;
        local_1c = local_28 * iVar2;
        local_18 = local_2c * iVar2;
        iVar15 = local_48;
        do {
          if (bVar3) {
            local_58 = local_20;
            local_50 = local_24;
            if ((((iVar5 <= (int)local_2c && iVar25 <= (int)local_24) && local_20 < iVar7) &&
                (int)local_2c < iVar13) && *(char *)(local_2c + iVar8) == '\0') {
              local_58 = iVar25;
              if (iVar25 <= local_20) {
                local_58 = local_20;
              }
              if (iVar7 < (int)local_24) {
                local_50 = iVar7;
              }
              local_4c = (local_50 - local_58) + 1;
              local_68 = (uint *)(local_18 + local_58 * 2 + iVar20);
              uVar21 = ~param_6 & 0xffff;
              *(undefined1 *)(local_2c + iVar8) = 1;
              do {
                uVar12 = (ushort)*local_68;
                *(ushort *)local_68 =
                     ((uVar12 >> 5 & 0x3f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((uVar21 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 + iVar23 * 0x800))
                     * 0x20 | ((uVar12 >> 0xb) +
                              *(short *)(&DAT_00d4a6e0 +
                                        ((uVar21 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                        iVar23 * 0x800)) * 0x800 |
                     (uVar12 & 0x1f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                local_68 = (uint *)((int)local_68 + 2);
                local_4c = local_4c + -1;
              } while (local_4c != 0);
              uVar17 = local_5c;
            }
            if ((((iVar5 <= (int)local_28 && (int)local_28 < iVar13) && iVar25 <= local_50) &&
                local_58 < iVar7) && *(char *)(local_28 + iVar8) == '\0') {
              if (local_58 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_50) {
                local_50 = iVar7;
              }
              local_4c = (local_50 - local_58) + 1;
              local_68 = (uint *)(local_1c + local_58 * 2 + iVar20);
              uVar21 = ~param_6 & 0xffff;
              *(undefined1 *)(local_28 + iVar8) = 1;
              do {
                uVar12 = (ushort)*local_68;
                *(ushort *)local_68 =
                     ((uVar12 >> 5 & 0x3f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((uVar21 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 + iVar23 * 0x800))
                     * 0x20 | ((uVar12 >> 0xb) +
                              *(short *)(&DAT_00d4a6e0 +
                                        ((uVar21 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                        iVar23 * 0x800)) * 0x800 |
                     (uVar12 & 0x1f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
                local_68 = (uint *)((int)local_68 + 2);
                local_4c = local_4c + -1;
              } while (local_4c != 0);
              uVar17 = local_5c;
            }
            uVar21 = local_40;
            iVar15 = local_48;
          }
          bVar3 = false;
          if (local_70 < 0) {
            local_48 = iVar15 + param_5;
            bVar3 = iVar9 <= local_48;
            if (bVar3) {
              local_18 = local_18 + iVar2;
              local_1c = local_1c + -iVar2;
              local_2c = local_2c + 1;
              local_28 = local_28 + -1;
              uVar21 = uVar21 + 1;
              local_48 = local_48 - iVar9;
              local_40 = uVar21;
            }
            local_74 = local_74 + uVar21 * 4;
            local_70 = local_70 + 2 + uVar21 * 4;
            iVar15 = local_48;
          }
          else {
            local_20 = local_20 + 1;
            local_24 = local_24 + -1;
            uVar17 = uVar17 + -1;
            local_5c = uVar17;
            if (local_74 < 0) {
              local_48 = iVar15 + param_5;
              local_14 = local_14 + -4;
              bVar3 = iVar9 <= local_48;
              if (bVar3) {
                local_2c = local_2c + 1;
                uVar21 = uVar21 + 1;
                local_18 = local_18 + iVar2;
                local_1c = local_1c + -iVar2;
                local_28 = local_28 + -1;
                local_48 = local_48 - iVar9;
                local_40 = uVar21;
              }
              iVar15 = (uVar21 - uVar17) * 4;
              local_70 = local_70 + 2 + iVar15;
              local_74 = local_74 + 2 + iVar15;
              iVar15 = local_48;
            }
            else {
              local_14 = local_14 + -4;
              local_70 = local_70 - local_14;
              local_74 = local_74 + (2 - local_14);
            }
          }
        } while (-1 < (int)uVar17);
      }
      iVar15 = param_2 - uVar17;
      param_2 = (uVar17 - param_8) + param_2;
      param_3 = param_3 - uVar21;
      if ((((iVar5 <= param_3 && iVar25 <= param_2) && param_3 < iVar13) && iVar15 < iVar7) &&
          *(char *)(param_3 + iVar8) == '\0') {
        if (iVar15 < iVar25) {
          iVar15 = iVar25;
        }
        if (iVar7 < param_2) {
          param_2 = iVar7;
        }
        *(undefined1 *)(param_3 + iVar8) = 1;
        uVar21 = ~param_6 & 0xffff;
        local_4c = (param_2 - iVar15) + 1;
        puVar26 = (ushort *)(param_3 * iVar2 + iVar20 + iVar15 * 2);
        while( true ) {
          uVar12 = *puVar26;
          local_4c = local_4c + -1;
          *puVar26 = ((uVar12 >> 5 & 0x3f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((uVar21 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 + iVar23 * 0x800))
                     * 0x20 | ((uVar12 >> 0xb) +
                              *(short *)(&DAT_00d4a6e0 +
                                        ((uVar21 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 +
                                        iVar23 * 0x800)) * 0x800 |
                     (uVar12 & 0x1f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((~param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 + iVar23 * 0x800);
          if (local_4c == 0) break;
          puVar26 = puVar26 + 1;
        }
        FUN_0056e1d0(iVar8);
        return;
      }
      break;
    case 0xb:
      if (param_9 == 0) {
        iVar22 = param_2 - param_4;
        iVar15 = (param_2 - param_8) + param_4;
        if ((((iVar25 <= iVar15 && iVar5 <= param_3) && iVar22 < iVar7) && param_3 < iVar13) &&
            *(char *)(iVar8 + param_3) == '\0') {
          if (iVar22 < iVar25) {
            iVar22 = iVar25;
          }
          if (iVar7 < iVar15) {
            iVar15 = iVar7;
          }
          local_4c = (iVar15 - iVar22) + 1;
          *(undefined1 *)(iVar8 + param_3) = 1;
          local_68 = (uint *)(iVar2 * param_3 + iVar20 + iVar22 * 2);
          do {
            uVar12 = (ushort)*local_68;
            uVar21 = uVar12 >> 5 & 0x3f;
            *(ushort *)local_68 =
                 ((uVar12 >> 5 & 0x3f) +
                 *(short *)(&DAT_00d4a6e0 +
                           ((uVar21 * (param_6 >> 5 & 0x3f) >> 6) - uVar21) * 4 + iVar23 * 0x800)) *
                 0x20 | ((uVar12 >> 0xb) +
                        *(short *)(&DAT_00d4a6e0 +
                                  (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                  (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                 (uVar12 & 0x1f) +
                 *(short *)(&DAT_00d4a6e0 +
                           (((uVar12 & 0x1f) * (param_6 & 0x1f) >> 5) - (uVar12 & 0x1f)) * 4 +
                           iVar23 * 0x800);
            local_68 = (uint *)((int)local_68 + 2);
            local_4c = local_4c + -1;
          } while (local_4c != 0);
        }
      }
      uVar21 = 0;
      bVar3 = false;
      if (local_70 < 0) {
        local_48 = param_5;
        bVar3 = iVar9 <= param_5;
        if (bVar3) {
          local_48 = param_5 - iVar9;
        }
        local_40 = (uint)bVar3;
        uVar21 = (uint)bVar3;
        local_74 = local_74 + uVar21 * 4;
        local_70 = iVar4 + 5 + uVar21 * 4;
      }
      else {
        local_5c = param_4 + -1;
        if (local_74 < 0) {
          local_48 = param_5;
          bVar3 = iVar9 <= param_5;
          if (bVar3) {
            local_48 = param_5 - iVar9;
          }
          local_40 = (uint)bVar3;
          uVar21 = (uint)bVar3;
          local_74 = (uVar21 - local_5c) * 4;
          local_70 = iVar4 + 5 + local_74;
          local_74 = iVar10 + 5 + local_74;
        }
        else {
          local_70 = local_70 + local_5c * -4;
          local_74 = local_74 + local_5c * -4 + 2;
        }
      }
      uVar17 = local_5c;
      if (-1 < (int)local_5c) {
        local_14 = local_5c * 4;
        local_28 = param_3 - uVar21;
        local_2c = (uVar21 - param_9) + param_3;
        local_24 = (local_5c - param_8) + param_2;
        local_20 = param_2 - local_5c;
        local_18 = local_28 * iVar2;
        local_1c = local_2c * iVar2;
        iVar15 = local_48;
        do {
          if (bVar3) {
            local_58 = local_20;
            local_50 = local_24;
            if ((((iVar5 <= (int)local_2c && iVar25 <= (int)local_24) && local_20 < iVar7) &&
                (int)local_2c < iVar13) && *(char *)(iVar8 + local_2c) == '\0') {
              local_58 = iVar25;
              if (iVar25 <= local_20) {
                local_58 = local_20;
              }
              if (iVar7 < (int)local_24) {
                local_50 = iVar7;
              }
              *(undefined1 *)(iVar8 + local_2c) = 1;
              local_4c = (local_50 - local_58) + 1;
              local_68 = (uint *)(local_1c + local_58 * 2 + iVar20);
              do {
                uVar12 = (ushort)*local_68;
                uVar21 = uVar12 >> 5 & 0x3f;
                *(ushort *)local_68 =
                     ((uVar12 >> 5 & 0x3f) +
                     *(short *)(&DAT_00d4a6e0 +
                               ((uVar21 * (param_6 >> 5 & 0x3f) >> 6) - uVar21) * 4 + iVar23 * 0x800
                               )) * 0x20 |
                     ((uVar12 >> 0xb) +
                     *(short *)(&DAT_00d4a6e0 +
                               (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                               (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                     (uVar12 & 0x1f) +
                     *(short *)(&DAT_00d4a6e0 +
                               (((uVar12 & 0x1f) * (param_6 & 0x1f) >> 5) - (uVar12 & 0x1f)) * 4 +
                               iVar23 * 0x800);
                local_68 = (uint *)((int)local_68 + 2);
                local_4c = local_4c + -1;
              } while (local_4c != 0);
            }
            if ((((iVar5 <= (int)local_28 && (int)local_28 < iVar13) && iVar25 <= local_50) &&
                local_58 < iVar7) && *(char *)(local_28 + iVar8) == '\0') {
              if (local_58 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_50) {
                local_50 = iVar7;
              }
              local_4c = (local_50 - local_58) + 1;
              *(undefined1 *)(local_28 + iVar8) = 1;
              puVar26 = (ushort *)(local_18 + local_58 * 2 + iVar20);
              do {
                uVar12 = *puVar26;
                uVar21 = uVar12 >> 5 & 0x3f;
                local_4c = local_4c + -1;
                *puVar26 = ((uVar12 >> 5 & 0x3f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     ((uVar21 * (param_6 >> 5 & 0x3f) >> 6) - uVar21) * 4 +
                                     iVar23 * 0x800)) * 0x20 |
                           ((uVar12 >> 0xb) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                     (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
                           (uVar12 & 0x1f) +
                           *(short *)(&DAT_00d4a6e0 +
                                     (((uVar12 & 0x1f) * (param_6 & 0x1f) >> 5) - (uVar12 & 0x1f)) *
                                     4 + iVar23 * 0x800);
                puVar26 = puVar26 + 1;
              } while (local_4c != 0);
              uVar17 = local_5c;
            }
            uVar21 = local_40;
            iVar15 = local_48;
          }
          bVar3 = false;
          if (local_70 < 0) {
            local_48 = iVar15 + param_5;
            bVar3 = iVar9 <= local_48;
            if (bVar3) {
              local_2c = local_2c + 1;
              uVar21 = uVar21 + 1;
              local_1c = local_1c + iVar2;
              local_18 = local_18 + -iVar2;
              local_28 = local_28 + -1;
              local_48 = local_48 - iVar9;
              local_40 = uVar21;
            }
            local_74 = local_74 + uVar21 * 4;
            local_70 = local_70 + 2 + uVar21 * 4;
            iVar15 = local_48;
          }
          else {
            local_20 = local_20 + 1;
            local_24 = local_24 + -1;
            uVar17 = uVar17 + -1;
            local_5c = uVar17;
            if (local_74 < 0) {
              local_48 = iVar15 + param_5;
              local_14 = local_14 + -4;
              bVar3 = iVar9 <= local_48;
              if (bVar3) {
                local_2c = local_2c + 1;
                uVar21 = uVar21 + 1;
                local_1c = local_1c + iVar2;
                local_18 = local_18 + -iVar2;
                local_28 = local_28 + -1;
                local_48 = local_48 - iVar9;
                local_40 = uVar21;
              }
              iVar15 = (uVar21 - uVar17) * 4;
              local_70 = local_70 + 2 + iVar15;
              local_74 = local_74 + 2 + iVar15;
              iVar15 = local_48;
            }
            else {
              local_14 = local_14 + -4;
              local_70 = local_70 - local_14;
              local_74 = local_74 + (2 - local_14);
            }
          }
        } while (-1 < (int)uVar17);
      }
      iVar15 = param_2 - uVar17;
      param_2 = (uVar17 - param_8) + param_2;
      param_3 = param_3 - uVar21;
      if ((((iVar5 <= param_3 && iVar25 <= param_2) && param_3 < iVar13) && iVar15 < iVar7) &&
          *(char *)(param_3 + iVar8) == '\0') {
        if (iVar15 < iVar25) {
          iVar15 = iVar25;
        }
        if (iVar7 < param_2) {
          param_2 = iVar7;
        }
        *(undefined1 *)(param_3 + iVar8) = 1;
        local_4c = (param_2 - iVar15) + 1;
        local_68 = (uint *)(param_3 * iVar2 + iVar20 + iVar15 * 2);
        do {
          uVar12 = (ushort)*local_68;
          uVar21 = uVar12 >> 5 & 0x3f;
          *(ushort *)local_68 =
               ((uVar12 >> 5 & 0x3f) +
               *(short *)(&DAT_00d4a6e0 +
                         ((uVar21 * (param_6 >> 5 & 0x3f) >> 6) - uVar21) * 4 + iVar23 * 0x800)) *
               0x20 | ((uVar12 >> 0xb) +
                      *(short *)(&DAT_00d4a6e0 +
                                (((param_6 >> 0xb) * (uint)(uVar12 >> 0xb) >> 5) -
                                (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800)) * 0x800 |
               (uVar12 & 0x1f) +
               *(short *)(&DAT_00d4a6e0 +
                         (((uVar12 & 0x1f) * (param_6 & 0x1f) >> 5) - (uVar12 & 0x1f)) * 4 +
                         iVar23 * 0x800);
          local_68 = (uint *)((int)local_68 + 2);
          local_4c = local_4c + -1;
        } while (local_4c != 0);
        FUN_0056e1d0(iVar8);
        return;
      }
    }
  }
  else {
    if (iVar15 != 1) goto switchD_00774a8e_caseD_5;
    if ((DAT_00dca3fc & 0xffffff) != 0xffffff) {
      param_6._0_2_ =
           CONCAT11((char)((uint)param_6._1_1_ * (DAT_00dca3fc >> 8 & 0xff) >> 8),(byte)param_6);
      param_6 = CONCAT22(CONCAT11(param_6._3_1_,
                                  (char)((uint)param_6._2_1_ * (DAT_00dca3fc >> 0x10 & 0xff) >> 8)),
                         (ushort)param_6);
      uVar17 = (uint)(ushort)param_6;
      param_6 = CONCAT31(param_6._1_3_,(char)((uVar17 & 0xff) * (DAT_00dca3fc & 0xff) >> 8));
    }
    switch(DAT_00dca3f4) {
    case 0:
      goto switchD_00774a8e_caseD_0;
    case 1:
      if (DAT_00dca3f8 != 0xff) {
        if (DAT_00dca3f8 != 0) {
          if (param_9 == 0) {
            iVar23 = param_2 - param_4;
            iVar15 = (param_2 - param_8) + param_4;
            if ((((iVar25 <= iVar15 && iVar5 <= param_3) && iVar23 < iVar7) && param_3 < iVar13) &&
                *(char *)(iVar8 + param_3) == '\0') {
              if (iVar23 < iVar25) {
                iVar23 = iVar25;
              }
              if (iVar7 < iVar15) {
                iVar15 = iVar7;
              }
              local_4c = (iVar15 - iVar23) + 1;
              *(undefined1 *)(iVar8 + param_3) = 1;
              pbVar24 = (byte *)(iVar2 * param_3 + iVar20 + iVar23 * 4);
              do {
                *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                  (uint)*pbVar24 * 0x100 >> 8);
                pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                    (uint)pbVar24[1] * 0x100 >> 8);
                pbVar24[2] = (byte)(((uint)param_6._2_1_ - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                    (uint)pbVar24[2] * 0x100 >> 8);
                pbVar24 = pbVar24 + 4;
                local_4c = local_4c + -1;
              } while (local_4c != 0);
            }
          }
          bVar3 = false;
          if (local_70 < 0) {
            bVar3 = iVar9 <= param_5;
            iVar22 = param_5;
            if (bVar3) {
              iVar22 = param_5 - iVar9;
            }
            uVar21 = (uint)bVar3;
            local_74 = local_74 + uVar21 * 4;
            local_70 = iVar4 + 5 + uVar21 * 4;
          }
          else {
            param_4 = param_4 + -1;
            if (local_74 < 0) {
              bVar3 = iVar9 <= param_5;
              iVar22 = param_5;
              if (bVar3) {
                iVar22 = param_5 - iVar9;
              }
              uVar21 = (uint)bVar3;
              local_74 = (uVar21 - param_4) * 4;
              local_70 = iVar4 + 5 + local_74;
              local_74 = iVar10 + 5 + local_74;
            }
            else {
              local_70 = local_70 + param_4 * -4;
              local_74 = local_74 + param_4 * -4 + 2;
            }
          }
          if (-1 < param_4) {
            local_18 = param_4 * 4;
            local_3c = (uVar21 - param_9) + param_3;
            local_2c = param_2 - param_4;
            local_40 = param_3 - uVar21;
            local_28 = local_40 * iVar2;
            local_50 = (param_4 - param_8) + param_2;
            local_24 = local_3c * iVar2;
            local_20 = local_50;
            do {
              if (bVar3) {
                local_58 = local_2c;
                if ((((iVar5 <= (int)local_3c && iVar25 <= local_20) && (int)local_2c < iVar7) &&
                    (int)local_3c < iVar13) && *(char *)(local_3c + iVar8) == '\0') {
                  local_58 = iVar25;
                  if (iVar25 <= (int)local_2c) {
                    local_58 = local_2c;
                  }
                  if (iVar7 < local_20) {
                    local_50 = iVar7;
                  }
                  *(undefined1 *)(local_3c + iVar8) = 1;
                  iVar23 = (local_50 - local_58) + 1;
                  pbVar24 = (byte *)(local_24 + local_58 * 4 + iVar20);
                  do {
                    *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                      (uint)*pbVar24 * 0x100 >> 8);
                    pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                        (uint)pbVar24[1] * 0x100 >> 8);
                    pbVar24[2] = (byte)(((uint)param_6._2_1_ - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                        (uint)pbVar24[2] * 0x100 >> 8);
                    pbVar24 = pbVar24 + 4;
                    iVar23 = iVar23 + -1;
                  } while (iVar23 != 0);
                }
                if ((((iVar5 <= (int)local_40 && (int)local_40 < iVar13) && iVar25 <= local_50) &&
                    local_58 < iVar7) && *(char *)(local_40 + iVar8) == '\0') {
                  if (local_58 < iVar25) {
                    local_58 = iVar25;
                  }
                  if (iVar7 < local_50) {
                    local_50 = iVar7;
                  }
                  iVar23 = (local_50 - local_58) + 1;
                  *(undefined1 *)(local_40 + iVar8) = 1;
                  pbVar24 = (byte *)(local_28 + local_58 * 4 + iVar20);
                  do {
                    *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                      (uint)*pbVar24 * 0x100 >> 8);
                    pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                        (uint)pbVar24[1] * 0x100 >> 8);
                    pbVar24[2] = (byte)(((uint)param_6._2_1_ - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                        (uint)pbVar24[2] * 0x100 >> 8);
                    pbVar24 = pbVar24 + 4;
                    iVar23 = iVar23 + -1;
                  } while (iVar23 != 0);
                }
                local_50 = local_20;
              }
              bVar3 = false;
              if (local_70 < 0) {
                iVar22 = iVar22 + param_5;
                bVar3 = iVar9 <= iVar22;
                if (bVar3) {
                  local_24 = local_24 + iVar2;
                  local_28 = local_28 + -iVar2;
                  local_3c = local_3c + 1;
                  local_40 = local_40 + -1;
                  uVar21 = uVar21 + 1;
                  iVar22 = iVar22 - iVar9;
                }
                local_74 = local_74 + uVar21 * 4;
                local_70 = local_70 + 2 + uVar21 * 4;
              }
              else {
                local_2c = local_2c + 1;
                local_50 = local_50 + -1;
                param_4 = param_4 + -1;
                local_20 = local_50;
                if (local_74 < 0) {
                  iVar22 = iVar22 + param_5;
                  local_18 = local_18 + -4;
                  bVar3 = iVar9 <= iVar22;
                  if (bVar3) {
                    local_24 = local_24 + iVar2;
                    local_28 = local_28 + -iVar2;
                    local_3c = local_3c + 1;
                    local_40 = local_40 + -1;
                    uVar21 = uVar21 + 1;
                    iVar22 = iVar22 - iVar9;
                  }
                  iVar23 = (uVar21 - param_4) * 4;
                  local_70 = local_70 + 2 + iVar23;
                  local_74 = local_74 + 2 + iVar23;
                }
                else {
                  local_18 = local_18 + -4;
                  local_70 = local_70 - local_18;
                  local_74 = local_74 + (2 - local_18);
                }
              }
            } while (-1 < param_4);
          }
          param_3 = param_3 - uVar21;
          iVar23 = param_2 - param_4;
          param_2 = (param_4 - param_8) + param_2;
          if ((((iVar5 <= param_3 && iVar25 <= param_2) && param_3 < iVar13) && iVar23 < iVar7) &&
              *(char *)(param_3 + iVar8) == '\0') {
            if (iVar23 < iVar25) {
              iVar23 = iVar25;
            }
            if (iVar7 < param_2) {
              param_2 = iVar7;
            }
            *(undefined1 *)(param_3 + iVar8) = 1;
            iVar25 = (param_2 - iVar23) + 1;
            pbVar24 = (byte *)(param_3 * iVar2 + iVar20 + iVar23 * 4);
            do {
              *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                (uint)*pbVar24 * 0x100 >> 8);
              pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                  (uint)pbVar24[1] * 0x100 >> 8);
              pbVar24[2] = (byte)(((uint)param_6._2_1_ - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                  (uint)pbVar24[2] * 0x100 >> 8);
              pbVar24 = pbVar24 + 4;
              iVar25 = iVar25 + -1;
            } while (iVar25 != 0);
            FUN_0056e1d0(iVar8);
            return;
          }
        }
        break;
      }
switchD_00774a8e_caseD_0:
      if (param_9 == 0) {
        iVar15 = param_2 - param_4;
        iVar23 = (param_2 - param_8) + param_4;
        if ((((iVar25 <= iVar23 && iVar5 <= param_3) && iVar15 < iVar7) && param_3 < iVar13) &&
            *(char *)(iVar8 + param_3) == '\0') {
          if (iVar15 < iVar25) {
            iVar15 = iVar25;
          }
          if (iVar7 < iVar23) {
            iVar23 = iVar7;
          }
          *(undefined1 *)(iVar8 + param_3) = 1;
          iVar23 = (iVar23 - iVar15) + 1;
          puVar29 = (uint *)(iVar2 * param_3 + iVar20 + iVar15 * 4);
          do {
            *puVar29 = param_6;
            puVar29 = puVar29 + 1;
            iVar23 = iVar23 + -1;
          } while (iVar23 != 0);
        }
      }
      bVar3 = false;
      if (local_70 < 0) {
        iVar22 = param_5;
        if (iVar9 <= param_5) {
          iVar22 = param_5 - iVar9;
        }
        uVar21 = (uint)(iVar9 <= param_5);
        local_74 = local_74 + uVar21 * 4;
        local_70 = iVar4 + 5 + uVar21 * 4;
LAB_00774c05:
        bVar3 = iVar9 <= param_5;
      }
      else {
        param_4 = param_4 + -1;
        if (local_74 < 0) {
          iVar22 = param_5;
          if (iVar9 <= param_5) {
            iVar22 = param_5 - iVar9;
          }
          uVar21 = (uint)(iVar9 <= param_5);
          local_74 = (uVar21 - param_4) * 4;
          local_70 = iVar4 + 5 + local_74;
          local_74 = iVar10 + 5 + local_74;
          goto LAB_00774c05;
        }
        local_70 = local_70 + param_4 * -4;
        local_74 = local_74 + param_4 * -4 + 2;
      }
      if (-1 < param_4) {
        local_18 = param_4 * 4;
        local_30 = (uVar21 - param_9) + param_3;
        local_2c = param_3 - uVar21;
        local_34 = local_2c * iVar2;
        local_50 = (param_4 - param_8) + param_2;
        local_58 = param_2 - param_4;
        local_28 = local_30 * iVar2;
        local_24 = local_58;
        local_20 = local_50;
        do {
          if (bVar3) {
            if ((((local_58 < iVar7 && (int)local_30 < iVar13) && iVar5 <= (int)local_30) &&
                iVar25 <= local_20) && *(char *)(local_30 + iVar8) == '\0') {
              if ((int)local_24 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_20) {
                local_50 = iVar7;
              }
              *(undefined1 *)(local_30 + iVar8) = 1;
              iVar23 = (local_50 - local_58) + 1;
              puVar29 = (uint *)(local_28 + local_58 * 4 + iVar20);
              do {
                *puVar29 = param_6;
                puVar29 = puVar29 + 1;
                iVar23 = iVar23 + -1;
              } while (iVar23 != 0);
            }
            if (((((int)local_2c < iVar13 && iVar25 <= local_50) && local_58 < iVar7) &&
                iVar5 <= (int)local_2c) && *(char *)(local_2c + iVar8) == '\0') {
              if (local_58 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_50) {
                local_50 = iVar7;
              }
              iVar23 = (local_50 - local_58) + 1;
              *(undefined1 *)(local_2c + iVar8) = 1;
              puVar29 = (uint *)(local_34 + local_58 * 4 + iVar20);
              do {
                *puVar29 = param_6;
                puVar29 = puVar29 + 1;
                iVar23 = iVar23 + -1;
              } while (iVar23 != 0);
            }
            local_50 = local_20;
            local_58 = local_24;
          }
          bVar3 = false;
          if (local_70 < 0) {
            iVar22 = iVar22 + param_5;
            bVar3 = iVar9 <= iVar22;
            if (bVar3) {
              local_28 = local_28 + iVar2;
              local_34 = local_34 + -iVar2;
              local_30 = local_30 + 1;
              local_2c = local_2c + -1;
              uVar21 = uVar21 + 1;
              iVar22 = iVar22 - iVar9;
            }
            local_74 = local_74 + uVar21 * 4;
            local_70 = local_70 + 2 + uVar21 * 4;
          }
          else {
            local_58 = local_58 + 1;
            local_50 = local_50 + -1;
            param_4 = param_4 + -1;
            local_24 = local_58;
            local_20 = local_50;
            if (local_74 < 0) {
              iVar22 = iVar22 + param_5;
              local_18 = local_18 + -4;
              bVar3 = iVar9 <= iVar22;
              if (bVar3) {
                local_28 = local_28 + iVar2;
                local_34 = local_34 + -iVar2;
                local_30 = local_30 + 1;
                local_2c = local_2c + -1;
                uVar21 = uVar21 + 1;
                iVar22 = iVar22 - iVar9;
              }
              iVar23 = (uVar21 - param_4) * 4;
              local_70 = local_70 + 2 + iVar23;
              local_74 = local_74 + 2 + iVar23;
            }
            else {
              local_18 = local_18 + -4;
              local_70 = local_70 - local_18;
              local_74 = local_74 + (2 - local_18);
            }
          }
        } while (-1 < param_4);
      }
      iVar23 = param_2 - param_4;
      param_3 = param_3 - uVar21;
      param_2 = (param_4 - param_8) + param_2;
      if ((((iVar5 <= param_3 && iVar25 <= param_2) && param_3 < iVar13) && iVar23 < iVar7) &&
          *(char *)(param_3 + iVar8) == '\0') {
        if (iVar23 < iVar25) {
          iVar23 = iVar25;
        }
        if (iVar7 < param_2) {
          param_2 = iVar7;
        }
        *(undefined1 *)(param_3 + iVar8) = 1;
        iVar25 = (param_2 - iVar23) + 1;
        puVar29 = (uint *)(param_3 * iVar2 + iVar20 + iVar23 * 4);
        do {
          *puVar29 = param_6;
          puVar29 = puVar29 + 1;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        FUN_0056e1d0(iVar8);
        return;
      }
      break;
    case 2:
      if (DAT_00dca3f8 != 0) {
        if (param_9 == 0) {
          iVar22 = param_2 - param_4;
          iVar15 = (param_2 - param_8) + param_4;
          if ((((iVar25 <= iVar15 && iVar5 <= param_3) && iVar22 < iVar7) && param_3 < iVar13) &&
              *(char *)(iVar8 + param_3) == '\0') {
            if (iVar22 < iVar25) {
              iVar22 = iVar25;
            }
            if (iVar7 < iVar15) {
              iVar15 = iVar7;
            }
            local_4c = (iVar15 - iVar22) + 1;
            *(undefined1 *)(iVar8 + param_3) = 1;
            local_68 = (uint *)(iVar2 * param_3 + iVar20 + iVar22 * 4);
            do {
              local_78._0_2_ =
                   CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                            *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
              local_78._0_3_ =
                   CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._2_1_),
                            (undefined2)local_78);
              uVar6 = (uint3)local_78;
              local_78 = (uint)(uint3)local_78;
              uVar17 = (*local_68 & 0xfefeff) + (uVar6 & 0xfefeff);
              uVar21 = uVar17 & 0x1010100;
              *local_68 = uVar21 - (uVar21 >> 8) | (*local_68 | local_78) & 0x10100 | uVar17;
              local_68 = local_68 + 1;
              local_4c = local_4c + -1;
            } while (local_4c != 0);
          }
        }
        uVar21 = 0;
        bVar3 = false;
        if (local_70 < 0) {
          local_48 = param_5;
          bVar3 = iVar9 <= param_5;
          if (bVar3) {
            local_48 = param_5 - iVar9;
          }
          local_40 = (uint)bVar3;
          uVar21 = (uint)bVar3;
          local_74 = local_74 + uVar21 * 4;
          local_70 = iVar4 + 5 + uVar21 * 4;
        }
        else {
          param_4 = param_4 + -1;
          if (local_74 < 0) {
            local_48 = param_5;
            bVar3 = iVar9 <= param_5;
            if (bVar3) {
              local_48 = param_5 - iVar9;
            }
            local_40 = (uint)bVar3;
            uVar21 = (uint)bVar3;
            local_74 = (uVar21 - param_4) * 4;
            local_70 = iVar4 + 5 + local_74;
            local_74 = iVar10 + 5 + local_74;
          }
          else {
            local_70 = local_70 + param_4 * -4;
            local_74 = local_74 + param_4 * -4 + 2;
          }
        }
        if (-1 < param_4) {
          local_18 = param_4 * 4;
          local_30 = (uVar21 - param_9) + param_3;
          local_2c = param_2 - param_4;
          local_5c = param_3 - uVar21;
          local_28 = local_5c * iVar2;
          local_50 = (param_4 - param_8) + param_2;
          local_24 = local_30 * iVar2;
          iVar15 = local_48;
          local_20 = local_50;
          do {
            if (bVar3) {
              local_58 = local_2c;
              if ((((iVar5 <= (int)local_30 && iVar25 <= local_50) && (int)local_2c < iVar7) &&
                  (int)local_30 < iVar13) && *(char *)(local_30 + iVar8) == '\0') {
                local_58 = iVar25;
                if (iVar25 <= (int)local_2c) {
                  local_58 = local_2c;
                }
                if (iVar7 < local_20) {
                  local_50 = iVar7;
                }
                *(undefined1 *)(local_30 + iVar8) = 1;
                local_4c = (local_50 - local_58) + 1;
                local_68 = (uint *)(local_24 + local_58 * 4 + iVar20);
                do {
                  local_78._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                  local_78._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._2_1_),
                                (undefined2)local_78);
                  uVar6 = (uint3)local_78;
                  local_78 = (uint)(uint3)local_78;
                  uVar17 = (*local_68 & 0xfefeff) + (uVar6 & 0xfefeff);
                  uVar21 = uVar17 & 0x1010100;
                  *local_68 = uVar21 - (uVar21 >> 8) | (*local_68 | local_78) & 0x10100 | uVar17;
                  local_68 = local_68 + 1;
                  local_4c = local_4c + -1;
                } while (local_4c != 0);
              }
              if ((((iVar5 <= (int)local_5c && (int)local_5c < iVar13) && iVar25 <= local_50) &&
                  local_58 < iVar7) && *(char *)(local_5c + iVar8) == '\0') {
                if (local_58 < iVar25) {
                  local_58 = iVar25;
                }
                if (iVar7 < local_50) {
                  local_50 = iVar7;
                }
                local_4c = (local_50 - local_58) + 1;
                *(undefined1 *)(local_5c + iVar8) = 1;
                puVar29 = (uint *)(local_28 + local_58 * 4 + iVar20);
                do {
                  local_78._0_2_ =
                       CONCAT11(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                                *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                  local_78._0_3_ =
                       CONCAT12(*(undefined1 *)
                                 (&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._2_1_),
                                (undefined2)local_78);
                  uVar6 = (uint3)local_78;
                  local_78 = (uint)(uint3)local_78;
                  uVar17 = (*puVar29 & 0xfefeff) + (uVar6 & 0xfefeff);
                  uVar21 = uVar17 & 0x1010100;
                  *puVar29 = uVar21 - (uVar21 >> 8) | (*puVar29 | local_78) & 0x10100 | uVar17;
                  puVar29 = puVar29 + 1;
                  local_4c = local_4c + -1;
                } while (local_4c != 0);
                iVar15 = local_48;
              }
              uVar21 = local_40;
              local_50 = local_20;
            }
            bVar3 = false;
            if (local_70 < 0) {
              local_48 = iVar15 + param_5;
              bVar3 = iVar9 <= local_48;
              if (bVar3) {
                local_28 = local_28 + -iVar2;
                local_24 = local_24 + iVar2;
                local_30 = local_30 + 1;
                local_5c = local_5c + -1;
                uVar21 = uVar21 + 1;
                local_48 = local_48 - iVar9;
                local_40 = uVar21;
              }
              local_74 = local_74 + uVar21 * 4;
              local_70 = local_70 + 2 + uVar21 * 4;
              iVar15 = local_48;
            }
            else {
              local_2c = local_2c + 1;
              local_50 = local_50 + -1;
              param_4 = param_4 + -1;
              local_20 = local_50;
              if (local_74 < 0) {
                local_48 = iVar15 + param_5;
                local_18 = local_18 + -4;
                bVar3 = iVar9 <= local_48;
                if (bVar3) {
                  local_24 = local_24 + iVar2;
                  local_30 = local_30 + 1;
                  local_28 = local_28 + -iVar2;
                  local_5c = local_5c + -1;
                  uVar21 = uVar21 + 1;
                  local_48 = local_48 - iVar9;
                  local_40 = uVar21;
                }
                iVar15 = (uVar21 - param_4) * 4;
                local_70 = local_70 + 2 + iVar15;
                local_74 = local_74 + 2 + iVar15;
                iVar15 = local_48;
              }
              else {
                local_18 = local_18 + -4;
                local_70 = local_70 - local_18;
                local_74 = local_74 + (2 - local_18);
              }
            }
          } while (-1 < param_4);
        }
        iVar15 = param_2 - param_4;
        param_3 = param_3 - uVar21;
        param_2 = (param_4 - param_8) + param_2;
        if ((((iVar5 <= param_3 && iVar25 <= param_2) && param_3 < iVar13) && iVar15 < iVar7) &&
            *(char *)(param_3 + iVar8) == '\0') {
          if (iVar15 < iVar25) {
            iVar15 = iVar25;
          }
          if (iVar7 < param_2) {
            param_2 = iVar7;
          }
          *(undefined1 *)(param_3 + iVar8) = 1;
          iVar25 = (param_2 - iVar15) + 1;
          puVar29 = (uint *)(param_3 * iVar2 + iVar20 + iVar15 * 4);
          do {
            local_78._0_2_ =
                 CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                          *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
            local_78._0_3_ =
                 CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._2_1_),
                          (undefined2)local_78);
            uVar6 = (uint3)local_78;
            local_78 = (uint)(uint3)local_78;
            uVar17 = (*puVar29 & 0xfefeff) + (uVar6 & 0xfefeff);
            uVar21 = uVar17 & 0x1010100;
            *puVar29 = uVar21 - (uVar21 >> 8) | (*puVar29 | local_78) & 0x10100 | uVar17;
            puVar29 = puVar29 + 1;
            iVar25 = iVar25 + -1;
          } while (iVar25 != 0);
          FUN_0056e1d0(iVar8);
          return;
        }
      }
      break;
    case 3:
      if (DAT_00dca3f8 == 0) break;
      if (param_9 == 0) {
        iVar14 = param_2 - param_4;
        iVar15 = (param_2 - param_8) + param_4;
        if ((((iVar25 <= iVar15 && iVar5 <= param_3) && iVar14 < iVar7) && param_3 < iVar13) &&
            *(char *)(iVar8 + param_3) == '\0') {
          if (iVar14 < iVar25) {
            iVar14 = iVar25;
          }
          if (iVar7 < iVar15) {
            iVar15 = iVar7;
          }
          local_4c = (iVar15 - iVar14) + 1;
          *(undefined1 *)(iVar8 + param_3) = 1;
          puVar29 = (uint *)(iVar2 * param_3 + iVar20 + iVar14 * 4);
          do {
            uVar21 = local_78;
            local_78._0_2_ =
                 CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                          *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
            local_78._3_1_ = SUB41(uVar21,3);
            local_78._0_3_ =
                 CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._2_1_),
                          (undefined2)local_78);
            uVar17 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
            uVar21 = uVar17 & 0x1010100;
            *puVar29 = uVar21 - (uVar21 >> 8) & uVar17;
            puVar29 = puVar29 + 1;
            local_4c = local_4c + -1;
          } while (local_4c != 0);
        }
      }
      uVar21 = 0;
      bVar3 = false;
      if (local_70 < 0) {
        iVar22 = param_5;
        if (iVar9 <= param_5) {
          iVar22 = param_5 - iVar9;
        }
        uVar21 = (uint)(iVar9 <= param_5);
        local_74 = local_74 + uVar21 * 4;
        local_70 = iVar4 + 5 + uVar21 * 4;
LAB_00775f40:
        bVar3 = iVar9 <= param_5;
        local_40 = (uint)bVar3;
      }
      else {
        param_4 = param_4 + -1;
        if (local_74 < 0) {
          iVar22 = param_5;
          if (iVar9 <= param_5) {
            iVar22 = param_5 - iVar9;
          }
          uVar21 = (uint)(iVar9 <= param_5);
          local_74 = (uVar21 - param_4) * 4;
          local_70 = iVar4 + 5 + local_74;
          local_74 = iVar10 + 5 + local_74;
          goto LAB_00775f40;
        }
        local_70 = local_70 + param_4 * -4;
        local_74 = local_74 + param_4 * -4 + 2;
      }
      if (-1 < param_4) {
        local_18 = param_4 * 4;
        local_48 = param_3 - uVar21;
        local_30 = (uVar21 - param_9) + param_3;
        local_2c = param_2 - param_4;
        local_28 = local_48 * iVar2;
        local_50 = (param_4 - param_8) + param_2;
        local_24 = local_30 * iVar2;
        local_20 = local_50;
        do {
          if (bVar3) {
            local_58 = local_2c;
            if ((((iVar5 <= (int)local_30 && iVar25 <= local_50) && (int)local_2c < iVar7) &&
                (int)local_30 < iVar13) && *(char *)(local_30 + iVar8) == '\0') {
              local_58 = iVar25;
              if (iVar25 <= (int)local_2c) {
                local_58 = local_2c;
              }
              if (iVar7 < local_20) {
                local_50 = iVar7;
              }
              *(undefined1 *)(local_30 + iVar8) = 1;
              local_4c = (local_50 - local_58) + 1;
              puVar29 = (uint *)(local_24 + local_58 * 4 + iVar20);
              do {
                uVar21 = local_78;
                local_78._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                local_78._3_1_ = SUB41(uVar21,3);
                local_78._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._2_1_),
                              (undefined2)local_78);
                uVar17 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                uVar21 = uVar17 & 0x1010100;
                *puVar29 = uVar21 - (uVar21 >> 8) & uVar17;
                puVar29 = puVar29 + 1;
                local_4c = local_4c + -1;
              } while (local_4c != 0);
            }
            if ((((iVar5 <= local_48 && local_48 < iVar13) && iVar25 <= local_50) &&
                local_58 < iVar7) && *(char *)(local_48 + iVar8) == '\0') {
              if (local_58 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_50) {
                local_50 = iVar7;
              }
              local_4c = (local_50 - local_58) + 1;
              *(undefined1 *)(local_48 + iVar8) = 1;
              puVar29 = (uint *)(local_28 + local_58 * 4 + iVar20);
              do {
                uVar21 = local_78;
                local_78._0_2_ =
                     CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                              *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
                local_78._3_1_ = SUB41(uVar21,3);
                local_78._0_3_ =
                     CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._2_1_),
                              (undefined2)local_78);
                uVar17 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
                uVar21 = uVar17 & 0x1010100;
                *puVar29 = uVar21 - (uVar21 >> 8) & uVar17;
                puVar29 = puVar29 + 1;
                local_4c = local_4c + -1;
              } while (local_4c != 0);
            }
            uVar21 = local_40;
            local_50 = local_20;
          }
          bVar3 = false;
          if (local_70 < 0) {
            iVar22 = iVar22 + param_5;
            bVar3 = iVar9 <= iVar22;
            if (bVar3) {
              local_28 = local_28 + -iVar2;
              local_24 = local_24 + iVar2;
              local_30 = local_30 + 1;
              local_48 = local_48 + -1;
              uVar21 = uVar21 + 1;
              iVar22 = iVar22 - iVar9;
              local_40 = uVar21;
            }
            local_74 = local_74 + uVar21 * 4;
            local_70 = local_70 + 2 + uVar21 * 4;
          }
          else {
            local_2c = local_2c + 1;
            local_50 = local_50 + -1;
            param_4 = param_4 + -1;
            local_20 = local_50;
            if (local_74 < 0) {
              iVar22 = iVar22 + param_5;
              local_18 = local_18 + -4;
              bVar3 = iVar9 <= iVar22;
              if (bVar3) {
                local_24 = local_24 + iVar2;
                local_30 = local_30 + 1;
                local_28 = local_28 + -iVar2;
                local_48 = local_48 + -1;
                uVar21 = uVar21 + 1;
                iVar22 = iVar22 - iVar9;
                local_40 = uVar21;
              }
              iVar15 = (uVar21 - param_4) * 4;
              local_70 = local_70 + 2 + iVar15;
              local_74 = local_74 + 2 + iVar15;
            }
            else {
              local_18 = local_18 + -4;
              local_70 = local_70 - local_18;
              local_74 = local_74 + (2 - local_18);
            }
          }
        } while (-1 < param_4);
      }
      iVar15 = param_2 - param_4;
      param_2 = (param_4 - param_8) + param_2;
      param_3 = param_3 - uVar21;
      if ((((iVar5 <= param_3 && iVar25 <= param_2) && param_3 < iVar13) && iVar15 < iVar7) &&
          *(char *)(param_3 + iVar8) == '\0') {
        if (iVar15 < iVar25) {
          iVar15 = iVar25;
        }
        if (iVar7 < param_2) {
          param_2 = iVar7;
        }
        *(undefined1 *)(param_3 + iVar8) = 1;
        iVar25 = (param_2 - iVar15) + 1;
        puVar29 = (uint *)(param_3 * iVar2 + iVar20 + iVar15 * 4);
        do {
          uVar21 = local_78;
          local_78._0_2_ =
               CONCAT11(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._1_1_),
                        *(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (param_6 & 0xff)));
          local_78._3_1_ = SUB41(uVar21,3);
          local_78._0_3_ =
               CONCAT12(*(undefined1 *)(&DAT_00d0a2e0 + iVar23 * 0x100 + (uint)param_6._2_1_),
                        (undefined2)local_78);
          uVar17 = (*puVar29 | 0x1010100) - (local_78 & 0xfefefeff);
          uVar21 = uVar17 & 0x1010100;
          *puVar29 = uVar21 - (uVar21 >> 8) & uVar17;
          puVar29 = puVar29 + 1;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        FUN_0056e1d0(iVar8);
        return;
      }
      break;
    case 4:
      if (param_9 == 0) {
        iVar23 = param_2 - param_4;
        iVar15 = (param_2 - param_8) + param_4;
        if ((((iVar25 <= iVar15 && iVar5 <= param_3) && iVar23 < iVar7) && param_3 < iVar13) &&
            *(char *)(iVar8 + param_3) == '\0') {
          if (iVar23 < iVar25) {
            iVar23 = iVar25;
          }
          if (iVar7 < iVar15) {
            iVar15 = iVar7;
          }
          local_4c = (iVar15 - iVar23) + 1;
          *(undefined1 *)(iVar8 + param_3) = 1;
          pbVar24 = (byte *)(iVar2 * param_3 + iVar20 + iVar23 * 4);
          do {
            *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
            pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
            pbVar24[2] = (byte)((uint)pbVar24[2] * (uint)param_6._2_1_ >> 8);
            pbVar24 = pbVar24 + 4;
            local_4c = local_4c + -1;
          } while (local_4c != 0);
        }
      }
      bVar3 = false;
      if (local_70 < 0) {
        bVar3 = iVar9 <= param_5;
        iVar22 = param_5;
        if (bVar3) {
          iVar22 = param_5 - iVar9;
        }
        uVar21 = (uint)bVar3;
        local_74 = local_74 + uVar21 * 4;
        local_70 = iVar4 + 5 + uVar21 * 4;
      }
      else {
        param_4 = param_4 + -1;
        if (local_74 < 0) {
          bVar3 = iVar9 <= param_5;
          iVar22 = param_5;
          if (bVar3) {
            iVar22 = param_5 - iVar9;
          }
          uVar21 = (uint)bVar3;
          local_74 = (uVar21 - param_4) * 4;
          local_70 = iVar4 + 5 + local_74;
          local_74 = iVar10 + 5 + local_74;
        }
        else {
          local_70 = local_70 + param_4 * -4;
          local_74 = local_74 + param_4 * -4 + 2;
        }
      }
      if (-1 < param_4) {
        local_18 = param_4 * 4;
        local_3c = (uVar21 - param_9) + param_3;
        local_2c = param_2 - param_4;
        local_40 = param_3 - uVar21;
        local_28 = local_40 * iVar2;
        local_50 = (param_4 - param_8) + param_2;
        local_24 = local_3c * iVar2;
        local_20 = local_50;
        do {
          if (bVar3) {
            local_58 = local_2c;
            if ((((iVar5 <= (int)local_3c && iVar25 <= local_20) && (int)local_2c < iVar7) &&
                (int)local_3c < iVar13) && *(char *)(local_3c + iVar8) == '\0') {
              local_58 = iVar25;
              if (iVar25 <= (int)local_2c) {
                local_58 = local_2c;
              }
              if (iVar7 < local_20) {
                local_50 = iVar7;
              }
              *(undefined1 *)(local_3c + iVar8) = 1;
              iVar23 = (local_50 - local_58) + 1;
              pbVar24 = (byte *)(local_24 + local_58 * 4 + iVar20);
              do {
                *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
                pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
                pbVar24[2] = (byte)((uint)pbVar24[2] * (uint)param_6._2_1_ >> 8);
                pbVar24 = pbVar24 + 4;
                iVar23 = iVar23 + -1;
              } while (iVar23 != 0);
            }
            if ((((iVar5 <= (int)local_40 && iVar25 <= local_50) && (int)local_40 < iVar13) &&
                local_58 < iVar7) && *(char *)(local_40 + iVar8) == '\0') {
              if (local_58 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_50) {
                local_50 = iVar7;
              }
              iVar23 = (local_50 - local_58) + 1;
              *(undefined1 *)(local_40 + iVar8) = 1;
              pbVar24 = (byte *)(local_28 + local_58 * 4 + iVar20);
              do {
                *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
                pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
                pbVar24[2] = (byte)((uint)pbVar24[2] * (uint)param_6._2_1_ >> 8);
                pbVar24 = pbVar24 + 4;
                iVar23 = iVar23 + -1;
              } while (iVar23 != 0);
            }
            local_50 = local_20;
          }
          bVar3 = false;
          if (local_70 < 0) {
            iVar22 = iVar22 + param_5;
            bVar3 = iVar9 <= iVar22;
            if (bVar3) {
              local_24 = local_24 + iVar2;
              local_28 = local_28 + -iVar2;
              local_3c = local_3c + 1;
              local_40 = local_40 + -1;
              uVar21 = uVar21 + 1;
              iVar22 = iVar22 - iVar9;
            }
            local_74 = local_74 + uVar21 * 4;
            local_70 = local_70 + 2 + uVar21 * 4;
          }
          else {
            local_2c = local_2c + 1;
            local_50 = local_50 + -1;
            param_4 = param_4 + -1;
            local_20 = local_50;
            if (local_74 < 0) {
              iVar22 = iVar22 + param_5;
              local_18 = local_18 + -4;
              bVar3 = iVar9 <= iVar22;
              if (bVar3) {
                local_24 = local_24 + iVar2;
                local_28 = local_28 + -iVar2;
                local_3c = local_3c + 1;
                local_40 = local_40 + -1;
                uVar21 = uVar21 + 1;
                iVar22 = iVar22 - iVar9;
              }
              iVar23 = (uVar21 - param_4) * 4;
              local_70 = local_70 + 2 + iVar23;
              local_74 = local_74 + 2 + iVar23;
            }
            else {
              local_18 = local_18 + -4;
              local_70 = local_70 - local_18;
              local_74 = local_74 + (2 - local_18);
            }
          }
        } while (-1 < param_4);
      }
      iVar23 = param_2 - param_4;
      param_3 = param_3 - uVar21;
      param_2 = (param_4 - param_8) + param_2;
      if ((((iVar5 <= param_3 && iVar25 <= param_2) && param_3 < iVar13) && iVar23 < iVar7) &&
          *(char *)(param_3 + iVar8) == '\0') {
        if (iVar23 < iVar25) {
          iVar23 = iVar25;
        }
        if (iVar7 < param_2) {
          param_2 = iVar7;
        }
        *(undefined1 *)(param_3 + iVar8) = 1;
        iVar25 = (param_2 - iVar23) + 1;
        pbVar24 = (byte *)(param_3 * iVar2 + iVar20 + iVar23 * 4);
        do {
          *pbVar24 = (byte)((uint)*pbVar24 * (param_6 & 0xff) >> 8);
          pbVar24[1] = (byte)((uint)pbVar24[1] * (uint)param_6._1_1_ >> 8);
          pbVar24[2] = (byte)((uint)pbVar24[2] * (uint)param_6._2_1_ >> 8);
          pbVar24 = pbVar24 + 4;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        FUN_0056e1d0(iVar8);
        return;
      }
      break;
    case 10:
      if (param_9 == 0) {
        iVar23 = param_2 - param_4;
        iVar15 = (param_2 - param_8) + param_4;
        if ((((iVar25 <= iVar15 && iVar5 <= param_3) && iVar23 < iVar7) && param_3 < iVar13) &&
            *(char *)(iVar8 + param_3) == '\0') {
          if (iVar23 < iVar25) {
            iVar23 = iVar25;
          }
          if (iVar7 < iVar15) {
            iVar15 = iVar7;
          }
          local_4c = (iVar15 - iVar23) + 1;
          pbVar24 = (byte *)(iVar2 * param_3 + iVar20 + iVar23 * 4);
          *(undefined1 *)(iVar8 + param_3) = 1;
          do {
            *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                              (uint)*pbVar24 * 0x100 >> 8);
            pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                (uint)pbVar24[1] * 0x100 >> 8);
            pbVar24[2] = (byte)(((uint)(byte)~param_6._2_1_ - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                (uint)pbVar24[2] * 0x100 >> 8);
            pbVar24 = pbVar24 + 4;
            local_4c = local_4c + -1;
          } while (local_4c != 0);
        }
      }
      bVar3 = false;
      if (local_70 < 0) {
        bVar3 = iVar9 <= param_5;
        iVar22 = param_5;
        if (bVar3) {
          iVar22 = param_5 - iVar9;
        }
        uVar21 = (uint)bVar3;
        local_74 = local_74 + uVar21 * 4;
        local_70 = iVar4 + 5 + uVar21 * 4;
      }
      else {
        param_4 = param_4 + -1;
        if (local_74 < 0) {
          bVar3 = iVar9 <= param_5;
          iVar22 = param_5;
          if (bVar3) {
            iVar22 = param_5 - iVar9;
          }
          uVar21 = (uint)bVar3;
          local_74 = (uVar21 - param_4) * 4;
          local_70 = iVar4 + 5 + local_74;
          local_74 = iVar10 + 5 + local_74;
        }
        else {
          local_70 = local_70 + param_4 * -4;
          local_74 = local_74 + param_4 * -4 + 2;
        }
      }
      if (-1 < param_4) {
        local_18 = param_4 * 4;
        local_34 = (uVar21 - param_9) + param_3;
        local_2c = param_2 - param_4;
        local_38 = param_3 - uVar21;
        local_40 = local_38 * iVar2;
        local_50 = (param_4 - param_8) + param_2;
        local_3c = local_34 * iVar2;
        local_24 = local_50;
        do {
          if (bVar3) {
            local_58 = local_2c;
            if ((((iVar5 <= (int)local_34 && iVar25 <= (int)local_24) && (int)local_2c < iVar7) &&
                (int)local_34 < iVar13) && *(char *)(local_34 + iVar8) == '\0') {
              local_58 = iVar25;
              if (iVar25 <= (int)local_2c) {
                local_58 = local_2c;
              }
              if (iVar7 < (int)local_24) {
                local_50 = iVar7;
              }
              *(undefined1 *)(local_34 + iVar8) = 1;
              iVar23 = (local_50 - local_58) + 1;
              pbVar24 = (byte *)(local_3c + local_58 * 4 + iVar20);
              do {
                *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                  (uint)*pbVar24 * 0x100 >> 8);
                pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                    (uint)pbVar24[1] * 0x100 >> 8);
                pbVar24[2] = (byte)(((uint)(byte)~param_6._2_1_ - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                    (uint)pbVar24[2] * 0x100 >> 8);
                pbVar24 = pbVar24 + 4;
                iVar23 = iVar23 + -1;
              } while (iVar23 != 0);
            }
            if ((((iVar5 <= (int)local_38 && iVar25 <= local_50) && (int)local_38 < iVar13) &&
                local_58 < iVar7) && *(char *)(local_38 + iVar8) == '\0') {
              if (local_58 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_50) {
                local_50 = iVar7;
              }
              iVar23 = (local_50 - local_58) + 1;
              *(undefined1 *)(local_38 + iVar8) = 1;
              pbVar24 = (byte *)(local_40 + local_58 * 4 + iVar20);
              do {
                *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                                  (uint)*pbVar24 * 0x100 >> 8);
                pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                    (uint)pbVar24[1] * 0x100 >> 8);
                pbVar24[2] = (byte)(((uint)(byte)~param_6._2_1_ - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                    (uint)pbVar24[2] * 0x100 >> 8);
                pbVar24 = pbVar24 + 4;
                iVar23 = iVar23 + -1;
              } while (iVar23 != 0);
            }
            local_50 = local_24;
          }
          bVar3 = false;
          if (local_70 < 0) {
            iVar22 = iVar22 + param_5;
            bVar3 = iVar9 <= iVar22;
            if (bVar3) {
              local_3c = local_3c + iVar2;
              local_40 = local_40 + -iVar2;
              local_34 = local_34 + 1;
              local_38 = local_38 + -1;
              uVar21 = uVar21 + 1;
              iVar22 = iVar22 - iVar9;
            }
            local_74 = local_74 + uVar21 * 4;
            local_70 = local_70 + 2 + uVar21 * 4;
          }
          else {
            local_2c = local_2c + 1;
            local_50 = local_50 + -1;
            param_4 = param_4 + -1;
            local_24 = local_50;
            if (local_74 < 0) {
              iVar22 = iVar22 + param_5;
              local_18 = local_18 + -4;
              bVar3 = iVar9 <= iVar22;
              if (bVar3) {
                local_3c = local_3c + iVar2;
                local_40 = local_40 + -iVar2;
                local_34 = local_34 + 1;
                local_38 = local_38 + -1;
                uVar21 = uVar21 + 1;
                iVar22 = iVar22 - iVar9;
              }
              iVar23 = (uVar21 - param_4) * 4;
              local_70 = local_70 + 2 + iVar23;
              local_74 = local_74 + 2 + iVar23;
            }
            else {
              local_18 = local_18 + -4;
              local_70 = local_70 - local_18;
              local_74 = local_74 + (2 - local_18);
            }
          }
        } while (-1 < param_4);
      }
      param_3 = param_3 - uVar21;
      iVar23 = param_2 - param_4;
      param_2 = (param_4 - param_8) + param_2;
      if ((((iVar5 <= param_3 && iVar25 <= param_2) && param_3 < iVar13) && iVar23 < iVar7) &&
          *(char *)(param_3 + iVar8) == '\0') {
        if (iVar23 < iVar25) {
          iVar23 = iVar25;
        }
        if (iVar7 < param_2) {
          param_2 = iVar7;
        }
        *(undefined1 *)(param_3 + iVar8) = 1;
        iVar25 = (param_2 - iVar23) + 1;
        pbVar24 = (byte *)(param_3 * iVar2 + iVar20 + iVar23 * 4);
        do {
          *pbVar24 = (byte)(((uint)(byte)~(byte)param_6 - (uint)*pbVar24) * DAT_00dca3f8 +
                            (uint)*pbVar24 * 0x100 >> 8);
          pbVar24[1] = (byte)(((uint)(byte)~param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                              (uint)pbVar24[1] * 0x100 >> 8);
          pbVar24[2] = (byte)(((uint)(byte)~param_6._2_1_ - (uint)pbVar24[2]) * DAT_00dca3f8 +
                              (uint)pbVar24[2] * 0x100 >> 8);
          pbVar24 = pbVar24 + 4;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        FUN_0056e1d0(iVar8);
        return;
      }
      break;
    case 0xb:
      if (param_9 == 0) {
        iVar15 = param_2 - param_4;
        iVar23 = (param_2 - param_8) + param_4;
        if ((((iVar25 <= iVar23 && iVar5 <= param_3) && iVar15 < iVar7) && param_3 < iVar13) &&
            *(char *)(iVar8 + param_3) == '\0') {
          if (iVar15 < iVar25) {
            iVar15 = iVar25;
          }
          if (iVar7 < iVar23) {
            iVar23 = iVar7;
          }
          local_4c = (iVar23 - iVar15) + 1;
          *(undefined1 *)(iVar8 + param_3) = 1;
          pbVar24 = (byte *)(iVar2 * param_3 + iVar20 + iVar15 * 4);
          do {
            uVar17 = (uint)*pbVar24;
            *pbVar24 = (byte)((((int)(uVar17 * (param_6 & 0xff)) >> 8) - uVar17) * DAT_00dca3f8 +
                              uVar17 * 0x100 >> 8);
            uVar17 = (uint)pbVar24[1];
            pbVar24[1] = (byte)((((int)(uVar17 * param_6._1_1_) >> 8) - uVar17) * DAT_00dca3f8 +
                                uVar17 * 0x100 >> 8);
            uVar17 = (uint)pbVar24[2];
            pbVar24[2] = (byte)((((int)(uVar17 * param_6._2_1_) >> 8) - uVar17) * DAT_00dca3f8 +
                                uVar17 * 0x100 >> 8);
            pbVar24 = pbVar24 + 4;
            local_4c = local_4c + -1;
          } while (local_4c != 0);
        }
      }
      bVar3 = false;
      if (local_70 < 0) {
        bVar3 = iVar9 <= param_5;
        iVar22 = param_5;
        if (bVar3) {
          iVar22 = param_5 - iVar9;
        }
        uVar21 = (uint)bVar3;
        local_74 = local_74 + uVar21 * 4;
        local_70 = iVar4 + 5 + uVar21 * 4;
      }
      else {
        param_4 = param_4 + -1;
        if (local_74 < 0) {
          bVar3 = iVar9 <= param_5;
          iVar22 = param_5;
          if (bVar3) {
            iVar22 = param_5 - iVar9;
          }
          uVar21 = (uint)bVar3;
          local_74 = (uVar21 - param_4) * 4;
          local_70 = iVar4 + 5 + local_74;
          local_74 = iVar10 + 5 + local_74;
        }
        else {
          local_70 = local_70 + param_4 * -4;
          local_74 = local_74 + param_4 * -4 + 2;
        }
      }
      if (-1 < param_4) {
        local_18 = param_4 * 4;
        local_38 = (uVar21 - param_9) + param_3;
        local_2c = param_2 - param_4;
        local_3c = param_3 - uVar21;
        local_50 = (param_4 - param_8) + param_2;
        local_28 = local_3c * iVar2;
        local_24 = local_38 * iVar2;
        local_20 = local_50;
        do {
          if (bVar3) {
            local_58 = local_2c;
            if ((((iVar5 <= (int)local_38 && iVar25 <= local_20) && (int)local_2c < iVar7) &&
                (int)local_38 < iVar13) && *(char *)(local_38 + iVar8) == '\0') {
              local_58 = iVar25;
              if (iVar25 <= (int)local_2c) {
                local_58 = local_2c;
              }
              if (iVar7 < local_20) {
                local_50 = iVar7;
              }
              local_4c = (local_50 - local_58) + 1;
              pbVar24 = (byte *)(local_24 + local_58 * 4 + iVar20);
              *(undefined1 *)(local_38 + iVar8) = 1;
              do {
                uVar17 = (uint)*pbVar24;
                *pbVar24 = (byte)((((int)(uVar17 * (param_6 & 0xff)) >> 8) - uVar17) * DAT_00dca3f8
                                  + uVar17 * 0x100 >> 8);
                uVar17 = (uint)pbVar24[1];
                pbVar24[1] = (byte)((((int)(uVar17 * param_6._1_1_) >> 8) - uVar17) * DAT_00dca3f8 +
                                    uVar17 * 0x100 >> 8);
                uVar17 = (uint)pbVar24[2];
                pbVar24[2] = (byte)((((int)(uVar17 * param_6._2_1_) >> 8) - uVar17) * DAT_00dca3f8 +
                                    uVar17 * 0x100 >> 8);
                pbVar24 = pbVar24 + 4;
                local_4c = local_4c + -1;
              } while (local_4c != 0);
            }
            if ((((iVar5 <= (int)local_3c && (int)local_3c < iVar13) && iVar25 <= local_50) &&
                local_58 < iVar7) && *(char *)(local_3c + iVar8) == '\0') {
              if (local_58 < iVar25) {
                local_58 = iVar25;
              }
              if (iVar7 < local_50) {
                local_50 = iVar7;
              }
              local_4c = (local_50 - local_58) + 1;
              pbVar24 = (byte *)(local_28 + local_58 * 4 + iVar20);
              *(undefined1 *)(local_3c + iVar8) = 1;
              do {
                uVar17 = (uint)*pbVar24;
                *pbVar24 = (byte)((((int)(uVar17 * (param_6 & 0xff)) >> 8) - uVar17) * DAT_00dca3f8
                                  + uVar17 * 0x100 >> 8);
                uVar17 = (uint)pbVar24[1];
                pbVar24[1] = (byte)((((int)(uVar17 * param_6._1_1_) >> 8) - uVar17) * DAT_00dca3f8 +
                                    uVar17 * 0x100 >> 8);
                uVar17 = (uint)pbVar24[2];
                pbVar24[2] = (byte)((((int)(uVar17 * param_6._2_1_) >> 8) - uVar17) * DAT_00dca3f8 +
                                    uVar17 * 0x100 >> 8);
                pbVar24 = pbVar24 + 4;
                local_4c = local_4c + -1;
              } while (local_4c != 0);
            }
            local_50 = local_20;
          }
          bVar3 = false;
          if (local_70 < 0) {
            iVar22 = iVar22 + param_5;
            bVar3 = iVar9 <= iVar22;
            if (bVar3) {
              local_24 = local_24 + iVar2;
              local_38 = local_38 + 1;
              local_28 = local_28 + -iVar2;
              local_3c = local_3c + -1;
              uVar21 = uVar21 + 1;
              iVar22 = iVar22 - iVar9;
            }
            local_74 = local_74 + uVar21 * 4;
            local_70 = local_70 + 2 + uVar21 * 4;
          }
          else {
            local_2c = local_2c + 1;
            local_50 = local_50 + -1;
            param_4 = param_4 + -1;
            local_20 = local_50;
            if (local_74 < 0) {
              iVar22 = iVar22 + param_5;
              local_18 = local_18 + -4;
              bVar3 = iVar9 <= iVar22;
              if (bVar3) {
                local_24 = local_24 + iVar2;
                local_38 = local_38 + 1;
                local_28 = local_28 + -iVar2;
                local_3c = local_3c + -1;
                uVar21 = uVar21 + 1;
                iVar22 = iVar22 - iVar9;
              }
              iVar23 = (uVar21 - param_4) * 4;
              local_70 = local_70 + 2 + iVar23;
              local_74 = local_74 + 2 + iVar23;
            }
            else {
              local_18 = local_18 + -4;
              local_70 = local_70 - local_18;
              local_74 = local_74 + (2 - local_18);
            }
          }
        } while (-1 < param_4);
      }
      iVar23 = param_2 - param_4;
      param_3 = param_3 - uVar21;
      param_2 = (param_4 - param_8) + param_2;
      if ((((iVar5 <= param_3 && iVar25 <= param_2) && param_3 < iVar13) && iVar23 < iVar7) &&
          *(char *)(param_3 + iVar8) == '\0') {
        if (iVar23 < iVar25) {
          iVar23 = iVar25;
        }
        if (iVar7 < param_2) {
          param_2 = iVar7;
        }
        *(undefined1 *)(param_3 + iVar8) = 1;
        iVar25 = (param_2 - iVar23) + 1;
        pbVar24 = (byte *)(param_3 * iVar2 + iVar20 + iVar23 * 4);
        do {
          uVar21 = (uint)*pbVar24;
          *pbVar24 = (byte)((((int)(uVar21 * (param_6 & 0xff)) >> 8) - uVar21) * DAT_00dca3f8 +
                            uVar21 * 0x100 >> 8);
          uVar21 = (uint)pbVar24[1];
          pbVar24[1] = (byte)((((int)(uVar21 * param_6._1_1_) >> 8) - uVar21) * DAT_00dca3f8 +
                              uVar21 * 0x100 >> 8);
          uVar21 = (uint)pbVar24[2];
          pbVar24[2] = (byte)((((int)(uVar21 * param_6._2_1_) >> 8) - uVar21) * DAT_00dca3f8 +
                              uVar21 * 0x100 >> 8);
          pbVar24 = pbVar24 + 4;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        FUN_0056e1d0(iVar8);
        return;
      }
    }
  }
switchD_00774a8e_caseD_5:
  FUN_0056e1d0(iVar8);
  return;
switchD_0077a912_caseD_1:
  if (DAT_00dca3f8 != 0xff) {
    if (DAT_00dca3f8 == 0) goto switchD_00774a8e_caseD_5;
    if (local_70 < 0) {
      local_48 = param_4;
      if (param_4 < iVar9) {
        uVar21 = 0;
        local_70 = 0;
      }
      else {
        uVar21 = 1;
        local_48 = param_4 - iVar9;
        local_70 = 4;
        local_5c = 1;
        local_74 = iVar10 + 7;
      }
LAB_0077acec:
      local_70 = iVar4 + 5 + local_70;
    }
    else {
      param_5 = param_5 + -1;
      if (local_74 < 0) {
        local_48 = param_4;
        bVar3 = param_4 < iVar9;
        if (!bVar3) {
          local_48 = param_4 - iVar9;
        }
        local_5c = (uint)!bVar3;
        uVar21 = (uint)!bVar3;
        local_70 = (uVar21 - param_5) * 4;
        local_74 = iVar10 + 5 + local_70;
        goto LAB_0077acec;
      }
      uVar21 = 0;
      local_70 = local_70 + param_5 * -4;
      local_74 = local_74 + param_5 * -4 + 2;
    }
    if (-1 < param_5) {
      local_28 = param_5 * 4;
      local_2c = (param_5 - param_9) + param_3;
      local_50 = (uVar21 - param_8) + param_2;
      local_20 = param_2 - uVar21;
      local_24 = param_3 - param_5;
      local_14 = local_2c * iVar2;
      local_18 = local_24 * iVar2;
      iVar23 = local_48;
      local_1c = local_50;
      do {
        if (local_70 < 0) {
          local_48 = iVar23 + param_4;
          if (iVar9 <= local_48) {
            local_5c = local_5c + 1;
            local_20 = local_20 + -1;
            local_50 = local_50 + 1;
            local_48 = local_48 - iVar9;
            local_1c = local_50;
          }
          iVar23 = local_5c * 4;
          local_74 = local_74 + iVar23;
LAB_0077b03d:
          local_70 = local_70 + 2 + iVar23;
          iVar23 = local_48;
        }
        else {
          local_58 = local_20;
          if ((((iVar5 <= (int)local_24 && iVar25 <= local_50) && (int)local_24 < iVar13) &&
              local_20 < iVar7) && *(char *)(local_24 + iVar8) == '\0') {
            local_58 = iVar25;
            if (iVar25 <= local_20) {
              local_58 = local_20;
            }
            if (iVar7 < local_50) {
              local_50 = iVar7;
            }
            *(undefined1 *)(local_24 + iVar8) = 1;
            iVar23 = (local_50 - local_58) + 1;
            pbVar24 = (byte *)(local_18 + local_58 * 4 + iVar20);
            do {
              *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                (uint)*pbVar24 * 0x100 >> 8);
              pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                  (uint)pbVar24[1] * 0x100 >> 8);
              pbVar24[2] = (byte)(((uint)param_6._2_1_ - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                  (uint)pbVar24[2] * 0x100 >> 8);
              pbVar24 = pbVar24 + 4;
              iVar23 = iVar23 + -1;
            } while (iVar23 != 0);
            iVar23 = local_48;
          }
          if (!(((((int)local_2c < iVar5 || iVar13 <= (int)local_2c) || local_50 < iVar25) ||
                iVar7 <= local_58) || *(char *)(local_2c + iVar8) != '\0')) {
            if (local_58 < iVar25) {
              local_58 = iVar25;
            }
            if (iVar7 < local_50) {
              local_50 = iVar7;
            }
            *(undefined1 *)(local_2c + iVar8) = 1;
            iVar23 = (local_50 - local_58) + 1;
            pbVar24 = (byte *)(local_14 + local_58 * 4 + iVar20);
            do {
              *pbVar24 = (byte)(((param_6 & 0xff) - (uint)*pbVar24) * DAT_00dca3f8 +
                                (uint)*pbVar24 * 0x100 >> 8);
              pbVar24[1] = (byte)(((uint)param_6._1_1_ - (uint)pbVar24[1]) * DAT_00dca3f8 +
                                  (uint)pbVar24[1] * 0x100 >> 8);
              pbVar24[2] = (byte)(((uint)param_6._2_1_ - (uint)pbVar24[2]) * DAT_00dca3f8 +
                                  (uint)pbVar24[2] * 0x100 >> 8);
              pbVar24 = pbVar24 + 4;
              iVar23 = iVar23 + -1;
            } while (iVar23 != 0);
            iVar23 = local_48;
          }
          local_14 = local_14 - iVar2;
          local_24 = local_24 + 1;
          local_18 = local_18 + iVar2;
          param_5 = param_5 + -1;
          if (local_74 < 0) {
            local_48 = iVar23 + param_4;
            local_28 = local_28 + -4;
            local_2c = local_2c + -1;
            if (iVar9 <= local_48) {
              local_5c = local_5c + 1;
              local_20 = local_20 + -1;
              local_1c = local_1c + 1;
              local_48 = local_48 - iVar9;
            }
            iVar23 = (local_5c - param_5) * 4;
            local_74 = local_74 + 2 + iVar23;
            local_50 = local_1c;
            goto LAB_0077b03d;
          }
          local_2c = local_2c + -1;
          local_28 = local_28 + -4;
          local_70 = local_70 - local_28;
          local_74 = local_74 + (2 - local_28);
          local_50 = local_1c;
        }
        if (param_5 < 0) {
          FUN_0056e1d0(iVar8);
          return;
        }
      } while( true );
    }
    goto switchD_00774a8e_caseD_5;
  }
switchD_0077a912_caseD_0:
  if (local_70 < 0) {
    if (param_4 < iVar9) {
      local_24 = 0;
      local_70 = 0;
      iVar22 = param_4;
    }
    else {
      local_24 = 1;
      local_70 = 4;
      local_5c = 1;
      local_74 = iVar10 + 7;
      iVar22 = param_4 - iVar9;
    }
LAB_0077a9ae:
    local_70 = iVar4 + 5 + local_70;
  }
  else {
    param_5 = param_5 + -1;
    if (local_74 < 0) {
      bVar3 = iVar9 <= param_4;
      iVar22 = param_4;
      if (bVar3) {
        iVar22 = param_4 - iVar9;
      }
      local_5c = (uint)bVar3;
      local_24 = (uint)bVar3;
      local_70 = (local_24 - param_5) * 4;
      local_74 = iVar10 + 5 + local_70;
      goto LAB_0077a9ae;
    }
    local_24 = 0;
    local_70 = local_70 + param_5 * -4;
    local_74 = local_74 + param_5 * -4 + 2;
  }
  if (-1 < param_5) {
    local_1c = param_5 * 4;
    local_2c = (param_5 - param_9) + param_3;
    local_28 = (local_24 - param_8) + param_2;
    local_24 = param_2 - local_24;
    local_14 = local_2c * iVar2;
    local_20 = param_3 - param_5;
    local_18 = local_20 * iVar2;
    do {
      if (local_70 < 0) {
        iVar22 = iVar22 + param_4;
        if (iVar9 <= iVar22) {
          local_5c = local_5c + 1;
          local_24 = local_24 + -1;
          local_28 = local_28 + 1;
          iVar22 = iVar22 - iVar9;
        }
        iVar23 = local_5c * 4;
        local_74 = local_74 + iVar23;
LAB_0077ac2c:
        local_70 = local_70 + 2 + iVar23;
      }
      else {
        local_50 = local_28;
        local_58 = local_24;
        if ((((local_20 < iVar13 && (int)local_24 < iVar7) && iVar5 <= local_20) &&
            iVar25 <= (int)local_28) && *(char *)(local_20 + iVar8) == '\0') {
          local_58 = iVar25;
          if (iVar25 <= (int)local_24) {
            local_58 = local_24;
          }
          if (iVar7 < (int)local_28) {
            local_50 = iVar7;
          }
          *(undefined1 *)(local_20 + iVar8) = 1;
          iVar23 = (local_50 - local_58) + 1;
          puVar29 = (uint *)(local_18 + local_58 * 4 + iVar20);
          do {
            *puVar29 = param_6;
            puVar29 = puVar29 + 1;
            iVar23 = iVar23 + -1;
          } while (iVar23 != 0);
        }
        if (((((int)local_2c < iVar13 && iVar25 <= local_50) && iVar5 <= (int)local_2c) &&
            local_58 < iVar7) && *(char *)(local_2c + iVar8) == '\0') {
          if (local_58 < iVar25) {
            local_58 = iVar25;
          }
          if (iVar7 < local_50) {
            local_50 = iVar7;
          }
          local_4c = (local_50 - local_58) + 1;
          *(undefined1 *)(local_2c + iVar8) = 1;
          puVar29 = (uint *)(local_14 + local_58 * 4 + iVar20);
          do {
            *puVar29 = param_6;
            puVar29 = puVar29 + 1;
            local_4c = local_4c + -1;
          } while (local_4c != 0);
        }
        local_18 = local_18 + iVar2;
        local_14 = local_14 - iVar2;
        local_20 = local_20 + 1;
        local_2c = local_2c + -1;
        param_5 = param_5 + -1;
        if (local_74 < 0) {
          iVar22 = iVar22 + param_4;
          local_1c = local_1c + -4;
          if (iVar9 <= iVar22) {
            local_5c = local_5c + 1;
            local_24 = local_24 + -1;
            local_28 = local_28 + 1;
            iVar22 = iVar22 - iVar9;
          }
          iVar23 = (local_5c - param_5) * 4;
          local_74 = local_74 + 2 + iVar23;
          goto LAB_0077ac2c;
        }
        local_1c = local_1c + -4;
        local_70 = local_70 - local_1c;
        local_74 = local_74 + (2 - local_1c);
      }
      if (param_5 < 0) {
        FUN_0056e1d0(iVar8);
        return;
      }
    } while( true );
  }
  goto switchD_00774a8e_caseD_5;
switchD_0077c5b0_caseD_1:
  if (DAT_00dca3f8 != 0xff) {
    if (DAT_00dca3f8 == 0) goto switchD_00774a8e_caseD_5;
    if (local_70 < 0) {
      local_48 = param_4;
      if (iVar9 <= param_4) {
        local_48 = param_4 - iVar9;
      }
      local_5c = (uint)(iVar9 <= param_4);
      local_70 = local_5c * 4;
      local_74 = local_74 + local_70;
LAB_0077c97a:
      local_70 = iVar4 + 5 + local_70;
    }
    else {
      local_40 = param_5 + -1;
      if (local_74 < 0) {
        local_48 = param_4;
        if (iVar9 <= param_4) {
          local_48 = param_4 - iVar9;
        }
        local_5c = (uint)(iVar9 <= param_4);
        local_70 = (local_5c - local_40) * 4;
        local_74 = iVar10 + 5 + local_70;
        goto LAB_0077c97a;
      }
      local_70 = local_70 + local_40 * -4;
      local_74 = local_74 + local_40 * -4 + 2;
    }
    if (-1 < (int)local_40) {
      local_14 = local_40 * 4;
      local_2c = (local_40 - param_9) + param_3;
      local_28 = (local_5c - param_8) + param_2;
      local_24 = param_2 - local_5c;
      local_20 = param_3 - local_40;
      local_1c = local_2c * iVar2;
      local_18 = local_20 * iVar2;
      uVar21 = local_40;
      iVar15 = local_48;
      do {
        if (local_70 < 0) {
          local_48 = iVar15 + param_4;
          if (iVar9 <= local_48) {
            local_5c = local_5c + 1;
            local_24 = local_24 + -1;
            local_28 = local_28 + 1;
            local_48 = local_48 - iVar9;
          }
          iVar15 = local_5c * 4;
          local_74 = local_74 + iVar15;
LAB_0077cd21:
          local_70 = local_70 + 2 + iVar15;
          iVar15 = local_48;
        }
        else {
          local_58 = local_24;
          local_50 = local_28;
          if ((((iVar5 <= local_20 && iVar25 <= (int)local_28) && local_20 < iVar13) &&
              (int)local_24 < iVar7) && *(char *)(local_20 + iVar8) == '\0') {
            local_58 = iVar25;
            if (iVar25 <= (int)local_24) {
              local_58 = local_24;
            }
            if (iVar7 < (int)local_28) {
              local_50 = iVar7;
            }
            *(undefined1 *)(local_20 + iVar8) = 1;
            local_4c = (local_50 - local_58) + 1;
            puVar26 = (ushort *)(local_18 + local_58 * 2 + iVar20);
            while( true ) {
              uVar12 = *puVar26;
              local_4c = local_4c + -1;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800))
                         * 0x800 | (uVar12 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 +
                                             iVar23 * 0x800);
              if (local_4c == 0) break;
              puVar26 = puVar26 + 1;
            }
            uVar21 = local_40;
            iVar15 = local_48;
          }
          if ((((iVar5 <= (int)local_2c && iVar25 <= local_50) && (int)local_2c < iVar13) &&
              local_58 < iVar7) && *(char *)(local_2c + iVar8) == '\0') {
            if (local_58 < iVar25) {
              local_58 = iVar25;
            }
            if (iVar7 < local_50) {
              local_50 = iVar7;
            }
            local_4c = (local_50 - local_58) + 1;
            *(undefined1 *)(local_2c + iVar8) = 1;
            puVar26 = (ushort *)(local_1c + local_58 * 2 + iVar20);
            while( true ) {
              uVar12 = *puVar26;
              local_4c = local_4c + -1;
              *puVar26 = ((uVar12 >> 5 & 0x3f) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 >> 5 & 0x3f) - (uVar12 >> 5 & 0x3f)) * 4 +
                                   iVar23 * 0x800)) * 0x20 |
                         ((uVar12 >> 0xb) +
                         *(short *)(&DAT_00d4a6e0 +
                                   ((param_6 >> 0xb) - (uint)(uVar12 >> 0xb)) * 4 + iVar23 * 0x800))
                         * 0x800 | (uVar12 & 0x1f) +
                                   *(short *)(&DAT_00d4a6e0 +
                                             ((param_6 & 0x1f) - (uVar12 & 0x1f)) * 4 +
                                             iVar23 * 0x800);
              if (local_4c == 0) break;
              puVar26 = puVar26 + 1;
            }
            uVar21 = local_40;
            iVar15 = local_48;
          }
          local_18 = local_18 + iVar2;
          local_20 = local_20 + 1;
          local_2c = local_2c + -1;
          local_1c = local_1c - iVar2;
          uVar21 = uVar21 + -1;
          local_40 = uVar21;
          if (local_74 < 0) {
            local_48 = iVar15 + param_4;
            local_14 = local_14 + -4;
            if (iVar9 <= local_48) {
              local_5c = local_5c + 1;
              local_24 = local_24 + -1;
              local_28 = local_28 + 1;
              local_48 = local_48 - iVar9;
            }
            iVar15 = (local_5c - uVar21) * 4;
            local_74 = local_74 + 2 + iVar15;
            goto LAB_0077cd21;
          }
          local_14 = local_14 + -4;
          local_70 = local_70 - local_14;
          local_74 = local_74 + (2 - local_14);
        }
        if ((int)uVar21 < 0) {
          FUN_0056e1d0(iVar8);
          return;
        }
      } while( true );
    }
    goto switchD_00774a8e_caseD_5;
  }
switchD_0077c5b0_caseD_0:
  if (local_70 < 0) {
    if (param_4 < iVar9) {
      local_24 = 0;
      local_70 = 0;
      iVar22 = param_4;
    }
    else {
      local_24 = 1;
      local_70 = 4;
      local_5c = 1;
      local_74 = iVar10 + 7;
      iVar22 = param_4 - iVar9;
    }
LAB_0077c64c:
    local_70 = iVar4 + 5 + local_70;
  }
  else {
    param_5 = param_5 + -1;
    if (local_74 < 0) {
      bVar3 = iVar9 <= param_4;
      iVar22 = param_4;
      if (bVar3) {
        iVar22 = param_4 - iVar9;
      }
      local_5c = (uint)bVar3;
      local_24 = (uint)bVar3;
      local_70 = (local_24 - param_5) * 4;
      local_74 = iVar10 + 5 + local_70;
      goto LAB_0077c64c;
    }
    local_24 = 0;
    local_70 = local_70 + param_5 * -4;
    local_74 = local_74 + param_5 * -4 + 2;
  }
  if (-1 < param_5) {
    local_1c = param_5 * 4;
    local_2c = (param_5 - param_9) + param_3;
    local_28 = (local_24 - param_8) + param_2;
    local_24 = param_2 - local_24;
    local_14 = local_2c * iVar2;
    local_20 = param_3 - param_5;
    local_18 = local_20 * iVar2;
    do {
      if (local_70 < 0) {
        iVar22 = iVar22 + param_4;
        if (iVar9 <= iVar22) {
          local_5c = local_5c + 1;
          local_24 = local_24 + -1;
          local_28 = local_28 + 1;
          iVar22 = iVar22 - iVar9;
        }
        iVar23 = local_5c * 4;
        local_74 = local_74 + iVar23;
LAB_0077c8ce:
        local_70 = local_70 + 2 + iVar23;
      }
      else {
        local_50 = local_28;
        local_58 = local_24;
        if ((((local_20 < iVar13 && (int)local_24 < iVar7) && iVar5 <= local_20) &&
            iVar25 <= (int)local_28) && *(char *)(local_20 + iVar8) == '\0') {
          local_58 = iVar25;
          if (iVar25 <= (int)local_24) {
            local_58 = local_24;
          }
          if (iVar7 < (int)local_28) {
            local_50 = iVar7;
          }
          *(undefined1 *)(local_20 + iVar8) = 1;
          iVar23 = (local_50 - local_58) + 1;
          puVar16 = (undefined2 *)(local_18 + local_58 * 2 + iVar20);
          do {
            *puVar16 = (ushort)param_6;
            puVar16 = puVar16 + 1;
            iVar23 = iVar23 + -1;
          } while (iVar23 != 0);
        }
        if (((((int)local_2c < iVar13 && iVar25 <= local_50) && iVar5 <= (int)local_2c) &&
            local_58 < iVar7) && *(char *)(local_2c + iVar8) == '\0') {
          if (local_58 < iVar25) {
            local_58 = iVar25;
          }
          if (iVar7 < local_50) {
            local_50 = iVar7;
          }
          local_4c = (local_50 - local_58) + 1;
          *(undefined1 *)(local_2c + iVar8) = 1;
          puVar16 = (undefined2 *)(local_14 + local_58 * 2 + iVar20);
          do {
            *puVar16 = (ushort)param_6;
            puVar16 = puVar16 + 1;
            local_4c = local_4c + -1;
          } while (local_4c != 0);
        }
        local_18 = local_18 + iVar2;
        local_14 = local_14 - iVar2;
        local_20 = local_20 + 1;
        local_2c = local_2c + -1;
        param_5 = param_5 + -1;
        if (local_74 < 0) {
          iVar22 = iVar22 + param_4;
          local_1c = local_1c + -4;
          if (iVar9 <= iVar22) {
            local_5c = local_5c + 1;
            local_24 = local_24 + -1;
            local_28 = local_28 + 1;
            iVar22 = iVar22 - iVar9;
          }
          iVar23 = (local_5c - param_5) * 4;
          local_74 = local_74 + 2 + iVar23;
          goto LAB_0077c8ce;
        }
        local_1c = local_1c + -4;
        local_70 = local_70 - local_1c;
        local_74 = local_74 + (2 - local_1c);
      }
      if (param_5 < 0) {
        FUN_0056e1d0(iVar8);
        return;
      }
    } while( true );
  }
  goto switchD_00774a8e_caseD_5;
}

