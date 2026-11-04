
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00549b20(int param_1,int param_2,undefined4 *param_3,int param_4,int param_5,
                 undefined4 *param_6,int param_7,int param_8,ulonglong *param_9,uint param_10,
                 int param_11,int *param_12,float *param_13,int param_14,float param_15,int param_16
                 ,int param_17,int param_18,int param_19,int param_20)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  ulonglong uVar6;
  int *piVar7;
  undefined1 uVar8;
  ushort uVar9;
  undefined2 uVar10;
  uint uVar11;
  undefined1 *puVar12;
  uint *puVar13;
  byte bVar14;
  int iVar15;
  undefined4 *puVar16;
  byte *pbVar17;
  byte *pbVar18;
  int iVar19;
  undefined4 *puVar20;
  byte bVar21;
  char cVar22;
  uint uVar23;
  ushort *puVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  undefined4 *puVar28;
  byte *pbVar29;
  byte *pbVar30;
  uint3 *puVar31;
  float *pfVar32;
  ulonglong *puVar33;
  float fVar34;
  undefined4 *puVar35;
  float *pfVar36;
  uint uVar37;
  int iVar38;
  uint *puVar39;
  bool bVar40;
  float10 fVar41;
  uint auStack_e3c [16];
  uint auStack_dfc [16];
  uint auStack_dbc [16];
  uint auStack_d7c [16];
  undefined4 local_d3c;
  byte local_d38;
  undefined1 local_d37;
  char local_d34;
  byte local_d30;
  uint *local_d2c;
  uint auStack_d14 [256];
  undefined4 local_914;
  byte local_910;
  char local_90f;
  char local_90c;
  char cStack_90b;
  char cStack_90a;
  char cStack_909;
  byte local_908;
  byte local_907;
  byte local_906;
  byte local_905;
  uint local_904;
  uint *local_900;
  uint local_8fc;
  uint *local_8f8;
  undefined4 uStack_8ec;
  undefined4 local_4ec;
  byte local_4e8;
  char local_4e7;
  char local_4e4;
  char local_4e3;
  char local_4e2;
  char local_4e1;
  byte local_4e0;
  byte local_4df;
  byte local_4de;
  byte local_4dd;
  uint local_4dc;
  uint *local_4d8;
  uint local_4d4;
  uint *local_4d0;
  uint local_4cc;
  uint local_c4;
  uint local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  uint local_b0;
  int local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint *local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  int local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint *local_60;
  float *local_5c;
  uint local_58;
  ushort *local_54;
  float local_50;
  uint *local_4c;
  uint local_48;
  float local_44;
  uint local_40;
  uint local_3c;
  ulonglong *local_38;
  uint local_34;
  float local_30;
  float local_2c;
  uint local_28;
  int local_24;
  byte local_1e;
  byte local_1d;
  uint *local_1c;
  byte local_15;
  float *local_14;
  undefined1 local_e;
  char local_d;
  uint local_c;
  int local_8;
  
  piVar7 = param_12;
  puVar16 = param_6;
  puVar28 = param_6;
  puVar35 = &local_914;
  for (iVar15 = 0x10a; iVar15 != 0; iVar15 = iVar15 + -1) {
    *puVar35 = *puVar28;
    puVar28 = puVar28 + 1;
    puVar35 = puVar35 + 1;
  }
  puVar28 = param_3;
  puVar35 = &local_4ec;
  for (iVar15 = 0x10a; iVar15 != 0; iVar15 = iVar15 + -1) {
    *puVar35 = *puVar28;
    puVar28 = puVar28 + 1;
    puVar35 = puVar35 + 1;
  }
  if (param_9 == (ulonglong *)0x0) {
    FUN_0056d380(&local_d3c,0,0x428);
  }
  else {
    puVar28 = &local_d3c;
    for (iVar15 = 0x10a; iVar15 != 0; iVar15 = iVar15 + -1) {
      *puVar28 = *(undefined4 *)param_9;
      param_9 = (ulonglong *)((int)param_9 + 4);
      puVar28 = puVar28 + 1;
    }
  }
  if ((local_914._3_1_ == '\0') && (local_4ec._3_1_ == '\0')) {
    local_14 = (float *)0x0;
  }
  else {
    local_14 = (float *)0x1;
  }
  if ((local_4e1 == '\0') || ((param_7 == 0 && (cStack_909 == '\0')))) {
    bVar40 = false;
    bVar5 = false;
  }
  else {
    bVar40 = true;
    bVar5 = true;
  }
  if (((local_4e1 == '\0') || (param_7 == 0)) || (cStack_909 != '\0')) {
    local_24 = 0;
  }
  else {
    local_24 = 1;
  }
  if (((bVar40) || (local_4e1 == '\0')) || (param_18 == 1)) {
    param_14 = 0;
  }
  if (param_13 != (float *)0x0) {
    param_19 = 0;
  }
  param_9 = (ulonglong *)*param_12;
  iVar15 = param_12[1];
  local_c = param_12[2] - (int)param_9;
  local_8 = param_12[3] - iVar15;
  if (local_c == 0) {
    return 0xffffffff;
  }
  if (param_12[3] - iVar15 == 0) {
    return 0xffffffff;
  }
  if (((local_914._3_1_ == '\0') && (local_914._2_1_ == 0x10)) ||
     ((local_4ec._3_1_ == '\0' && (local_4ec._2_1_ == 0x10)))) {
    if (((((param_14 == 0) && (local_24 == 0)) && (param_17 == 0)) &&
        ((param_18 == 0 && (local_4ec._3_1_ == local_914._3_1_)))) &&
       ((local_4ec._2_1_ == local_914._2_1_ &&
        ((local_4ec._1_1_ == local_914._1_1_ && (local_4e8 == local_910)))))) {
      uVar11 = local_4e8 * local_c;
      puVar16 = (undefined4 *)(iVar15 * param_5 + (uint)local_910 * (int)param_9 + param_4);
      puVar28 = (undefined4 *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
      do {
        uVar26 = uVar11 >> 2;
        do {
          *puVar28 = *puVar16;
          puVar28 = puVar28 + 1;
          puVar16 = puVar16 + 1;
          uVar26 = uVar26 - 1;
        } while (uVar26 != 0);
        puVar28 = (undefined4 *)((int)puVar28 + (param_2 - uVar11));
        puVar16 = (undefined4 *)((int)puVar16 + (param_5 - uVar11));
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
  }
  else {
    if (local_14 == (float *)0x0) {
      if (*(char *)((int)param_3 + 5) == '\x04') {
        if (*(char *)((int)param_6 + 5) == '\b') {
          uVar11 = param_10 & 0x80000001;
          bVar40 = uVar11 == 0;
          if ((int)uVar11 < 0) {
            bVar40 = (uVar11 - 1 | 0xfffffffe) == 0xffffffff;
          }
          if (bVar40) {
            pbVar17 = (byte *)((int)param_9 + param_4 + iVar15 * param_5);
            pbVar29 = (byte *)((int)param_10 / 2 + param_11 * param_2 + param_1);
            do {
              iVar15 = (int)local_c / 2;
              do {
                pbVar18 = pbVar17;
                pbVar30 = pbVar29 + 1;
                *pbVar29 = pbVar18[1] << 4 | *pbVar18;
                pbVar17 = pbVar18 + 2;
                iVar15 = iVar15 + -1;
                pbVar29 = pbVar30;
              } while (iVar15 != 0);
              if ((int)local_c % 2 != 0) {
                *pbVar30 = *pbVar17;
                pbVar17 = pbVar18 + 3;
              }
              pbVar17 = pbVar17 + (param_5 - local_c);
              pbVar29 = pbVar30 + (param_2 - (int)local_c / 2);
              local_8 = local_8 + -1;
            } while (local_8 != 0);
            return 0;
          }
        }
      }
      else {
        if ((((param_20 != 0) && (*(char *)((int)param_3 + 5) == '\b')) &&
            (*(char *)((int)param_6 + 5) == '\b')) &&
           ((param_13 == (float *)0x0 &&
            (iVar15 = FUN_0056d3d0(param_3 + 10,param_6 + 10,0x400), iVar15 != 0)))) {
          param_13 = (float *)0x0;
          if (0 < local_8) {
            param_12 = (int *)(param_11 * param_2 + param_10 + param_1);
            do {
              param_6 = param_12;
              pbVar17 = (byte *)((piVar7[1] + (int)param_13) * param_5 + *piVar7 + param_4);
              if (0 < (int)local_c) {
                param_9 = (ulonglong *)local_c;
                do {
                  iVar15 = (uint)*pbVar17 * 4;
                  uVar8 = FUN_005440f0(param_3,*(undefined1 *)((int)puVar16 + iVar15 + 0x2a),
                                       *(undefined1 *)((int)puVar16 + iVar15 + 0x29),
                                       *(undefined1 *)(puVar16 + *pbVar17 + 10),0);
                  *(undefined1 *)param_6 = uVar8;
                  param_6 = (undefined4 *)((int)param_6 + 1);
                  pbVar17 = pbVar17 + 1;
                  param_9 = (ulonglong *)((int)param_9 - 1);
                } while (param_9 != (ulonglong *)0x0);
              }
              param_12 = (int *)((int)param_12 + param_2);
              param_13 = (float *)((int)param_13 + 1);
            } while ((int)param_13 < local_8);
          }
          return 0;
        }
        if (((*(char *)((int)param_3 + 5) == '\b') &&
            (cVar22 = *(char *)((int)param_6 + 5), cVar22 != '\b')) &&
           ((param_18 == 0 && (param_13 == (float *)0x0)))) {
          if (cVar22 == '\x10') {
            param_13 = (float *)0x0;
            if (0 < local_8) {
              param_6 = (undefined4 *)(param_11 * param_2 + param_10 + param_1);
              do {
                puVar24 = (ushort *)((piVar7[1] + (int)param_13) * param_5 + param_4 + *piVar7 * 2);
                param_12 = param_6;
                if (0 < (int)local_c) {
                  param_9 = (ulonglong *)local_c;
                  do {
                    uVar11 = (uint)*puVar24;
                    uVar8 = FUN_005440f0(param_3,(uVar11 & puVar16[4]) >>
                                                 (*(byte *)(puVar16 + 3) & 0x1f),
                                         (uVar11 & puVar16[5]) >>
                                         (*(byte *)((int)puVar16 + 0xd) & 0x1f),
                                         (puVar16[6] & uVar11) >>
                                         (*(byte *)((int)puVar16 + 0xe) & 0x1f),
                                         (uVar11 & puVar16[7]) >>
                                         (*(byte *)((int)puVar16 + 0xf) & 0x1f));
                    *(undefined1 *)param_12 = uVar8;
                    param_12 = (int *)((int)param_12 + 1);
                    puVar24 = puVar24 + 1;
                    param_9 = (ulonglong *)((int)param_9 - 1);
                  } while (param_9 != (ulonglong *)0x0);
                }
                param_6 = (undefined4 *)((int)param_6 + param_2);
                param_13 = (float *)((int)param_13 + 1);
              } while ((int)param_13 < local_8);
            }
          }
          else if (cVar22 == '\x18') {
            param_13 = (float *)0x0;
            if (0 < local_8) {
              param_6 = (undefined4 *)(param_11 * param_2 + param_10 + param_1);
              do {
                puVar31 = (uint3 *)((piVar7[1] + (int)param_13) * param_5 + param_4 + *piVar7 * 2);
                param_12 = param_6;
                if (0 < (int)local_c) {
                  param_9 = (ulonglong *)local_c;
                  do {
                    uVar11 = (uint)*puVar31;
                    uVar8 = FUN_005440f0(param_3,(puVar16[4] & uVar11) >>
                                                 (*(byte *)(puVar16 + 3) & 0x1f),
                                         (uVar11 & puVar16[5]) >>
                                         (*(byte *)((int)puVar16 + 0xd) & 0x1f),
                                         (puVar16[6] & uVar11) >>
                                         (*(byte *)((int)puVar16 + 0xe) & 0x1f),
                                         (uVar11 & puVar16[7]) >>
                                         (*(byte *)((int)puVar16 + 0xf) & 0x1f));
                    *(undefined1 *)param_12 = uVar8;
                    param_12 = (int *)((int)param_12 + 1);
                    puVar31 = (uint3 *)((int)puVar31 + 3);
                    param_9 = (ulonglong *)((int)param_9 - 1);
                  } while (param_9 != (ulonglong *)0x0);
                }
                param_6 = (undefined4 *)((int)param_6 + param_2);
                param_13 = (float *)((int)param_13 + 1);
              } while ((int)param_13 < local_8);
              return 0;
            }
          }
          else if ((cVar22 == ' ') && (param_13 = (float *)0x0, 0 < local_8)) {
            param_6 = (undefined4 *)(param_11 * param_2 + param_10 + param_1);
            do {
              puVar13 = (uint *)((piVar7[1] + (int)param_13) * param_5 + param_4 + *piVar7 * 4);
              if (0 < (int)local_c) {
                param_9 = (ulonglong *)local_c;
                param_12 = param_6;
                do {
                  uVar11 = *puVar13;
                  uVar8 = FUN_005440f0(param_3,(uVar11 & puVar16[4]) >>
                                               (*(byte *)(puVar16 + 3) & 0x1f),
                                       (uVar11 & puVar16[5]) >>
                                       (*(byte *)((int)puVar16 + 0xd) & 0x1f),
                                       (puVar16[6] & uVar11) >>
                                       (*(byte *)((int)puVar16 + 0xe) & 0x1f),
                                       (uVar11 & puVar16[7]) >>
                                       (*(byte *)((int)puVar16 + 0xf) & 0x1f));
                  *(undefined1 *)param_12 = uVar8;
                  param_12 = (int *)((int)param_12 + 1);
                  puVar13 = puVar13 + 1;
                  param_9 = (ulonglong *)((int)param_9 - 1);
                } while (param_9 != (ulonglong *)0x0);
              }
              param_6 = (undefined4 *)((int)param_6 + param_2);
              param_13 = (float *)((int)param_13 + 1);
            } while ((int)param_13 < local_8);
            return 0;
          }
          return 0;
        }
        if ((((*(char *)((int)param_3 + 5) != '\b') || (param_17 != 0)) || (param_19 != 0)) ||
           ((param_18 != 0 || (param_13 != (float *)0x0)))) {
          if ((((param_14 == 0) && ((local_24 == 0 && (param_17 == 0)))) && (param_18 == 0)) &&
             ((((((local_4ec._1_1_ == 0 && (local_914._1_1_ == 0)) && (local_4e7 == local_90f)) &&
                ((local_4dc == local_904 && (local_4d8 == local_900)))) && (local_4d4 == local_8fc))
              && (local_4d0 == local_8f8)))) {
            uVar11 = (uint)local_4e8;
            iVar15 = uVar11 * local_c;
            if (param_13 != (float *)0x0) {
              puVar28 = (undefined4 *)
                        (param_11 * param_2 + ((param_10 - 1) + local_c) * uVar11 + param_1);
              iVar38 = param_5 - iVar15;
              puVar16 = (undefined4 *)
                        (param_12[1] * param_5 + (uint)local_910 * *param_12 + param_4);
              param_2 = param_2 + iVar15;
              if (local_4e7 == '\b') {
                do {
                  uVar11 = local_c;
                  do {
                    puVar35 = (undefined4 *)((int)puVar16 + 1);
                    *(undefined1 *)puVar28 = *(undefined1 *)puVar16;
                    puVar28 = (undefined4 *)((int)puVar28 + -1);
                    uVar11 = uVar11 - 1;
                    puVar16 = puVar35;
                  } while (uVar11 != 0);
                  puVar28 = (undefined4 *)((int)puVar28 + param_2);
                  puVar16 = (undefined4 *)((int)puVar35 + iVar38);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
              }
              else if (local_4e7 == '\x10') {
                do {
                  uVar11 = local_c;
                  do {
                    puVar35 = (undefined4 *)((int)puVar16 + 2);
                    *(undefined2 *)puVar28 = *(undefined2 *)puVar16;
                    puVar28 = (undefined4 *)((int)puVar28 + -2);
                    uVar11 = uVar11 - 1;
                    puVar16 = puVar35;
                  } while (uVar11 != 0);
                  puVar28 = (undefined4 *)((int)puVar28 + param_2);
                  puVar16 = (undefined4 *)((int)puVar35 + iVar38);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
              }
              else if (local_4e7 == '\x18') {
                do {
                  uVar11 = local_c;
                  do {
                    puVar1 = (undefined2 *)((int)puVar16 + 2);
                    *(undefined2 *)puVar28 = *(undefined2 *)puVar16;
                    puVar16 = (undefined4 *)((int)puVar16 + 3);
                    *(undefined1 *)((int)puVar28 + 2) = *(undefined1 *)puVar1;
                    puVar28 = (undefined4 *)((int)puVar28 + -3);
                    uVar11 = uVar11 - 1;
                  } while (uVar11 != 0);
                  puVar28 = (undefined4 *)((int)puVar28 + param_2);
                  puVar16 = (undefined4 *)((int)puVar16 + iVar38);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
              }
              else {
                do {
                  uVar11 = local_c;
                  do {
                    puVar35 = puVar16 + 1;
                    *puVar28 = *puVar16;
                    puVar28 = puVar28 + -1;
                    uVar11 = uVar11 - 1;
                    puVar16 = puVar35;
                  } while (uVar11 != 0);
                  puVar28 = (undefined4 *)((int)puVar28 + param_2);
                  puVar16 = (undefined4 *)((int)puVar35 + iVar38);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
              }
              return 0;
            }
            iVar38 = param_2 - iVar15;
            pfVar32 = (float *)(param_11 * param_2 + uVar11 * param_10 + param_1);
            pfVar36 = (float *)(param_12[1] * param_5 + (uint)local_910 * *param_12 + param_4);
            param_5 = param_5 - iVar15;
            if (param_19 != 1) {
              iVar27 = (int)(iVar15 + (iVar15 >> 0x1f & 3U)) >> 2;
              iVar15 = (iVar15 + iVar27 * -4) / (int)uVar11;
              if (local_4e7 == '\b') {
                do {
                  iVar19 = iVar27;
                  if (iVar27 != 0) {
                    for (; iVar19 != 0; iVar19 = iVar19 + -1) {
                      *pfVar32 = *pfVar36;
                      pfVar36 = pfVar36 + 1;
                      pfVar32 = pfVar32 + 1;
                    }
                  }
                  iVar19 = iVar15;
                  if (iVar15 != 0) {
                    for (; iVar19 != 0; iVar19 = iVar19 + -1) {
                      *(undefined1 *)pfVar32 = *(undefined1 *)pfVar36;
                      pfVar36 = (float *)((int)pfVar36 + 1);
                      pfVar32 = (float *)((int)pfVar32 + 1);
                    }
                  }
                  pfVar32 = (float *)((int)pfVar32 + iVar38);
                  pfVar36 = (float *)((int)pfVar36 + param_5);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
              }
              else if (local_4e7 == '\x10') {
                do {
                  iVar19 = iVar27;
                  if (iVar27 != 0) {
                    for (; iVar19 != 0; iVar19 = iVar19 + -1) {
                      *pfVar32 = *pfVar36;
                      pfVar36 = pfVar36 + 1;
                      pfVar32 = pfVar32 + 1;
                    }
                  }
                  iVar19 = iVar15;
                  if (iVar15 != 0) {
                    for (; iVar19 != 0; iVar19 = iVar19 + -1) {
                      *(undefined2 *)pfVar32 = *(undefined2 *)pfVar36;
                      pfVar36 = (float *)((int)pfVar36 + 2);
                      pfVar32 = (float *)((int)pfVar32 + 2);
                    }
                  }
                  pfVar32 = (float *)((int)pfVar32 + iVar38);
                  pfVar36 = (float *)((int)pfVar36 + param_5);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
              }
              else if (local_4e7 == '\x18') {
                do {
                  iVar25 = iVar27;
                  iVar19 = iVar15;
                  if (iVar27 != 0) {
                    for (; iVar25 != 0; iVar25 = iVar25 + -1) {
                      *pfVar32 = *pfVar36;
                      pfVar36 = pfVar36 + 1;
                      pfVar32 = pfVar32 + 1;
                    }
                  }
                  for (; iVar19 != 0; iVar19 = iVar19 + -1) {
                    puVar2 = (undefined1 *)((int)pfVar32 + 2);
                    puVar12 = (undefined1 *)((int)pfVar36 + 2);
                    *(undefined2 *)pfVar32 = *(undefined2 *)pfVar36;
                    pfVar32 = (float *)((int)pfVar32 + 3);
                    pfVar36 = (float *)((int)pfVar36 + 3);
                    *puVar2 = *puVar12;
                  }
                  pfVar32 = (float *)((int)pfVar32 + iVar38);
                  pfVar36 = (float *)((int)pfVar36 + param_5);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
              }
              else {
                do {
                  for (iVar15 = iVar27; iVar15 != 0; iVar15 = iVar15 + -1) {
                    *pfVar32 = *pfVar36;
                    pfVar36 = pfVar36 + 1;
                    pfVar32 = pfVar32 + 1;
                  }
                  pfVar32 = (float *)((int)pfVar32 + iVar38);
                  pfVar36 = (float *)((int)pfVar36 + param_5);
                  local_8 = local_8 + -1;
                } while (local_8 != 0);
              }
              return 0;
            }
            if (local_4e7 == '\b') {
              do {
                uVar11 = local_c;
                do {
                  if (*(char *)pfVar36 != SUB41(param_15,0)) {
                    *(char *)pfVar32 = *(char *)pfVar36;
                  }
                  pfVar36 = (float *)((int)pfVar36 + 1);
                  pfVar32 = (float *)((int)pfVar32 + 1);
                  uVar11 = uVar11 - 1;
                } while (uVar11 != 0);
                pfVar32 = (float *)((int)pfVar32 + iVar38);
                pfVar36 = (float *)((int)pfVar36 + param_5);
                local_8 = local_8 + -1;
              } while (local_8 != 0);
            }
            else if (local_4e7 == '\x10') {
              do {
                uVar11 = local_c;
                do {
                  if (*(short *)pfVar36 != SUB42(param_15,0)) {
                    *(short *)pfVar32 = *(short *)pfVar36;
                  }
                  pfVar36 = (float *)((int)pfVar36 + 2);
                  pfVar32 = (float *)((int)pfVar32 + 2);
                  uVar11 = uVar11 - 1;
                } while (uVar11 != 0);
                pfVar32 = (float *)((int)pfVar32 + iVar38);
                pfVar36 = (float *)((int)pfVar36 + param_5);
                local_8 = local_8 + -1;
              } while (local_8 != 0);
            }
            else if (local_4e7 == '\x18') {
              do {
                param_15 = (float)((uint)param_15 & 0xffffff);
                uVar11 = local_c;
                do {
                  uVar8 = *(undefined1 *)((int)pfVar36 + 2);
                  if ((float)(uint)*(uint3 *)pfVar36 != param_15) {
                    *(undefined2 *)pfVar32 = *(undefined2 *)pfVar36;
                    *(undefined1 *)((int)pfVar32 + 2) = uVar8;
                  }
                  pfVar36 = (float *)((int)pfVar36 + 3);
                  pfVar32 = (float *)((int)pfVar32 + 3);
                  uVar11 = uVar11 - 1;
                } while (uVar11 != 0);
                pfVar32 = (float *)((int)pfVar32 + iVar38);
                pfVar36 = (float *)((int)pfVar36 + param_5);
                local_8 = local_8 + -1;
              } while (local_8 != 0);
            }
            else {
              do {
                uVar11 = local_c;
                do {
                  if (*pfVar36 != param_15) {
                    *pfVar32 = *pfVar36;
                  }
                  pfVar36 = pfVar36 + 1;
                  pfVar32 = pfVar32 + 1;
                  uVar11 = uVar11 - 1;
                } while (uVar11 != 0);
                pfVar32 = (float *)((int)pfVar32 + iVar38);
                pfVar36 = (float *)((int)pfVar36 + param_5);
                local_8 = local_8 + -1;
              } while (local_8 != 0);
            }
            return 0;
          }
          if (param_19 == 1) {
            if (((((param_17 == 0) && (local_24 == 0)) &&
                 ((!bVar5 && (((param_18 == 0 && (param_14 == 0)) && (param_13 == (float *)0x0))))))
                && ((local_90f == ' ' && (local_4e7 == ' ')))) &&
               (((local_904 == 0xff0000 &&
                 (((local_900 == (uint *)0xff00 && (local_8fc == 0xff)) &&
                  ((local_8f8 == (uint *)0x0 &&
                   (((local_4dc == 0xff0000 && (local_4d8 == (uint *)0xff00)) && (local_4d4 == 0xff)
                    ))))))) && (local_4d0 == (uint *)0xff000000)))) {
              puVar39 = (uint *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
              puVar13 = (uint *)(param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
              if (local_8 != 0) {
                param_3 = (undefined4 *)local_8;
                do {
                  uVar11 = local_c;
                  do {
                    if ((*puVar13 & 0xffffff) != ((uint)param_15 & 0xffffff)) {
                      *puVar39 = *puVar13 | 0xff000000;
                    }
                    puVar39 = puVar39 + 1;
                    puVar13 = puVar13 + 1;
                    uVar11 = uVar11 - 1;
                  } while (uVar11 != 0);
                  puVar13 = (uint *)((int)puVar13 + (param_5 - local_910 * local_c));
                  puVar39 = (uint *)((int)puVar39 + (param_2 - local_4e8 * local_c));
                  param_3 = (undefined4 *)((int)param_3 + -1);
                } while (param_3 != (undefined4 *)0x0);
              }
              return 0;
            }
          }
          else {
            if ((((local_4e1 != '\0') && (param_14 == 1)) &&
                ((param_17 == 0 && ((param_18 == 0 && (local_4dc == local_904)))))) &&
               ((local_4d8 == local_900 && ((local_4d4 == local_8fc && (local_4e7 == local_90f))))))
            {
              uVar11 = FUN_005440f0(&local_4ec,param_15._2_1_,(uint)param_15 >> 8 & 0xff,
                                    (uint)param_15 & 0xff,0xff);
              if (param_13 == (float *)0x1) {
                uVar26 = (uint)local_4e8;
                iVar15 = uVar26 * local_c;
                iVar38 = ((param_10 - 1) + local_c) * uVar26;
                uVar26 = -uVar26;
              }
              else {
                uVar26 = (uint)local_4e8;
                iVar15 = -(uVar26 * local_c);
                iVar38 = uVar26 * param_10;
              }
              iVar15 = iVar15 + param_2;
              puVar13 = (uint *)(param_11 * param_2 + iVar38 + param_1);
              puVar39 = (uint *)(param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
              param_5 = param_5 - local_910 * local_c;
              switch(local_4e7) {
              case '\b':
                param_13 = (float *)0x0;
                if (0 < local_8) {
                  do {
                    if (0 < (int)local_c) {
                      uVar37 = local_c;
                      do {
                        bVar21 = (byte)*puVar39;
                        param_3._0_1_ = (byte)uVar11;
                        if ((byte)param_3 == bVar21) {
                          bVar21 = bVar21 & ~(byte)local_4d0;
                        }
                        else {
                          bVar21 = bVar21 | (byte)local_4d0;
                        }
                        *(byte *)puVar13 = bVar21;
                        puVar13 = (uint *)((int)puVar13 + uVar26);
                        puVar39 = (uint *)((int)puVar39 + (uint)local_910);
                        uVar37 = uVar37 - 1;
                      } while (uVar37 != 0);
                    }
                    puVar39 = (uint *)((int)puVar39 + param_5);
                    param_13 = (float *)((int)param_13 + 1);
                    puVar13 = (uint *)((int)puVar13 + uVar26);
                  } while ((int)param_13 < local_8);
                  return 0;
                }
                break;
              case '\x10':
                param_6 = (undefined4 *)0x0;
                if (0 < local_8) {
                  do {
                    uVar37 = local_c;
                    if (0 < (int)local_c) {
                      do {
                        uVar9 = (ushort)*puVar39;
                        param_3._0_2_ = (ushort)uVar11;
                        if ((ushort)param_3 == uVar9) {
                          uVar9 = uVar9 & ~(ushort)local_4d0;
                        }
                        else {
                          uVar9 = uVar9 | (ushort)local_4d0;
                        }
                        *(ushort *)puVar13 = uVar9;
                        puVar13 = (uint *)((int)puVar13 + uVar26);
                        puVar39 = (uint *)((int)puVar39 + (uint)local_910);
                        uVar37 = uVar37 - 1;
                      } while (uVar37 != 0);
                    }
                    puVar39 = (uint *)((int)puVar39 + param_5);
                    param_6 = (undefined4 *)((int)param_6 + 1);
                    puVar13 = (uint *)((int)puVar13 + iVar15);
                  } while ((int)param_6 < local_8);
                  return 0;
                }
                break;
              case '\x18':
                param_6 = (undefined4 *)0x0;
                if (0 < local_8) {
                  do {
                    uVar37 = local_c;
                    if (0 < (int)local_c) {
                      do {
                        uVar23 = (uint)(uint3)*puVar39;
                        if (uVar11 == uVar23) {
                          uVar23 = uVar23 & ~(uint)local_4d0;
                        }
                        else {
                          uVar23 = uVar23 | (uint)local_4d0;
                        }
                        *(ushort *)puVar13 = (ushort)uVar23;
                        *(byte *)((int)puVar13 + 2) = (byte)(uVar23 >> 0x10);
                        puVar13 = (uint *)((int)puVar13 + uVar26);
                        puVar39 = (uint *)((int)puVar39 + (uint)local_910);
                        uVar37 = uVar37 - 1;
                      } while (uVar37 != 0);
                    }
                    puVar39 = (uint *)((int)puVar39 + param_5);
                    param_6 = (undefined4 *)((int)param_6 + 1);
                    puVar13 = (uint *)((int)puVar13 + iVar15);
                  } while ((int)param_6 < local_8);
                  return 0;
                }
                break;
              case ' ':
                param_6 = (undefined4 *)0x0;
                if (0 < local_8) {
                  do {
                    uVar37 = local_c;
                    if (0 < (int)local_c) {
                      do {
                        uVar23 = *puVar39 | ~(local_4d4 | (uint)local_4d8 | local_4dc);
                        if (uVar11 == uVar23) {
                          uVar23 = uVar23 & ~(uint)local_4d0;
                        }
                        else {
                          uVar23 = uVar23 | (uint)local_4d0;
                        }
                        *puVar13 = uVar23;
                        puVar13 = (uint *)((int)puVar13 + uVar26);
                        puVar39 = (uint *)((int)puVar39 + (uint)local_910);
                        uVar37 = uVar37 - 1;
                      } while (uVar37 != 0);
                    }
                    puVar39 = (uint *)((int)puVar39 + param_5);
                    param_6 = (undefined4 *)((int)param_6 + 1);
                    puVar13 = (uint *)((int)puVar13 + iVar15);
                  } while ((int)param_6 < local_8);
                }
              }
              return 0;
            }
            if ((((param_16 == 0) && (param_17 == 0)) && (param_18 == 0)) &&
               ((param_13 == (float *)0x0 && (param_7 == 0)))) {
              if (param_14 == 0) {
                uVar11 = (int)local_c >> 0x1f;
                if (local_914._1_1_ == 1) {
                  if (local_914._2_1_ == 8) {
                    iVar15 = param_2 - local_4e8 * local_c;
                    param_9 = (ulonglong *)(param_5 - local_910 * local_c);
                    puVar16 = (undefined4 *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
                    puVar28 = (undefined4 *)
                              (param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
                    if (local_4ec._1_1_ == 1) {
                      if (local_4ec._2_1_ == 8) {
                        iVar27 = (int)(local_c + (uVar11 & 7)) >> 3;
                        iVar38 = local_c + iVar27 * -8;
                        do {
                          iVar19 = iVar38;
                          if (iVar27 != 0) {
                            iVar25 = iVar27;
                            do {
                              *puVar16 = *puVar28;
                              puVar16[1] = puVar28[1];
                              puVar16 = puVar16 + 2;
                              puVar28 = puVar28 + 2;
                              iVar25 = iVar25 + -1;
                            } while (iVar25 != 0);
                          }
                          for (; iVar19 != 0; iVar19 = iVar19 + -1) {
                            *(undefined1 *)puVar16 = *(undefined1 *)puVar28;
                            puVar16 = (undefined4 *)((int)puVar16 + 1);
                            puVar28 = (undefined4 *)((int)puVar28 + 1);
                          }
                          puVar28 = (undefined4 *)((int)puVar28 + (int)param_9);
                          puVar16 = (undefined4 *)((int)puVar16 + iVar15);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        return 0;
                      }
                    }
                    else if ((local_4ec._1_1_ == 2) && (local_4ec._2_1_ == 8)) {
                      iVar38 = (int)(local_c + (uVar11 & 7)) >> 3;
                      iVar27 = local_c + iVar38 * -8;
                      do {
                        iVar19 = iVar27;
                        if (iVar38 != 0) {
                          iVar25 = iVar38;
                          do {
                            *(undefined1 *)puVar16 = *(undefined1 *)puVar28;
                            *(undefined1 *)((int)puVar16 + 1) = *(undefined1 *)puVar28;
                            *(undefined1 *)((int)puVar16 + 2) = *(undefined1 *)((int)puVar28 + 1);
                            *(undefined1 *)((int)puVar16 + 3) = *(undefined1 *)((int)puVar28 + 1);
                            *(undefined1 *)(puVar16 + 1) = *(undefined1 *)((int)puVar28 + 2);
                            *(undefined1 *)((int)puVar16 + 5) = *(undefined1 *)((int)puVar28 + 2);
                            *(undefined1 *)((int)puVar16 + 6) = *(undefined1 *)((int)puVar28 + 3);
                            *(undefined1 *)((int)puVar16 + 7) = *(undefined1 *)((int)puVar28 + 3);
                            *(undefined1 *)(puVar16 + 2) = *(undefined1 *)(puVar28 + 1);
                            *(undefined1 *)((int)puVar16 + 9) = *(undefined1 *)(puVar28 + 1);
                            *(undefined1 *)((int)puVar16 + 10) = *(undefined1 *)((int)puVar28 + 5);
                            *(undefined1 *)((int)puVar16 + 0xb) = *(undefined1 *)((int)puVar28 + 5);
                            *(undefined1 *)(puVar16 + 3) = *(undefined1 *)((int)puVar28 + 6);
                            *(undefined1 *)((int)puVar16 + 0xd) = *(undefined1 *)((int)puVar28 + 6);
                            *(undefined1 *)((int)puVar16 + 0xe) = *(undefined1 *)((int)puVar28 + 7);
                            *(undefined1 *)((int)puVar16 + 0xf) = *(undefined1 *)((int)puVar28 + 7);
                            puVar16 = puVar16 + 4;
                            puVar28 = puVar28 + 2;
                            iVar25 = iVar25 + -1;
                          } while (iVar25 != 0);
                        }
                        for (; iVar19 != 0; iVar19 = iVar19 + -1) {
                          *(undefined1 *)puVar16 = *(undefined1 *)puVar28;
                          *(undefined1 *)((int)puVar16 + 1) = 0;
                          puVar16 = (undefined4 *)((int)puVar16 + 2);
                          puVar28 = (undefined4 *)((int)puVar28 + 1);
                        }
                        puVar16 = (undefined4 *)((int)puVar16 + iVar15);
                        puVar28 = (undefined4 *)((int)puVar28 + (int)param_9);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      return 0;
                    }
                    if (local_4e7 == ' ') {
                      if (local_4dc == 0xff0000) {
                        if ((local_4d8 == (uint *)0xff00) && (local_4d4 == 0xff)) goto LAB_0054ae27;
                      }
                      else if ((local_4dc == 0xff) &&
                              ((local_4d8 == (uint *)0xff00 && (local_4d4 == 0xff0000)))) {
LAB_0054ae27:
                        iVar38 = (int)(local_c + (uVar11 & 7)) >> 3;
                        iVar27 = local_c + iVar38 * -8;
                        do {
                          iVar19 = iVar27;
                          if (iVar38 != 0) {
                            iVar25 = iVar38;
                            do {
                              *(undefined1 *)puVar16 = *(undefined1 *)puVar28;
                              *(undefined1 *)((int)puVar16 + 1) = *(undefined1 *)puVar28;
                              *(undefined1 *)((int)puVar16 + 2) = *(undefined1 *)puVar28;
                              *(undefined1 *)((int)puVar16 + 3) = *(undefined1 *)puVar28;
                              *(undefined1 *)(puVar16 + 1) = *(undefined1 *)((int)puVar28 + 1);
                              *(undefined1 *)((int)puVar16 + 5) = *(undefined1 *)((int)puVar28 + 1);
                              *(undefined1 *)((int)puVar16 + 6) = *(undefined1 *)((int)puVar28 + 1);
                              *(undefined1 *)((int)puVar16 + 7) = *(undefined1 *)((int)puVar28 + 1);
                              *(undefined1 *)(puVar16 + 2) = *(undefined1 *)((int)puVar28 + 2);
                              *(undefined1 *)((int)puVar16 + 9) = *(undefined1 *)((int)puVar28 + 2);
                              *(undefined1 *)((int)puVar16 + 10) = *(undefined1 *)((int)puVar28 + 2)
                              ;
                              *(undefined1 *)((int)puVar16 + 0xb) =
                                   *(undefined1 *)((int)puVar28 + 2);
                              *(undefined1 *)(puVar16 + 3) = *(undefined1 *)((int)puVar28 + 3);
                              *(undefined1 *)((int)puVar16 + 0xd) =
                                   *(undefined1 *)((int)puVar28 + 3);
                              *(undefined1 *)((int)puVar16 + 0xe) =
                                   *(undefined1 *)((int)puVar28 + 3);
                              *(undefined1 *)((int)puVar16 + 0xf) =
                                   *(undefined1 *)((int)puVar28 + 3);
                              *(undefined1 *)(puVar16 + 4) = *(undefined1 *)(puVar28 + 1);
                              *(undefined1 *)((int)puVar16 + 0x11) = *(undefined1 *)(puVar28 + 1);
                              *(undefined1 *)((int)puVar16 + 0x12) = *(undefined1 *)(puVar28 + 1);
                              *(undefined1 *)((int)puVar16 + 0x13) = *(undefined1 *)(puVar28 + 1);
                              *(undefined1 *)(puVar16 + 5) = *(undefined1 *)((int)puVar28 + 5);
                              *(undefined1 *)((int)puVar16 + 0x15) =
                                   *(undefined1 *)((int)puVar28 + 5);
                              *(undefined1 *)((int)puVar16 + 0x16) =
                                   *(undefined1 *)((int)puVar28 + 5);
                              *(undefined1 *)((int)puVar16 + 0x17) =
                                   *(undefined1 *)((int)puVar28 + 5);
                              *(undefined1 *)(puVar16 + 6) = *(undefined1 *)((int)puVar28 + 6);
                              *(undefined1 *)((int)puVar16 + 0x19) =
                                   *(undefined1 *)((int)puVar28 + 6);
                              *(undefined1 *)((int)puVar16 + 0x1a) =
                                   *(undefined1 *)((int)puVar28 + 6);
                              *(undefined1 *)((int)puVar16 + 0x1b) =
                                   *(undefined1 *)((int)puVar28 + 6);
                              *(undefined1 *)(puVar16 + 7) = *(undefined1 *)((int)puVar28 + 7);
                              *(undefined1 *)((int)puVar16 + 0x1d) =
                                   *(undefined1 *)((int)puVar28 + 7);
                              *(undefined1 *)((int)puVar16 + 0x1e) =
                                   *(undefined1 *)((int)puVar28 + 7);
                              *(undefined1 *)((int)puVar16 + 0x1f) =
                                   *(undefined1 *)((int)puVar28 + 7);
                              puVar16 = puVar16 + 8;
                              puVar28 = puVar28 + 2;
                              iVar25 = iVar25 + -1;
                            } while (iVar25 != 0);
                          }
                          for (; iVar19 != 0; iVar19 = iVar19 + -1) {
                            *(undefined1 *)puVar16 = *(undefined1 *)puVar28;
                            *(undefined1 *)((int)puVar16 + 1) = *(undefined1 *)puVar28;
                            *(undefined1 *)((int)puVar16 + 2) = *(undefined1 *)puVar28;
                            *(undefined1 *)((int)puVar16 + 3) = *(undefined1 *)puVar28;
                            puVar16 = puVar16 + 1;
                            puVar28 = (undefined4 *)((int)puVar28 + 1);
                          }
                          puVar28 = (undefined4 *)((int)puVar28 + (int)param_9);
                          puVar16 = (undefined4 *)((int)puVar16 + iVar15);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        return 0;
                      }
                    }
                    goto LAB_00549d0c;
                  }
                }
                else if ((local_914._1_1_ == 2) && (local_914._2_1_ == 8)) {
                  param_9 = (ulonglong *)(param_2 - local_4e8 * local_c);
                  iVar15 = param_5 - local_910 * local_c;
                  puVar16 = (undefined4 *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
                  puVar28 = (undefined4 *)
                            (param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
                  if ((local_4ec._1_1_ == 2) && (local_4ec._2_1_ == 8)) {
                    iVar38 = (int)(local_c + (uVar11 & 7)) >> 3;
                    iVar27 = local_c + iVar38 * -8;
                    do {
                      iVar19 = iVar27;
                      if (iVar38 != 0) {
                        iVar25 = iVar38;
                        do {
                          *puVar16 = *puVar28;
                          puVar16[1] = puVar28[1];
                          puVar16[2] = puVar28[2];
                          puVar16[3] = puVar28[3];
                          puVar16 = puVar16 + 4;
                          puVar28 = puVar28 + 4;
                          iVar25 = iVar25 + -1;
                        } while (iVar25 != 0);
                      }
                      for (; iVar19 != 0; iVar19 = iVar19 + -1) {
                        *(undefined2 *)puVar16 = *(undefined2 *)puVar28;
                        puVar16 = (undefined4 *)((int)puVar16 + 2);
                        puVar28 = (undefined4 *)((int)puVar28 + 2);
                      }
                      puVar28 = (undefined4 *)((int)puVar28 + iVar15);
                      puVar16 = (undefined4 *)((int)puVar16 + (int)param_9);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    return 0;
                  }
                  if (local_4e7 == ' ') {
                    if (local_4dc == 0xff0000) {
                      if ((local_4d8 == (uint *)0xff00) && (local_4d4 == 0xff)) goto LAB_0054b0cb;
                    }
                    else if ((local_4dc == 0xff) &&
                            ((local_4d8 == (uint *)0xff00 && (local_4d4 == 0xff0000)))) {
LAB_0054b0cb:
                      iVar38 = (int)(local_c + (uVar11 & 7)) >> 3;
                      iVar27 = local_c + iVar38 * -8;
                      do {
                        iVar19 = iVar27;
                        if (iVar38 != 0) {
                          iVar25 = iVar38;
                          do {
                            *(undefined1 *)puVar16 = *(undefined1 *)puVar28;
                            *(undefined1 *)((int)puVar16 + 1) = *(undefined1 *)((int)puVar28 + 1);
                            *(undefined1 *)((int)puVar16 + 2) = *(undefined1 *)puVar28;
                            *(undefined1 *)((int)puVar16 + 3) = *(undefined1 *)((int)puVar28 + 1);
                            *(undefined1 *)(puVar16 + 1) = *(undefined1 *)((int)puVar28 + 2);
                            *(undefined1 *)((int)puVar16 + 5) = *(undefined1 *)((int)puVar28 + 3);
                            *(undefined1 *)((int)puVar16 + 6) = *(undefined1 *)((int)puVar28 + 2);
                            *(undefined1 *)((int)puVar16 + 7) = *(undefined1 *)((int)puVar28 + 3);
                            *(undefined1 *)(puVar16 + 2) = *(undefined1 *)(puVar28 + 1);
                            *(undefined1 *)((int)puVar16 + 9) = *(undefined1 *)((int)puVar28 + 5);
                            *(undefined1 *)((int)puVar16 + 10) = *(undefined1 *)(puVar28 + 1);
                            *(undefined1 *)((int)puVar16 + 0xb) = *(undefined1 *)((int)puVar28 + 5);
                            *(undefined1 *)(puVar16 + 3) = *(undefined1 *)((int)puVar28 + 6);
                            *(undefined1 *)((int)puVar16 + 0xd) = *(undefined1 *)((int)puVar28 + 7);
                            *(undefined1 *)((int)puVar16 + 0xe) = *(undefined1 *)((int)puVar28 + 6);
                            *(undefined1 *)((int)puVar16 + 0xf) = *(undefined1 *)((int)puVar28 + 7);
                            *(undefined1 *)(puVar16 + 4) = *(undefined1 *)(puVar28 + 2);
                            *(undefined1 *)((int)puVar16 + 0x11) = *(undefined1 *)((int)puVar28 + 9)
                            ;
                            *(undefined1 *)((int)puVar16 + 0x12) = *(undefined1 *)(puVar28 + 2);
                            *(undefined1 *)((int)puVar16 + 0x13) = *(undefined1 *)((int)puVar28 + 9)
                            ;
                            *(undefined1 *)(puVar16 + 5) = *(undefined1 *)((int)puVar28 + 10);
                            *(undefined1 *)((int)puVar16 + 0x15) =
                                 *(undefined1 *)((int)puVar28 + 0xb);
                            *(undefined1 *)((int)puVar16 + 0x16) =
                                 *(undefined1 *)((int)puVar28 + 10);
                            *(undefined1 *)((int)puVar16 + 0x17) =
                                 *(undefined1 *)((int)puVar28 + 0xb);
                            *(undefined1 *)(puVar16 + 6) = *(undefined1 *)(puVar28 + 3);
                            *(undefined1 *)((int)puVar16 + 0x19) =
                                 *(undefined1 *)((int)puVar28 + 0xd);
                            *(undefined1 *)((int)puVar16 + 0x1a) = *(undefined1 *)(puVar28 + 3);
                            *(undefined1 *)((int)puVar16 + 0x1b) =
                                 *(undefined1 *)((int)puVar28 + 0xd);
                            *(undefined1 *)(puVar16 + 7) = *(undefined1 *)((int)puVar28 + 0xe);
                            *(undefined1 *)((int)puVar16 + 0x1d) =
                                 *(undefined1 *)((int)puVar28 + 0xf);
                            *(undefined1 *)((int)puVar16 + 0x1e) =
                                 *(undefined1 *)((int)puVar28 + 0xe);
                            *(undefined1 *)((int)puVar16 + 0x1f) =
                                 *(undefined1 *)((int)puVar28 + 0xf);
                            puVar16 = puVar16 + 8;
                            puVar28 = puVar28 + 4;
                            iVar25 = iVar25 + -1;
                          } while (iVar25 != 0);
                        }
                        for (; iVar19 != 0; iVar19 = iVar19 + -1) {
                          *(undefined1 *)puVar16 = *(undefined1 *)puVar28;
                          *(undefined1 *)((int)puVar16 + 1) = *(undefined1 *)((int)puVar28 + 1);
                          *(undefined1 *)((int)puVar16 + 2) = *(undefined1 *)puVar28;
                          *(undefined1 *)((int)puVar16 + 3) = *(undefined1 *)((int)puVar28 + 1);
                          puVar16 = puVar16 + 1;
                          puVar28 = (undefined4 *)((int)puVar28 + 2);
                        }
                        puVar16 = (undefined4 *)((int)puVar16 + (int)param_9);
                        puVar28 = (undefined4 *)((int)puVar28 + iVar15);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      return 0;
                    }
                  }
                  goto LAB_00549d0c;
                }
                if (local_90f == '\b') {
                  iVar38 = param_2 - local_4e8 * local_c;
                  iVar15 = param_5 - local_910 * local_c;
                  local_1c = (uint *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
                  param_9 = (ulonglong *)
                            (param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
                  if (local_4e7 == '\x10') {
                    if (local_4d0 == (uint *)0x0) {
                      if (local_4dc == 0xf800) {
                        if ((local_4d8 == (uint *)0x7e0) && (local_4d4 == 0x1f)) {
                          do {
                            uVar11 = local_c;
                            do {
                              uVar26 = (&uStack_8ec)[(byte)*param_9];
                              *(ushort *)local_1c =
                                   (ushort)(uVar26 >> 5) & 0x7e0 | (ushort)(uVar26 >> 3) & 0x1f |
                                   (ushort)(uVar26 >> 8) & 0xf800;
                              local_1c = (uint *)((int)local_1c + 2);
                              param_9 = (ulonglong *)((int)param_9 + 1);
                              uVar11 = uVar11 - 1;
                            } while (uVar11 != 0);
                            local_1c = (uint *)((int)local_1c + iVar38);
                            param_9 = (ulonglong *)((int)param_9 + iVar15);
                            local_8 = local_8 + -1;
                          } while (local_8 != 0);
                          return 0;
                        }
                      }
                      else if (((local_4dc == 0x7c00) && (local_4d8 == (uint *)0x3e0)) &&
                              (local_4d4 == 0x1f)) {
                        do {
                          uVar11 = local_c;
                          do {
                            uVar26 = (&uStack_8ec)[(byte)*param_9];
                            *(ushort *)local_1c =
                                 (ushort)(uVar26 >> 6) & 0x3e0 | (ushort)(uVar26 >> 3) & 0x1f |
                                 (ushort)(uVar26 >> 9) & 0x7c00 | 0x8000;
                            local_1c = (uint *)((int)local_1c + 2);
                            param_9 = (ulonglong *)((int)param_9 + 1);
                            uVar11 = uVar11 - 1;
                          } while (uVar11 != 0);
                          local_1c = (uint *)((int)local_1c + iVar38);
                          param_9 = (ulonglong *)((int)param_9 + iVar15);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        return 0;
                      }
                    }
                  }
                  else if (((local_4e7 == ' ') && (local_4d0 == (uint *)0x0)) &&
                          ((local_4dc == 0xff0000 &&
                           ((local_4d8 == (uint *)0xff00 && (local_4d4 == 0xff)))))) {
                    do {
                      uVar11 = local_c;
                      do {
                        *local_1c = (&uStack_8ec)[(byte)*param_9] | 0xff000000;
                        param_9 = (ulonglong *)((int)param_9 + 1);
                        local_1c = local_1c + 1;
                        uVar11 = uVar11 - 1;
                      } while (uVar11 != 0);
                      local_1c = (uint *)((int)local_1c + iVar38);
                      param_9 = (ulonglong *)((int)param_9 + iVar15);
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    return 0;
                  }
                }
                else {
                  if (local_90f == ' ') {
                    if ((((local_8f8 == (uint *)0xff000000) && (local_904 == 0xff0000)) &&
                        (local_900 == (uint *)0xff00)) && (local_8fc == 0xff)) {
                      iVar38 = param_2 - local_4e8 * local_c;
                      iVar15 = param_5 - local_910 * local_c;
                      puVar28 = (undefined4 *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
                      puVar16 = (undefined4 *)
                                (param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
                      if (local_4e7 == ' ') {
                        if (local_4d0 == (uint *)0xff000000) {
                          if (((local_4dc == 0xff) && (local_4d8 == (uint *)0xff00)) &&
                             (local_4d4 == 0xff0000)) {
                            do {
                              uVar11 = local_c;
                              do {
                                puVar20 = puVar28 + 1;
                                puVar35 = puVar16 + 1;
                                uVar11 = uVar11 - 1;
                                *puVar28 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)
                                                                       ((int)puVar16 + 3),
                                                                      *(undefined1 *)puVar16),
                                                             *(undefined1 *)((int)puVar16 + 1)),
                                                    *(undefined1 *)((int)puVar16 + 2));
                                puVar16 = puVar35;
                                puVar28 = puVar20;
                              } while (uVar11 != 0);
                              puVar16 = (undefined4 *)((int)puVar35 + iVar15);
                              puVar28 = (undefined4 *)((int)puVar20 + iVar38);
                              local_8 = local_8 + -1;
                            } while (local_8 != 0);
                            return 0;
                          }
                        }
                        else if (((local_4d0 == (uint *)0x0) && (local_4dc == 0xff0000)) &&
                                ((local_4d8 == (uint *)0xff00 && (local_4d4 == 0xff)))) {
                          do {
                            uVar11 = local_c;
                            do {
                              *puVar28 = *puVar16;
                              puVar28 = puVar28 + 1;
                              puVar16 = puVar16 + 1;
                              uVar11 = uVar11 - 1;
                            } while (uVar11 != 0);
                            puVar28 = (undefined4 *)((int)puVar28 + iVar38);
                            puVar16 = (undefined4 *)((int)puVar16 + iVar15);
                            local_8 = local_8 + -1;
                          } while (local_8 != 0);
                          return 0;
                        }
                      }
                      goto LAB_00549d0c;
                    }
                  }
                  else if ((((local_90f == '\x18') && (local_904 == 0xff0000)) &&
                           (local_900 == (uint *)0xff00)) && (local_8fc == 0xff)) {
                    iVar38 = param_2 - local_4e8 * local_c;
                    iVar15 = param_5 - local_910 * local_c;
                    local_1c = (uint *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
                    param_9 = (ulonglong *)
                              (param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
                    if (local_4e7 == '\x10') {
                      if (local_4d0 == (uint *)0x0) {
                        if (local_4dc == 0xf800) {
                          if ((local_4d8 == (uint *)0x7e0) && (local_4d4 == 0x1f)) {
                            do {
                              uVar11 = local_c;
                              do {
                                *(ushort *)local_1c =
                                     (ushort)(*(byte *)((int)param_9 + 2) >> 3) << 0xb |
                                     (ushort)(*(byte *)((int)param_9 + 1) >> 2) << 5 |
                                     (ushort)(byte)((byte)*param_9 >> 3);
                                local_1c = (uint *)((int)local_1c + 2);
                                param_9 = (ulonglong *)((int)param_9 + 3);
                                uVar11 = uVar11 - 1;
                              } while (uVar11 != 0);
                              local_1c = (uint *)((int)local_1c + iVar38);
                              param_9 = (ulonglong *)((int)param_9 + iVar15);
                              local_8 = local_8 + -1;
                            } while (local_8 != 0);
                            return 0;
                          }
                        }
                        else if (((local_4dc == 0x7c00) && (local_4d8 == (uint *)0x3e0)) &&
                                (local_4d4 == 0x1f)) {
                          do {
                            uVar11 = local_c;
                            do {
                              *(ushort *)local_1c =
                                   (ushort)(*(byte *)((int)param_9 + 2) >> 3) << 10 |
                                   (ushort)(*(byte *)((int)param_9 + 1) >> 3) << 5 |
                                   (byte)((byte)*param_9 >> 3) | 0x8000;
                              local_1c = (uint *)((int)local_1c + 2);
                              param_9 = (ulonglong *)((int)param_9 + 3);
                              uVar11 = uVar11 - 1;
                            } while (uVar11 != 0);
                            local_1c = (uint *)((int)local_1c + iVar38);
                            param_9 = (ulonglong *)((int)param_9 + iVar15);
                            local_8 = local_8 + -1;
                          } while (local_8 != 0);
                          return 0;
                        }
                      }
                    }
                    else if (local_4e7 == ' ') {
                      if (local_4dc == 0xff0000) {
                        if ((local_4d8 == (uint *)0xff00) && (local_4d4 == 0xff)) {
                          do {
                            uVar11 = local_c;
                            do {
                              puVar12 = (undefined1 *)((int)param_9 + 2);
                              *(short *)local_1c = (short)*param_9;
                              param_9 = (ulonglong *)((int)param_9 + 3);
                              *(undefined1 *)((int)local_1c + 2) = *puVar12;
                              *(undefined1 *)((int)local_1c + 3) = 0xff;
                              local_1c = local_1c + 1;
                              uVar11 = uVar11 - 1;
                            } while (uVar11 != 0);
                            local_1c = (uint *)((int)local_1c + iVar38);
                            param_9 = (ulonglong *)((int)param_9 + iVar15);
                            local_8 = local_8 + -1;
                          } while (local_8 != 0);
                          return 0;
                        }
                      }
                      else if (((local_4dc == 0xff) && (local_4d8 == (uint *)0xff00)) &&
                              (local_4d4 == 0xff0000)) {
                        do {
                          uVar11 = local_c;
                          do {
                            *local_1c = (((byte)*param_9 | 0xffffff00) << 8 |
                                        (uint)*(byte *)((int)param_9 + 1)) << 8 |
                                        (uint)*(byte *)((int)param_9 + 2);
                            local_1c = local_1c + 1;
                            param_9 = (ulonglong *)((int)param_9 + 3);
                            uVar11 = uVar11 - 1;
                          } while (uVar11 != 0);
                          param_9 = (ulonglong *)((int)param_9 + iVar15);
                          local_1c = (uint *)((int)local_1c + iVar38);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        return 0;
                      }
                    }
                    goto LAB_00549d0c;
                  }
                  if ((bVar5) || (local_90f != ' ')) {
                    if ((((local_90f == '\x10') &&
                         ((local_8f8 == (uint *)0x8000 && (local_904 == 0x7c00)))) &&
                        (local_900 == (uint *)0x3e0)) && (local_8fc == 0x1f)) {
                      puVar13 = (uint *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
                      puVar24 = (ushort *)
                                (param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
                      if ((((local_4e7 == ' ') && (local_4d0 == (uint *)0xff000000)) &&
                          (local_4dc == 0xff)) &&
                         ((local_4d8 == (uint *)0xff00 && (local_4d4 == 0xff0000)))) {
                        do {
                          param_3 = (undefined4 *)local_c;
                          do {
                            uVar9 = *puVar24;
                            uVar11 = (uint)uVar9;
                            if ((uVar9 & 0x8000) == 0) {
                              uVar26 = uVar11 & 0x1f;
                            }
                            else {
                              uVar26 = uVar11 | 0xffffffe0;
                            }
                            *puVar13 = (uVar26 << 0xd | uVar11 & 0x3e0) << 6 | uVar9 >> 7 & 0xf8;
                            puVar24 = puVar24 + 1;
                            puVar13 = puVar13 + 1;
                            param_3 = (undefined4 *)((int)param_3 - 1);
                          } while (param_3 != (undefined4 *)0x0);
                          puVar24 = (ushort *)((int)puVar24 + (param_5 - local_910 * local_c));
                          puVar13 = (uint *)((int)puVar13 + (param_2 - local_4e8 * local_c));
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        return 0;
                      }
                    }
                    else if (((!bVar5) && (local_90f == '\x10')) && (local_8f8 == (uint *)0x0)) {
                      if (local_904 == 0xf800) {
                        if ((local_900 == (uint *)0x7e0) && (local_8fc == 0x1f)) {
                          iVar38 = param_2 - local_4e8 * local_c;
                          iVar15 = param_5 - local_910 * local_c;
                          local_38 = (ulonglong *)
                                     (param_11 * param_2 + local_4e8 * param_10 + param_1);
                          param_9 = (ulonglong *)
                                    (param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
                          if (local_4e7 == '\x18') {
                            if ((((local_4d0 == (uint *)0x0) && (local_4dc == 0xff0000)) &&
                                (local_4d8 == (uint *)0xff00)) && (local_4d4 == 0xff)) {
                              do {
                                uVar11 = local_c;
                                do {
                                  uVar6 = *param_9;
                                  uVar26 = (uint)(ushort)uVar6;
                                  *(ushort *)local_38 =
                                       (ushort)((uVar26 & 0x1f) << 3) |
                                       (ushort)((uVar26 & 0x7e0) << 5);
                                  *(byte *)((int)local_38 + 2) = (byte)(uVar6 >> 8) & 0xf8;
                                  local_38 = (ulonglong *)((int)local_38 + 3);
                                  param_9 = (ulonglong *)((int)param_9 + 2);
                                  uVar11 = uVar11 - 1;
                                } while (uVar11 != 0);
                                local_38 = (ulonglong *)((int)local_38 + iVar38);
                                param_9 = (ulonglong *)((int)param_9 + iVar15);
                                local_8 = local_8 + -1;
                              } while (local_8 != 0);
                              return 0;
                            }
                          }
                          else if (local_4e7 == ' ') {
                            if (((local_4d0 == (uint *)0x0) && (local_4dc == 0xff0000)) &&
                               ((local_4d8 == (uint *)0xff00 && (local_4d4 == 0xff)))) {
                              do {
                                uVar11 = local_c;
                                do {
                                  uVar26 = (uint)(ushort)*param_9;
                                  *(uint *)local_38 =
                                       (uVar26 & 0x1f) << 3 |
                                       (uVar26 & 0x7e0) << 5 | (uVar26 & 0xf800) << 8;
                                  local_38 = (ulonglong *)((int)local_38 + 4);
                                  param_9 = (ulonglong *)((int)param_9 + 2);
                                  uVar11 = uVar11 - 1;
                                } while (uVar11 != 0);
                                local_38 = (ulonglong *)((int)local_38 + iVar38);
                                param_9 = (ulonglong *)((int)param_9 + iVar15);
                                local_8 = local_8 + -1;
                              } while (local_8 != 0);
                              return 0;
                            }
                          }
                          else if (((local_4e7 == '\x10') && (local_4d0 == (uint *)0x0)) &&
                                  ((local_4dc == 0x7c00 &&
                                   ((local_4d8 == (uint *)0x3e0 && (local_4d4 == 0x1f)))))) {
                            iVar27 = FUN_0050e8b0();
                            if (iVar27 == 1) {
                              do {
                                for (uVar11 = local_c >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
                                  *local_38 = (*param_9 & 0xffc0ffc0ffc0ffc0) >> 1 |
                                              *param_9 & 0x1f001f001f001f;
                                  local_38 = local_38 + 1;
                                  param_9 = param_9 + 1;
                                }
                                for (uVar11 = local_c & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
                                  *(ushort *)local_38 =
                                       (ushort)*param_9 & 0x1f |
                                       (ushort)(((ushort)*param_9 & 0xffc0ffc0) >> 1);
                                  local_38 = (ulonglong *)((int)local_38 + 2);
                                  param_9 = (ulonglong *)((int)param_9 + 2);
                                }
                                local_38 = (ulonglong *)((int)local_38 + iVar38);
                                param_9 = (ulonglong *)((int)param_9 + iVar15);
                                local_8 = local_8 + -1;
                              } while (local_8 != 0);
                              return 0;
                            }
                            do {
                              for (uVar11 = local_c >> 1; uVar11 != 0; uVar11 = uVar11 - 1) {
                                *(uint *)local_38 =
                                     (uint)*param_9 & 0x1f001f | ((uint)*param_9 & 0xffc0ffc0) >> 1;
                                local_38 = (ulonglong *)((int)local_38 + 4);
                                param_9 = (ulonglong *)((int)param_9 + 4);
                              }
                              if ((local_c & 1) != 0) {
                                *(ushort *)local_38 =
                                     (ushort)*param_9 & 0x1f |
                                     (ushort)(((ushort)*param_9 & 0xffc0ffc0) >> 1);
                                local_38 = (ulonglong *)((int)local_38 + 2);
                                param_9 = (ulonglong *)((int)param_9 + 2);
                              }
                              local_38 = (ulonglong *)((int)local_38 + iVar38);
                              param_9 = (ulonglong *)((int)param_9 + iVar15);
                              local_8 = local_8 + -1;
                            } while (local_8 != 0);
                            return 0;
                          }
                        }
                      }
                      else if (((local_904 == 0x7c00) && (local_900 == (uint *)0x3e0)) &&
                              (local_8fc == 0x1f)) {
                        iVar38 = param_2 - local_4e8 * local_c;
                        iVar15 = param_5 - local_910 * local_c;
                        local_14 = (float *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
                        param_9 = (ulonglong *)
                                  (param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
                        if (((local_4e7 == '\x10') && (local_4d0 == (uint *)0x0)) &&
                           ((local_4dc == 0xf800 &&
                            ((local_4d8 == (uint *)0x7e0 && (local_4d4 == 0x1f)))))) {
                          iVar27 = FUN_0050e8b0();
                          if (iVar27 == 1) {
                            do {
                              for (uVar11 = local_c >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
                                *(ulonglong *)local_14 =
                                     (*param_9 & 0x7fe07fe07fe07fe0) << 1 |
                                     *param_9 & 0x3f003f003f003f;
                                local_14 = local_14 + 2;
                                param_9 = param_9 + 1;
                              }
                              for (uVar11 = local_c & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
                                *(ushort *)local_14 =
                                     (ushort)*param_9 & 0x3f | ((ushort)*param_9 & 0x7fe0) << 1;
                                local_14 = (float *)((int)local_14 + 2);
                                param_9 = (ulonglong *)((int)param_9 + 2);
                              }
                              local_14 = (float *)((int)local_14 + iVar38);
                              param_9 = (ulonglong *)((int)param_9 + iVar15);
                              local_8 = local_8 + -1;
                            } while (local_8 != 0);
                            return 0;
                          }
                          do {
                            for (uVar11 = local_c >> 1; uVar11 != 0; uVar11 = uVar11 - 1) {
                              *local_14 = (float)((uint)*param_9 & 0x3f003f |
                                                 ((uint)*param_9 & 0x7fe07fe0) << 1);
                              local_14 = local_14 + 1;
                              param_9 = (ulonglong *)((int)param_9 + 4);
                            }
                            if ((local_c & 1) != 0) {
                              *(ushort *)local_14 =
                                   (ushort)*param_9 & 0x3f | ((ushort)*param_9 & 0x7fe0) << 1;
                              local_14 = (float *)((int)local_14 + 2);
                              param_9 = (ulonglong *)((int)param_9 + 2);
                            }
                            local_14 = (float *)((int)local_14 + iVar38);
                            param_9 = (ulonglong *)((int)param_9 + iVar15);
                            local_8 = local_8 + -1;
                          } while (local_8 != 0);
                          return 0;
                        }
                      }
                    }
                  }
                  else if ((((local_8f8 == (uint *)0x0) && (local_904 == 0xff0000)) &&
                           (local_900 == (uint *)0xff00)) && (local_8fc == 0xff)) {
                    local_54 = (ushort *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
                    param_9 = (ulonglong *)
                              (param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
                    if (((local_4e7 == '\x10') && (local_4d0 == (uint *)0x0)) &&
                       ((local_4dc == 0xf800 &&
                        ((local_4d8 == (uint *)0x7e0 && (local_4d4 == 0x1f)))))) {
                      do {
                        uVar11 = local_c;
                        do {
                          uVar26 = (uint)*param_9;
                          *local_54 = (ushort)((uVar26 & 0xf8) >> 3) |
                                      (ushort)((uVar26 & 0xfc00) >> 5) |
                                      (ushort)(*param_9 >> 8) & 0xf800;
                          local_54 = local_54 + 1;
                          param_9 = (ulonglong *)((int)param_9 + 4);
                          uVar11 = uVar11 - 1;
                        } while (uVar11 != 0);
                        local_54 = (ushort *)((int)local_54 + (param_2 - local_4e8 * local_c));
                        param_9 = (ulonglong *)((int)param_9 + (param_5 - local_910 * local_c));
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      return 0;
                    }
                  }
                }
              }
              else if (param_14 == 1) {
                if (local_90f == '\b') {
                  iVar38 = param_2 - local_4e8 * local_c;
                  iVar15 = param_5 - local_910 * local_c;
                  local_14 = (float *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
                  param_9 = (ulonglong *)
                            (param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
                  if (local_4e7 == '\x10') {
                    if ((((local_4d0 == (uint *)0x8000) && (local_4dc == 0x7c00)) &&
                        (local_4d8 == (uint *)0x3e0)) && (local_4d4 == 0x1f)) {
                      do {
                        uVar11 = local_c;
                        do {
                          fVar34 = (float)(&uStack_8ec)[(byte)*param_9];
                          if (fVar34 != param_15) {
                            fVar34 = (float)((uint)fVar34 | 0x1000000);
                          }
                          *(ushort *)local_14 =
                               (ushort)((uint)fVar34 >> 6) & 0x3e0 |
                               (ushort)((uint)fVar34 >> 3) & 0x1f |
                               (ushort)((uint)fVar34 >> 9) & 0xfc00;
                          local_14 = (float *)((int)local_14 + 2);
                          param_9 = (ulonglong *)((int)param_9 + 1);
                          uVar11 = uVar11 - 1;
                        } while (uVar11 != 0);
                        local_14 = (float *)((int)local_14 + iVar38);
                        param_9 = (ulonglong *)((int)param_9 + iVar15);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      return 0;
                    }
                  }
                  else if ((local_4e7 == ' ') && (local_4d0 == (uint *)0xff000000)) {
                    if (local_4dc == 0xff0000) {
                      if ((local_4d8 == (uint *)0xff00) && (local_4d4 == 0xff)) {
                        do {
                          uVar11 = local_c;
                          do {
                            fVar34 = (float)(&uStack_8ec)[(byte)*param_9];
                            if (fVar34 != param_15) {
                              fVar34 = (float)((uint)fVar34 | 0xff000000);
                            }
                            *local_14 = fVar34;
                            param_9 = (ulonglong *)((int)param_9 + 1);
                            local_14 = local_14 + 1;
                            uVar11 = uVar11 - 1;
                          } while (uVar11 != 0);
                          local_14 = (float *)((int)local_14 + iVar38);
                          param_9 = (ulonglong *)((int)param_9 + iVar15);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        return 0;
                      }
                    }
                    else if (((local_4dc == 0xff) && (local_4d8 == (uint *)0xff00)) &&
                            (local_4d4 == 0xff0000)) {
                      do {
                        uVar11 = local_c;
                        do {
                          uVar26 = (uint)(byte)*param_9;
                          param_3._0_2_ =
                               CONCAT11(*(undefined1 *)((int)&uStack_8ec + uVar26 * 4 + 1),
                                        *(undefined1 *)((int)&uStack_8ec + uVar26 * 4 + 2));
                          param_3._0_3_ =
                               CONCAT12(*(undefined1 *)(&uStack_8ec + uVar26),(ushort)param_3);
                          param_3 = (undefined4 *)
                                    CONCAT13(*(undefined1 *)((int)&uStack_8ec + uVar26 * 4 + 3),
                                             param_3._0_3_);
                          pfVar36 = local_14 + 1;
                          param_9 = (ulonglong *)((int)param_9 + 1);
                          uVar11 = uVar11 - 1;
                          param_3 = (undefined4 *)
                                    CONCAT13((param_3 ==
                                             (undefined4 *)
                                             ((uint)param_15._2_1_ | ((uint)param_15 & 0xff) << 0x10
                                             | (uint)param_15 & 0xff00ff00)) + -1,param_3._0_3_);
                          *local_14 = (float)param_3;
                          local_14 = pfVar36;
                        } while (uVar11 != 0);
                        param_9 = (ulonglong *)((int)param_9 + iVar15);
                        local_14 = (float *)((int)pfVar36 + iVar38);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      return 0;
                    }
                  }
                }
                else if (((local_90f == '\x18') && (local_904 == 0xff0000)) &&
                        ((local_900 == (uint *)0xff00 && (local_8fc == 0xff)))) {
                  iVar15 = param_2 - local_4e8 * local_c;
                  iVar38 = param_5 - local_910 * local_c;
                  local_14 = (float *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
                  param_9 = (ulonglong *)
                            (param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
                  if (local_4e7 == '\x10') {
                    if (((local_4d0 == (uint *)0x8000) && (local_4dc == 0x7c00)) &&
                       ((local_4d8 == (uint *)0x3e0 && (local_4d4 == 0x1f)))) {
                      do {
                        uVar11 = local_c;
                        do {
                          while( true ) {
                            pfVar36 = local_14;
                            puVar33 = param_9;
                            uVar26 = (uint)*puVar33;
                            if ((float)(uVar26 & 0xffffff) != param_15) break;
                            uVar9 = (ushort)((uVar26 & 0xf8f8f8) >> 3);
                            *(ushort *)pfVar36 =
                                 uVar9 & 0xff | (uVar9 >> 8) << 5 |
                                 (ushort)(((uVar26 & 0xf8f8f8) >> 0x13) << 10);
                            uVar11 = uVar11 - 1;
                            param_9 = (ulonglong *)((int)puVar33 + 3);
                            local_14 = (float *)((int)pfVar36 + 2);
                            if (uVar11 == 0) goto LAB_0054bba8;
                          }
                          uVar9 = (ushort)((uVar26 & 0xf8f8f8) >> 3);
                          *(ushort *)pfVar36 =
                               uVar9 & 0xff | (uVar9 >> 8) << 5 |
                               (ushort)(((uVar26 & 0xf8f8f8) >> 0x13) << 10) | 0x8000;
                          uVar11 = uVar11 - 1;
                          param_9 = (ulonglong *)((int)puVar33 + 3);
                          local_14 = (float *)((int)pfVar36 + 2);
                        } while (uVar11 != 0);
LAB_0054bba8:
                        local_14 = (float *)((int)pfVar36 + iVar15 + 2);
                        param_9 = (ulonglong *)((int)puVar33 + iVar38 + 3);
                        local_8 = local_8 + -1;
                        if (local_8 == 0) {
                          return 0;
                        }
                      } while( true );
                    }
                  }
                  else if ((local_4e7 == ' ') && (local_4d0 == (uint *)0xff000000)) {
                    if (local_4dc == 0xff0000) {
                      if ((local_4d8 == (uint *)0xff00) && (local_4d4 == 0xff)) {
                        do {
                          uVar11 = local_c;
                          do {
                            fVar34 = (float)(uint)(uint3)*param_9;
                            if (fVar34 != param_15) {
                              fVar34 = (float)((uint)fVar34 | 0xff000000);
                            }
                            *local_14 = fVar34;
                            param_9 = (ulonglong *)((int)param_9 + 3);
                            local_14 = local_14 + 1;
                            uVar11 = uVar11 - 1;
                          } while (uVar11 != 0);
                          local_14 = (float *)((int)local_14 + iVar15);
                          param_9 = (ulonglong *)((int)param_9 + iVar38);
                          local_8 = local_8 + -1;
                        } while (local_8 != 0);
                        return 0;
                      }
                    }
                    else if (((local_4dc == 0xff) && (local_4d8 == (uint *)0xff00)) &&
                            (local_4d4 == 0xff0000)) {
                      do {
                        param_13 = (float *)local_c;
                        do {
                          pbVar17 = (byte *)((int)param_9 + 2);
                          uVar11 = 0xff000000;
                          if ((float)(uint)(uint3)*param_9 == param_15) {
                            uVar11 = 0;
                          }
                          puVar12 = (undefined1 *)((int)param_9 + 1);
                          uVar6 = *param_9;
                          pfVar36 = local_14 + 1;
                          param_9 = (ulonglong *)((int)param_9 + 3);
                          *local_14 = (float)((uint)CONCAT11((char)uVar6,*puVar12) << 8 | uVar11 |
                                             (uint)*pbVar17);
                          param_13 = (float *)((int)param_13 - 1);
                          local_14 = pfVar36;
                        } while (param_13 != (float *)0x0);
                        local_14 = (float *)((int)pfVar36 + iVar15);
                        param_9 = (ulonglong *)((int)param_9 + iVar38);
                        local_8 = local_8 + -1;
                      } while (local_8 != 0);
                      return 0;
                    }
                  }
                }
                else if ((bVar5) || (local_90f != ' ')) {
                  if ((local_90f == '\x10') && (local_8f8 == (uint *)0x0)) {
                    if (local_904 == 0xf800) {
                      if ((local_900 == (uint *)0x7e0) && (local_8fc == 0x1f)) {
                        iVar15 = param_2 - local_4e8 * local_c;
                        param_9 = (ulonglong *)(param_5 - local_910 * local_c);
                        local_60 = (uint *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
                        local_14 = (float *)(param_12[1] * param_5 +
                                            *param_12 * (uint)local_910 + param_4);
                        if (local_4e7 == '\x10') {
                          if (local_4d0 == (uint *)0x1) {
                            if (((local_4dc == 0xf800) && (local_4d8 == (uint *)0x7c0)) &&
                               (local_4d4 == 0x3e)) {
                              do {
                                uVar11 = local_c;
                                do {
                                  uVar26 = (*(ushort *)local_14 & 0x1f) * 2 |
                                           *(ushort *)local_14 & 0xffc0;
                                  uVar9 = (ushort)uVar26;
                                  if ((((uint)param_15 >> 8 & 0xf8) * 8 |
                                       ((uint)param_15 & 0xff) >> 2 & 0xfffffffe |
                                      (param_15._2_1_ & 0xfffffff8) << 8) != uVar26) {
                                    uVar9 = uVar9 | 1;
                                  }
                                  *(ushort *)local_60 = uVar9;
                                  local_14 = (float *)((int)local_14 + 2);
                                  local_60 = (uint *)((int)local_60 + 2);
                                  uVar11 = uVar11 - 1;
                                } while (uVar11 != 0);
                                local_60 = (uint *)((int)local_60 + iVar15);
                                local_14 = (float *)((int)local_14 + (int)param_9);
                                local_8 = local_8 + -1;
                              } while (local_8 != 0);
                              return 0;
                            }
                          }
                          else if (((local_4d0 == (uint *)0x8000) && (local_4dc == 0x7c00)) &&
                                  ((local_4d8 == (uint *)0x3e0 && (local_4d4 == 0x1f)))) {
                            do {
                              uVar11 = local_c;
                              do {
                                uVar26 = (*(ushort *)local_14 & 0xffc0) >> 1 |
                                         *(ushort *)local_14 & 0x1f;
                                uVar9 = (ushort)uVar26;
                                if (uVar26 != (((param_15._2_1_ & 0xfffffff8) << 5 |
                                               (uint)param_15 >> 8 & 0xf8) * 4 |
                                              ((uint)param_15 & 0xff) >> 3)) {
                                  uVar9 = uVar9 | 0x8000;
                                }
                                *(ushort *)local_60 = uVar9;
                                local_60 = (uint *)((int)local_60 + 2);
                                local_14 = (float *)((int)local_14 + 2);
                                uVar11 = uVar11 - 1;
                              } while (uVar11 != 0);
                              local_60 = (uint *)((int)local_60 + iVar15);
                              local_14 = (float *)((int)local_14 + (int)param_9);
                              local_8 = local_8 + -1;
                            } while (local_8 != 0);
                            return 0;
                          }
                        }
                        else if ((local_4e7 == ' ') && (local_4d0 == (uint *)0xff000000)) {
                          if (local_4dc == 0xff0000) {
                            if ((local_4d8 == (uint *)0xff00) && (local_4d4 == 0xff)) {
                              do {
                                uVar11 = local_c;
                                do {
                                  uVar26 = (uint)*(ushort *)local_14;
                                  uVar26 = (uVar26 & 0x7e0) << 5 | (uVar26 & 0x1f) << 3 |
                                           (uVar26 & 0xf800) << 8;
                                  if ((uint)*(ushort *)local_14 !=
                                      (((param_15._2_1_ & 0xfffffff8) << 5 |
                                       (uint)param_15 >> 8 & 0xfc) * 8 |
                                      ((uint)param_15 & 0xff) >> 3)) {
                                    uVar26 = uVar26 | 0xff000000;
                                  }
                                  *local_60 = uVar26;
                                  local_60 = local_60 + 1;
                                  local_14 = (float *)((int)local_14 + 2);
                                  uVar11 = uVar11 - 1;
                                } while (uVar11 != 0);
                                local_60 = (uint *)((int)local_60 + iVar15);
                                local_14 = (float *)((int)local_14 + (int)param_9);
                                local_8 = local_8 + -1;
                              } while (local_8 != 0);
                              return 0;
                            }
                          }
                          else if (((local_4dc == 0xff) && (local_4d8 == (uint *)0xff00)) &&
                                  (local_4d4 == 0xff0000)) {
                            uVar11 = local_c;
                            while( true ) {
                              do {
                                uVar26 = (uint)*(ushort *)local_14;
                                if (uVar26 == (((param_15._2_1_ & 0xfffffff8) << 5 |
                                               (uint)param_15 >> 8 & 0xfc) * 8 |
                                              ((uint)param_15 & 0xff) >> 3)) {
                                  uVar37 = uVar26 & 0x1f;
                                }
                                else {
                                  uVar37 = uVar26 | 0xffffffe0;
                                }
                                *local_60 = (uVar37 << 0xe | uVar26 & 0x7e0) << 5 |
                                            *(ushort *)local_14 >> 8 & 0xf8;
                                local_14 = (float *)((int)local_14 + 2);
                                local_60 = local_60 + 1;
                                uVar11 = uVar11 - 1;
                              } while (uVar11 != 0);
                              local_60 = (uint *)((int)local_60 + iVar15);
                              local_14 = (float *)((int)local_14 + (int)param_9);
                              local_8 = local_8 + -1;
                              if (local_8 == 0) break;
                              uVar11 = local_c;
                            }
                            return 0;
                          }
                        }
                      }
                    }
                    else if (((local_904 == 0x7c00) && (local_900 == (uint *)0x3e0)) &&
                            (local_8fc == 0x1f)) {
                      iVar15 = param_2 - local_4e8 * local_c;
                      param_9 = (ulonglong *)(param_5 - local_910 * local_c);
                      puVar13 = (uint *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
                      puVar24 = (ushort *)
                                (param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
                      if (local_4e7 == '\x10') {
                        if (local_4d0 == (uint *)0x1) {
                          if (((local_4dc == 0xf800) && (local_4d8 == (uint *)0x7c0)) &&
                             (local_4d4 == 0x3e)) {
                            do {
                              uVar11 = local_c;
                              do {
                                uVar26 = (*puVar24 & 0x7fff) * 2;
                                uVar9 = (ushort)uVar26;
                                if ((((uint)param_15 >> 8 & 0xf8) * 8 |
                                     ((uint)param_15 & 0xff) >> 2 & 0xfffffffe |
                                    (param_15._2_1_ & 0xfffffff8) << 8) != uVar26) {
                                  uVar9 = uVar9 | 1;
                                }
                                *(ushort *)puVar13 = uVar9;
                                puVar24 = puVar24 + 1;
                                puVar13 = (uint *)((int)puVar13 + 2);
                                uVar11 = uVar11 - 1;
                              } while (uVar11 != 0);
                              puVar24 = (ushort *)((int)puVar24 + (int)param_9);
                              puVar13 = (uint *)((int)puVar13 + iVar15);
                              local_8 = local_8 + -1;
                            } while (local_8 != 0);
                            return 0;
                          }
                        }
                        else if (local_4d0 == (uint *)0x8000) {
                          if (((local_4dc == 0x7c00) && (local_4d8 == (uint *)0x3e0)) &&
                             (local_4d4 == 0x1f)) {
                            do {
                              uVar11 = local_c;
                              do {
                                uVar9 = (ushort)(*puVar24 & 0x7fff);
                                if ((((param_15._2_1_ & 0xfffffff8) << 5 |
                                     (uint)param_15 >> 8 & 0xf8) * 4 | ((uint)param_15 & 0xff) >> 3)
                                    != (*puVar24 & 0x7fff)) {
                                  uVar9 = uVar9 | 0x8000;
                                }
                                *(ushort *)puVar13 = uVar9;
                                puVar24 = puVar24 + 1;
                                puVar13 = (uint *)((int)puVar13 + 2);
                                uVar11 = uVar11 - 1;
                              } while (uVar11 != 0);
                              puVar24 = (ushort *)((int)puVar24 + (int)param_9);
                              puVar13 = (uint *)((int)puVar13 + iVar15);
                              local_8 = local_8 + -1;
                            } while (local_8 != 0);
                            return 0;
                          }
                        }
                        else if (((local_4d0 == (uint *)0x0) && (local_4dc == 0xf800)) &&
                                ((local_4d8 == (uint *)0x7e0 && (local_4d4 == 0x1f)))) {
                          do {
                            uVar11 = local_c;
                            do {
                              *puVar13 = (*puVar24 & 0xffe0) * 2 & 0xffff | *puVar24 & 0x1f;
                              puVar24 = puVar24 + 1;
                              puVar13 = (uint *)((int)puVar13 + 2);
                              uVar11 = uVar11 - 1;
                            } while (uVar11 != 0);
                            puVar24 = (ushort *)((int)puVar24 + (int)param_9);
                            puVar13 = (uint *)((int)puVar13 + iVar15);
                            local_8 = local_8 + -1;
                          } while (local_8 != 0);
                          return 0;
                        }
                      }
                      else if ((local_4e7 == ' ') && (local_4d0 == (uint *)0xff000000)) {
                        if (local_4dc == 0xff0000) {
                          if ((local_4d8 == (uint *)0xff00) && (local_4d4 == 0xff)) {
                            uVar11 = local_c;
                            while( true ) {
                              do {
                                uVar26 = (uint)*puVar24;
                                if (uVar26 == (((param_15._2_1_ & 0xfffffff8) << 5 |
                                               (uint)param_15 >> 8 & 0xf8) * 4 |
                                              ((uint)param_15 & 0xff) >> 3)) {
                                  uVar37 = uVar26 & 0x7c00;
                                }
                                else {
                                  uVar37 = uVar26 & 0xfffffc00 | 0xffff8000;
                                }
                                *puVar13 = ((uVar37 * 8 | uVar26 & 0x3e0) * 8 | uVar26 & 0x1f) * 8;
                                puVar24 = puVar24 + 1;
                                puVar13 = puVar13 + 1;
                                uVar11 = uVar11 - 1;
                              } while (uVar11 != 0);
                              puVar13 = (uint *)((int)puVar13 + iVar15);
                              puVar24 = (ushort *)((int)puVar24 + (int)param_9);
                              local_8 = local_8 + -1;
                              if (local_8 == 0) break;
                              uVar11 = local_c;
                            }
                            return 0;
                          }
                        }
                        else if (((local_4dc == 0xff) && (local_4d8 == (uint *)0xff00)) &&
                                (local_4d4 == 0xff0000)) {
                          uVar11 = local_c;
                          while( true ) {
                            do {
                              uVar26 = (uint)*puVar24;
                              if (uVar26 == (((param_15._2_1_ & 0xfffffff8) << 5 |
                                             (uint)param_15 >> 8 & 0xf8) * 4 |
                                            ((uint)param_15 & 0xff) >> 3)) {
                                uVar37 = uVar26 & 0x1f;
                              }
                              else {
                                uVar37 = uVar26 | 0xffffffe0;
                              }
                              *puVar13 = (uVar37 << 0xd | uVar26 & 0x3e0) << 6 |
                                         *puVar24 >> 7 & 0xf8;
                              puVar24 = puVar24 + 1;
                              puVar13 = puVar13 + 1;
                              uVar11 = uVar11 - 1;
                            } while (uVar11 != 0);
                            puVar13 = (uint *)((int)puVar13 + iVar15);
                            puVar24 = (ushort *)((int)puVar24 + (int)param_9);
                            local_8 = local_8 + -1;
                            if (local_8 == 0) break;
                            uVar11 = local_c;
                          }
                          return 0;
                        }
                      }
                    }
                  }
                }
                else if (((local_8f8 == (uint *)0x0) && (local_904 == 0xff0000)) &&
                        ((local_900 == (uint *)0xff00 && (local_8fc == 0xff)))) {
                  puVar13 = (uint *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
                  puVar12 = (undefined1 *)
                            (param_12[1] * param_5 + *param_12 * (uint)local_910 + param_4);
                  if (((local_4e7 == ' ') && (local_4d0 == (uint *)0xff000000)) &&
                     ((local_4dc == 0xff &&
                      ((local_4d8 == (uint *)0xff00 && (local_4d4 == 0xff0000)))))) {
                    do {
                      uVar11 = local_c;
                      do {
                        uVar26 = (uint)CONCAT21(CONCAT11(*puVar12,puVar12[1]),puVar12[2]);
                        if (((((uint)param_15 & 0xff) << 8 | (uint)param_15 >> 8 & 0xff) << 8 |
                            (uint)param_15._2_1_) != uVar26) {
                          uVar26 = uVar26 | 0xff000000;
                        }
                        *puVar13 = uVar26;
                        puVar12 = puVar12 + 4;
                        puVar13 = puVar13 + 1;
                        uVar11 = uVar11 - 1;
                      } while (uVar11 != 0);
                      puVar12 = puVar12 + (param_5 - local_910 * local_c);
                      puVar13 = (uint *)((int)puVar13 + (param_2 - local_4e8 * local_c));
                      local_8 = local_8 + -1;
                    } while (local_8 != 0);
                    return 0;
                  }
                }
              }
            }
          }
          goto LAB_00549d0c;
        }
        if (*(char *)((int)param_6 + 5) == '\b') {
          pbVar17 = (byte *)(param_11 * param_2 + param_10 + param_1);
          pbVar29 = (byte *)(param_12[1] * param_5 + *param_12 + param_4);
          uVar11 = 0;
          do {
            uVar26 = local_c;
            do {
              bVar21 = *pbVar29;
              *pbVar17 = bVar21;
              if (uVar11 < bVar21) {
                uVar11 = (uint)bVar21;
              }
              pbVar29 = pbVar29 + 1;
              pbVar17 = pbVar17 + 1;
              uVar26 = uVar26 - 1;
            } while (uVar26 != 0);
            pbVar17 = pbVar17 + (param_2 - local_c);
            pbVar29 = pbVar29 + (param_5 - local_c);
            local_8 = local_8 + -1;
          } while (local_8 != 0);
          return uVar11;
        }
      }
      return 0xffffffff;
    }
    if ((((((param_14 == 0) && (local_24 == 0)) && (param_17 == 0)) &&
         ((param_18 == 0 && (local_4ec._3_1_ == local_914._3_1_)))) &&
        (local_4ec._2_1_ == local_914._2_1_)) &&
       ((local_4ec._1_1_ == local_914._1_1_ && (local_4e8 == local_910)))) {
      uVar11 = local_4e8 * local_c;
      puVar16 = (undefined4 *)(iVar15 * param_5 + (uint)local_910 * (int)param_9 + param_4);
      puVar28 = (undefined4 *)(param_11 * param_2 + local_4e8 * param_10 + param_1);
      do {
        uVar26 = uVar11 >> 2;
        do {
          *puVar28 = *puVar16;
          puVar28 = puVar28 + 1;
          puVar16 = puVar16 + 1;
          uVar26 = uVar26 - 1;
        } while (uVar26 != 0);
        puVar28 = (undefined4 *)((int)puVar28 + (param_2 - uVar11));
        puVar16 = (undefined4 *)((int)puVar16 + (param_5 - uVar11));
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
  }
LAB_00549d0c:
  puVar33 = param_9;
  local_7c = 0;
  local_84 = 0;
  local_74 = 0;
  local_38 = (ulonglong *)0x0;
  local_b0 = 0;
  local_58 = 0;
  local_68 = 0;
  local_6c = 0;
  local_64 = 0;
  local_9c = (uint *)0x0;
  local_a8 = 0;
  local_94 = 0;
  local_1d = 0;
  local_1e = 0;
  local_15 = 0;
  param_9 = (ulonglong *)((uint)param_9 & 0xffffff);
  local_b8 = 0;
  local_b4 = 0;
  local_bc = 0;
  local_ac = 0;
  local_a0 = 0;
  local_a4 = 0;
  local_98 = 0;
  local_88 = 0;
  if ((local_914._3_1_ != '\0') || (local_914._2_1_ == 0x10)) {
    local_90f = ' ';
    local_904 = 0xff0000;
    local_908 = 0x10;
    local_90c = '\b';
    local_900 = (uint *)0xff00;
    local_907 = 8;
    cStack_90b = '\b';
    local_8fc = 0xff;
    local_906 = 0;
    cStack_90a = '\b';
    local_8f8 = (uint *)0xff000000;
    local_905 = 0x18;
    cStack_909 = '\b';
  }
  if ((local_4ec._3_1_ != '\0') || (local_4ec._2_1_ == 0x10)) {
    local_4e7 = ' ';
    local_4dc = 0xff0000;
    local_4e0 = 0x10;
    local_4e4 = '\b';
    local_4d8 = (uint *)0xff00;
    local_4df = 8;
    local_4e3 = '\b';
    local_4d4 = 0xff;
    local_4de = 0;
    local_4e2 = '\b';
    local_4d0 = (uint *)0xff000000;
    local_4dd = 0x18;
    local_4e1 = '\b';
  }
  if ((local_90c != local_4e4) || (local_d = '\0', cStack_90b != local_4e3)) {
    local_d = '\x01';
  }
  if ((local_24 != 0) && (local_d34 != local_4e1)) {
    local_d = '\x01';
  }
  if ((local_4ec._3_1_ != '\0') || (local_4ec._2_1_ == 0x10)) {
    local_d = '\0';
  }
  if ((((local_914._3_1_ != '\0') || (local_4ec._3_1_ != '\0')) || (local_914._2_1_ == 0x10)) ||
     (local_4ec._2_1_ == 0x10)) {
    param_19 = 0;
    param_14 = 0;
    local_24 = 0;
  }
  bVar21 = 0;
  if (local_914._3_1_ == '\0') {
    if (local_914._2_1_ == 0x10) {
      bVar21 = 6;
    }
    else {
      switch(local_90f) {
      case '\b':
        bVar21 = 3;
        break;
      case '\x10':
        bVar21 = 0;
        break;
      case '\x18':
        bVar21 = 1;
        break;
      case ' ':
        bVar21 = 2;
      }
    }
  }
  else if (local_914._2_1_ == 0x10) {
    bVar21 = 5;
  }
  else if (local_914._2_1_ == 0x20) {
    bVar21 = 4;
  }
  local_c4 = (uint)local_8f8 | local_8fc | (uint)local_900 | local_904;
  if (param_14 == 0) {
    switch(local_90f) {
    case '\b':
      param_15 = (float)((uint)param_15 & 0xff);
      break;
    case '\x10':
      param_15 = (float)((uint)param_15 & 0xffff);
      break;
    case '\x18':
      param_15 = (float)((uint)param_15 & 0xffffff);
    }
    if (local_90f != '\b') {
      param_15 = (float)((uint)param_15 & local_c4);
    }
  }
  param_6 = (undefined4 *)0x0;
  if (local_4ec._3_1_ == '\0') {
    if (local_4ec._2_1_ == 0x10) {
      param_6 = (undefined4 *)0x6000000;
    }
    else {
      switch(local_4e7) {
      case '\b':
        param_6 = (undefined4 *)0x3000000;
        break;
      case '\x10':
        param_6 = (undefined4 *)0x0;
        break;
      case '\x18':
        param_6 = (undefined4 *)0x1000000;
        break;
      case ' ':
        param_6 = (undefined4 *)0x2000000;
      }
    }
  }
  else if (local_4ec._2_1_ == 0x10) {
    param_6 = (undefined4 *)0x5000000;
  }
  else if (local_4ec._2_1_ == 0x20) {
    param_6 = (undefined4 *)0x4000000;
  }
  local_e = 0;
  switch(local_d37) {
  case 8:
    local_e = 3;
    break;
  case 0x10:
    local_e = 0;
    break;
  case 0x18:
    local_e = 1;
    break;
  case 0x20:
    local_e = 2;
  }
  if (local_d == '\x01') {
    local_15 = cStack_90a - local_4e2;
    local_1d = local_90c - local_4e4;
    local_1e = cStack_90b - local_4e3;
    cVar22 = local_d34;
    if (local_24 == 0) {
      cVar22 = cStack_909;
    }
    iVar15 = 1 << (local_90c - local_4e4 & 0x1fU);
    iVar38 = 1 << (cStack_90b - local_4e3 & 0x1fU);
    local_14 = (float *)(1 << (cStack_90a - local_4e2 & 0x1fU));
    local_90 = 1 << (cVar22 - local_4e1 & 0x1fU);
    param_9 = (ulonglong *)CONCAT13(cVar22 - local_4e1,(int3)puVar33);
    if (param_16 == 1) {
      local_54 = (ushort *)(uint)local_908;
      local_70 = (uint)local_907;
      local_8c = (uint)local_906;
      iVar27 = 0;
      do {
        iVar19 = *(int *)((int)&DAT_0084d368 + iVar27);
        *(uint *)((int)auStack_dbc + iVar27) = ((uint)(iVar19 * iVar15) >> 4) << (local_908 & 0x1f);
        *(uint *)((int)auStack_dfc + iVar27) = ((uint)(iVar19 * iVar38) >> 4) << (local_907 & 0x1f);
        *(uint *)((int)auStack_d7c + iVar27) =
             ((uint)(iVar19 * (int)local_14) >> 4) << (local_906 & 0x1f);
        bVar14 = local_d30;
        if (local_24 == 0) {
          bVar14 = local_905;
        }
        iVar25 = iVar27 + 4;
        *(uint *)((int)auStack_e3c + iVar27) = (iVar19 * local_90 >> 4) << (bVar14 & 0x1f);
        iVar27 = iVar25;
      } while (iVar25 < 0x40);
    }
    local_7c = iVar15 + -1 << (local_908 & 0x1f);
    local_84 = iVar38 + -1 << (local_907 & 0x1f);
    local_74 = (int)local_14 + -1 << (local_906 & 0x1f);
    bVar14 = local_d30;
    if (local_24 == 0) {
      bVar14 = local_905;
    }
    local_38 = (ulonglong *)(local_90 + -1 << (bVar14 & 0x1f));
    local_b0 = ~((uint)local_4d0 | local_4d4 | (uint)local_4d8 | local_4dc);
    local_a0 = local_904 >> (local_908 & 0x1f);
    local_a4 = (uint)local_900 >> (local_907 & 0x1f);
    local_98 = local_8fc >> (local_906 & 0x1f);
    if (local_24 == 0) {
      puVar13 = local_8f8;
      bVar14 = local_905;
    }
    else {
      puVar13 = local_d2c;
      bVar14 = local_d30;
    }
    local_88 = (uint)puVar13 >> (bVar14 & 0x1f);
    local_b8 = (1 << (local_4e4 - local_90c & 0x1fU)) + -1;
    local_b4 = (1 << (local_4e3 - cStack_90b & 0x1fU)) + -1;
    local_bc = (1 << (local_4e2 - cStack_90a & 0x1fU)) + -1;
    if (local_24 == 0) {
      local_d34 = cStack_909;
    }
    local_68 = 0;
    local_6c = 0;
    local_58 = 0;
    local_ac = (1 << (local_4e1 - local_d34 & 0x1fU)) + -1;
    local_64 = 0;
  }
  local_58 = 0;
  local_64 = 0;
  local_68 = 0;
  local_6c = 0;
  if (param_14 != 0) {
    uVar11 = FUN_005440f0(&local_914,(uint)param_15 >> 0x10 & 0xff,(uint)param_15 >> 8 & 0xff,
                          (uint)param_15 & 0xff,0xff);
    if (local_90f == '\b') {
      local_9c = (uint *)(uint)*(byte *)((int)&uStack_8ec + uVar11 * 4 + 2);
      local_a8 = (uint)*(byte *)((int)&uStack_8ec + uVar11 * 4 + 1);
      local_94 = (uint)*(byte *)(&uStack_8ec + uVar11);
    }
    else {
      local_9c = (uint *)((uVar11 & local_904) >> (local_908 & 0x1f));
      local_a8 = ((uint)local_900 & uVar11) >> (local_907 & 0x1f);
      local_94 = (local_8fc & uVar11) >> (local_906 & 0x1f);
    }
  }
  local_90 = (uint)local_4e8;
  if (param_13 == (float *)0x0) {
    iVar15 = -(local_90 * local_c);
  }
  else {
    iVar15 = local_90 * local_c;
  }
  local_8c = param_2 + iVar15;
  local_70 = param_5 - local_910 * local_c;
  local_54 = (ushort *)(param_8 - local_d38 * local_c);
  fVar34 = 0.0;
  uVar11 = 0;
  local_28 = 0;
  local_80 = 0;
  local_48 = 0;
  local_40 = 0;
  local_34 = 0;
  local_3c = 0;
  local_50 = 0.0;
  local_30 = 0.0;
  local_2c = 0.0;
  local_44 = 0.0;
  if (param_13 == (float *)0x1) {
    local_5c = (float *)(param_11 * param_2 + ((param_10 - 1) + local_c) * local_90 + param_1);
    local_90 = -local_90;
  }
  else {
    local_5c = (float *)(param_11 * param_2 + local_90 * param_10 + param_1);
  }
  param_13 = (float *)((uint)local_910 * *param_12 + param_12[1] * param_5 + param_4);
  local_14 = (float *)0x0;
  local_4c = (uint *)((uint)local_d38 * *param_12 + param_12[1] * param_8 + param_7);
  if (0 < local_8) {
    do {
      local_60 = (uint *)0x0;
      if (0 < (int)local_c) {
        local_c0 = (uint)bVar21;
        do {
          pfVar36 = local_5c;
          switch(local_c0) {
          case 0:
            fVar34 = (float)(uint)*(ushort *)param_13;
            break;
          case 1:
            fVar34 = (float)(uint)*(uint3 *)param_13;
            break;
          case 2:
            fVar34 = *param_13;
            break;
          case 3:
            fVar34 = (float)(&uStack_8ec)[*(byte *)param_13];
            break;
          case 4:
            local_50 = *param_13;
            if (local_914._1_1_ < 2) {
              local_30 = 1.0;
            }
            else {
              local_30 = param_13[1];
            }
            if (local_914._1_1_ < 3) {
              local_2c = 1.0;
            }
            else {
              local_2c = param_13[2];
            }
            if (local_914._1_1_ < 4) {
LAB_0054d324:
              local_44 = 1.0;
            }
            else {
              local_44 = param_13[3];
            }
            break;
          case 5:
            fVar41 = (float10)FUN_00540830(*(undefined2 *)param_13);
            local_50 = (float)fVar41;
            if (local_914._1_1_ < 2) {
              local_30 = 1.0;
            }
            else {
              fVar41 = (float10)FUN_00540830(*(undefined2 *)((int)param_13 + 2));
              local_30 = (float)fVar41;
            }
            if (local_914._1_1_ < 3) {
              local_2c = 1.0;
            }
            else {
              fVar41 = (float10)FUN_00540830(*(undefined2 *)(param_13 + 1));
              local_2c = (float)fVar41;
            }
            if (local_914._1_1_ < 4) goto LAB_0054d324;
            fVar41 = (float10)FUN_00540830(*(undefined2 *)((int)param_13 + 6));
            local_44 = (float)fVar41;
            break;
          case 6:
            local_48 = (uint)*(ushort *)param_13;
            if (local_914._1_1_ < 2) {
              local_40 = 0xffff;
            }
            else {
              local_40 = (uint)*(ushort *)((int)param_13 + 2);
            }
            if (local_914._1_1_ < 3) {
              local_34 = 0xffff;
            }
            else {
              local_34 = (uint)*(ushort *)(param_13 + 1);
            }
            if (local_914._1_1_ < 4) {
              local_3c = 0xffff;
            }
            else {
              local_3c = (uint)*(ushort *)((int)param_13 + 6);
            }
          }
          if (local_914._3_1_ == '\0') {
            if (local_914._2_1_ == 0x10) {
              if (local_4ec._3_1_ == '\0') {
                if (local_4ec._2_1_ != 0x10) {
                  fVar34 = (float)((local_3c >> 8 & 0xff) << (local_905 & 0x1f) |
                                   (local_34 >> 8 & 0xff) << (local_906 & 0x1f) |
                                   (local_40 >> 8 & 0xff) << (local_907 & 0x1f) |
                                  (local_48 >> 8 & 0xff) << (local_908 & 0x1f));
                }
              }
              else {
                fVar3 = (float)_DAT_00804a68;
                local_50 = (float)(local_48 & 0xffff) / fVar3;
                local_30 = (float)(local_40 & 0xffff) / fVar3;
                local_2c = (float)(local_34 & 0xffff) / fVar3;
                local_44 = (float)(local_3c & 0xffff) / fVar3;
              }
            }
            else if (local_4ec._3_1_ == '\0') {
              if (8 < local_4ec._2_1_) {
                if (local_90c == '\0') {
                  local_48 = 0xffff;
                }
                else {
                  local_48 = ((((uint)fVar34 & local_904) >> (local_908 & 0x1f)) * 0xffff) /
                             (local_904 >> (local_908 & 0x1f)) & 0xffff;
                }
                if (cStack_90b == '\0') {
                  local_40 = 0xffff;
                }
                else {
                  local_40 = ((((uint)local_900 & (uint)fVar34) >> (local_907 & 0x1f)) * 0xffff) /
                             ((uint)local_900 >> (local_907 & 0x1f)) & 0xffff;
                }
                if (cStack_90a == '\0') {
                  local_34 = 0xffff;
                }
                else {
                  local_34 = (((local_8fc & (uint)fVar34) >> (local_906 & 0x1f)) * 0xffff) /
                             (local_8fc >> (local_906 & 0x1f)) & 0xffff;
                }
                if (cStack_909 == '\0') {
                  local_3c = 0xffff;
                }
                else {
                  local_3c = ((((uint)local_8f8 & (uint)fVar34) >> (local_905 & 0x1f)) * 0xffff) /
                             ((uint)local_8f8 >> (local_905 & 0x1f)) & 0xffff;
                }
              }
            }
            else {
              if (local_90c == '\0') {
                local_50 = 1.0;
              }
              else {
                uVar26 = ((uint)fVar34 & local_904) >> (local_908 & 0x1f);
                local_50 = (float)(int)uVar26;
                if ((int)uVar26 < 0) {
                  local_50 = local_50 + _DAT_007d4bd8;
                }
                uVar26 = local_904 >> (local_908 & 0x1f);
                fVar3 = (float)(int)uVar26;
                if ((int)uVar26 < 0) {
                  fVar3 = fVar3 + _DAT_007d4bd8;
                }
                local_50 = local_50 / fVar3;
              }
              local_44 = 1.0;
              local_30 = local_44;
              if (cStack_90b != '\0') {
                uVar26 = ((uint)local_900 & (uint)fVar34) >> (local_907 & 0x1f);
                fVar3 = (float)(int)uVar26;
                if ((int)uVar26 < 0) {
                  fVar3 = fVar3 + _DAT_007d4bd8;
                }
                uVar26 = (uint)local_900 >> (local_907 & 0x1f);
                fVar4 = (float)(int)uVar26;
                if ((int)uVar26 < 0) {
                  fVar4 = fVar4 + _DAT_007d4bd8;
                }
                local_30 = fVar3 / fVar4;
              }
              local_2c = local_44;
              if (cStack_90a != '\0') {
                uVar26 = (local_8fc & (uint)fVar34) >> (local_906 & 0x1f);
                fVar3 = (float)(int)uVar26;
                if ((int)uVar26 < 0) {
                  fVar3 = fVar3 + _DAT_007d4bd8;
                }
                uVar26 = local_8fc >> (local_906 & 0x1f);
                fVar4 = (float)(int)uVar26;
                if ((int)uVar26 < 0) {
                  fVar4 = fVar4 + _DAT_007d4bd8;
                }
                local_2c = fVar3 / fVar4;
              }
              if (cStack_909 != '\0') {
                uVar26 = ((uint)local_8f8 & (uint)fVar34) >> (local_905 & 0x1f);
                local_44 = (float)(int)uVar26;
                if ((int)uVar26 < 0) {
                  local_44 = local_44 + _DAT_007d4bd8;
                }
                uVar26 = (uint)local_8f8 >> (local_905 & 0x1f);
                fVar3 = (float)(int)uVar26;
                if ((int)uVar26 < 0) {
                  fVar3 = fVar3 + _DAT_007d4bd8;
                }
                local_44 = local_44 / fVar3;
              }
            }
          }
          else if (local_4ec._3_1_ == '\0') {
            if (local_4ec._2_1_ == 0x10) {
              local_48 = 0;
              local_40 = 0;
              local_34 = 0;
              local_3c = 0;
              if (local_50 <= 1.0) {
                if (0.0 < local_50) {
                  uVar26 = FUN_0050e270(local_50 * (float)_DAT_00804a68);
                  local_48 = uVar26 & 0xffff;
                }
              }
              else {
                local_48 = 0xffff;
              }
              if (local_30 <= 1.0) {
                if (0.0 < local_30) {
                  uVar26 = FUN_0050e270(local_30 * (float)_DAT_00804a68);
                  local_40 = uVar26 & 0xffff;
                }
              }
              else {
                local_40 = 0xffff;
              }
              if (local_2c <= 1.0) {
                if (0.0 < local_2c) {
                  uVar26 = FUN_0050e270(local_2c * (float)_DAT_00804a68);
                  local_34 = uVar26 & 0xffff;
                }
              }
              else {
                local_34 = 0xffff;
              }
              if (local_44 <= 1.0) {
                if (0.0 < local_44) {
                  uVar26 = FUN_0050e270(local_44 * (float)_DAT_00804a68);
                  local_3c = uVar26 & 0xffff;
                }
              }
              else {
                local_3c = 0xffff;
              }
            }
            else {
              fVar34 = 0.0;
              if (local_50 <= 1.0) {
                if (0.0 < local_50) {
                  iVar15 = FUN_0050e270(local_50 * (float)_DAT_0081ec30);
                  fVar34 = (float)(iVar15 << (local_908 & 0x1f));
                }
              }
              else {
                fVar34 = (float)(0xff << (local_908 & 0x1f));
              }
              if (local_30 <= 1.0) {
                if (0.0 < local_30) {
                  iVar15 = FUN_0050e270(local_30 * (float)_DAT_0081ec30);
                  fVar34 = (float)((uint)fVar34 | iVar15 << (local_907 & 0x1f));
                }
              }
              else {
                fVar34 = (float)((uint)fVar34 | 0xff << (local_907 & 0x1f));
              }
              if (local_2c <= 1.0) {
                if (0.0 < local_2c) {
                  iVar15 = FUN_0050e270(local_2c * (float)_DAT_0081ec30);
                  fVar34 = (float)((uint)fVar34 | iVar15 << (local_906 & 0x1f));
                }
              }
              else {
                fVar34 = (float)((uint)fVar34 | 0xff << (local_906 & 0x1f));
              }
              if (local_44 <= 1.0) {
                if (0.0 < local_44) {
                  iVar15 = FUN_0050e270(local_44 * (float)_DAT_0081ec30);
                  fVar34 = (float)((uint)fVar34 | iVar15 << (local_905 & 0x1f));
                }
              }
              else {
                fVar34 = (float)((uint)fVar34 | 0xff << (local_905 & 0x1f));
              }
            }
          }
          if (param_19 == 0) {
LAB_0054d9d9:
            if (local_24 == 1) {
              switch(local_e) {
              case 0:
                local_80 = (uint)(ushort)*local_4c;
                break;
              case 1:
                local_80 = (uint)(uint3)*local_4c;
                break;
              case 2:
                local_80 = *local_4c;
                break;
              case 3:
                local_80 = auStack_d14[(byte)*local_4c];
                break;
              default:
                goto switchD_0054d9e8_default;
              }
            }
switchD_0054d9e8_default:
            if (local_4ec._3_1_ == '\0') {
              local_1c = (uint *)(((uint)fVar34 & local_904) >> (local_908 & 0x1f));
              param_12 = (int *)(((uint)local_900 & (uint)fVar34) >> (local_907 & 0x1f));
              uVar11 = (local_8fc & (uint)fVar34) >> (local_906 & 0x1f);
              if ((local_4e1 == '\0') || (param_14 != 1)) {
                bVar14 = param_9._3_1_;
                if (local_24 == 1) {
                  puVar13 = (uint *)((local_80 & (uint)local_d2c) >> (local_d30 & 0x1f));
                  if (param_9._3_1_ != 0) {
                    if (-1 < (int)param_9) goto LAB_0054daf5;
                    local_78 = (int)puVar13 << (~param_9._3_1_ + 1 & 0x1f);
LAB_0054db85:
                    puVar13 = (uint *)(local_78 + (uint)((int)puVar13 * local_ac) / local_88);
                  }
                }
                else if (cStack_909 == '\0') {
                  puVar13 = local_4d0;
                  bVar14 = local_4dd;
LAB_0054daf5:
                  puVar13 = (uint *)((uint)puVar13 >> (bVar14 & 0x1f));
                }
                else if (local_4d0 == (uint *)0x0) {
                  puVar13 = (uint *)0x0;
                }
                else {
                  puVar13 = (uint *)(((uint)local_8f8 & (uint)fVar34) >> (local_905 & 0x1f));
                  if (param_9._3_1_ != 0) {
                    if ((int)param_9 < 0) {
                      local_78 = (int)puVar13 << (~param_9._3_1_ + 1 & 0x1f);
                      goto LAB_0054db85;
                    }
                    goto LAB_0054daf5;
                  }
                }
                if (param_18 != 0) {
                  puVar13 = local_1c;
                }
              }
              else if (((local_1c == local_9c) && (param_12 == (int *)local_a8)) &&
                      (uVar11 == local_94)) {
                puVar13 = (uint *)0x0;
              }
              else {
                puVar13 = (uint *)((uint)local_4d0 >> (local_4dd & 0x1f));
              }
              if ((local_1d != 0) && (local_a0 != 0)) {
                if ((char)local_1d < '\0') {
                  local_1c = (uint *)(((int)local_1c << (~local_1d + 1 & 0x1f)) +
                                     (uint)((int)local_1c * local_b8) / local_a0);
                }
                else {
                  local_1c = (uint *)((uint)local_1c >> (local_1d & 0x1f));
                }
              }
              if ((local_1e != 0) && (local_a4 != 0)) {
                if ((char)local_1e < '\0') {
                  param_12 = (int *)(((int)param_12 << (~local_1e + 1 & 0x1f)) +
                                    (uint)((int)param_12 * local_b4) / local_a4);
                }
                else {
                  param_12 = (int *)((uint)param_12 >> (local_1e & 0x1f));
                }
              }
              if ((local_15 != 0) && (local_98 != 0)) {
                if ((char)local_15 < '\0') {
                  uVar11 = (uVar11 << (~local_15 + 1 & 0x1f)) + (uVar11 * local_bc) / local_98;
                }
                else {
                  uVar11 = uVar11 >> (local_15 & 0x1f);
                }
              }
              puVar39 = local_1c;
              if (param_17 != 0) {
                puVar39 = (uint *)0x0;
                uVar11 = 0;
                param_12 = (int *)0x0;
              }
              uVar11 = (int)puVar13 << (local_4dd & 0x1f) | uVar11 << (local_4de & 0x1f) |
                       (int)param_12 << (local_4df & 0x1f) | (int)puVar39 << (local_4e0 & 0x1f);
              local_28 = uVar11;
              pfVar36 = local_5c;
            }
            if (local_d != '\0') {
              param_12 = (int *)(uVar11 & local_4dc);
              puVar13 = (uint *)((uint)local_4d8 & uVar11);
              uVar26 = local_4d4 & uVar11;
              puVar39 = (uint *)((uint)local_4d0 & uVar11);
              local_1c = puVar13;
              if (param_16 == 1) {
                iVar15 = ((uint)local_60 & 3) + ((uint)local_14 & 3) * 4;
                iVar38 = (uint)(auStack_dbc[iVar15] < (local_7c & (uint)fVar34)) <<
                         (local_4e0 & 0x1f);
                puVar13 = (uint *)((int)puVar13 +
                                  ((uint)(auStack_dfc[iVar15] < (local_84 & (uint)fVar34)) <<
                                  (local_4df & 0x1f)));
                local_1c = puVar13;
                iVar27 = (uint)(auStack_d7c[iVar15] < (local_74 & (uint)fVar34)) <<
                         (local_4de & 0x1f);
                iVar15 = (uint)(auStack_e3c[iVar15] < ((uint)local_38 & (uint)fVar34)) <<
                         (local_4dd & 0x1f);
LAB_0054ddcc:
                param_12 = (int *)((int)param_12 + iVar38);
                uVar26 = uVar26 + iVar27;
                puVar39 = (uint *)((int)puVar39 + iVar15);
              }
              else if (param_16 == 2) {
                local_58 = local_58 + (local_7c & (uint)fVar34);
                local_68 = local_68 + (local_84 & (uint)fVar34);
                local_6c = local_6c + (local_74 & (uint)fVar34);
                local_64 = local_64 + ((uint)local_38 & (uint)fVar34);
                iVar38 = (uint)(local_7c < local_58) << (local_4e0 & 0x1f);
                puVar13 = (uint *)((int)puVar13 +
                                  ((uint)(local_84 < local_68) << (local_4df & 0x1f)));
                iVar27 = (uint)(local_74 < local_6c) << (local_4de & 0x1f);
                iVar15 = (uint)(local_38 < local_64) << (local_4dd & 0x1f);
                local_58 = local_58 & local_7c;
                local_68 = local_68 & local_84;
                local_6c = local_6c & local_74;
                local_64 = local_64 & (uint)local_38;
                goto LAB_0054ddcc;
              }
              if (local_4dc < param_12) {
                param_12 = (int *)local_4dc;
              }
              if (local_4d8 < puVar13) {
                puVar13 = local_4d8;
              }
              if (local_4d4 < uVar26) {
                uVar26 = local_4d4;
              }
              if (local_4d0 < puVar39) {
                puVar39 = local_4d0;
              }
              uVar11 = local_28 & local_b0 | (uint)puVar39 | uVar26 | (uint)puVar13 | (uint)param_12
              ;
              local_28 = uVar11;
              pfVar36 = local_5c;
            }
            switch((uint)param_6 >> 0x18) {
            case 0:
              *(ushort *)pfVar36 = (ushort)local_4cc | (ushort)uVar11;
              break;
            case 1:
              *(ushort *)pfVar36 = (ushort)uVar11;
              *(char *)((int)pfVar36 + 2) = (char)(uVar11 >> 0x10);
              break;
            case 2:
              *pfVar36 = (float)(local_4cc | uVar11);
              break;
            case 3:
              *(char *)pfVar36 = (char)uVar11;
              break;
            case 4:
              *pfVar36 = local_50;
              if (1 < local_4ec._1_1_) {
                pfVar36[1] = local_30;
              }
              if (2 < local_4ec._1_1_) {
                pfVar36[2] = local_2c;
              }
              if (3 < local_4ec._1_1_) {
                pfVar36[3] = local_44;
              }
              break;
            case 5:
              uVar10 = FUN_00540880(local_50);
              *(undefined2 *)pfVar36 = uVar10;
              if (1 < local_4ec._1_1_) {
                uVar10 = FUN_00540880(local_30);
                *(undefined2 *)((int)pfVar36 + 2) = uVar10;
              }
              if (2 < local_4ec._1_1_) {
                uVar10 = FUN_00540880(local_2c);
                *(undefined2 *)(pfVar36 + 1) = uVar10;
              }
              if (3 < local_4ec._1_1_) {
                uVar10 = FUN_00540880(local_44);
                *(undefined2 *)((int)pfVar36 + 6) = uVar10;
              }
              break;
            case 6:
              *(undefined2 *)pfVar36 = (undefined2)local_48;
              if (1 < local_4ec._1_1_) {
                *(undefined2 *)((int)pfVar36 + 2) = (undefined2)local_40;
              }
              if (2 < local_4ec._1_1_) {
                *(undefined2 *)(pfVar36 + 1) = (undefined2)local_34;
              }
              if (3 < local_4ec._1_1_) {
                *(undefined2 *)((int)pfVar36 + 6) = (undefined2)local_3c;
              }
            }
          }
          else {
            fVar3 = fVar34;
            if (bVar21 != 3) {
              fVar3 = (float)((uint)fVar34 & local_c4);
            }
            if (fVar3 != param_15) goto LAB_0054d9d9;
          }
          param_13 = (float *)((int)param_13 + (uint)local_910);
          local_5c = (float *)((int)pfVar36 + local_90);
          local_4c = (uint *)((int)local_4c + (uint)local_d38);
          local_60 = (uint *)((int)local_60 + 1);
        } while ((int)local_60 < (int)local_c);
      }
      param_13 = (float *)((int)param_13 + local_70);
      local_4c = (uint *)((int)local_4c + (int)local_54);
      local_14 = (float *)((int)local_14 + 1);
      local_5c = (float *)((int)local_5c + local_8c);
    } while ((int)local_14 < local_8);
  }
  return 0;
}

