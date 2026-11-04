
undefined4 FUN_005b6a60(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  int local_64;
  int local_60;
  undefined1 *local_5c;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  DAT_00ee9a34 = 0;
  DAT_00ee9a38 = 0;
  FUN_0056d380(&local_24,0,0x24);
  local_10 = 0;
  local_14 = 0x1c;
  local_c = 8;
  local_24 = 0x80;
  local_20 = 0x80;
  local_1c = 0x80;
  local_8 = 0;
  local_18 = 1;
  iVar1 = FUN_005d4f40(&local_24,0,&DAT_00ee9a34,0);
  if (iVar1 < 0) {
    puVar4 = &DAT_007fa0e8;
  }
  else {
    FUN_0056d380(&local_3c,0,0x18);
    local_3c = 0x1c;
    local_38 = 8;
    local_30 = 1;
    local_34 = 0;
    iVar1 = FUN_005d4fa0(DAT_00ee9a34,&local_3c,&DAT_00ee9a38,0);
    if (iVar1 < 0) {
      puVar4 = &DAT_007fce40;
    }
    else {
      puVar2 = (undefined1 *)
               FUN_0056e030(0x800000,
                            "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp",
                            0x344);
      if (puVar2 != (undefined1 *)0x0) {
        local_60 = 0;
        local_64 = 0;
        local_5c = puVar2;
        while( true ) {
          do {
            iVar1 = 0;
            puVar3 = local_5c;
            do {
              FUN_00597580(iVar1 * 2,local_64,local_60,puVar3 + 2,puVar3 + 1,puVar3);
              if (((iVar1 < 8) && (local_64 < 0x10)) && (local_60 < 0x10)) {
                *puVar3 = 0xff;
                puVar3[1] = 0xff;
                puVar3[2] = 0xff;
              }
              puVar3[3] = 0xff;
              iVar1 = iVar1 + 1;
              puVar3 = puVar3 + 4;
            } while (iVar1 < 0x80);
            local_5c = local_5c + 0x200;
            local_64 = local_64 + 2;
          } while (local_64 < 0x100);
          local_60 = local_60 + 2;
          if (0xff < local_60) break;
          local_64 = 0;
        }
        local_48 = 0x80;
        local_44 = 0x80;
        local_40 = 0x80;
        local_54 = 0;
        local_50 = 0;
        local_4c = 0;
        FUN_005d52f0(DAT_00ee9a34,0,&local_54,puVar2,0x200,0x10000,0);
        FUN_0056e1d0(puVar2);
        return 0;
      }
      puVar4 = &DAT_007fcda8;
    }
  }
  FUN_0056bb10(puVar4);
  if (DAT_00ee9a38 != 0) {
    FUN_005d1f20(DAT_00ee9a38);
    DAT_00ee9a38 = 0;
  }
  if (DAT_00ee9a34 != 0) {
    FUN_005d4d80(DAT_00ee9a34,0);
    DAT_00ee9a34 = 0;
  }
  return 0xffffffff;
}

