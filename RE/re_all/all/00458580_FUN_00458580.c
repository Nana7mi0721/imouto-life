
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_00458580(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  undefined4 *puVar5;
  uint *puVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined3 uVar14;
  int *piVar13;
  undefined8 uVar15;
  undefined1 *puVar16;
  int local_2a4;
  uint local_2a0;
  int local_29c;
  uint local_298;
  int local_294;
  uint local_290;
  int local_28c;
  int local_288;
  int local_284;
  int local_280;
  int local_27c;
  int local_278;
  uint local_270;
  int local_26c;
  uint local_268;
  uint local_264;
  uint local_260;
  uint local_25c;
  uint local_258;
  uint local_254;
  byte local_24b;
  int local_244;
  uint local_240;
  undefined *local_98;
  undefined *local_94;
  int local_90;
  undefined1 local_8c [4];
  uint local_88;
  undefined1 local_68 [8];
  uint local_60;
  undefined4 local_54;
  uint local_50;
  undefined1 local_49;
  uint local_48;
  uint local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  char local_e;
  undefined1 local_d;
  int local_c;
  uint local_8;
  
  puVar5 = (undefined4 *)FUN_004ce990(1);
  local_14 = FUN_00487080(*puVar5);
  local_e = '\0';
  puVar6 = (uint *)FUN_004ce990(2);
  local_d = (*puVar6 & 1) != 0;
  local_c = 0;
  puVar6 = (uint *)FUN_004ce990(2);
  if ((*puVar6 & 0x10) != 0) {
    local_c = ((999999 < (int)local_14) - 1 & 2000000) + local_14;
    local_14 = FUN_00487080(local_c);
    local_e = '\x01';
  }
  local_8 = 0;
  puVar6 = (uint *)FUN_004ce990(2);
  iVar7 = ((int)(*puVar6 & 0xf000) >> 0xc) + -1;
  switch(iVar7) {
  case 0:
    local_18 = 0;
    puVar5 = (undefined4 *)FUN_004ce990(3);
    uVar9 = FUN_00487080(*puVar5);
    local_18 = FUN_00452590(uVar9);
    if (local_18 == 0) {
      local_8 = 0xffffffff;
    }
    else {
      puVar5 = (undefined4 *)FUN_004ce990(4);
      switch(*puVar5) {
      case 0:
        iVar7 = *(int *)(local_18 + 0x28);
        iVar10 = FUN_0047a490();
        iVar11 = FUN_0047a490();
        local_8 = (iVar7 / 2 + iVar10) % iVar11;
        break;
      case 1:
        iVar7 = *(int *)(local_18 + 0x2c);
        iVar10 = FUN_0047a4b0();
        iVar11 = FUN_0047a4b0();
        local_8 = (iVar7 / 2 + iVar10) % iVar11;
        break;
      case 2:
        iVar10 = FUN_0047a490();
        iVar7 = *(int *)(local_18 + 0x28);
        iVar11 = FUN_0047a490();
        local_8 = (iVar7 + iVar10 * 2) % (iVar11 << 1);
        break;
      case 3:
        iVar10 = FUN_0047a4b0();
        iVar7 = *(int *)(local_18 + 0x2c);
        iVar11 = FUN_0047a4b0();
        local_8 = (iVar7 + iVar10 * 2) % (iVar11 << 1);
        break;
      case 4:
        local_8 = *(uint *)(local_18 + 0xc4);
        break;
      case 5:
        local_8 = (uint)*(short *)(local_18 + 0x48);
        break;
      case 6:
        local_8 = FUN_00478140(CONCAT31((int3)((uint)*puVar5 >> 8),DAT_00a180f4));
        break;
      case 7:
        local_8 = FUN_00478270(DAT_00a180f5);
        break;
      case 8:
        iVar7 = FUN_004cd730();
        if (iVar7 == 0) {
          local_8 = 0xffffffff;
        }
        else {
          pbVar8 = (byte *)FUN_004cd7c0(0);
          local_8 = (uint)*pbVar8;
        }
        break;
      case 9:
        local_8 = FUN_0049ba50();
        break;
      case 10:
        local_8 = *(uint *)(local_18 + 0x24);
        break;
      case 0xb:
        iVar7 = FUN_00478140(1);
        iVar10 = FUN_0047a490();
        local_20 = iVar7 % (iVar10 * DAT_0084b264);
        iVar7 = FUN_00478270(1);
        iVar10 = FUN_0047a4b0();
        local_1c = iVar7 % (iVar10 * DAT_0084b264);
        if ((((-DAT_0084b264 < local_20) && (local_20 < *DAT_00a16718 + DAT_0084b264)) &&
            (-DAT_0084b264 < local_1c)) && (local_1c < (int)*DAT_00a1671c + DAT_0084b264 * 2)) {
          local_8 = 1;
        }
        break;
      case 0xc:
        if ((*(char *)(local_18 + 0x54) == '\0') && (*(char *)(local_18 + 0xbf) == '\0')) {
          local_24 = local_18;
          local_8 = *(int *)(local_18 + 0x15c) + 1;
        }
        break;
      case 0xd:
        if ((*(char *)(local_18 + 0x54) == '\0') && (*(char *)(local_18 + 0xbf) == '\0')) {
          local_28 = local_18;
          local_8 = *(uint *)(local_18 + 0x1e8);
        }
        break;
      case 0xe:
        if (((*(char *)(local_18 + 0x54) == '\0') && (*(char *)(local_18 + 0xbf) == '\0')) &&
           (local_2c = local_18, -1 < *(int *)(local_18 + 0x15c))) {
          FUN_004cf170(*(undefined4 *)(local_18 + 0x15c));
          iVar7 = FUN_004cd730();
          if (2 < iVar7) {
            uVar9 = 1;
            FUN_004cf170(*(undefined4 *)(local_2c + 0x15c));
            pbVar8 = (byte *)FUN_004cd7c0(uVar9);
            local_8 = (uint)*pbVar8;
          }
        }
        break;
      case 0xf:
        if (((*(char *)(local_18 + 0x54) == '\0') && (*(char *)(local_18 + 0xbf) == '\0')) &&
           (local_30 = local_18, -1 < *(int *)(local_18 + 0x15c))) {
          FUN_004cf170(*(undefined4 *)(local_18 + 0x15c));
          iVar7 = FUN_004cd730();
          if (2 < iVar7) {
            uVar9 = 2;
            FUN_004cf170(*(undefined4 *)(local_30 + 0x15c));
            pbVar8 = (byte *)FUN_004cd7c0(uVar9);
            local_8 = (uint)*pbVar8;
          }
        }
        break;
      case 0x10:
        local_34 = local_18;
        if (-1 < *(int *)(local_18 + 0x15c)) {
          switch(*(undefined2 *)(local_18 + 0x50)) {
          case 0:
            local_8 = (uint)*(short *)(local_18 + 0x4a);
            break;
          case 1:
            cVar4 = FUN_0049ba00();
            if (cVar4 == '\0') {
              local_240 = 0;
            }
            else {
              local_240 = (int)*(short *)(local_34 + 0x4a) + 1;
            }
            local_8 = local_240;
            break;
          case 2:
            cVar4 = FUN_0049ba00();
            if (cVar4 == '\0') {
              local_244 = 0;
            }
            else {
              local_244 = (int)*DAT_00a16690;
            }
            local_8 = *(short *)(local_34 + 0x4a) + local_244;
            break;
          case 0xffff:
            local_8 = 0;
          }
        }
        break;
      case 0x11:
        local_38 = local_18;
        if (-1 < *(int *)(local_18 + 0x15c)) {
          if (((*(char *)(local_18 + 0x54) == '\0') || (cVar4 = FUN_0049ba00(), cVar4 == '\0')) &&
             ((*(char *)(local_38 + 0x54) != '\0' || (cVar4 = FUN_004780e0(), cVar4 == '\0')))) {
            local_8 = 0;
          }
          else {
            local_8 = 1;
          }
        }
      }
    }
    break;
  case 1:
    puVar5 = (undefined4 *)FUN_004ce990(3);
    local_40 = FUN_00487080(*puVar5);
    puVar5 = (undefined4 *)FUN_004ce990(4);
    local_3c = FUN_00487080(*puVar5);
    puVar6 = (uint *)FUN_004ce990(2);
    switch((int)(*puVar6 & 0xf0000) >> 0x10) {
    case 0:
      puVar6 = (uint *)FUN_004ce990(2);
      if ((*puVar6 & 0x20) == 0) {
        local_8 = FUN_0047eba0(local_40 << 1,local_3c << 1);
        local_8 = local_8 & 0xff;
      }
      else if (*DAT_00a16714 < 0xcb) {
        uVar9 = FUN_0047a4d0(local_40,local_3c,2);
        pbVar8 = (byte *)FUN_004cd7c0(uVar9);
        local_8 = (uint)*pbVar8;
        if (local_8 == 0) {
          uVar9 = FUN_0047a4d0(local_40,local_3c,1);
          pbVar8 = (byte *)FUN_004cd7c0(uVar9);
          local_8 = (uint)*pbVar8;
        }
        if (local_8 == 0) {
          uVar9 = FUN_0047a4d0(local_40,local_3c,0);
          pbVar8 = (byte *)FUN_004cd7c0(uVar9);
          local_8 = (uint)*pbVar8;
        }
      }
      else {
        local_8 = FUN_0047eba0(local_40,local_3c);
        local_8 = local_8 & 0xff;
      }
      break;
    case 1:
      local_8 = 0xffffffff;
      puVar6 = (uint *)FUN_004ce990(2);
      if ((*puVar6 & 0x20) == 0) {
        local_48 = 0;
        while (iVar7 = FUN_004d29a0(), (int)local_48 < iVar7) {
          iVar7 = FUN_004d2a00(local_48);
          if (((*(int *)(iVar7 + 0x28) / 2 == local_40) &&
              (iVar7 = FUN_004d2a00(local_48), *(int *)(iVar7 + 0x2c) / 2 == local_3c)) &&
             (iVar7 = FUN_004d2a00(local_48), *(int *)(iVar7 + 0x254) == -1)) {
            iVar7 = FUN_004d2a00(local_48);
            local_49 = *(undefined1 *)(iVar7 + 0xbe);
            local_8 = local_48;
            break;
          }
          local_48 = local_48 + 1;
        }
      }
      else {
        local_44 = 0;
        while (iVar7 = FUN_004d29a0(), (int)local_44 < iVar7) {
          iVar7 = FUN_004d2a00(local_44);
          if (((*(int *)(iVar7 + 0x28) == local_40) &&
              (iVar7 = FUN_004d2a00(local_44), *(int *)(iVar7 + 0x2c) == local_3c)) &&
             (iVar7 = FUN_004d2a00(local_44), *(int *)(iVar7 + 0x254) == -1)) {
            local_8 = local_44;
            break;
          }
          local_44 = local_44 + 1;
        }
      }
      if (local_8 != 0xffffffff) {
        iVar7 = FUN_004d2a00(local_8);
        local_8 = *(uint *)(iVar7 + 0x24);
      }
      break;
    case 2:
      puVar6 = (uint *)FUN_004ce990(2);
      if ((*puVar6 & 0x20) == 0) {
        local_40 = local_40 << 1;
        local_3c = local_3c << 1;
        if ((((*DAT_00a16698 == '\x01') &&
             (cVar4 = FUN_0044a350(local_40,local_3c,0,0xffffffff,0), cVar4 == '\x01')) &&
            (cVar4 = FUN_0044a350(local_40,local_3c + -1,0,0xffffffff,0), cVar4 == '\x01')) ||
           ((*DAT_00a16698 == '\0' &&
            (cVar4 = FUN_0044a350(local_40,local_3c,0,0xffffffff,0), cVar4 == '\x01')))) {
          local_8 = 0;
        }
        else {
          local_8 = 1;
        }
      }
      else {
        cVar4 = FUN_0044a8a0(local_40,local_3c);
        if (cVar4 == '\x01') {
          local_8 = 0;
        }
        else {
          local_8 = 1;
        }
      }
      break;
    case 3:
      puVar6 = (uint *)FUN_004ce990(2);
      if ((*puVar6 & 0x20) == 0) {
        local_40 = local_40 << 1;
        local_3c = local_3c << 1;
        if (((((*DAT_00a16698 == '\x01') &&
              (cVar4 = FUN_0044a350(local_40,local_3c,0,0xffffffff,0), cVar4 == '\x01')) &&
             (cVar4 = FUN_0044a350(local_40,local_3c + -1,0,0xffffffff,0), cVar4 == '\x01')) ||
            ((*DAT_00a16698 == '\0' &&
             (cVar4 = FUN_0044a350(local_40,local_3c,0,0xffffffff,0), cVar4 == '\x01')))) &&
           (cVar4 = FUN_00442d90(local_40,local_3c), cVar4 == '\x01')) {
          local_8 = 0;
        }
        else {
          local_8 = 1;
        }
      }
      else {
        cVar4 = FUN_00442d90(local_40,local_3c);
        if ((cVar4 == '\x01') && (cVar4 = FUN_0044a8a0(local_40,local_3c), cVar4 == '\x01')) {
          local_8 = 0;
        }
        else {
          local_8 = 1;
        }
      }
      break;
    case 4:
      puVar6 = (uint *)FUN_004ce990(2);
      if ((*puVar6 & 0x20) == 0) {
        local_40 = local_40 << 1;
        local_3c = local_3c << 1;
      }
      local_50 = FUN_0047a4d0(local_40,local_3c,2);
      if (local_50 == 0) {
        local_50 = FUN_0047a4d0(local_40,local_3c,1);
      }
      if (local_50 == 0) {
        local_50 = FUN_0047a4d0(local_40,local_3c,0);
      }
      local_8 = local_50;
      break;
    case 5:
      puVar6 = (uint *)FUN_004ce990(2);
      if ((*puVar6 & 0x20) == 0) {
        local_40 = local_40 << 1;
        local_3c = local_3c << 1;
      }
      local_8 = FUN_0047a4d0(local_40,local_3c,0);
      break;
    case 6:
      puVar6 = (uint *)FUN_004ce990(2);
      if ((*puVar6 & 0x20) == 0) {
        local_40 = local_40 << 1;
        local_3c = local_3c << 1;
      }
      local_8 = FUN_0047a4d0(local_40,local_3c,1);
      break;
    case 7:
      puVar6 = (uint *)FUN_004ce990(2);
      if ((*puVar6 & 0x20) == 0) {
        local_40 = local_40 << 1;
        local_3c = local_3c << 1;
      }
      local_8 = FUN_0047a4d0(local_40,local_3c,2);
      break;
    case 8:
      puVar6 = (uint *)FUN_004ce990(2);
      if ((*puVar6 & 0x20) == 0) {
        uVar9 = FUN_0047a4d0(local_40 << 1,local_3c * 2 + 1,0);
        pbVar8 = (byte *)FUN_004cd7c0(uVar9);
        bVar1 = *pbVar8;
        uVar9 = FUN_0047a4d0(local_40 * 2 + 1,local_3c * 2 + 1,0);
        pbVar8 = (byte *)FUN_004cd7c0(uVar9);
        if (*pbVar8 < bVar1) {
          uVar9 = FUN_0047a4d0(local_40 << 1,local_3c * 2 + 1,0);
          pbVar8 = (byte *)FUN_004cd7c0(uVar9);
          bVar1 = *pbVar8;
        }
        else {
          uVar9 = FUN_0047a4d0(local_40 * 2 + 1,local_3c * 2 + 1,0);
          pbVar8 = (byte *)FUN_004cd7c0(uVar9);
          bVar1 = *pbVar8;
        }
      }
      else {
        uVar9 = FUN_0047a4d0(local_40,local_3c,0);
        pbVar8 = (byte *)FUN_004cd7c0(uVar9);
        bVar1 = *pbVar8;
      }
      local_8 = (uint)bVar1;
      break;
    case 9:
      puVar6 = (uint *)FUN_004ce990(2);
      if ((*puVar6 & 0x20) == 0) {
        uVar9 = FUN_0047a4d0(local_40 << 1,local_3c * 2 + 1,1);
        pbVar8 = (byte *)FUN_004cd7c0(uVar9);
        bVar1 = *pbVar8;
        uVar9 = FUN_0047a4d0(local_40 * 2 + 1,local_3c * 2 + 1,1);
        pbVar8 = (byte *)FUN_004cd7c0(uVar9);
        if (*pbVar8 < bVar1) {
          uVar9 = FUN_0047a4d0(local_40 << 1,local_3c * 2 + 1,1);
          pbVar8 = (byte *)FUN_004cd7c0(uVar9);
          bVar1 = *pbVar8;
        }
        else {
          uVar9 = FUN_0047a4d0(local_40 * 2 + 1,local_3c * 2 + 1,1);
          pbVar8 = (byte *)FUN_004cd7c0(uVar9);
          bVar1 = *pbVar8;
        }
      }
      else {
        uVar9 = FUN_0047a4d0(local_40,local_3c,1);
        pbVar8 = (byte *)FUN_004cd7c0(uVar9);
        bVar1 = *pbVar8;
      }
      local_8 = (uint)bVar1;
      break;
    case 10:
      puVar6 = (uint *)FUN_004ce990(2);
      if ((*puVar6 & 0x20) == 0) {
        uVar9 = FUN_0047a4d0(local_40 << 1,local_3c * 2 + 1,2);
        pbVar8 = (byte *)FUN_004cd7c0(uVar9);
        bVar1 = *pbVar8;
        uVar9 = FUN_0047a4d0(local_40 * 2 + 1,local_3c * 2 + 1,2);
        pbVar8 = (byte *)FUN_004cd7c0(uVar9);
        if (*pbVar8 < bVar1) {
          uVar9 = FUN_0047a4d0(local_40 << 1,local_3c * 2 + 1,2);
          pbVar8 = (byte *)FUN_004cd7c0(uVar9);
          local_24b = *pbVar8;
        }
        else {
          uVar9 = FUN_0047a4d0(local_40 * 2 + 1,local_3c * 2 + 1,2);
          pbVar8 = (byte *)FUN_004cd7c0(uVar9);
          local_24b = *pbVar8;
        }
        local_8 = (uint)local_24b;
      }
      else {
        uVar9 = FUN_0047a4d0(local_40,local_3c,2);
        pbVar8 = (byte *)FUN_004cd7c0(uVar9);
        local_8 = (uint)*pbVar8;
      }
    }
    break;
  case 2:
    puVar5 = (undefined4 *)FUN_004ce990(3);
    switch(*puVar5) {
    case 0:
      if (DAT_00a14061 == '\0') {
        local_254 = DAT_00a17eb8;
      }
      else {
        local_254 = DAT_00a14068;
      }
      local_8 = local_254;
      break;
    case 1:
      if ((int)DAT_00a18a34 < DAT_00a14328) {
        local_258 = DAT_00a18a34;
      }
      else {
        local_258 = 0xffffffff;
      }
      local_8 = local_258;
      break;
    case 2:
      if ((int)DAT_00a18a38 < DAT_00a1432c) {
        local_25c = DAT_00a18a38;
      }
      else {
        local_25c = 0xffffffff;
      }
      local_8 = local_25c;
      break;
    case 3:
      if (DAT_00a18a34 != 0xffffffff) {
        if (DAT_00a18de4 == '\0') {
          puVar5 = (undefined4 *)FUN_004cc020(&DAT_00a18a34);
          local_8 = FUN_0055f5e0(*puVar5);
        }
        else if (DAT_00a18de4 == '\x01') {
          puVar16 = local_68;
          FUN_00401000(puVar16);
          FUN_00401570(puVar16);
          local_8 = local_60;
        }
      }
      break;
    case 4:
      if (DAT_00a18a38 != 0xffffffff) {
        puVar5 = (undefined4 *)FUN_004cc020(&DAT_00a18a38);
        local_8 = FUN_0055f5e0(*puVar5);
      }
      break;
    case 5:
      if (DAT_00a18a34 != 0xffffffff) {
        if (DAT_00a18de4 == '\0') {
          puVar5 = (undefined4 *)FUN_004cc020(&DAT_00a18a34);
          local_8 = FUN_0055d360(*puVar5);
        }
        else if (DAT_00a18de4 == '\x01') {
          puVar16 = local_8c;
          uVar9 = DAT_00a18dfc;
          FUN_00401000(puVar16,DAT_00a18dfc);
          FUN_004016b0(puVar16,uVar9);
          local_8 = local_88;
        }
      }
      break;
    case 6:
      if (DAT_00a18a38 != 0xffffffff) {
        puVar5 = (undefined4 *)FUN_004cc020(&DAT_00a18a38);
        local_8 = FUN_0055d360(*puVar5);
      }
      break;
    case 7:
      if (DAT_00a1461d == '\0') {
        local_260 = (uint)(DAT_00a1461a != '\0');
      }
      else {
        local_260 = 2;
      }
      local_8 = local_260;
      break;
    case 8:
      if (DAT_00a1461e == '\0') {
        local_264 = (uint)(DAT_00a1461b != '\0');
      }
      else {
        local_264 = 2;
      }
      local_8 = local_264;
      break;
    case 9:
      if (DAT_00a1461f == '\0') {
        local_268 = (uint)(DAT_00a1461c != '\0');
      }
      else {
        local_268 = 2;
      }
      local_8 = local_268;
      break;
    case 10:
      local_8 = DAT_00a14640;
      break;
    case 0xb:
      local_8 = DAT_00a14644;
      break;
    case 0xc:
      local_8 = DAT_00a14648;
      break;
    case 0xd:
      local_8 = 0xffffffff;
      local_90 = 0;
      while( true ) {
        iVar7 = FUN_004d29a0();
        uVar2 = DAT_00a14620;
        if (iVar7 <= local_90) break;
        iVar7 = DAT_00a17ebc + (DAT_00a17ebc >> 0x1f & 3U);
        iVar10 = FUN_0047a490();
        iVar10 = iVar10 * DAT_0084b264;
        iVar11 = FUN_0047a490();
        iVar11 = iVar11 * DAT_0084b264;
        iVar12 = FUN_004d2a00(local_90);
        uVar3 = DAT_00a14620;
        if ((int)(uVar2 + iVar10 + (iVar7 >> 2)) % iVar11 -
            ((int)(*(int *)(iVar12 + 0x38) + (*(int *)(iVar12 + 0x38) >> 0x1f & 3U)) >> 2) <
            DAT_0084b264) {
          iVar7 = DAT_00a17ebc + (DAT_00a17ebc >> 0x1f & 3U);
          iVar10 = FUN_0047a490();
          iVar10 = iVar10 * DAT_0084b264;
          iVar11 = FUN_0047a490();
          iVar11 = iVar11 * DAT_0084b264;
          iVar12 = FUN_004d2a00(local_90);
          if (-1 < (int)(uVar3 + iVar10 + (iVar7 >> 2)) % iVar11 -
                   ((int)(*(int *)(iVar12 + 0x38) + (*(int *)(iVar12 + 0x38) >> 0x1f & 3U)) >> 2)) {
            iVar7 = FUN_004d2a00(local_90);
            uVar2 = DAT_00a14624;
            if (*(char *)(iVar7 + 0xb9) == '\0') {
              local_26c = 0;
            }
            else {
              local_26c = DAT_0084b264 / 2;
            }
            iVar7 = DAT_00a17ec0 + (DAT_00a17ec0 >> 0x1f & 3U);
            iVar10 = FUN_0047a4b0();
            iVar10 = iVar10 * DAT_0084b264;
            iVar11 = FUN_0047a4b0();
            iVar11 = iVar11 * DAT_0084b264;
            iVar12 = FUN_004d2a00(local_90);
            uVar3 = DAT_00a14624;
            if (DAT_0084b264 / 2 - local_26c <=
                (int)(uVar2 + iVar10 + (iVar7 >> 2)) % iVar11 -
                ((int)(*(int *)(iVar12 + 0x3c) + (*(int *)(iVar12 + 0x3c) >> 0x1f & 3U)) >> 2)) {
              iVar7 = DAT_00a17ec0 + (DAT_00a17ec0 >> 0x1f & 3U);
              iVar10 = FUN_0047a4b0();
              iVar10 = iVar10 * DAT_0084b264;
              iVar11 = FUN_0047a4b0();
              iVar11 = iVar11 * DAT_0084b264;
              iVar12 = FUN_004d2a00(local_90);
              if ((int)(uVar3 + iVar10 + (iVar7 >> 2)) % iVar11 -
                  ((int)(*(int *)(iVar12 + 0x3c) + (*(int *)(iVar12 + 0x3c) >> 0x1f & 3U)) >> 2) <
                  DAT_0084b264) {
                if (local_8 == 0xffffffff) {
                  iVar7 = FUN_004d2a00(local_90);
                  local_8 = *(uint *)(iVar7 + 0x24);
                }
                else {
                  iVar7 = FUN_004d2a00(local_90);
                  if ((int)local_8 < *(int *)(iVar7 + 0x24)) {
                    local_270 = local_8;
                  }
                  else {
                    iVar7 = FUN_004d2a00(local_90);
                    local_270 = *(uint *)(iVar7 + 0x24);
                  }
                  local_8 = local_270;
                }
              }
            }
          }
        }
        local_90 = local_90 + 1;
      }
      break;
    case 0xe:
      local_8 = *(uint *)(param_1 + 0x14);
      break;
    case 0xf:
      local_8 = FUN_0047a490();
      break;
    case 0x10:
      local_8 = FUN_0047a4b0();
      break;
    case 0x11:
      local_8 = *(uint *)(param_1 + 0x18);
      break;
    case 0x12:
      local_94 = &DAT_00a1817c;
      local_8 = 0xffffffff;
      if (DAT_00a18984 != 0) {
        while (iVar7 = FUN_004d21f0(), iVar7 != 0) {
          local_94 = (undefined *)FUN_004d2250(0);
        }
        if (*(int *)(local_94 + 0x18) == -1) {
          local_8 = *(uint *)(local_94 + 0x14);
        }
        else {
          local_8 = *(int *)(local_94 + 0x18) + 500000;
        }
      }
      break;
    case 0x13:
      local_98 = &DAT_00a1817c;
      local_8 = 0xffffffff;
      if (DAT_00a18984 != 0) {
        while (iVar7 = FUN_004d21f0(), iVar7 != 0) {
          local_98 = (undefined *)FUN_004d2250(0);
        }
        if ((*(int *)(local_98 + 0x14) != -1) || (*(int *)(local_98 + 0x18) != -1)) {
          local_8 = *(uint *)(local_98 + 8);
        }
      }
      break;
    case 0x14:
      local_8 = DAT_00a14620;
      break;
    case 0x15:
      local_8 = DAT_00a14624;
    }
    break;
  case 3:
    puVar5 = (undefined4 *)FUN_004ce990(3);
    local_54 = FUN_00487080(*puVar5);
    uVar9 = FUN_004ce990(4);
    local_8 = FUN_004874c0(&local_54,uVar9);
    break;
  default:
    uVar14 = (undefined3)((uint)iVar7 >> 8);
    goto LAB_00459fd2;
  }
  DAT_00a1809c = 1;
  puVar6 = (uint *)FUN_004ce990(2);
  iVar7 = (int)(*puVar6 & 0xf00) >> 8;
  switch(iVar7) {
  case 0:
    if (local_e == '\0') {
      uVar15 = FUN_004ce990(1);
      iVar7 = (int)((ulonglong)uVar15 >> 0x20);
      local_278 = *(int *)uVar15;
    }
    else {
      local_278 = local_c;
    }
    uVar9 = FUN_00487450(CONCAT31((int3)((uint)iVar7 >> 8),local_d),local_8);
    iVar7 = FUN_00486e50(local_278,uVar9);
    break;
  case 1:
    if (local_e == '\0') {
      piVar13 = (int *)FUN_004ce990(1);
      local_27c = *piVar13;
    }
    else {
      local_27c = local_c;
    }
    uVar9 = FUN_004873b0(local_14 + local_8,
                         ((int)local_14 >> 0x1f) + ((int)local_8 >> 0x1f) +
                         (uint)CARRY4(local_14,local_8));
    uVar9 = FUN_00487450(local_d,uVar9);
    iVar7 = FUN_00486e50(local_27c,uVar9);
    break;
  case 2:
    if (local_e == '\0') {
      piVar13 = (int *)FUN_004ce990(1);
      local_280 = *piVar13;
    }
    else {
      local_280 = local_c;
    }
    uVar9 = FUN_004873b0(local_14 - local_8,
                         (((int)local_14 >> 0x1f) - ((int)local_8 >> 0x1f)) -
                         (uint)(local_14 < local_8));
    uVar9 = FUN_00487450(local_d,uVar9);
    iVar7 = FUN_00486e50(local_280,uVar9);
    break;
  case 3:
    if (local_e == '\0') {
      piVar13 = (int *)FUN_004ce990(1);
      local_284 = *piVar13;
    }
    else {
      local_284 = local_c;
    }
    uVar15 = __allmul(local_14,(int)local_14 >> 0x1f,local_8,(int)local_8 >> 0x1f);
    uVar9 = FUN_004873b0(uVar15);
    uVar9 = FUN_00487450(local_d,uVar9);
    iVar7 = FUN_00486e50(local_284,uVar9);
    break;
  case 4:
    if (local_8 == 0) {
      local_8 = 1;
    }
    if (local_e == '\0') {
      piVar13 = (int *)FUN_004ce990(1);
      local_288 = *piVar13;
    }
    else {
      local_288 = local_c;
    }
    uVar9 = FUN_00487450(CONCAT31((int3)((uint)((int)local_14 % (int)local_8) >> 8),local_d),
                         (int)local_14 / (int)local_8);
    iVar7 = FUN_00486e50(local_288,uVar9);
    break;
  case 5:
    if (local_8 == 0) {
      local_8 = 1;
    }
    if (local_e == '\0') {
      piVar13 = (int *)FUN_004ce990(1);
      local_28c = *piVar13;
    }
    else {
      local_28c = local_c;
    }
    uVar9 = FUN_00487450(CONCAT31((int3)((uint)((int)local_14 % (int)local_8) >> 8),local_d),
                         (int)local_14 % (int)local_8);
    iVar7 = FUN_00486e50(local_28c,uVar9);
    break;
  case 6:
    if ((int)local_14 < (int)local_8) {
      local_290 = local_8;
    }
    else {
      local_290 = local_14;
    }
    if (local_e == '\0') {
      piVar13 = (int *)FUN_004ce990(1);
      local_294 = *piVar13;
    }
    else {
      local_294 = local_c;
    }
    uVar9 = FUN_00487450(local_d,local_290);
    iVar7 = FUN_00486e50(local_294,uVar9);
    break;
  case 7:
    if ((int)local_8 < (int)local_14) {
      local_298 = local_8;
    }
    else {
      local_298 = local_14;
    }
    if (local_e == '\0') {
      piVar13 = (int *)FUN_004ce990(1);
      local_29c = *piVar13;
    }
    else {
      local_29c = local_c;
    }
    uVar9 = FUN_00487450(local_d,local_298);
    iVar7 = FUN_00486e50(local_29c,uVar9);
    break;
  case 8:
    if ((int)local_8 < 0) {
      local_2a0 = -local_8;
    }
    else {
      local_2a0 = local_8;
    }
    if (local_e == '\0') {
      piVar13 = (int *)FUN_004ce990(1);
      local_2a4 = *piVar13;
    }
    else {
      local_2a4 = local_c;
    }
    uVar9 = FUN_00487450(local_d,local_2a0);
    iVar7 = FUN_00486e50(local_2a4,uVar9);
  }
  uVar14 = (undefined3)((uint)iVar7 >> 8);
LAB_00459fd2:
  return CONCAT31(uVar14,1);
}

