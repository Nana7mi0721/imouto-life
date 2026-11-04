
undefined4 __thiscall FUN_0046c360(void *param_1,char param_2)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  size_t sVar4;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  byte local_a;
  byte local_9;
  int local_8;
  
  local_9 = FUN_004ce080();
  cVar1 = FUN_004e5650();
  local_a = cVar1 + 1;
  local_8 = FUN_004cbb30();
  if (param_2 == '\0') {
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),param_1,1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_9,1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    for (local_10 = 0; local_10 < (int)(uint)local_9; local_10 = local_10 + 1) {
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        sVar4 = 4;
        pvVar2 = (void *)FUN_004ce990(local_10);
        _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),pvVar2,sVar4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_a,1);
    }
    for (local_14 = 0; DAT_00a11790 = DAT_00a11790 + 1, iVar3 = DAT_00a11790,
        local_14 < (int)(uint)local_a; local_14 = local_14 + 1) {
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 1;
        _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)(local_8 + local_14),1);
      }
    }
  }
  else {
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 1;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),param_1,1);
    }
    else {
      DAT_00a0f844 = 1;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 1;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_9,1);
    }
    else {
      DAT_00a0f844 = 1;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    for (local_18 = 0; local_18 < (int)(uint)local_9; local_18 = local_18 + 1) {
      if (DAT_00a117e8 == 0) {
        DAT_00a0f844 = 4;
        sVar4 = 4;
        pvVar2 = (void *)FUN_004ce990(local_18);
        _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar2,sVar4);
      }
      else {
        DAT_00a0f844 = 4;
      }
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    }
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 1;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_a,1);
    }
    else {
      DAT_00a0f844 = 1;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    for (local_1c = 0; iVar3 = DAT_00a0f820, local_1c < (int)(uint)local_a; local_1c = local_1c + 1)
    {
      if (DAT_00a117e8 == 0) {
        DAT_00a0f844 = 1;
        _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(local_8 + local_1c),1);
      }
      else {
        DAT_00a0f844 = 1;
      }
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    }
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}

