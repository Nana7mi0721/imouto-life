
undefined4 FUN_00572ac0(int param_1)

{
  bool bVar1;
  
  if (param_1 < 0x4e5) {
    if (param_1 == 0x4e4) {
      return 1;
    }
    if (0x3b6 < param_1) {
      if (param_1 < 0x4b0) {
        return 0xffffffff;
      }
      if (param_1 < 0x4b2) {
        return 2;
      }
      return 0xffffffff;
    }
    if (0x3b4 < param_1) {
      return 1;
    }
    if (param_1 == 0x3a4) {
      return 1;
    }
    bVar1 = param_1 == 0x3a8;
  }
  else {
    if (param_1 < 0x8000) {
      if (0x7ffd < param_1) {
        return 4;
      }
      if (param_1 < 0x7ffc) {
        return 0xffffffff;
      }
      if (param_1 < 0x7ffe) {
        return 1;
      }
      return 0xffffffff;
    }
    bVar1 = param_1 == 0xfde9;
  }
  if (bVar1) {
    return 1;
  }
  return 0xffffffff;
}

