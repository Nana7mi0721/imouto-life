
void FUN_0067a560(int *param_1,byte *param_2,byte *param_3)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  undefined2 uVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  uint local_20 [4];
  int local_10 [4];
  
  pbVar3 = param_3;
  pbVar11 = param_2;
  if (*(byte *)(param_1 + 2) != 3) {
    bVar6 = *(byte *)((int)param_1 + 9);
    if ((*(byte *)(param_1 + 2) & 2) == 0) {
      pbVar1 = param_3 + 3;
      param_3 = (byte *)0x1;
      uVar9 = 1;
      local_10[0] = (uint)bVar6 - (uint)*pbVar1;
      local_20[0] = (uint)*pbVar1;
    }
    else {
      uVar9 = (uint)bVar6;
      local_10[0] = uVar9 - *param_3;
      local_20[0] = (uint)*param_3;
      local_20[1] = (uint)param_3[1];
      local_10[1] = uVar9 - param_3[1];
      local_20[2] = (uint)param_3[2];
      local_10[2] = uVar9 - param_3[2];
      uVar9 = 3;
      param_3 = (byte *)0x3;
    }
    if ((*(byte *)(param_1 + 2) & 4) != 0) {
      uVar10 = (uint)pbVar3[4];
      local_20[uVar9] = uVar10;
      local_10[uVar9] = bVar6 - uVar10;
      uVar9 = uVar9 + 1;
      param_3 = (byte *)uVar9;
    }
    if (bVar6 < 8) {
      bVar2 = pbVar3[3];
      param_1 = (int *)param_1[1];
      if ((bVar2 == 1) && (bVar6 == 2)) {
        param_2 = (byte *)0x55;
      }
      else if ((bVar6 != 4) || (param_2 = (byte *)0x11, bVar2 != 3)) {
        param_2 = (byte *)0xff;
      }
      if (param_1 != (int *)0x0) {
        do {
          uVar9 = 0;
          bVar6 = 0;
          if ((int)-local_20[0] < local_10[0]) {
            iVar4 = local_10[0];
            do {
              if (iVar4 < 1) {
                uVar10 = (uint)(*pbVar11 >> (-(byte)iVar4 & 0x1f)) & (uint)param_2;
              }
              else {
                uVar10 = (uint)*pbVar11 << ((byte)iVar4 & 0x1f);
              }
              uVar9 = uVar9 | uVar10;
              bVar6 = (byte)uVar9;
              iVar4 = iVar4 - local_20[0];
            } while ((int)-local_20[0] < iVar4);
          }
          *pbVar11 = bVar6;
          pbVar11 = pbVar11 + 1;
          param_1 = (int *)((int)param_1 + -1);
        } while (param_1 != (int *)0x0);
        return;
      }
    }
    else if (bVar6 == 8) {
      iVar4 = *param_1;
      param_3 = (byte *)0x0;
      if (iVar4 * uVar9 != 0) {
        do {
          uVar10 = 0;
          bVar6 = 0;
          for (iVar5 = local_10[(uint)param_3 % uVar9];
              (int)-local_20[(uint)param_3 % uVar9] < iVar5;
              iVar5 = iVar5 - local_20[(uint)param_3 % uVar9]) {
            if (iVar5 < 1) {
              uVar12 = (uint)(*param_2 >> (-(byte)iVar5 & 0x1f));
            }
            else {
              uVar12 = (uint)*param_2 << ((byte)iVar5 & 0x1f);
            }
            uVar10 = uVar10 | uVar12;
            bVar6 = (byte)uVar10;
          }
          *param_2 = bVar6;
          param_3 = (byte *)((int)param_3 + 1);
          param_2 = param_2 + 1;
        } while (param_3 < iVar4 * uVar9);
        return;
      }
    }
    else {
      uVar10 = *param_1 * uVar9;
      param_2 = (byte *)0x0;
      if (uVar10 != 0) {
        while( true ) {
          uVar12 = 0;
          uVar8 = 0;
          for (iVar4 = local_10[(uint)param_2 % uVar9];
              (int)-local_20[(uint)param_2 % uVar9] < iVar4;
              iVar4 = iVar4 - local_20[(uint)param_2 % uVar9]) {
            if (iVar4 < 1) {
              uVar7 = (uint)(ushort)(CONCAT11(*pbVar11,pbVar11[1]) >> (-(byte)iVar4 & 0x1f));
            }
            else {
              uVar7 = (uint)CONCAT11(*pbVar11,pbVar11[1]) << ((byte)iVar4 & 0x1f);
            }
            uVar12 = uVar12 | uVar7;
            uVar8 = (undefined2)uVar12;
          }
          *pbVar11 = (byte)((ushort)uVar8 >> 8);
          pbVar11[1] = (byte)uVar8;
          pbVar11 = pbVar11 + 2;
          param_2 = (byte *)((int)param_2 + 1);
          if (uVar10 <= param_2) break;
          uVar9 = (uint)param_3;
        }
      }
    }
  }
  return;
}

