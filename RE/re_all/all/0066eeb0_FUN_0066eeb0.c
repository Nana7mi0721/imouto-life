
undefined4 FUN_0066eeb0(int param_1,int *param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  char cVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  ushort uVar10;
  uint uVar11;
  byte *pbVar12;
  int iVar13;
  byte *pbVar14;
  uint uVar15;
  byte *pbVar16;
  byte *pbVar17;
  undefined4 local_20;
  uint local_c;
  int local_8;
  uint local_4;
  
  bVar4 = *(byte *)(param_2 + 2);
  local_20 = 0;
  if (((bVar4 & 1) != 0) || ((bVar4 & 2) == 0)) {
    return 0;
  }
  iVar2 = *param_2;
  uVar11 = (uint)*(ushort *)(param_1 + 0x264);
  uVar15 = (uint)*(ushort *)(param_1 + 0x262);
  uVar7 = (bVar4 & 4) >> 2;
  iVar13 = (0x8000 - uVar11) - uVar15;
  local_8 = iVar2;
  if (*(char *)((int)param_2 + 9) == '\b') {
    if ((*(int *)(param_1 + 0x198) == 0) || (*(int *)(param_1 + 0x19c) == 0)) {
      if (iVar2 != 0) {
        pbVar14 = param_3;
        local_c = iVar2;
        do {
          bVar4 = *param_3;
          local_4 = (uint)bVar4;
          pbVar16 = param_3 + 3;
          if ((bVar4 != param_3[1]) || (bVar4 != param_3[2])) {
            local_20 = 1;
            bVar4 = (byte)((uint)param_3[2] * iVar13 + param_3[1] * uVar11 + local_4 * uVar15 >> 0xf
                          );
          }
          *pbVar14 = bVar4;
          pbVar12 = pbVar14 + 1;
          if (uVar7 != 0) {
            *pbVar12 = *pbVar16;
            pbVar12 = pbVar14 + 2;
            pbVar16 = param_3 + 4;
          }
          local_c = local_c + -1;
          param_3 = pbVar16;
          pbVar14 = pbVar12;
        } while (local_c != 0);
      }
    }
    else if (iVar2 != 0) {
      pbVar14 = param_3;
      do {
        bVar4 = *pbVar14;
        local_c = (uint)bVar4;
        pbVar16 = pbVar14 + 3;
        if ((bVar4 == pbVar14[1]) && (bVar4 == pbVar14[2])) {
          if (*(int *)(param_1 + 400) != 0) {
            bVar4 = *(byte *)(local_c + *(int *)(param_1 + 400));
          }
          *param_3 = bVar4;
        }
        else {
          iVar3 = *(int *)(param_1 + 0x19c);
          local_20 = 1;
          *param_3 = *(byte *)(((uint)*(byte *)((uint)pbVar14[2] + iVar3) * iVar13 +
                                *(byte *)((uint)pbVar14[1] + iVar3) * uVar11 + 0x4000 +
                                *(byte *)(local_c + iVar3) * uVar15 >> 0xf) +
                              *(int *)(param_1 + 0x198));
        }
        pbVar12 = param_3 + 1;
        if (uVar7 != 0) {
          *pbVar12 = *pbVar16;
          pbVar12 = param_3 + 2;
          pbVar16 = pbVar14 + 4;
        }
        local_8 = local_8 + -1;
        param_3 = pbVar12;
        pbVar14 = pbVar16;
      } while (local_8 != 0);
    }
  }
  else if ((*(int *)(param_1 + 0x1a4) == 0) || (*(int *)(param_1 + 0x1a0) == 0)) {
    if (iVar2 != 0) {
      pbVar14 = param_3;
      pbVar16 = param_3;
      param_3 = (byte *)iVar2;
      while( true ) {
        uVar10 = CONCAT11(*pbVar16,pbVar16[1]);
        pbVar12 = pbVar16 + 6;
        if ((uVar10 != CONCAT11(pbVar16[2],pbVar16[3])) ||
           (uVar10 != CONCAT11(pbVar16[4],pbVar16[5]))) {
          local_20 = 1;
        }
        uVar8 = (uint)CONCAT11(pbVar16[4],pbVar16[5]) * iVar13 +
                CONCAT11(pbVar16[2],pbVar16[3]) * uVar11 + 0x4000 + uVar10 * uVar15 >> 0xf;
        *pbVar14 = (byte)(uVar8 >> 8);
        pbVar14[1] = (byte)uVar8;
        pbVar17 = pbVar14 + 2;
        if (uVar7 != 0) {
          *pbVar17 = *pbVar12;
          pbVar14[3] = pbVar16[7];
          pbVar17 = pbVar14 + 4;
          pbVar12 = pbVar16 + 8;
        }
        param_3 = (byte *)((int)param_3 + -1);
        if (param_3 == (byte *)0x0) break;
        pbVar14 = pbVar17;
        pbVar16 = pbVar12;
      }
    }
  }
  else if (iVar2 != 0) {
    pbVar14 = param_3;
    do {
      bVar4 = *pbVar14;
      bVar1 = pbVar14[1];
      sVar6 = CONCAT11(bVar4,bVar1);
      pbVar16 = pbVar14 + 6;
      if ((sVar6 == CONCAT11(pbVar14[2],pbVar14[3])) && (sVar6 == CONCAT11(pbVar14[4],pbVar14[5])))
      {
        if (*(int *)(param_1 + 0x194) != 0) {
          sVar6 = *(short *)(*(int *)(*(int *)(param_1 + 0x194) +
                                     (uint)(bVar1 >> (*(byte *)(param_1 + 0x188) & 0x1f)) * 4) +
                            (uint)bVar4 * 2);
        }
      }
      else {
        bVar9 = (byte)*(undefined2 *)(param_1 + 0x188);
        uVar8 = *(ushort *)
                 (*(int *)(*(int *)(param_1 + 0x1a4) + (uint)(bVar1 >> (bVar9 & 0x1f)) * 4) +
                 (uint)bVar4 * 2) * uVar15 + 0x4000 +
                *(ushort *)
                 (*(int *)(*(int *)(param_1 + 0x1a4) + (uint)(pbVar14[3] >> (bVar9 & 0x1f)) * 4) +
                 (uint)pbVar14[2] * 2) * uVar11 +
                (uint)*(ushort *)
                       (*(int *)(*(int *)(param_1 + 0x1a4) +
                                (uint)(pbVar14[5] >> (bVar9 & 0x1f)) * 4) + (uint)pbVar14[4] * 2) *
                iVar13 >> 0xf;
        sVar6 = *(short *)(*(int *)(*(int *)(param_1 + 0x1a0) +
                                   ((uVar8 & 0xff) >> (bVar9 & 0x1f)) * 4) +
                          ((uVar8 & 0xffff) >> 8) * 2);
        local_20 = 1;
      }
      *param_3 = (byte)((ushort)sVar6 >> 8);
      param_3[1] = (byte)sVar6;
      pbVar12 = param_3 + 2;
      if (uVar7 != 0) {
        param_3[2] = *pbVar16;
        param_3[3] = pbVar14[7];
        pbVar16 = pbVar14 + 8;
        pbVar12 = param_3 + 4;
      }
      param_3 = pbVar12;
      local_8 = local_8 + -1;
      pbVar14 = pbVar16;
    } while (local_8 != 0);
  }
  cVar5 = *(char *)((int)param_2 + 10) + -2;
  *(char *)((int)param_2 + 10) = cVar5;
  bVar4 = cVar5 * *(char *)((int)param_2 + 9);
  *(byte *)(param_2 + 2) = *(byte *)(param_2 + 2) & 0xfd;
  *(byte *)((int)param_2 + 0xb) = bVar4;
  if (bVar4 < 8) {
    param_2[1] = (uint)bVar4 * iVar2 + 7 >> 3;
    return local_20;
  }
  param_2[1] = (uint)(bVar4 >> 3) * iVar2;
  return local_20;
}

