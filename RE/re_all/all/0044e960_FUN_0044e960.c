
void __fastcall FUN_0044e960(int param_1)

{
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_38 [20];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007ad8f8;
  local_10 = ExceptionList;
  local_8 = 5;
  ExceptionList = &local_10;
  local_18 = param_1;
  if (*(int *)(param_1 + 0x85c) != 0) {
    DAT_00a14314 = 0;
    uStack_20 = *(undefined4 *)(param_1 + 0x85c);
    uStack_24 = 0x44e9aa;
    ExceptionList = &local_10;
    FUN_00564510();
    DAT_00a18ad0 = 0xffffffff;
    local_14 = abStack_38;
    local_1c = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
               basic_string<char,std::char_traits<char>,std::allocator<char>_>
                         (abStack_38,
                          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)(local_18 + 0x864));
    FUN_00486bf0(*(undefined4 *)(local_18 + 0x860));
  }
  local_8._0_1_ = 4;
  uStack_20 = 0x44e9f4;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (local_18 + 0x864));
  local_8._0_1_ = 3;
  uStack_20 = 0x44ea06;
  FUN_004ce950();
  local_8._0_1_ = 2;
  uStack_20 = 0x44ea18;
  FUN_004ce950();
  local_8._0_1_ = 1;
  uStack_20 = 0x44ea2a;
  FUN_004cfbf0();
  local_8 = (uint)local_8._1_3_ << 8;
  uStack_20 = 0x44ea3c;
  FUN_004cee50();
  local_8 = 0xffffffff;
  uStack_20 = 0x44ea4e;
  FUN_004d2300();
  ExceptionList = local_10;
  return;
}

