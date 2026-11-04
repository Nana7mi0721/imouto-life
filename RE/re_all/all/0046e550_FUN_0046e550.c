
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __thiscall FUN_0046e550(void *param_1,char param_2)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  undefined1 uStack00000000;
  size_t sVar4;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  byte local_10e;
  byte local_10d;
  char local_10c [260];
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  if (param_2 == '\0') {
    if (param_1 == (void *)0x0) {
      local_124 = 0xffffffff;
      __CxxThrowException_8(&local_124,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy(param_1,(void *)(DAT_00a0f830 + DAT_00a11790),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (&uStack00000000 == (undefined1 *)0x10d) {
      local_128 = 0xffffffff;
      __CxxThrowException_8(0xffffffe5,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy(&local_10d,(void *)(DAT_00a0f830 + DAT_00a11790),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    FUN_004ce970(local_10d);
    for (local_114 = 0; local_114 < (int)(uint)local_10d; local_114 = local_114 + 1) {
      iVar1 = FUN_004ce990(local_114);
      if (iVar1 == 0) {
        local_12c = 0xffffffff;
        __CxxThrowException_8(&local_12c,&DAT_00842f44);
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        sVar4 = 4;
        pvVar2 = (void *)(DAT_00a0f830 + DAT_00a11790);
        pvVar3 = (void *)FUN_004ce990(local_114);
        _memcpy(pvVar3,pvVar2,sVar4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
    }
    if (&uStack00000000 == (undefined1 *)0x10e) {
      local_130 = 0xffffffff;
      __CxxThrowException_8(0xffffffde,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy(&local_10e,(void *)(DAT_00a0f830 + DAT_00a11790),1);
    }
    for (local_118 = 0; DAT_00a11790 = DAT_00a11790 + 1, local_118 < (int)(uint)local_10e;
        local_118 = local_118 + 1) {
      if (local_10c + local_118 == (char *)0x0) {
        local_134 = 0xffffffff;
        __CxxThrowException_8(&local_134,&DAT_00842f44);
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 1;
        _memcpy(local_10c + local_118,(void *)(DAT_00a0f830 + DAT_00a11790),1);
      }
    }
  }
  else {
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
    _memcpy(&local_10d,(void *)(DAT_00a0f824 + DAT_00a0f820),1);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    FUN_004ce970(local_10d);
    for (local_11c = 0; local_11c < (int)(uint)local_10d; local_11c = local_11c + 1) {
      if (DAT_00a0f828 < DAT_00a0f820 + 4) {
        DAT_00a117e4 = 1;
        return 0;
      }
      DAT_00a0f844 = 4;
      sVar4 = 4;
      pvVar2 = (void *)(DAT_00a0f824 + DAT_00a0f820);
      pvVar3 = (void *)FUN_004ce990(local_11c);
      _memcpy(pvVar3,pvVar2,sVar4);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    }
    if (DAT_00a0f828 < DAT_00a0f820 + 1) {
      DAT_00a117e4 = 1;
      return 0;
    }
    DAT_00a0f844 = 1;
    _memcpy(&local_10e,(void *)(DAT_00a0f824 + DAT_00a0f820),1);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    for (local_120 = 0; local_120 < (int)(uint)local_10e; local_120 = local_120 + 1) {
      if (DAT_00a0f828 < DAT_00a0f820 + 1) {
        DAT_00a117e4 = 1;
        return 0;
      }
      DAT_00a0f844 = 1;
      _memcpy(local_10c + local_120,(void *)(DAT_00a0f824 + DAT_00a0f820),1);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    }
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
             ((int)param_1 + 0x14),local_10c);
  return 1;
}

