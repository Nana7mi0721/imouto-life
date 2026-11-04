
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __thiscall
FUN_00482e20(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,char param_2)

{
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  undefined1 uStack00000000;
  size_t sVar5;
  char *pcVar6;
  undefined4 local_c440;
  undefined4 local_c43c;
  undefined4 local_c438;
  undefined4 local_c434;
  undefined4 local_c430;
  undefined4 local_c42c;
  undefined4 local_c428;
  undefined4 local_c424;
  undefined4 local_c420;
  undefined4 local_c41c;
  undefined4 local_c418;
  undefined4 local_c414;
  undefined4 local_c410;
  undefined4 local_c40c;
  undefined4 local_c408;
  undefined4 local_c404;
  undefined4 local_c400;
  undefined4 local_c3fc;
  undefined4 local_c3f8;
  undefined4 local_c3f4;
  undefined4 local_c3f0;
  undefined4 local_c3ec;
  undefined4 local_c3e8;
  undefined4 local_c3e4;
  int local_c3e0;
  int local_c3dc;
  int local_c3d8;
  int local_c3d4;
  int local_c3d0;
  int local_c3cc;
  int local_c3c8;
  int local_c3c4;
  int local_c3c0;
  int local_c3bc;
  size_t local_c3b8;
  char local_c3b4 [50084];
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_8 = 0x482e2d;
  local_10 = DAT_0084b484;
  local_c3b8 = 0;
  if (&uStack00000000 == (undefined1 *)0xc3b8) {
    local_c3e4 = 0xffffffff;
    __CxxThrowException_8(0xffffffd4,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(&local_c3b8,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (&uStack00000000 == (undefined1 *)0xc3b4) {
    local_c3e8 = 0xffffffff;
    __CxxThrowException_8(0xffffffcc,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = local_c3b8;
    _memcpy(local_c3b4,(void *)(DAT_00a0f830 + DAT_00a11790),local_c3b8);
  }
  DAT_00a11790 = DAT_00a11790 + local_c3b8;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (param_1,local_c3b4);
  if (&uStack00000000 == (undefined1 *)0x8) {
    local_c3ec = 0xffffffff;
    __CxxThrowException_8(0xffff3c1c,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(&local_8,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  FUN_004cc400(local_8);
  for (local_c3c0 = 0; local_c3c0 < local_8; local_c3c0 = local_c3c0 + 1) {
    if (&uStack00000000 == (undefined1 *)0xc3b8) {
      local_c3f0 = 0xffffffff;
      __CxxThrowException_8(0xffffffc8,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_c3b8,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    if (&uStack00000000 == (undefined1 *)0xc3b4) {
      local_c3f4 = 0xffffffff;
      __CxxThrowException_8(0xffffffc0,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = local_c3b8;
      _memcpy(local_c3b4,(void *)(DAT_00a0f830 + DAT_00a11790),local_c3b8);
    }
    DAT_00a11790 = DAT_00a11790 + local_c3b8;
    pcVar6 = local_c3b4;
    pbVar1 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
             FUN_004cc4c0(local_c3c0);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(pbVar1,pcVar6);
  }
  if (param_2 != '\0') {
    if (&uStack00000000 == (undefined1 *)0xc) {
      local_c3f8 = 0xffffffff;
      __CxxThrowException_8(0xffff3c14,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_c,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    FUN_004cc400(local_c);
    for (local_c3c4 = 0; local_c3c4 < local_c; local_c3c4 = local_c3c4 + 1) {
      if (&uStack00000000 == (undefined1 *)0xc3b8) {
        local_c3fc = 0xffffffff;
        __CxxThrowException_8(0xffffffbc,&DAT_00842f44);
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy(&local_c3b8,(void *)(DAT_00a0f830 + DAT_00a11790),4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      if (&uStack00000000 == (undefined1 *)0xc3b4) {
        local_c400 = 0xffffffff;
        __CxxThrowException_8(0xffffffb4,&DAT_00842f44);
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = local_c3b8;
        _memcpy(local_c3b4,(void *)(DAT_00a0f830 + DAT_00a11790),local_c3b8);
      }
      DAT_00a11790 = DAT_00a11790 + local_c3b8;
      pcVar6 = local_c3b4;
      pbVar1 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
               FUN_004cc4c0(local_c3c4);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(pbVar1,pcVar6)
      ;
    }
  }
  FUN_004cc400(local_8);
  FUN_004cde50(local_8);
  FUN_004cd310(local_8);
  FUN_004ce970(local_8);
  if (&uStack00000000 == (undefined1 *)0xc3b8) {
    local_c404 = 0xffffffff;
    __CxxThrowException_8(0xffffffb4,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(&local_c3b8,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (&uStack00000000 == (undefined1 *)0xc3b4) {
    local_c408 = 0xffffffff;
    __CxxThrowException_8(0xffffffac,&DAT_00842f44);
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = local_c3b8;
    _memcpy(local_c3b4,(void *)(DAT_00a0f830 + DAT_00a11790),local_c3b8);
  }
  DAT_00a11790 = DAT_00a11790 + local_c3b8;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (param_1 + 0x1c,local_c3b4);
  if (DAT_00a0f808 != 0xc0) {
    if (&uStack00000000 == (undefined1 *)0xc) {
      local_c40c = 0xffffffff;
      __CxxThrowException_8(0xffff3c00,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_c,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    for (local_c3c8 = 0; local_c3c8 < local_c; local_c3c8 = local_c3c8 + 1) {
      iVar2 = FUN_004cd7c0(local_c3c8);
      if (iVar2 == 0) {
        local_c410 = 0xffffffff;
        __CxxThrowException_8(&local_c410,&DAT_00842f44);
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 1;
        sVar5 = 1;
        pvVar4 = (void *)(DAT_00a0f830 + DAT_00a11790);
        pvVar3 = (void *)FUN_004cd7c0(local_c3c8);
        _memcpy(pvVar3,pvVar4,sVar5);
      }
      DAT_00a11790 = DAT_00a11790 + 1;
    }
    if (&uStack00000000 == (undefined1 *)0xc) {
      local_c414 = 0xffffffff;
      __CxxThrowException_8(0xffff3bf8,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_c,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    for (local_c3cc = 0; local_c3cc < local_c; local_c3cc = local_c3cc + 1) {
      if (&uStack00000000 == (undefined1 *)0xc3b8) {
        local_c418 = 0xffffffff;
        __CxxThrowException_8(0xffffffa0,&DAT_00842f44);
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy(&local_c3b8,(void *)(DAT_00a0f830 + DAT_00a11790),4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      if (&uStack00000000 == (undefined1 *)0xc3b4) {
        local_c41c = 0xffffffff;
        __CxxThrowException_8(0xffffff98,&DAT_00842f44);
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = local_c3b8;
        _memcpy(local_c3b4,(void *)(DAT_00a0f830 + DAT_00a11790),local_c3b8);
      }
      DAT_00a11790 = DAT_00a11790 + local_c3b8;
      pcVar6 = local_c3b4;
      pbVar1 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
               FUN_004cc4c0(local_c3cc);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(pbVar1,pcVar6)
      ;
    }
    if (&uStack00000000 == (undefined1 *)0xc3bc) {
      local_c420 = 0xffffffff;
      __CxxThrowException_8(0xffffff9c,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_c3bc,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    for (local_c3d0 = 0; local_c3d0 < local_c3bc; local_c3d0 = local_c3d0 + 1) {
      if (&uStack00000000 == (undefined1 *)0xc) {
        local_c424 = 0xffffffff;
        __CxxThrowException_8(0xffff3be8,&DAT_00842f44);
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy(&local_c,(void *)(DAT_00a0f830 + DAT_00a11790),4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      iVar2 = local_c;
      FUN_004cde80(local_c3d0);
      FUN_004cc400(iVar2);
      for (local_c3d4 = 0; local_c3d4 < local_c; local_c3d4 = local_c3d4 + 1) {
        if (&uStack00000000 == (undefined1 *)0xc3b8) {
          local_c428 = 0xffffffff;
          __CxxThrowException_8(0xffffff90,&DAT_00842f44);
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = 4;
          _memcpy(&local_c3b8,(void *)(DAT_00a0f830 + DAT_00a11790),4);
        }
        DAT_00a11790 = DAT_00a11790 + 4;
        if (&uStack00000000 == (undefined1 *)0xc3b4) {
          local_c42c = 0xffffffff;
          __CxxThrowException_8(0xffffff88,&DAT_00842f44);
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = local_c3b8;
          _memcpy(local_c3b4,(void *)(DAT_00a0f830 + DAT_00a11790),local_c3b8);
        }
        DAT_00a11790 = DAT_00a11790 + local_c3b8;
        pcVar6 = local_c3b4;
        iVar2 = local_c3d4;
        FUN_004cde80(local_c3d0);
        pbVar1 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 FUN_004cc4c0(iVar2);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (pbVar1,pcVar6);
      }
    }
    local_c3bc = FUN_004cd340();
    if (&uStack00000000 == (undefined1 *)0xc3bc) {
      local_c430 = 0xffffffff;
      __CxxThrowException_8(0xffffff8c,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_c3bc,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    for (local_c3d8 = 0; local_c3d8 < local_c3bc; local_c3d8 = local_c3d8 + 1) {
      if (&uStack00000000 == (undefined1 *)0xc) {
        local_c434 = 0xffffffff;
        __CxxThrowException_8(0xffff3bd8,&DAT_00842f44);
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy(&local_c,(void *)(DAT_00a0f830 + DAT_00a11790),4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      iVar2 = local_c;
      FUN_004cde80(local_c3d8);
      FUN_004ce970(iVar2);
      for (local_c3dc = 0; local_c3dc < local_c; local_c3dc = local_c3dc + 1) {
        iVar2 = local_c3dc;
        FUN_004cde80(local_c3d8);
        iVar2 = FUN_004ce990(iVar2);
        if (iVar2 == 0) {
          local_c438 = 0xffffffff;
          __CxxThrowException_8(&local_c438,&DAT_00842f44);
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = 4;
          sVar5 = 4;
          pvVar4 = (void *)(DAT_00a0f830 + DAT_00a11790);
          iVar2 = local_c3dc;
          FUN_004cde80(local_c3d8);
          pvVar3 = (void *)FUN_004ce990(iVar2);
          _memcpy(pvVar3,pvVar4,sVar5);
        }
        DAT_00a11790 = DAT_00a11790 + 4;
      }
    }
    if (&uStack00000000 == (undefined1 *)0xc) {
      local_c43c = 0xffffffff;
      __CxxThrowException_8(0xffff3bd0,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_c,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    for (local_c3e0 = 0; DAT_00a11790 = DAT_00a11790 + 4, local_c3e0 < local_c;
        local_c3e0 = local_c3e0 + 1) {
      iVar2 = FUN_004ce990(local_c3e0);
      if (iVar2 == 0) {
        local_c440 = 0xffffffff;
        __CxxThrowException_8(&local_c440,&DAT_00842f44);
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        sVar5 = 4;
        pvVar3 = (void *)(DAT_00a0f830 + DAT_00a11790);
        pvVar4 = (void *)FUN_004ce990(local_c3e0);
        _memcpy(pvVar4,pvVar3,sVar5);
      }
    }
  }
  return 1;
}

