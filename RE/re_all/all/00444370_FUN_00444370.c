
undefined4 __fastcall FUN_00444370(int param_1)

{
  void *_Src;
  size_t _Size;
  int local_14;
  int local_10;
  undefined1 local_9;
  int local_8;
  
  FUN_00440f00();
  local_8 = DAT_0084b21c;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_8,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_10 = 0; local_10 < local_8; local_10 = local_10 + 1) {
    FUN_004d2620(local_10);
    FUN_00440f00();
  }
  local_9 = *(undefined1 *)(param_1 + 0x149);
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_9,1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_9 = *(undefined1 *)(param_1 + 0xc0);
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_9,1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_8 = FUN_004ce080();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_8,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_14 = 0; local_14 < local_8; local_14 = local_14 + 1) {
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 4;
      _Size = 4;
      _Src = (void *)FUN_004ce990(local_14);
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),_Src,_Size);
    }
    else {
      DAT_00a0f844 = 4;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  return 1;
}

