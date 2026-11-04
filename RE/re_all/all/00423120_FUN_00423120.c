
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00423120(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_1)

{
  char cVar1;
  char *_Format;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  char in_stack_0000002c;
  undefined4 local_16c;
  undefined4 local_154;
  int local_150;
  int local_14c;
  char local_140 [256];
  void *local_40;
  undefined4 local_3c;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_38 [28];
  undefined4 local_1c;
  size_t local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007ac3a9;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  local_8 = 0;
  ExceptionList = &local_10;
  cVar1 = FUN_004ec750();
  if (cVar1 == '\0') {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (local_38,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                         *)&DAT_00a14c70);
    local_8._0_1_ = 1;
    FUN_004cb880();
    FUN_004cbb30();
    local_14 = FUN_0052e3c0();
    if (local_14 == 0) {
      if (in_stack_0000002c == '\0') {
        FUN_004cbb30();
        basic_string<>();
        _Format = (char *)FUN_00401c50();
        _sprintf(local_140,_Format);
        cVar1 = operator!=<>();
        if (cVar1 != '\0') {
          basic_string<>();
          local_8._0_1_ = 2;
          basic_string<>();
          FUN_00401c50();
          basic_string<>();
          local_8._0_1_ = 3;
          basic_string<>(local_140);
          local_8._0_1_ = 1;
          FUN_0042bed0();
        }
      }
      thunk_FUN_00580b80();
      local_16c = 0xffffffff;
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_38);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
      local_154 = local_16c;
    }
    else {
      FUN_004cbb30();
      local_18 = FUN_0052c9a0();
      local_40 = _malloc(local_18);
      FUN_0052cde0();
      thunk_FUN_00580b80();
      local_3c = FUN_0052a200();
      _free(local_40);
      if ((in_stack_00000028 != 0) && ((1 < in_stack_00000020 || (1 < in_stack_00000024)))) {
        FUN_00515880();
        FUN_004ce950();
        FUN_004ce160();
        for (local_14c = 0; local_14c < in_stack_00000024; local_14c = local_14c + 1) {
          for (local_150 = 0; local_150 < in_stack_00000020; local_150 = local_150 + 1) {
            FUN_0052a120();
            FUN_004ce160();
          }
        }
      }
      local_154 = local_3c;
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_38);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
    }
  }
  else {
    local_154 = 0xffffffff;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
  }
  ExceptionList = local_10;
  return local_154;
}

