
undefined4 __thiscall FUN_004a7480(undefined4 param_1,uint param_2,uint param_3)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  size_t sVar4;
  int local_10;
  int local_c;
  size_t local_8;
  
  local_8 = 0;
  uVar1 = FUN_004ce080(param_1);
  if (uVar1 < param_2) {
    FUN_004ce970(param_2);
  }
  for (local_c = 0; local_c < (int)param_2; local_c = local_c + 1) {
    if (DAT_00a0f7f8 == '\0') {
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        sVar4 = 4;
        pvVar2 = (void *)FUN_004ce990(local_c);
        _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),pvVar2,sVar4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
    }
    else {
      if (DAT_00a117e8 == 0) {
        DAT_00a0f844 = 4;
        sVar4 = 4;
        pvVar2 = (void *)FUN_004ce990(local_c);
        _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar2,sVar4);
      }
      else {
        DAT_00a0f844 = 4;
      }
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    }
  }
  uVar1 = FUN_004cc430();
  if (uVar1 < param_3) {
    FUN_004cc400(param_3);
  }
  for (local_10 = 0; local_10 < (int)param_3; local_10 = local_10 + 1) {
    FUN_004cc4c0(local_10);
    iVar3 = FUN_004e5650();
    local_8 = iVar3 + 1;
    FUN_004cc4c0(local_10);
    pvVar2 = (void *)FUN_004cbb30();
    if (DAT_00a0f7f8 == '\0') {
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_8,4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = local_8;
        _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),pvVar2,local_8);
      }
      DAT_00a11790 = DAT_00a11790 + local_8;
    }
    else {
      if (DAT_00a117e8 == 0) {
        DAT_00a0f844 = 4;
        _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_8,4);
      }
      else {
        DAT_00a0f844 = 4;
      }
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      if (DAT_00a117e8 == 0) {
        DAT_00a0f844 = local_8;
        _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar2,local_8);
      }
      else {
        DAT_00a0f844 = local_8;
      }
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    }
  }
  return 1;
}

