
void FUN_007a3fe0(int *param_1,uint *param_2,undefined4 param_3,float *param_4,int param_5,
                 int *param_6,byte param_7,int param_8,uint param_9,int param_10,uint *param_11)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint local_14;
  
  uVar14 = 0;
  iVar9 = *param_1;
  iVar1 = param_1[6];
  iVar2 = param_1[2];
  iVar3 = param_1[1];
  iVar4 = param_1[8];
  iVar7 = param_1[3];
  local_14 = 0;
  iVar6 = (int)*(short *)(*(int *)(iVar3 + 0x38) + iVar2 * 2) + param_9 * 8;
  if ((param_10 == 0) || (iVar11 = 0x10, param_5 != 2)) {
    iVar11 = 4;
  }
  param_9 = FUN_007a4670(param_5,*param_6,(iVar6 >> 1) - iVar11,iVar6,param_10);
  if ((param_10 != 0) && (iVar7 <= iVar2)) {
    param_9 = 1;
  }
  if (iVar9 != 0) {
    uVar14 = FUN_007a6c10(param_3,param_4,param_10,param_5,param_1[10]);
  }
  iVar6 = FUN_007a2340(iVar1);
  if (param_9 == 1) {
    if (param_10 != 0) {
      if (iVar9 != 0) {
        local_14 = (uint)(0x2000 < (int)uVar14);
        if ((local_14 != 0) && (0 < param_5)) {
          pfVar8 = param_4;
          iVar7 = param_5;
          do {
            *pfVar8 = -*pfVar8;
            pfVar8 = pfVar8 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
        FUN_007a45b0(iVar3,param_3,param_4,iVar4,iVar2,param_5);
      }
      if ((*param_6 < 0x11) || (param_1[7] < 0x11)) {
        local_14 = 0;
      }
      else if (iVar9 == 0) {
        local_14 = FUN_007a2130(iVar1,2);
      }
      else {
        FUN_007a24d0(iVar1,local_14);
      }
      uVar14 = 0;
    }
    goto LAB_007a43d2;
  }
  if (iVar9 != 0) {
    uVar14 = (int)(param_9 * uVar14 + 0x2000) >> 0xe;
  }
  if ((param_10 == 0) || (param_5 < 3)) {
    if ((param_8 < 2) && (param_10 == 0)) {
      iVar13 = (int)param_9 >> 1;
      iVar7 = iVar13 + 1;
      iVar11 = iVar7 * iVar7;
      if (iVar9 != 0) {
        uVar10 = uVar14;
        if (iVar13 < (int)uVar14) {
          uVar10 = param_9 - uVar14;
        }
        if (iVar13 < (int)uVar14) {
          iVar13 = iVar11 - ((int)(((param_9 - uVar14) + 2) * ((param_9 - uVar14) + 1)) >> 1);
          iVar7 = uVar10 + 1 + iVar13;
        }
        else {
          iVar13 = (int)((uVar14 + 1) * uVar14) >> 1;
          iVar7 = uVar10 + 1 + iVar13;
        }
        goto LAB_007a4119;
      }
      iVar15 = FUN_007a2060(iVar1,iVar11);
      if (iVar15 < iVar7 * iVar13 >> 1) {
        iVar7 = FUN_007a7620(iVar15 * 8 + 1);
        uVar14 = iVar7 - 1U >> 1;
        iVar7 = (int)((uVar14 + 1) * uVar14) >> 1;
        FUN_007a20e0(iVar1,iVar7,uVar14 + 1 + iVar7,iVar11);
      }
      else {
        iVar7 = FUN_007a7620((iVar15 * 0x1fffffff + iVar11) * 8 + -7);
        uVar14 = (param_9 * 2 + 2) - iVar7 >> 1;
        iVar7 = (param_9 - uVar14) + 1;
        iVar13 = iVar11 - ((int)(((param_9 - uVar14) + 2) * iVar7) >> 1);
        FUN_007a20e0(iVar1,iVar13,iVar7 + iVar13,iVar11);
      }
    }
    else if (iVar9 == 0) {
      uVar14 = FUN_007a21c0(iVar1,param_9 + 1);
    }
    else {
      FUN_007a2540(iVar1,uVar14,param_9 + 1);
    }
  }
  else {
    iVar15 = (int)param_9 / 2;
    iVar13 = iVar15 * 3 + 3;
    iVar11 = iVar13 + iVar15;
    if (iVar9 == 0) {
      iVar7 = FUN_007a2060(iVar1,iVar11);
      if (iVar7 < iVar13) {
        uVar14 = iVar7 / 3;
      }
      else {
        uVar14 = (iVar7 - iVar13) + 1 + iVar15;
      }
      if (iVar15 < (int)uVar14) {
        iVar7 = (iVar13 - iVar15) + uVar14;
        iVar13 = (iVar13 - iVar15) + -1 + uVar14;
      }
      else {
        iVar7 = uVar14 * 3 + 3;
        iVar13 = uVar14 * 3;
      }
      FUN_007a20e0(iVar1,iVar13,iVar7,iVar11);
    }
    else {
      if (iVar15 < (int)uVar14) {
        iVar7 = (iVar13 - iVar15) + uVar14;
        iVar13 = (iVar13 - iVar15) + -1 + uVar14;
      }
      else {
        iVar7 = uVar14 * 3 + 3;
        iVar13 = uVar14 * 3;
      }
LAB_007a4119:
      FUN_007a2390(iVar1,iVar13,iVar7,iVar11);
    }
  }
  uVar14 = (uVar14 << 0xe) / param_9;
  if ((iVar9 != 0) && (param_10 != 0)) {
    if (uVar14 == 0) {
      FUN_007a45b0(iVar3,param_3,param_4,iVar4,iVar2);
    }
    else {
      FUN_007a4630(param_3,param_4,param_5);
    }
  }
LAB_007a43d2:
  iVar9 = FUN_007a2340(iVar1);
  *param_6 = *param_6 - (iVar9 - iVar6);
  if (uVar14 == 0) {
    uVar12 = 0;
    uVar16 = 0x7fff;
    *param_11 = *param_11 & (1 << (param_7 & 0x1f)) - 1U;
    uVar10 = 0xffffc000;
  }
  else if (uVar14 == 0x4000) {
    uVar16 = 0;
    uVar12 = 0x7fff;
    *param_11 = *param_11 & (1 << (param_7 & 0x1f)) + -1 << (param_7 & 0x1f);
    uVar10 = 0x4000;
  }
  else {
    sVar5 = FUN_007a44b0(uVar14);
    uVar16 = (uint)sVar5;
    sVar5 = FUN_007a44b0(0x4000 - uVar14);
    uVar12 = (uint)sVar5;
    sVar5 = FUN_007a4510(uVar12,uVar16);
    uVar10 = (int)sVar5 * (int)(short)((short)param_5 * 0x80 + -0x80) + 0x4000 >> 0xf;
  }
  param_2[1] = uVar16;
  param_2[4] = uVar14;
  param_2[5] = iVar9 - iVar6;
  param_2[2] = uVar12;
  *param_2 = local_14;
  param_2[3] = uVar10;
  return;
}

