
undefined4 __thiscall FUN_0046df90(void *param_1,byte param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 uStack00000000;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (param_2 == 0) {
    if (param_1 == (void *)0xffffffff) {
      local_10 = 0xffffffff;
      __CxxThrowException_8(&local_10,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)((int)param_1 + 1),(void *)(DAT_00a0f830 + DAT_00a11790),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (param_1 == (void *)0xfffffffe) {
      local_14 = 0xffffffff;
      __CxxThrowException_8(&local_14,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)((int)param_1 + 2),(void *)(DAT_00a0f830 + DAT_00a11790),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (param_1 == (void *)0xfffffffd) {
      local_18 = 0xffffffff;
      __CxxThrowException_8(&local_18,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)((int)param_1 + 3),(void *)(DAT_00a0f830 + DAT_00a11790),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (param_1 == (void *)0x0) {
      local_1c = 0xffffffff;
      __CxxThrowException_8(&local_1c,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy(param_1,(void *)(DAT_00a0f830 + DAT_00a11790),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (param_1 == (void *)0xfffffffc) {
      local_20 = 0xffffffff;
      __CxxThrowException_8(&local_20,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)((int)param_1 + 4),(void *)(DAT_00a0f830 + DAT_00a11790),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (param_1 == (void *)0xfffffffb) {
      local_24 = 0xffffffff;
      __CxxThrowException_8(&local_24,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy((void *)((int)param_1 + 5),(void *)(DAT_00a0f830 + DAT_00a11790),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (&uStack00000000 == (undefined1 *)0x8) {
      __CxxThrowException_8(0xffffffe0,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_8,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
  }
  else {
    if (DAT_00a0f828 < DAT_00a0f820 + 1) {
      DAT_00a117e4 = 1;
      return 0;
    }
    DAT_00a0f844 = 1;
    _memcpy((void *)((int)param_1 + 1),(void *)(DAT_00a0f824 + DAT_00a0f820),1);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a0f828 < DAT_00a0f820 + 1) {
      DAT_00a117e4 = 1;
      return 0;
    }
    DAT_00a0f844 = 1;
    _memcpy((void *)((int)param_1 + 2),(void *)(DAT_00a0f824 + DAT_00a0f820),1);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a0f828 < DAT_00a0f820 + 1) {
      DAT_00a117e4 = 1;
      return 0;
    }
    DAT_00a0f844 = 1;
    _memcpy((void *)((int)param_1 + 3),(void *)(DAT_00a0f824 + DAT_00a0f820),1);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a0f828 < DAT_00a0f820 + 1) {
      DAT_00a117e4 = 1;
      return 0;
    }
    DAT_00a0f844 = 1;
    _memcpy(param_1,(void *)(DAT_00a0f824 + DAT_00a0f820),1);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a0f828 < DAT_00a0f820 + 1) {
      DAT_00a117e4 = 1;
      return 0;
    }
    DAT_00a0f844 = 1;
    _memcpy((void *)((int)param_1 + 4),(void *)(DAT_00a0f824 + DAT_00a0f820),1);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a0f828 < DAT_00a0f820 + 1) {
      DAT_00a117e4 = 1;
      return 0;
    }
    DAT_00a0f844 = 1;
    _memcpy((void *)((int)param_1 + 5),(void *)(DAT_00a0f824 + DAT_00a0f820),1);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a0f828 < DAT_00a0f820 + 4) {
      DAT_00a117e4 = 1;
      return 0;
    }
    DAT_00a0f844 = 4;
    _memcpy(&local_8,(void *)(DAT_00a0f824 + DAT_00a0f820),4);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  }
  if (local_8 < 0x10001) {
    FUN_004ce590(local_8);
    local_c = 0;
    while (iVar2 = FUN_004ce5c0(), local_c < iVar2) {
      uVar3 = (uint)param_2;
      FUN_004ce620(local_c);
      FUN_0046e550(uVar3);
      local_c = local_c + 1;
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

