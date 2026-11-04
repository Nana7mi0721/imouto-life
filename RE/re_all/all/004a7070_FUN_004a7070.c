
undefined4 __fastcall FUN_004a7070(int param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  size_t sVar4;
  int iVar5;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  *(undefined4 *)(param_1 + 0x20) = 0xfffffffe;
  local_c = FUN_004ce080();
  local_10 = FUN_004cfc90();
  local_14 = 0;
  local_8 = 0;
  if (DAT_00a0f7f8 == '\0') {
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)(param_1 + 0x20),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)(param_1 + 0x24),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_c,4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
  }
  else {
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 4;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x20),4);
    }
    else {
      DAT_00a0f844 = 4;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 4;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)(param_1 + 0x24),4);
    }
    else {
      DAT_00a0f844 = 4;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 4;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_c,4);
    }
    else {
      DAT_00a0f844 = 4;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  for (local_18 = 0; local_18 < local_c; local_18 = local_18 + 1) {
    if (DAT_00a0f7f8 == '\0') {
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        sVar4 = 4;
        pvVar1 = (void *)FUN_004ce990(local_18);
        _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),pvVar1,sVar4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
    }
    else {
      if (DAT_00a117e8 == 0) {
        DAT_00a0f844 = 4;
        sVar4 = 4;
        pvVar1 = (void *)FUN_004ce990(local_18);
        _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar1,sVar4);
      }
      else {
        DAT_00a0f844 = 4;
      }
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    }
    piVar2 = (int *)FUN_004ce990(local_18);
    if (*piVar2 / 1000 == 1) {
      local_14 = local_14 + 1;
    }
    piVar2 = (int *)FUN_004ce990(local_18);
    if (*piVar2 / 1000 == 2) {
      local_8 = local_8 + 1;
    }
  }
  if (DAT_00a0f7f8 == '\0') {
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_10,4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
  }
  else {
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 4;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_10,4);
    }
    else {
      DAT_00a0f844 = 4;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  for (local_1c = 0; local_1c < local_10; local_1c = local_1c + 1) {
    iVar3 = local_14;
    iVar5 = local_8;
    FUN_004cfcd0(local_1c);
    FUN_004a7480(iVar3,iVar5);
  }
  return 1;
}

