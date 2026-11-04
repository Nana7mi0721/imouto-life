
undefined4 FUN_0058ce60(int param_1,int param_2,char *param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  char cVar15;
  int iVar16;
  char cVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  byte *local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0xfe < param_2) {
    param_2 = 0xfe;
  }
  if ((int)param_3 < 1) {
    param_3 = (char *)0x1;
  }
  else if (0xff < (int)param_3) {
    param_3 = (char *)0xff;
  }
  if ((char *)param_2 == param_3) {
    param_3 = (char *)(param_2 + 1);
  }
  if (DAT_00a37dc8 == 1) {
    FUN_005db8c0(param_1,param_2,param_3,param_4);
    return 0;
  }
  iVar11 = (int)param_3 - param_2;
  iVar5 = FUN_00586970(param_1,1);
  if (iVar5 < 0) {
    return 0xffffffff;
  }
  iVar12 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20);
  local_14 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24);
  local_28 = *(byte **)(param_1 + 0x48c);
  param_3 = *(char **)(param_1 + 0xd0c);
  iVar5 = *(int *)(param_1 + 0x488);
  iVar4 = *(int *)(param_1 + 0xd08);
  local_18 = iVar12;
  do {
    if (param_4 == 0) {
      bVar1 = local_28[2];
      bVar3 = local_28[1];
      bVar2 = *local_28;
    }
    else {
      bVar1 = local_28[3];
      bVar2 = (&DAT_00a62a60)[CONCAT11(*local_28,bVar1)];
      bVar3 = (&DAT_00a62a60)[CONCAT11(local_28[1],bVar1)];
      bVar1 = (&DAT_00a62a60)[CONCAT11(local_28[2],bVar1)];
    }
    local_20 = (uint)bVar3;
    local_24 = (uint)bVar1;
    uVar18 = (uint)bVar2;
    if (local_20 < local_24) {
      if (local_24 <= uVar18) goto LAB_0058cfce;
      uVar13 = local_24;
    }
    else {
      uVar13 = local_20;
      if (local_20 <= uVar18) {
LAB_0058cfce:
        uVar13 = uVar18;
      }
    }
    if (local_24 < local_20) {
      iVar19 = local_24 - uVar18;
      uVar6 = local_24;
    }
    else {
      iVar19 = local_20 - uVar18;
      uVar6 = local_20;
    }
    if (SBORROW4(uVar6,uVar18) == iVar19 < 0) {
      uVar6 = uVar18;
    }
    local_1c = uVar6 + uVar13;
    iVar19 = uVar13 - uVar6;
    uVar20 = local_1c >> 1;
    if (uVar13 == uVar6) {
      iVar14 = 0;
      local_1c = 0;
      iVar7 = 0xff;
      iVar16 = 0;
    }
    else {
      if (0x80 < uVar20) {
        local_1c = (0x200 - uVar6) - uVar13;
      }
      local_1c = (iVar19 * 0x100) / local_1c;
      iVar8 = (int)((uVar13 - uVar18) * 0x100) / iVar19;
      iVar9 = (int)((uVar13 - local_20) * 0x100) / iVar19;
      iVar19 = (int)((uVar13 - local_24) * 0x100) / iVar19;
      if (local_24 == uVar13) {
        iVar16 = iVar8 - iVar9;
        iVar7 = 0xff;
        if (iVar9 < iVar8) {
          iVar14 = 0;
        }
        else {
          iVar14 = -iVar16;
          iVar16 = 0;
        }
      }
      else if (local_20 == uVar13) {
        iVar14 = iVar19 - iVar8;
        iVar16 = 0xff;
        if (iVar8 < iVar19) goto LAB_0058d0a5;
        iVar7 = -iVar14;
        iVar14 = 0;
      }
      else {
        iVar7 = iVar9 - iVar19;
        iVar14 = 0xff;
        if (iVar19 < iVar9) {
          iVar16 = 0;
        }
        else {
          iVar16 = -iVar7;
LAB_0058d0a5:
          iVar7 = 0;
        }
      }
    }
    local_1c = 0x100 - local_1c;
    iVar14 = iVar14 + ((0x80 - iVar14) * local_1c >> 8);
    iVar16 = iVar16 + ((0x80 - iVar16) * local_1c >> 8);
    iVar7 = iVar7 + ((0x80 - iVar7) * local_1c >> 8);
    iVar19 = (int)((uVar20 - param_2) * (int)(0xff000 / (longlong)iVar11)) >> 0xc;
    if (iVar19 < 0) {
      iVar19 = 0;
LAB_0058d1e8:
      iVar19 = iVar19 * 2;
      cVar17 = (char)((uint)(iVar19 * iVar14) >> 8);
      cVar10 = (char)((uint)(iVar19 * iVar16) >> 8);
      cVar15 = (char)((uint)(iVar19 * iVar7) >> 8);
    }
    else {
      if (iVar19 < 0x100) {
        if (iVar19 < 0x81) goto LAB_0058d1e8;
      }
      else {
        iVar19 = 0xff;
      }
      iVar19 = iVar19 + -0x80;
      cVar17 = (char)((uint)((0xff - iVar14) * iVar19 * 2) >> 8) + (char)iVar14;
      cVar10 = (char)((uint)((0xff - iVar16) * iVar19 * 2) >> 8) + (char)iVar16;
      cVar15 = (char)((uint)((0xff - iVar7) * iVar19 * 2) >> 8) + (char)iVar7;
    }
    param_3[2] = cVar15;
    param_3[1] = cVar10;
    *param_3 = cVar17;
    if (param_4 != 0) {
      *param_3 = (&DAT_00a52a60)[CONCAT11(cVar17,local_28[3])];
      param_3[1] = (&DAT_00a52a60)[CONCAT11(param_3[1],local_28[3])];
      param_3[2] = (&DAT_00a52a60)[CONCAT11(param_3[2],local_28[3])];
    }
    param_3[3] = local_28[3];
    local_28 = local_28 + 4;
    param_3 = param_3 + 4;
    local_18 = local_18 + -1;
    if (local_18 == 0) {
      param_3 = param_3 + iVar4 + iVar12 * -4;
      local_28 = local_28 + iVar5 + iVar12 * -4;
      local_14 = local_14 + -1;
      if (local_14 == 0) {
        FUN_00586b00();
        return 0;
      }
      local_18 = iVar12;
    }
  } while( true );
}

