
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d0050(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 local_5c;
  undefined4 local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_00586680();
  _DAT_00f130f0 = 0;
  _DAT_00f130f4 = 0;
  DAT_00f13224 = 0xff;
  DAT_00f13225 = 0xff;
  DAT_00ef7324 = 1;
  DAT_00f130e0 = 3;
  DAT_00f130e4 = 1;
  DAT_00f130e8 = 0;
  DAT_00f130ec = 0;
  DAT_00f130f8 = 1;
  DAT_00f130fc = 0;
  DAT_00f13100 = 1;
  DAT_00f13104 = 0;
  DAT_00f13214 = 0;
  DAT_00f13218 = 0;
  DAT_00f1321c = 4;
  DAT_00f13220 = 0;
  DAT_00f13228 = 1;
  DAT_00f1322c = 1;
  DAT_00f13230 = 1;
  DAT_00f13234 = 8;
  DAT_00f13238 = 1;
  DAT_00f1323c = 1;
  DAT_00f13240 = 1;
  DAT_00f13244 = 8;
  _DAT_00f132e8 = 0;
  _DAT_00f132ec = 0;
  puVar4 = &DAT_00f132f4;
  do {
    puVar4[-1] = 0;
    *puVar4 = 2;
    puVar4[1] = 1;
    puVar4[2] = 1;
    puVar4[3] = 2;
    puVar4[4] = 1;
    puVar4[5] = 1;
    *(undefined1 *)(puVar4 + 6) = 0xf;
    uVar3 = _DAT_007ff1ec;
    uVar2 = _DAT_007d8c08;
    puVar4 = puVar4 + 8;
  } while ((int)puVar4 < 0xf133f4);
  puVar4 = &DAT_00f076c8;
  do {
    puVar4[-1] = 0;
    puVar4[3] = 0;
    *puVar4 = 3;
    puVar4[6] = 0;
    puVar4[1] = 3;
    puVar4[7] = 0;
    puVar4[2] = 3;
    puVar4[8] = 0;
    puVar4[4] = 0x10;
    puVar4[9] = 0;
    puVar4[5] = 8;
    puVar5 = puVar4 + 0xd;
    puVar4[10] = uVar2;
    puVar4[0xb] = uVar3;
    puVar4 = puVar5;
  } while ((int)puVar5 < 0xf07a08);
  piVar6 = &DAT_00a38020;
  do {
    if (piVar6[-0x10] == 0) {
      piVar6[-0x10] = 3;
    }
    if (*piVar6 == 0) {
      *piVar6 = 3;
    }
    if (piVar6[0x10] == 0) {
      piVar6[0x10] = 3;
    }
    piVar6 = piVar6 + 1;
  } while ((int)piVar6 < 0xa38060);
  if (DAT_00f3a070 != 0) {
    if (DAT_00f07678 == 0) {
      if (DAT_00ef7324 == 0) goto LAB_005d0211;
    }
    else if ((DAT_00ef7324 == 0) && (FUN_00568ca0(0), DAT_00dda46c != 0)) {
      FUN_00584d70();
    }
    FUN_005b90c0(0,0xffffffff);
    DAT_00f07678 = 0;
    DAT_00ef72cc = 1;
  }
LAB_005d0211:
  FUN_005bb0b0(0x10,0xffffffff);
  if (DAT_00f3a070 != 0) {
    if ((DAT_00f138e0 != 0) || (DAT_00ef7324 != 0)) {
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      DAT_00f138e0 = 0;
      FUN_00585060(&DAT_00f138e4);
      FUN_005bace0();
    }
    if ((DAT_00f3a070 != 0) && ((DAT_00f07614 != 1 || (DAT_00ef7324 != 0)))) {
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      DAT_00f07614 = 1;
      DAT_00ef72cc = 1;
    }
  }
  local_44 = _DAT_007d5914;
  local_40 = _DAT_007d5914;
  local_3c = _DAT_007d5914;
  local_38 = 0x3f800000;
  local_24 = _DAT_007d5914;
  local_20 = _DAT_007d5914;
  local_1c = _DAT_007d5914;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_4 = _DAT_007d5910;
  FUN_005b9a40(&local_44);
  if (DAT_00f3a070 != 0) {
    if ((DAT_00f07670 != 1) || (DAT_00ef7324 != 0)) {
      iVar1 = *(int *)(DAT_00ef1b8c + 8);
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      *(undefined4 *)(iVar1 + 0xf0) = 0x3f800000;
      *(undefined4 *)(DAT_00ef1b8c + 0xc) = 1;
      DAT_00f07670 = 1;
      DAT_00ef72cc = 1;
    }
    if (DAT_00f3a070 != 0) {
      if ((DAT_00f07674 != 1) || (DAT_00ef7324 != 0)) {
        iVar1 = *(int *)(DAT_00ef1b8c + 8);
        FUN_00568ca0(0);
        if (DAT_00dda46c != 0) {
          FUN_00584d70();
        }
        *(undefined4 *)(iVar1 + 0xf4) = 0x3f800000;
        *(undefined4 *)(DAT_00ef1b8c + 0xc) = 1;
        DAT_00f07674 = 1;
        DAT_00ef72cc = 1;
      }
      if (DAT_00f3a070 != 0) {
        if ((DAT_00f07618 != 1) || (DAT_00ef7324 != 0)) {
          iVar1 = *(int *)(DAT_00ef1b8c + 8);
          FUN_00568ca0(0);
          if (DAT_00dda46c != 0) {
            FUN_00584d70();
          }
          DAT_00f07618 = 1;
          *(undefined4 *)(iVar1 + 0xf8) = 0x3f800000;
          *(undefined4 *)(DAT_00ef1b8c + 0xc) = 1;
          DAT_00ef72cc = 1;
        }
        if ((DAT_00f3a070 != 0) && ((DAT_00f07360 != 0 || (DAT_00ef7324 != 0)))) {
          FUN_00568ca0(0);
          if (DAT_00dda46c != 0) {
            FUN_00584d70();
          }
          DAT_00f07360 = 0;
          DAT_00ef72cc = 1;
        }
      }
    }
  }
  FUN_005bae90(0);
  if ((DAT_00f3a070 != 0) && ((DAT_00f07364 != 0 || (DAT_00ef7324 != 0)))) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    DAT_00f07364 = 0;
    DAT_00ef72cc = 1;
  }
  FUN_005bafc0(0,0x3f800000);
  if ((DAT_00f3a070 != 0) && ((_DAT_00f07374 != (float)_DAT_00802e18 || (DAT_00ef7324 != 0)))) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    _DAT_00f07374 = 1.0;
    if (DAT_00f3a070 != 0) {
      iVar1 = *(int *)(DAT_00ef1b84 + 8);
      *(float *)(iVar1 + 0x2e0) = _DAT_00f07370 / (_DAT_00f07370 - _DAT_00f0736c);
      *(float *)(iVar1 + 0x2e4) = (float)_DAT_00805148 / (_DAT_00f07370 - _DAT_00f0736c);
      *(float *)(iVar1 + 0x2e8) = _DAT_00f07374;
      *(undefined4 *)(iVar1 + 0x2ec) = _DAT_007fc510;
      *(undefined4 *)(DAT_00ef1b84 + 0xc) = 1;
    }
    DAT_00ef72cc = 1;
  }
  local_58 = 0;
  local_5c = 0;
  local_54 = 0.0;
  local_50 = 0.0;
  FUN_005b9d80(&local_5c);
  local_5c = 0;
  local_58 = 0;
  local_54 = (float)DAT_00a37e60;
  local_50 = (float)DAT_00a37e64;
  local_4c = 0;
  local_48 = 0x3f800000;
  FUN_005c29f0(&local_5c);
  if (DAT_00f3a070 != 0) {
    if ((DAT_00ef72ec != 0) || (DAT_00ef7324 != 0)) {
      iVar1 = *(int *)(DAT_00ef1ba0 + 8);
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      DAT_00ef72ec = 0;
      *(undefined4 *)(iVar1 + 0x30) = 0;
      *(undefined4 *)(iVar1 + 0x34) = 0;
      *(undefined4 *)(iVar1 + 0x38) = 0;
      *(undefined4 *)(DAT_00ef1ba0 + 0xc) = 1;
    }
    if ((DAT_00f3a070 != 0) && ((DAT_00ef72f0 != 0 || (DAT_00ef7324 != 0)))) {
      iVar1 = *(int *)(DAT_00ef1ba0 + 8);
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      DAT_00ef72f0 = 0;
      *(undefined4 *)(iVar1 + 0x3c) = 0;
      *(undefined4 *)(DAT_00ef1ba0 + 0xc) = 1;
    }
  }
  FUN_005c2b20(DAT_00ee9b90,DAT_00ee9bc4,0);
  if (DAT_00f3a070 != 0) {
    if ((DAT_00f132e0 != 0) || (DAT_00ef7324 != 0)) {
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      DAT_00f132e0 = 0;
      DAT_00f132e4 = 1;
      DAT_00ef72cc = 1;
    }
    if (DAT_00f3a070 != 0) {
      if ((DAT_00f13674 != 4) || (DAT_00ef7324 != 0)) {
        DAT_00f13674 = 4;
        FUN_005d2cf0(4);
      }
      if (DAT_00f3a070 != 0) {
        if (((DAT_00ef7324 != 0) || (DAT_00ef72d8 != -1)) || (DAT_00ef72dc != 0)) {
          FUN_00568ca0(0);
          if (DAT_00dda46c != 0) {
            FUN_00584d70();
          }
          DAT_00ef72d8 = -1;
          DAT_00ef72dc = 0;
          DAT_00ef72cc = 1;
          DAT_00ef72e4 = 1;
        }
        if (DAT_00f3a070 != 0) {
          if (DAT_00ef7324 == 0) {
            if (DAT_00ef731c == 0) goto LAB_005d0766;
            FUN_00568ca0(0);
            if (DAT_00dda46c != 0) {
              FUN_00584d70();
            }
          }
          DAT_00ef72e8 = 1;
          DAT_00ef72cc = 1;
          if (DAT_00ef731c != 0) {
            DAT_00ef72e4 = 1;
          }
          DAT_00ef731c = 0;
          DAT_00ef7320 = 0;
        }
      }
    }
  }
LAB_005d0766:
  DAT_00ef72fc = 0xffffffff;
  DAT_00ef72f4 = 0;
  if (DAT_00f3a070 != 0) {
    if (DAT_00ef7314 == 0) {
      if (DAT_00ef7324 == 0) goto LAB_005d07d0;
    }
    else if ((DAT_00ef7324 == 0) && (FUN_00568ca0(0), DAT_00dda46c != 0)) {
      FUN_00584d70();
    }
    DAT_00ef72e8 = 1;
    if (DAT_00ef7314 != 0) {
      DAT_00ef72e4 = 1;
    }
    DAT_00ef7314 = 0;
    DAT_00ef7318 = 0;
    DAT_00ef72cc = 1;
  }
LAB_005d07d0:
  DAT_00ef72d0 = 0;
  DAT_00ef72d4 = 0;
  DAT_00ef7324 = 0;
  FUN_005cb6f0();
  DAT_00ef72cc = 1;
  DAT_00ef72e4 = 1;
  DAT_00ef72e8 = 0;
  DAT_00f07344 = 0xffffffff;
  DAT_00f0734c = 0;
  DAT_00f07348 = 0;
  DAT_00f07334 = 0;
  DAT_00f07338 = 0;
  DAT_00f0733c = 1;
  if (DAT_00f07330 == 0) {
    DAT_00f0732c = DAT_00f07328;
    return 0;
  }
  if (DAT_00f07328 == 0) {
    FUN_005d5220(DAT_00f07330,0,4,0,&local_5c,0);
    DAT_00f07328 = local_5c;
    DAT_00f0732c = local_5c;
    return 0;
  }
  DAT_00f0732c = DAT_00f07328;
  return 0;
}

