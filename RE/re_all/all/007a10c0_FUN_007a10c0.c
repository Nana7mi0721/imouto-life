
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a10c0(int param_1,float *param_2,int *param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,int *param_7,int param_8,int param_9,int param_10,
                 undefined4 param_11,undefined4 param_12,undefined4 param_13)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  float *pfVar10;
  int iVar11;
  int aiStack_74 [12];
  float afStack_44 [6];
  undefined4 uStack_2c;
  int local_10;
  uint local_8;
  
  iVar4 = param_10;
  iVar1 = *(int *)(param_1 + 4);
  iVar7 = *(int *)(param_1 + 8);
  uVar3 = *(int *)(param_1 + 0x2c) << ((byte)param_10 & 0x1f);
  uStack_2c = 0x7a10f3;
  pfVar10 = afStack_44 + (7 - uVar3);
  iVar8 = 1 << ((byte)param_10 & 0x1f);
  if (param_9 == 0) {
    param_10 = 1;
    iVar4 = *(int *)(param_1 + 0x24) - iVar4;
    local_8 = uVar3;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x24);
    param_10 = iVar8;
    local_8 = *(uint *)(param_1 + 0x2c);
  }
  if (param_8 == 2) {
    if (param_7 == (int *)0x1) {
      afStack_44[6 - uVar3] = (float)param_12;
      afStack_44[5 - uVar3] = (float)param_11;
      afStack_44[4 - uVar3] = (float)iVar8;
      afStack_44[3 - uVar3] = (float)param_6;
      afStack_44[2 - uVar3] = (float)param_5;
      afStack_44[1 - uVar3] = (float)param_4;
      afStack_44[-uVar3] = (float)(afStack_44 + (7 - uVar3));
      aiStack_74[0xb - uVar3] = (int)param_2;
      aiStack_74[10 - uVar3] = param_1;
      aiStack_74[9 - uVar3] = 0x7a1162;
      FUN_007a2af0();
      param_2 = (float *)(param_3[1] + (iVar1 / 2) * 4);
      pfVar10 = afStack_44 + (7 - uVar3);
      puVar9 = param_2;
      for (uVar6 = uVar3 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar9 = *pfVar10;
        pfVar10 = pfVar10 + 1;
        puVar9 = puVar9 + 1;
      }
      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined1 *)puVar9 = *(undefined1 *)pfVar10;
        pfVar10 = (float *)((int)pfVar10 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      if (param_10 < 1) {
        return;
      }
      iVar7 = 0;
      param_4 = param_10;
      do {
        afStack_44[6 - uVar3] = (float)param_13;
        uVar2 = *(undefined4 *)(param_1 + 0x3c);
        afStack_44[5 - uVar3] = (float)param_10;
        afStack_44[4 - uVar3] = (float)iVar4;
        afStack_44[3 - uVar3] = (float)iVar1;
        afStack_44[2 - uVar3] = (float)uVar2;
        afStack_44[1 - uVar3] = (float)(iVar7 + *param_3);
        afStack_44[-uVar3] = (float)param_2;
        aiStack_74[0xb - uVar3] = param_1 + 0x40;
        aiStack_74[10 - uVar3] = 0x7a11d1;
        FUN_007a59a0();
        iVar7 = iVar7 + local_8 * 4;
        param_2 = param_2 + 1;
        param_4 = param_4 + -1;
      } while (param_4 != 0);
      if (param_10 < 1) {
        return;
      }
      iVar7 = 0;
      param_4 = param_10;
      param_2 = afStack_44 + (7 - uVar3);
      do {
        afStack_44[6 - uVar3] = (float)param_13;
        uVar2 = *(undefined4 *)(param_1 + 0x3c);
        afStack_44[5 - uVar3] = (float)param_10;
        afStack_44[4 - uVar3] = (float)iVar4;
        afStack_44[3 - uVar3] = (float)iVar1;
        afStack_44[2 - uVar3] = (float)uVar2;
        afStack_44[1 - uVar3] = (float)(iVar7 + param_3[1]);
        afStack_44[-uVar3] = (float)param_2;
        aiStack_74[0xb - uVar3] = param_1 + 0x40;
        aiStack_74[10 - uVar3] = 0x7a1234;
        FUN_007a59a0();
        iVar7 = iVar7 + local_8 * 4;
        param_2 = (float *)((int)param_2 + 4);
        param_4 = param_4 + -1;
      } while (param_4 != 0);
      return;
    }
  }
  else if ((param_8 == 1) && (param_7 == (int *)0x2)) {
    iVar11 = *param_3;
    afStack_44[6 - uVar3] = (float)param_12;
    iVar11 = iVar11 + (iVar1 / 2) * 4;
    afStack_44[5 - uVar3] = (float)param_11;
    afStack_44[4 - uVar3] = (float)iVar8;
    afStack_44[3 - uVar3] = (float)param_6;
    afStack_44[2 - uVar3] = (float)param_5;
    afStack_44[1 - uVar3] = (float)param_4;
    afStack_44[-uVar3] = (float)(afStack_44 + (7 - uVar3));
    aiStack_74[0xb - uVar3] = (int)param_2;
    aiStack_74[10 - uVar3] = param_1;
    aiStack_74[9 - uVar3] = 0x7a129d;
    FUN_007a2af0();
    aiStack_74[9 - uVar3] = param_12;
    aiStack_74[8 - uVar3] = param_11;
    aiStack_74[7 - uVar3] = iVar8;
    aiStack_74[6 - uVar3] = param_6;
    aiStack_74[5 - uVar3] = param_5;
    aiStack_74[4 - uVar3] = param_4 + iVar7 * 4;
    aiStack_74[3 - uVar3] = iVar11;
    aiStack_74[2 - uVar3] = uVar3 * 4 + (int)param_2;
    aiStack_74[1 - uVar3] = param_1;
    aiStack_74[-uVar3] = 0x7a12cb;
    FUN_007a2af0();
    if (0 < (int)uVar3) {
      pfVar5 = afStack_44 + (7 - uVar3);
      uVar6 = uVar3;
      do {
        uVar6 = uVar6 - 1;
        *pfVar5 = (*(float *)((iVar11 - (int)(afStack_44 + (7 - uVar3))) + (int)pfVar5) + *pfVar5) *
                  _DAT_007d589c;
        pfVar5 = pfVar5 + 1;
      } while (uVar6 != 0);
    }
    if (param_10 < 1) {
      return;
    }
    iVar7 = 0;
    param_2 = (float *)param_10;
    do {
      afStack_44[6 - uVar3] = (float)param_13;
      uVar2 = *(undefined4 *)(param_1 + 0x3c);
      afStack_44[5 - uVar3] = (float)param_10;
      afStack_44[4 - uVar3] = (float)iVar4;
      afStack_44[3 - uVar3] = (float)iVar1;
      afStack_44[2 - uVar3] = (float)uVar2;
      afStack_44[1 - uVar3] = (float)(iVar7 + *param_3);
      afStack_44[-uVar3] = (float)pfVar10;
      aiStack_74[0xb - uVar3] = param_1 + 0x40;
      aiStack_74[10 - uVar3] = 0x7a1338;
      FUN_007a59a0();
      iVar7 = iVar7 + local_8 * 4;
      pfVar10 = (float *)((int)pfVar10 + 4);
      param_2 = (float *)((int)param_2 + -1);
    } while (param_2 != (float *)0x0);
    return;
  }
  param_7 = param_3;
  local_10 = 0;
  param_3 = (int *)param_4;
  do {
    pfVar10 = afStack_44 + (7 - uVar3);
    afStack_44[6 - uVar3] = (float)param_12;
    afStack_44[5 - uVar3] = (float)param_11;
    afStack_44[4 - uVar3] = (float)iVar8;
    afStack_44[3 - uVar3] = (float)param_6;
    afStack_44[2 - uVar3] = (float)param_5;
    afStack_44[1 - uVar3] = (float)param_3;
    afStack_44[-uVar3] = (float)pfVar10;
    aiStack_74[0xb - uVar3] = (int)param_2;
    aiStack_74[10 - uVar3] = param_1;
    aiStack_74[9 - uVar3] = 0x7a139c;
    FUN_007a2af0();
    if (0 < param_10) {
      iVar11 = 0;
      param_4 = param_10;
      do {
        afStack_44[6 - uVar3] = (float)param_13;
        afStack_44[5 - uVar3] = (float)param_10;
        uVar2 = *(undefined4 *)(param_1 + 0x3c);
        afStack_44[4 - uVar3] = (float)iVar4;
        afStack_44[3 - uVar3] = (float)iVar1;
        afStack_44[2 - uVar3] = (float)uVar2;
        afStack_44[1 - uVar3] = (float)(iVar11 + *param_7);
        afStack_44[-uVar3] = (float)pfVar10;
        aiStack_74[0xb - uVar3] = param_1 + 0x40;
        aiStack_74[10 - uVar3] = 0x7a13d1;
        FUN_007a59a0();
        pfVar10 = pfVar10 + 1;
        iVar11 = iVar11 + local_8 * 4;
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
    param_3 = (int *)((int)param_3 + iVar7 * 4);
    local_10 = local_10 + 1;
    param_2 = (float *)((int)param_2 + uVar3 * 4);
    param_7 = param_7 + 1;
  } while (local_10 < param_8);
  return;
}

