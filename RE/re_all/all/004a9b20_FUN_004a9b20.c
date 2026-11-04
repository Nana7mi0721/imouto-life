
undefined4 __fastcall FUN_004a9b20(undefined4 param_1)

{
  int local_c;
  short local_8 [2];
  
  local_8[0] = FUN_004d3180(param_1);
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_8,2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_c = 0; local_c < local_8[0]; local_c = local_c + 1) {
    FUN_004d31e0(local_c);
    FUN_004a9bc0();
  }
  return 1;
}

