
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0047f0ee) */
/* WARNING: Removing unreachable block (ram,0x0047f16a) */
/* WARNING: Removing unreachable block (ram,0x0047f173) */
/* WARNING: Removing unreachable block (ram,0x0047f182) */

undefined4
FUN_0047ecc0(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_1)

{
  LPCSTR lpCaption;
  LPCSTR lpText;
  int *piVar1;
  undefined4 uVar2;
  undefined1 uStack00000000;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_348 [12];
  undefined4 uStack_33c;
  undefined *puStack_338;
  undefined *puStack_334;
  char *pcStack_32c;
  undefined4 uStack_328;
  size_t sStack_324;
  UINT uType;
  undefined1 auStack_302 [670];
  int local_64;
  int local_60;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_58 [31];
  char local_39;
  char local_38;
  char local_37;
  char local_36;
  size_t local_34;
  undefined1 auStack_30 [12];
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007af34b;
  pvStack_10 = ExceptionList;
  local_24 = DAT_0084b484;
  local_14 = auStack_302 + -0xe;
  local_18 = 0;
  local_8 = 1;
  ExceptionList = &pvStack_10;
  FUN_004cbb30();
  basic_string<>();
  local_8._0_1_ = 2;
  FUN_004cb880();
  FUN_004cbb30();
  local_20 = FUN_0052e3c0();
  if (local_20 == 0) {
    uType = 0;
    puStack_334 = &DAT_007d0d98;
    puStack_338 = (undefined *)0x47ed89;
    basic_string<>();
    puStack_334 = (undefined *)0x47ed94;
    lpCaption = (LPCSTR)FUN_00401c50();
    puStack_338 = &DAT_007d0d68;
    uStack_33c = 0x47edb9;
    basic_string<>();
    puStack_338 = (undefined *)0x47edc4;
    lpText = (LPCSTR)FUN_00401c50();
    sStack_324 = 0x47eddc;
    MessageBoxA((HWND)0x0,lpText,lpCaption,uType);
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
  }
  else {
    FUN_004cbb30();
    local_34 = FUN_0052c9a0();
    DAT_00a11790 = 0;
    if (DAT_00a117ec == 0) {
      DAT_00a0f830 = _malloc(local_34);
      _memset(DAT_00a0f830,0,local_34);
    }
    FUN_0052cde0();
    thunk_FUN_00580b80();
    for (local_60 = 0; local_60 < 10; local_60 = local_60 + 1) {
      if (auStack_30 + local_60 == (undefined1 *)0x0) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 1;
        _memcpy(auStack_30 + local_60,DAT_00a0f830 + DAT_00a11790,1);
      }
      DAT_00a11790 = DAT_00a11790 + 1;
    }
    local_38 = *DAT_00a0f830;
    local_37 = DAT_00a0f830[3];
    local_36 = DAT_00a0f830[9];
    if ((((DAT_00a0f830[1] != 'W') || (DAT_00a0f830[4] != 'O')) || (DAT_00a0f830[5] != 'L')) ||
       ((DAT_00a0f830[7] != 'F' || (DAT_00a0f830[8] != 'C')))) {
      sStack_324 = local_34;
      uStack_328 = 10;
      pcStack_32c = DAT_00a0f830;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (abStack_348,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_58);
      FUN_0041b9e0();
    }
    if (&uStack00000000 == (undefined1 *)0x39) {
      __CxxThrowException_8();
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = 1;
      _memcpy(&local_39,DAT_00a0f830 + DAT_00a11790,1);
    }
    DAT_00a11790 = DAT_00a11790 + 1;
    if (local_39 == -0x71) {
      if (&uStack00000000 == (undefined1 *)0x1c) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 4;
        _memcpy(&local_1c,DAT_00a0f830 + DAT_00a11790,4);
      }
      DAT_00a11790 = DAT_00a11790 + 4;
      FUN_00480f20();
      for (local_64 = 0; local_64 < local_1c; local_64 = local_64 + 1) {
        local_18 = local_64;
        FUN_004cfb40();
        FUN_0047f3d0();
        piVar1 = (int *)FUN_004cfb40();
        *piVar1 = local_64;
      }
      if (&uStack00000000 == (undefined1 *)0x39) {
        __CxxThrowException_8();
      }
      if (DAT_00a117ec == 0) {
        DAT_00a1179c = 1;
        _memcpy(&local_39,DAT_00a0f830 + DAT_00a11790,1);
      }
      DAT_00a11790 = DAT_00a11790 + 1;
      if (local_39 == -0x71) {
        if (((local_38 != '\0') || (local_37 != '\0')) || (local_36 != '\0')) {
          uStack_328 = 10;
          pcStack_32c = DAT_00a0f830;
          sStack_324 = DAT_00a11790;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    (abStack_348,
                     (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )local_58);
          FUN_0041b9e0();
        }
        if (DAT_00a117ec == 0) {
          _free(DAT_00a0f830);
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58);
        uVar2 = FUN_0047f372();
        return uVar2;
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
    }
    else {
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
    }
  }
  ExceptionList = pvStack_10;
  return 0;
}

