
void FUN_0042e900(int param_1,int param_2,char param_3,undefined *param_4)

{
  undefined1 auStack_dc [20];
  undefined4 uStack_c8;
  undefined *puStack_c4;
  undefined1 auStack_c0 [20];
  undefined4 uStack_ac;
  undefined *puStack_a8;
  undefined1 auStack_a4 [28];
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
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 *local_34;
  undefined1 *local_30;
  undefined1 *local_2c;
  undefined1 *local_28;
  undefined1 *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ace31;
  local_10 = ExceptionList;
  if (param_4 == (undefined *)0x0) {
    local_14 = &DAT_00a18178;
  }
  else {
    local_14 = param_4;
  }
  if (param_3 == '\0') {
    if ((param_1 < 0x12d) || (0x140 < param_1)) {
      if (DAT_00a117a8 == 0) {
        return;
      }
      local_18 = auStack_a4;
      puStack_a8 = &DAT_007cd6ea;
      uStack_ac = 0x42e974;
      ExceptionList = &local_10;
      local_40 = basic_string<>();
      local_8 = 0;
      local_1c = auStack_c0;
      puStack_c4 = &DAT_007cd6eb;
      uStack_c8 = 0x42e996;
      local_3c = local_40;
      local_48 = basic_string<>();
      local_8 = CONCAT31(local_8._1_3_,1);
      local_24 = auStack_dc;
      local_44 = local_48;
      local_4c = basic_string<>(&DAT_007cd6ec);
      local_50 = FUN_00401c50();
      local_20 = auStack_dc;
      local_54 = basic_string<>(local_50);
      local_8 = 0xffffffff;
      FUN_0042bed0();
      ExceptionList = local_10;
      return;
    }
    if (param_1 == 0x12d) {
      param_1 = 0x10;
    }
    else if (param_1 == 0x12e) {
      param_1 = 0x20;
    }
    else if (param_1 == 0x12f) {
      param_1 = 0x40;
    }
    else if (param_1 == 0x130) {
      param_1 = 0x80;
    }
    else if (param_1 == 0x131) {
      param_1 = 0x100;
    }
    else if (param_1 == 0x132) {
      param_1 = 0x200;
    }
    else if (param_1 == 0x133) {
      param_1 = 0x400;
    }
    else if (param_1 == 0x134) {
      param_1 = 0x800;
    }
    else if (param_1 == 0x135) {
      param_1 = 0x1000;
    }
    else if (param_1 == 0x136) {
      param_1 = 0x2000;
    }
    else if (param_1 == 0x137) {
      param_1 = 0x4000;
    }
    else if (param_1 == 0x138) {
      param_1 = 0x8000;
    }
    else if (param_1 == 0x139) {
      param_1 = 0x10000;
    }
    else if (param_1 == 0x13a) {
      param_1 = 0x20000;
    }
    else if (param_1 == 0x13b) {
      param_1 = 0x40000;
    }
    else if (param_1 == 0x13c) {
      param_1 = 0x80000;
    }
    else if (param_1 == 0x13d) {
      param_1 = 0x100000;
    }
    else if (param_1 == 0x13e) {
      param_1 = 0x400;
    }
    else if (param_1 == 0x13f) {
      param_1 = 0x2000;
    }
    else if (param_1 == 0x140) {
      param_1 = 0x400000;
    }
  }
  else if (((param_1 == 0) || (param_1 < 100)) || (0x163 < param_1)) {
    if (DAT_00a117a8 == 0) {
      return;
    }
    local_28 = auStack_a4;
    puStack_a8 = &DAT_007cd727;
    uStack_ac = 0x42ebb2;
    ExceptionList = &local_10;
    local_5c = basic_string<>();
    local_8 = 2;
    local_2c = auStack_c0;
    puStack_c4 = &DAT_007cd728;
    uStack_c8 = 0x42ebd4;
    local_58 = local_5c;
    local_64 = basic_string<>();
    local_8 = CONCAT31(local_8._1_3_,3);
    local_34 = auStack_dc;
    local_60 = local_64;
    local_68 = basic_string<>(&DAT_007cd72c);
    local_6c = FUN_00401c50();
    local_30 = auStack_dc;
    local_70 = basic_string<>(local_6c);
    local_8 = 0xffffffff;
    FUN_0042bed0();
    ExceptionList = local_10;
    return;
  }
  if (param_3 == '\0') {
    if ((param_1 == *(int *)(local_14 + 0x9c8)) && (param_2 != 0)) {
      if (param_2 == 1) {
        local_80 = *(undefined4 *)(local_14 + 0x9cc);
      }
      else {
        local_80 = *(undefined4 *)(local_14 + 0x9d0);
      }
      *(undefined4 *)(local_14 + 0x9c8) = local_80;
    }
    if ((param_1 == *(int *)(local_14 + 0x9cc)) && (param_2 != 1)) {
      if (param_2 == 0) {
        local_84 = *(undefined4 *)(local_14 + 0x9c8);
      }
      else {
        local_84 = *(undefined4 *)(local_14 + 0x9d0);
      }
      *(undefined4 *)(local_14 + 0x9cc) = local_84;
    }
    if ((param_1 == *(int *)(local_14 + 0x9d0)) && (param_2 != 2)) {
      if (param_2 == 0) {
        local_88 = *(undefined4 *)(local_14 + 0x9c8);
      }
      else {
        local_88 = *(undefined4 *)(local_14 + 0x9cc);
      }
      *(undefined4 *)(local_14 + 0x9d0) = local_88;
    }
    if (param_2 == 0) {
      *(int *)(local_14 + 0x9c8) = param_1;
    }
    if (param_2 == 1) {
      *(int *)(local_14 + 0x9cc) = param_1;
    }
    if (param_2 == 2) {
      *(int *)(local_14 + 0x9d0) = param_1;
    }
  }
  else {
    if ((param_1 == *(int *)(local_14 + 0x9bc)) && (param_2 != 0)) {
      if (param_2 == 1) {
        local_74 = *(undefined4 *)(local_14 + 0x9c0);
      }
      else {
        local_74 = *(undefined4 *)(local_14 + 0x9c4);
      }
      *(undefined4 *)(local_14 + 0x9bc) = local_74;
    }
    if ((param_1 == *(int *)(local_14 + 0x9c0)) && (param_2 != 1)) {
      if (param_2 == 0) {
        local_78 = *(undefined4 *)(local_14 + 0x9bc);
      }
      else {
        local_78 = *(undefined4 *)(local_14 + 0x9c4);
      }
      *(undefined4 *)(local_14 + 0x9c0) = local_78;
    }
    if ((param_1 == *(int *)(local_14 + 0x9c4)) && (param_2 != 2)) {
      if (param_2 == 0) {
        local_7c = *(undefined4 *)(local_14 + 0x9bc);
      }
      else {
        local_7c = *(undefined4 *)(local_14 + 0x9c0);
      }
      *(undefined4 *)(local_14 + 0x9c4) = local_7c;
    }
    if (param_2 == 0) {
      *(int *)(local_14 + 0x9bc) = param_1;
    }
    if (param_2 == 1) {
      *(int *)(local_14 + 0x9c0) = param_1;
    }
    if (param_2 == 2) {
      *(int *)(local_14 + 0x9c4) = param_1;
    }
  }
  return;
}

