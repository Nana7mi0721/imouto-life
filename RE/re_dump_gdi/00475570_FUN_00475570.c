
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00475570(void)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  LPCSTR pCVar4;
  BOOL BVar5;
  long lVar6;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar7;
  undefined4 *puVar8;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_9b8 [20];
  undefined4 uStack_9a4;
  int iStack_9a0;
  undefined4 uStack_99c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_998;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_95c [28];
  long local_940;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_93c [28];
  long local_920;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_91c [28];
  int local_900;
  HANDLE local_8fc;
  CHAR local_8f8 [260];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_7f4 [28];
  _WIN32_FIND_DATAA local_7d8;
  char local_698 [512];
  int local_498;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_494 [1052];
  int local_78;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_74 [28];
  int local_58;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_54 [28];
  undefined4 local_38;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aedd7;
  local_10 = ExceptionList;
  local_38 = DAT_0084b484;
  ExceptionList = &local_10;
  FUN_00475c70();
  local_78 = 0;
  while (iVar1 = FUN_004ce080(), local_78 < iVar1) {
    piVar2 = (int *)FUN_004ce990();
    if (0 < *piVar2) {
      pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x475601;
      FUN_004ce990();
      pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x475609;
      FUN_00515700();
    }
    local_78 = local_78 + 1;
  }
  FUN_004ce950();
  FUN_004ce950();
  FUN_004ce970();
  FUN_004ce950();
  FUN_004ce970();
  FUN_004ce850();
  local_8 = 0;
  FUN_004ce950();
  FUN_004cc150();
  local_8._0_1_ = 1;
  FUN_004cc250();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_54,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)&DAT_00a14c70);
  local_8._0_1_ = 2;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_54,"BasicData\\");
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_74,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)local_54);
  local_8._0_1_ = 3;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_74,"EncodedIconList.xxxxx");
  FUN_004cbb30();
  pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                0x4756e3;
  local_14 = FUN_0052e3c0();
  if (local_14 == 0) {
    pCVar4 = (LPCSTR)FUN_004cbb30();
    SetCurrentDirectoryA(pCVar4);
    pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x47583f;
    GetCurrentDirectoryA(0x100,local_8f8);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_54,"");
    basic_string<>();
    local_8 = CONCAT31(local_8._1_3_,6);
    pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x475872;
    local_8fc = FindFirstFileA("icon???.png",&local_7d8);
    if (local_8fc != (HANDLE)0xffffffff) {
      do {
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_54,"BasicData\\");
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_54,local_7d8.cFileName);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_7f4,local_7d8.cFileName);
        pbStack_998 = local_93c;
        uStack_99c = 0x4758c9;
        FUN_004cbc20();
        local_8._0_1_ = 7;
        FUN_004cb840();
        local_8 = CONCAT31(local_8._1_3_,6);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_93c);
        FUN_004cc500();
        pcVar3 = (char *)FUN_004cbb30();
        local_940 = _atol(pcVar3);
        FUN_004ce160();
        pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x475949;
        BVar5 = FindNextFileA(local_8fc,&local_7d8);
      } while (BVar5 != 0);
      FindClose(local_8fc);
    }
    pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x475970;
    local_8fc = FindFirstFileA("icon????.png",&local_7d8);
    if (local_8fc != (HANDLE)0xffffffff) {
      do {
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_54,"BasicData\\");
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_54,local_7d8.cFileName);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_7f4,local_7d8.cFileName);
        pbStack_998 = local_95c;
        uStack_99c = 0x4759c7;
        FUN_004cbc20();
        local_8._0_1_ = 8;
        FUN_004cb840();
        local_8 = CONCAT31(local_8._1_3_,6);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_95c);
        pcVar3 = (char *)FUN_004cbb30();
        lVar6 = _atol(pcVar3);
        if (999 < lVar6) {
          FUN_004cc500();
          pcVar3 = (char *)FUN_004cbb30();
          _atol(pcVar3);
          FUN_004ce160();
        }
        pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x475a62;
        BVar5 = FindNextFileA(local_8fc,&local_7d8);
      } while (BVar5 != 0);
      FindClose(local_8fc);
    }
    pCVar4 = (LPCSTR)FUN_004cbb30();
    SetCurrentDirectoryA(pCVar4);
    local_8 = CONCAT31(local_8._1_3_,3);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
               local_7f4);
  }
  else {
    local_498 = 0;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_54,"");
    basic_string<>();
    local_8._0_1_ = 4;
    while( true ) {
      pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    local_698;
      uStack_99c = 0x475733;
      local_498 = FUN_0052e4f0();
      if (local_498 < 1) break;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (local_54,"BasicData\\");
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (local_54,local_698);
      FUN_004cc500();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (local_494,local_698);
      pbStack_998 = local_91c;
      uStack_99c = 0x475799;
      FUN_004cbc20();
      local_8._0_1_ = 5;
      FUN_004cb840();
      local_8._0_1_ = 4;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_91c);
      pcVar3 = (char *)FUN_004cbb30();
      local_920 = _atol(pcVar3);
      FUN_004ce160();
    }
    thunk_FUN_00580b80();
    local_8 = CONCAT31(local_8._1_3_,3);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
               local_494);
  }
  local_900 = 0;
  while (iVar1 = FUN_004cc430(), local_900 < iVar1) {
    piVar2 = (int *)FUN_004ce990();
    if (-1 < *piVar2) {
      pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0x1
      ;
      uStack_99c = 1;
      iStack_9a0 = local_900;
      uStack_9a4 = 0x475af3;
      pbVar7 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004cc4c0();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_9b8,pbVar7);
      local_58 = FUN_00423120();
      if (local_58 != -1) {
        piVar2 = (int *)FUN_004ce990();
        iVar1 = FUN_004ce080();
        if (iVar1 <= *piVar2) {
          FUN_004ce990();
          FUN_004ce970();
        }
        FUN_004ce990();
        piVar2 = (int *)FUN_004ce990();
        *piVar2 = local_58;
        FUN_004ce990();
        FUN_004ce990();
        pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x475bd2;
        FUN_004ce990();
        pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x475be6;
        FUN_004ce990();
        pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_900;
        uStack_99c = 0x475bf6;
        puVar8 = (undefined4 *)FUN_004ce990();
        pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      *puVar8;
        uStack_99c = 0x475c0a;
        piVar2 = (int *)FUN_004ce990();
        pbStack_998 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      *piVar2;
        uStack_99c = 0x475c12;
        FUN_00515880();
      }
    }
    local_900 = local_900 + 1;
  }
  local_8._0_1_ = 2;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_74);
  local_8._0_1_ = 1;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_54);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004cc250();
  local_8 = 0xffffffff;
  FUN_004ce950();
  ExceptionList = local_10;
  return;
}

