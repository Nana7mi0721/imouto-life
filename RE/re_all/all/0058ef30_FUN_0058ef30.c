
undefined4 FUN_0058ef30(int param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  undefined1 uVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  byte *local_4a8;
  byte *local_4a4;
  int local_4a0;
  byte *local_49c;
  byte *local_498;
  uint local_494;
  int local_490;
  int local_48c;
  byte *local_488;
  byte *local_484;
  byte *local_480;
  undefined1 *local_47c;
  int local_478;
  byte *local_474;
  int local_470;
  int local_46c;
  int local_468;
  int local_464;
  int local_460;
  int local_45c;
  int local_458;
  byte *local_454;
  undefined4 local_450;
  undefined4 local_44c;
  byte *local_448;
  byte *local_444;
  undefined1 local_440 [1064];
  byte *local_18;
  int local_14;
  int local_10;
  byte *local_c;
  
  if (DAT_00a37dc8 == 1) {
    FUN_005dbad0(param_1,param_2);
    return 0;
  }
  if ((*(int *)(param_1 + 4) == 0xe) || (*(int *)(param_1 + 4) == 0xf)) {
    local_488 = (byte *)0x1;
    FUN_00515880(*(undefined4 *)(param_1 + 8),&local_474,&local_4a8);
    FUN_00515880(param_2,&local_480,&local_484);
    if (*(int *)(param_1 + 0x20) != 0) {
      return 0xffffffff;
    }
    if (*(int *)(param_1 + 0x24) != 0) {
      return 0xffffffff;
    }
    if (*(int *)(param_1 + 0x28) != (int)local_474 / 2) {
      return 0xffffffff;
    }
    if (*(byte **)(param_1 + 0x2c) != local_4a8) {
      return 0xffffffff;
    }
    local_448 = local_474;
    local_444 = local_4a8;
    local_450 = 0;
    local_44c = 0;
    iVar3 = FUN_00586970(param_1,1);
  }
  else {
    local_488 = (byte *)0x0;
    iVar3 = FUN_00586970(param_1,1);
  }
  if ((iVar3 < 0) || (iVar3 = FUN_005866a0(param_2,local_440,0), iVar3 < 0)) {
    return 0xffffffff;
  }
  local_49c = *(byte **)(param_1 + 0x48c);
  local_4a0 = *(int *)(param_1 + 0xd0c);
  local_4a4 = local_c;
  FUN_00515880(*(undefined4 *)(param_1 + 8),&local_454,&local_458);
  local_494 = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24);
  local_47c = (undefined1 *)(*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20));
  local_478 = *(int *)(param_1 + 0x488);
  local_470 = *(int *)(param_1 + 0xd08);
  local_468 = local_10;
  local_46c = (*(int *)(param_1 + 0x480) / 2) * 4;
  iVar3 = ((int)local_18 / 2) * 4;
  if ((local_454 == local_18) && (local_458 == local_14)) {
    if (local_488 == (byte *)0x0) {
      do {
        local_474 = local_49c + -(int)local_4a4;
        puVar9 = (undefined1 *)(local_4a0 + 2);
        local_4a8 = (byte *)(local_4a0 - (int)local_4a4);
        pbVar8 = local_4a4;
        local_498 = local_47c;
        do {
          bVar4 = pbVar8[1];
          iVar11 = (uint)local_474[(int)pbVar8] * 0x8000;
          iVar3 = (*pbVar8 - 0x80) * 0xe2d0 + iVar11;
          if (iVar3 < 0) {
            bVar2 = 0;
          }
          else if (iVar3 < 0x7f8001) {
            bVar2 = (byte)(iVar3 >> 0xf);
          }
          else {
            bVar2 = 0xff;
          }
          iVar3 = (*pbVar8 - 0x80) * -0x2c08 + (bVar4 - 0x80) * -0x5b64 + iVar11;
          local_4a8[(int)pbVar8] = bVar2;
          if (iVar3 < 0) {
            uVar5 = 0;
          }
          else if (iVar3 < 0x7f8001) {
            uVar5 = (undefined1)(iVar3 >> 0xf);
          }
          else {
            uVar5 = 0xff;
          }
          iVar11 = iVar11 + (bVar4 - 0x80) * 0xb374;
          puVar9[-1] = uVar5;
          if (iVar11 < 0) {
            uVar5 = 0;
          }
          else if (iVar11 < 0x7f8001) {
            uVar5 = (undefined1)(iVar11 >> 0xf);
          }
          else {
            uVar5 = 0xff;
          }
          *puVar9 = uVar5;
          puVar9[1] = 0xff;
          pbVar8 = pbVar8 + 4;
          puVar9 = puVar9 + 4;
          local_498 = local_498 + -1;
        } while (local_498 != (undefined1 *)0x0);
        local_49c = local_49c + local_478;
        local_4a4 = local_4a4 + local_10;
        local_4a0 = local_4a0 + local_470;
        local_494 = local_494 - 1;
      } while (local_494 != 0);
      local_498 = (byte *)0x0;
      local_494 = 0;
    }
    else {
      local_464 = iVar3 + 1;
      local_45c = 1 - local_464;
      do {
        local_484 = (byte *)(local_4a0 + 2);
        local_4a8 = local_4a4 + local_464;
        local_480 = local_4a4 + -(int)local_49c;
        local_460 = local_4a0 - (int)local_49c;
        pbVar8 = local_49c;
        local_498 = local_47c;
        do {
          local_490 = (local_4a8[local_45c] - 0x80) * 0xb374;
          bVar4 = *local_4a8;
          bVar2 = pbVar8[local_46c];
          iVar11 = (uint)*pbVar8 * 0x8000;
          iVar3 = (local_480[(int)pbVar8] - 0x80) * 0xe2d0 + iVar11;
          if (iVar3 < 0) {
            bVar1 = 0;
          }
          else if (iVar3 < 0x7f8001) {
            bVar1 = (byte)(iVar3 >> 0xf);
          }
          else {
            bVar1 = 0xff;
          }
          iVar3 = (local_480[(int)pbVar8] - 0x80) * -0x2c08 +
                  (local_4a8[local_45c] - 0x80) * -0x5b64 + iVar11;
          pbVar8[local_460] = bVar1;
          if (iVar3 < 0) {
            bVar1 = 0;
          }
          else if (iVar3 < 0x7f8001) {
            bVar1 = (byte)(iVar3 >> 0xf);
          }
          else {
            bVar1 = 0xff;
          }
          local_484[-1] = bVar1;
          iVar11 = iVar11 + local_490;
          if (iVar11 < 0) {
            bVar1 = 0;
          }
          else if (iVar11 < 0x7f8001) {
            bVar1 = (byte)(iVar11 >> 0xf);
          }
          else {
            bVar1 = 0xff;
          }
          iVar3 = (bVar4 - 0x80) * 0xb374 + (uint)bVar2 * 0x8000;
          *local_484 = bVar1;
          if (iVar3 < 0) {
            bVar4 = 0;
          }
          else if (iVar3 < 0x7f8001) {
            bVar4 = (byte)(iVar3 >> 0xf);
          }
          else {
            bVar4 = 0xff;
          }
          local_484[1] = bVar4;
          local_484 = local_484 + 4;
          local_4a8 = local_4a8 + 4;
          pbVar8 = pbVar8 + 4;
          local_498 = local_498 + -1;
        } while (local_498 != (undefined1 *)0x0);
        local_49c = local_49c + local_478;
        local_4a4 = local_4a4 + local_10;
        local_4a0 = local_4a0 + local_470;
        local_494 = local_494 - 1;
      } while (local_494 != 0);
      local_498 = (byte *)0x0;
      local_494 = 0;
    }
  }
  else {
    local_474 = (byte *)((int)local_454 / 2);
    if ((local_474 == local_18) && (local_458 / 2 == local_14)) {
      local_494 = local_494 >> 1;
      if (local_488 == (byte *)0x0) {
        local_480 = (byte *)(4 - local_478);
        do {
          local_4a8 = local_4a4;
          puVar9 = (undefined1 *)(local_4a0 + 2);
          local_474 = local_49c + local_478;
          local_484 = local_49c;
          local_498 = (byte *)((uint)local_47c >> 1);
          do {
            iVar11 = (*local_4a8 - 0x80) * 0xe2d0;
            local_490 = (local_4a8[1] - 0x80) * 0xb374;
            local_48c = (*local_4a8 - 0x80) * -0x2c08 + (local_4a8[1] - 0x80) * -0x5b64;
            iVar6 = (uint)*local_484 * 0x8000;
            iVar3 = iVar6 + iVar11;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            iVar3 = iVar6 + local_48c;
            puVar9[-2] = uVar5;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[-1] = uVar5;
            iVar6 = iVar6 + local_490;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            *puVar9 = uVar5;
            puVar9[1] = 0xff;
            iVar6 = (uint)local_480[(int)local_474] * 0x8000;
            iVar3 = iVar6 + iVar11;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[2] = uVar5;
            iVar3 = iVar6 + local_48c;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[3] = uVar5;
            iVar6 = iVar6 + local_490;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[4] = uVar5;
            puVar9[5] = 0xff;
            iVar6 = (uint)*local_474 * 0x8000;
            iVar3 = iVar6 + iVar11;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470 + -2] = uVar5;
            iVar3 = iVar6 + local_48c;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470 + -1] = uVar5;
            iVar6 = iVar6 + local_490;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470] = uVar5;
            puVar9[local_470 + 1] = 0xff;
            iVar3 = (uint)local_474[4] * 0x8000;
            iVar11 = iVar3 + iVar11;
            if (iVar11 < 0) {
              uVar5 = 0;
            }
            else if (iVar11 < 0x7f8001) {
              uVar5 = (undefined1)(iVar11 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470 + 2] = uVar5;
            iVar11 = local_48c + iVar3;
            if (iVar11 < 0) {
              uVar5 = 0;
            }
            else if (iVar11 < 0x7f8001) {
              uVar5 = (undefined1)(iVar11 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470 + 3] = uVar5;
            iVar3 = iVar3 + local_490;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            local_4a8 = local_4a8 + 4;
            local_484 = local_484 + 8;
            puVar9[local_470 + 4] = uVar5;
            puVar9[local_470 + 5] = 0xff;
            local_474 = local_474 + 8;
            puVar9 = puVar9 + 8;
            local_498 = local_498 + -1;
          } while (local_498 != (byte *)0x0);
          local_4a4 = local_4a4 + local_10;
          local_49c = local_49c + local_478 * 2;
          local_4a0 = local_4a0 + local_470 * 2;
          local_494 = local_494 - 1;
        } while (local_494 != 0);
        local_498 = (byte *)0x0;
        local_494 = 0;
        local_488 = (byte *)((uint)local_47c >> 1);
      }
      else {
        local_488 = (byte *)((uint)local_47c >> 1);
        local_474 = (byte *)(local_46c + local_478);
        local_464 = iVar3 + 1;
        local_45c = 1 - local_464;
        do {
          local_4a8 = local_4a4 + local_464;
          local_484 = local_4a4;
          puVar9 = (undefined1 *)(local_4a0 + 2);
          local_480 = local_49c + 4;
          local_460 = local_4a0 - (int)local_49c;
          local_498 = local_488;
          do {
            local_490 = (local_4a8[local_45c] - 0x80) * 0xb374;
            local_47c = (undefined1 *)((*local_4a8 - 0x80) * 0xb374);
            iVar11 = (*local_484 - 0x80) * 0xe2d0;
            local_48c = (*local_484 - 0x80) * -0x2c08 + (local_4a8[local_45c] - 0x80) * -0x5b64;
            bVar4 = local_480[local_46c + -4];
            iVar6 = (uint)local_480[-4] * 0x8000;
            iVar3 = iVar6 + iVar11;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            iVar3 = iVar6 + local_48c;
            puVar9[-2] = uVar5;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[-1] = uVar5;
            iVar6 = iVar6 + local_490;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar10 = local_47c + (uint)bVar4 * 0x8000;
            *puVar9 = uVar5;
            if ((int)puVar10 < 0) {
              uVar5 = 0;
            }
            else if ((int)puVar10 < 0x7f8001) {
              uVar5 = (undefined1)((int)puVar10 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[1] = uVar5;
            bVar4 = local_480[local_46c];
            iVar6 = (uint)*local_480 * 0x8000;
            iVar3 = iVar6 + iVar11;
            if (iVar3 < 0) {
              bVar2 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              bVar2 = (byte)(iVar3 >> 0xf);
            }
            else {
              bVar2 = 0xff;
            }
            local_480[local_460] = bVar2;
            iVar3 = iVar6 + local_48c;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[3] = uVar5;
            iVar6 = iVar6 + local_490;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[4] = uVar5;
            puVar10 = local_47c + (uint)bVar4 * 0x8000;
            if ((int)puVar10 < 0) {
              uVar5 = 0;
            }
            else if ((int)puVar10 < 0x7f8001) {
              uVar5 = (undefined1)((int)puVar10 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[5] = uVar5;
            bVar4 = (local_474 + -4)[(int)local_480];
            iVar6 = (uint)local_480[local_478 + -4] * 0x8000;
            iVar3 = iVar6 + iVar11;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470 + -2] = uVar5;
            iVar3 = iVar6 + local_48c;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470 + -1] = uVar5;
            iVar6 = iVar6 + local_490;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470] = uVar5;
            puVar10 = local_47c + (uint)bVar4 * 0x8000;
            if ((int)puVar10 < 0) {
              uVar5 = 0;
            }
            else if ((int)puVar10 < 0x7f8001) {
              uVar5 = (undefined1)((int)puVar10 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470 + 1] = uVar5;
            bVar4 = local_474[(int)local_480];
            iVar3 = (uint)local_480[local_478] * 0x8000;
            iVar11 = iVar3 + iVar11;
            if (iVar11 < 0) {
              uVar5 = 0;
            }
            else if (iVar11 < 0x7f8001) {
              uVar5 = (undefined1)(iVar11 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470 + 2] = uVar5;
            iVar11 = local_48c + iVar3;
            if (iVar11 < 0) {
              uVar5 = 0;
            }
            else if (iVar11 < 0x7f8001) {
              uVar5 = (undefined1)(iVar11 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470 + 3] = uVar5;
            iVar3 = iVar3 + local_490;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470 + 4] = uVar5;
            puVar10 = local_47c + (uint)bVar4 * 0x8000;
            if ((int)puVar10 < 0) {
              uVar5 = 0;
            }
            else if ((int)puVar10 < 0x7f8001) {
              uVar5 = (undefined1)((int)puVar10 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            local_480 = local_480 + 8;
            puVar9[local_470 + 5] = uVar5;
            local_484 = local_484 + 4;
            local_4a8 = local_4a8 + 4;
            puVar9 = puVar9 + 8;
            local_498 = local_498 + -1;
          } while (local_498 != (byte *)0x0);
          local_49c = local_49c + local_478 * 2;
          local_4a4 = local_4a4 + local_10;
          local_4a0 = local_4a0 + local_470 * 2;
          local_494 = local_494 - 1;
        } while (local_494 != 0);
        local_498 = (byte *)0x0;
        local_494 = 0;
      }
    }
    else if ((local_474 == local_18) && (local_458 == local_14)) {
      pbVar8 = (byte *)((uint)local_47c >> 1);
      if (local_488 == (byte *)0x0) {
        do {
          local_4a8 = local_4a4;
          local_480 = local_49c;
          puVar9 = (undefined1 *)(local_4a0 + 2);
          local_498 = pbVar8;
          do {
            iVar13 = (*local_4a8 - 0x80) * 0xe2d0;
            iVar6 = (local_4a8[1] - 0x80) * 0xb374;
            iVar11 = (*local_4a8 - 0x80) * -0x2c08 + (local_4a8[1] - 0x80) * -0x5b64;
            iVar12 = (uint)*local_480 * 0x8000;
            iVar3 = iVar12 + iVar13;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            iVar3 = iVar12 + iVar11;
            puVar9[-2] = uVar5;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            iVar12 = iVar12 + iVar6;
            puVar9[-1] = uVar5;
            if (iVar12 < 0) {
              uVar5 = 0;
            }
            else if (iVar12 < 0x7f8001) {
              uVar5 = (undefined1)(iVar12 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            *puVar9 = uVar5;
            puVar9[1] = 0xff;
            iVar3 = (uint)local_480[4] * 0x8000;
            iVar13 = iVar13 + iVar3;
            if (iVar13 < 0) {
              uVar5 = 0;
            }
            else if (iVar13 < 0x7f8001) {
              uVar5 = (undefined1)(iVar13 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[2] = uVar5;
            iVar11 = iVar3 + iVar11;
            if (iVar11 < 0) {
              uVar5 = 0;
            }
            else if (iVar11 < 0x7f8001) {
              uVar5 = (undefined1)(iVar11 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            iVar3 = iVar3 + iVar6;
            puVar9[3] = uVar5;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            local_4a8 = local_4a8 + 4;
            local_480 = local_480 + 8;
            puVar9[4] = uVar5;
            puVar9[5] = 0xff;
            puVar9 = puVar9 + 8;
            local_498 = local_498 + -1;
          } while (local_498 != (byte *)0x0);
          local_49c = local_49c + local_478;
          local_4a4 = local_4a4 + local_10;
          local_4a0 = local_4a0 + local_470;
          local_494 = local_494 - 1;
        } while (local_494 != 0);
        local_498 = (byte *)0x0;
        local_494 = 0;
        local_488 = pbVar8;
      }
      else {
        local_464 = iVar3 + 1;
        local_45c = 1 - local_464;
        do {
          local_47c = (undefined1 *)(local_4a0 + 2);
          local_484 = local_4a4 + local_464;
          local_4a8 = local_4a4;
          local_460 = local_4a0 - (int)local_49c;
          pbVar7 = local_49c + 4;
          local_498 = pbVar8;
          do {
            local_490 = (local_484[local_45c] - 0x80) * 0xb374;
            iVar12 = (*local_4a8 - 0x80) * 0xe2d0;
            local_48c = (*local_4a8 - 0x80) * -0x2c08 + (local_484[local_45c] - 0x80) * -0x5b64;
            bVar4 = pbVar7[local_46c + -4];
            iVar11 = (uint)pbVar7[-4] * 0x8000;
            iVar3 = iVar11 + iVar12;
            iVar6 = (*local_484 - 0x80) * 0xb374;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            local_47c[-2] = uVar5;
            iVar3 = iVar11 + local_48c;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            local_47c[-1] = uVar5;
            iVar11 = iVar11 + local_490;
            if (iVar11 < 0) {
              uVar5 = 0;
            }
            else if (iVar11 < 0x7f8001) {
              uVar5 = (undefined1)(iVar11 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            iVar3 = (uint)bVar4 * 0x8000 + iVar6;
            *local_47c = uVar5;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            local_47c[1] = uVar5;
            bVar4 = pbVar7[local_46c];
            iVar3 = (uint)*pbVar7 * 0x8000;
            iVar12 = iVar12 + iVar3;
            if (iVar12 < 0) {
              bVar2 = 0;
            }
            else if (iVar12 < 0x7f8001) {
              bVar2 = (byte)(iVar12 >> 0xf);
            }
            else {
              bVar2 = 0xff;
            }
            pbVar7[local_460] = bVar2;
            iVar11 = iVar3 + local_48c;
            if (iVar11 < 0) {
              uVar5 = 0;
            }
            else if (iVar11 < 0x7f8001) {
              uVar5 = (undefined1)(iVar11 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            local_47c[3] = uVar5;
            iVar3 = iVar3 + local_490;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            iVar6 = iVar6 + (uint)bVar4 * 0x8000;
            local_47c[4] = uVar5;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            local_47c[5] = uVar5;
            local_4a8 = local_4a8 + 4;
            local_484 = local_484 + 4;
            local_47c = local_47c + 8;
            pbVar7 = pbVar7 + 8;
            local_498 = local_498 + -1;
          } while (local_498 != (byte *)0x0);
          local_49c = local_49c + local_478;
          local_4a4 = local_4a4 + local_10;
          local_4a0 = local_4a0 + local_470;
          local_494 = local_494 - 1;
        } while (local_494 != 0);
        local_498 = (byte *)0x0;
        local_494 = 0;
        local_488 = pbVar8;
      }
    }
    else if ((local_454 == local_18) && (local_458 / 2 == local_14)) {
      local_494 = local_494 >> 1;
      if (local_488 == (byte *)0x0) {
        do {
          puVar9 = (undefined1 *)(local_4a0 + 2);
          local_480 = local_4a4 + -(int)local_49c;
          pbVar8 = local_49c;
          local_498 = local_47c;
          do {
            iVar12 = (local_480[(int)pbVar8] - 0x80) * 0xe2d0;
            iVar11 = ((local_480 + 1)[(int)pbVar8] - 0x80) * 0xb374;
            local_48c = (local_480[(int)pbVar8] - 0x80) * -0x2c08 +
                        ((local_480 + 1)[(int)pbVar8] - 0x80) * -0x5b64;
            iVar6 = (uint)*pbVar8 * 0x8000;
            iVar3 = iVar6 + iVar12;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[-2] = uVar5;
            iVar3 = iVar6 + local_48c;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            iVar6 = iVar6 + iVar11;
            puVar9[-1] = uVar5;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            *puVar9 = uVar5;
            puVar9[1] = 0xff;
            iVar3 = (uint)pbVar8[local_478] * 0x8000;
            iVar12 = iVar12 + iVar3;
            if (iVar12 < 0) {
              uVar5 = 0;
            }
            else if (iVar12 < 0x7f8001) {
              uVar5 = (undefined1)(iVar12 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470 + -2] = uVar5;
            iVar6 = local_48c + iVar3;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            iVar3 = iVar3 + iVar11;
            puVar9[local_470 + -1] = uVar5;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470] = uVar5;
            puVar9[local_470 + 1] = 0xff;
            puVar9 = puVar9 + 4;
            pbVar8 = pbVar8 + 4;
            local_498 = local_498 + -1;
          } while (local_498 != (undefined1 *)0x0);
          local_4a4 = local_4a4 + local_10;
          local_49c = local_49c + local_478 * 2;
          local_4a0 = local_4a0 + local_470 * 2;
          local_494 = local_494 - 1;
        } while (local_494 != 0);
        local_498 = (byte *)0x0;
        local_494 = 0;
      }
      else {
        local_464 = iVar3 + 1;
        local_45c = 1 - local_464;
        local_474 = (byte *)(local_46c - local_478);
        do {
          local_488 = local_49c + local_478;
          local_4a8 = local_4a4 + local_464;
          puVar9 = (undefined1 *)(local_4a0 + 2);
          local_480 = local_4a4 + -(int)local_49c;
          local_484 = local_49c;
          local_498 = local_47c;
          do {
            local_490 = (local_4a8[local_45c] - 0x80) * 0xb374;
            iVar12 = (local_480[(int)local_484] - 0x80) * 0xe2d0;
            local_48c = (local_480[(int)local_484] - 0x80) * -0x2c08 +
                        (local_4a8[local_45c] - 0x80) * -0x5b64;
            bVar4 = local_488[(int)local_474];
            iVar11 = (uint)*local_484 * 0x8000;
            iVar3 = iVar11 + iVar12;
            iVar6 = (*local_4a8 - 0x80) * 0xb374;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[-2] = uVar5;
            iVar3 = iVar11 + local_48c;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[-1] = uVar5;
            iVar11 = iVar11 + local_490;
            if (iVar11 < 0) {
              uVar5 = 0;
            }
            else if (iVar11 < 0x7f8001) {
              uVar5 = (undefined1)(iVar11 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            iVar3 = (uint)bVar4 * 0x8000 + iVar6;
            *puVar9 = uVar5;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[1] = uVar5;
            bVar4 = local_488[local_46c];
            iVar3 = (uint)*local_488 * 0x8000;
            iVar12 = iVar12 + iVar3;
            if (iVar12 < 0) {
              uVar5 = 0;
            }
            else if (iVar12 < 0x7f8001) {
              uVar5 = (undefined1)(iVar12 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470 + -2] = uVar5;
            iVar11 = iVar3 + local_48c;
            if (iVar11 < 0) {
              uVar5 = 0;
            }
            else if (iVar11 < 0x7f8001) {
              uVar5 = (undefined1)(iVar11 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470 + -1] = uVar5;
            iVar3 = iVar3 + local_490;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            iVar6 = iVar6 + (uint)bVar4 * 0x8000;
            puVar9[local_470] = uVar5;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[local_470 + 1] = uVar5;
            local_4a8 = local_4a8 + 4;
            local_484 = local_484 + 4;
            local_488 = local_488 + 4;
            puVar9 = puVar9 + 4;
            local_498 = local_498 + -1;
          } while (local_498 != (undefined1 *)0x0);
          local_4a4 = local_4a4 + local_10;
          local_49c = local_49c + local_478 * 2;
          local_4a0 = local_4a0 + local_470 * 2;
          local_494 = local_494 - 1;
        } while (local_494 != 0);
        local_498 = (byte *)0x0;
        local_494 = 0;
      }
    }
    else if (((byte *)((int)(local_454 + ((int)local_454 >> 0x1f & 3)) >> 2) == local_18) &&
            (local_458 == local_14)) {
      pbVar8 = (byte *)((uint)local_47c >> 2);
      if (local_488 == (byte *)0x0) {
        do {
          local_4a8 = local_4a4;
          puVar9 = (undefined1 *)(local_4a0 + 2);
          local_460 = local_4a0 - (int)local_49c;
          pbVar7 = local_49c + 8;
          local_498 = pbVar8;
          do {
            iVar11 = (*local_4a8 - 0x80) * 0xe2d0;
            local_490 = (local_4a8[1] - 0x80) * 0xb374;
            local_48c = (*local_4a8 - 0x80) * -0x2c08 + (local_4a8[1] - 0x80) * -0x5b64;
            iVar6 = (uint)pbVar7[-8] * 0x8000;
            iVar3 = iVar6 + iVar11;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            iVar3 = iVar6 + local_48c;
            puVar9[-2] = uVar5;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[-1] = uVar5;
            iVar6 = iVar6 + local_490;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            *puVar9 = uVar5;
            puVar9[1] = 0xff;
            iVar6 = (uint)pbVar7[-4] * 0x8000;
            iVar3 = iVar6 + iVar11;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            iVar3 = iVar6 + local_48c;
            puVar9[2] = uVar5;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[3] = uVar5;
            iVar6 = iVar6 + local_490;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[4] = uVar5;
            puVar9[5] = 0xff;
            iVar6 = (uint)*pbVar7 * 0x8000;
            iVar3 = iVar6 + iVar11;
            if (iVar3 < 0) {
              bVar4 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              bVar4 = (byte)(iVar3 >> 0xf);
            }
            else {
              bVar4 = 0xff;
            }
            pbVar7[local_460] = bVar4;
            iVar3 = iVar6 + local_48c;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[7] = uVar5;
            iVar6 = iVar6 + local_490;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[8] = uVar5;
            puVar9[9] = 0xff;
            iVar3 = (uint)pbVar7[4] * 0x8000;
            iVar11 = iVar3 + iVar11;
            if (iVar11 < 0) {
              uVar5 = 0;
            }
            else if (iVar11 < 0x7f8001) {
              uVar5 = (undefined1)(iVar11 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[10] = uVar5;
            iVar11 = iVar3 + local_48c;
            if (iVar11 < 0) {
              uVar5 = 0;
            }
            else if (iVar11 < 0x7f8001) {
              uVar5 = (undefined1)(iVar11 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            iVar3 = iVar3 + local_490;
            puVar9[0xb] = uVar5;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            local_4a8 = local_4a8 + 4;
            puVar9[0xc] = uVar5;
            puVar9[0xd] = 0xff;
            puVar9 = puVar9 + 0x10;
            pbVar7 = pbVar7 + 0x10;
            local_498 = local_498 + -1;
          } while (local_498 != (byte *)0x0);
          local_49c = local_49c + local_478;
          local_4a4 = local_4a4 + local_10;
          local_4a0 = local_4a0 + local_470;
          local_494 = local_494 - 1;
          local_498 = (byte *)0x0;
          local_488 = pbVar8;
        } while (local_494 != 0);
      }
      else {
        local_464 = iVar3 + 1;
        local_45c = 1 - local_464;
        do {
          local_484 = local_4a4 + local_464;
          local_4a8 = local_4a4;
          puVar9 = (undefined1 *)(local_4a0 + 2);
          local_480 = local_49c + 4;
          local_460 = local_4a0 - (int)local_49c;
          local_498 = pbVar8;
          do {
            local_490 = (local_484[local_45c] - 0x80) * 0xb374;
            iVar11 = (*local_4a8 - 0x80) * 0xe2d0;
            local_48c = (*local_4a8 - 0x80) * -0x2c08 + (local_484[local_45c] - 0x80) * -0x5b64;
            local_47c = (undefined1 *)((*local_484 - 0x80) * 0xb374);
            bVar4 = local_480[local_46c + -4];
            iVar6 = (uint)local_480[-4] * 0x8000;
            iVar3 = iVar6 + iVar11;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[-2] = uVar5;
            iVar3 = iVar6 + local_48c;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[-1] = uVar5;
            iVar6 = iVar6 + local_490;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar10 = local_47c + (uint)bVar4 * 0x8000;
            *puVar9 = uVar5;
            if ((int)puVar10 < 0) {
              uVar5 = 0;
            }
            else if ((int)puVar10 < 0x7f8001) {
              uVar5 = (undefined1)((int)puVar10 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[1] = uVar5;
            bVar4 = local_480[local_46c];
            iVar6 = (uint)*local_480 * 0x8000;
            iVar3 = iVar6 + iVar11;
            if (iVar3 < 0) {
              bVar2 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              bVar2 = (byte)(iVar3 >> 0xf);
            }
            else {
              bVar2 = 0xff;
            }
            local_480[local_460] = bVar2;
            iVar3 = iVar6 + local_48c;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[3] = uVar5;
            iVar6 = iVar6 + local_490;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[4] = uVar5;
            puVar10 = local_47c + (uint)bVar4 * 0x8000;
            if ((int)puVar10 < 0) {
              uVar5 = 0;
            }
            else if ((int)puVar10 < 0x7f8001) {
              uVar5 = (undefined1)((int)puVar10 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[5] = uVar5;
            bVar4 = local_480[local_46c + 4];
            iVar6 = (uint)local_480[4] * 0x8000;
            iVar3 = iVar6 + iVar11;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[6] = uVar5;
            iVar3 = iVar6 + local_48c;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[7] = uVar5;
            iVar6 = iVar6 + local_490;
            if (iVar6 < 0) {
              uVar5 = 0;
            }
            else if (iVar6 < 0x7f8001) {
              uVar5 = (undefined1)(iVar6 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[8] = uVar5;
            puVar10 = local_47c + (uint)bVar4 * 0x8000;
            if ((int)puVar10 < 0) {
              uVar5 = 0;
            }
            else if ((int)puVar10 < 0x7f8001) {
              uVar5 = (undefined1)((int)puVar10 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[9] = uVar5;
            bVar4 = local_480[local_46c + 8];
            iVar3 = (uint)local_480[8] * 0x8000;
            iVar11 = iVar3 + iVar11;
            if (iVar11 < 0) {
              uVar5 = 0;
            }
            else if (iVar11 < 0x7f8001) {
              uVar5 = (undefined1)(iVar11 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[10] = uVar5;
            iVar11 = local_48c + iVar3;
            if (iVar11 < 0) {
              uVar5 = 0;
            }
            else if (iVar11 < 0x7f8001) {
              uVar5 = (undefined1)(iVar11 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[0xb] = uVar5;
            iVar3 = iVar3 + local_490;
            if (iVar3 < 0) {
              uVar5 = 0;
            }
            else if (iVar3 < 0x7f8001) {
              uVar5 = (undefined1)(iVar3 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[0xc] = uVar5;
            puVar10 = local_47c + (uint)bVar4 * 0x8000;
            if ((int)puVar10 < 0) {
              uVar5 = 0;
            }
            else if ((int)puVar10 < 0x7f8001) {
              uVar5 = (undefined1)((int)puVar10 >> 0xf);
            }
            else {
              uVar5 = 0xff;
            }
            puVar9[0xd] = uVar5;
            local_4a8 = local_4a8 + 4;
            local_484 = local_484 + 4;
            local_480 = local_480 + 0x10;
            puVar9 = puVar9 + 0x10;
            local_498 = local_498 + -1;
          } while (local_498 != (byte *)0x0);
          local_49c = local_49c + local_478;
          local_4a4 = local_4a4 + local_10;
          local_4a0 = local_4a0 + local_470;
          local_494 = local_494 - 1;
        } while (local_494 != 0);
        local_498 = (byte *)0x0;
        local_494 = 0;
        local_488 = pbVar8;
      }
    }
  }
  FUN_005421c0(local_440);
  FUN_00586b00();
  return 0;
}

