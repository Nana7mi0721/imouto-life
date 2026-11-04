
uint FUN_007985c0(byte *param_1,uint param_2,int param_3,byte *param_4,undefined4 *param_5,
                 short *param_6,int *param_7,undefined4 *param_8)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  short *psVar15;
  int local_c;
  int local_8;
  
  local_c = 0;
  if (param_6 == (short *)0x0) {
    return 0xffffffff;
  }
  iVar5 = FUN_00798510(param_1,48000);
  bVar1 = *param_1;
  cVar3 = '\0';
  pbVar14 = param_1 + 1;
  uVar11 = param_2 - 1;
  if ((bVar1 & 3) == 0) {
    param_2 = 1;
    uVar13 = uVar11;
LAB_007987fd:
    uVar12 = uVar11;
    uVar11 = uVar13;
    if (param_3 == 0) {
LAB_00798778:
      if (0x4fb < (int)uVar13) {
        return 0xfffffffc;
      }
      param_6[param_2 - 1] = (short)uVar13;
      goto LAB_00798876;
    }
  }
  else {
    if ((bVar1 & 3) != 1) {
      if ((bVar1 & 3) == 2) {
        param_2 = 2;
        iVar5 = FUN_00798900(pbVar14,uVar11,param_6);
        sVar4 = *param_6;
        uVar11 = uVar11 - iVar5;
        if (sVar4 < 0) {
          return 0xfffffffc;
        }
        if ((int)uVar11 < (int)sVar4) {
          return 0xfffffffc;
        }
        pbVar14 = pbVar14 + iVar5;
        uVar13 = uVar11 - (int)sVar4;
      }
      else {
        if ((int)uVar11 < 1) {
          return 0xfffffffc;
        }
        bVar2 = *pbVar14;
        pbVar14 = param_1 + 2;
        uVar7 = bVar2 & 0x3f;
        if ((bVar2 & 0x3f) == 0) {
          return 0xfffffffc;
        }
        if (0x1680 < (int)(uVar7 * iVar5)) {
          return 0xfffffffc;
        }
        uVar12 = param_2 - 2;
        if ((bVar2 & 0x40) != 0) {
          do {
            if ((int)uVar12 < 1) {
              return 0xfffffffc;
            }
            uVar8 = (uint)*pbVar14;
            pbVar14 = pbVar14 + 1;
            uVar13 = 0xfe;
            if (uVar8 != 0xff) {
              uVar13 = uVar8;
            }
            uVar12 = (uVar12 - 1) - uVar13;
            local_c = local_c + uVar13;
          } while (uVar8 == 0xff);
        }
        if ((int)uVar12 < 0) {
          return 0xfffffffc;
        }
        cVar3 = -((char)~bVar2 >> 7);
        param_2 = uVar7;
        if (cVar3 != '\0') {
          if (param_3 == 0) {
            uVar13 = (int)uVar12 / (int)uVar7;
            if (uVar7 * uVar13 != uVar12) {
              return 0xfffffffc;
            }
            uVar7 = uVar7 - 1;
            if (0 < (int)uVar7) {
              sVar4 = (short)uVar13;
              psVar15 = param_6;
              for (uVar11 = uVar7 >> 1; uVar11 != 0; uVar11 = uVar11 - 1) {
                *(uint *)psVar15 = CONCAT22(sVar4,sVar4);
                psVar15 = psVar15 + 2;
              }
              for (uVar11 = (uint)((uVar7 & 1) != 0); uVar11 != 0; uVar11 = uVar11 - 1) {
                *psVar15 = sVar4;
                psVar15 = psVar15 + 1;
              }
            }
            goto LAB_00798778;
          }
          goto LAB_00798809;
        }
        local_8 = 0;
        uVar13 = uVar12;
        psVar15 = param_6;
        if (0 < (int)(uVar7 - 1)) {
          do {
            iVar5 = FUN_00798900(pbVar14,uVar12,psVar15);
            sVar4 = *psVar15;
            uVar12 = uVar12 - iVar5;
            if (sVar4 < 0) {
              return 0xfffffffc;
            }
            if ((int)uVar12 < (int)sVar4) {
              return 0xfffffffc;
            }
            pbVar14 = pbVar14 + iVar5;
            uVar13 = uVar13 - (sVar4 + iVar5);
            local_8 = local_8 + 1;
            psVar15 = psVar15 + 1;
          } while (local_8 < (int)(uVar7 - 1));
        }
        uVar11 = uVar12;
        if ((int)uVar13 < 0) {
          return 0xfffffffc;
        }
      }
      goto LAB_007987fd;
    }
    param_2 = 2;
    cVar3 = '\x01';
    uVar12 = uVar11;
    if (param_3 == 0) {
      if ((uVar11 & 1) != 0) {
        return 0xfffffffc;
      }
      uVar13 = (int)uVar11 / 2;
      *param_6 = (short)uVar13;
      goto LAB_00798778;
    }
  }
LAB_00798809:
  psVar15 = param_6 + (param_2 - 1);
  iVar5 = FUN_00798900(pbVar14,uVar12,psVar15);
  if ((*psVar15 < 0) || (iVar9 = (int)*psVar15, (int)(uVar12 - iVar5) < iVar9)) {
    return 0xfffffffc;
  }
  pbVar14 = pbVar14 + iVar5;
  if (cVar3 == '\0') {
    if ((int)uVar11 < iVar9 + iVar5) {
      return 0xfffffffc;
    }
  }
  else {
    if ((int)(uVar12 - iVar5) < (int)(iVar9 * param_2)) {
      return 0xfffffffc;
    }
    iVar5 = param_2 - 1;
    if (0 < iVar5) {
      psVar6 = param_6;
      do {
        *psVar6 = *psVar15;
        psVar6 = psVar6 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
LAB_00798876:
  if (param_7 != (int *)0x0) {
    *param_7 = (int)pbVar14 - (int)param_1;
  }
  if (param_2 != 0) {
    puVar10 = param_5;
    uVar11 = param_2;
    do {
      if (param_5 != (undefined4 *)0x0) {
        *puVar10 = pbVar14;
      }
      pbVar14 = pbVar14 + *param_6;
      puVar10 = puVar10 + 1;
      param_6 = param_6 + 1;
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
  }
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = pbVar14 + (local_c - (int)param_1);
  }
  if (param_4 != (byte *)0x0) {
    *param_4 = bVar1;
  }
  return param_2;
}

