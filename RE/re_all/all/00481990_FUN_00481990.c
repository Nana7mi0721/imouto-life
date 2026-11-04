
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall
FUN_00481990(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1)

{
  LPCSTR lpText;
  int iVar1;
  void *pvVar2;
  uint *puVar3;
  iterator *this;
  void *pvVar4;
  undefined1 uStack00000000;
  undefined1 auStack_4b0 [12];
  undefined4 uStack_4a4;
  undefined1 *puStack_4a0;
  undefined1 *puVar5;
  LPCSTR lpCaption;
  UINT uType;
  size_t sVar6;
  undefined1 local_474 [4];
  undefined1 local_470 [4];
  undefined1 local_46c [4];
  undefined4 local_468;
  undefined4 local_464;
  undefined4 local_460;
  undefined4 local_45c;
  undefined4 local_458;
  undefined4 local_454;
  undefined1 *local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438;
  undefined4 local_434;
  int local_430;
  int local_42c;
  int local_428;
  int local_424;
  int local_420;
  int local_41c;
  undefined1 local_416;
  char local_415;
  char local_414 [1028];
  undefined4 local_10;
  int local_c;
  size_t local_8;
  
  local_10 = DAT_0084b484;
  local_c = 0;
  if (&uStack00000000 == (undefined1 *)0x8) {
    local_434 = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(&local_8,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (&uStack00000000 == (undefined1 *)0x414) {
    local_438 = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = local_8;
    _memcpy(local_414,(void *)(DAT_00a0f830 + DAT_00a11790),local_8);
  }
  DAT_00a11790 = DAT_00a11790 + local_8;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(param_1,local_414)
  ;
  for (local_41c = 0; local_41c < 8; local_41c = local_41c + 1) {
    if (&uStack00000000 == (undefined1 *)0x8) {
      local_43c = 0xffffffff;
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_8,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    if (&uStack00000000 == (undefined1 *)0x414) {
      local_440 = 0xffffffff;
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = local_8;
      _memcpy(local_414,(void *)(DAT_00a0f830 + DAT_00a11790),local_8);
    }
    DAT_00a11790 = DAT_00a11790 + local_8;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (param_1 + local_41c * 0x1c + 0x1c,local_414);
  }
  if (DAT_0084b26c < 3) {
    for (local_424 = 8; local_424 < 0x10; local_424 = local_424 + 1) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (param_1 + local_424 * 0x1c + 0x1c,"");
    }
  }
  else {
    for (local_420 = 8; local_420 < 0x10; local_420 = local_420 + 1) {
      if (&uStack00000000 == (undefined1 *)0x8) {
        local_444 = 0xffffffff;
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy(&local_8,(void *)(DAT_00a0f830 + DAT_00a11790),4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      if (&uStack00000000 == (undefined1 *)0x414) {
        local_448 = 0xffffffff;
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = local_8;
        _memcpy(local_414,(void *)(DAT_00a0f830 + DAT_00a11790),local_8);
      }
      DAT_00a11790 = DAT_00a11790 + local_8;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (param_1 + local_420 * 0x1c + 0x1c,local_414);
    }
  }
  if (&uStack00000000 == (undefined1 *)0x415) {
    local_44c = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy(&local_415,(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (local_415 != -1) {
    uType = 0;
    lpCaption = "";
    local_450 = auStack_4b0;
    basic_string<>(&DAT_007d0e68);
    lpText = (LPCSTR)FUN_00401c50();
    puStack_4a0 = (undefined1 *)0x481de2;
    MessageBoxA((HWND)0x0,lpText,lpCaption,uType);
  }
  if (&uStack00000000 == (undefined1 *)0xc) {
    local_454 = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(&local_c,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  FUN_004cf7d0();
  for (local_428 = 0; local_428 < local_c; local_428 = local_428 + 1) {
    iVar1 = FUN_004cd7c0();
    if (iVar1 == 0) {
      local_458 = 0xffffffff;
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      sVar6 = 1;
      pvVar4 = (void *)(DAT_00a0f830 + DAT_00a11790);
      pvVar2 = (void *)FUN_004cd7c0();
      _memcpy(pvVar2,pvVar4,sVar6);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
  }
  if (&uStack00000000 == (undefined1 *)0x416) {
    local_45c = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy(&local_416,(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (&uStack00000000 == (undefined1 *)0xc) {
    local_460 = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(&local_c,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  FUN_004ce970();
  for (local_42c = 0; local_42c < local_c; local_42c = local_42c + 1) {
    if (1 < DAT_0084b26c) {
      iVar1 = FUN_004ce990();
      if (iVar1 == 0) {
        local_464 = 0xffffffff;
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        sVar6 = 4;
        pvVar4 = (void *)(DAT_00a0f830 + DAT_00a11790);
        pvVar2 = (void *)FUN_004ce990();
        _memcpy(pvVar2,pvVar4,sVar6);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
    }
    if (DAT_0084b26c == 1) {
      iVar1 = FUN_004ce990();
      if (iVar1 == 0) {
        local_468 = 0xffffffff;
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 1;
        sVar6 = 1;
        pvVar2 = (void *)(DAT_00a0f830 + DAT_00a11790);
        pvVar4 = (void *)FUN_004ce990();
        _memcpy(pvVar4,pvVar2,sVar6);
      }
      DAT_00a11790 = DAT_00a11790 + 1;
      puVar3 = (uint *)FUN_004ce990();
      *puVar3 = *puVar3 & 0xff;
    }
  }
  if (DAT_0084b26c < 3) {
    puVar5 = local_470;
    puStack_4a0 = local_46c;
    uStack_4a4 = 0x4821d6;
    this = (iterator *)FUN_004ce060();
    puStack_4a0 = (undefined1 *)0x4821dd;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::iterator::operator+
              (this,(int)puVar5);
    FUN_004ec6d0();
    puStack_4a0 = local_474;
    uStack_4a4 = 0x482216;
    FUN_004ce060();
    puStack_4a0 = (undefined1 *)0x48221d;
    iterator__operator_();
    FUN_004ec710();
    local_430 = 0;
    while (iVar1 = FUN_004ce080(), local_430 < iVar1) {
      puVar3 = (uint *)FUN_004ce990();
      if ((*puVar3 & 0x110) != 0) {
        puVar3 = (uint *)FUN_004ce990();
        *puVar3 = *puVar3 | 0x200;
      }
      local_430 = local_430 + 1;
    }
  }
  return 1;
}

