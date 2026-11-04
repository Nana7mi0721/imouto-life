
undefined4 __fastcall FUN_004a7730(void *param_1)

{
  int iVar1;
  void *pvVar2;
  size_t _Size;
  undefined4 local_50;
  undefined4 local_4c;
  int local_28;
  size_t local_24;
  void *local_20;
  int local_1c;
  void *local_18;
  undefined4 local_14;
  short local_10 [2];
  int local_c;
  void *local_8;
  
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x8ac),1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x8ad),1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x8b0),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x8b4),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  iVar1 = FUN_004717c0(1);
  if (*(int *)((int)param_1 + 0x8bc) < iVar1 + -10) {
    local_4c = *(undefined4 *)((int)param_1 + 0x8bc);
  }
  else {
    local_4c = 0xfffffffd;
  }
  local_14 = local_4c;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_14,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  iVar1 = FUN_004717c0(2);
  if (*(int *)((int)param_1 + 0x8c0) < iVar1 + -10) {
    local_50 = *(undefined4 *)((int)param_1 + 0x8c0);
  }
  else {
    local_50 = 0xfffffffd;
  }
  local_14 = local_50;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_14,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),param_1,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x914),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x8cc),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x8d0),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x8d4),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x8d8),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x8dc),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x8e0),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x8e4),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x8e8),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x8ec),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 0x12;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x8f0),0x12);
  }
  else {
    DAT_00a0f844 = 0x12;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x902),2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x904),2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 6;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x906),6);
  }
  else {
    DAT_00a0f844 = 6;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x90c),2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x90e),2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x918),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x91c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x920),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x924),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x928),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x92c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x930),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x934),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x938),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x94c),1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x93c),2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x940),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x944),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x94e),2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x950),2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x95c),2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x95e),2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x960),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x964),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x968),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x96c),1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x970),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x974),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x978),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x97c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x980),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x984),1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_c = FUN_004cc430();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_c,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_1c = 0; local_1c < local_c; local_1c = local_1c + 1) {
    FUN_004cc4c0(local_1c);
    iVar1 = FUN_004e5650();
    local_24 = iVar1 + 1;
    FUN_004cc4c0(local_1c);
    local_20 = (void *)FUN_004cbb30();
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
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_20,local_24);
    }
    else {
      DAT_00a0f844 = local_24;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  local_c = FUN_004ce080();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_c,4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  for (local_28 = 0; local_28 < local_c; local_28 = local_28 + 1) {
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 4;
      _Size = 4;
      pvVar2 = (void *)FUN_004ce990(local_28);
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar2,_Size);
    }
    else {
      DAT_00a0f844 = 4;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x9a8),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x9ac),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x9b0),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x9b4),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x9b8),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x9bc),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x9c8),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x9c0),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x9cc),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x9c4),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x9d0),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x954),2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_10[0] = FUN_004e5650();
  local_10[0] = local_10[0] + 1;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_10,2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_18 = (void *)FUN_004cbb30();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = (size_t)local_10[0];
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_18,DAT_00a0f844);
  }
  else {
    DAT_00a0f844 = (size_t)local_10[0];
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_10[0] = FUN_004e5650();
  local_10[0] = local_10[0] + 1;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_10,2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_8 = (void *)FUN_004cbb30();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = (size_t)local_10[0];
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_8,DAT_00a0f844);
  }
  else {
    DAT_00a0f844 = (size_t)local_10[0];
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0x9d4),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xa10),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xa14),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xa18),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_10[0] = FUN_004e5650();
  local_10[0] = local_10[0] + 1;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_10,2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  pvVar2 = (void *)FUN_004cbb30();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = (size_t)local_10[0];
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar2,DAT_00a0f844);
  }
  else {
    DAT_00a0f844 = (size_t)local_10[0];
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xa54),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xa58),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xa5c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_10[0] = FUN_004e5650();
  local_10[0] = local_10[0] + 1;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_10,2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  pvVar2 = (void *)FUN_004cbb30();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = (size_t)local_10[0];
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar2,DAT_00a0f844);
  }
  else {
    DAT_00a0f844 = (size_t)local_10[0];
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xa60),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xa64),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xa68),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_10[0] = FUN_004e5650();
  local_10[0] = local_10[0] + 1;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_10,2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  pvVar2 = (void *)FUN_004cbb30();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = (size_t)local_10[0];
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar2,DAT_00a0f844);
  }
  else {
    DAT_00a0f844 = (size_t)local_10[0];
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_10[0] = FUN_004e5650();
  local_10[0] = local_10[0] + 1;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_10,2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  pvVar2 = (void *)FUN_004cbb30();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = (size_t)local_10[0];
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar2,DAT_00a0f844);
  }
  else {
    DAT_00a0f844 = (size_t)local_10[0];
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xaf8),1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 1;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xaf9),1);
  }
  else {
    DAT_00a0f844 = 1;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_10[0] = FUN_004e5650();
  local_10[0] = local_10[0] + 1;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_10,2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  pvVar2 = (void *)FUN_004cbb30();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = (size_t)local_10[0];
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar2,DAT_00a0f844);
  }
  else {
    DAT_00a0f844 = (size_t)local_10[0];
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_10[0] = FUN_004e5650();
  local_10[0] = local_10[0] + 1;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_10,2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  pvVar2 = (void *)FUN_004cbb30();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = (size_t)local_10[0];
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar2,DAT_00a0f844);
  }
  else {
    DAT_00a0f844 = (size_t)local_10[0];
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_10[0] = FUN_004e5650();
  local_10[0] = local_10[0] + 1;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_10,2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  pvVar2 = (void *)FUN_004cbb30();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = (size_t)local_10[0];
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),pvVar2,DAT_00a0f844);
  }
  else {
    DAT_00a0f844 = (size_t)local_10[0];
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xafc),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xb00),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xb04),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xb08),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 4;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 0xb0c),4);
  }
  else {
    DAT_00a0f844 = 4;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  return 1;
}

