
void FUN_006796c0(uint param_1,int param_2)

{
  char cVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  byte bVar5;
  char *pcVar6;
  uint uVar7;
  byte bVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  byte *pbVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  char *pcVar19;
  uint uVar20;
  byte *pbVar21;
  int iVar22;
  uint uVar23;
  byte *pbVar24;
  byte *pbVar25;
  undefined1 *local_28;
  uint local_24;
  uint local_20;
  byte *local_1c;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar4 = param_1;
  uVar16 = *(uint *)(param_2 + 4);
  uVar13 = (uint)*(byte *)(param_1 + 0x211);
  bVar8 = *(byte *)(param_1 + 0x156);
  iVar22 = *(int *)(param_1 + 0x120);
  puVar3 = *(undefined1 **)(param_1 + 0x124);
  uVar23 = (int)(*(byte *)(param_2 + 0xb) + 7) >> 3;
  local_24 = 0x7fffffff;
  if (((bVar8 & 8) != 0) && (bVar8 != 8)) {
    local_24 = 0;
    uVar18 = 0;
    if (uVar16 != 0) {
      do {
        uVar14 = (uint)(byte)puVar3[uVar18 + 1];
        if (0x7f < (byte)puVar3[uVar18 + 1]) {
          uVar14 = 0x100 - uVar14;
        }
        local_24 = local_24 + uVar14;
        uVar18 = uVar18 + 1;
      } while (uVar18 < uVar16);
    }
    if (*(char *)(param_1 + 0x210) == '\x02') {
      iVar9 = 0;
      uVar14 = local_24 & 0xffff;
      uVar18 = local_24 >> 10 & 0x3fffc0;
      if (uVar13 != 0) {
        do {
          if (*(char *)(*(int *)(param_1 + 0x214) + iVar9) == '\0') {
            uVar20 = (uint)*(ushort *)(*(int *)(param_1 + 0x218) + iVar9 * 2);
            uVar14 = uVar20 * uVar14 >> 8;
            uVar18 = uVar20 * uVar18 >> 8;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)uVar13);
      }
      uVar18 = **(ushort **)(param_1 + 0x220) * uVar18 >> 3;
      if (uVar18 < 0x3fffc1) {
        local_24 = (**(ushort **)(param_1 + 0x220) * uVar14 >> 3) + uVar18 * 0x400;
      }
      else {
        local_24 = 0x7fffffff;
      }
    }
  }
  if (bVar8 == 0x10) {
    pcVar19 = puVar3 + 1;
    pcVar6 = (char *)(*(int *)(param_1 + 0x128) + 1);
    uVar14 = 0;
    pcVar10 = pcVar19;
    for (uVar18 = uVar23; uVar18 != 0; uVar18 = uVar18 - 1) {
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      *pcVar6 = cVar1;
      pcVar6 = pcVar6 + 1;
      uVar14 = uVar23;
    }
    if (uVar14 < uVar16) {
      iVar9 = uVar16 - uVar14;
      do {
        cVar1 = *pcVar10;
        cVar2 = *pcVar19;
        pcVar10 = pcVar10 + 1;
        pcVar19 = pcVar19 + 1;
        *pcVar6 = cVar1 - cVar2;
        pcVar6 = pcVar6 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    local_28 = *(undefined1 **)(param_1 + 0x128);
LAB_00679837:
    if ((bVar8 & 0x20) != 0) {
      uVar18 = 0;
      local_10 = local_24;
      if (*(char *)(param_1 + 0x210) == '\x02') {
        uVar20 = local_24 & 0xffff;
        uVar14 = local_24 >> 10 & 0x3fffc0;
        iVar9 = 0;
        if (uVar13 != 0) {
          do {
            if (*(char *)(iVar9 + *(int *)(param_1 + 0x214)) == '\x02') {
              uVar7 = (uint)*(ushort *)(*(int *)(param_1 + 0x21c) + iVar9 * 2);
              uVar20 = uVar20 * uVar7 >> 8;
              uVar14 = uVar14 * uVar7 >> 8;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)uVar13);
        }
        uVar7 = (uint)*(ushort *)(*(int *)(param_1 + 0x224) + 4);
        uVar14 = uVar7 * uVar14 >> 3;
        if (uVar14 < 0x3fffc1) {
          local_10 = (uVar7 * uVar20 >> 3) + uVar14 * 0x400;
        }
        else {
          local_10 = 0x7fffffff;
        }
      }
      local_c = 0;
      pcVar10 = puVar3 + 1;
      pbVar15 = *(byte **)(param_1 + 300);
      if (uVar16 != 0) {
        iVar9 = (iVar22 + 1) - (int)pcVar10;
        do {
          pbVar15 = pbVar15 + 1;
          cVar1 = *pcVar10;
          cVar2 = pcVar10[iVar9];
          *pbVar15 = cVar1 - cVar2;
          uVar14 = (uint)(byte)(cVar1 - cVar2);
          pcVar10 = pcVar10 + 1;
          if (0x7f < uVar14) {
            uVar14 = 0x100 - uVar14;
          }
          uVar18 = uVar18 + uVar14;
        } while ((uVar18 <= local_10) && (local_c = local_c + 1, local_c < uVar16));
      }
      if (*(char *)(param_1 + 0x210) == '\x02') {
        uVar14 = uVar18 & 0xffff;
        uVar18 = uVar18 >> 10 & 0x3fffc0;
        iVar9 = 0;
        if (uVar13 != 0) {
          do {
            if (*(char *)(iVar9 + *(int *)(param_1 + 0x214)) == '\x02') {
              uVar20 = (uint)*(ushort *)(*(int *)(param_1 + 0x218) + iVar9 * 2);
              uVar14 = uVar14 * uVar20 >> 8;
              uVar18 = uVar18 * uVar20 >> 8;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)uVar13);
        }
        uVar20 = (uint)*(ushort *)(*(int *)(param_1 + 0x220) + 4);
        uVar18 = uVar20 * uVar18 >> 3;
        if (uVar18 < 0x3fffc1) {
          uVar18 = (uVar20 * uVar14 >> 3) + uVar18 * 0x400;
        }
        else {
          uVar18 = 0x7fffffff;
        }
      }
      if (uVar18 < local_24) {
        local_28 = *(undefined1 **)(param_1 + 300);
        local_24 = uVar18;
      }
    }
    if (bVar8 != 0x40) goto LAB_00679aec;
    pcVar10 = (char *)(*(int *)(param_1 + 0x130) + 1);
    pbVar15 = puVar3 + 1;
    pbVar21 = (byte *)(iVar22 + 1);
    param_1 = 0;
    pbVar24 = pbVar15;
    if (uVar23 != 0) {
      param_1 = uVar23;
      do {
        *pcVar10 = *pbVar24 - (*pbVar21 >> 1);
        pcVar10 = pcVar10 + 1;
        pbVar21 = pbVar21 + 1;
        pbVar24 = pbVar24 + 1;
        param_1 = param_1 - 1;
      } while (param_1 != 0);
      param_1 = uVar23;
    }
    if (param_1 < uVar16) {
      param_1 = uVar16 - param_1;
      do {
        *pcVar10 = *pbVar24 - (char)(((uint)*pbVar21 + (uint)*pbVar15) / 2);
        pcVar10 = pcVar10 + 1;
        pbVar15 = pbVar15 + 1;
        pbVar21 = pbVar21 + 1;
        pbVar24 = pbVar24 + 1;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
    local_28 = *(undefined1 **)(iVar4 + 0x130);
  }
  else {
    local_28 = puVar3;
    if ((bVar8 & 0x10) != 0) {
      uVar18 = 0;
      local_10 = local_24;
      if (*(char *)(param_1 + 0x210) == '\x02') {
        uVar20 = local_24 & 0xffff;
        uVar14 = local_24 >> 10 & 0x3fffc0;
        iVar9 = 0;
        if (uVar13 != 0) {
          do {
            if (*(char *)(*(int *)(param_1 + 0x214) + iVar9) == '\x01') {
              uVar7 = (uint)*(ushort *)(*(int *)(param_1 + 0x21c) + iVar9 * 2);
              uVar20 = uVar7 * uVar20 >> 8;
              uVar14 = uVar7 * uVar14 >> 8;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)uVar13);
        }
        uVar7 = (uint)*(ushort *)(*(int *)(param_1 + 0x224) + 2);
        uVar14 = uVar7 * uVar14 >> 3;
        if (uVar14 < 0x3fffc1) {
          local_10 = (uVar7 * uVar20 >> 3) + uVar14 * 0x400;
        }
        else {
          local_10 = 0x7fffffff;
        }
      }
      local_20 = 0;
      pbVar15 = puVar3 + 1;
      pbVar21 = (byte *)(*(int *)(param_1 + 0x128) + 1);
      pbVar24 = pbVar15;
      if (uVar23 != 0) {
        local_c = uVar23;
        do {
          bVar5 = *pbVar24;
          *pbVar21 = bVar5;
          uVar14 = (uint)bVar5;
          if (0x7f < uVar14) {
            uVar14 = 0x100 - uVar14;
          }
          uVar18 = uVar18 + uVar14;
          pbVar24 = pbVar24 + 1;
          pbVar21 = pbVar21 + 1;
          local_c = local_c - 1;
          local_20 = uVar23;
        } while (local_c != 0);
      }
      for (; local_20 < uVar16; local_20 = local_20 + 1) {
        bVar5 = *pbVar24;
        bVar12 = *pbVar15;
        *pbVar21 = bVar5 - bVar12;
        uVar14 = (uint)(byte)(bVar5 - bVar12);
        if (0x7f < uVar14) {
          uVar14 = 0x100 - uVar14;
        }
        uVar18 = uVar18 + uVar14;
        if (local_10 < uVar18) break;
        pbVar15 = pbVar15 + 1;
        pbVar21 = pbVar21 + 1;
        pbVar24 = pbVar24 + 1;
      }
      if (*(char *)(param_1 + 0x210) == '\x02') {
        uVar14 = uVar18 & 0xffff;
        uVar18 = uVar18 >> 10 & 0x3fffc0;
        iVar9 = 0;
        if (uVar13 != 0) {
          do {
            if (*(char *)(iVar9 + *(int *)(param_1 + 0x214)) == '\x01') {
              uVar20 = (uint)*(ushort *)(*(int *)(param_1 + 0x21c) + iVar9 * 2);
              uVar14 = uVar14 * uVar20 >> 8;
              uVar18 = uVar18 * uVar20 >> 8;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)uVar13);
        }
        uVar20 = (uint)*(ushort *)(*(int *)(param_1 + 0x224) + 2);
        uVar18 = uVar20 * uVar18 >> 3;
        if (uVar18 < 0x3fffc1) {
          uVar18 = (uVar20 * uVar14 >> 3) + uVar18 * 0x400;
        }
        else {
          uVar18 = 0x7fffffff;
        }
      }
      if (uVar18 < local_24) {
        local_28 = *(undefined1 **)(param_1 + 0x128);
        local_24 = uVar18;
      }
    }
    if (bVar8 != 0x20) goto LAB_00679837;
    pcVar10 = *(char **)(param_1 + 300);
    uVar18 = 0;
    if (uVar16 != 0) {
      pcVar6 = puVar3 + iVar22 + (1 - (int)puVar3);
      do {
        pcVar10 = pcVar10 + 1;
        iVar9 = uVar18 + 1;
        cVar1 = *pcVar6;
        uVar18 = uVar18 + 1;
        pcVar6 = pcVar6 + 1;
        *pcVar10 = puVar3[iVar9] - cVar1;
      } while (uVar18 < uVar16);
    }
    local_28 = *(undefined1 **)(param_1 + 300);
LAB_00679aec:
    if ((bVar8 & 0x40) != 0) {
      iVar9 = 0;
      local_20 = 0;
      local_c = local_24;
      if (*(char *)(param_1 + 0x210) == '\x02') {
        uVar14 = local_24 & 0xffff;
        uVar18 = local_24 >> 10 & 0x3fffc0;
        if (uVar13 != 0) {
          do {
            if (*(char *)(iVar9 + *(int *)(param_1 + 0x214)) == '\x03') {
              uVar20 = (uint)*(ushort *)(*(int *)(param_1 + 0x21c) + iVar9 * 2);
              uVar14 = uVar20 * uVar14 >> 8;
              uVar18 = uVar20 * uVar18 >> 8;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)uVar13);
        }
        uVar20 = (uint)*(ushort *)(*(int *)(param_1 + 0x224) + 6);
        uVar18 = uVar20 * uVar18 >> 3;
        if (uVar18 < 0x3fffc1) {
          local_c = (uVar20 * uVar14 >> 3) + uVar18 * 0x400;
        }
        else {
          local_c = 0x7fffffff;
        }
      }
      local_10 = 0;
      pbVar15 = puVar3 + 1;
      pbVar24 = (byte *)(*(int *)(param_1 + 0x130) + 1);
      pbVar21 = (byte *)(iVar22 + 1);
      pbVar25 = pbVar15;
      if (uVar23 != 0) {
        local_8 = uVar23;
        do {
          bVar5 = *pbVar25 - (*pbVar21 >> 1);
          *pbVar24 = bVar5;
          uVar18 = (uint)bVar5;
          pbVar24 = pbVar24 + 1;
          pbVar21 = pbVar21 + 1;
          pbVar25 = pbVar25 + 1;
          if (0x7f < uVar18) {
            uVar18 = 0x100 - uVar18;
          }
          local_20 = local_20 + uVar18;
          local_8 = local_8 - 1;
          local_10 = uVar23;
        } while (local_8 != 0);
      }
      for (; local_10 < uVar16; local_10 = local_10 + 1) {
        bVar5 = *pbVar25 - (char)(((uint)*pbVar15 + (uint)*pbVar21) / 2);
        *pbVar24 = bVar5;
        uVar18 = (uint)bVar5;
        pbVar24 = pbVar24 + 1;
        pbVar15 = pbVar15 + 1;
        pbVar21 = pbVar21 + 1;
        if (0x7f < uVar18) {
          uVar18 = 0x100 - uVar18;
        }
        local_20 = local_20 + uVar18;
        if (local_c < local_20) break;
        pbVar25 = pbVar25 + 1;
      }
      if (*(char *)(param_1 + 0x210) == '\x02') {
        iVar9 = 0;
        uVar18 = local_20 & 0xffff;
        uVar14 = local_20 >> 10 & 0x3fffc0;
        if (uVar13 != 0) {
          do {
            if (*(char *)(iVar9 + *(int *)(param_1 + 0x214)) == '\0') {
              uVar20 = (uint)*(ushort *)(*(int *)(param_1 + 0x218) + iVar9 * 2);
              uVar18 = uVar18 * uVar20 >> 8;
              uVar14 = uVar14 * uVar20 >> 8;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)uVar13);
        }
        uVar20 = (uint)*(ushort *)(*(int *)(param_1 + 0x220) + 6);
        uVar14 = uVar20 * uVar14 >> 3;
        if (uVar14 < 0x3fffc1) {
          local_20 = (uVar20 * uVar18 >> 3) + uVar14 * 0x400;
        }
        else {
          local_20 = 0x7fffffff;
        }
      }
      if (local_20 < local_24) {
        local_28 = *(undefined1 **)(param_1 + 0x130);
        local_24 = local_20;
      }
    }
    if (bVar8 == 0x80) {
      pbVar15 = puVar3 + 1;
      pcVar10 = (char *)(*(int *)(param_1 + 0x134) + 1);
      pbVar21 = (byte *)(iVar22 + 1);
      local_10 = 0;
      pbVar24 = pbVar21;
      local_1c = pbVar15;
      if (uVar23 != 0) {
        pcVar6 = pcVar10;
        uVar18 = uVar23;
        do {
          bVar8 = *pbVar24;
          pcVar10 = pcVar6 + 1;
          pbVar24 = pbVar24 + 1;
          *pcVar6 = *local_1c - bVar8;
          local_1c = local_1c + 1;
          uVar18 = uVar18 - 1;
          pcVar6 = pcVar10;
          local_10 = uVar23;
        } while (uVar18 != 0);
      }
      if (local_10 < uVar16) {
        iVar22 = (int)pbVar21 - (int)pbVar15;
        local_10 = uVar16 - local_10;
        do {
          bVar8 = pbVar15[iVar22];
          bVar5 = *pbVar24;
          bVar12 = *pbVar15;
          pbVar24 = pbVar24 + 1;
          iVar9 = (uint)bVar5 - (uint)bVar8;
          pbVar15 = pbVar15 + 1;
          iVar11 = (uint)bVar12 - (uint)bVar8;
          if (iVar9 < 0) {
            local_8 = -iVar9;
          }
          else {
            local_8 = iVar9;
          }
          iVar17 = iVar11;
          if (iVar11 < 0) {
            iVar17 = -iVar11;
          }
          iVar9 = iVar9 + iVar11;
          if (iVar9 < 0) {
            iVar9 = -iVar9;
          }
          if (((iVar17 < (int)local_8) || (iVar9 < (int)local_8)) &&
             (bVar12 = bVar8, iVar17 <= iVar9)) {
            bVar12 = bVar5;
          }
          *pcVar10 = *local_1c - bVar12;
          pcVar10 = pcVar10 + 1;
          local_1c = local_1c + 1;
          local_10 = local_10 + -1;
        } while (local_10 != 0);
      }
      local_28 = *(undefined1 **)(param_1 + 0x134);
      goto LAB_0067a225;
    }
  }
  if ((bVar8 & 0x80) != 0) {
    iVar9 = 0;
    param_1 = 0;
    local_20 = local_24;
    if (*(char *)(iVar4 + 0x210) == '\x02') {
      uVar14 = local_24 & 0xffff;
      uVar18 = local_24 >> 10 & 0x3fffc0;
      if (uVar13 != 0) {
        do {
          if (*(char *)(iVar9 + *(int *)(iVar4 + 0x214)) == '\x04') {
            uVar20 = (uint)*(ushort *)(*(int *)(iVar4 + 0x21c) + iVar9 * 2);
            uVar14 = uVar20 * uVar14 >> 8;
            uVar18 = uVar20 * uVar18 >> 8;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)uVar13);
      }
      uVar20 = (uint)*(ushort *)(*(int *)(iVar4 + 0x224) + 8);
      uVar18 = uVar20 * uVar18 >> 3;
      if (uVar18 < 0x3fffc1) {
        local_20 = (uVar20 * uVar14 >> 3) + uVar18 * 0x400;
      }
      else {
        local_20 = 0x7fffffff;
      }
    }
    pbVar15 = puVar3 + 1;
    pbVar25 = (byte *)(*(int *)(iVar4 + 0x134) + 1);
    pbVar21 = (byte *)(iVar22 + 1);
    local_10 = 0;
    pbVar24 = pbVar21;
    local_1c = pbVar15;
    if (uVar23 != 0) {
      local_8 = uVar23;
      do {
        bVar8 = *local_1c;
        bVar5 = *pbVar24;
        *pbVar25 = bVar8 - bVar5;
        uVar18 = (uint)(byte)(bVar8 - bVar5);
        pbVar25 = pbVar25 + 1;
        pbVar24 = pbVar24 + 1;
        local_1c = local_1c + 1;
        if (0x7f < uVar18) {
          uVar18 = 0x100 - uVar18;
        }
        param_1 = param_1 + uVar18;
        local_8 = local_8 - 1;
      } while (local_8 != 0);
      local_10 = uVar23;
    }
    if (local_10 < uVar16) {
      iVar22 = (int)pbVar21 - (int)pbVar15;
      do {
        bVar8 = *pbVar24;
        bVar5 = pbVar15[iVar22];
        pbVar24 = pbVar24 + 1;
        bVar12 = *pbVar15;
        iVar9 = (uint)bVar8 - (uint)bVar5;
        pbVar15 = pbVar15 + 1;
        iVar11 = (uint)bVar12 - (uint)bVar5;
        if (iVar9 < 0) {
          local_8 = -iVar9;
        }
        else {
          local_8 = iVar9;
        }
        iVar17 = iVar11;
        if (iVar11 < 0) {
          iVar17 = -iVar11;
        }
        iVar9 = iVar9 + iVar11;
        if (iVar9 < 0) {
          iVar9 = -iVar9;
        }
        if ((iVar17 < (int)local_8) || (iVar9 < (int)local_8)) {
          if (iVar9 < iVar17) {
            bVar8 = bVar5;
          }
        }
        else {
          bVar8 = bVar12;
        }
        bVar5 = *local_1c;
        *pbVar25 = bVar5 - bVar8;
        uVar23 = (uint)(byte)(bVar5 - bVar8);
        pbVar25 = pbVar25 + 1;
        local_1c = local_1c + 1;
        if (0x7f < uVar23) {
          uVar23 = 0x100 - uVar23;
        }
        param_1 = param_1 + uVar23;
      } while ((param_1 <= local_20) && (local_10 = local_10 + 1, local_10 < uVar16));
    }
    if (*(char *)(iVar4 + 0x210) == '\x02') {
      uVar16 = param_1 & 0xffff;
      uVar23 = param_1 >> 10 & 0x3fffc0;
      iVar22 = 0;
      if (uVar13 != 0) {
        do {
          if (*(char *)(iVar22 + *(int *)(iVar4 + 0x214)) == '\x04') {
            uVar18 = (uint)*(ushort *)(*(int *)(iVar4 + 0x218) + iVar22 * 2);
            uVar16 = uVar16 * uVar18 >> 8;
            uVar23 = uVar23 * uVar18 >> 8;
          }
          iVar22 = iVar22 + 1;
        } while (iVar22 < (int)uVar13);
      }
      uVar18 = (uint)*(ushort *)(*(int *)(iVar4 + 0x220) + 8);
      uVar23 = uVar18 * uVar23 >> 3;
      if (uVar23 < 0x3fffc1) {
        param_1 = (uVar18 * uVar16 >> 3) + uVar23 * 0x400;
      }
      else {
        param_1 = 0x7fffffff;
      }
    }
    if (param_1 < local_24) {
      local_28 = *(undefined1 **)(iVar4 + 0x134);
    }
  }
LAB_0067a225:
  FUN_0067a290(iVar4,local_28,*(int *)(param_2 + 4) + 1);
  if (*(char *)(iVar4 + 0x211) != '\0') {
    iVar22 = 1;
    if (1 < uVar13) {
      do {
        puVar3 = (undefined1 *)(iVar22 + *(int *)(iVar4 + 0x214));
        iVar22 = iVar22 + 1;
        *puVar3 = puVar3[-1];
      } while (iVar22 < (int)uVar13);
    }
    *(undefined1 *)(*(int *)(iVar4 + 0x214) + iVar22) = *local_28;
  }
  return;
}

