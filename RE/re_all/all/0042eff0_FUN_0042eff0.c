
undefined4 FUN_0042eff0(undefined4 param_1,int param_2,char param_3)

{
  undefined1 auStack_e4 [16];
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined *puStack_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  undefined4 local_48;
  undefined1 *local_44;
  undefined1 *local_40;
  undefined1 *local_3c;
  undefined1 *local_38;
  undefined1 *local_34;
  undefined1 *local_30;
  undefined1 *local_2c;
  undefined1 *local_28;
  undefined1 *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  int local_8;
  
  local_48 = 0;
  if (param_3 == '\0') {
    if (param_2 == 0) {
      local_8 = DAT_00a18b40;
    }
    if (param_2 == 1) {
      local_8 = DAT_00a18b44;
    }
    if (param_2 == 2) {
      local_8 = DAT_00a18b48;
    }
    local_50 = local_8;
    if (local_8 < 0x801) {
      if (local_8 == 0x800) {
        local_28 = auStack_e4;
        local_8c = basic_string<>(&DAT_007cd7a4);
        puStack_cc = (undefined *)FUN_00401c50();
        uStack_d0 = 0x42f39c;
        local_90 = puStack_cc;
        basic_string<>();
        return param_1;
      }
      if (local_8 < 0x81) {
        if (local_8 == 0x80) {
          local_18 = auStack_e4;
          local_6c = basic_string<>(&DAT_007cd784);
          puStack_cc = (undefined *)FUN_00401c50();
          uStack_d0 = 0x42f299;
          local_70 = puStack_cc;
          basic_string<>();
          return param_1;
        }
        if (local_8 == 0x10) {
          local_c = auStack_e4;
          local_54 = basic_string<>(&DAT_007cd76c);
          puStack_cc = (undefined *)FUN_00401c50();
          uStack_d0 = 0x42f1e2;
          local_58 = puStack_cc;
          basic_string<>();
          return param_1;
        }
        if (local_8 == 0x20) {
          local_10 = auStack_e4;
          local_5c = basic_string<>(&DAT_007cd774);
          puStack_cc = (undefined *)FUN_00401c50();
          uStack_d0 = 0x42f21f;
          local_60 = puStack_cc;
          basic_string<>();
          return param_1;
        }
        if (local_8 == 0x40) {
          local_14 = auStack_e4;
          local_64 = basic_string<>(&DAT_007cd77c);
          puStack_cc = (undefined *)FUN_00401c50();
          uStack_d0 = 0x42f25c;
          local_68 = puStack_cc;
          basic_string<>();
          return param_1;
        }
      }
      else {
        if (local_8 == 0x100) {
          local_1c = auStack_e4;
          local_74 = basic_string<>(&DAT_007cd78c);
          puStack_cc = (undefined *)FUN_00401c50();
          uStack_d0 = 0x42f2d6;
          local_78 = puStack_cc;
          basic_string<>();
          return param_1;
        }
        if (local_8 == 0x200) {
          local_20 = auStack_e4;
          local_7c = basic_string<>(&DAT_007cd794);
          puStack_cc = (undefined *)FUN_00401c50();
          uStack_d0 = 0x42f313;
          local_80 = puStack_cc;
          basic_string<>();
          return param_1;
        }
        if (local_8 == 0x400) {
          local_24 = auStack_e4;
          local_84 = basic_string<>(&DAT_007cd79c);
          puStack_cc = (undefined *)FUN_00401c50();
          uStack_d0 = 0x42f356;
          local_88 = puStack_cc;
          basic_string<>();
          return param_1;
        }
      }
    }
    else if (local_8 < 0x8001) {
      if (local_8 == 0x8000) {
        local_38 = auStack_e4;
        local_ac = basic_string<>(&DAT_007cd7cc);
        puStack_cc = (undefined *)FUN_00401c50();
        uStack_d0 = 0x42f4b4;
        local_b0 = puStack_cc;
        basic_string<>();
        return param_1;
      }
      if (local_8 == 0x1000) {
        local_2c = auStack_e4;
        local_94 = basic_string<>(&DAT_007cd7ac);
        puStack_cc = (undefined *)FUN_00401c50();
        uStack_d0 = 0x42f3e2;
        local_98 = puStack_cc;
        basic_string<>();
        return param_1;
      }
      if (local_8 == 0x2000) {
        local_30 = auStack_e4;
        local_9c = basic_string<>(&DAT_007cd7b4);
        puStack_cc = (undefined *)FUN_00401c50();
        uStack_d0 = 0x42f428;
        local_a0 = puStack_cc;
        basic_string<>();
        return param_1;
      }
      if (local_8 == 0x4000) {
        local_34 = auStack_e4;
        local_a4 = basic_string<>(&DAT_007cd7c0);
        puStack_cc = (undefined *)FUN_00401c50();
        uStack_d0 = 0x42f46e;
        local_a8 = puStack_cc;
        basic_string<>();
        return param_1;
      }
    }
    else {
      if (local_8 == 0x10000) {
        local_3c = auStack_e4;
        local_b4 = basic_string<>(&DAT_007cd7d8);
        puStack_cc = (undefined *)FUN_00401c50();
        uStack_d0 = 0x42f4fa;
        local_b8 = puStack_cc;
        basic_string<>();
        return param_1;
      }
      if (local_8 == 0x20000) {
        local_40 = auStack_e4;
        local_bc = basic_string<>(&DAT_007cd7e4);
        puStack_cc = (undefined *)FUN_00401c50();
        uStack_d0 = 0x42f540;
        local_c0 = puStack_cc;
        basic_string<>();
        return param_1;
      }
      if (local_8 == 0x40000) {
        local_44 = auStack_e4;
        local_c4 = basic_string<>(&DAT_007cd7f0);
        puStack_cc = (undefined *)FUN_00401c50();
        uStack_d0 = 0x42f583;
        local_c8 = puStack_cc;
        basic_string<>();
        return param_1;
      }
    }
  }
  else {
    if (param_2 == 0) {
      puStack_cc = (undefined *)(DAT_00a18b34 + -100);
      uStack_d0 = param_1;
      uStack_d4 = 0x42f028;
      FUN_0042a5a0();
      return param_1;
    }
    if (param_2 == 1) {
      puStack_cc = (undefined *)(DAT_00a18b38 + -100);
      uStack_d0 = param_1;
      uStack_d4 = 0x42f055;
      FUN_0042a5a0();
      return param_1;
    }
    if (param_2 == 2) {
      puStack_cc = (undefined *)(DAT_00a18b3c + -100);
      uStack_d0 = param_1;
      uStack_d4 = 0x42f082;
      FUN_0042a5a0();
      return param_1;
    }
  }
  puStack_cc = &DAT_007cd7f9;
  uStack_d0 = 0x42f59e;
  basic_string<>();
  return param_1;
}

