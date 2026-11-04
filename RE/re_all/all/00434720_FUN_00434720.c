
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00435fc5) */
/* WARNING: Removing unreachable block (ram,0x004349a2) */
/* WARNING: Removing unreachable block (ram,0x0043607d) */
/* WARNING: Removing unreachable block (ram,0x004360ce) */
/* WARNING: Removing unreachable block (ram,0x0043611a) */
/* WARNING: Removing unreachable block (ram,0x004360bf) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00434720(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar4;
  int *piVar5;
  float10 fVar6;
  int local_5c8;
  int local_408;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_404 [32];
  int local_3e4;
  undefined4 local_3e0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3dc [28];
  int local_3c0;
  int local_3bc;
  int local_3b8;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_3b4 [28];
  int local_398;
  int local_394;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_390 [28];
  undefined *local_374;
  int local_370;
  undefined4 local_36c;
  CHAR local_368 [260];
  undefined4 local_264;
  int local_260;
  int local_25c;
  int local_254;
  int local_250;
  int local_24c;
  undefined4 local_248;
  int local_244;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_240 [28];
  int local_224;
  char local_220 [256];
  char local_120 [260];
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007ad08d;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  ExceptionList = &local_10;
  if ((DAT_00a1fb94 & 1) == 0) {
    DAT_00a1fb94 = DAT_00a1fb94 | 1;
    local_8 = 0;
    ExceptionList = &local_10;
    _DAT_00a1fb90 = FUN_00550060();
  }
  local_8 = 0xffffffff;
  DAT_00a1fb8c = DAT_00a1fb8c + 1;
  fVar6 = (float10)FUN_0050e8d0();
  if ((float10)_DAT_0084b3b8 != fVar6) {
    iVar2 = FUN_00550060();
    DAT_00a1fb84 = iVar2 + 0x3c8c;
    fVar6 = (float10)FUN_0050e8d0();
    _DAT_0084b3b8 = (double)fVar6;
  }
  iVar2 = FUN_00550060();
  if ((iVar2 < DAT_00a1fb84) && (fVar6 = (float10)FUN_0050e8d0(), (float10)_DAT_00802e18 != fVar6))
  {
    if (DAT_00a140bc == DAT_0084b3b0) {
      iVar2 = FUN_00550060();
      if ((DAT_00a1fb84 - iVar2) / 1000 != DAT_00a1fb88) {
        iVar2 = FUN_00550060();
        DAT_00a1fb88 = (DAT_00a1fb84 - iVar2) / 1000;
        basic_string<>();
        pcVar3 = (char *)FUN_00401c50();
        _sprintf(local_220,pcVar3);
        thunk_FUN_00511800();
      }
      if (0 < DAT_00a1fb88) {
        _DAT_00a1fb80 = DAT_00a1fb7c;
        DAT_00a1fb7c = DAT_00a1fb78;
        DAT_00a1fb78 = DAT_00a1fb74;
        DAT_00a1fb74 = FUN_00550060();
        iVar2 = FUN_00550060();
        iVar2 = (iVar2 - _DAT_00a1fb80) + (iVar2 - _DAT_00a1fb80 >> 0x1f & 3U);
        iVar2 = (int)(CONCAT44(iVar2 >> 0x1f,iVar2 >> 2) / 5);
        goto LAB_004361b6;
      }
      if (-1 < DAT_00a1fb88) {
        DAT_0084b3b0 = -1;
      }
    }
    else {
      DAT_00a1fb84 = FUN_00550060();
      DAT_00a1fb88 = -1;
    }
  }
  else if (DAT_00a1fb88 != 0) {
    DAT_00a1fb88 = 0;
    DAT_0084b3b0 = -1;
  }
  iVar2 = FUN_00550060();
  if (999 < iVar2 - _DAT_00a1fb90) {
    DAT_00a1fb70 = DAT_00a1fb8c;
    DAT_00a1fb8c = 0;
    _DAT_00a1fb90 = FUN_00550060();
  }
  if (DAT_00a117ac != '\0') {
    FUN_00543f70();
    FUN_00540490();
  }
  FUN_0054f460();
  if (((DAT_00a140bc == 0) && (DAT_0084b3b0 != 0)) || (DAT_00a140bc == -10)) {
    if (DAT_00a14360 == 1) {
      FUN_004cbb30();
      FUN_004cbb30();
      basic_string<>();
      pcVar3 = (char *)FUN_00401c50();
      _sprintf(local_120,pcVar3);
    }
    else {
      FUN_004cbb30();
      FUN_004cbb30();
      basic_string<>();
      pcVar3 = (char *)FUN_00401c50();
      _sprintf(local_120,pcVar3);
    }
    thunk_FUN_00511800();
    DAT_00a140bc = 0;
  }
  else if ((DAT_00a140bc == 1) || (DAT_00a140bc == -0xb)) {
    if (DAT_00a117a8 == 0) {
      local_254 = FUN_0042f5b0();
      if (((DAT_00a140bc != DAT_0084b3b0) || (DAT_00a1fb70 != DAT_0084b3ac)) ||
         ((local_254 != DAT_0084b3a8 || (DAT_0084b3a4 != DAT_00a18a8c)))) {
        if (DAT_00a14360 == 1) {
          if (DAT_00a18a8c == 0) {
            basic_string<>();
            FUN_00401c50();
          }
          else if (DAT_00a18a8c == 1) {
            basic_string<>();
            FUN_00401c50();
          }
          else {
            basic_string<>();
            FUN_00401c50();
          }
          basic_string<>();
          pcVar3 = (char *)FUN_00401c50();
          _sprintf(local_120,pcVar3);
        }
        else {
          if (DAT_00a18a8c == 0) {
            basic_string<>();
            FUN_00401c50();
          }
          else if (DAT_00a18a8c == 1) {
            basic_string<>();
            FUN_00401c50();
          }
          else {
            basic_string<>();
            FUN_00401c50();
          }
          basic_string<>();
          pcVar3 = (char *)FUN_00401c50();
          _sprintf(local_120,pcVar3);
        }
        thunk_FUN_00511800();
        DAT_0084b3ac = DAT_00a1fb70;
        DAT_0084b3a8 = local_254;
        DAT_0084b3a4 = DAT_00a18a8c;
      }
    }
    else {
      DAT_00a140bc = 1;
      DAT_00a1fb68 = DAT_00a1fb68 + _DAT_00a140c8;
      if (DAT_00a1fb8c % 5 == 0) {
        basic_string<>();
        local_8 = 1;
        local_244 = 0;
        for (local_24c = 0; local_24c < 5; local_24c = local_24c + 1) {
          if (*(int *)(&DAT_00a140d0 + local_24c * 4) < local_244) {
            local_5c8 = local_244;
          }
          else {
            local_5c8 = *(int *)(&DAT_00a140d0 + local_24c * 4);
          }
          local_244 = local_5c8;
        }
        local_224 = 0;
        _sprintf(local_120,"%d");
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_240,local_120);
        local_250 = 0;
        while ((local_250 < local_244 && (local_224 < 0x15))) {
          if (local_250 < 0x1a) {
            if (local_250 < 10) {
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                        (local_240,"|");
              local_224 = local_224 + 1;
            }
            else if (local_250 % 3 == 0) {
              basic_string<>();
              pcVar3 = (char *)FUN_00401c50();
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                        (local_240,pcVar3);
              local_224 = local_224 + 1;
            }
          }
          else if (local_250 % 5 == 0) {
            basic_string<>();
            pcVar3 = (char *)FUN_00401c50();
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                      (local_240,pcVar3);
            local_224 = local_224 + 1;
          }
          local_250 = local_250 + 1;
        }
        local_248 = 1;
        if (DAT_0084b248 == 2) {
          local_248 = 2;
        }
        FUN_004cbb30();
        FUN_00515710();
        FUN_0042f5b0();
        __allrem();
        __alldiv();
        __alldiv();
        basic_string<>(&DAT_007cdff8);
        pcVar3 = (char *)FUN_00401c50();
        _sprintf(local_120,pcVar3);
        DAT_00a1fb68 = 0;
        thunk_FUN_00511800();
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_240);
      }
    }
  }
  if ((DAT_00a117a8 != 0) && (DAT_00a14682 != '\0')) {
    FUN_005161e0();
    FUN_005160d0();
    FUN_00543f70();
    FUN_00526390();
    FUN_005160d0();
    if (DAT_0084b3a0 != '\0') {
      FUN_00536af0();
      FUN_00536900();
    }
    local_260 = 0;
    local_25c = 0;
    FUN_004760c0();
    FUN_00515710();
    FUN_004cc430();
    FUN_004d3180();
    basic_string<>();
    FUN_00401c50();
    FUN_00543f70();
    FUN_00540490();
    local_260 = local_260 + 0x16;
    local_25c = 0;
    basic_string<>();
    FUN_00401c50();
    FUN_00543f70();
    FUN_00540490();
    local_25c = local_25c + 0x78;
    local_394 = 0;
    while (iVar2 = FUN_004d2d60(), local_394 < iVar2) {
      FUN_004d2dc0();
      cVar1 = FUN_004d2230();
      if (cVar1 == '\0') {
        FUN_004d2dc0();
        FUN_00543f70();
        FUN_00540490();
        local_25c = local_25c + 0x28;
      }
      if (600 < local_25c) {
        local_260 = local_260 + 0xc;
        local_25c = 0;
      }
      local_394 = local_394 + 1;
    }
    local_260 = local_260 + 0xf;
    basic_string<>();
    FUN_00401c50();
    FUN_00543f70();
    FUN_00540490();
    local_374 = &DAT_00a1817c;
    basic_string<>();
    local_8 = 2;
    local_25c = 0x78;
    local_370 = 0;
    local_36c = 0;
    if (*(int *)(local_374 + 0x808) != 0) {
      while( true ) {
        local_36c = 0;
        iVar2 = FUN_004d21f0();
        if (iVar2 != 0) {
          local_36c = 1;
        }
        if (*(int *)(local_374 + 0x18) != -1) {
          FUN_0041b5f0();
        }
        if (*(int *)(local_374 + 0x18) != -1) {
          basic_string<>();
          FUN_00401c50();
        }
        if (*(int *)(local_374 + 0x14) != -1) {
          FUN_0041b5f0();
        }
        basic_string<>();
        pcVar3 = (char *)FUN_00401c50();
        _sprintf(local_120,pcVar3);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_390,local_120);
        iVar2 = FUN_004d21f0();
        if (iVar2 == 0) break;
        local_374 = (undefined *)FUN_004d2250();
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_390," -> ");
        local_370 = local_370 + 1;
        if (3 < local_370) {
          FUN_004cbb30();
          FUN_00543f70();
          FUN_00540490();
          local_25c = 10;
          local_260 = local_260 + 0xc;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    (local_390,"");
          local_370 = 0;
        }
      }
    }
    FUN_004cbb30();
    FUN_00543f70();
    FUN_00540490();
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
               local_390);
    local_260 = local_260 + 0x16;
    basic_string<>();
    FUN_00401c50();
    FUN_00543f70();
    FUN_00540490();
    local_260 = local_260 + 0xc;
    local_398 = 0;
    while (iVar2 = FUN_004cc430(), local_398 < iVar2) {
      pbVar4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004cc4c0();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_3b4,pbVar4);
      local_8 = 3;
      FUN_004cbb30();
      FUN_00543f70();
      FUN_00540490();
      local_260 = local_260 + 0xc;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_3b4);
      local_398 = local_398 + 1;
    }
    local_260 = local_260 + 0xc;
    basic_string<>();
    FUN_00401c50();
    FUN_00543f70();
    FUN_00540490();
    local_260 = local_260 + 0xc;
    local_264 = 0;
    for (local_3b8 = 0; local_3b8 < 3; local_3b8 = local_3b8 + 1) {
      for (local_3bc = 0; local_3bc < (int)(&DAT_00a14328)[local_3b8]; local_3bc = local_3bc + 1) {
        piVar5 = (int *)FUN_004cc020();
        local_3c0 = *piVar5;
        if (local_3c0 != 0) {
          FUN_0046ff30();
          local_8 = 4;
          FUN_004cbb30();
          FUN_00543f70();
          FUN_00540490();
          local_260 = local_260 + 0xc;
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3dc);
        }
      }
    }
    local_3e0 = 0;
    for (local_3e4 = 0; local_3e4 < 2; local_3e4 = local_3e4 + 1) {
      FUN_004cc870();
      while( true ) {
        FUN_004ce060();
        cVar1 = const_iterator__operator__();
        if (cVar1 == '\0') break;
        FUN_004d07e0();
        FUN_004cbb30();
        FUN_00543f70();
        FUN_00540490();
        local_260 = local_260 + 0xc;
        FUN_004e9550();
      }
    }
    local_260 = 0x3e;
    basic_string<>();
    FUN_00401c50();
    FUN_00543f70();
    FUN_00540490();
    local_260 = 0x4c;
    FUN_004cc870();
    while( true ) {
      FUN_004ce060();
      cVar1 = const_iterator__operator__();
      if (cVar1 == '\0') break;
      pbVar4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004df340();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_404,pbVar4);
      local_8 = 5;
      FUN_004cbb30();
      FUN_00543f70();
      FUN_00540490();
      FUN_004e9530();
      local_260 = local_260 + 0xc;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_404);
    }
    local_25c = 0;
    FUN_005160d0();
    FUN_00543f70();
    FUN_00526390();
    FUN_005160d0();
    local_260 = 0x142;
    for (local_408 = 0; iVar2 = FUN_004d3180(), local_408 < iVar2; local_408 = local_408 + 1) {
      FUN_004d31e0();
      FUN_00543f70();
      FUN_00540490();
      local_25c = local_25c + 0x3c;
      if ((local_408 != 0) && (local_408 % 10 == 0)) {
        local_260 = local_260 + 0xc;
        local_25c = 0;
      }
    }
    GetCurrentDirectoryA(0x100,local_368);
    if ((DAT_00a1fb94 & 2) == 0) {
      DAT_00a1fb94 = DAT_00a1fb94 | 2;
      local_8 = 6;
      basic_string<>();
      _atexit(FUN_007b3420);
      local_8 = 0xffffffff;
    }
    cVar1 = FUN_004cbb70();
    if (cVar1 == '\0') {
      pcVar3 = (char *)FUN_004cbb30();
      _strcmp(local_368,pcVar3);
    }
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a1fb4c,
               local_368);
  }
  DAT_0084b3b0 = DAT_00a140bc;
  _DAT_00a18a40 = DAT_00a1fb70;
  _DAT_00a1fb80 = DAT_00a1fb7c;
  DAT_00a1fb7c = DAT_00a1fb78;
  DAT_00a1fb78 = DAT_00a1fb74;
  DAT_00a1fb74 = FUN_00550060();
  iVar2 = FUN_00550060();
  iVar2 = (iVar2 - _DAT_00a1fb80) + (iVar2 - _DAT_00a1fb80 >> 0x1f & 3U);
  iVar2 = (int)(CONCAT44(iVar2 >> 0x1f,iVar2 >> 2) / 5);
LAB_004361b6:
  ExceptionList = local_10;
  return iVar2 * 5 + 5;
}

