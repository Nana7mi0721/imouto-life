
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a2f60(short *param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,float *param_9,int param_10,int param_11,int param_12,
                 uint param_13,int param_14,int param_15,int param_16,undefined4 param_17,
                 undefined4 param_18,uint param_19,undefined4 *param_20,uint param_21)

{
  byte *pbVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  byte *pbVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  short *psVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  bool bVar16;
  float afStack_c0 [11];
  undefined4 uStack_94;
  int local_84;
  int local_80;
  uint local_7c;
  uint local_78;
  int local_74;
  int local_70;
  undefined4 local_6c;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  short *local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined1 *local_44;
  uint local_40;
  short *local_3c;
  int local_38;
  float *local_34;
  int local_30;
  int local_2c;
  uint local_28;
  int *local_24;
  uint local_20;
  float *local_1c;
  float *local_18;
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  local_50 = *(int *)(param_2 + 0x20);
  local_14 = (param_6 != 0) + 1;
  local_40 = (uint)(param_1 == (short *)0x0);
  local_2c = 1 << ((byte)param_18 & 0x1f);
  local_28 = 1;
  local_8 = local_2c;
  if (param_10 == 0) {
    local_8 = 1;
  }
  local_3c = (short *)(local_50 + param_3 * 2);
  iVar12 = *(short *)(local_50 + -2 + *(int *)(param_2 + 8) * 2) * local_2c;
  local_30 = *local_3c * local_2c;
  iVar15 = iVar12 - local_30;
  iVar4 = iVar15 * local_14;
  uStack_94 = 0x7a2fe6;
  local_18 = afStack_c0 + (0xc - iVar4);
  local_10 = 0;
  local_20 = param_3;
  local_34 = afStack_c0 + ((iVar15 + 0xc) - iVar4);
  local_64 = param_8;
  local_c = param_5 + iVar12 * 4;
  local_78 = param_13;
  local_74 = param_11;
  local_6c = param_17;
  local_84 = (int)param_1;
  local_5c = param_21;
  local_80 = param_2;
  local_60 = *param_20;
  if (param_4 <= (int)param_3) {
    *param_20 = local_60;
    return;
  }
  local_48 = param_19 + -1;
  local_38 = param_19 - param_3;
  local_24 = (int *)((int)param_9 + param_3 * 4);
  local_44 = (undefined1 *)(local_14 * param_3 + param_7);
  local_4c = param_14 - (int)param_9;
  param_1 = local_3c;
  do {
    uVar14 = local_20;
    iVar12 = local_2c;
    bVar16 = local_20 != param_4 - 1U;
    local_7c = local_20;
    iVar15 = *param_1 * local_2c * 4;
    local_1c = (float *)(param_5 + iVar15);
    param_21 = 0xffffffff;
    if (param_6 == 0) {
      param_9 = (float *)0x0;
    }
    else {
      param_9 = (float *)(iVar15 + param_6);
    }
    iVar15 = ((int)param_1[1] - (int)*param_1) * local_2c;
    afStack_c0[0xb - iVar4] = (float)param_17;
    afStack_c0[10 - iVar4] = 1.1221448e-38;
    local_58 = FUN_007a2340();
    if (uVar14 != param_3) {
      param_16 = param_16 - local_58;
    }
    iVar7 = param_15 - local_58;
    local_68 = iVar7 + -1;
    if (local_48 < (int)uVar14) {
LAB_007a3153:
      param_8 = 0;
    }
    else {
      iVar13 = local_38;
      if (3 < local_38) {
        iVar13 = 3;
      }
      param_8 = param_16 / iVar13 + *local_24;
      iVar13 = iVar7;
      if (param_8 <= iVar7) {
        iVar13 = param_8;
      }
      if (iVar13 < 0x4000) {
        iVar13 = iVar7;
        if (param_8 <= iVar7) {
          iVar13 = param_8;
        }
        if (iVar13 < 0) goto LAB_007a3153;
      }
      iVar13 = iVar7;
      if (param_8 <= iVar7) {
        iVar13 = param_8;
      }
      if (iVar13 < 0x4000) {
        if (iVar7 < param_8) {
          param_8 = iVar7;
        }
      }
      else {
        param_8 = 0x3fff;
      }
    }
    if (((local_40 != 0) && (*local_3c * iVar12 <= *param_1 * iVar12 - iVar15)) &&
       ((local_28 != 0 || (local_10 == 0)))) {
      local_10 = uVar14;
    }
    local_70 = *(int *)(local_4c + (int)local_24);
    if (*(int *)(param_2 + 0xc) <= (int)uVar14) {
      local_1c = local_18;
      if (param_6 != 0) {
        param_9 = local_18;
      }
      local_c = 0;
    }
    if (uVar14 == param_4 - 1U) {
      local_c = 0;
    }
    iVar7 = local_c;
    if ((local_10 == 0) || (((param_11 == 3 && (local_8 < 2)) && (-1 < local_70)))) {
      uVar14 = (1 << ((byte)local_8 & 0x1f)) - 1;
      param_19 = uVar14;
    }
    else {
      local_54 = (short *)(local_50 + local_10 * 2);
      iVar8 = *(short *)(local_50 + local_10 * 2) * iVar12;
      param_21 = (iVar8 - iVar15) - local_30;
      param_21 = ((int)param_21 < 0) - 1 & param_21;
      iVar13 = local_10 - 1;
      psVar9 = (short *)(local_50 + iVar13 * 2);
      if ((int)(param_21 + local_30) < *psVar9 * iVar12) {
        do {
          psVar9 = psVar9 + -1;
          iVar13 = iVar13 + -1;
        } while ((int)(param_21 + local_30) < *psVar9 * iVar12);
      }
      local_28 = local_10;
      iVar11 = iVar15 + param_21 + local_30;
      if (iVar8 < iVar11) {
        psVar9 = local_54;
        do {
          psVar9 = psVar9 + 1;
          local_28 = local_28 + 1;
        } while (*psVar9 * iVar12 < iVar11);
      }
      uVar14 = 0;
      param_19 = 0;
      pbVar5 = (byte *)(iVar13 * local_14 + param_7);
      do {
        param_19 = param_19 | *pbVar5;
        pbVar1 = pbVar5 + local_14 + -1;
        pbVar5 = pbVar5 + local_14;
        uVar14 = uVar14 | *pbVar1;
        iVar13 = iVar13 + 1;
      } while (iVar13 < (int)local_28);
      iVar12 = local_2c;
    }
    if (param_12 == 0) {
LAB_007a3314:
      if (param_9 == (float *)0x0) {
        if (bVar16) {
          pfVar10 = local_18 + (*param_1 * iVar12 - local_30);
        }
        else {
          pfVar10 = (float *)0x0;
        }
        if (param_21 == 0xffffffff) {
          pfVar6 = (float *)0x0;
        }
        else {
          pfVar6 = local_18 + param_21;
        }
        afStack_c0[0xb - iVar4] = (float)(uVar14 | param_19);
        afStack_c0[10 - iVar4] = (float)iVar7;
        iVar12 = local_8;
        afStack_c0[9 - iVar4] = 1.0;
        afStack_c0[8 - iVar4] = (float)pfVar10;
        afStack_c0[7 - iVar4] = (float)param_18;
        afStack_c0[6 - iVar4] = (float)pfVar6;
        afStack_c0[5 - iVar4] = (float)iVar12;
        pfVar10 = local_1c;
        afStack_c0[4 - iVar4] = (float)param_8;
        afStack_c0[3 - iVar4] = (float)iVar15;
        afStack_c0[2 - iVar4] = (float)pfVar10;
        afStack_c0[1 - iVar4] = (float)&local_84;
        afStack_c0[-iVar4] = 1.1222771e-38;
        uVar3 = FUN_007a3510();
      }
      else {
        if (bVar16) {
          pfVar10 = local_18 + (*param_1 * iVar12 - local_30);
        }
        else {
          pfVar10 = (float *)0x0;
        }
        if (param_21 == 0xffffffff) {
          pfVar6 = (float *)0x0;
        }
        else {
          pfVar6 = local_18 + param_21;
        }
        afStack_c0[0xb - iVar4] = (float)(uVar14 | param_19);
        afStack_c0[10 - iVar4] = (float)iVar7;
        iVar12 = local_8;
        afStack_c0[9 - iVar4] = (float)pfVar10;
        afStack_c0[8 - iVar4] = (float)param_18;
        afStack_c0[7 - iVar4] = (float)pfVar6;
        afStack_c0[6 - iVar4] = (float)iVar12;
        afStack_c0[5 - iVar4] = (float)param_8;
        pfVar10 = local_1c;
        afStack_c0[4 - iVar4] = (float)iVar15;
        afStack_c0[3 - iVar4] = (float)param_9;
        afStack_c0[2 - iVar4] = (float)pfVar10;
        afStack_c0[1 - iVar4] = (float)&local_84;
        afStack_c0[-iVar4] = 1.1222656e-38;
        uVar3 = FUN_007a46e0();
      }
      uVar2 = uVar3;
    }
    else {
      if (local_20 == param_13) {
        param_12 = 0;
        if (local_40 != 0) {
          local_54 = (short *)0x0;
          if (0 < *param_1 * iVar12 - local_30) {
            iVar13 = 0;
            pfVar10 = local_18;
            while( true ) {
              iVar13 = iVar13 + 1;
              *pfVar10 = (*(float *)(((int)local_34 - (int)local_18) + (int)pfVar10) + *pfVar10) *
                         _DAT_007d589c;
              local_28 = (int)local_34 - (int)local_18;
              if (*param_1 * iVar12 - local_30 <= iVar13) break;
              pfVar10 = pfVar10 + 1;
            }
          }
        }
        goto LAB_007a3314;
      }
      if (bVar16) {
        pfVar10 = local_18 + (*param_1 * iVar12 - local_30);
      }
      else {
        pfVar10 = (float *)0x0;
      }
      if (param_21 == 0xffffffff) {
        pfVar6 = (float *)0x0;
      }
      else {
        pfVar6 = local_18 + param_21;
      }
      afStack_c0[0xb - iVar4] = (float)param_19;
      iVar12 = local_8;
      afStack_c0[10 - iVar4] = (float)iVar7;
      afStack_c0[9 - iVar4] = 1.0;
      afStack_c0[8 - iVar4] = (float)pfVar10;
      afStack_c0[7 - iVar4] = (float)param_18;
      pfVar10 = local_1c;
      afStack_c0[6 - iVar4] = (float)pfVar6;
      afStack_c0[5 - iVar4] = (float)iVar12;
      afStack_c0[4 - iVar4] = (float)(param_8 / 2);
      afStack_c0[3 - iVar4] = (float)iVar15;
      afStack_c0[2 - iVar4] = (float)pfVar10;
      afStack_c0[1 - iVar4] = (float)&local_84;
      afStack_c0[-iVar4] = 1.1222418e-38;
      uVar3 = FUN_007a3510();
      iVar12 = local_c;
      if (bVar16) {
        pfVar10 = local_34 + (*param_1 * local_2c - local_30);
      }
      else {
        pfVar10 = (float *)0x0;
      }
      if (param_21 == 0xffffffff) {
        pfVar6 = (float *)0x0;
      }
      else {
        pfVar6 = local_34 + param_21;
      }
      afStack_c0[0xb - iVar4] = (float)uVar14;
      afStack_c0[10 - iVar4] = (float)iVar12;
      iVar12 = local_8;
      afStack_c0[9 - iVar4] = 1.0;
      afStack_c0[8 - iVar4] = (float)pfVar10;
      afStack_c0[7 - iVar4] = (float)param_18;
      afStack_c0[6 - iVar4] = (float)pfVar6;
      afStack_c0[5 - iVar4] = (float)iVar12;
      afStack_c0[4 - iVar4] = (float)(param_8 / 2);
      afStack_c0[3 - iVar4] = (float)iVar15;
      afStack_c0[2 - iVar4] = (float)param_9;
      afStack_c0[1 - iVar4] = (float)&local_84;
      afStack_c0[-iVar4] = 1.1222545e-38;
      uVar2 = FUN_007a3510();
    }
    *local_44 = uVar3;
    local_44[local_14 + -1] = uVar2;
    param_16 = param_16 + *local_24 + local_58;
    local_28 = (uint)(iVar15 * 8 < param_8);
    local_44 = local_44 + local_14;
    local_20 = local_20 + 1;
    local_38 = local_38 + -1;
    param_1 = param_1 + 1;
    local_24 = local_24 + 1;
    if (param_4 <= (int)local_20) {
      *param_20 = local_60;
      return;
    }
  } while( true );
}

