
undefined4 __fastcall FUN_004a6f70(undefined4 param_1)

{
  int local_10;
  undefined1 local_9;
  int local_8;
  
  DAT_00a0f7f8 = 1;
  local_9 = 0x6f;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_9,1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_8 = FUN_004d00e0(param_1);
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_8,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_10 = 0; local_10 < local_8; local_10 = local_10 + 1) {
    FUN_004d0120(local_10);
    FUN_004a7070();
  }
  DAT_00a0f7f8 = 0;
  return CONCAT31((int3)((uint)local_10 >> 8),1);
}

