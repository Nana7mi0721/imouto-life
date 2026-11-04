
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0058d210(int param_1,char *param_2,byte *param_3,float param_4,float param_5,int param_6)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  float fVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  char cVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  char cVar21;
  char *pcVar22;
  int iVar23;
  int iVar24;
  int local_20;
  uint local_14;
  
  param_3 = (byte *)((float)param_3 / (float)_DAT_007d9bd8);
  if (param_2 == (char *)0x0) {
    if (_DAT_007d5550 <= (float)param_3) {
      if ((float)param_3 <= _DAT_007d589c) {
      }
      else {
        param_3 = (byte *)_DAT_007d589c;
      }
    }
    else {
      param_3 = (byte *)_DAT_007d5550;
    }
  }
  else if (0.0 <= (float)param_3) {
    if (1.0 < (float)param_3) {
      param_3 = (byte *)1.0;
    }
  }
  else {
    param_3 = (byte *)0.0;
  }
  param_4 = param_4 / (float)_DAT_00829840;
  if (_DAT_007d5340 <= param_4) {
    if (1.0 < param_4) {
      param_4 = 1.0;
    }
  }
  else {
    param_4 = _DAT_007d5340;
  }
  param_5 = param_5 / (float)_DAT_00829840;
  if (DAT_00a37dc8 == 1) {
    FUN_005db8e0(param_1,param_2,(float)param_3 * (float)_DAT_008053e0,param_4,param_5,param_6);
    return 0;
  }
  local_14 = (uint)ROUND((float)param_3 * (float)_DAT_008053e0 * (float)_DAT_008052e8);
  if (0.0 < param_4) {
    param_4 = param_4 * (float)_DAT_007d5558;
  }
  fVar5 = param_4 * (float)_DAT_008052e8;
  iVar1 = (int)ROUND(param_5 * (float)_DAT_008052e8);
  iVar7 = FUN_00586970(param_1,1);
  if (iVar7 < 0) {
    return 0xffffffff;
  }
  local_20 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24);
  param_3 = *(byte **)(param_1 + 0x48c);
  iVar7 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20);
  pcVar22 = *(char **)(param_1 + 0xd0c);
  iVar16 = *(int *)(param_1 + 0x488) + iVar7 * -4;
  iVar23 = *(int *)(param_1 + 0xd08) + iVar7 * -4;
  if (param_2 != (char *)0x1) {
    param_2 = pcVar22;
    do {
      param_5 = (float)iVar7;
      do {
        if (param_6 == 0) {
          bVar3 = *param_3;
          bVar4 = param_3[1];
          bVar2 = param_3[2];
        }
        else {
          bVar2 = param_3[3];
          bVar3 = (&DAT_00a62a60)[CONCAT11(*param_3,bVar2)];
          bVar4 = (&DAT_00a62a60)[CONCAT11(param_3[1],bVar2)];
          bVar2 = (&DAT_00a62a60)[CONCAT11(param_3[2],bVar2)];
        }
        uVar13 = (uint)bVar2;
        uVar9 = (uint)bVar4;
        uVar8 = (uint)bVar3;
        if (iVar1 < 1) {
          iVar10 = iVar1 + 0x100;
          iVar18 = (int)(iVar10 * uVar8) >> 8;
          iVar14 = (int)(iVar10 * uVar9) >> 8;
          iVar10 = (int)(iVar10 * uVar13) >> 8;
        }
        else {
          iVar18 = uVar8 + ((int)((0xff - uVar8) * iVar1) >> 8);
          iVar14 = uVar9 + ((int)((0xff - uVar9) * iVar1) >> 8);
          iVar10 = uVar13 + ((int)((0xff - uVar13) * iVar1) >> 8);
        }
        if (iVar14 < iVar10) {
          if (iVar10 <= iVar18) goto LAB_0058d812;
          iVar15 = iVar10;
        }
        else {
          iVar15 = iVar14;
          if (iVar14 <= iVar18) {
LAB_0058d812:
            iVar15 = iVar18;
          }
        }
        if (iVar10 < iVar14) {
          if (iVar18 <= iVar10) goto LAB_0058d826;
          iVar11 = iVar10;
        }
        else {
          iVar11 = iVar14;
          if (iVar18 <= iVar14) {
LAB_0058d826:
            iVar11 = iVar18;
          }
        }
        iVar20 = iVar11 + iVar15;
        iVar19 = iVar20 >> 1;
        iVar24 = iVar15 - iVar11;
        if (iVar15 == iVar11) {
          iVar11 = 0;
          param_4 = 0.0;
        }
        else {
          if (0x80 < iVar19) {
            iVar20 = (0x200 - iVar11) - iVar15;
          }
          param_4 = (float)((iVar24 * 0x100) / iVar20);
          iVar11 = ((iVar15 - iVar18) * 0x100) / iVar24;
          iVar18 = ((iVar15 - iVar14) * 0x100) / iVar24;
          iVar24 = ((iVar15 - iVar10) * 0x100) / iVar24;
          if (iVar10 == iVar15) {
            iVar11 = iVar11 - iVar18;
          }
          else if (iVar14 == iVar15) {
            iVar11 = (iVar24 - iVar11) + 0x200;
          }
          else {
            iVar11 = (iVar18 - iVar24) + 0x400;
          }
          if (iVar11 < 0) {
            iVar11 = iVar11 + 0x600;
          }
        }
        uVar8 = iVar11 + local_14;
        if ((int)uVar8 < 0) {
          uVar8 = uVar8 + 0x600;
        }
        else if (0x5ff < (int)uVar8) {
          uVar8 = uVar8 - 0x600;
        }
        iVar10 = ((int)ROUND(fVar5) + 0x100) * (int)param_4 >> 8;
        if (0x100 < iVar10) {
          iVar10 = 0x100;
        }
        uVar9 = uVar8 & 0xff;
        if ((int)uVar8 < 0x100) {
          uVar8 = 0;
          uVar13 = uVar9;
          uVar17 = 0xff;
        }
        else if ((int)uVar8 < 0x200) {
          uVar13 = 0xff;
          uVar8 = 0;
          uVar17 = 0xff - uVar9;
        }
        else if ((int)uVar8 < 0x300) {
          uVar13 = 0xff;
          uVar8 = uVar9;
          uVar17 = 0;
        }
        else if ((int)uVar8 < 0x400) {
          uVar13 = 0xff - uVar9;
          uVar8 = 0xff;
          uVar17 = 0;
        }
        else {
          uVar13 = 0;
          if ((int)uVar8 < 0x500) {
            uVar8 = 0xff;
            uVar17 = uVar9;
          }
          else {
            uVar17 = 0xff;
            uVar8 = 0xff - uVar9;
          }
        }
        iVar10 = 0x100 - iVar10;
        iVar14 = uVar8 + ((int)((0x80 - uVar8) * iVar10) >> 8);
        iVar18 = uVar13 + ((int)((0x80 - uVar13) * iVar10) >> 8);
        iVar10 = uVar17 + ((int)((0x80 - uVar17) * iVar10) >> 8);
        if (iVar19 < 0x81) {
          iVar19 = iVar19 * 2;
          cVar21 = (char)((uint)(iVar19 * iVar14) >> 8);
          cVar6 = (char)((uint)(iVar19 * iVar18) >> 8);
          cVar12 = (char)((uint)(iVar19 * iVar10) >> 8);
        }
        else {
          iVar19 = iVar19 + -0x80;
          cVar21 = (char)((uint)((0xff - iVar14) * iVar19 * 2) >> 8) + (char)iVar14;
          cVar6 = (char)((uint)((0xff - iVar18) * iVar19 * 2) >> 8) + (char)iVar18;
          cVar12 = (char)((uint)((0xff - iVar10) * iVar19 * 2) >> 8) + (char)iVar10;
        }
        param_2[1] = cVar6;
        param_2[2] = cVar12;
        *param_2 = cVar21;
        if (param_6 != 0) {
          *param_2 = (&DAT_00a52a60)[CONCAT11(cVar21,param_3[3])];
          param_2[1] = (&DAT_00a52a60)[CONCAT11(param_2[1],param_3[3])];
          param_2[2] = (&DAT_00a52a60)[CONCAT11(param_2[2],param_3[3])];
        }
        param_2[3] = param_3[3];
        param_3 = param_3 + 4;
        param_2 = param_2 + 4;
        param_5 = (float)((int)param_5 + -1);
      } while (param_5 != 0.0);
      param_3 = param_3 + iVar16;
      param_2 = param_2 + iVar23;
      local_20 = local_20 + -1;
      if (local_20 == 0) {
        FUN_00586b00();
        return 0;
      }
    } while( true );
  }
  if (0x5ff < (int)local_14) {
    local_14 = local_14 - 0x600;
  }
  uVar8 = local_14 & 0xff;
  do {
    param_5 = (float)iVar7;
    do {
      if (param_6 == 0) {
        bVar3 = *param_3;
        bVar4 = param_3[1];
        bVar2 = param_3[2];
      }
      else {
        bVar2 = param_3[3];
        bVar3 = (&DAT_00a62a60)[CONCAT11(*param_3,bVar2)];
        bVar4 = (&DAT_00a62a60)[CONCAT11(param_3[1],bVar2)];
        bVar2 = (&DAT_00a62a60)[CONCAT11(param_3[2],bVar2)];
      }
      uVar17 = (uint)bVar2;
      uVar13 = (uint)bVar4;
      uVar9 = (uint)bVar3;
      if (iVar1 < 1) {
        iVar18 = iVar1 + 0x100;
        iVar10 = (int)(iVar18 * uVar9) >> 8;
        iVar14 = (int)(iVar18 * uVar13) >> 8;
        iVar18 = (int)(iVar18 * uVar17) >> 8;
      }
      else {
        iVar10 = uVar9 + ((int)((0xff - uVar9) * iVar1) >> 8);
        iVar14 = uVar13 + ((int)((0xff - uVar13) * iVar1) >> 8);
        iVar18 = uVar17 + ((int)((0xff - uVar17) * iVar1) >> 8);
      }
      if (iVar14 < iVar18) {
        if (iVar18 <= iVar10) goto LAB_0058d53f;
        iVar15 = iVar18;
      }
      else {
        iVar15 = iVar14;
        if (iVar14 <= iVar10) {
LAB_0058d53f:
          iVar15 = iVar10;
        }
      }
      if (iVar18 < iVar14) {
        if (iVar18 < iVar10) {
          iVar10 = iVar18;
        }
      }
      else if (iVar14 < iVar10) {
        iVar10 = iVar14;
      }
      iVar18 = iVar10 + iVar15;
      iVar14 = iVar18 >> 1;
      if (iVar15 == iVar10) {
        iVar18 = 0;
      }
      else {
        if (0x80 < iVar14) {
          iVar18 = (0x200 - iVar10) - iVar15;
        }
        iVar18 = ((iVar15 - iVar10) * 0x100) / iVar18;
      }
      iVar10 = ((int)ROUND(fVar5) + 0x100) * iVar18 >> 8;
      if (0x100 < iVar10) {
        iVar10 = 0x100;
      }
      if ((int)local_14 < 0x100) {
        uVar13 = 0;
        uVar9 = uVar8;
        uVar17 = 0xff;
      }
      else if ((int)local_14 < 0x200) {
        uVar9 = 0xff;
        uVar13 = 0;
        uVar17 = 0xff - uVar8;
      }
      else if ((int)local_14 < 0x300) {
        uVar9 = 0xff;
        uVar13 = uVar8;
        uVar17 = 0;
      }
      else if ((int)local_14 < 0x400) {
        uVar9 = 0xff - uVar8;
        uVar13 = 0xff;
        uVar17 = 0;
      }
      else {
        uVar9 = 0;
        if ((int)local_14 < 0x500) {
          uVar13 = 0xff;
          uVar17 = uVar8;
        }
        else {
          uVar17 = 0xff;
          uVar13 = 0xff - uVar8;
        }
      }
      iVar10 = 0x100 - iVar10;
      iVar18 = uVar13 + ((int)((0x80 - uVar13) * iVar10) >> 8);
      iVar15 = uVar9 + ((int)((0x80 - uVar9) * iVar10) >> 8);
      iVar10 = uVar17 + ((int)((0x80 - uVar17) * iVar10) >> 8);
      if (iVar14 < 0x81) {
        iVar14 = iVar14 * 2;
        cVar21 = (char)((uint)(iVar14 * iVar18) >> 8);
        cVar6 = (char)((uint)(iVar14 * iVar15) >> 8);
        cVar12 = (char)((uint)(iVar14 * iVar10) >> 8);
      }
      else {
        iVar14 = iVar14 + -0x80;
        cVar21 = (char)((uint)((0xff - iVar18) * iVar14 * 2) >> 8) + (char)iVar18;
        cVar6 = (char)((uint)((0xff - iVar15) * iVar14 * 2) >> 8) + (char)iVar15;
        cVar12 = (char)((uint)((0xff - iVar10) * iVar14 * 2) >> 8) + (char)iVar10;
      }
      pcVar22[1] = cVar6;
      pcVar22[2] = cVar12;
      *pcVar22 = cVar21;
      if (param_6 != 0) {
        *pcVar22 = (&DAT_00a52a60)[CONCAT11(cVar21,param_3[3])];
        pcVar22[1] = (&DAT_00a52a60)[CONCAT11(pcVar22[1],param_3[3])];
        pcVar22[2] = (&DAT_00a52a60)[CONCAT11(pcVar22[2],param_3[3])];
      }
      pcVar22[3] = param_3[3];
      param_3 = param_3 + 4;
      pcVar22 = pcVar22 + 4;
      param_5 = (float)((int)param_5 + -1);
    } while (param_5 != 0.0);
    param_3 = param_3 + iVar16;
    pcVar22 = pcVar22 + iVar23;
    local_20 = local_20 + -1;
    if (local_20 == 0) {
      FUN_00586b00();
      return 0;
    }
  } while( true );
}

