
undefined4 __thiscall FUN_0046bee0(void *param_1,byte param_2)

{
  int iVar1;
  uint uVar2;
  int local_c;
  undefined4 local_8;
  
  local_8 = FUN_004ce5c0();
  if (param_2 == 0) {
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 1),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 2),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 3),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),param_1,1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 4),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),(void *)((int)param_1 + 5),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy((void *)(DAT_00a0f830 + DAT_00a11790),&local_8,4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
  }
  else {
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 1;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 1),1);
    }
    else {
      DAT_00a0f844 = 1;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 1;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 2),1);
    }
    else {
      DAT_00a0f844 = 1;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 1;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 3),1);
    }
    else {
      DAT_00a0f844 = 1;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
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
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 4),1);
    }
    else {
      DAT_00a0f844 = 1;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 1;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),(void *)((int)param_1 + 5),1);
    }
    else {
      DAT_00a0f844 = 1;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a117e8 == 0) {
      DAT_00a0f844 = 4;
      _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&local_8,4);
    }
    else {
      DAT_00a0f844 = 4;
    }
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  local_c = 0;
  while( true ) {
    iVar1 = FUN_004ce5c0();
    if (iVar1 <= local_c) break;
    uVar2 = (uint)param_2;
    FUN_004ce620(local_c);
    FUN_0046c360(uVar2);
    local_c = local_c + 1;
  }
  return 1;
}

