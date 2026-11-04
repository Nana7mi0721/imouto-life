
void FUN_00676440(uint *param_1,int param_2,uint param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  byte *pbVar6;
  uint *puVar7;
  byte *pbVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  uint local_18;
  uint local_14;
  uint local_10;
  byte *local_c;
  uint local_8 [2];
  
  if ((param_2 != 0) && (param_1 != (uint *)0x0)) {
    uVar2 = *(uint *)(&DAT_0081f0a8 + param_3 * 4);
    uVar3 = *param_1;
    uVar11 = uVar3 * uVar2;
    bVar1 = *(byte *)((int)param_1 + 0xb);
    if (bVar1 == 1) {
      pbVar6 = (byte *)((uVar3 - 1 >> 3) + param_2);
      pbVar8 = (byte *)((uVar11 - 1 >> 3) + param_2);
      if ((param_4 & 0x10000) == 0) {
        param_4 = 7 - (uVar3 - 1 & 7);
        uVar4 = 7 - (uVar11 - 1 & 7);
        local_14 = 0;
        param_3 = 7;
        local_18 = 1;
      }
      else {
        param_4 = uVar3 - 1 & 7;
        uVar4 = uVar11 - 1 & 7;
        local_14 = 7;
        param_3 = 0;
        local_18 = -1;
      }
      local_10 = 0;
      local_c = pbVar6;
      if (uVar3 != 0) {
        do {
          bVar1 = *pbVar6;
          if (0 < (int)uVar2) {
            local_8[0] = uVar2;
            do {
              *pbVar8 = (byte)(0x7f7f >> (7 - (byte)uVar4 & 0x1f)) & *pbVar8 |
                        (bVar1 >> ((byte)param_4 & 0x1f) & 1) << ((byte)uVar4 & 0x1f);
              if (uVar4 == param_3) {
                pbVar8 = pbVar8 + -1;
                uVar4 = local_14;
              }
              else {
                uVar4 = uVar4 + local_18;
              }
              local_8[0] = local_8[0] - 1;
            } while (local_8[0] != 0);
            pbVar6 = local_c;
          }
          if (param_4 == param_3) {
            pbVar6 = pbVar6 + -1;
            param_4 = local_14;
            local_c = pbVar6;
          }
          else {
            param_4 = param_4 + local_18;
          }
          local_10 = local_10 + 1;
        } while (local_10 < *param_1);
      }
    }
    else if (bVar1 == 2) {
      pbVar6 = (byte *)((uVar3 - 1 >> 2) + param_2);
      pbVar8 = (byte *)((uVar11 - 1 >> 2) + param_2);
      if ((param_4 & 0x10000) == 0) {
        local_18 = 0;
        param_3 = 6;
        uVar4 = (3 - (uVar3 - 1 & 3)) * 2;
        uVar10 = (3 - (uVar11 - 1 & 3)) * 2;
        local_14 = 2;
      }
      else {
        uVar4 = uVar3 * 2 - 1 & 6;
        uVar10 = uVar11 * 2 - 1 & 6;
        local_18 = 6;
        param_3 = 0;
        local_14 = -2;
      }
      local_10 = 0;
      local_c = pbVar6;
      if (uVar3 != 0) {
        do {
          bVar1 = *pbVar6;
          if (0 < (int)uVar2) {
            local_8[0] = uVar2;
            do {
              *pbVar8 = (byte)(0x3f3f >> (6 - (byte)uVar10 & 0x1f)) & *pbVar8 |
                        (bVar1 >> ((byte)uVar4 & 0x1f) & 3) << ((byte)uVar10 & 0x1f);
              if (uVar10 == param_3) {
                pbVar8 = pbVar8 + -1;
                uVar10 = local_18;
              }
              else {
                uVar10 = uVar10 + local_14;
              }
              local_8[0] = local_8[0] - 1;
            } while (local_8[0] != 0);
            pbVar6 = local_c;
          }
          if (uVar4 == param_3) {
            pbVar6 = pbVar6 + -1;
            uVar4 = local_18;
            local_c = pbVar6;
          }
          else {
            uVar4 = uVar4 + local_14;
          }
          local_10 = local_10 + 1;
        } while (local_10 < *param_1);
      }
    }
    else if (bVar1 == 4) {
      pbVar6 = (byte *)((uVar3 - 1 >> 1) + param_2);
      pbVar8 = (byte *)((uVar11 - 1 >> 1) + param_2);
      if ((param_4 & 0x10000) == 0) {
        param_3 = 0;
        uVar4 = (uVar3 - 1 & 1) * -4 + 4;
        uVar10 = (uVar11 - 1 & 1) * -4 + 4;
        uVar13 = 4;
        local_18 = 4;
      }
      else {
        uVar4 = uVar3 * -4 - 1 & 4;
        uVar10 = uVar11 * -4 - 1 & 4;
        param_3 = 4;
        uVar13 = 0;
        local_18 = -4;
      }
      local_8[0] = 0;
      local_c = pbVar6;
      if (uVar3 != 0) {
        do {
          bVar1 = *pbVar6;
          if (0 < (int)uVar2) {
            local_10 = uVar2;
            do {
              *pbVar8 = (byte)(0xf0f >> (4 - (byte)uVar10 & 0x1f)) & *pbVar8 |
                        (bVar1 >> ((byte)uVar4 & 0x1f) & 0xf) << ((byte)uVar10 & 0x1f);
              if (uVar10 == uVar13) {
                pbVar8 = pbVar8 + -1;
                uVar10 = param_3;
              }
              else {
                uVar10 = uVar10 + local_18;
              }
              local_10 = local_10 - 1;
            } while (local_10 != 0);
            pbVar6 = local_c;
          }
          if (uVar4 == uVar13) {
            pbVar6 = pbVar6 + -1;
            uVar4 = param_3;
            local_c = pbVar6;
          }
          else {
            uVar4 = uVar4 + local_18;
          }
          local_8[0] = local_8[0] + 1;
        } while (local_8[0] < *param_1);
      }
    }
    else {
      uVar4 = (uint)(bVar1 >> 3);
      puVar7 = (uint *)((uVar3 - 1) * uVar4 + param_2);
      puVar5 = (uint *)((uVar11 - 1) * uVar4 + param_2);
      param_3 = 0;
      if (uVar3 != 0) {
        do {
          puVar9 = puVar7;
          puVar12 = local_8;
          for (uVar3 = (uint)(bVar1 >> 5); uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar12 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar12 = puVar12 + 1;
          }
          for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(char *)puVar12 = (char)*puVar9;
            puVar9 = (uint *)((int)puVar9 + 1);
            puVar12 = (uint *)((int)puVar12 + 1);
          }
          if (0 < (int)uVar2) {
            param_4 = uVar2;
            do {
              puVar9 = local_8;
              puVar12 = puVar5;
              for (uVar3 = (uint)(bVar1 >> 5); uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar12 = *puVar9;
                puVar9 = puVar9 + 1;
                puVar12 = puVar12 + 1;
              }
              puVar5 = (uint *)((int)puVar5 - uVar4);
              param_4 = param_4 - 1;
              for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                *(char *)puVar12 = (char)*puVar9;
                puVar9 = (uint *)((int)puVar9 + 1);
                puVar12 = (uint *)((int)puVar12 + 1);
              }
            } while (param_4 != 0);
          }
          puVar7 = (uint *)((int)puVar7 - uVar4);
          param_3 = param_3 + 1;
        } while (param_3 < *param_1);
      }
    }
    bVar1 = *(byte *)((int)param_1 + 0xb);
    *param_1 = uVar11;
    if (7 < bVar1) {
      param_1[1] = (bVar1 >> 3) * uVar11;
      return;
    }
    param_1[1] = bVar1 * uVar11 + 7 >> 3;
  }
  return;
}

