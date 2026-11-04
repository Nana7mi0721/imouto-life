
undefined4 FUN_0051a320(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  ushort *puVar12;
  int iVar13;
  int local_38;
  int local_34;
  ushort *local_30;
  int local_2c;
  ushort *local_24;
  ushort *local_20;
  ushort *local_1c;
  int local_18;
  int local_14;
  
  iVar5 = param_2;
  iVar4 = param_1;
  iVar3 = DAT_00a381a0;
  iVar2 = DAT_00a38198;
  iVar7 = param_4 / 2 + param_3;
  local_1c = (ushort *)(param_3 - param_4 / 2);
  if (param_4 < (iVar7 - (int)local_1c) + 1) {
    local_1c = (ushort *)((int)local_1c + 1);
  }
  param_4 = iVar7 * -2 + 3;
  if ((DAT_00a38198 <= param_2) && (param_2 < DAT_00a381a0)) {
    psVar1 = (short *)(param_5 + param_2 * 10);
    if (((psVar1[4] & 1U) == 0) || (param_1 - iVar7 < (int)*psVar1)) {
      psVar1[4] = psVar1[4] | 1;
      *psVar1 = (short)(param_1 - iVar7);
    }
  }
  if ((iVar2 <= param_2) && (param_2 < iVar3)) {
    iVar6 = param_5 + param_2 * 10;
    if (((*(ushort *)(iVar6 + 8) & 2) == 0) || ((int)*(short *)(iVar6 + 2) < iVar7 + param_1)) {
      *(ushort *)(iVar6 + 8) = *(ushort *)(iVar6 + 8) | 2;
      param_1._0_2_ = (undefined2)(iVar7 + param_1);
      *(undefined2 *)(iVar6 + 2) = (undefined2)param_1;
    }
  }
  iVar6 = iVar7 + param_2;
  sVar8 = (short)iVar4;
  if ((iVar2 <= iVar6) && (iVar6 < iVar3)) {
    psVar1 = (short *)(param_5 + iVar6 * 10);
    if (((psVar1[4] & 1U) == 0) || (iVar4 < *psVar1)) {
      psVar1[4] = psVar1[4] | 1;
      *psVar1 = sVar8;
    }
    if (((psVar1[4] & 2U) == 0) || (psVar1[1] < iVar4)) {
      psVar1[4] = psVar1[4] | 2;
      psVar1[1] = sVar8;
    }
  }
  iVar6 = param_2 - iVar7;
  if ((iVar2 <= iVar6) && (iVar6 < iVar3)) {
    psVar1 = (short *)(param_5 + iVar6 * 10);
    if (((psVar1[4] & 1U) == 0) || (iVar4 < *psVar1)) {
      psVar1[4] = psVar1[4] | 1;
      *psVar1 = sVar8;
    }
    if (((psVar1[4] & 2U) == 0) || (psVar1[1] < iVar4)) {
      psVar1[4] = psVar1[4] | 2;
      psVar1[1] = sVar8;
    }
  }
  if (param_4 < 0) {
    param_3 = iVar7;
  }
  else {
    param_4 = param_4 + (iVar7 + -1) * -4;
    param_3 = iVar7 + -1;
  }
  param_4 = param_4 + 6;
  local_18 = 1;
  if (0 < param_3) {
    local_14 = param_3 * 4;
    local_38 = param_3 + iVar4;
    local_24 = (ushort *)(param_5 + 8 + (param_3 + param_2) * 10);
    local_20 = (ushort *)(param_5 + 8 + (param_2 - param_3) * 10);
    iVar7 = param_5 + param_2 * 10;
    puVar9 = (ushort *)(iVar7 + 0x12);
    local_30 = (ushort *)(iVar7 + -2);
    iVar6 = iVar4 - param_2;
    iVar7 = param_2 - iVar4;
    param_2 = param_2 - param_3;
    local_34 = iVar4;
    local_2c = iVar4;
    do {
      local_2c = local_2c + -1;
      local_34 = local_34 + 1;
      iVar13 = local_34 + iVar7;
      if (iVar2 <= iVar13) {
        if ((iVar13 < iVar3) && (((*puVar9 & 1) == 0 || (param_2 + iVar6 < (int)(short)puVar9[-4])))
           ) {
          *puVar9 = *puVar9 | 1;
          puVar9[-4] = (short)param_2 + (short)iVar6;
        }
        if (((iVar2 <= iVar13) && (iVar13 < iVar3)) &&
           (((*puVar9 & 2) == 0 || ((short)puVar9[-3] < local_38)))) {
          *puVar9 = *puVar9 | 2;
          puVar9[-3] = (ushort)local_38;
        }
      }
      iVar13 = local_38 + iVar7;
      if (iVar2 <= iVar13) {
        if ((iVar13 < iVar3) && (((*local_24 & 2) == 0 || ((short)local_24[-3] < local_34)))) {
          *local_24 = *local_24 | 2;
          local_24[-3] = (ushort)local_34;
        }
        if (((iVar2 <= iVar13) && (iVar13 < iVar3)) &&
           (((*local_24 & 1) == 0 || (local_2c < (short)local_24[-4])))) {
          *local_24 = *local_24 | 1;
          local_24[-4] = (ushort)local_2c;
        }
      }
      iVar13 = local_2c + iVar7;
      if (iVar2 <= iVar13) {
        if ((iVar13 < iVar3) && (((*local_30 & 2) == 0 || ((short)local_30[-3] < local_38)))) {
          *local_30 = *local_30 | 2;
          local_30[-3] = (ushort)local_38;
        }
        if (((iVar2 <= iVar13) && (iVar13 < iVar3)) &&
           (((*local_30 & 1) == 0 || (param_2 + iVar6 < (int)(short)local_30[-4])))) {
          *local_30 = *local_30 | 1;
          local_30[-4] = (short)param_2 + (short)iVar6;
        }
      }
      if (iVar2 <= param_2) {
        if ((param_2 < iVar3) && (((*local_20 & 2) == 0 || ((short)local_20[-3] < local_34)))) {
          *local_20 = *local_20 | 2;
          local_20[-3] = (ushort)local_34;
        }
        if ((param_2 < iVar3) && (((*local_20 & 1) == 0 || (local_2c < (short)local_20[-4])))) {
          *local_20 = *local_20 | 1;
          local_20[-4] = (ushort)local_2c;
        }
      }
      if (-1 < param_4) {
        param_3 = param_3 + -1;
        local_38 = local_38 + -1;
        param_2 = param_2 + 1;
        local_24 = local_24 + -5;
        local_20 = local_20 + 5;
        local_14 = local_14 + -4;
        param_4 = param_4 - local_14;
      }
      local_18 = local_18 + 1;
      local_30 = local_30 + -5;
      puVar9 = puVar9 + 5;
      param_4 = param_4 + 2 + local_18 * 4;
    } while (local_18 <= param_3);
  }
  param_4 = (int)local_1c * -2 + 3;
  param_3 = (int)local_1c;
  if ((iVar2 <= iVar5) && (iVar5 < iVar3)) {
    iVar7 = param_5 + iVar5 * 10;
    if (((*(ushort *)(iVar7 + 8) & 4) == 0) || ((int)*(short *)(iVar7 + 4) < iVar4 - (int)local_1c))
    {
      *(ushort *)(iVar7 + 8) = *(ushort *)(iVar7 + 8) | 4;
      *(short *)(iVar7 + 4) = (short)(iVar4 - (int)local_1c);
    }
  }
  if ((iVar2 <= iVar5) && (iVar5 < iVar3)) {
    iVar7 = param_5 + iVar5 * 10;
    if (((*(ushort *)(iVar7 + 8) & 8) == 0) || ((int)local_1c + iVar4 < (int)*(short *)(iVar7 + 6)))
    {
      *(ushort *)(iVar7 + 8) = *(ushort *)(iVar7 + 8) | 8;
      *(short *)(iVar7 + 6) = (short)((int)local_1c + iVar4);
    }
  }
  iVar7 = (int)local_1c + iVar5;
  if ((iVar2 <= iVar7) && (iVar7 < iVar3)) {
    iVar7 = param_5 + iVar7 * 10;
    if (((*(ushort *)(iVar7 + 8) & 4) == 0) || (*(short *)(iVar7 + 4) < iVar4)) {
      *(ushort *)(iVar7 + 8) = *(ushort *)(iVar7 + 8) | 4;
      *(short *)(iVar7 + 4) = sVar8;
    }
    if (((*(ushort *)(iVar7 + 8) & 8) == 0) || (iVar4 < *(short *)(iVar7 + 6))) {
      *(ushort *)(iVar7 + 8) = *(ushort *)(iVar7 + 8) | 8;
      *(short *)(iVar7 + 6) = sVar8;
    }
  }
  iVar7 = iVar5 - (int)local_1c;
  if ((iVar2 <= iVar7) && (iVar7 < iVar3)) {
    iVar7 = param_5 + iVar7 * 10;
    if (((*(ushort *)(iVar7 + 8) & 4) == 0) || (*(short *)(iVar7 + 4) < iVar4)) {
      *(ushort *)(iVar7 + 8) = *(ushort *)(iVar7 + 8) | 4;
      *(short *)(iVar7 + 4) = sVar8;
    }
    if (((*(ushort *)(iVar7 + 8) & 8) == 0) || (iVar4 < *(short *)(iVar7 + 6))) {
      *(ushort *)(iVar7 + 8) = *(ushort *)(iVar7 + 8) | 8;
      *(short *)(iVar7 + 6) = sVar8;
    }
  }
  if (-1 < param_4) {
    param_3 = (int)local_1c + -1;
    param_4 = param_4 + param_3 * -4;
  }
  param_4 = param_4 + 6;
  local_18 = 1;
  if (0 < param_3) {
    local_14 = param_3 * 4;
    local_2c = param_3 + iVar4;
    param_2 = iVar5 - param_3;
    puVar10 = (ushort *)(param_5 + 8 + (param_3 + iVar5) * 10);
    iVar7 = param_5 + iVar5 * 10;
    puVar11 = (ushort *)(param_5 + 8 + param_2 * 10);
    puVar9 = (ushort *)(iVar7 + 0x12);
    iVar6 = iVar4 - iVar5;
    puVar12 = (ushort *)(iVar7 + -2);
    iVar5 = iVar5 - iVar4;
    local_30 = puVar11;
    local_1c = puVar10;
    local_38 = iVar4;
    local_34 = iVar4;
    do {
      local_34 = local_34 + 1;
      local_38 = local_38 + -1;
      iVar7 = local_34 + iVar5;
      if (iVar2 <= iVar7) {
        if (iVar7 < iVar3) {
          if ((*puVar9 & 4) != 0) {
            puVar10 = local_1c;
            puVar11 = local_30;
            if (param_2 + iVar6 <= (int)(short)puVar9[-2]) goto LAB_0051a98c;
          }
          *puVar9 = *puVar9 | 4;
          puVar9[-2] = (short)iVar6 + (short)param_2;
        }
LAB_0051a98c:
        if (((iVar2 <= iVar7) && (iVar7 < iVar3)) &&
           (((*puVar9 & 8) == 0 || (local_2c < (short)puVar9[-1])))) {
          *puVar9 = *puVar9 | 8;
          puVar9[-1] = (ushort)local_2c;
        }
      }
      iVar7 = local_2c + iVar5;
      if (iVar2 <= iVar7) {
        if (iVar7 < iVar3) {
          if ((*puVar10 & 8) != 0) {
            puVar11 = local_30;
            if ((short)puVar10[-1] <= local_34) goto LAB_0051a9f4;
          }
          *puVar10 = *puVar10 | 8;
          puVar10[-1] = (ushort)local_34;
        }
LAB_0051a9f4:
        if (((iVar2 <= iVar7) && (iVar7 < iVar3)) &&
           (((*puVar10 & 4) == 0 || ((short)puVar10[-2] < local_38)))) {
          *puVar10 = *puVar10 | 4;
          puVar10[-2] = (ushort)local_38;
        }
      }
      iVar7 = local_38 + iVar5;
      if (iVar2 <= iVar7) {
        if (iVar7 < iVar3) {
          if ((*puVar12 & 8) != 0) {
            puVar11 = local_30;
            if ((short)puVar12[-1] <= local_2c) goto LAB_0051aa5c;
          }
          *puVar12 = *puVar12 | 8;
          puVar12[-1] = (ushort)local_2c;
        }
LAB_0051aa5c:
        if (((iVar2 <= iVar7) && (iVar7 < iVar3)) &&
           (((*puVar12 & 4) == 0 || ((int)(short)puVar12[-2] < param_2 + iVar6)))) {
          *puVar12 = *puVar12 | 4;
          puVar12[-2] = (short)iVar6 + (short)param_2;
        }
      }
      if (iVar2 <= param_2) {
        if ((param_2 < iVar3) && (((*puVar11 & 8) == 0 || (local_34 < (short)puVar11[-1])))) {
          *puVar11 = *puVar11 | 8;
          puVar11[-1] = (ushort)local_34;
        }
        if ((param_2 < iVar3) && (((*puVar11 & 4) == 0 || ((short)puVar11[-2] < local_38)))) {
          *puVar11 = *puVar11 | 4;
          puVar11[-2] = (ushort)local_38;
        }
      }
      if (-1 < param_4) {
        param_3 = param_3 + -1;
        local_2c = local_2c + -1;
        param_2 = param_2 + 1;
        puVar10 = puVar10 + -5;
        puVar11 = puVar11 + 5;
        local_14 = local_14 + -4;
        param_4 = param_4 - local_14;
        local_30 = puVar11;
        local_1c = puVar10;
      }
      local_18 = local_18 + 1;
      puVar9 = puVar9 + 5;
      puVar12 = puVar12 + -5;
      param_4 = param_4 + 2 + local_18 * 4;
    } while (local_18 <= param_3);
  }
  return 0;
}

