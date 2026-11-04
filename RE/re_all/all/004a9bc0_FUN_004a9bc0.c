
undefined4 __fastcall FUN_004a9bc0(int param_1)

{
  void *_Src;
  int local_1c;
  int local_18;
  short local_10 [2];
  void *local_c;
  short local_8 [2];
  
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x26c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x278),1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x279),1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x268),2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x264),1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x265),1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (*(char *)(param_1 + 0x264) == '\0') {
    local_10[0] = FUN_004e5650();
    local_10[0] = local_10[0] + 1;
    _Src = (void *)FUN_004cbb30();
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 2;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_10,2);
    }
    else {
      DAT_00a0f844 = 2;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = (size_t)local_10[0];
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),_Src,DAT_00a0f844);
    }
    else {
      DAT_00a0f844 = (size_t)local_10[0];
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  else {
    local_8[0] = FUN_004e5650();
    local_8[0] = local_8[0] + 1;
    local_c = (void *)FUN_004cbb30();
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 2;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_8,2);
    }
    else {
      DAT_00a0f844 = 2;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = (size_t)local_8[0];
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_c,DAT_00a0f844);
    }
    else {
      DAT_00a0f844 = (size_t)local_8[0];
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x188),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 400),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x270),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x274),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x198),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1a0),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1a8),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1b0),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1b4),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1d0),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1d8),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1b8),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
    for (local_1c = 0; local_1c < 3; local_1c = local_1c + 1) {
      if (DAT_00a117e8 == 0) {
        DAT_00a0f844 = 4;
        _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),
                (void *)(param_1 + 0x1e0 + local_18 * 0xc + local_1c * 4),4);
      }
      else {
        DAT_00a0f844 = 4;
      }
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    }
  }
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 700),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x2c0),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x2c8),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x2c4),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x2cc),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x2d4),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x2d0),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x2d8),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x2e0),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x2dc),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x300),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x304),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x308),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x30c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x31c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x318),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x310),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x314),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x266),1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x267),1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x240),1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x200),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x204),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x208),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x20c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x220),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x224),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x228),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x22c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 800),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x324),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x328),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x32c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x330),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x334),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x338),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x33c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x340),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x344),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x348),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x34c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x350),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x354),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x358),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x360),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x364),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x368),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x370),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x374),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x378),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x37c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x380),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 900),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  return CONCAT31((int3)((uint)DAT_00a0f820 >> 8),1);
}

