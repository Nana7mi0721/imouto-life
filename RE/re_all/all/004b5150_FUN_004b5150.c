
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_004b5150(undefined4 param_1,int param_2,int param_3,undefined4 param_4,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_5)

{
  char cVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_16c [4];
  undefined4 uStack_168;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbStack_164;
  char local_130 [256];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_007b050f;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  local_8 = 1;
  if (param_2 < 0) {
    ExceptionList = &local_10;
    basic_string<>(&DAT_007d16c4);
    FUN_00401c50();
    basic_string<>();
    local_8 = local_8 & 0xffffff00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_5);
  }
  else if ((param_3 < 1600000) || (1699999 < param_3)) {
    ExceptionList = &local_10;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (abStack_16c,
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &param_5);
    cVar1 = FUN_004ab7b0(param_2,0,0);
    if (cVar1 == '\0') {
      basic_string<>();
      local_8 = local_8 & 0xffffff00;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_5);
    }
    else {
      if (param_2 < 1) {
        if (param_2 == 0) {
          FUN_004cbb30();
          _sprintf(local_130,"%s");
        }
      }
      else {
        FUN_004cbb30();
        pbStack_164 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x4b52c2;
        _sprintf(local_130,"%s%.2i.sav");
      }
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (local_30,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)&DAT_00a14b78);
      local_8._0_1_ = 2;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (local_30,local_130);
      FUN_004d3570();
      pbStack_164 = local_30;
      uStack_168 = 0x4b5340;
      FUN_004d3570();
      pbStack_164 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x4b534c;
      FUN_0043be80();
      local_8._0_1_ = 1;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_30);
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_5);
    }
  }
  else {
    ExceptionList = &local_10;
    basic_string<>();
    local_8 = local_8 & 0xffffff00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_5);
  }
  ExceptionList = local_10;
  return param_1;
}

