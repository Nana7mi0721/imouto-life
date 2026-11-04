
undefined4 FUN_005bb1f0(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (DAT_00f07678 == param_1) {
    if (DAT_00ef7324 == 0) {
      return 0;
    }
  }
  else if (DAT_00ef7324 == 0) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
  }
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else if (param_1 == 1) {
    uVar1 = 0x15;
  }
  else {
    if (param_1 != 2) {
      return 0xffffffff;
    }
    uVar1 = 0x55;
  }
  FUN_005b90c0(uVar1,0xffffffff);
  DAT_00f07678 = param_1;
  DAT_00ef72cc = 1;
  return 0;
}

