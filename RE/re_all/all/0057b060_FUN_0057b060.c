
undefined4 FUN_0057b060(int param_1)

{
  int iVar1;
  
  if ((DAT_00ca39c8 == 0) || (DAT_00ca39d4 == 0)) {
    return 0xffffffff;
  }
  if (DAT_00ca39e8 != 0) {
    if (DAT_00ca39f4 != 0) {
      FUN_0057ae10(DAT_00a38194,DAT_00a38198,DAT_00a3819c,DAT_00a381a0);
    }
    DAT_00ca39e8 = 0;
  }
  DAT_00ca39f0 = param_1;
  if ((param_1 == 0) || (DAT_00ca39ec == 0)) {
    DAT_00ca39f4 = 0;
  }
  else {
    DAT_00ca39f4 = 1;
  }
  if (DAT_00a37d78 == 0) {
    if (DAT_00ca39f4 == 0) {
      iVar1 = FUN_00519300(DAT_00a38120,0);
      if (iVar1 == 0) {
        DAT_00a37e58 = (undefined4 *)&DAT_00a37df8;
      }
      else {
        DAT_00a37e58 = (undefined4 *)(iVar1 + 0x88);
      }
    }
    else {
      DAT_00a37e58 = &DAT_00ca3a00;
    }
  }
  else {
    FUN_005d9150();
  }
  if (DAT_00a37d94 != 0) {
    FUN_005217e0(DAT_00a38184,DAT_00a38188,DAT_00a3818c,DAT_00a38190);
  }
  return 0;
}

