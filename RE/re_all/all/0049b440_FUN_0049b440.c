
int FUN_0049b440(int param_1)

{
  int local_3c;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  if (DAT_0084b248 == 2) {
    if (*DAT_00a16714 < 0xdc) {
      if (param_1 < 0x50) {
        local_14 = param_1;
      }
      else {
        local_14 = 0x50;
      }
      if (local_14 < 2) {
        local_18 = 2;
      }
      else {
        if (param_1 < 0x50) {
          local_1c = param_1;
        }
        else {
          local_1c = 0x50;
        }
        local_18 = local_1c;
      }
      param_1 = local_18;
    }
    else {
      if (param_1 < 2) {
        local_10 = 2;
      }
      else {
        local_10 = param_1;
      }
      param_1 = local_10;
    }
    local_8 = param_1;
    if (DAT_00a14120 < 2) {
      switch(param_1) {
      case 4:
        local_8 = 3;
        break;
      case 5:
        local_8 = 6;
        break;
      case 9:
        local_8 = 8;
        break;
      case 0xb:
        local_8 = 10;
        break;
      case 0xd:
        local_8 = 0xc;
      }
    }
    if (local_8 < 0xc9) {
      local_24 = local_8;
    }
    else {
      local_24 = 200;
    }
    local_8 = local_24;
  }
  else {
    if (*DAT_00a16714 < 0xdc) {
      if (param_1 < 0x80) {
        local_2c = param_1;
      }
      else {
        local_2c = 0x80;
      }
      if (local_2c < 7) {
        local_30 = 7;
      }
      else {
        if (param_1 < 0x80) {
          local_34 = param_1;
        }
        else {
          local_34 = 0x80;
        }
        local_30 = local_34;
      }
      param_1 = local_30;
    }
    else {
      if (param_1 < 4) {
        local_28 = 4;
      }
      else {
        local_28 = param_1;
      }
      param_1 = local_28;
    }
    local_8 = param_1;
    if (DAT_00a14120 < 2) {
      switch(param_1) {
      case 8:
        local_8 = 7;
        break;
      case 10:
        local_8 = 9;
        break;
      case 0xb:
        local_8 = 9;
        break;
      case 0xd:
        local_8 = 0xc;
        break;
      case 0x12:
        local_8 = 0x11;
        break;
      case 0x16:
        local_8 = 0x15;
        break;
      case 0x1a:
        local_8 = 0x19;
      }
    }
    if (local_8 < 0x191) {
      local_3c = local_8;
    }
    else {
      local_3c = 400;
    }
    local_8 = local_3c;
  }
  return local_8;
}

