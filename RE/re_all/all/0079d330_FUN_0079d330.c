
undefined2 *
FUN_0079d330(undefined2 *param_1,int param_2,short *param_3,uint param_4,int param_5,int param_6,
            int param_7)

{
  int *piVar1;
  uint *puVar2;
  short *psVar3;
  short *psVar4;
  undefined2 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  if (param_4 == 0x12) {
    param_4 = 0;
    if (0 < param_6) {
      do {
        puVar2 = (uint *)(param_2 + ((int)param_4 >> 0x10) * 4);
        iVar8 = (int)((param_4 & 0xffff) * (int)(short)param_5) >> 0x10;
        psVar3 = param_3 + iVar8 * 9;
        iVar6 = (param_5 - iVar8) + -1;
        psVar4 = param_3 + iVar6 * 9;
        uVar7 = (((int)puVar2[10] >> 0x10) * (int)psVar4[7] +
                 ((int)((puVar2[7] & 0xffff) * (int)psVar3[7]) >> 0x10) +
                 ((int)((puVar2[8] & 0xffff) * (int)psVar3[8]) >> 0x10) +
                 ((int)((*puVar2 & 0xffff) * (int)*psVar3) >> 0x10) +
                 ((int)((puVar2[1] & 0xffff) * (int)psVar3[1]) >> 0x10) +
                 ((int)((puVar2[2] & 0xffff) * (int)psVar3[2]) >> 0x10) +
                 ((int)((puVar2[3] & 0xffff) * (int)psVar3[3]) >> 0x10) +
                 ((int)((puVar2[4] & 0xffff) * (int)psVar3[4]) >> 0x10) +
                 ((int)((puVar2[5] & 0xffff) * (int)psVar3[5]) >> 0x10) +
                 ((int)((puVar2[6] & 0xffff) * (int)param_3[iVar8 * 9 + 6]) >> 0x10) +
                 ((int)puVar2[7] >> 0x10) * (int)psVar3[7] +
                 ((int)puVar2[8] >> 0x10) * (int)psVar3[8] + ((int)*puVar2 >> 0x10) * (int)*psVar3 +
                 ((int)puVar2[1] >> 0x10) * (int)psVar3[1] +
                 ((int)puVar2[2] >> 0x10) * (int)psVar3[2] +
                 ((int)puVar2[3] >> 0x10) * (int)psVar3[3] +
                 ((int)puVar2[4] >> 0x10) * (int)psVar3[4] +
                 ((int)puVar2[5] >> 0x10) * (int)psVar3[5] +
                 ((int)puVar2[6] >> 0x10) * (int)param_3[iVar8 * 9 + 6] +
                 ((int)((puVar2[0x11] & 0xffff) * (int)*psVar4) >> 0x10) +
                 ((int)((puVar2[0x10] & 0xffff) * (int)psVar4[1]) >> 0x10) +
                 ((int)((puVar2[0xf] & 0xffff) * (int)psVar4[2]) >> 0x10) +
                 ((int)((puVar2[0xe] & 0xffff) * (int)psVar4[3]) >> 0x10) +
                 ((int)((puVar2[0xd] & 0xffff) * (int)param_3[iVar6 * 9 + 4]) >> 0x10) +
                 ((int)((puVar2[0xc] & 0xffff) * (int)psVar4[5]) >> 0x10) +
                 ((int)((puVar2[0xb] & 0xffff) * (int)psVar4[6]) >> 0x10) +
                 ((int)((puVar2[9] & 0xffff) * (int)psVar4[8]) >> 0x10) +
                 ((int)((puVar2[10] & 0xffff) * (int)psVar4[7]) >> 0x10) +
                 ((int)puVar2[0x11] >> 0x10) * (int)*psVar4 +
                 ((int)puVar2[0x10] >> 0x10) * (int)psVar4[1] +
                 ((int)puVar2[0xf] >> 0x10) * (int)psVar4[2] +
                 ((int)puVar2[0xe] >> 0x10) * (int)psVar4[3] +
                 ((int)puVar2[0xd] >> 0x10) * (int)param_3[iVar6 * 9 + 4] +
                 ((int)puVar2[0xc] >> 0x10) * (int)psVar4[5] +
                 ((int)puVar2[9] >> 0x10) * (int)psVar4[8] +
                 ((int)puVar2[0xb] >> 0x10) * (int)psVar4[6] >> 5) + 1;
        uVar9 = uVar7 & 0xfffffffe;
        if ((int)uVar9 < 0xffff) {
          if ((int)uVar9 < -0x10000) {
            uVar5 = 0x8000;
          }
          else {
            uVar5 = (undefined2)((int)uVar7 >> 1);
          }
        }
        else {
          uVar5 = 0x7fff;
        }
        *param_1 = uVar5;
        param_4 = param_4 + param_7;
        param_1 = param_1 + 1;
      } while ((int)param_4 < param_6);
      return param_1;
    }
  }
  else if (param_4 == 0x18) {
    param_4 = 0;
    if (0 < param_6) {
      do {
        iVar6 = (int)param_4 >> 0x10;
        piVar1 = (int *)(param_2 + iVar6 * 4);
        uVar7 = *(int *)(param_2 + 0x2c + iVar6 * 4) + piVar1[0xc];
        uVar9 = *(int *)(param_2 + 0x28 + iVar6 * 4) + piVar1[0xd];
        uVar9 = (((int)((*piVar1 + piVar1[0x17] & 0xffffU) * (int)*param_3) >> 0x10) +
                 ((int)((piVar1[0x16] + piVar1[1] & 0xffffU) * (int)param_3[1]) >> 0x10) +
                 ((int)((piVar1[0x15] + piVar1[2] & 0xffffU) * (int)param_3[2]) >> 0x10) +
                 ((int)((piVar1[0x14] + piVar1[3] & 0xffffU) * (int)param_3[3]) >> 0x10) +
                 ((int)((piVar1[0x13] + piVar1[4] & 0xffffU) * (int)param_3[4]) >> 0x10) +
                 ((int)((piVar1[0x12] + piVar1[5] & 0xffffU) * (int)param_3[5]) >> 0x10) +
                 ((int)((piVar1[0x11] + piVar1[6] & 0xffffU) * (int)param_3[6]) >> 0x10) +
                 ((int)((piVar1[0x10] + piVar1[7] & 0xffffU) * (int)param_3[7]) >> 0x10) +
                 ((int)((piVar1[0xf] + piVar1[8] & 0xffffU) * (int)param_3[8]) >> 0x10) +
                 ((int)((piVar1[9] + piVar1[0xe] & 0xffffU) * (int)param_3[9]) >> 0x10) +
                 ((int)((uVar9 & 0xffff) * (int)param_3[10]) >> 0x10) +
                 ((int)((uVar7 & 0xffff) * (int)param_3[0xb]) >> 0x10) +
                 (*piVar1 + piVar1[0x17] >> 0x10) * (int)*param_3 +
                 (piVar1[0x16] + piVar1[1] >> 0x10) * (int)param_3[1] +
                 (piVar1[0x15] + piVar1[2] >> 0x10) * (int)param_3[2] +
                 (piVar1[0x14] + piVar1[3] >> 0x10) * (int)param_3[3] +
                 (piVar1[0x13] + piVar1[4] >> 0x10) * (int)param_3[4] +
                 (piVar1[0x12] + piVar1[5] >> 0x10) * (int)param_3[5] +
                 (piVar1[0x11] + piVar1[6] >> 0x10) * (int)param_3[6] +
                 (piVar1[0x10] + piVar1[7] >> 0x10) * (int)param_3[7] +
                 (piVar1[0xf] + piVar1[8] >> 0x10) * (int)param_3[8] +
                 (piVar1[9] + piVar1[0xe] >> 0x10) * (int)param_3[9] +
                 ((int)uVar9 >> 0x10) * (int)param_3[10] + ((int)uVar7 >> 0x10) * (int)param_3[0xb]
                >> 5) + 1;
        uVar7 = uVar9 & 0xfffffffe;
        if ((int)uVar7 < 0xffff) {
          if ((int)uVar7 < -0x10000) {
            uVar5 = 0x8000;
          }
          else {
            uVar5 = (undefined2)((int)uVar9 >> 1);
          }
        }
        else {
          uVar5 = 0x7fff;
        }
        *param_1 = uVar5;
        param_4 = param_4 + param_7;
        param_1 = param_1 + 1;
      } while ((int)param_4 < param_6);
      return param_1;
    }
  }
  else if ((param_4 == 0x24) && (param_4 = 0, 0 < param_6)) {
    do {
      iVar6 = (int)param_4 >> 0x10;
      piVar1 = (int *)(param_2 + iVar6 * 4);
      uVar7 = *(int *)(param_2 + 0x44 + iVar6 * 4) + piVar1[0x12];
      uVar9 = *(int *)(param_2 + 0x40 + iVar6 * 4) + piVar1[0x13];
      uVar9 = (((int)((uVar7 & 0xffff) * (int)param_3[0x11]) >> 0x10) +
               ((int)((piVar1[0x23] + *piVar1 & 0xffffU) * (int)*param_3) >> 0x10) +
               ((int)((piVar1[0x22] + piVar1[1] & 0xffffU) * (int)param_3[1]) >> 0x10) +
               ((int)((piVar1[0x21] + piVar1[2] & 0xffffU) * (int)param_3[2]) >> 0x10) +
               ((int)((piVar1[0x20] + piVar1[3] & 0xffffU) * (int)param_3[3]) >> 0x10) +
               ((int)((piVar1[0x1f] + piVar1[4] & 0xffffU) * (int)param_3[4]) >> 0x10) +
               ((int)((piVar1[0x1e] + piVar1[5] & 0xffffU) * (int)param_3[5]) >> 0x10) +
               ((int)((piVar1[0x1d] + piVar1[6] & 0xffffU) * (int)param_3[6]) >> 0x10) +
               ((int)((piVar1[0x1c] + piVar1[7] & 0xffffU) * (int)param_3[7]) >> 0x10) +
               ((int)((piVar1[0x1b] + piVar1[8] & 0xffffU) * (int)param_3[8]) >> 0x10) +
               ((int)((piVar1[0x1a] + piVar1[9] & 0xffffU) * (int)param_3[9]) >> 0x10) +
               ((int)((piVar1[0x19] + piVar1[10] & 0xffffU) * (int)param_3[10]) >> 0x10) +
               ((int)((piVar1[0x18] + piVar1[0xb] & 0xffffU) * (int)param_3[0xb]) >> 0x10) +
               ((int)((piVar1[0x17] + piVar1[0xc] & 0xffffU) * (int)param_3[0xc]) >> 0x10) +
               ((int)((piVar1[0x16] + piVar1[0xd] & 0xffffU) * (int)param_3[0xd]) >> 0x10) +
               ((int)((piVar1[0x15] + piVar1[0xe] & 0xffffU) * (int)param_3[0xe]) >> 0x10) +
               ((int)((piVar1[0xf] + piVar1[0x14] & 0xffffU) * (int)param_3[0xf]) >> 0x10) +
               ((int)((uVar9 & 0xffff) * (int)param_3[0x10]) >> 0x10) +
               ((int)uVar7 >> 0x10) * (int)param_3[0x11] +
               (piVar1[0x23] + *piVar1 >> 0x10) * (int)*param_3 +
               (piVar1[0x22] + piVar1[1] >> 0x10) * (int)param_3[1] +
               (piVar1[0x21] + piVar1[2] >> 0x10) * (int)param_3[2] +
               (piVar1[0x20] + piVar1[3] >> 0x10) * (int)param_3[3] +
               (piVar1[0x1f] + piVar1[4] >> 0x10) * (int)param_3[4] +
               (piVar1[0x1e] + piVar1[5] >> 0x10) * (int)param_3[5] +
               (piVar1[0x1d] + piVar1[6] >> 0x10) * (int)param_3[6] +
               (piVar1[0x1c] + piVar1[7] >> 0x10) * (int)param_3[7] +
               (piVar1[0x1b] + piVar1[8] >> 0x10) * (int)param_3[8] +
               (piVar1[0x1a] + piVar1[9] >> 0x10) * (int)param_3[9] +
               (piVar1[0x19] + piVar1[10] >> 0x10) * (int)param_3[10] +
               (piVar1[0x18] + piVar1[0xb] >> 0x10) * (int)param_3[0xb] +
               (piVar1[0x17] + piVar1[0xc] >> 0x10) * (int)param_3[0xc] +
               (piVar1[0x16] + piVar1[0xd] >> 0x10) * (int)param_3[0xd] +
               (piVar1[0x15] + piVar1[0xe] >> 0x10) * (int)param_3[0xe] +
               (piVar1[0xf] + piVar1[0x14] >> 0x10) * (int)param_3[0xf] +
               ((int)uVar9 >> 0x10) * (int)param_3[0x10] >> 5) + 1;
      uVar7 = uVar9 & 0xfffffffe;
      if ((int)uVar7 < 0xffff) {
        if ((int)uVar7 < -0x10000) {
          uVar5 = 0x8000;
        }
        else {
          uVar5 = (undefined2)((int)uVar9 >> 1);
        }
      }
      else {
        uVar5 = 0x7fff;
      }
      *param_1 = uVar5;
      param_4 = param_4 + param_7;
      param_1 = param_1 + 1;
    } while ((int)param_4 < param_6);
    return param_1;
  }
  return param_1;
}

