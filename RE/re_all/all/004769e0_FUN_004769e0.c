
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004769e0(int param_1)

{
  char cVar1;
  int iVar2;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;
  char *pcVar4;
  size_t *psVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined *puStack_230;
  undefined1 *puStack_22c;
  void *pvStack_228;
  void *pvStack_224;
  void *pvStack_220;
  int iStack_21c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1a8 [28];
  undefined4 local_18c;
  undefined4 local_188;
  int local_184;
  int local_180;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  int local_16c;
  int local_168;
  int local_164;
  char local_160 [260];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_5c [28];
  void *local_40;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3c [28];
  undefined4 local_20;
  void *local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aeec7;
  local_10 = ExceptionList;
  local_20 = DAT_0084b484;
  local_14 = 0;
  ExceptionList = &local_10;
  while( true ) {
    iVar2 = FUN_004cc430();
    if (iVar2 <= local_14) {
      if (param_1 == 1) {
        local_184 = 0;
        while (iVar2 = FUN_004d3180(), local_184 < iVar2) {
          FUN_004d31e0();
          cVar1 = operator!=<>();
          if (cVar1 != '\0') {
            FUN_004d31e0();
            pcVar4 = (char *)FUN_004cbb30();
            if (*pcVar4 != '<') {
              iVar2 = FUN_004d31e0();
              if (*(char *)(iVar2 + 0x265) == '\0') {
                FUN_004d31e0();
                FUN_004d31e0();
                iStack_21c = 0x4770ca;
                iVar2 = FUN_004d31e0();
                std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                basic_string<char,std::char_traits<char>,std::allocator<char>_>
                          ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                           &puStack_230,
                           (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                            *)(iVar2 + 0x16c));
                local_8 = 6;
                FUN_004d31e0();
                local_8 = 0xffffffff;
                FUN_00477140();
              }
              else {
                iVar2 = FUN_004d31e0();
                local_188 = *(undefined4 *)(iVar2 + 0x270);
                iVar2 = FUN_004d31e0();
                local_18c = *(undefined4 *)(iVar2 + 0x274);
                iStack_21c = 0x476ff6;
                iVar2 = FUN_004d31e0();
                std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                basic_string<char,std::char_traits<char>,std::allocator<char>_>
                          ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                           &puStack_230,
                           (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                            *)(iVar2 + 0x16c));
                local_8 = 5;
                FUN_004d31e0();
                local_8 = 0xffffffff;
                FUN_00477140();
                iVar2 = FUN_004d31e0();
                *(undefined4 *)(iVar2 + 0x270) = local_188;
                iVar2 = FUN_004d31e0();
                *(undefined4 *)(iVar2 + 0x274) = local_18c;
              }
            }
          }
          local_184 = local_184 + 1;
        }
      }
      ExceptionList = local_10;
      return;
    }
    pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             FUN_004cc4c0();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_5c,pbVar3);
    local_8 = 0;
    basic_string<>();
    local_8._0_1_ = 1;
    iStack_21c = 0x476a7e;
    FUN_004ec790();
    local_8._0_1_ = 2;
    FUN_004cb840();
    local_8._0_1_ = 1;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1a8);
    FUN_004cbb30();
    local_18 = FUN_0052e3c0();
    if (local_18 == 0) break;
    FUN_004cbb30();
    local_1c = (void *)FUN_0052c9a0();
    local_40 = _malloc((size_t)local_1c);
    iStack_21c = 0x476c53;
    FUN_0052cde0();
    thunk_FUN_00580b80();
    if (param_1 == 0) {
      iStack_21c = 0;
      pvStack_220 = (void *)local_14;
      pvStack_224 = (void *)0x476c7e;
      psVar5 = (size_t *)FUN_004ce990();
      pvStack_220 = (void *)*psVar5;
      pvStack_224 = local_1c;
      pvStack_228 = local_40;
      puStack_22c = (undefined1 *)0x476c8e;
      FUN_0052a260();
    }
    else if (param_1 == 1) {
      local_164 = 0;
      while( true ) {
        FUN_004cde80();
        iVar2 = FUN_004ce080();
        if (iVar2 <= local_164) break;
        iStack_21c = 0x476cef;
        FUN_004cde80();
        FUN_004ce990();
        FUN_00515700();
        local_164 = local_164 + 1;
      }
      FUN_004ce990();
      FUN_00515700();
      iStack_21c = 0;
      pvStack_220 = local_1c;
      pvStack_224 = local_40;
      pvStack_228 = (void *)0x476d33;
      uVar6 = FUN_0052a200();
      puVar7 = (undefined4 *)FUN_004ce990();
      *puVar7 = uVar6;
    }
    piVar8 = (int *)FUN_004ce990();
    local_170 = *piVar8;
    piVar8 = (int *)FUN_004ce990();
    local_16c = *piVar8;
    local_178 = local_14;
    iStack_21c = 0x476da9;
    FUN_004ce990();
    iStack_21c = 0x476db1;
    FUN_00515880();
    if (param_1 == 1) {
      FUN_004cde80();
      FUN_004ce950();
      for (local_17c = 0; local_17c < local_16c; local_17c = local_17c + 1) {
        for (local_180 = 0; local_180 < local_170; local_180 = local_180 + 1) {
          FUN_004ce990();
          iStack_21c = (local_174 / local_16c) * local_17c;
          pvStack_220 = (void *)((local_168 / local_170) * local_180);
          pvStack_224 = (void *)0x476e8f;
          FUN_0052a120();
          FUN_004cde80();
          FUN_004ce160();
        }
      }
    }
    _free(local_40);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3c);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_5c
              );
    local_14 = local_14 + 1;
  }
  FUN_004cbb30();
  puStack_230 = &DAT_007d093c;
  basic_string<>();
  puStack_230 = (undefined *)0x476afe;
  pcVar4 = (char *)FUN_00401c50();
  iStack_21c = 0x476b1a;
  _sprintf(local_160,pcVar4);
  cVar1 = operator!=<>();
  if ((cVar1 != '\0') && (cVar1 = operator!=<>(), cVar1 != '\0')) {
    puStack_22c = &DAT_007d0621;
    puStack_230 = (undefined *)0x476b6a;
    basic_string<>();
    local_8._0_1_ = 3;
    basic_string<>();
    FUN_00401c50();
    basic_string<>();
    local_8._0_1_ = 4;
    basic_string<>(local_160);
    local_8._0_1_ = 1;
    FUN_0042bed0();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3c);
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_5c);
  ExceptionList = local_10;
  return;
}

