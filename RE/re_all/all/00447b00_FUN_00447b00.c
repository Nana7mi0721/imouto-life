
undefined4 __fastcall FUN_00447b00(int param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  int local_40;
  int local_3c;
  int local_38;
  size_t local_30;
  int local_2c;
  void *local_28;
  size_t local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1658),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x165c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1660),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x161c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1620),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_18 = 0; local_18 < 3; local_18 = local_18 + 1) {
    for (local_1c = 0; local_1c < *(int *)(param_1 + 0x161c); local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < *(int *)(param_1 + 0x1620); local_20 = local_20 + 1) {
        if (DAT_00a117e8 == 0) {
          DAT_00a0f844 = 4;
          sVar4 = 4;
          iVar2 = local_1c;
          iVar3 = local_20;
          FUN_004cde80(local_18);
          FUN_004cde80(iVar2);
          pvVar1 = (void *)FUN_004ce990(iVar3);
          _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar1,sVar4);
        }
        else {
          DAT_00a0f844 = 4;
        }
        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      }
    }
  }
  local_28 = (void *)FUN_004cbb30();
  iVar2 = FUN_004e5650();
  local_24 = iVar2 + 1;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_24,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = local_24;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_28,local_24);
  }
  else {
    DAT_00a0f844 = local_24;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_8 = 0xf;
  for (local_2c = 0; local_2c < local_8; local_2c = local_2c + 1) {
    pvVar1 = (void *)FUN_004cbb30();
    iVar2 = FUN_004e5650();
    local_30 = iVar2 + 1;
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 4;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_30,4);
    }
    else {
      DAT_00a0f844 = 4;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = local_30;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar1,local_30);
    }
    else {
      DAT_00a0f844 = local_30;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  local_14 = FUN_004ce080();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_14,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_38 = 0; local_38 < local_14; local_38 = local_38 + 1) {
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 4;
      sVar4 = 4;
      pvVar1 = (void *)FUN_004ce990(local_38);
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar1,sVar4);
    }
    else {
      DAT_00a0f844 = 4;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  local_10 = FUN_004d29a0();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_10,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_3c = 0; local_3c < local_10; local_3c = local_3c + 1) {
    FUN_004d2a00(local_3c);
    FUN_00440f00();
  }
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x18ec),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x18f0),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x18f4),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x18f8),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x18fc),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1900),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1904),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1908),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x190c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1910),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x1914),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_c = FUN_004ce080();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_c,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_40 = 0; local_40 < local_c; local_40 = local_40 + 1) {
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 4;
      sVar4 = 4;
      pvVar1 = (void *)FUN_004ce990(local_40);
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar1,sVar4);
    }
    else {
      DAT_00a0f844 = 4;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  return 1;
}

