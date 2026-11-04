
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00586e60(int *param_1,int param_2,float param_3)

{
  float *pfVar1;
  float fVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  undefined4 *puVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint *puVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  uint uVar46;
  uint uVar47;
  uint uVar48;
  uint uVar49;
  uint uVar50;
  uint uVar51;
  uint uVar52;
  uint uVar53;
  uint uVar54;
  uint uVar55;
  uint uVar56;
  uint uVar57;
  uint uVar58;
  uint uVar59;
  uint uVar60;
  uint *puVar61;
  uint uVar62;
  uint uVar63;
  uint uVar64;
  uint uVar65;
  int iVar66;
  int iVar67;
  float10 fVar68;
  uint local_5fc;
  uint *local_5f8;
  uint *local_5f4;
  uint local_5f0;
  uint local_5ec;
  uint *local_5e8;
  uint *local_5e4;
  uint local_5dc;
  uint local_5d8;
  uint local_5d4;
  uint local_5cc;
  uint local_5c8;
  uint local_5bc;
  uint local_5b8;
  uint local_5ac;
  uint local_5a8;
  uint local_59c;
  uint local_598;
  uint local_58c;
  uint local_588;
  uint local_57c;
  uint local_578;
  uint local_56c;
  uint local_568;
  uint local_55c;
  uint local_558;
  uint local_54c;
  uint local_548;
  uint local_53c;
  uint local_538;
  uint local_52c;
  uint local_528;
  uint local_51c;
  uint local_518;
  uint local_510;
  uint local_500;
  float local_4e0;
  uint *local_4dc;
  float local_4d4;
  int local_4d0 [4];
  int local_4c0;
  int local_4bc;
  int local_4b8;
  int local_4b4;
  int local_4b0;
  int local_4ac;
  int local_4a8;
  int local_4a4;
  int local_4a0;
  int local_49c;
  int local_498;
  int local_494;
  int local_490;
  int local_48c;
  uint local_488;
  uint *local_484;
  uint local_480;
  uint local_47c;
  uint *local_478;
  uint local_474;
  uint local_470;
  uint local_46c;
  uint local_468;
  uint local_464;
  uint local_460;
  uint local_45c;
  uint local_458;
  uint local_454;
  int local_450;
  int local_44c;
  int local_448;
  int local_444;
  undefined1 local_440 [1072];
  int local_10;
  uint *local_c;
  
  if (param_2 < 9) {
    iVar21 = 8;
  }
  else {
    iVar21 = ((0x10 < param_2) - 1 & 0xfffffff0) + 0x20;
  }
  uVar62 = iVar21 / 2;
  if ((((float)_DAT_007d9bd0 < _DAT_0085e578 - param_3) ||
      (_DAT_0085e578 - param_3 < (float)_DAT_007d9bc8)) || (DAT_00ddae98 != iVar21)) {
    local_4e0 = param_3;
    if (param_3 < (float)_DAT_007d56c8) {
      local_4e0 = _DAT_007d9a88;
    }
    _DAT_0085e578 = param_3;
    iVar66 = 0;
    local_4d4 = 0.0;
    DAT_00ddae98 = iVar21;
    if (0 < (int)uVar62) {
      do {
        fVar68 = (float10)FUN_0056d530(((float)(iVar66 * iVar66) * (float)_DAT_007d9b88) / local_4e0
                                      );
        fVar2 = (float)fVar68;
        (&DAT_00ddae58)[iVar66] = fVar2;
        if (iVar66 != 0) {
          fVar2 = fVar2 + fVar2;
        }
        local_4d4 = fVar2 + local_4d4;
        iVar66 = iVar66 + 1;
      } while (iVar66 < (int)uVar62);
    }
    iVar66 = 0;
    if (3 < (int)uVar62) {
      do {
        pfVar1 = (float *)(&DAT_00ddae58 + iVar66);
        iVar66 = iVar66 + 4;
        *(float *)(iVar66 * 4 + 0xddae48) = *pfVar1 / local_4d4;
        *(float *)(iVar66 * 4 + 0xddae4c) = *(float *)(iVar66 * 4 + 0xddae4c) / local_4d4;
        *(float *)(iVar66 * 4 + 0xddae50) = *(float *)(iVar66 * 4 + 0xddae50) / local_4d4;
        *(float *)(iVar66 * 4 + 0xddae54) = *(float *)(iVar66 * 4 + 0xddae54) / local_4d4;
      } while (iVar66 < (int)(uVar62 - 3));
    }
    while (iVar66 < (int)uVar62) {
      pfVar1 = (float *)(&DAT_00ddae58 + iVar66);
      iVar66 = iVar66 + 1;
      *(float *)(iVar66 * 4 + 0xddae54) = *pfVar1 / local_4d4;
    }
  }
  if (DAT_00a37dc8 == 1) {
    FUN_005db7d0(param_1,iVar21,param_3,&DAT_00ddae58);
    return 0;
  }
  uVar22 = 0;
  if (uVar62 != 0) {
    do {
      local_4d0[uVar22] = (int)ROUND((float)(&DAT_00ddae58)[uVar22] * (float)_DAT_007d5fe0);
      uVar22 = uVar22 + 1;
    } while (uVar22 < uVar62);
  }
  local_448 = param_1[10];
  local_444 = param_1[0xb];
  local_450 = param_1[8];
  local_5ec = local_444 - param_1[9];
  uVar62 = local_448 - local_450;
  param_1[0x15] = local_5ec;
  local_44c = param_1[9];
  param_1[0x14] = uVar62;
  param_1[0x123] = 0;
  param_1[0x233] = 0;
  param_1[0x343] = 0;
  iVar66 = FUN_005866a0(param_1[2],param_1 + 0x16,&local_450);
  if (((iVar66 < 0) ||
      ((*param_1 != 0 && (iVar66 = FUN_005866a0(param_1[3],param_1 + 0x126,&local_450), iVar66 < 0))
      )) || (iVar66 = FUN_00546c90(param_1[0x14],param_1[0x15],param_1 + 0x236), iVar66 < 0)) {
    if (param_1[0x123] != 0) {
      FUN_005421c0(param_1 + 0x16);
    }
    if (param_1[0x233] != 0) {
      FUN_005421c0(param_1 + 0x126);
    }
    if (param_1[0x343] != 0) {
      FUN_005421c0(param_1 + 0x236);
    }
    return 0xffffffff;
  }
  if (param_3 < (float)_DAT_007d5348) {
    iVar21 = param_1[0x122];
    puVar3 = (undefined4 *)param_1[0x123];
    puVar23 = (undefined4 *)param_1[0x343];
    local_490 = param_1[0x342] + uVar62 * -4;
    do {
      uVar22 = uVar62;
      do {
        *puVar23 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar23 = puVar23 + 1;
        uVar22 = uVar22 - 1;
      } while (uVar22 != 0);
      puVar23 = (undefined4 *)((int)puVar23 + local_490);
      puVar3 = (undefined4 *)((int)puVar3 + iVar21 + uVar62 * -4);
      local_5ec = local_5ec - 1;
    } while (local_5ec != 0);
    FUN_00586b00();
    return 0;
  }
  iVar66 = FUN_00546c90(uVar62,local_5ec,local_440);
  if (-1 < iVar66) {
    local_5e4 = (uint *)param_1[0x123];
    local_5e8 = local_c;
    iVar66 = param_1[0x122] + uVar62 * -4;
    iVar67 = local_10 + uVar62 * -4;
    local_4e0 = (float)local_5ec;
    if (iVar21 == 8) {
      if (local_5ec != 0) {
        do {
          puVar61 = local_5e4;
          puVar36 = local_5e4 + (uVar62 - 1);
          local_4dc = (uint *)0x0;
          if (uVar62 != 0) {
            do {
              uVar22 = *local_5e4;
              if (local_4dc == (uint *)0x0) {
                uVar17 = *puVar61;
              }
              else {
                uVar17 = local_5e4[-1];
              }
              if (local_4dc < 2) {
                uVar18 = *puVar61;
              }
              else {
                uVar18 = local_5e4[-2];
              }
              if ((int)local_4dc + 1U < uVar62) {
                uVar20 = local_5e4[1];
              }
              else {
                uVar20 = *puVar36;
              }
              if ((int)local_4dc + 2U < uVar62) {
                uVar19 = local_5e4[2];
              }
              else {
                uVar19 = *puVar36;
              }
              if (local_4dc < 3) {
                uVar37 = *puVar61;
              }
              else {
                uVar37 = local_5e4[-3];
              }
              if (local_4dc < 4) {
                uVar38 = *puVar61;
              }
              else {
                uVar38 = local_5e4[-4];
              }
              if ((int)local_4dc + 3U < uVar62) {
                uVar39 = local_5e4[3];
              }
              else {
                uVar39 = *puVar36;
              }
              if ((int)local_4dc + 4U < uVar62) {
                uVar40 = local_5e4[4];
              }
              else {
                uVar40 = *puVar36;
              }
              if (local_4dc < 5) {
                uVar41 = *puVar61;
              }
              else {
                uVar41 = local_5e4[-5];
              }
              if (local_4dc < 6) {
                uVar25 = *puVar61;
              }
              else {
                uVar25 = local_5e4[-6];
              }
              if ((int)local_4dc + 5U < uVar62) {
                uVar28 = local_5e4[5];
              }
              else {
                uVar28 = *puVar36;
              }
              if ((int)local_4dc + 6U < uVar62) {
                uVar26 = local_5e4[6];
              }
              else {
                uVar26 = *puVar36;
              }
              *(char *)local_5e8 =
                   (char)(((int)(((uVar26 & 0xff) + (uVar28 & 0xff) + (uVar25 & 0xff) +
                                 (uVar41 & 0xff)) * local_4d0[3] +
                                 ((uVar40 & 0xff) + (uVar39 & 0xff) + (uVar38 & 0xff) +
                                 (uVar37 & 0xff)) * local_4d0[2] +
                                ((uVar19 & 0xff) + (uVar20 & 0xff) + (uVar18 & 0xff) +
                                (uVar17 & 0xff)) * local_4d0[1]) >> 1) +
                          (uVar22 & 0xff) * local_4d0[0] >> 0x10);
              *(char *)((int)local_5e8 + 1) =
                   (char)(((int)(((uVar19 >> 8 & 0xff) + (uVar20 >> 8 & 0xff) + (uVar18 >> 8 & 0xff)
                                 + (uVar17 >> 8 & 0xff)) * local_4d0[1] +
                                 ((uVar40 >> 8 & 0xff) + (uVar39 >> 8 & 0xff) + (uVar38 >> 8 & 0xff)
                                 + (uVar37 >> 8 & 0xff)) * local_4d0[2] +
                                ((uVar26 >> 8 & 0xff) + (uVar28 >> 8 & 0xff) + (uVar25 >> 8 & 0xff)
                                + (uVar41 >> 8 & 0xff)) * local_4d0[3]) >> 1) +
                          (uVar22 >> 8 & 0xff) * local_4d0[0] >> 0x10);
              *(char *)((int)local_5e8 + 2) =
                   (char)(((int)(((uVar19 >> 0x10 & 0xff) + (uVar20 >> 0x10 & 0xff) +
                                  (uVar18 >> 0x10 & 0xff) + (uVar17 >> 0x10 & 0xff)) * local_4d0[1]
                                 + ((uVar40 >> 0x10 & 0xff) + (uVar39 >> 0x10 & 0xff) +
                                    (uVar38 >> 0x10 & 0xff) + (uVar37 >> 0x10 & 0xff)) *
                                   local_4d0[2] +
                                ((uVar26 >> 0x10 & 0xff) + (uVar28 >> 0x10 & 0xff) +
                                 (uVar25 >> 0x10 & 0xff) + (uVar41 >> 0x10 & 0xff)) * local_4d0[3])
                          >> 1) + (uVar22 >> 0x10 & 0xff) * local_4d0[0] >> 0x10);
              *(char *)((int)local_5e8 + 3) =
                   (char)(((int)(((uVar19 >> 0x18) + (uVar20 >> 0x18) + (uVar18 >> 0x18) +
                                 (uVar17 >> 0x18)) * local_4d0[1] +
                                 ((uVar40 >> 0x18) + (uVar39 >> 0x18) + (uVar38 >> 0x18) +
                                 (uVar37 >> 0x18)) * local_4d0[2] +
                                ((uVar26 >> 0x18) + (uVar28 >> 0x18) + (uVar25 >> 0x18) +
                                (uVar41 >> 0x18)) * local_4d0[3]) >> 1) +
                          (uVar22 >> 0x18) * local_4d0[0] >> 0x10);
              local_5e8 = local_5e8 + 1;
              local_4dc = (uint *)((int)local_4dc + 1);
              local_5e4 = local_5e4 + 1;
            } while (local_4dc < uVar62);
          }
          local_5e8 = (uint *)((int)local_5e8 + iVar67);
          local_5e4 = (uint *)((int)local_5e4 + iVar66);
          local_4e0 = (float)((int)local_4e0 - 1);
        } while (local_4e0 != 0.0);
      }
    }
    else if (iVar21 == 0x10) {
      if (local_5ec != 0) {
        do {
          puVar61 = local_5e4;
          puVar36 = local_5e4 + (uVar62 - 1);
          local_4dc = (uint *)0x0;
          if (uVar62 != 0) {
            do {
              uVar22 = *local_5e4;
              if (local_4dc == (uint *)0x0) {
                uVar17 = *puVar61;
              }
              else {
                uVar17 = local_5e4[-1];
              }
              if (local_4dc < 2) {
                uVar18 = *puVar61;
              }
              else {
                uVar18 = local_5e4[-2];
              }
              if ((int)local_4dc + 1U < uVar62) {
                uVar20 = local_5e4[1];
              }
              else {
                uVar20 = *puVar36;
              }
              if ((int)local_4dc + 2U < uVar62) {
                uVar19 = local_5e4[2];
              }
              else {
                uVar19 = *puVar36;
              }
              if (local_4dc < 3) {
                uVar37 = *puVar61;
              }
              else {
                uVar37 = local_5e4[-3];
              }
              if (local_4dc < 4) {
                uVar38 = *puVar61;
              }
              else {
                uVar38 = local_5e4[-4];
              }
              if ((int)local_4dc + 3U < uVar62) {
                uVar39 = local_5e4[3];
              }
              else {
                uVar39 = *puVar36;
              }
              if ((int)local_4dc + 4U < uVar62) {
                uVar40 = local_5e4[4];
              }
              else {
                uVar40 = *puVar36;
              }
              if (local_4dc < 5) {
                uVar41 = *puVar61;
              }
              else {
                uVar41 = local_5e4[-5];
              }
              if (local_4dc < 6) {
                uVar25 = *puVar61;
              }
              else {
                uVar25 = local_5e4[-6];
              }
              if ((int)local_4dc + 5U < uVar62) {
                uVar28 = local_5e4[5];
              }
              else {
                uVar28 = *puVar36;
              }
              if ((int)local_4dc + 6U < uVar62) {
                uVar26 = local_5e4[6];
              }
              else {
                uVar26 = *puVar36;
              }
              if (local_4dc < 7) {
                uVar42 = *puVar61;
              }
              else {
                uVar42 = local_5e4[-7];
              }
              if (local_4dc < 8) {
                uVar43 = *puVar61;
              }
              else {
                uVar43 = local_5e4[-8];
              }
              if ((int)local_4dc + 7U < uVar62) {
                uVar44 = local_5e4[7];
              }
              else {
                uVar44 = *puVar36;
              }
              if ((int)local_4dc + 8U < uVar62) {
                uVar45 = local_5e4[8];
              }
              else {
                uVar45 = *puVar36;
              }
              if (local_4dc < 9) {
                uVar46 = *puVar61;
              }
              else {
                uVar46 = local_5e4[-9];
              }
              if (local_4dc < 10) {
                uVar47 = *puVar61;
              }
              else {
                uVar47 = local_5e4[-10];
              }
              if ((int)local_4dc + 9U < uVar62) {
                uVar48 = local_5e4[9];
              }
              else {
                uVar48 = *puVar36;
              }
              if ((int)local_4dc + 10U < uVar62) {
                uVar49 = local_5e4[10];
              }
              else {
                uVar49 = *puVar36;
              }
              if (local_4dc < 0xb) {
                uVar50 = *puVar61;
              }
              else {
                uVar50 = local_5e4[-0xb];
              }
              if (local_4dc < 0xc) {
                uVar51 = *puVar61;
              }
              else {
                uVar51 = local_5e4[-0xc];
              }
              if ((int)local_4dc + 0xbU < uVar62) {
                uVar52 = local_5e4[0xb];
              }
              else {
                uVar52 = *puVar36;
              }
              if ((int)local_4dc + 0xcU < uVar62) {
                uVar53 = local_5e4[0xc];
              }
              else {
                uVar53 = *puVar36;
              }
              if (local_4dc < 0xd) {
                uVar54 = *puVar61;
              }
              else {
                uVar54 = local_5e4[-0xd];
              }
              if (local_4dc < 0xe) {
                uVar16 = *puVar61;
              }
              else {
                uVar16 = local_5e4[-0xe];
              }
              if ((int)local_4dc + 0xdU < uVar62) {
                uVar27 = local_5e4[0xd];
              }
              else {
                uVar27 = *puVar36;
              }
              if ((int)local_4dc + 0xeU < uVar62) {
                uVar24 = local_5e4[0xe];
              }
              else {
                uVar24 = *puVar36;
              }
              *(char *)local_5e8 =
                   (char)(((int)(((uVar24 & 0xff) + (uVar27 & 0xff) + (uVar16 & 0xff) +
                                 (uVar54 & 0xff)) * local_4b4 +
                                 ((uVar26 & 0xff) + (uVar28 & 0xff) + (uVar25 & 0xff) +
                                 (uVar41 & 0xff)) * local_4d0[3] +
                                 ((uVar53 & 0xff) + (uVar52 & 0xff) + (uVar51 & 0xff) +
                                 (uVar50 & 0xff)) * local_4b8 +
                                 ((uVar40 & 0xff) + (uVar39 & 0xff) + (uVar38 & 0xff) +
                                 (uVar37 & 0xff)) * local_4d0[2] +
                                 ((uVar49 & 0xff) + (uVar48 & 0xff) + (uVar47 & 0xff) +
                                 (uVar46 & 0xff)) * local_4bc +
                                 ((uVar19 & 0xff) + (uVar20 & 0xff) + (uVar18 & 0xff) +
                                 (uVar17 & 0xff)) * local_4d0[1] +
                                ((uVar45 & 0xff) + (uVar44 & 0xff) + (uVar43 & 0xff) +
                                (uVar42 & 0xff)) * local_4c0) >> 1) + (uVar22 & 0xff) * local_4d0[0]
                         >> 0x10);
              *(char *)((int)local_5e8 + 1) =
                   (char)(((int)(((uVar19 >> 8 & 0xff) + (uVar20 >> 8 & 0xff) + (uVar18 >> 8 & 0xff)
                                 + (uVar17 >> 8 & 0xff)) * local_4d0[1] +
                                 ((uVar24 >> 8 & 0xff) + (uVar27 >> 8 & 0xff) + (uVar16 >> 8 & 0xff)
                                 + (uVar54 >> 8 & 0xff)) * local_4b4 +
                                 ((uVar45 >> 8 & 0xff) + (uVar44 >> 8 & 0xff) + (uVar43 >> 8 & 0xff)
                                 + (uVar42 >> 8 & 0xff)) * local_4c0 +
                                 ((uVar40 >> 8 & 0xff) + (uVar39 >> 8 & 0xff) + (uVar38 >> 8 & 0xff)
                                 + (uVar37 >> 8 & 0xff)) * local_4d0[2] +
                                 ((uVar26 >> 8 & 0xff) + (uVar28 >> 8 & 0xff) + (uVar25 >> 8 & 0xff)
                                 + (uVar41 >> 8 & 0xff)) * local_4d0[3] +
                                 ((uVar53 >> 8 & 0xff) + (uVar52 >> 8 & 0xff) + (uVar51 >> 8 & 0xff)
                                 + (uVar50 >> 8 & 0xff)) * local_4b8 +
                                ((uVar49 >> 8 & 0xff) + (uVar48 >> 8 & 0xff) + (uVar47 >> 8 & 0xff)
                                + (uVar46 >> 8 & 0xff)) * local_4bc) >> 1) +
                          (uVar22 >> 8 & 0xff) * local_4d0[0] >> 0x10);
              *(char *)((int)local_5e8 + 2) =
                   (char)(((int)(((uVar19 >> 0x10 & 0xff) + (uVar20 >> 0x10 & 0xff) +
                                  (uVar18 >> 0x10 & 0xff) + (uVar17 >> 0x10 & 0xff)) * local_4d0[1]
                                 + ((uVar24 >> 0x10 & 0xff) + (uVar27 >> 0x10 & 0xff) +
                                    (uVar16 >> 0x10 & 0xff) + (uVar54 >> 0x10 & 0xff)) * local_4b4 +
                                 ((uVar45 >> 0x10 & 0xff) + (uVar44 >> 0x10 & 0xff) +
                                  (uVar43 >> 0x10 & 0xff) + (uVar42 >> 0x10 & 0xff)) * local_4c0 +
                                 ((uVar40 >> 0x10 & 0xff) + (uVar39 >> 0x10 & 0xff) +
                                  (uVar38 >> 0x10 & 0xff) + (uVar37 >> 0x10 & 0xff)) * local_4d0[2]
                                 + ((uVar26 >> 0x10 & 0xff) + (uVar28 >> 0x10 & 0xff) +
                                    (uVar25 >> 0x10 & 0xff) + (uVar41 >> 0x10 & 0xff)) *
                                   local_4d0[3] +
                                 ((uVar53 >> 0x10 & 0xff) + (uVar52 >> 0x10 & 0xff) +
                                  (uVar51 >> 0x10 & 0xff) + (uVar50 >> 0x10 & 0xff)) * local_4b8 +
                                ((uVar49 >> 0x10 & 0xff) + (uVar48 >> 0x10 & 0xff) +
                                 (uVar47 >> 0x10 & 0xff) + (uVar46 >> 0x10 & 0xff)) * local_4bc) >>
                          1) + (uVar22 >> 0x10 & 0xff) * local_4d0[0] >> 0x10);
              local_4dc = (uint *)((int)local_4dc + 1);
              *(char *)((int)local_5e8 + 3) =
                   (char)(((int)(((uVar19 >> 0x18) + (uVar20 >> 0x18) + (uVar18 >> 0x18) +
                                 (uVar17 >> 0x18)) * local_4d0[1] +
                                 ((uVar24 >> 0x18) + (uVar27 >> 0x18) + (uVar16 >> 0x18) +
                                 (uVar54 >> 0x18)) * local_4b4 +
                                 ((uVar45 >> 0x18) + (uVar44 >> 0x18) + (uVar43 >> 0x18) +
                                 (uVar42 >> 0x18)) * local_4c0 +
                                 ((uVar40 >> 0x18) + (uVar39 >> 0x18) + (uVar38 >> 0x18) +
                                 (uVar37 >> 0x18)) * local_4d0[2] +
                                 ((uVar26 >> 0x18) + (uVar28 >> 0x18) + (uVar25 >> 0x18) +
                                 (uVar41 >> 0x18)) * local_4d0[3] +
                                 ((uVar53 >> 0x18) + (uVar52 >> 0x18) + (uVar51 >> 0x18) +
                                 (uVar50 >> 0x18)) * local_4b8 +
                                ((uVar49 >> 0x18) + (uVar48 >> 0x18) + (uVar47 >> 0x18) +
                                (uVar46 >> 0x18)) * local_4bc) >> 1) +
                          (uVar22 >> 0x18) * local_4d0[0] >> 0x10);
              local_5e4 = local_5e4 + 1;
              local_5e8 = local_5e8 + 1;
            } while (local_4dc < uVar62);
          }
          local_5e8 = (uint *)((int)local_5e8 + iVar67);
          local_5e4 = (uint *)((int)local_5e4 + iVar66);
          local_4e0 = (float)((int)local_4e0 - 1);
        } while (local_4e0 != 0.0);
      }
    }
    else if ((iVar21 == 0x20) && (local_5f0 = 0, local_5ec != 0)) {
      do {
        puVar61 = local_5e4;
        puVar36 = local_5e4 + (uVar62 - 1);
        uVar22 = 0;
        if (uVar62 != 0) {
          do {
            uVar17 = *local_5e4;
            if (uVar22 == 0) {
              local_5dc = *puVar61;
            }
            else {
              local_5dc = local_5e4[-1];
            }
            if (uVar22 < 2) {
              local_5d8 = *puVar61;
            }
            else {
              local_5d8 = local_5e4[-2];
            }
            uVar18 = uVar22 + 1;
            if (uVar18 < uVar62) {
              local_5d4 = local_5e4[1];
            }
            else {
              local_5d4 = *puVar36;
            }
            if (uVar22 + 2 < uVar62) {
              uVar20 = local_5e4[2];
            }
            else {
              uVar20 = *puVar36;
            }
            if (uVar22 < 3) {
              uVar19 = *puVar61;
            }
            else {
              uVar19 = local_5e4[-3];
            }
            if (uVar22 < 4) {
              uVar37 = *puVar61;
            }
            else {
              uVar37 = local_5e4[-4];
            }
            if (uVar22 + 3 < uVar62) {
              uVar38 = local_5e4[3];
            }
            else {
              uVar38 = *puVar36;
            }
            if (uVar22 + 4 < uVar62) {
              uVar39 = local_5e4[4];
            }
            else {
              uVar39 = *puVar36;
            }
            if (uVar22 < 5) {
              uVar40 = *puVar61;
            }
            else {
              uVar40 = local_5e4[-5];
            }
            if (uVar22 < 6) {
              uVar41 = *puVar61;
            }
            else {
              uVar41 = local_5e4[-6];
            }
            if (uVar22 + 5 < uVar62) {
              uVar25 = local_5e4[5];
            }
            else {
              uVar25 = *puVar36;
            }
            if (uVar22 + 6 < uVar62) {
              uVar28 = local_5e4[6];
            }
            else {
              uVar28 = *puVar36;
            }
            if (uVar22 < 7) {
              uVar26 = *puVar61;
            }
            else {
              uVar26 = local_5e4[-7];
            }
            if (uVar22 < 8) {
              uVar42 = *puVar61;
            }
            else {
              uVar42 = local_5e4[-8];
            }
            if (uVar22 + 7 < uVar62) {
              uVar43 = local_5e4[7];
            }
            else {
              uVar43 = *puVar36;
            }
            if (uVar22 + 8 < uVar62) {
              uVar44 = local_5e4[8];
            }
            else {
              uVar44 = *puVar36;
            }
            if (uVar22 < 9) {
              uVar45 = *puVar61;
            }
            else {
              uVar45 = local_5e4[-9];
            }
            if (uVar22 < 10) {
              uVar46 = *puVar61;
            }
            else {
              uVar46 = local_5e4[-10];
            }
            if (uVar22 + 9 < uVar62) {
              uVar47 = local_5e4[9];
            }
            else {
              uVar47 = *puVar36;
            }
            if (uVar22 + 10 < uVar62) {
              uVar48 = local_5e4[10];
            }
            else {
              uVar48 = *puVar36;
            }
            if (uVar22 < 0xb) {
              uVar49 = *puVar61;
            }
            else {
              uVar49 = local_5e4[-0xb];
            }
            if (uVar22 < 0xc) {
              uVar50 = *puVar61;
            }
            else {
              uVar50 = local_5e4[-0xc];
            }
            if (uVar22 + 0xb < uVar62) {
              uVar51 = local_5e4[0xb];
            }
            else {
              uVar51 = *puVar36;
            }
            if (uVar22 + 0xc < uVar62) {
              uVar52 = local_5e4[0xc];
            }
            else {
              uVar52 = *puVar36;
            }
            if (uVar22 < 0xd) {
              uVar53 = *puVar61;
            }
            else {
              uVar53 = local_5e4[-0xd];
            }
            if (uVar22 < 0xe) {
              uVar54 = *puVar61;
            }
            else {
              uVar54 = local_5e4[-0xe];
            }
            if (uVar22 + 0xd < uVar62) {
              uVar16 = local_5e4[0xd];
            }
            else {
              uVar16 = *puVar36;
            }
            if (uVar22 + 0xe < uVar62) {
              uVar27 = local_5e4[0xe];
            }
            else {
              uVar27 = *puVar36;
            }
            if (uVar22 < 0xf) {
              uVar24 = *puVar61;
            }
            else {
              uVar24 = local_5e4[-0xf];
            }
            if (uVar22 < 0x10) {
              uVar29 = *puVar61;
            }
            else {
              uVar29 = local_5e4[-0x10];
            }
            if (uVar22 + 0xf < uVar62) {
              uVar30 = local_5e4[0xf];
            }
            else {
              uVar30 = *puVar36;
            }
            if (uVar22 + 0x10 < uVar62) {
              uVar31 = local_5e4[0x10];
            }
            else {
              uVar31 = *puVar36;
            }
            if (uVar22 < 0x11) {
              uVar32 = *puVar61;
            }
            else {
              uVar32 = local_5e4[-0x11];
            }
            if (uVar22 < 0x12) {
              uVar33 = *puVar61;
            }
            else {
              uVar33 = local_5e4[-0x12];
            }
            if (uVar22 + 0x11 < uVar62) {
              uVar34 = local_5e4[0x11];
            }
            else {
              uVar34 = *puVar36;
            }
            if (uVar22 + 0x12 < uVar62) {
              uVar35 = local_5e4[0x12];
            }
            else {
              uVar35 = *puVar36;
            }
            if (uVar22 < 0x13) {
              uVar4 = *puVar61;
            }
            else {
              uVar4 = local_5e4[-0x13];
            }
            if (uVar22 < 0x14) {
              uVar5 = *puVar61;
            }
            else {
              uVar5 = local_5e4[-0x14];
            }
            if (uVar22 + 0x13 < uVar62) {
              uVar6 = local_5e4[0x13];
            }
            else {
              uVar6 = *puVar36;
            }
            if (uVar22 + 0x14 < uVar62) {
              uVar7 = local_5e4[0x14];
            }
            else {
              uVar7 = *puVar36;
            }
            if (uVar22 < 0x15) {
              uVar8 = *puVar61;
            }
            else {
              uVar8 = local_5e4[-0x15];
            }
            if (uVar22 < 0x16) {
              uVar9 = *puVar61;
            }
            else {
              uVar9 = local_5e4[-0x16];
            }
            if (uVar22 + 0x15 < uVar62) {
              uVar10 = local_5e4[0x15];
            }
            else {
              uVar10 = *puVar36;
            }
            if (uVar22 + 0x16 < uVar62) {
              uVar11 = local_5e4[0x16];
            }
            else {
              uVar11 = *puVar36;
            }
            if (uVar22 < 0x17) {
              uVar12 = *puVar61;
            }
            else {
              uVar12 = local_5e4[-0x17];
            }
            if (uVar22 < 0x18) {
              uVar13 = *puVar61;
            }
            else {
              uVar13 = local_5e4[-0x18];
            }
            if (uVar22 + 0x17 < uVar62) {
              uVar14 = local_5e4[0x17];
            }
            else {
              uVar14 = *puVar36;
            }
            if (uVar22 + 0x18 < uVar62) {
              uVar15 = local_5e4[0x18];
            }
            else {
              uVar15 = *puVar36;
            }
            if (uVar22 < 0x19) {
              uVar55 = *puVar61;
            }
            else {
              uVar55 = local_5e4[-0x19];
            }
            if (uVar22 < 0x1a) {
              uVar63 = *puVar61;
            }
            else {
              uVar63 = local_5e4[-0x1a];
            }
            if (uVar22 + 0x19 < uVar62) {
              uVar56 = local_5e4[0x19];
            }
            else {
              uVar56 = *puVar36;
            }
            if (uVar22 + 0x1a < uVar62) {
              local_510 = local_5e4[0x1a];
            }
            else {
              local_510 = *puVar36;
            }
            if (uVar22 < 0x1b) {
              uVar57 = *puVar61;
            }
            else {
              uVar57 = local_5e4[-0x1b];
            }
            if (uVar22 < 0x1c) {
              uVar64 = *puVar61;
            }
            else {
              uVar64 = local_5e4[-0x1c];
            }
            if (uVar22 + 0x1b < uVar62) {
              uVar58 = local_5e4[0x1b];
            }
            else {
              uVar58 = *puVar36;
            }
            if (uVar22 + 0x1c < uVar62) {
              local_500 = local_5e4[0x1c];
            }
            else {
              local_500 = *puVar36;
            }
            if (uVar22 < 0x1d) {
              uVar59 = *puVar61;
            }
            else {
              uVar59 = local_5e4[-0x1d];
            }
            if (uVar22 < 0x1e) {
              uVar65 = *puVar61;
            }
            else {
              uVar65 = local_5e4[-0x1e];
            }
            if (uVar22 + 0x1d < uVar62) {
              uVar60 = local_5e4[0x1d];
            }
            else {
              uVar60 = *puVar36;
            }
            if (uVar22 + 0x1e < uVar62) {
              uVar22 = local_5e4[0x1e];
            }
            else {
              uVar22 = *puVar36;
            }
            *(char *)local_5e8 =
                 (char)(((int)(((uVar35 & 0xff) + (uVar34 & 0xff) + (uVar33 & 0xff) +
                               (uVar32 & 0xff)) * local_4ac +
                               ((uVar31 & 0xff) + (uVar30 & 0xff) + (uVar29 & 0xff) +
                               (uVar24 & 0xff)) * local_4b0 +
                               ((uVar22 & 0xff) + (uVar60 & 0xff) + (uVar65 & 0xff) +
                               (uVar59 & 0xff)) * local_494 +
                               ((local_500 & 0xff) + (uVar58 & 0xff) + (uVar64 & 0xff) +
                               (uVar57 & 0xff)) * local_498 +
                               ((uVar27 & 0xff) + (uVar16 & 0xff) + (uVar54 & 0xff) +
                               (uVar53 & 0xff)) * local_4b4 +
                               ((local_510 & 0xff) + (uVar56 & 0xff) + (uVar63 & 0xff) +
                               (uVar55 & 0xff)) * local_49c +
                               ((uVar15 & 0xff) + (uVar14 & 0xff) + (uVar13 & 0xff) +
                               (uVar12 & 0xff)) * local_4a0 +
                               ((uVar11 & 0xff) + (uVar10 & 0xff) + (uVar9 & 0xff) + (uVar8 & 0xff))
                               * local_4a4 +
                               ((uVar28 & 0xff) + (uVar25 & 0xff) + (uVar41 & 0xff) +
                               (uVar40 & 0xff)) * local_4d0[3] +
                               ((uVar52 & 0xff) + (uVar51 & 0xff) + (uVar50 & 0xff) +
                               (uVar49 & 0xff)) * local_4b8 +
                               ((uVar39 & 0xff) + (uVar38 & 0xff) + (uVar37 & 0xff) +
                               (uVar19 & 0xff)) * local_4d0[2] +
                               ((uVar48 & 0xff) + (uVar47 & 0xff) + (uVar46 & 0xff) +
                               (uVar45 & 0xff)) * local_4bc +
                               ((uVar7 & 0xff) + (uVar6 & 0xff) + (uVar5 & 0xff) + (uVar4 & 0xff)) *
                               local_4a8 +
                               ((uVar20 & 0xff) + (local_5d4 & 0xff) + (local_5d8 & 0xff) +
                               (local_5dc & 0xff)) * local_4d0[1] +
                              ((uVar44 & 0xff) + (uVar43 & 0xff) + (uVar42 & 0xff) + (uVar26 & 0xff)
                              ) * local_4c0) >> 1) + (uVar17 & 0xff) * local_4d0[0] >> 0x10);
            *(char *)((int)local_5e8 + 1) =
                 (char)(((int)(((uVar15 >> 8 & 0xff) + (uVar14 >> 8 & 0xff) + (uVar13 >> 8 & 0xff) +
                               (uVar12 >> 8 & 0xff)) * local_4a0 +
                               ((uVar11 >> 8 & 0xff) + (uVar10 >> 8 & 0xff) + (uVar9 >> 8 & 0xff) +
                               (uVar8 >> 8 & 0xff)) * local_4a4 +
                               ((uVar7 >> 8 & 0xff) + (uVar6 >> 8 & 0xff) + (uVar5 >> 8 & 0xff) +
                               (uVar4 >> 8 & 0xff)) * local_4a8 +
                               ((uVar20 >> 8 & 0xff) + (local_5d4 >> 8 & 0xff) +
                                (local_5d8 >> 8 & 0xff) + (local_5dc >> 8 & 0xff)) * local_4d0[1] +
                               ((uVar27 >> 8 & 0xff) + (uVar16 >> 8 & 0xff) + (uVar54 >> 8 & 0xff) +
                               (uVar53 >> 8 & 0xff)) * local_4b4 +
                               ((uVar44 >> 8 & 0xff) + (uVar43 >> 8 & 0xff) + (uVar42 >> 8 & 0xff) +
                               (uVar26 >> 8 & 0xff)) * local_4c0 +
                               ((uVar35 >> 8 & 0xff) + (uVar34 >> 8 & 0xff) + (uVar33 >> 8 & 0xff) +
                               (uVar32 >> 8 & 0xff)) * local_4ac +
                               ((uVar31 >> 8 & 0xff) + (uVar30 >> 8 & 0xff) + (uVar29 >> 8 & 0xff) +
                               (uVar24 >> 8 & 0xff)) * local_4b0 +
                               ((uVar39 >> 8 & 0xff) + (uVar38 >> 8 & 0xff) + (uVar37 >> 8 & 0xff) +
                               (uVar19 >> 8 & 0xff)) * local_4d0[2] +
                               ((uVar28 >> 8 & 0xff) + (uVar25 >> 8 & 0xff) + (uVar41 >> 8 & 0xff) +
                               (uVar40 >> 8 & 0xff)) * local_4d0[3] +
                               ((uVar52 >> 8 & 0xff) + (uVar51 >> 8 & 0xff) + (uVar50 >> 8 & 0xff) +
                               (uVar49 >> 8 & 0xff)) * local_4b8 +
                               ((uVar48 >> 8 & 0xff) + (uVar47 >> 8 & 0xff) + (uVar46 >> 8 & 0xff) +
                               (uVar45 >> 8 & 0xff)) * local_4bc +
                               ((uVar22 >> 8 & 0xff) + (uVar60 >> 8 & 0xff) + (uVar65 >> 8 & 0xff) +
                               (uVar59 >> 8 & 0xff)) * local_494 +
                               ((local_500 >> 8 & 0xff) + (uVar58 >> 8 & 0xff) +
                                (uVar64 >> 8 & 0xff) + (uVar57 >> 8 & 0xff)) * local_498 +
                              ((local_510 >> 8 & 0xff) + (uVar56 >> 8 & 0xff) + (uVar63 >> 8 & 0xff)
                              + (uVar55 >> 8 & 0xff)) * local_49c) >> 1) +
                        (uVar17 >> 8 & 0xff) * local_4d0[0] >> 0x10);
            *(char *)((int)local_5e8 + 2) =
                 (char)(((int)(((uVar15 >> 0x10 & 0xff) + (uVar14 >> 0x10 & 0xff) +
                                (uVar13 >> 0x10 & 0xff) + (uVar12 >> 0x10 & 0xff)) * local_4a0 +
                               ((uVar11 >> 0x10 & 0xff) + (uVar10 >> 0x10 & 0xff) +
                                (uVar9 >> 0x10 & 0xff) + (uVar8 >> 0x10 & 0xff)) * local_4a4 +
                               ((uVar7 >> 0x10 & 0xff) + (uVar6 >> 0x10 & 0xff) +
                                (uVar5 >> 0x10 & 0xff) + (uVar4 >> 0x10 & 0xff)) * local_4a8 +
                               ((uVar20 >> 0x10 & 0xff) + (local_5d4 >> 0x10 & 0xff) +
                                (local_5d8 >> 0x10 & 0xff) + (local_5dc >> 0x10 & 0xff)) *
                               local_4d0[1] +
                               ((uVar27 >> 0x10 & 0xff) + (uVar16 >> 0x10 & 0xff) +
                                (uVar54 >> 0x10 & 0xff) + (uVar53 >> 0x10 & 0xff)) * local_4b4 +
                               ((uVar44 >> 0x10 & 0xff) + (uVar43 >> 0x10 & 0xff) +
                                (uVar42 >> 0x10 & 0xff) + (uVar26 >> 0x10 & 0xff)) * local_4c0 +
                               ((uVar35 >> 0x10 & 0xff) + (uVar34 >> 0x10 & 0xff) +
                                (uVar33 >> 0x10 & 0xff) + (uVar32 >> 0x10 & 0xff)) * local_4ac +
                               ((uVar31 >> 0x10 & 0xff) + (uVar30 >> 0x10 & 0xff) +
                                (uVar29 >> 0x10 & 0xff) + (uVar24 >> 0x10 & 0xff)) * local_4b0 +
                               ((uVar39 >> 0x10 & 0xff) + (uVar38 >> 0x10 & 0xff) +
                                (uVar37 >> 0x10 & 0xff) + (uVar19 >> 0x10 & 0xff)) * local_4d0[2] +
                               ((uVar28 >> 0x10 & 0xff) + (uVar25 >> 0x10 & 0xff) +
                                (uVar41 >> 0x10 & 0xff) + (uVar40 >> 0x10 & 0xff)) * local_4d0[3] +
                               ((uVar52 >> 0x10 & 0xff) + (uVar51 >> 0x10 & 0xff) +
                                (uVar50 >> 0x10 & 0xff) + (uVar49 >> 0x10 & 0xff)) * local_4b8 +
                               ((uVar48 >> 0x10 & 0xff) + (uVar47 >> 0x10 & 0xff) +
                                (uVar46 >> 0x10 & 0xff) + (uVar45 >> 0x10 & 0xff)) * local_4bc +
                               ((uVar22 >> 0x10 & 0xff) + (uVar60 >> 0x10 & 0xff) +
                                (uVar65 >> 0x10 & 0xff) + (uVar59 >> 0x10 & 0xff)) * local_494 +
                               ((local_500 >> 0x10 & 0xff) + (uVar58 >> 0x10 & 0xff) +
                                (uVar64 >> 0x10 & 0xff) + (uVar57 >> 0x10 & 0xff)) * local_498 +
                              ((local_510 >> 0x10 & 0xff) + (uVar56 >> 0x10 & 0xff) +
                               (uVar63 >> 0x10 & 0xff) + (uVar55 >> 0x10 & 0xff)) * local_49c) >> 1)
                        + (uVar17 >> 0x10 & 0xff) * local_4d0[0] >> 0x10);
            local_5e4 = local_5e4 + 1;
            *(char *)((int)local_5e8 + 3) =
                 (char)(((int)(((uVar15 >> 0x18) + (uVar14 >> 0x18) + (uVar13 >> 0x18) +
                               (uVar12 >> 0x18)) * local_4a0 +
                               ((uVar11 >> 0x18) + (uVar10 >> 0x18) + (uVar9 >> 0x18) +
                               (uVar8 >> 0x18)) * local_4a4 +
                               ((uVar7 >> 0x18) + (uVar6 >> 0x18) + (uVar5 >> 0x18) +
                               (uVar4 >> 0x18)) * local_4a8 +
                               ((uVar20 >> 0x18) + (local_5d4 >> 0x18) + (local_5d8 >> 0x18) +
                               (local_5dc >> 0x18)) * local_4d0[1] +
                               ((uVar27 >> 0x18) + (uVar16 >> 0x18) + (uVar54 >> 0x18) +
                               (uVar53 >> 0x18)) * local_4b4 +
                               ((uVar44 >> 0x18) + (uVar43 >> 0x18) + (uVar42 >> 0x18) +
                               (uVar26 >> 0x18)) * local_4c0 +
                               ((uVar35 >> 0x18) + (uVar34 >> 0x18) + (uVar33 >> 0x18) +
                               (uVar32 >> 0x18)) * local_4ac +
                               ((uVar31 >> 0x18) + (uVar30 >> 0x18) + (uVar29 >> 0x18) +
                               (uVar24 >> 0x18)) * local_4b0 +
                               ((uVar39 >> 0x18) + (uVar38 >> 0x18) + (uVar37 >> 0x18) +
                               (uVar19 >> 0x18)) * local_4d0[2] +
                               ((uVar28 >> 0x18) + (uVar25 >> 0x18) + (uVar41 >> 0x18) +
                               (uVar40 >> 0x18)) * local_4d0[3] +
                               ((uVar52 >> 0x18) + (uVar51 >> 0x18) + (uVar50 >> 0x18) +
                               (uVar49 >> 0x18)) * local_4b8 +
                               ((uVar48 >> 0x18) + (uVar47 >> 0x18) + (uVar46 >> 0x18) +
                               (uVar45 >> 0x18)) * local_4bc +
                               ((uVar22 >> 0x18) + (uVar60 >> 0x18) + (uVar65 >> 0x18) +
                               (uVar59 >> 0x18)) * local_494 +
                               ((local_500 >> 0x18) + (uVar58 >> 0x18) + (uVar64 >> 0x18) +
                               (uVar57 >> 0x18)) * local_498 +
                              ((local_510 >> 0x18) + (uVar56 >> 0x18) + (uVar63 >> 0x18) +
                              (uVar55 >> 0x18)) * local_49c) >> 1) + (uVar17 >> 0x18) * local_4d0[0]
                       >> 0x10);
            local_5e8 = local_5e8 + 1;
            uVar22 = uVar18;
          } while (uVar18 < uVar62);
        }
        local_5e4 = (uint *)((int)local_5e4 + iVar66);
        local_5e8 = (uint *)((int)local_5e8 + iVar67);
        local_5f0 = local_5f0 + 1;
      } while (local_5f0 < local_5ec);
    }
    local_5e8 = (uint *)param_1[0x343];
    local_478 = (uint *)((local_5ec - 1) * local_10 + (int)local_c);
    local_48c = local_10 + uVar62 * -4;
    local_490 = param_1[0x342] + uVar62 * -4;
    local_5e4 = local_c;
    local_484 = local_c;
    if (iVar21 == 8) {
      local_5f0 = 0;
      if (local_5ec != 0) {
        do {
          if (uVar62 != 0) {
            local_474 = local_5f0 + 1;
            local_47c = local_5f0 + 3;
            local_480 = local_5f0 + 4;
            local_470 = local_5f0 + 5;
            local_4dc = (uint *)((int)local_5e4 - local_10);
            iVar21 = (int)local_478 - (int)local_c;
            puVar36 = local_c;
            local_5fc = uVar62;
            do {
              uVar22 = *local_5e4;
              if (local_5f0 == 0) {
                uVar17 = *puVar36;
              }
              else {
                uVar17 = *local_4dc;
              }
              if (local_5f0 < 2) {
                local_5d8 = *puVar36;
              }
              else {
                local_5d8 = *(uint *)((int)local_5e4 + local_10 * -2);
              }
              if (local_474 < local_5ec) {
                uVar18 = *(uint *)(local_10 + (int)local_5e4);
              }
              else {
                uVar18 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_5f0 + 2 < local_5ec) {
                uVar20 = *(uint *)((int)local_5e4 + local_10 * 2);
              }
              else {
                uVar20 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_5f0 < 3) {
                uVar19 = *puVar36;
              }
              else {
                uVar19 = *(uint *)((int)local_5e4 + local_10 * -3);
              }
              puVar61 = puVar36;
              if (3 < local_5f0) {
                puVar61 = local_5e4 + -local_10;
              }
              uVar37 = *puVar61;
              if (local_47c < local_5ec) {
                uVar38 = *(uint *)((int)local_5e4 + local_10 * 3);
              }
              else {
                uVar38 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_480 < local_5ec) {
                uVar39 = local_5e4[local_10];
              }
              else {
                uVar39 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_5f0 < 5) {
                uVar40 = *puVar36;
              }
              else {
                uVar40 = *(uint *)((int)local_5e4 + local_10 * -5);
              }
              if (local_5f0 < 6) {
                uVar41 = *puVar36;
              }
              else {
                uVar41 = *(uint *)((int)local_5e4 + local_10 * -6);
              }
              if (local_470 < local_5ec) {
                uVar25 = *(uint *)((int)local_5e4 + local_10 * 5);
              }
              else {
                uVar25 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_5f0 + 6 < local_5ec) {
                uVar28 = *(uint *)((int)local_5e4 + local_10 * 6);
              }
              else {
                uVar28 = *(uint *)(iVar21 + (int)puVar36);
              }
              *(char *)local_5e8 =
                   (char)(((int)(((uVar28 & 0xff) + (uVar25 & 0xff) + (uVar41 & 0xff) +
                                 (uVar40 & 0xff)) * local_4d0[3] +
                                 ((uVar39 & 0xff) + (uVar38 & 0xff) + (uVar37 & 0xff) +
                                 (uVar19 & 0xff)) * local_4d0[2] +
                                ((uVar20 & 0xff) + (uVar18 & 0xff) + (local_5d8 & 0xff) +
                                (uVar17 & 0xff)) * local_4d0[1]) >> 1) +
                          (uVar22 & 0xff) * local_4d0[0] >> 0x10);
              *(char *)((int)local_5e8 + 1) =
                   (char)(((int)(((uVar20 >> 8 & 0xff) + (uVar18 >> 8 & 0xff) +
                                  (local_5d8 >> 8 & 0xff) + (uVar17 >> 8 & 0xff)) * local_4d0[1] +
                                 ((uVar39 >> 8 & 0xff) + (uVar38 >> 8 & 0xff) + (uVar37 >> 8 & 0xff)
                                 + (uVar19 >> 8 & 0xff)) * local_4d0[2] +
                                ((uVar28 >> 8 & 0xff) + (uVar25 >> 8 & 0xff) + (uVar41 >> 8 & 0xff)
                                + (uVar40 >> 8 & 0xff)) * local_4d0[3]) >> 1) +
                          (uVar22 >> 8 & 0xff) * local_4d0[0] >> 0x10);
              *(char *)((int)local_5e8 + 2) =
                   (char)(((int)(((uVar20 >> 0x10 & 0xff) + (uVar18 >> 0x10 & 0xff) +
                                  (local_5d8 >> 0x10 & 0xff) + (uVar17 >> 0x10 & 0xff)) *
                                 local_4d0[1] +
                                 ((uVar39 >> 0x10 & 0xff) + (uVar38 >> 0x10 & 0xff) +
                                  (uVar37 >> 0x10 & 0xff) + (uVar19 >> 0x10 & 0xff)) * local_4d0[2]
                                + ((uVar28 >> 0x10 & 0xff) + (uVar25 >> 0x10 & 0xff) +
                                   (uVar41 >> 0x10 & 0xff) + (uVar40 >> 0x10 & 0xff)) * local_4d0[3]
                                ) >> 1) + (uVar22 >> 0x10 & 0xff) * local_4d0[0] >> 0x10);
              local_4dc = local_4dc + 1;
              *(char *)((int)local_5e8 + 3) =
                   (char)(((int)(((uVar20 >> 0x18) + (uVar18 >> 0x18) + (local_5d8 >> 0x18) +
                                 (uVar17 >> 0x18)) * local_4d0[1] +
                                 ((uVar39 >> 0x18) + (uVar38 >> 0x18) + (uVar37 >> 0x18) +
                                 (uVar19 >> 0x18)) * local_4d0[2] +
                                ((uVar28 >> 0x18) + (uVar25 >> 0x18) + (uVar41 >> 0x18) +
                                (uVar40 >> 0x18)) * local_4d0[3]) >> 1) +
                          (uVar22 >> 0x18) * local_4d0[0] >> 0x10);
              puVar36 = puVar36 + 1;
              local_5e4 = local_5e4 + 1;
              local_5e8 = (uint *)((int)local_5e8 + 4);
              local_5fc = local_5fc - 1;
            } while (local_5fc != 0);
          }
          local_5e8 = (uint *)((int)local_5e8 + local_490);
          local_5f0 = local_5f0 + 1;
          local_5e4 = (uint *)((int)local_5e4 + local_48c);
        } while (local_5f0 < local_5ec);
      }
    }
    else if (iVar21 == 0x10) {
      local_5f0 = 0;
      if (local_5ec != 0) {
        do {
          if (uVar62 != 0) {
            local_474 = local_5f0 + 1;
            local_47c = local_5f0 + 3;
            local_480 = local_5f0 + 4;
            local_470 = local_5f0 + 5;
            local_45c = local_5f0 + 7;
            local_468 = local_5f0 + 8;
            local_454 = local_5f0 + 9;
            local_460 = local_5f0 + 10;
            local_464 = local_5f0 + 0xb;
            local_46c = local_5f0 + 0xc;
            local_458 = local_5f0 + 0xd;
            local_488 = local_5f0 + 0xe;
            local_4dc = (uint *)((int)local_5e4 - local_10);
            iVar21 = (int)local_478 - (int)local_c;
            puVar36 = local_c;
            local_5fc = uVar62;
            do {
              uVar22 = *local_5e4;
              if (local_5f0 == 0) {
                uVar17 = *puVar36;
              }
              else {
                uVar17 = *local_4dc;
              }
              if (local_5f0 < 2) {
                uVar18 = *puVar36;
              }
              else {
                uVar18 = *(uint *)((int)local_5e4 + local_10 * -2);
              }
              if (local_474 < local_5ec) {
                uVar20 = *(uint *)(local_10 + (int)local_5e4);
              }
              else {
                uVar20 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_5f0 + 2 < local_5ec) {
                uVar19 = *(uint *)((int)local_5e4 + local_10 * 2);
              }
              else {
                uVar19 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_5f0 < 3) {
                local_5cc = *puVar36;
              }
              else {
                local_5cc = *(uint *)((int)local_5e4 + local_10 * -3);
              }
              if (local_5f0 < 4) {
                uVar37 = *puVar36;
              }
              else {
                uVar37 = local_5e4[-local_10];
              }
              if (local_47c < local_5ec) {
                uVar38 = *(uint *)((int)local_5e4 + local_10 * 3);
              }
              else {
                uVar38 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_480 < local_5ec) {
                uVar39 = local_5e4[local_10];
              }
              else {
                uVar39 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_5f0 < 5) {
                uVar40 = *puVar36;
              }
              else {
                uVar40 = *(uint *)((int)local_5e4 + local_10 * -5);
              }
              if (local_5f0 < 6) {
                uVar41 = *puVar36;
              }
              else {
                uVar41 = *(uint *)((int)local_5e4 + local_10 * -6);
              }
              if (local_470 < local_5ec) {
                uVar25 = *(uint *)((int)local_5e4 + local_10 * 5);
              }
              else {
                uVar25 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_5f0 + 6 < local_5ec) {
                uVar28 = *(uint *)((int)local_5e4 + local_10 * 6);
              }
              else {
                uVar28 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_5f0 < 7) {
                uVar26 = *puVar36;
              }
              else {
                uVar26 = *(uint *)((int)local_5e4 + local_10 * -7);
              }
              if (local_5f0 < 8) {
                uVar42 = *puVar36;
              }
              else {
                uVar42 = local_5e4[local_10 * -2];
              }
              if (local_45c < local_5ec) {
                uVar43 = *(uint *)(local_10 * 7 + (int)local_5e4);
              }
              else {
                uVar43 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_468 < local_5ec) {
                uVar44 = local_5e4[local_10 * 2];
              }
              else {
                uVar44 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_5f0 < 9) {
                uVar45 = *puVar36;
              }
              else {
                uVar45 = *(uint *)((int)local_5e4 + local_10 * -9);
              }
              if (local_5f0 < 10) {
                uVar46 = *puVar36;
              }
              else {
                uVar46 = *(uint *)((int)local_5e4 + local_10 * -10);
              }
              if (local_454 < local_5ec) {
                uVar47 = *(uint *)((int)local_5e4 + local_10 * 9);
              }
              else {
                uVar47 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_460 < local_5ec) {
                uVar48 = *(uint *)((int)local_5e4 + local_10 * 10);
              }
              else {
                uVar48 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_5f0 < 0xb) {
                uVar49 = *puVar36;
              }
              else {
                uVar49 = *(uint *)((int)local_5e4 + local_10 * -0xb);
              }
              if (local_5f0 < 0xc) {
                uVar50 = *puVar36;
              }
              else {
                uVar50 = local_5e4[local_10 * -3];
              }
              if (local_464 < local_5ec) {
                uVar51 = *(uint *)(local_10 * 0xb + (int)local_5e4);
              }
              else {
                uVar51 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_46c < local_5ec) {
                uVar52 = local_5e4[local_10 * 3];
              }
              else {
                uVar52 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_5f0 < 0xd) {
                uVar53 = *puVar36;
              }
              else {
                uVar53 = *(uint *)((int)local_5e4 + local_10 * -0xd);
              }
              if (local_5f0 < 0xe) {
                uVar54 = *puVar36;
              }
              else {
                uVar54 = *(uint *)((int)local_5e4 + local_10 * -0xe);
              }
              if (local_458 < local_5ec) {
                uVar16 = *(uint *)(local_10 * 0xd + (int)local_5e4);
              }
              else {
                uVar16 = *(uint *)(iVar21 + (int)puVar36);
              }
              if (local_488 < local_5ec) {
                uVar27 = *(uint *)((int)local_5e4 + local_10 * 0xe);
              }
              else {
                uVar27 = *(uint *)(iVar21 + (int)puVar36);
              }
              *(char *)local_5e8 =
                   (char)(((int)(((uVar27 & 0xff) + (uVar16 & 0xff) + (uVar54 & 0xff) +
                                 (uVar53 & 0xff)) * local_4b4 +
                                 ((uVar28 & 0xff) + (uVar25 & 0xff) + (uVar41 & 0xff) +
                                 (uVar40 & 0xff)) * local_4d0[3] +
                                 ((uVar52 & 0xff) + (uVar51 & 0xff) + (uVar50 & 0xff) +
                                 (uVar49 & 0xff)) * local_4b8 +
                                 ((uVar39 & 0xff) + (uVar38 & 0xff) + (uVar37 & 0xff) +
                                 (local_5cc & 0xff)) * local_4d0[2] +
                                 ((uVar48 & 0xff) + (uVar47 & 0xff) + (uVar46 & 0xff) +
                                 (uVar45 & 0xff)) * local_4bc +
                                 ((uVar19 & 0xff) + (uVar20 & 0xff) + (uVar18 & 0xff) +
                                 (uVar17 & 0xff)) * local_4d0[1] +
                                ((uVar44 & 0xff) + (uVar43 & 0xff) + (uVar42 & 0xff) +
                                (uVar26 & 0xff)) * local_4c0) >> 1) + (uVar22 & 0xff) * local_4d0[0]
                         >> 0x10);
              *(char *)((int)local_5e8 + 1) =
                   (char)(((int)(((uVar19 >> 8 & 0xff) + (uVar20 >> 8 & 0xff) + (uVar18 >> 8 & 0xff)
                                 + (uVar17 >> 8 & 0xff)) * local_4d0[1] +
                                 ((uVar27 >> 8 & 0xff) + (uVar16 >> 8 & 0xff) + (uVar54 >> 8 & 0xff)
                                 + (uVar53 >> 8 & 0xff)) * local_4b4 +
                                 ((uVar44 >> 8 & 0xff) + (uVar43 >> 8 & 0xff) + (uVar42 >> 8 & 0xff)
                                 + (uVar26 >> 8 & 0xff)) * local_4c0 +
                                 ((uVar39 >> 8 & 0xff) + (uVar38 >> 8 & 0xff) + (uVar37 >> 8 & 0xff)
                                 + (local_5cc >> 8 & 0xff)) * local_4d0[2] +
                                 ((uVar28 >> 8 & 0xff) + (uVar25 >> 8 & 0xff) + (uVar41 >> 8 & 0xff)
                                 + (uVar40 >> 8 & 0xff)) * local_4d0[3] +
                                 ((uVar52 >> 8 & 0xff) + (uVar51 >> 8 & 0xff) + (uVar50 >> 8 & 0xff)
                                 + (uVar49 >> 8 & 0xff)) * local_4b8 +
                                ((uVar48 >> 8 & 0xff) + (uVar47 >> 8 & 0xff) + (uVar46 >> 8 & 0xff)
                                + (uVar45 >> 8 & 0xff)) * local_4bc) >> 1) +
                          (uVar22 >> 8 & 0xff) * local_4d0[0] >> 0x10);
              *(char *)((int)local_5e8 + 2) =
                   (char)(((int)(((uVar19 >> 0x10 & 0xff) + (uVar20 >> 0x10 & 0xff) +
                                  (uVar18 >> 0x10 & 0xff) + (uVar17 >> 0x10 & 0xff)) * local_4d0[1]
                                 + ((uVar27 >> 0x10 & 0xff) + (uVar16 >> 0x10 & 0xff) +
                                    (uVar54 >> 0x10 & 0xff) + (uVar53 >> 0x10 & 0xff)) * local_4b4 +
                                 ((uVar44 >> 0x10 & 0xff) + (uVar43 >> 0x10 & 0xff) +
                                  (uVar42 >> 0x10 & 0xff) + (uVar26 >> 0x10 & 0xff)) * local_4c0 +
                                 ((uVar39 >> 0x10 & 0xff) + (uVar38 >> 0x10 & 0xff) +
                                  (uVar37 >> 0x10 & 0xff) + (local_5cc >> 0x10 & 0xff)) *
                                 local_4d0[2] +
                                 ((uVar28 >> 0x10 & 0xff) + (uVar25 >> 0x10 & 0xff) +
                                  (uVar41 >> 0x10 & 0xff) + (uVar40 >> 0x10 & 0xff)) * local_4d0[3]
                                 + ((uVar52 >> 0x10 & 0xff) + (uVar51 >> 0x10 & 0xff) +
                                    (uVar50 >> 0x10 & 0xff) + (uVar49 >> 0x10 & 0xff)) * local_4b8 +
                                ((uVar48 >> 0x10 & 0xff) + (uVar47 >> 0x10 & 0xff) +
                                 (uVar46 >> 0x10 & 0xff) + (uVar45 >> 0x10 & 0xff)) * local_4bc) >>
                          1) + (uVar22 >> 0x10 & 0xff) * local_4d0[0] >> 0x10);
              local_4dc = local_4dc + 1;
              *(char *)((int)local_5e8 + 3) =
                   (char)(((int)(((uVar19 >> 0x18) + (uVar20 >> 0x18) + (uVar18 >> 0x18) +
                                 (uVar17 >> 0x18)) * local_4d0[1] +
                                 ((uVar27 >> 0x18) + (uVar16 >> 0x18) + (uVar54 >> 0x18) +
                                 (uVar53 >> 0x18)) * local_4b4 +
                                 ((uVar44 >> 0x18) + (uVar43 >> 0x18) + (uVar42 >> 0x18) +
                                 (uVar26 >> 0x18)) * local_4c0 +
                                 ((uVar39 >> 0x18) + (uVar38 >> 0x18) + (uVar37 >> 0x18) +
                                 (local_5cc >> 0x18)) * local_4d0[2] +
                                 ((uVar28 >> 0x18) + (uVar25 >> 0x18) + (uVar41 >> 0x18) +
                                 (uVar40 >> 0x18)) * local_4d0[3] +
                                 ((uVar52 >> 0x18) + (uVar51 >> 0x18) + (uVar50 >> 0x18) +
                                 (uVar49 >> 0x18)) * local_4b8 +
                                ((uVar48 >> 0x18) + (uVar47 >> 0x18) + (uVar46 >> 0x18) +
                                (uVar45 >> 0x18)) * local_4bc) >> 1) +
                          (uVar22 >> 0x18) * local_4d0[0] >> 0x10);
              local_5e8 = (uint *)((int)local_5e8 + 4);
              puVar36 = puVar36 + 1;
              local_5e4 = local_5e4 + 1;
              local_5fc = local_5fc - 1;
            } while (local_5fc != 0);
          }
          local_5e8 = (uint *)((int)local_5e8 + local_490);
          local_5f0 = local_5f0 + 1;
          local_5e4 = (uint *)((int)local_5e4 + local_48c);
        } while (local_5f0 < local_5ec);
      }
    }
    else if ((iVar21 == 0x20) && (local_5f0 = 0, local_5ec != 0)) {
      do {
        local_5f8 = local_c;
        local_4dc = (uint *)0x0;
        local_5f4 = local_478;
        if (uVar62 != 0) {
          do {
            uVar22 = *local_5e4;
            if (local_5f0 == 0) {
              uVar17 = *local_5f8;
            }
            else {
              uVar17 = *(uint *)((int)local_5e4 - local_10);
            }
            if (local_5f0 < 2) {
              uVar18 = *local_5f8;
            }
            else {
              uVar18 = *(uint *)((int)local_5e4 + local_10 * -2);
            }
            if (local_5f0 + 1 < local_5ec) {
              uVar20 = *(uint *)(local_10 + (int)local_5e4);
            }
            else {
              uVar20 = *local_5f4;
            }
            if (local_5f0 + 2 < local_5ec) {
              uVar19 = *(uint *)((int)local_5e4 + local_10 * 2);
            }
            else {
              uVar19 = *local_5f4;
            }
            if (local_5f0 < 3) {
              local_5cc = *local_5f8;
            }
            else {
              local_5cc = *(uint *)((int)local_5e4 + local_10 * -3);
            }
            if (local_5f0 < 4) {
              local_5c8 = *local_5f8;
            }
            else {
              local_5c8 = local_5e4[-local_10];
            }
            if (local_5f0 + 3 < local_5ec) {
              uVar37 = *(uint *)((int)local_5e4 + local_10 * 3);
            }
            else {
              uVar37 = *local_5f4;
            }
            if (local_5f0 + 4 < local_5ec) {
              uVar38 = local_5e4[local_10];
            }
            else {
              uVar38 = *local_5f4;
            }
            if (local_5f0 < 5) {
              local_5bc = *local_5f8;
            }
            else {
              local_5bc = *(uint *)((int)local_5e4 + local_10 * -5);
            }
            if (local_5f0 < 6) {
              local_5b8 = *local_5f8;
            }
            else {
              local_5b8 = *(uint *)((int)local_5e4 + local_10 * -6);
            }
            if (local_5f0 + 5 < local_5ec) {
              uVar39 = *(uint *)((int)local_5e4 + local_10 * 5);
            }
            else {
              uVar39 = *local_5f4;
            }
            if (local_5f0 + 6 < local_5ec) {
              uVar40 = *(uint *)((int)local_5e4 + local_10 * 6);
            }
            else {
              uVar40 = *local_5f4;
            }
            if (local_5f0 < 7) {
              local_5ac = *local_5f8;
            }
            else {
              local_5ac = *(uint *)((int)local_5e4 + local_10 * -7);
            }
            if (local_5f0 < 8) {
              local_5a8 = *local_5f8;
            }
            else {
              local_5a8 = local_5e4[local_10 * -2];
            }
            if (local_5f0 + 7 < local_5ec) {
              uVar41 = *(uint *)(local_10 * 7 + (int)local_5e4);
            }
            else {
              uVar41 = *local_5f4;
            }
            if (local_5f0 + 8 < local_5ec) {
              uVar25 = local_5e4[local_10 * 2];
            }
            else {
              uVar25 = *local_5f4;
            }
            if (local_5f0 < 9) {
              local_59c = *local_5f8;
            }
            else {
              local_59c = *(uint *)((int)local_5e4 + local_10 * -9);
            }
            if (local_5f0 < 10) {
              local_598 = *local_5f8;
            }
            else {
              local_598 = *(uint *)((int)local_5e4 + local_10 * -10);
            }
            if (local_5f0 + 9 < local_5ec) {
              uVar28 = *(uint *)((int)local_5e4 + local_10 * 9);
            }
            else {
              uVar28 = *local_5f4;
            }
            if (local_5f0 + 10 < local_5ec) {
              uVar26 = *(uint *)((int)local_5e4 + local_10 * 10);
            }
            else {
              uVar26 = *local_5f4;
            }
            if (local_5f0 < 0xb) {
              local_58c = *local_5f8;
            }
            else {
              local_58c = *(uint *)((int)local_5e4 + local_10 * -0xb);
            }
            if (local_5f0 < 0xc) {
              local_588 = *local_5f8;
            }
            else {
              local_588 = local_5e4[local_10 * -3];
            }
            if (local_5f0 + 0xb < local_5ec) {
              uVar42 = *(uint *)(local_10 * 0xb + (int)local_5e4);
            }
            else {
              uVar42 = *local_5f4;
            }
            if (local_5f0 + 0xc < local_5ec) {
              uVar43 = local_5e4[local_10 * 3];
            }
            else {
              uVar43 = *local_5f4;
            }
            if (local_5f0 < 0xd) {
              local_57c = *local_5f8;
            }
            else {
              local_57c = *(uint *)((int)local_5e4 + local_10 * -0xd);
            }
            if (local_5f0 < 0xe) {
              local_578 = *local_5f8;
            }
            else {
              local_578 = *(uint *)((int)local_5e4 + local_10 * -0xe);
            }
            if (local_5f0 + 0xd < local_5ec) {
              uVar44 = *(uint *)(local_10 * 0xd + (int)local_5e4);
            }
            else {
              uVar44 = *local_5f4;
            }
            if (local_5f0 + 0xe < local_5ec) {
              uVar45 = *(uint *)((int)local_5e4 + local_10 * 0xe);
            }
            else {
              uVar45 = *local_5f4;
            }
            if (local_5f0 < 0xf) {
              local_56c = *local_5f8;
            }
            else {
              local_56c = *(uint *)((int)local_5e4 + local_10 * -0xf);
            }
            if (local_5f0 < 0x10) {
              local_568 = *local_5f8;
            }
            else {
              local_568 = local_5e4[local_10 * -4];
            }
            if (local_5f0 + 0xf < local_5ec) {
              uVar46 = *(uint *)(local_10 * 0xf + (int)local_5e4);
            }
            else {
              uVar46 = *local_5f4;
            }
            if (local_5f0 + 0x10 < local_5ec) {
              uVar47 = local_5e4[local_10 * 4];
            }
            else {
              uVar47 = *local_5f4;
            }
            if (local_5f0 < 0x11) {
              local_55c = *local_5f8;
            }
            else {
              local_55c = *(uint *)((int)local_5e4 + local_10 * -0x11);
            }
            if (local_5f0 < 0x12) {
              local_558 = *local_5f8;
            }
            else {
              local_558 = *(uint *)((int)local_5e4 + local_10 * -0x12);
            }
            if (local_5f0 + 0x11 < local_5ec) {
              uVar48 = *(uint *)(local_10 * 0x11 + (int)local_5e4);
            }
            else {
              uVar48 = *local_5f4;
            }
            if (local_5f0 + 0x12 < local_5ec) {
              uVar49 = *(uint *)((int)local_5e4 + local_10 * 0x12);
            }
            else {
              uVar49 = *local_5f4;
            }
            if (local_5f0 < 0x13) {
              local_54c = *local_5f8;
            }
            else {
              local_54c = *(uint *)((int)local_5e4 + local_10 * -0x13);
            }
            if (local_5f0 < 0x14) {
              local_548 = *local_5f8;
            }
            else {
              local_548 = local_5e4[local_10 * -5];
            }
            if (local_5f0 + 0x13 < local_5ec) {
              uVar50 = *(uint *)(local_10 * 0x13 + (int)local_5e4);
            }
            else {
              uVar50 = *local_5f4;
            }
            if (local_5f0 + 0x14 < local_5ec) {
              uVar51 = local_5e4[local_10 * 5];
            }
            else {
              uVar51 = *local_5f4;
            }
            if (local_5f0 < 0x15) {
              local_53c = *local_5f8;
            }
            else {
              local_53c = *(uint *)((int)local_5e4 + local_10 * -0x15);
            }
            if (local_5f0 < 0x16) {
              local_538 = *local_5f8;
            }
            else {
              local_538 = *(uint *)((int)local_5e4 + local_10 * -0x16);
            }
            if (local_5f0 + 0x15 < local_5ec) {
              uVar52 = *(uint *)(local_10 * 0x15 + (int)local_5e4);
            }
            else {
              uVar52 = *local_5f4;
            }
            if (local_5f0 + 0x16 < local_5ec) {
              uVar53 = *(uint *)(local_10 * 0x16 + (int)local_5e4);
            }
            else {
              uVar53 = *local_5f4;
            }
            if (local_5f0 < 0x17) {
              local_52c = *local_5f8;
            }
            else {
              local_52c = *(uint *)((int)local_5e4 + local_10 * -0x17);
            }
            if (local_5f0 < 0x18) {
              local_528 = *local_5f8;
            }
            else {
              local_528 = local_5e4[local_10 * -6];
            }
            if (local_5f0 + 0x17 < local_5ec) {
              uVar54 = *(uint *)(local_10 * 0x17 + (int)local_5e4);
            }
            else {
              uVar54 = *local_5f4;
            }
            if (local_5f0 + 0x18 < local_5ec) {
              uVar16 = local_5e4[local_10 * 6];
            }
            else {
              uVar16 = *local_5f4;
            }
            if (local_5f0 < 0x19) {
              local_51c = *local_5f8;
            }
            else {
              local_51c = *(uint *)((int)local_5e4 + local_10 * -0x19);
            }
            if (local_5f0 < 0x1a) {
              local_518 = *local_5f8;
            }
            else {
              local_518 = *(uint *)((int)local_5e4 + local_10 * -0x1a);
            }
            if (local_5f0 + 0x19 < local_5ec) {
              uVar27 = *(uint *)(local_10 * 0x19 + (int)local_5e4);
            }
            else {
              uVar27 = *local_5f4;
            }
            if (local_5f0 + 0x1a < local_5ec) {
              uVar24 = *(uint *)(local_10 * 0x1a + (int)local_5e4);
            }
            else {
              uVar24 = *local_5f4;
            }
            if (local_5f0 < 0x1b) {
              uVar29 = *local_5f8;
            }
            else {
              uVar29 = *(uint *)((int)local_5e4 + local_10 * -0x1b);
            }
            if (local_5f0 < 0x1c) {
              uVar30 = *local_5f8;
            }
            else {
              uVar30 = local_5e4[local_10 * -7];
            }
            if (local_5f0 + 0x1b < local_5ec) {
              uVar31 = *(uint *)(local_10 * 0x1b + (int)local_5e4);
            }
            else {
              uVar31 = *local_5f4;
            }
            if (local_5f0 + 0x1c < local_5ec) {
              uVar32 = local_5e4[local_10 * 7];
            }
            else {
              uVar32 = *local_5f4;
            }
            if (local_5f0 < 0x1d) {
              uVar33 = *local_5f8;
            }
            else {
              uVar33 = *(uint *)((int)local_5e4 + local_10 * -0x1d);
            }
            if (local_5f0 < 0x1e) {
              uVar34 = *local_5f8;
            }
            else {
              uVar34 = *(uint *)((int)local_5e4 + local_10 * -0x1e);
            }
            if (local_5f0 + 0x1d < local_5ec) {
              uVar35 = *(uint *)(local_10 * 0x1d + (int)local_5e4);
            }
            else {
              uVar35 = *local_5f4;
            }
            if (local_5f0 + 0x1e < local_5ec) {
              uVar4 = *(uint *)((int)local_5e4 + local_10 * 0x1e);
            }
            else {
              uVar4 = *local_5f4;
            }
            *(char *)local_5e8 =
                 (char)(((int)(((uVar49 & 0xff) + (uVar48 & 0xff) + (local_558 & 0xff) +
                               (local_55c & 0xff)) * local_4ac +
                               ((uVar47 & 0xff) + (uVar46 & 0xff) + (local_568 & 0xff) +
                               (local_56c & 0xff)) * local_4b0 +
                               ((uVar4 & 0xff) + (uVar35 & 0xff) + (uVar34 & 0xff) + (uVar33 & 0xff)
                               ) * local_494 +
                               ((uVar32 & 0xff) + (uVar31 & 0xff) + (uVar30 & 0xff) +
                               (uVar29 & 0xff)) * local_498 +
                               ((uVar45 & 0xff) + (uVar44 & 0xff) + (local_578 & 0xff) +
                               (local_57c & 0xff)) * local_4b4 +
                               ((uVar24 & 0xff) + (uVar27 & 0xff) + (local_518 & 0xff) +
                               (local_51c & 0xff)) * local_49c +
                               ((uVar16 & 0xff) + (uVar54 & 0xff) + (local_528 & 0xff) +
                               (local_52c & 0xff)) * local_4a0 +
                               ((uVar53 & 0xff) + (uVar52 & 0xff) + (local_538 & 0xff) +
                               (local_53c & 0xff)) * local_4a4 +
                               ((uVar40 & 0xff) + (uVar39 & 0xff) + (local_5b8 & 0xff) +
                               (local_5bc & 0xff)) * local_4d0[3] +
                               ((uVar43 & 0xff) + (uVar42 & 0xff) + (local_588 & 0xff) +
                               (local_58c & 0xff)) * local_4b8 +
                               ((uVar38 & 0xff) + (uVar37 & 0xff) + (local_5c8 & 0xff) +
                               (local_5cc & 0xff)) * local_4d0[2] +
                               ((uVar26 & 0xff) + (uVar28 & 0xff) + (local_598 & 0xff) +
                               (local_59c & 0xff)) * local_4bc +
                               ((uVar51 & 0xff) + (uVar50 & 0xff) + (local_548 & 0xff) +
                               (local_54c & 0xff)) * local_4a8 +
                               ((uVar19 & 0xff) + (uVar20 & 0xff) + (uVar18 & 0xff) +
                               (uVar17 & 0xff)) * local_4d0[1] +
                              ((uVar25 & 0xff) + (uVar41 & 0xff) + (local_5a8 & 0xff) +
                              (local_5ac & 0xff)) * local_4c0) >> 1) +
                        (uVar22 & 0xff) * local_4d0[0] >> 0x10);
            *(char *)((int)local_5e8 + 1) =
                 (char)(((int)(((uVar16 >> 8 & 0xff) + (uVar54 >> 8 & 0xff) +
                                (local_528 >> 8 & 0xff) + (local_52c >> 8 & 0xff)) * local_4a0 +
                               ((uVar53 >> 8 & 0xff) + (uVar52 >> 8 & 0xff) +
                                (local_538 >> 8 & 0xff) + (local_53c >> 8 & 0xff)) * local_4a4 +
                               ((uVar51 >> 8 & 0xff) + (uVar50 >> 8 & 0xff) +
                                (local_548 >> 8 & 0xff) + (local_54c >> 8 & 0xff)) * local_4a8 +
                               ((uVar19 >> 8 & 0xff) + (uVar20 >> 8 & 0xff) + (uVar18 >> 8 & 0xff) +
                               (uVar17 >> 8 & 0xff)) * local_4d0[1] +
                               ((uVar45 >> 8 & 0xff) + (uVar44 >> 8 & 0xff) +
                                (local_578 >> 8 & 0xff) + (local_57c >> 8 & 0xff)) * local_4b4 +
                               ((uVar25 >> 8 & 0xff) + (uVar41 >> 8 & 0xff) +
                                (local_5a8 >> 8 & 0xff) + (local_5ac >> 8 & 0xff)) * local_4c0 +
                               ((uVar49 >> 8 & 0xff) + (uVar48 >> 8 & 0xff) +
                                (local_558 >> 8 & 0xff) + (local_55c >> 8 & 0xff)) * local_4ac +
                               ((uVar47 >> 8 & 0xff) + (uVar46 >> 8 & 0xff) +
                                (local_568 >> 8 & 0xff) + (local_56c >> 8 & 0xff)) * local_4b0 +
                               ((uVar38 >> 8 & 0xff) + (uVar37 >> 8 & 0xff) +
                                (local_5c8 >> 8 & 0xff) + (local_5cc >> 8 & 0xff)) * local_4d0[2] +
                               ((uVar40 >> 8 & 0xff) + (uVar39 >> 8 & 0xff) +
                                (local_5b8 >> 8 & 0xff) + (local_5bc >> 8 & 0xff)) * local_4d0[3] +
                               ((uVar43 >> 8 & 0xff) + (uVar42 >> 8 & 0xff) +
                                (local_588 >> 8 & 0xff) + (local_58c >> 8 & 0xff)) * local_4b8 +
                               ((uVar26 >> 8 & 0xff) + (uVar28 >> 8 & 0xff) +
                                (local_598 >> 8 & 0xff) + (local_59c >> 8 & 0xff)) * local_4bc +
                               ((uVar4 >> 8 & 0xff) + (uVar35 >> 8 & 0xff) + (uVar34 >> 8 & 0xff) +
                               (uVar33 >> 8 & 0xff)) * local_494 +
                               ((uVar32 >> 8 & 0xff) + (uVar31 >> 8 & 0xff) + (uVar30 >> 8 & 0xff) +
                               (uVar29 >> 8 & 0xff)) * local_498 +
                              ((uVar24 >> 8 & 0xff) + (uVar27 >> 8 & 0xff) + (local_518 >> 8 & 0xff)
                              + (local_51c >> 8 & 0xff)) * local_49c) >> 1) +
                        (uVar22 >> 8 & 0xff) * local_4d0[0] >> 0x10);
            *(char *)((int)local_5e8 + 2) =
                 (char)(((int)(((uVar16 >> 0x10 & 0xff) + (uVar54 >> 0x10 & 0xff) +
                                (local_528 >> 0x10 & 0xff) + (local_52c >> 0x10 & 0xff)) * local_4a0
                               + ((uVar53 >> 0x10 & 0xff) + (uVar52 >> 0x10 & 0xff) +
                                  (local_538 >> 0x10 & 0xff) + (local_53c >> 0x10 & 0xff)) *
                                 local_4a4 +
                               ((uVar51 >> 0x10 & 0xff) + (uVar50 >> 0x10 & 0xff) +
                                (local_548 >> 0x10 & 0xff) + (local_54c >> 0x10 & 0xff)) * local_4a8
                               + ((uVar19 >> 0x10 & 0xff) + (uVar20 >> 0x10 & 0xff) +
                                  (uVar18 >> 0x10 & 0xff) + (uVar17 >> 0x10 & 0xff)) * local_4d0[1]
                               + ((uVar45 >> 0x10 & 0xff) + (uVar44 >> 0x10 & 0xff) +
                                  (local_578 >> 0x10 & 0xff) + (local_57c >> 0x10 & 0xff)) *
                                 local_4b4 +
                               ((uVar25 >> 0x10 & 0xff) + (uVar41 >> 0x10 & 0xff) +
                                (local_5a8 >> 0x10 & 0xff) + (local_5ac >> 0x10 & 0xff)) * local_4c0
                               + ((uVar49 >> 0x10 & 0xff) + (uVar48 >> 0x10 & 0xff) +
                                  (local_558 >> 0x10 & 0xff) + (local_55c >> 0x10 & 0xff)) *
                                 local_4ac +
                               ((uVar47 >> 0x10 & 0xff) + (uVar46 >> 0x10 & 0xff) +
                                (local_568 >> 0x10 & 0xff) + (local_56c >> 0x10 & 0xff)) * local_4b0
                               + ((uVar38 >> 0x10 & 0xff) + (uVar37 >> 0x10 & 0xff) +
                                  (local_5c8 >> 0x10 & 0xff) + (local_5cc >> 0x10 & 0xff)) *
                                 local_4d0[2] +
                               ((uVar40 >> 0x10 & 0xff) + (uVar39 >> 0x10 & 0xff) +
                                (local_5b8 >> 0x10 & 0xff) + (local_5bc >> 0x10 & 0xff)) *
                               local_4d0[3] +
                               ((uVar43 >> 0x10 & 0xff) + (uVar42 >> 0x10 & 0xff) +
                                (local_588 >> 0x10 & 0xff) + (local_58c >> 0x10 & 0xff)) * local_4b8
                               + ((uVar26 >> 0x10 & 0xff) + (uVar28 >> 0x10 & 0xff) +
                                  (local_598 >> 0x10 & 0xff) + (local_59c >> 0x10 & 0xff)) *
                                 local_4bc +
                               ((uVar4 >> 0x10 & 0xff) + (uVar35 >> 0x10 & 0xff) +
                                (uVar34 >> 0x10 & 0xff) + (uVar33 >> 0x10 & 0xff)) * local_494 +
                               ((uVar32 >> 0x10 & 0xff) + (uVar31 >> 0x10 & 0xff) +
                                (uVar30 >> 0x10 & 0xff) + (uVar29 >> 0x10 & 0xff)) * local_498 +
                              ((uVar24 >> 0x10 & 0xff) + (uVar27 >> 0x10 & 0xff) +
                               (local_518 >> 0x10 & 0xff) + (local_51c >> 0x10 & 0xff)) * local_49c)
                        >> 1) + (uVar22 >> 0x10 & 0xff) * local_4d0[0] >> 0x10);
            *(char *)((int)local_5e8 + 3) =
                 (char)(((int)(((uVar16 >> 0x18) + (uVar54 >> 0x18) + (local_528 >> 0x18) +
                               (local_52c >> 0x18)) * local_4a0 +
                               ((uVar53 >> 0x18) + (uVar52 >> 0x18) + (local_538 >> 0x18) +
                               (local_53c >> 0x18)) * local_4a4 +
                               ((uVar51 >> 0x18) + (uVar50 >> 0x18) + (local_548 >> 0x18) +
                               (local_54c >> 0x18)) * local_4a8 +
                               ((uVar19 >> 0x18) + (uVar20 >> 0x18) + (uVar18 >> 0x18) +
                               (uVar17 >> 0x18)) * local_4d0[1] +
                               ((uVar45 >> 0x18) + (uVar44 >> 0x18) + (local_578 >> 0x18) +
                               (local_57c >> 0x18)) * local_4b4 +
                               ((uVar25 >> 0x18) + (uVar41 >> 0x18) + (local_5a8 >> 0x18) +
                               (local_5ac >> 0x18)) * local_4c0 +
                               ((uVar49 >> 0x18) + (uVar48 >> 0x18) + (local_558 >> 0x18) +
                               (local_55c >> 0x18)) * local_4ac +
                               ((uVar47 >> 0x18) + (uVar46 >> 0x18) + (local_568 >> 0x18) +
                               (local_56c >> 0x18)) * local_4b0 +
                               ((uVar38 >> 0x18) + (uVar37 >> 0x18) + (local_5c8 >> 0x18) +
                               (local_5cc >> 0x18)) * local_4d0[2] +
                               ((uVar40 >> 0x18) + (uVar39 >> 0x18) + (local_5b8 >> 0x18) +
                               (local_5bc >> 0x18)) * local_4d0[3] +
                               ((uVar43 >> 0x18) + (uVar42 >> 0x18) + (local_588 >> 0x18) +
                               (local_58c >> 0x18)) * local_4b8 +
                               ((uVar26 >> 0x18) + (uVar28 >> 0x18) + (local_598 >> 0x18) +
                               (local_59c >> 0x18)) * local_4bc +
                               ((uVar4 >> 0x18) + (uVar35 >> 0x18) + (uVar34 >> 0x18) +
                               (uVar33 >> 0x18)) * local_494 +
                               ((uVar32 >> 0x18) + (uVar31 >> 0x18) + (uVar30 >> 0x18) +
                               (uVar29 >> 0x18)) * local_498 +
                              ((uVar24 >> 0x18) + (uVar27 >> 0x18) + (local_518 >> 0x18) +
                              (local_51c >> 0x18)) * local_49c) >> 1) +
                        (uVar22 >> 0x18) * local_4d0[0] >> 0x10);
            local_5f8 = local_5f8 + 1;
            local_5f4 = local_5f4 + 1;
            local_5e4 = local_5e4 + 1;
            local_5e8 = (uint *)((int)local_5e8 + 4);
            local_4dc = (uint *)((int)local_4dc + 1);
          } while (local_4dc < uVar62);
        }
        local_5e4 = (uint *)((int)local_5e4 + local_48c);
        local_5e8 = (uint *)((int)local_5e8 + local_490);
        local_5f0 = local_5f0 + 1;
      } while (local_5f0 < local_5ec);
    }
    FUN_005421c0(local_440);
  }
  FUN_00586b00();
  return 0;
}

