
undefined4 FUN_0051ab60(int param_1,int param_2,int param_3,uint param_4,int param_5,int param_6)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  short *psVar11;
  uint uVar12;
  int iVar13;
  ushort *puVar14;
  ushort *puVar15;
  ushort *local_38;
  short *local_34;
  int local_30;
  int local_2c;
  short *local_28;
  short *local_24;
  short *local_20;
  short *local_1c;
  short *local_18;
  int local_14;
  
  iVar4 = DAT_00a381a0;
  iVar3 = DAT_00a38198;
  local_2c = param_5 / 2;
  iVar9 = local_2c + param_3;
  local_28 = (short *)(param_3 - local_2c);
  if (param_5 < (iVar9 - (int)local_28) + 1) {
    local_28 = (short *)((int)local_28 + 1);
  }
  iVar7 = local_2c + param_4;
  local_2c = param_4 - local_2c;
  if (param_5 < (iVar7 - local_2c) + 1) {
    local_2c = local_2c + 1;
  }
  if (((((int)local_28 < 1) || (iVar9 < 1)) || (local_2c < 1)) || (iVar7 < 1)) {
    return 0xffffffff;
  }
  if (iVar9 < iVar7) {
    iVar13 = (iVar7 * iVar7) / iVar9;
    iVar6 = iVar7 * -2;
    param_5 = iVar6 + 3;
    iVar5 = 0;
    iVar10 = iVar7 * -4;
    param_3 = iVar10 + 3;
    uVar12 = 0;
    param_4 = 0;
    if (param_5 < 0) {
      iVar5 = iVar9;
      if (iVar13 <= iVar9) {
        iVar5 = iVar9 - iVar13;
      }
      uVar12 = (uint)(iVar13 <= iVar9);
      param_5 = uVar12 * 4;
      param_3 = param_3 + param_5;
LAB_0051b0b1:
      param_4 = (uint)(iVar13 <= iVar9);
      param_5 = iVar6 + 5 + param_5;
    }
    else {
      iVar7 = iVar7 + -1;
      if (param_3 < 0) {
        iVar5 = iVar9;
        if (iVar13 <= iVar9) {
          iVar5 = iVar9 - iVar13;
        }
        uVar12 = (uint)(iVar13 <= iVar9);
        param_5 = (uVar12 - iVar7) * 4;
        param_3 = iVar10 + 5 + param_5;
        goto LAB_0051b0b1;
      }
      param_5 = param_5 + iVar7 * -4;
      param_3 = param_3 + iVar7 * -4 + 2;
    }
    if (-1 < iVar7) {
      local_18 = (short *)(iVar7 * 4);
      local_34 = (short *)(uVar12 + param_1);
      local_20 = (short *)(iVar7 + param_2);
      local_30 = param_1 - uVar12;
      local_1c = (short *)(param_2 - iVar7);
      psVar8 = (short *)(param_6 + (int)local_20 * 10);
      psVar11 = (short *)(param_6 + (int)local_1c * 10);
      while( true ) {
        if (param_5 < 0) {
          iVar5 = iVar5 + iVar9;
          if (iVar13 <= iVar5) {
            local_30 = local_30 + -1;
            local_34 = (short *)((int)local_34 + 1);
            uVar12 = uVar12 + 1;
            iVar5 = iVar5 - iVar13;
            param_4 = uVar12;
          }
          param_3 = param_3 + uVar12 * 4;
          param_5 = param_5 + 2 + uVar12 * 4;
        }
        else {
          if (iVar3 <= (int)local_1c) {
            if (((int)local_1c < iVar4) && (((psVar11[4] & 1U) == 0 || (local_30 < *psVar11)))) {
              psVar11[4] = psVar11[4] | 1;
              *psVar11 = (short)local_30;
            }
            if (((int)local_1c < iVar4) &&
               (((psVar11[4] & 2U) == 0 || ((int)psVar11[1] < (int)local_34)))) {
              psVar11[4] = psVar11[4] | 2;
              psVar11[1] = (short)local_34;
            }
          }
          if (iVar3 <= (int)local_20) {
            if (((int)local_20 < iVar4) && (((psVar8[4] & 1U) == 0 || (local_30 < *psVar8)))) {
              psVar8[4] = psVar8[4] | 1;
              *psVar8 = (short)local_30;
            }
            if (((int)local_20 < iVar4) &&
               (((psVar8[4] & 2U) == 0 || ((int)psVar8[1] < (int)local_34)))) {
              psVar8[4] = psVar8[4] | 2;
              psVar8[1] = (short)local_34;
            }
          }
          local_1c = (short *)((int)local_1c + 1);
          local_20 = (short *)((int)local_20 + -1);
          psVar11 = psVar11 + 5;
          psVar8 = psVar8 + -5;
          iVar7 = iVar7 + -1;
          if (param_3 < 0) {
            local_18 = (short *)((int)local_18 + -4);
            iVar5 = iVar5 + iVar9;
            if (iVar13 <= iVar5) {
              param_4 = param_4 + 1;
              local_30 = local_30 + -1;
              local_34 = (short *)((int)local_34 + 1);
              iVar5 = iVar5 - iVar13;
            }
            iVar6 = (param_4 - iVar7) * 4;
            param_5 = param_5 + 2 + iVar6;
            param_3 = param_3 + 2 + iVar6;
          }
          else {
            local_18 = (short *)((int)local_18 + -4);
            param_5 = param_5 - (int)local_18;
            param_3 = param_3 + (2 - (int)local_18);
          }
        }
        if (iVar7 < 0) break;
        uVar12 = param_4;
      }
    }
  }
  else {
    iVar5 = (iVar9 * iVar9) / iVar7;
    iVar10 = 0;
    iVar13 = iVar9 * -4 + 3;
    local_38 = (ushort *)0x0;
    iVar6 = iVar9 * -2;
    if ((DAT_00a38198 <= param_2) && (param_2 < DAT_00a381a0)) {
      psVar8 = (short *)(param_6 + param_2 * 10);
      if (((psVar8[4] & 1U) == 0) || (param_1 - iVar9 < (int)*psVar8)) {
        psVar8[4] = psVar8[4] | 1;
        *psVar8 = (short)(param_1 - iVar9);
      }
    }
    if ((iVar3 <= param_2) && (param_2 < iVar4)) {
      iVar1 = param_6 + param_2 * 10;
      if (((*(ushort *)(iVar1 + 8) & 2) == 0) || ((int)*(short *)(iVar1 + 2) < iVar9 + param_1)) {
        *(ushort *)(iVar1 + 8) = *(ushort *)(iVar1 + 8) | 2;
        param_3._0_2_ = (undefined2)(iVar9 + param_1);
        *(undefined2 *)(iVar1 + 2) = (undefined2)param_3;
      }
    }
    if (iVar6 + 3 < 0) {
      bVar2 = iVar5 <= iVar7;
      iVar10 = iVar7;
      if (bVar2) {
        iVar10 = iVar7 - iVar5;
      }
      local_38 = (ushort *)(uint)bVar2;
      param_5 = iVar6 + 5 + (int)local_38 * 4;
      param_3 = iVar13 + (int)local_38 * 4;
      param_4 = iVar9;
    }
    else {
      param_4 = iVar9 + -1;
      bVar2 = true;
      if (iVar13 < 0) {
        iVar10 = iVar7;
        if (iVar5 <= iVar7) {
          iVar10 = iVar7 - iVar5;
        }
        bVar2 = true;
        local_38 = (ushort *)(uint)(iVar5 <= iVar7);
        iVar9 = ((int)local_38 - param_4) * 4;
        param_5 = iVar6 + 5 + iVar9;
        param_3 = iVar9 + 2 + iVar13;
      }
      else {
        param_5 = iVar6 + 3 + param_4 * -4;
        param_3 = iVar13 + param_4 * -4 + 2;
      }
    }
    iVar9 = param_4;
    if (0 < (int)param_4) {
      local_34 = (short *)(param_4 + param_1);
      local_18 = (short *)(param_4 * 4);
      local_24 = (short *)((int)local_38 + param_2);
      local_1c = (short *)(param_2 - (int)local_38);
      psVar8 = (short *)(param_6 + (int)local_24 * 10);
      iVar6 = param_1 - param_4;
      psVar11 = (short *)(param_6 + (int)local_1c * 10);
      do {
        if (bVar2) {
          if ((iVar3 <= (int)local_24) && ((int)local_24 < iVar4)) {
            if (((psVar8[4] & 1U) == 0) || (iVar6 < *psVar8)) {
              psVar8[4] = psVar8[4] | 1;
              *psVar8 = (short)iVar6;
            }
            if ((int)local_24 < iVar4) {
              if ((psVar8[4] & 2U) != 0) {
                iVar9 = param_4;
                if ((int)local_34 <= (int)psVar8[1]) goto LAB_0051ae16;
              }
              psVar8[4] = psVar8[4] | 2;
              psVar8[1] = (short)local_34;
            }
          }
LAB_0051ae16:
          if (iVar3 <= (int)local_1c) {
            if (((int)local_1c < iVar4) && (((psVar11[4] & 1U) == 0 || (iVar6 < *psVar11)))) {
              psVar11[4] = psVar11[4] | 1;
              *psVar11 = (short)iVar6;
            }
            if ((int)local_1c < iVar4) {
              if ((psVar11[4] & 2U) != 0) {
                iVar9 = param_4;
                if ((int)local_34 <= (int)psVar11[1]) goto LAB_0051ae73;
              }
              psVar11[4] = psVar11[4] | 2;
              psVar11[1] = (short)local_34;
            }
          }
        }
LAB_0051ae73:
        bVar2 = false;
        if (param_5 < 0) {
          iVar10 = iVar10 + iVar7;
          bVar2 = iVar5 <= iVar10;
          if (bVar2) {
            local_38 = (ushort *)((int)local_38 + 1);
            local_24 = (short *)((int)local_24 + 1);
            local_1c = (short *)((int)local_1c + -1);
            psVar8 = psVar8 + 5;
            psVar11 = psVar11 + -5;
            iVar10 = iVar10 - iVar5;
          }
          param_3 = param_3 + (int)local_38 * 4;
          param_5 = param_5 + 2 + (int)local_38 * 4;
        }
        else {
          local_34 = (short *)((int)local_34 + -1);
          iVar9 = iVar9 + -1;
          iVar6 = iVar6 + 1;
          param_4 = iVar9;
          if (param_3 < 0) {
            iVar10 = iVar10 + iVar7;
            local_18 = (short *)((int)local_18 + -4);
            bVar2 = iVar5 <= iVar10;
            if (bVar2) {
              local_38 = (ushort *)((int)local_38 + 1);
              local_24 = (short *)((int)local_24 + 1);
              local_1c = (short *)((int)local_1c + -1);
              psVar8 = psVar8 + 5;
              psVar11 = psVar11 + -5;
              iVar10 = iVar10 - iVar5;
            }
            iVar13 = ((int)local_38 - iVar9) * 4;
            param_5 = param_5 + 2 + iVar13;
            param_3 = param_3 + 2 + iVar13;
          }
          else {
            local_18 = (short *)((int)local_18 + -4);
            param_5 = param_5 - (int)local_18;
            param_3 = param_3 + (2 - (int)local_18);
          }
        }
      } while (0 < iVar9);
    }
    iVar7 = iVar9 + param_1;
    iVar6 = param_2 - (int)local_38;
    if ((iVar3 <= iVar6) && (iVar6 < iVar4)) {
      psVar8 = (short *)(param_6 + iVar6 * 10);
      if (((psVar8[4] & 1U) == 0) || (iVar7 < *psVar8)) {
        psVar8[4] = psVar8[4] | 1;
        *psVar8 = (short)iVar7;
      }
      if (((psVar8[4] & 2U) == 0) || (psVar8[1] < iVar7)) {
        psVar8[4] = psVar8[4] | 2;
        psVar8[1] = (short)iVar7;
      }
    }
    iVar7 = (int)local_38 + param_2;
    iVar9 = param_1 - iVar9;
    if ((iVar3 <= iVar7) && (iVar7 < iVar4)) {
      psVar8 = (short *)(param_6 + iVar7 * 10);
      if (((psVar8[4] & 1U) == 0) || (iVar9 < *psVar8)) {
        psVar8[4] = psVar8[4] | 1;
        *psVar8 = (short)iVar9;
      }
      if (((psVar8[4] & 2U) == 0) || (psVar8[1] < iVar9)) {
        psVar8[4] = psVar8[4] | 2;
        psVar8[1] = (short)iVar9;
      }
    }
  }
  if ((int)local_28 < local_2c) {
    iVar7 = (local_2c * local_2c) / (int)local_28;
    iVar9 = local_2c * -2;
    uVar12 = 0;
    param_3 = local_2c * -4 + 3;
    param_4 = 0;
    local_38 = (ushort *)0x0;
    if (iVar9 + 3 < 0) {
      local_38 = (ushort *)local_28;
      bVar2 = iVar7 <= (int)local_28;
      if (bVar2) {
        local_38 = (ushort *)((int)local_28 - iVar7);
      }
      param_4 = (uint)bVar2;
      uVar12 = (uint)bVar2;
      param_5 = iVar9 + 5 + uVar12 * 4;
      param_3 = param_3 + uVar12 * 4;
      iVar6 = local_2c;
    }
    else {
      iVar6 = local_2c + -1;
      if (param_3 < 0) {
        local_38 = (ushort *)local_28;
        bVar2 = iVar7 <= (int)local_28;
        if (bVar2) {
          local_38 = (ushort *)((int)local_28 - iVar7);
        }
        param_4 = (uint)bVar2;
        uVar12 = (uint)bVar2;
        param_3 = (uVar12 - iVar6) * 4;
        param_5 = iVar9 + 5 + param_3;
        param_3 = local_2c * -4 + 5 + param_3;
      }
      else {
        param_5 = iVar9 + 3 + iVar6 * -4;
        param_3 = param_3 + iVar6 * -4 + 2;
      }
    }
    if (iVar6 < 0) {
      return 0;
    }
    local_30 = uVar12 + param_1;
    local_2c = param_1 - uVar12;
    iVar9 = iVar6 + param_2;
    iVar10 = param_6 + iVar9 * 10;
    local_34 = (short *)(iVar10 + 6);
    local_20 = (short *)(param_2 - iVar6);
    puVar14 = (ushort *)(iVar10 + 8);
    local_24 = (short *)(iVar10 + 4);
    param_6 = param_6 + (int)local_20 * 10;
    local_1c = (short *)(param_6 + 6);
    puVar15 = (ushort *)(param_6 + 8);
    local_18 = (short *)(param_6 + 4);
    iVar10 = iVar6 * 4;
    do {
      if (param_5 < 0) {
        local_38 = (ushort *)((int)local_38 + (int)local_28);
        if (iVar7 <= (int)local_38) {
          param_4 = param_4 + 1;
          local_2c = local_2c + -1;
          local_30 = local_30 + 1;
          local_38 = (ushort *)((int)local_38 - iVar7);
        }
        param_3 = param_3 + param_4 * 4;
        param_5 = param_5 + 2 + param_4 * 4;
      }
      else {
        if (iVar3 <= (int)local_20) {
          if (((int)local_20 < iVar4) && (((*puVar15 & 4) == 0 || (*local_18 < local_2c)))) {
            *puVar15 = *puVar15 | 4;
            *local_18 = (short)local_2c;
          }
          if (((int)local_20 < iVar4) && (((*puVar15 & 8) == 0 || (local_30 < *local_1c)))) {
            *puVar15 = *puVar15 | 8;
            *local_1c = (short)local_30;
          }
        }
        if ((iVar3 <= iVar9) && (iVar9 < iVar4)) {
          if (((*puVar14 & 4) == 0) || (*local_24 < local_2c)) {
            *puVar14 = *puVar14 | 4;
            *local_24 = (short)local_2c;
          }
          if ((iVar9 < iVar4) && (((*puVar14 & 8) == 0 || (local_30 < *local_34)))) {
            *puVar14 = *puVar14 | 8;
            *local_34 = (short)local_30;
          }
        }
        local_20 = (short *)((int)local_20 + 1);
        local_18 = local_18 + 5;
        local_1c = local_1c + 5;
        local_24 = local_24 + -5;
        local_34 = local_34 + -5;
        iVar6 = iVar6 + -1;
        iVar9 = iVar9 + -1;
        iVar10 = iVar10 + -4;
        puVar15 = puVar15 + 5;
        puVar14 = puVar14 + -5;
        if (param_3 < 0) {
          local_38 = (ushort *)((int)local_38 + (int)local_28);
          if (iVar7 <= (int)local_38) {
            param_4 = param_4 + 1;
            local_2c = local_2c + -1;
            local_30 = local_30 + 1;
            local_38 = (ushort *)((int)local_38 - iVar7);
          }
          iVar5 = (param_4 - iVar6) * 4;
          param_5 = param_5 + 2 + iVar5;
          param_3 = param_3 + 2 + iVar5;
        }
        else {
          param_5 = param_5 - iVar10;
          param_3 = param_3 + (2 - iVar10);
        }
      }
    } while (-1 < iVar6);
    return 0;
  }
  iVar7 = ((int)local_28 * (int)local_28) / local_2c;
  iVar9 = 0;
  uVar12 = 0;
  param_4 = (uint)local_28;
  param_5 = (int)local_28 * -2 + 3;
  iVar6 = (int)local_28 * -4 + 3;
  if ((iVar3 <= param_2) && (param_2 < iVar4)) {
    iVar10 = param_6 + param_2 * 10;
    if (((*(ushort *)(iVar10 + 8) & 4) == 0) ||
       ((int)*(short *)(iVar10 + 4) < param_1 - (int)local_28)) {
      *(ushort *)(iVar10 + 8) = *(ushort *)(iVar10 + 8) | 4;
      *(short *)(iVar10 + 4) = (short)(param_1 - (int)local_28);
    }
  }
  if ((iVar3 <= param_2) && (param_2 < iVar4)) {
    iVar10 = param_6 + param_2 * 10;
    if (((*(ushort *)(iVar10 + 8) & 8) == 0) ||
       ((int)local_28 + param_1 < (int)*(short *)(iVar10 + 6))) {
      *(ushort *)(iVar10 + 8) = *(ushort *)(iVar10 + 8) | 8;
      param_3._0_2_ = (undefined2)((int)local_28 + param_1);
      *(undefined2 *)(iVar10 + 6) = (undefined2)param_3;
    }
  }
  if (param_5 < 0) {
    bVar2 = iVar7 <= local_2c;
    iVar9 = local_2c;
    if (bVar2) {
      iVar9 = local_2c - iVar7;
    }
    uVar12 = (uint)bVar2;
    param_5 = uVar12 * 4;
    param_3 = iVar6 + param_5;
  }
  else {
    param_4 = (int)local_28 + -1;
    bVar2 = true;
    if (-1 < iVar6) {
      param_5 = param_5 + param_4 * -4;
      param_3 = iVar6 + param_4 * -4 + 2;
      goto LAB_0051b3ed;
    }
    iVar9 = local_2c;
    if (iVar7 <= local_2c) {
      iVar9 = local_2c - iVar7;
    }
    uVar12 = (uint)(iVar7 <= local_2c);
    param_5 = (uVar12 - param_4) * 4;
    param_3 = (int)local_28 * -4 + 5 + param_5;
  }
  param_5 = (int)local_28 * -2 + 5 + param_5;
LAB_0051b3ed:
  if (0 < (int)param_4) {
    local_14 = param_4 * 4;
    local_34 = (short *)(param_4 + param_1);
    local_30 = param_1 - param_4;
    iVar6 = uVar12 + param_2;
    iVar10 = param_6 + iVar6 * 10;
    local_20 = (short *)(iVar10 + 6);
    local_18 = (short *)(param_2 - uVar12);
    puVar14 = (ushort *)(iVar10 + 8);
    local_1c = (short *)(iVar10 + 4);
    iVar10 = param_6 + (int)local_18 * 10;
    local_28 = (short *)(iVar10 + 6);
    local_38 = (ushort *)(iVar10 + 8);
    local_24 = (short *)(iVar10 + 4);
    do {
      if (bVar2) {
        if ((iVar3 <= iVar6) && (iVar6 < iVar4)) {
          if (((*puVar14 & 4) == 0) || (*local_1c < local_30)) {
            *puVar14 = *puVar14 | 4;
            *local_1c = (short)local_30;
          }
          if ((iVar6 < iVar4) && (((*puVar14 & 8) == 0 || ((int)local_34 < (int)*local_20)))) {
            *puVar14 = *puVar14 | 8;
            *local_20 = (short)local_34;
          }
        }
        if (iVar3 <= (int)local_18) {
          if (((int)local_18 < iVar4) && (((*local_38 & 4) == 0 || (*local_24 < local_30)))) {
            *local_38 = *local_38 | 4;
            *local_24 = (short)local_30;
          }
          if (((int)local_18 < iVar4) &&
             (((*local_38 & 8) == 0 || ((int)local_34 < (int)*local_28)))) {
            *local_38 = *local_38 | 8;
            *local_28 = (short)local_34;
          }
        }
      }
      if (param_5 < 0) {
        iVar9 = iVar9 + local_2c;
        bVar2 = iVar7 <= iVar9;
        if (bVar2) {
          local_1c = local_1c + 5;
          local_20 = local_20 + 5;
          local_24 = local_24 + -5;
          local_38 = local_38 + -5;
          local_28 = local_28 + -5;
          local_18 = (short *)((int)local_18 + -1);
          uVar12 = uVar12 + 1;
          iVar6 = iVar6 + 1;
          puVar14 = puVar14 + 5;
          iVar9 = iVar9 - iVar7;
        }
        param_3 = param_3 + uVar12 * 4;
        param_5 = param_5 + 2 + uVar12 * 4;
      }
      else {
        bVar2 = true;
        if (param_3 < 0) {
          iVar9 = iVar9 + local_2c;
          local_14 = local_14 + -4;
          param_4 = param_4 + -1;
          local_30 = local_30 + 1;
          local_34 = (short *)((int)local_34 + -1);
          if (iVar7 <= iVar9) {
            local_18 = (short *)((int)local_18 + -1);
            local_1c = local_1c + 5;
            local_20 = local_20 + 5;
            local_24 = local_24 + -5;
            local_38 = local_38 + -5;
            local_28 = local_28 + -5;
            puVar14 = puVar14 + 5;
            uVar12 = uVar12 + 1;
            iVar6 = iVar6 + 1;
            iVar9 = iVar9 - iVar7;
          }
          bVar2 = true;
          iVar10 = (uVar12 - param_4) * 4;
          param_5 = param_5 + 2 + iVar10;
          param_3 = param_3 + 2 + iVar10;
        }
        else {
          param_4 = param_4 + -1;
          local_30 = local_30 + 1;
          local_34 = (short *)((int)local_34 + -1);
          local_14 = local_14 + -4;
          param_5 = param_5 - local_14;
          param_3 = param_3 + (2 - local_14);
        }
      }
    } while (0 < (int)param_4);
  }
  iVar9 = param_4 + param_1;
  iVar7 = param_2 - uVar12;
  if ((iVar3 <= iVar7) && (iVar7 < iVar4)) {
    iVar7 = param_6 + iVar7 * 10;
    if (((*(ushort *)(iVar7 + 8) & 4) == 0) || (*(short *)(iVar7 + 4) < iVar9)) {
      *(ushort *)(iVar7 + 8) = *(ushort *)(iVar7 + 8) | 4;
      *(short *)(iVar7 + 4) = (short)iVar9;
    }
    if (((*(ushort *)(iVar7 + 8) & 8) == 0) || (iVar9 < *(short *)(iVar7 + 6))) {
      *(ushort *)(iVar7 + 8) = *(ushort *)(iVar7 + 8) | 8;
      *(short *)(iVar7 + 6) = (short)iVar9;
    }
  }
  param_1 = param_1 - param_4;
  param_2 = uVar12 + param_2;
  if ((iVar3 <= param_2) && (param_2 < iVar4)) {
    param_6 = param_6 + param_2 * 10;
    if (((*(ushort *)(param_6 + 8) & 4) == 0) || (*(short *)(param_6 + 4) < param_1)) {
      *(ushort *)(param_6 + 8) = *(ushort *)(param_6 + 8) | 4;
      *(short *)(param_6 + 4) = (short)param_1;
    }
    if (((*(ushort *)(param_6 + 8) & 8) == 0) || (param_1 < *(short *)(param_6 + 6))) {
      *(short *)(param_6 + 6) = (short)param_1;
      *(ushort *)(param_6 + 8) = *(ushort *)(param_6 + 8) | 8;
      return 0;
    }
  }
  return 0;
}

