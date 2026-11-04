
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __fastcall FUN_0047f3d0(void *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  LPCSTR pCVar4;
  LPCSTR pCVar5;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbVar6;
  void *pvVar7;
  undefined1 uStack00000000;
  size_t sVar8;
  UINT UVar9;
  char *pcVar10;
  CBitmapButton local_17ec [84];
  undefined4 local_1798;
  undefined4 local_1794;
  undefined4 local_1790;
  undefined4 local_178c;
  undefined4 local_1788;
  undefined4 local_1784;
  undefined4 local_1780;
  undefined4 local_177c;
  undefined4 local_1778;
  undefined4 local_1774;
  char local_1770 [2052];
  size_t local_f6c;
  undefined1 local_f68 [2048];
  size_t local_768;
  int local_764;
  char local_760 [260];
  size_t local_65c;
  int local_658;
  int local_654;
  int local_650;
  int local_64c;
  char local_648 [512];
  int local_448;
  int local_444;
  int local_440;
  int local_43c;
  char local_438 [516];
  int local_234;
  int local_230;
  int local_22c;
  int local_228;
  int local_224;
  char local_21d;
  int local_21c;
  char local_218 [512];
  undefined4 local_18;
  size_t local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af36b;
  local_10 = ExceptionList;
  local_14 = 0x47f3f2;
  local_18 = DAT_0084b484;
  ExceptionList = &local_10;
  FUN_004cc250();
  FUN_004cc400();
  FUN_004cd870();
  FUN_004cf7d0();
  FUN_004cdf30();
  FUN_004cde50();
  FUN_004cd4c0();
  FUN_004cd310();
  FUN_004ce950();
  FUN_004ce970();
  if (&uStack00000000 == (undefined1 *)0x21d) {
    local_1774 = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy(&local_21d,(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (param_1 == (void *)0x0) {
    local_1778 = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(param_1,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (param_1 == (void *)0xffffffe0) {
    local_177c = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)((int)param_1 + 0x20),(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (param_1 == (void *)0xffffffdc) {
    local_1780 = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)((int)param_1 + 0x24),(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (param_1 == (void *)0xffffffd8) {
    local_1784 = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)((int)param_1 + 0x28),(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (param_1 == (void *)0xffffffd4) {
    local_1788 = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)((int)param_1 + 0x2c),(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (param_1 == (void *)0xffffffd3) {
    local_178c = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)((int)param_1 + 0x2d),(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (&uStack00000000 == (undefined1 *)0x14) {
    local_1790 = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(&local_14,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  if (&uStack00000000 == (undefined1 *)0x218) {
    local_1794 = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = local_14;
    _memcpy(local_218,(void *)(DAT_00a0f830 + DAT_00a11790),local_14);
  }
  DAT_00a11790 = DAT_00a11790 + local_14;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)((int)param_1 + 4),
             local_218);
  if (&uStack00000000 == (undefined1 *)0x228) {
    local_1798 = 0xffffffff;
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(&local_228,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  FUN_004cee50();
  for (local_22c = 0; local_22c < local_228; local_22c = local_22c + 1) {
    FUN_0046d3c0();
    local_8 = 0;
    FUN_004ced60();
    local_8 = 0xffffffff;
    CBitmapButton::~CBitmapButton(local_17ec);
    FUN_004cecd0();
    FUN_0046eac0();
  }
  FUN_004cecd0();
  puVar1 = (undefined4 *)FUN_004ce990();
  *puVar1 = 0xffffffff;
  if (&uStack00000000 == (undefined1 *)0x21c) {
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy(&local_21c,(void *)(DAT_00a0f830 + DAT_00a11790),4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  iVar2 = FUN_004cd730();
  if (iVar2 < local_21c) {
    FUN_004cf7d0();
  }
  for (local_230 = 0; local_230 < local_21c; local_230 = local_230 + 1) {
    iVar2 = FUN_004cd7c0();
    if (iVar2 == 0) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      sVar8 = 1;
      pvVar7 = (void *)(DAT_00a0f830 + DAT_00a11790);
      pvVar3 = (void *)FUN_004cd7c0();
      _memcpy(pvVar3,pvVar7,sVar8);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
  }
  if (0 < local_21c) {
    if (&uStack00000000 == (undefined1 *)0x14) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_14,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    if (&uStack00000000 == (undefined1 *)0x218) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = local_14;
      _memcpy(local_218,(void *)(DAT_00a0f830 + DAT_00a11790),local_14);
    }
    DAT_00a11790 = DAT_00a11790 + local_14;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
               ((int)param_1 + 0x50),local_218);
  }
  if (&uStack00000000 == (undefined1 *)0x21d) {
    __CxxThrowException_8();
  }
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy(&local_21d,(void *)(DAT_00a0f830 + DAT_00a11790),1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  if (((local_21d != -0x72) && (local_21d != -0x71)) && (local_21d != -0x70)) {
    UVar9 = 0;
    basic_string<>();
    pCVar4 = (LPCSTR)FUN_00401c50();
    basic_string<>(&DAT_007d0da8);
    pCVar5 = (LPCSTR)FUN_00401c50();
    MessageBoxA((HWND)0x0,pCVar5,pCVar4,UVar9);
  }
  if (local_21d != -0x72) {
    if (&uStack00000000 == (undefined1 *)0x224) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_224,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    iVar2 = FUN_004cc430();
    if (iVar2 < local_224) {
      FUN_004cc400();
    }
    for (local_234 = 0; local_234 < local_224; local_234 = local_234 + 1) {
      if (&uStack00000000 == (undefined1 *)0x14) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy(&local_14,(void *)(DAT_00a0f830 + DAT_00a11790),4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      if (&uStack00000000 == (undefined1 *)0x438) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = local_14;
        _memcpy(local_438,(void *)(DAT_00a0f830 + DAT_00a11790),local_14);
      }
      DAT_00a11790 = DAT_00a11790 + local_14;
      pcVar10 = local_438;
      pbVar6 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)FUN_004cc4c0();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (pbVar6,pcVar10);
    }
    FUN_004cd870();
    if (&uStack00000000 == (undefined1 *)0x224) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_224,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    iVar2 = FUN_004cd730();
    if (iVar2 < local_224) {
      FUN_004cf7d0();
    }
    for (local_43c = 0; local_43c < local_224; local_43c = local_43c + 1) {
      iVar2 = FUN_004cd7c0();
      if (iVar2 == 0) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 1;
        sVar8 = 1;
        pvVar3 = (void *)(DAT_00a0f830 + DAT_00a11790);
        pvVar7 = (void *)FUN_004cd7c0();
        _memcpy(pvVar7,pvVar3,sVar8);
      }
      DAT_00a11790 = DAT_00a11790 + 1;
    }
    local_224 = FUN_004cd340();
    if (&uStack00000000 == (undefined1 *)0x224) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_224,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    iVar2 = FUN_004cd340();
    if (iVar2 < local_224) {
      FUN_004cde50();
    }
    for (local_440 = 0; local_440 < local_224; local_440 = local_440 + 1) {
      if (&uStack00000000 == (undefined1 *)0x444) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy(&local_444,(void *)(DAT_00a0f830 + DAT_00a11790),4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      FUN_004cde80();
      iVar2 = FUN_004cc430();
      if (iVar2 < local_444) {
        FUN_004cde80();
        FUN_004cc400();
      }
      for (local_448 = 0; local_448 < local_444; local_448 = local_448 + 1) {
        if (&uStack00000000 == (undefined1 *)0x14) {
          __CxxThrowException_8();
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = 4;
          _memcpy(&local_14,(void *)(DAT_00a0f830 + DAT_00a11790),4);
        }
        DAT_00a11790 = DAT_00a11790 + 4;
        if (&uStack00000000 == (undefined1 *)0x648) {
          __CxxThrowException_8();
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = local_14;
          _memcpy(local_648,(void *)(DAT_00a0f830 + DAT_00a11790),local_14);
        }
        DAT_00a11790 = DAT_00a11790 + local_14;
        pcVar10 = local_648;
        FUN_004cde80();
        pbVar6 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)FUN_004cc4c0();
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (pbVar6,pcVar10);
      }
    }
    if (&uStack00000000 == (undefined1 *)0x224) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_224,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    iVar2 = FUN_004cd340();
    if (iVar2 < local_224) {
      FUN_004cd310();
    }
    for (local_64c = 0; local_64c < local_224; local_64c = local_64c + 1) {
      if (&uStack00000000 == (undefined1 *)0x650) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy(&local_650,(void *)(DAT_00a0f830 + DAT_00a11790),4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      FUN_004cde80();
      iVar2 = FUN_004ce080();
      if (iVar2 < local_650) {
        FUN_004cde80();
        FUN_004ce970();
      }
      for (local_654 = 0; local_654 < local_650; local_654 = local_654 + 1) {
        FUN_004cde80();
        iVar2 = FUN_004ce990();
        if (iVar2 == 0) {
          __CxxThrowException_8();
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = 4;
          sVar8 = 4;
          pvVar3 = (void *)(DAT_00a0f830 + DAT_00a11790);
          FUN_004cde80();
          pvVar7 = (void *)FUN_004ce990();
          _memcpy(pvVar7,pvVar3,sVar8);
        }
        DAT_00a11790 = DAT_00a11790 + 4;
      }
    }
    if (&uStack00000000 == (undefined1 *)0x224) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 4;
      _memcpy(&local_224,(void *)(DAT_00a0f830 + DAT_00a11790),4);
    }
    DAT_00a11790 = DAT_00a11790 + 4;
    iVar2 = FUN_004ce080();
    if (iVar2 < local_224) {
      FUN_004ce970();
    }
    for (local_658 = 0; local_658 < local_224; local_658 = local_658 + 1) {
      iVar2 = FUN_004ce990();
      if (iVar2 == 0) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        sVar8 = 4;
        pvVar3 = (void *)(DAT_00a0f830 + DAT_00a11790);
        pvVar7 = (void *)FUN_004ce990();
        _memcpy(pvVar7,pvVar3,sVar8);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
    }
    if (&uStack00000000 == (undefined1 *)0x21d) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy(&local_21d,(void *)(DAT_00a0f830 + DAT_00a11790),1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if ((local_21d != -0x71) && (local_21d != -0x70)) {
      UVar9 = 0;
      basic_string<>();
      pCVar4 = (LPCSTR)FUN_00401c50();
      basic_string<>(&DAT_007d0da8);
      pCVar5 = (LPCSTR)FUN_00401c50();
      MessageBoxA((HWND)0x0,pCVar5,pCVar4,UVar9);
    }
    if (local_21d == -0x70) {
      if (param_1 == (void *)0xfffff454) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy((void *)((int)param_1 + 0xbac),(void *)(DAT_00a0f830 + DAT_00a11790),4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      for (local_764 = 0; local_764 < 100; local_764 = local_764 + 1) {
        if (&uStack00000000 == (undefined1 *)0x65c) {
          __CxxThrowException_8();
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = 4;
          _memcpy(&local_65c,(void *)(DAT_00a0f830 + DAT_00a11790),4);
        }
        DAT_00a11790 = DAT_00a11790 + 4;
        if (&uStack00000000 == (undefined1 *)0x760) {
          __CxxThrowException_8();
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = local_65c;
          _memcpy(local_760,(void *)(DAT_00a0f830 + DAT_00a11790),local_65c);
        }
        DAT_00a11790 = DAT_00a11790 + local_65c;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                   ((int)param_1 + local_764 * 0x1c + 0xbc),local_760);
      }
      if (&uStack00000000 == (undefined1 *)0x21d) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 1;
        _memcpy(&local_21d,(void *)(DAT_00a0f830 + DAT_00a11790),1);
      }
      DAT_00a11790 = DAT_00a11790 + 1;
      if ((local_21d != -0x70) && (local_21d != -0x6f)) {
        UVar9 = 0;
        basic_string<>();
        pCVar4 = (LPCSTR)FUN_00401c50();
        basic_string<>(&DAT_007d0da8);
        pCVar5 = (LPCSTR)FUN_00401c50();
        MessageBoxA((HWND)0x0,pCVar5,pCVar4,UVar9);
      }
      if (local_21d == -0x6f) {
        if (&uStack00000000 == (undefined1 *)0x768) {
          __CxxThrowException_8();
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = 4;
          _memcpy(&local_768,(void *)(DAT_00a0f830 + DAT_00a11790),4);
        }
        DAT_00a11790 = DAT_00a11790 + 4;
        if (&uStack00000000 == (undefined1 *)0xf68) {
          __CxxThrowException_8();
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = local_768;
          _memcpy(local_f68,(void *)(DAT_00a0f830 + DAT_00a11790),local_768);
        }
        DAT_00a11790 = DAT_00a11790 + local_768;
        if (&uStack00000000 == (undefined1 *)0x21d) {
          __CxxThrowException_8();
        }
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = 1;
          _memcpy(&local_21d,(void *)(DAT_00a0f830 + DAT_00a11790),1);
        }
        DAT_00a11790 = DAT_00a11790 + 1;
        if ((local_21d != -0x6f) && (local_21d != -0x6e)) {
          UVar9 = 0;
          basic_string<>();
          pCVar4 = (LPCSTR)FUN_00401c50();
          basic_string<>(&DAT_007d0da8);
          pCVar5 = (LPCSTR)FUN_00401c50();
          MessageBoxA((HWND)0x0,pCVar5,pCVar4,UVar9);
        }
        if (local_21d == -0x6e) {
          if (&uStack00000000 == (undefined1 *)0xf6c) {
            __CxxThrowException_8();
          }
          if (DAT_00a117ec == 0) {
            DAT_00a1179c = 4;
            _memcpy(&local_f6c,(void *)(DAT_00a0f830 + DAT_00a11790),4);
          }
          DAT_00a11790 = DAT_00a11790 + 4;
          if (&uStack00000000 == (undefined1 *)0x1770) {
            __CxxThrowException_8();
          }
          if (DAT_00a117ec == 0) {
            DAT_00a1179c = local_f6c;
            _memcpy(local_1770,(void *)(DAT_00a0f830 + DAT_00a11790),local_f6c);
          }
          DAT_00a11790 = DAT_00a11790 + local_f6c;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                     ((int)param_1 + 0xbd0),local_1770);
          if (param_1 == (void *)0xfffff434) {
            __CxxThrowException_8();
          }
          if (DAT_00a117ec == 0) {
            DAT_00a1179c = 4;
            _memcpy((void *)((int)param_1 + 0xbcc),(void *)(DAT_00a0f830 + DAT_00a11790),4);
          }
          DAT_00a11790 = DAT_00a11790 + 4;
          if (&uStack00000000 == (undefined1 *)0x21d) {
            __CxxThrowException_8();
          }
          if (DAT_00a117ec == 0) {
            DAT_00a1179c = 1;
            _memcpy(&local_21d,(void *)(DAT_00a0f830 + DAT_00a11790),1);
          }
          DAT_00a11790 = DAT_00a11790 + 1;
          if (local_21d != -0x6e) {
            UVar9 = 0;
            basic_string<>();
            pCVar4 = (LPCSTR)FUN_00401c50();
            basic_string<>(&DAT_007d0da8);
            pCVar5 = (LPCSTR)FUN_00401c50();
            MessageBoxA((HWND)0x0,pCVar5,pCVar4,UVar9);
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  return 1;
}

