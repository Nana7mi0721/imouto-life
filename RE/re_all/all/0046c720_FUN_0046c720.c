
undefined4 __fastcall FUN_0046c720(int param_1)

{
  void *pvVar1;
  int iVar2;
  size_t _Size;
  undefined4 uVar3;
  int local_14;
  int local_10;
  size_t local_c;
  char local_7;
  char local_6;
  char local_5;
  
  local_6 = FUN_004ce080();
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_6,1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  for (local_10 = 0; local_10 < local_6; local_10 = local_10 + 1) {
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _Size = 4;
      pvVar1 = (void *)FUN_004ce990(local_10);
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),pvVar1,_Size);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)(param_1 + 0x10),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  local_5 = FUN_004cc430();
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_5,1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  for (local_14 = 0; local_14 < local_5; local_14 = local_14 + 1) {
    FUN_004cc4c0(local_14);
    pvVar1 = (void *)FUN_004cbb30();
    FUN_004cc4c0(local_14);
    iVar2 = FUN_004e5650();
    local_c = iVar2 + 1;
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_c,4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = local_c;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),pvVar1,local_c);
    }
    DAT_00a11790 = DAT_00a11790 + local_c;
  }
  local_7 = FUN_004ce7d0();
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_7,1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if ('\0' < local_7) {
    uVar3 = 0;
    FUN_004ce810(0);
    FUN_0046bee0(uVar3);
  }
  return 1;
}

