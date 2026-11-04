
undefined4 FUN_004b0b80(byte param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 extraout_var;
  int local_c;
  short local_8 [2];
  
  if (DAT_00a0f828 < DAT_00a0f820 + 2) {
    DAT_00a117e4 = 1;
    uVar1 = 0;
  }
  else {
    DAT_00a0f844 = 2;
    _memcpy(local_8,(void *)(DAT_00a0f824 + DAT_00a0f820),2);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (local_8[0] < 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = extraout_var;
      FUN_004d3150((int)local_8[0]);
      for (local_c = 0; local_c < local_8[0]; local_c = local_c + 1) {
        uVar2 = (uint)param_1;
        FUN_004d31e0(local_c);
        FUN_004b0c40(uVar2);
      }
      FUN_0049ed50(uVar1);
      uVar1 = 1;
    }
  }
  return uVar1;
}

