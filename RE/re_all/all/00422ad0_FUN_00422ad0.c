
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_00422ad0(int param_1)

{
  char cVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;
  char *_Format;
  int iVar3;
  int *piVar4;
  int local_1a8;
  int local_1a4;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_198 [28];
  int local_17c;
  int local_164;
  char local_160 [256];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_60 [28];
  void *local_44;
  undefined4 local_40;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3c [28];
  undefined4 local_20;
  size_t local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ac379;
  local_10 = ExceptionList;
  local_20 = DAT_0084b484;
  ExceptionList = &local_10;
  FUN_004cc870();
  while( true ) {
    while( true ) {
      FUN_004ce060();
      cVar1 = const_iterator__operator__();
      if (cVar1 == '\0') {
        ExceptionList = local_10;
        return 1;
      }
      pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004df340();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_60,pbVar2);
      local_8 = 0;
      FUN_004e9530();
      cVar1 = FUN_004ec750();
      if (cVar1 == '\0') break;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_60);
    }
    FUN_004ec790();
    local_8._0_1_ = 1;
    FUN_004cbb30();
    local_18 = FUN_0052e3c0();
    if (local_18 == 0) break;
    if (param_1 == 1) {
      local_164 = 0;
      while( true ) {
        FUN_004cc680();
        FUN_004cde80();
        iVar3 = FUN_004ce080();
        if (iVar3 <= local_164) break;
        FUN_004cc680();
        FUN_004cde80();
        FUN_004ce990();
        FUN_00515700();
        local_164 = local_164 + 1;
      }
      FUN_004cc680();
      FUN_004cde80();
      FUN_004ce950();
    }
    FUN_004cbb30();
    local_1c = FUN_0052c9a0();
    local_44 = _malloc(local_1c);
    FUN_0052cde0();
    thunk_FUN_00580b80();
    FUN_004cb840();
    if (param_1 == 0) {
      FUN_004cc680();
      FUN_004cde80();
      FUN_004ce990();
      FUN_0052a260();
    }
    else if (param_1 == 1) {
      local_40 = FUN_0052a200();
      FUN_004cb840();
      FUN_00515880();
      FUN_004cc680();
      piVar4 = (int *)FUN_004ce990();
      iVar3 = *piVar4;
      FUN_004cc680();
      piVar4 = (int *)FUN_004ce990();
      local_17c = *piVar4;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (local_198,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_3c);
      local_8._0_1_ = 4;
      FUN_004ce850();
      local_8 = CONCAT31(local_8._1_3_,5);
      FUN_004cc680();
      FUN_004cde80();
      FUN_004ce160();
      for (local_1a4 = 0; local_1a4 < local_17c; local_1a4 = local_1a4 + 1) {
        for (local_1a8 = 0; local_1a8 < iVar3; local_1a8 = local_1a8 + 1) {
          FUN_0052a120();
          FUN_004cc680();
          FUN_004cd3a0();
          FUN_004ce160();
        }
      }
      local_8._0_1_ = 4;
      FUN_004ce950();
      local_8._0_1_ = 1;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_198);
    }
    _free(local_44);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3c);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_60
              );
  }
  FUN_004cbb30();
  FUN_004cbb30();
  basic_string<>();
  _Format = (char *)FUN_00401c50();
  _sprintf(local_160,_Format);
  cVar1 = operator!=<>();
  if (cVar1 != '\0') {
    basic_string<>();
    local_8._0_1_ = 2;
    basic_string<>();
    FUN_00401c50();
    basic_string<>();
    local_8._0_1_ = 3;
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
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_60);
  ExceptionList = local_10;
  return 0;
}

