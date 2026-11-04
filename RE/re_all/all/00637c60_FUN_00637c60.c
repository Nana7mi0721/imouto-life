
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00637c60(int param_1,int param_2,int param_3)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  float *pfVar5;
  undefined4 *puVar6;
  float *pfVar7;
  undefined4 uVar8;
  float *pfVar9;
  uint uVar10;
  float *pfVar11;
  float fVar12;
  undefined4 *puVar13;
  float10 fVar14;
  uint uVar15;
  int iVar16;
  float fVar17;
  float local_550;
  float local_54c;
  float local_548;
  float local_544;
  uint local_540;
  uint local_53c;
  float local_538;
  uint local_534;
  float local_530;
  float local_52c;
  int local_528;
  float local_524;
  float local_520;
  float local_51c;
  float local_518;
  float local_514;
  float local_510;
  float local_50c;
  undefined4 local_508;
  float local_504;
  float local_500;
  float local_4fc;
  undefined4 local_4f8;
  undefined4 local_4f4;
  float local_4f0;
  float local_4ec;
  float local_4e8;
  float local_4e4;
  float local_4e0;
  uint local_4dc;
  float local_4d8;
  float local_4d4;
  float local_4d0;
  float local_4cc;
  float local_4c8;
  float local_4c4;
  float local_4c0;
  float local_4bc [3];
  undefined4 local_4b0;
  float local_4ac;
  float local_4a8;
  float local_4a4;
  float local_4a0;
  float local_498;
  float local_494;
  float local_490;
  float local_48c;
  float local_488;
  float local_484;
  float local_480;
  float local_47c;
  float local_478;
  float local_474;
  float local_470;
  float local_468;
  float local_464;
  float local_460;
  float local_458 [9];
  float local_434;
  float local_430;
  undefined4 local_42c;
  float local_428 [13];
  float local_3f4;
  float local_3f0;
  float local_3ec;
  float local_3e8;
  float local_3e4;
  float local_3e0;
  undefined4 local_3dc;
  float local_3d8 [13];
  undefined4 local_3a4;
  undefined4 local_3a0;
  undefined4 local_39c;
  float local_398;
  float local_394;
  float local_390;
  float local_38c;
  undefined4 local_388;
  undefined4 local_384;
  undefined4 local_380;
  undefined4 local_37c;
  float local_378;
  float local_374;
  float local_370;
  float local_368;
  float local_364;
  float local_360;
  float local_358;
  float local_354;
  float local_350;
  float local_348;
  float local_344;
  float local_340;
  float local_338;
  float local_334;
  float local_330;
  float local_328;
  float local_324;
  float local_320;
  float local_318;
  float local_314;
  float local_310;
  undefined1 local_308 [16];
  float local_2f8;
  float local_2f4;
  float local_2f0;
  undefined1 local_2e8 [16];
  undefined1 local_2d8 [16];
  undefined1 local_2c8 [16];
  undefined1 local_2b8 [16];
  undefined1 local_2a8 [16];
  undefined1 local_298 [16];
  undefined1 local_288 [16];
  undefined1 local_278 [16];
  float local_268 [4];
  undefined1 local_258 [16];
  undefined1 local_248 [16];
  float local_238 [4];
  undefined1 local_228 [16];
  float local_218 [4];
  undefined1 local_208 [16];
  float local_1f8 [4];
  undefined1 local_1e8 [16];
  undefined1 local_1d8 [16];
  undefined1 local_1c8 [16];
  undefined1 local_1b8 [16];
  undefined1 local_1a8 [16];
  undefined1 local_198 [16];
  undefined1 local_188 [16];
  undefined1 local_178 [16];
  undefined1 local_168 [16];
  undefined1 local_158 [16];
  undefined1 local_148 [16];
  undefined1 local_138 [16];
  undefined1 local_128 [16];
  undefined1 local_118 [16];
  undefined1 local_108 [16];
  undefined1 local_f8 [16];
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  undefined4 local_88 [34];
  
  uVar10 = *(uint *)(param_2 + 0x298);
  uVar15 = *(uint *)(param_2 + 0x294);
  local_520 = -NAN;
  local_51c = -NAN;
  local_540 = uVar15;
  local_534 = uVar10;
  local_528 = param_1;
  if (*(int *)(param_2 + 0x29c) == 0) goto LAB_00637d76;
  fVar12 = *(float *)(uVar15 + 0xd0);
  if ((int)*(float *)(uVar15 + 0xd0) < 0) {
    if (((*(int *)(uVar15 + 0xe8) == 2) && (uVar15 != 0)) &&
       (*(float *)(uVar15 + 0x150) != _DAT_007d5344)) {
      local_4f0 = *(float *)(param_1 + 8);
      uVar3 = FUN_0061ddb0();
      uVar3 = FUN_0063ac90(uVar3);
      FUN_006371f0(uVar3,uVar15);
      *(float *)(uVar15 + 0xd0) = local_4f0;
      fVar12 = local_4f0;
      goto LAB_00637cff;
    }
    local_520 = 0.0;
  }
  else {
LAB_00637cff:
    local_520 = fVar12;
  }
  fVar12 = *(float *)(uVar10 + 0xd0);
  if ((int)fVar12 < 0) {
    if (((*(int *)(uVar10 + 0xe8) == 2) && (uVar10 != 0)) &&
       (*(float *)(uVar10 + 0x150) != _DAT_007d5344)) {
      fVar12 = *(float *)(param_1 + 8);
      uVar3 = FUN_0061ddb0();
      uVar3 = FUN_0063ac90(uVar3);
      FUN_006371f0(uVar3,uVar10);
      *(float *)(uVar10 + 0xd0) = fVar12;
    }
    else {
      fVar12 = 0.0;
    }
  }
  local_51c = fVar12;
  if ((local_520 == 0.0) && (fVar12 == 0.0)) {
    return;
  }
LAB_00637d76:
  local_4f0 = 0.0;
  if (0 < *(int *)(param_2 + 0x29c)) {
    do {
      fVar12 = (float)(param_2 + 4 + (int)local_4f0 * 0xa4);
      if (*(float *)(param_2 + 0x54 + (int)local_4f0 * 0xa4) <= *(float *)(param_2 + 0x2a4)) {
        local_54c = *(float *)((int)fVar12 + 0x38) - *(float *)(local_540 + 0x3c);
        local_544 = *(float *)((int)fVar12 + 0x34) - *(float *)(local_540 + 0x38);
        local_550 = *(float *)((int)fVar12 + 0x30) - *(float *)(local_540 + 0x34);
        FUN_005fc500(&local_550,&local_544,&local_54c);
        local_504 = local_3e8;
        local_4fc = local_3e0;
        local_500 = local_3e4;
        local_4f8 = local_3dc;
        local_54c = *(float *)((int)fVar12 + 0x28) - *(float *)(local_534 + 0x3c);
        local_544 = *(float *)((int)fVar12 + 0x24) - *(float *)(local_534 + 0x38);
        local_550 = *(float *)((int)fVar12 + 0x20) - *(float *)(local_534 + 0x34);
        FUN_005fc500(&local_550,&local_544,&local_54c);
        iVar16 = local_528;
        local_510 = local_434;
        local_50c = local_430;
        local_514 = local_458[8];
        local_4f4 = *(undefined4 *)(local_528 + 0x1c);
        iVar1 = *(int *)(local_528 + 0x1c);
        local_508 = local_42c;
        if (iVar1 == *(int *)(local_528 + 0x20)) {
          iVar4 = iVar1 * 2;
          if (iVar1 == 0) {
            iVar4 = 1;
          }
          FUN_0063af40(iVar4);
        }
        *(int *)(iVar16 + 0x1c) = *(int *)(iVar16 + 0x1c) + 1;
        puVar13 = (undefined4 *)(iVar1 * 0x88 + *(int *)(iVar16 + 0x24));
        if (puVar13 != (undefined4 *)0x0) {
          puVar6 = local_88;
          for (iVar4 = 0x22; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar13 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar13 = puVar13 + 1;
          }
        }
        pfVar5 = (float *)(iVar1 * 0x88 + *(int *)(iVar16 + 0x24));
        uVar10 = (*(int *)(local_540 + 0xe8) != 2) - 1 & local_540;
        iVar1 = *(int *)(local_534 + 0xe8);
        pfVar5[0x1c] = fVar12;
        pfVar5[0x1b] = local_51c;
        local_53c = (iVar1 != 2) - 1 & local_534;
        pfVar5[0x1a] = local_520;
        pfVar7 = (float *)((int)fVar12 + 0x40);
        local_54c = local_504 * *(float *)((int)fVar12 + 0x44) - local_500 * *pfVar7;
        local_544 = local_4fc * *pfVar7 - local_504 * *(float *)((int)fVar12 + 0x48);
        local_550 = local_500 * *(float *)((int)fVar12 + 0x48) -
                    local_4fc * *(float *)((int)fVar12 + 0x44);
        local_4dc = uVar10;
        FUN_005fc500(&local_550,&local_544,&local_54c);
        if (uVar10 == 0) {
          local_3d8[0] = 0.0;
          local_3d8[1] = 0.0;
          local_3d8[2] = 0.0;
          local_3d8[3] = 0.0;
          pfVar9 = local_3d8;
        }
        else {
          fVar14 = (float10)FUN_005fcc30(local_308);
          local_4bc[0] = (float)fVar14;
          fVar14 = (float10)FUN_005fcc30(local_308);
          local_4c0 = (float)fVar14;
          fVar14 = (float10)FUN_005fcc30(local_308);
          local_4bc[2] = (float)fVar14;
          FUN_005fc500(local_4bc + 2,&local_4c0,local_4bc);
          local_54c = local_370 * *(float *)(uVar10 + 0x15c);
          local_544 = local_374 * *(float *)(uVar10 + 0x158);
          local_550 = local_378 * *(float *)(uVar10 + 0x154);
          FUN_005fc500(&local_550,&local_544,&local_54c);
          pfVar9 = local_268;
        }
        pfVar5[0xc] = *pfVar9;
        pfVar5[0xd] = pfVar9[1];
        fVar17 = pfVar9[3];
        pfVar5[0xe] = pfVar9[2];
        pfVar5[0xf] = fVar17;
        local_54c = local_514 * *(float *)((int)fVar12 + 0x44) - local_510 * *pfVar7;
        local_544 = local_50c * *pfVar7 - local_514 * *(float *)((int)fVar12 + 0x48);
        local_550 = local_510 * *(float *)((int)fVar12 + 0x48) -
                    local_50c * *(float *)((int)fVar12 + 0x44);
        FUN_005fc500(&local_550,&local_544,&local_54c);
        if (local_53c == 0) {
          local_428[4] = 0.0;
          local_428[5] = 0.0;
          local_428[6] = 0.0;
          local_428[7] = 0.0;
          pfVar9 = local_428 + 4;
        }
        else {
          local_54c = -local_340;
          local_544 = -local_344;
          local_550 = -local_348;
          FUN_005fc500(&local_550,&local_544,&local_54c);
          fVar14 = (float10)FUN_005fcc30(local_2e8);
          local_4c8 = (float)fVar14;
          fVar14 = (float10)FUN_005fcc30(local_2e8);
          local_4ac = (float)fVar14;
          fVar14 = (float10)FUN_005fcc30(local_2e8);
          local_4c4 = (float)fVar14;
          FUN_005fc500(&local_4c4,&local_4ac,&local_4c8);
          local_518 = local_2f0 * *(float *)(local_53c + 0x15c);
          local_530 = local_2f4 * *(float *)(local_53c + 0x158);
          local_52c = local_2f8 * *(float *)(local_53c + 0x154);
          FUN_005fc500(&local_52c,&local_530,&local_518);
          pfVar9 = local_218;
        }
        pfVar5[0x10] = *pfVar9;
        local_4d0 = 0.0;
        local_4e4 = 0.0;
        pfVar5[0x11] = pfVar9[1];
        fVar17 = pfVar9[3];
        pfVar5[0x12] = pfVar9[2];
        pfVar5[0x13] = fVar17;
        if (uVar10 != 0) {
          local_52c = local_500 * pfVar5[0xc] - local_504 * pfVar5[0xd];
          local_530 = local_504 * pfVar5[0xe] - local_4fc * pfVar5[0xc];
          local_54c = local_4fc * pfVar5[0xd] - local_500 * pfVar5[0xe];
          FUN_005fc500(&local_54c,&local_530,&local_52c);
          local_4d0 = local_318 * *pfVar7 +
                      local_310 * *(float *)((int)fVar12 + 0x48) +
                      local_314 * *(float *)((int)fVar12 + 0x44) + *(float *)(uVar10 + 0x150);
        }
        if (local_53c != 0) {
          local_52c = -pfVar5[0x12];
          local_530 = -pfVar5[0x11];
          local_54c = -pfVar5[0x10];
          FUN_005fc500(&local_54c,&local_530,&local_52c);
          local_544 = local_510 * local_4a8 - local_4a4 * local_514;
          local_4e4 = local_4a0 * local_514 - local_50c * local_4a8;
          local_550 = local_50c * local_4a4 - local_4a0 * local_510;
          FUN_005fc500(&local_550,&local_4e4,&local_544);
          local_4e4 = local_338 * *pfVar7 +
                      local_330 * *(float *)((int)fVar12 + 0x48) +
                      local_334 * *(float *)((int)fVar12 + 0x44) + *(float *)(local_53c + 0x150);
        }
        pfVar5[0x17] = _DAT_00804108 / (local_4e4 + local_4d0);
        pfVar5[4] = *pfVar7;
        pfVar5[5] = *(float *)((int)fVar12 + 0x44);
        pfVar5[6] = *(float *)((int)fVar12 + 0x48);
        pfVar5[7] = *(float *)((int)fVar12 + 0x4c);
        local_52c = local_504 * *(float *)((int)fVar12 + 0x44) - local_500 * *pfVar7;
        local_530 = local_4fc * *pfVar7 - local_504 * *(float *)((int)fVar12 + 0x48);
        local_54c = local_500 * *(float *)((int)fVar12 + 0x48) -
                    local_4fc * *(float *)((int)fVar12 + 0x44);
        FUN_005fc500(&local_54c,&local_530,&local_52c);
        *pfVar5 = local_398;
        pfVar5[1] = local_394;
        pfVar5[2] = local_390;
        pfVar5[3] = local_38c;
        local_52c = -*(float *)((int)fVar12 + 0x48);
        local_530 = -*(float *)((int)fVar12 + 0x44);
        local_54c = -*pfVar7;
        FUN_005fc500(&local_54c,&local_530,&local_52c);
        local_544 = local_474 * local_514 - local_510 * local_478;
        local_550 = local_50c * local_478 - local_470 * local_514;
        local_518 = local_470 * local_510 - local_474 * local_50c;
        FUN_005fc500(&local_518,&local_550,&local_544);
        pfVar5[8] = local_428[0xc];
        pfVar5[9] = local_3f4;
        pfVar5[10] = local_3f0;
        pfVar5[0xb] = local_3ec;
        if (uVar10 == 0) {
          local_3d8[8] = 0.0;
          local_3d8[9] = 0.0;
          local_3d8[10] = 0.0;
          local_3d8[0xb] = 0.0;
          pfVar9 = local_3d8 + 8;
        }
        else {
          uVar3 = FUN_006170e0(local_f8,&local_504);
          FUN_0060f480(local_238,uVar10 + 0x130,uVar3);
          pfVar9 = local_238;
        }
        local_498 = *pfVar9;
        local_494 = pfVar9[1];
        local_490 = pfVar9[2];
        local_48c = pfVar9[3];
        if (local_53c == 0) {
          local_458[4] = 0.0;
          local_458[5] = 0.0;
          local_458[6] = 0.0;
          local_458[7] = 0.0;
          pfVar9 = local_458 + 4;
        }
        else {
          uVar3 = FUN_006170e0(local_1b8,&local_514);
          FUN_0060f480(local_1f8,local_53c + 0x130,uVar3);
          pfVar9 = local_1f8;
        }
        local_488 = *pfVar9;
        local_484 = pfVar9[1];
        local_480 = pfVar9[2];
        local_52c = local_490 - local_480;
        local_47c = pfVar9[3];
        local_530 = local_494 - local_484;
        local_54c = local_498 - local_488;
        FUN_005fc500(&local_54c,&local_530,&local_52c);
        local_518 = local_468 * *pfVar7 +
                    local_460 * *(float *)((int)fVar12 + 0x48) +
                    local_464 * *(float *)((int)fVar12 + 0x44);
        local_54c = *(float *)((int)fVar12 + 0x50) + *(float *)(param_3 + 0x34);
        pfVar5[0x16] = *(float *)((int)fVar12 + 0x54);
        if ((*(int *)(param_3 + 0x40) < *(int *)((int)fVar12 + 0x80)) ||
           (local_4e0 = -(local_518 * *(float *)((int)fVar12 + 0x58)), local_4e0 <= _DAT_007d5344))
        {
          local_4e0 = 0.0;
        }
        if ((*(byte *)(param_3 + 0x3c) & 4) == 0) {
          pfVar5[0x15] = 0.0;
        }
        else {
          pfVar5[0x15] = *(float *)((int)fVar12 + 0x70) * *(float *)(param_3 + 0x38);
          if (uVar10 != 0) {
            local_544 = *(float *)(uVar10 + 0x150);
            local_52c = local_544 * pfVar5[6];
            local_530 = local_544 * pfVar5[5];
            local_544 = local_544 * pfVar5[4];
            FUN_005fc500(&local_544,&local_530,&local_52c);
            local_4d8 = local_320 * *(float *)(uVar10 + 0x16c);
            local_4e8 = local_324 * *(float *)(uVar10 + 0x168);
            local_4ec = local_328 * *(float *)(uVar10 + 0x164);
            FUN_005fc500(&local_4ec,&local_4e8,&local_4d8);
            local_4cc = pfVar5[0x15];
            local_550 = (float)(*(int *)(local_528 + 0x10) + (int)pfVar5[0x1a] * 0x68);
            uVar3 = FUN_0060fe40(local_118,local_258,&local_4cc);
            FUN_00612f50(uVar3);
            FUN_0060fe40(local_248,(int)local_550 + 0x20,&local_4cc);
            uVar3 = FUN_005fc560(local_198,pfVar5 + 0xc,local_248);
            FUN_00612f50(uVar3);
          }
          if (local_53c != 0) {
            local_550 = *(float *)(local_53c + 0x150);
            local_4ec = -pfVar5[0x12];
            local_4e8 = -pfVar5[0x11];
            local_4d8 = -pfVar5[0x10];
            FUN_005fc500(&local_4d8,&local_4e8,&local_4ec);
            local_52c = local_550 * pfVar5[6];
            local_530 = local_550 * pfVar5[5];
            local_4d4 = local_550 * pfVar5[4];
            FUN_005fc500(&local_4d4,&local_530,&local_52c);
            local_524 = local_360 * *(float *)(local_53c + 0x16c);
            local_538 = local_364 * *(float *)(local_53c + 0x168);
            local_548 = local_368 * *(float *)(local_53c + 0x164);
            FUN_005fc500(&local_548,&local_538,&local_524);
            local_544 = -pfVar5[0x15];
            local_550 = (float)(*(int *)(local_528 + 0x10) + (int)pfVar5[0x1b] * 0x68);
            uVar3 = FUN_0060fe40(local_98,local_228,&local_544);
            FUN_00612f50(uVar3);
            FUN_0060fe40(local_208,(int)local_550 + 0x20,&local_544);
            uVar3 = FUN_005fc560(local_178,local_1e8,local_208);
            FUN_00612f50(uVar3);
          }
        }
        pfVar5[0x14] = 0.0;
        if (uVar10 == 0) {
          local_428[0] = 0.0;
          local_428[1] = 0.0;
          local_428[2] = 0.0;
          local_428[3] = 0.0;
          pfVar9 = local_428;
          local_428[8] = 0.0;
          local_428[9] = 0.0;
          local_428[10] = 0.0;
          local_428[0xb] = 0.0;
          pfVar11 = local_428 + 8;
        }
        else {
          pfVar9 = (float *)(uVar10 + 0x130);
          pfVar11 = (float *)(uVar10 + 0x140);
        }
        local_548 = *pfVar5 * *pfVar11 +
                    pfVar5[4] * *pfVar9 +
                    pfVar11[1] * pfVar5[1] +
                    pfVar11[2] * pfVar5[2] + pfVar5[5] * pfVar9[1] + pfVar5[6] * pfVar9[2];
        if (local_53c == 0) {
          local_458[0] = 0.0;
          local_458[1] = 0.0;
          local_458[2] = 0.0;
          local_458[3] = 0.0;
          pfVar9 = local_458;
          local_3d8[4] = 0.0;
          local_3d8[5] = 0.0;
          local_3d8[6] = 0.0;
          local_3d8[7] = 0.0;
          pfVar11 = local_3d8 + 4;
        }
        else {
          pfVar9 = (float *)(local_53c + 0x130);
          pfVar11 = (float *)(local_53c + 0x140);
        }
        fVar17 = -((local_54c * *(float *)(param_3 + 0x20)) / *(float *)(param_3 + 0xc)) *
                 pfVar5[0x17];
        fVar2 = (local_4e0 -
                (pfVar5[8] * *pfVar11 +
                 ((pfVar5[9] * pfVar11[1] +
                  ((pfVar5[10] * pfVar11[2] - pfVar5[6] * pfVar9[2]) - pfVar5[5] * pfVar9[1])) -
                 pfVar5[4] * *pfVar9) + local_548)) * pfVar5[0x17];
        if ((*(int *)(param_3 + 0x2c) == 0) || (*(float *)(param_3 + 0x30) < local_54c)) {
          pfVar5[0x21] = 0.0;
          pfVar5[0x1d] = fVar2 + fVar17;
        }
        else {
          pfVar5[0x1d] = fVar2;
          pfVar5[0x21] = fVar17;
        }
        pfVar5[0x1e] = 0.0;
        pfVar5[0x1f] = 0.0;
        pfVar5[0x20] = 1e+10;
        pfVar5[0x19] = *(float *)(local_528 + 0x44);
        if (((*(byte *)(param_3 + 0x3c) & 0x20) == 0) || (*(char *)((int)fVar12 + 0x74) == '\0')) {
          local_548 = local_518 * *(float *)((int)fVar12 + 0x48);
          local_538 = local_518 * *(float *)((int)fVar12 + 0x44);
          local_524 = local_518 * *pfVar7;
          FUN_005fc500(&local_524,&local_538,&local_548);
          local_4d4 = local_460 - local_350;
          local_4ec = local_464 - local_354;
          local_4e8 = local_468 - local_358;
          FUN_005fc500(&local_4e8,&local_4ec,&local_4d4);
          pfVar9 = (float *)((int)fVar12 + 0x84);
          *pfVar9 = local_3d8[0xc];
          *(undefined4 *)((int)fVar12 + 0x88) = local_3a4;
          *(undefined4 *)((int)fVar12 + 0x8c) = local_3a0;
          *(undefined4 *)((int)fVar12 + 0x90) = local_39c;
          fVar14 = (float10)FUN_005fcc30(pfVar9);
          local_54c = (float)fVar14;
          if (((*(byte *)(param_3 + 0x3c) & 0x40) != 0) || (local_54c <= _DAT_00804520)) {
            if (ABS(*(float *)((int)fVar12 + 0x48)) <= _DAT_0080451c) {
              local_54c = *(float *)((int)fVar12 + 0x44) * *(float *)((int)fVar12 + 0x44) +
                          *pfVar7 * *pfVar7;
              local_4bc[1] = 0.0;
              local_550 = _DAT_00804108 / SQRT(local_54c);
              local_548 = local_550 * *pfVar7;
              local_538 = -(local_550 * *(float *)((int)fVar12 + 0x44));
              FUN_005fc530(&local_538,&local_548,local_4bc + 1);
              local_548 = local_550 * local_54c;
              local_538 = *(float *)((int)fVar12 + 0x48) * *pfVar9;
              local_524 = -(*(float *)((int)fVar12 + 0x88) * *(float *)((int)fVar12 + 0x48));
            }
            else {
              local_54c = *(float *)((int)fVar12 + 0x48) * *(float *)((int)fVar12 + 0x48) +
                          *(float *)((int)fVar12 + 0x44) * *(float *)((int)fVar12 + 0x44);
              local_4b0 = 0;
              local_550 = _DAT_00804108 / SQRT(local_54c);
              local_548 = local_550 * *(float *)((int)fVar12 + 0x44);
              local_538 = -(local_550 * *(float *)((int)fVar12 + 0x48));
              FUN_005fc530(&local_4b0,&local_538,&local_548);
              local_548 = *(float *)((int)fVar12 + 0x88) * *pfVar7;
              local_538 = -(*(float *)((int)fVar12 + 0x8c) * *pfVar7);
              local_524 = local_550 * local_54c;
            }
            FUN_005fc530(&local_524,&local_538,&local_548);
            if ((*(byte *)(param_3 + 0x3c) & 0x10) == 0) {
              uVar10 = local_534;
            }
            else {
              if ((local_540 != 0) && (*(char *)(local_540 + 0xb4) != '\0')) {
                local_548 = (float)(local_540 + 4);
                FUN_0063ab90(local_2b8,(undefined4 *)((int)fVar12 + 0x94),local_548);
                FUN_0063ab60(local_540 + 0xa4);
                puVar13 = (undefined4 *)FUN_005fc730(local_d8,local_548,local_2b8);
                *(undefined4 *)((int)fVar12 + 0x94) = *puVar13;
                *(undefined4 *)((int)fVar12 + 0x98) = puVar13[1];
                *(undefined4 *)((int)fVar12 + 0x9c) = puVar13[2];
                *(undefined4 *)((int)fVar12 + 0xa0) = puVar13[3];
              }
              uVar10 = local_534;
              if ((local_534 != 0) && (*(char *)(local_534 + 0xb4) != '\0')) {
                FUN_0063ab90(local_298,(int)fVar12 + 0x94,local_534 + 4);
                FUN_0063ab60(uVar10 + 0xa4);
                puVar13 = (undefined4 *)FUN_005fc730(local_1c8,uVar10 + 4,local_298);
                *(undefined4 *)((int)fVar12 + 0x94) = *puVar13;
                *(undefined4 *)((int)fVar12 + 0x98) = puVar13[1];
                *(undefined4 *)((int)fVar12 + 0x9c) = puVar13[2];
                *(undefined4 *)((int)fVar12 + 0xa0) = puVar13[3];
              }
              FUN_00637400((int)fVar12 + 0x94,local_520,local_51c,local_4f4,fVar12,&local_504,
                           &local_514,local_540,uVar10,0x3f800000);
            }
            if ((local_540 != 0) && (*(char *)(local_540 + 0xb4) != '\0')) {
              FUN_0063ab90(local_278,pfVar9,local_540 + 4);
              FUN_0063ab60(local_540 + 0xa4);
              pfVar7 = (float *)FUN_005fc730(local_1a8,local_540 + 4,local_278);
              *pfVar9 = *pfVar7;
              *(float *)((int)fVar12 + 0x88) = pfVar7[1];
              *(float *)((int)fVar12 + 0x8c) = pfVar7[2];
              *(float *)((int)fVar12 + 0x90) = pfVar7[3];
            }
            FUN_00637320(uVar10,pfVar9);
            uVar15 = local_540;
          }
          else {
            local_548 = _DAT_00804108 / SQRT(local_54c);
            FUN_0061a860(&local_548);
            if ((*(byte *)(param_3 + 0x3c) & 0x10) != 0) {
              local_548 = *pfVar9 * *(float *)((int)fVar12 + 0x44) -
                          *(float *)((int)fVar12 + 0x88) * *pfVar7;
              local_538 = *(float *)((int)fVar12 + 0x8c) * *pfVar7 -
                          *(float *)((int)fVar12 + 0x48) * *pfVar9;
              local_524 = *(float *)((int)fVar12 + 0x88) * *(float *)((int)fVar12 + 0x48) -
                          *(float *)((int)fVar12 + 0x8c) * *(float *)((int)fVar12 + 0x44);
              FUN_005fc500(&local_524,&local_538,&local_548);
              puVar13 = (undefined4 *)((int)fVar12 + 0x94);
              *puVar13 = local_388;
              *(undefined4 *)((int)fVar12 + 0x98) = local_384;
              *(undefined4 *)((int)fVar12 + 0x9c) = local_380;
              *(undefined4 *)((int)fVar12 + 0xa0) = local_37c;
              fVar14 = (float10)FUN_005fcc30(puVar13);
              local_548 = (float)((float10)_DAT_00804108 / SQRT(fVar14));
              FUN_0061a860(&local_548);
              if ((local_540 != 0) && (*(char *)(local_540 + 0xb4) != '\0')) {
                FUN_0063ab90(local_2d8,puVar13,local_540 + 4);
                FUN_0063ab60(local_540 + 0xa4);
                puVar6 = (undefined4 *)FUN_005fc730(local_1d8,local_540 + 4,local_2d8);
                *puVar13 = *puVar6;
                *(undefined4 *)((int)fVar12 + 0x98) = puVar6[1];
                *(undefined4 *)((int)fVar12 + 0x9c) = puVar6[2];
                *(undefined4 *)((int)fVar12 + 0xa0) = puVar6[3];
              }
              if ((local_534 != 0) && (*(char *)(local_534 + 0xb4) != '\0')) {
                FUN_0063ab90(local_288,puVar13,local_534 + 4);
                FUN_0063ab60(local_534 + 0xa4);
                puVar6 = (undefined4 *)FUN_005fc730(local_158,local_534 + 4,local_288);
                *puVar13 = *puVar6;
                *(undefined4 *)((int)fVar12 + 0x98) = puVar6[1];
                *(undefined4 *)((int)fVar12 + 0x9c) = puVar6[2];
                *(undefined4 *)((int)fVar12 + 0xa0) = puVar6[3];
              }
              FUN_00637400(puVar13,local_520,local_51c,local_4f4,fVar12,&local_504,&local_514,
                           local_540,local_534,0x3f800000);
            }
            uVar15 = local_540;
            if ((local_540 != 0) && (*(char *)(local_540 + 0xb4) != '\0')) {
              FUN_0063ab90(local_2a8,pfVar9,local_540 + 4);
              FUN_0063ab60(uVar15 + 0xa4);
              pfVar7 = (float *)FUN_005fc730(local_b8,uVar15 + 4,local_2a8);
              *pfVar9 = *pfVar7;
              *(float *)((int)fVar12 + 0x88) = pfVar7[1];
              *(float *)((int)fVar12 + 0x8c) = pfVar7[2];
              *(float *)((int)fVar12 + 0x90) = pfVar7[3];
            }
            if ((local_534 != 0) && (*(char *)(local_534 + 0xb4) != '\0')) {
              FUN_0063ab90(local_2c8,pfVar9,local_534 + 4);
              FUN_0063ab60(local_534 + 0xa4);
              pfVar7 = (float *)FUN_005fc730(local_138,local_534 + 4,local_2c8);
              *pfVar9 = *pfVar7;
              *(float *)((int)fVar12 + 0x88) = pfVar7[1];
              *(float *)((int)fVar12 + 0x8c) = pfVar7[2];
              *(float *)((int)fVar12 + 0x90) = pfVar7[3];
            }
            uVar10 = local_534;
          }
          FUN_00637400(pfVar9,local_520,local_51c,local_4f4,fVar12,&local_504,&local_514,uVar15,
                       uVar10,0x3f800000);
          *(undefined1 *)((int)fVar12 + 0x74) = 1;
        }
        else {
          FUN_00637400((int)fVar12 + 0x84,local_520,local_51c,local_4f4,fVar12,&local_504,&local_514
                       ,local_540,local_534,0x3f800000);
          if ((*(byte *)(param_3 + 0x3c) & 0x10) != 0) {
            FUN_00637400((int)fVar12 + 0x94,local_520,local_51c,local_4f4,fVar12,&local_504,
                         &local_514,local_540,local_534,0x3f800000);
          }
        }
        iVar1 = local_528;
        if ((*(uint *)(param_3 + 0x3c) & 8) == 0) {
          *(undefined4 *)(*(int *)(local_528 + 0x4c) + 0x54 + (int)pfVar5[0x19] * 0x88) = 0;
          if ((*(byte *)(param_3 + 0x3c) & 0x10) != 0) {
            *(undefined4 *)(*(int *)(local_528 + 0x4c) + 0xdc + (int)pfVar5[0x19] * 0x88) = 0;
          }
        }
        else {
          iVar16 = *(int *)(local_528 + 0x4c) + (int)pfVar5[0x19] * 0x88;
          if ((*(uint *)(param_3 + 0x3c) & 4) == 0) {
            *(undefined4 *)(iVar16 + 0x54) = 0;
          }
          else {
            fVar17 = *(float *)((int)fVar12 + 0x78) * *(float *)(param_3 + 0x38);
            *(float *)(iVar16 + 0x54) = fVar17;
            local_548 = fVar17;
            if (local_4dc != 0) {
              local_538 = *(float *)(local_4dc + 0x150);
              local_524 = (float)(*(int *)(local_528 + 0x10) + (int)pfVar5[0x1a] * 0x68);
              iVar4 = iVar16 + 0x30;
              uVar3 = FUN_0060fe40(local_188,iVar16 + 0x10,&local_538,local_4dc + 0x164,iVar4,fVar17
                                  );
              uVar3 = FUN_005fc560(local_168,uVar3);
              FUN_0063abf0(uVar3,iVar4,fVar17);
            }
            if (local_53c != 0) {
              local_548 = *(float *)(local_53c + 0x150);
              fVar17 = -*(float *)(iVar16 + 0x54);
              local_538 = (float)(*(int *)(iVar1 + 0x10) + (int)pfVar5[0x1b] * 0x68);
              uVar3 = FUN_005fc5c0(local_148,iVar16 + 0x40,fVar17);
              uVar8 = FUN_0060fe40(local_128,iVar16 + 0x10,&local_548,local_53c + 0x164,uVar3);
              uVar8 = FUN_005fc560(local_108,uVar8);
              FUN_0063abf0(uVar8,uVar3,fVar17);
            }
          }
          if ((*(uint *)(param_3 + 0x3c) & 0x10) != 0) {
            iVar1 = *(int *)(iVar1 + 0x4c) + ((int)pfVar5[0x19] + 1) * 0x88;
            if ((*(uint *)(param_3 + 0x3c) & 4) == 0) {
              *(undefined4 *)(iVar1 + 0x54) = 0;
            }
            else {
              fVar12 = *(float *)((int)fVar12 + 0x7c) * *(float *)(param_3 + 0x38);
              *(float *)(iVar1 + 0x54) = fVar12;
              local_548 = fVar12;
              if (local_4dc != 0) {
                local_538 = *(float *)(local_4dc + 0x150);
                iVar16 = iVar1 + 0x30;
                uVar3 = FUN_0060fe40(local_e8,iVar1 + 0x10,&local_538,iVar16,fVar12);
                FUN_0063abf0(uVar3,iVar16,fVar12);
              }
              if (local_53c != 0) {
                local_548 = *(float *)(local_53c + 0x150);
                fVar12 = -*(float *)(iVar1 + 0x54);
                uVar3 = FUN_005fc5c0(local_c8,iVar1 + 0x40,fVar12);
                uVar8 = FUN_0060fe40(local_a8,iVar1 + 0x10,&local_548,uVar3);
                FUN_0063abf0(uVar8,uVar3,fVar12);
              }
            }
          }
        }
      }
      local_4f0 = (float)((int)local_4f0 + 1);
    } while ((int)local_4f0 < *(int *)(param_2 + 0x29c));
  }
  return;
}

