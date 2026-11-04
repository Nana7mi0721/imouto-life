
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_004b3280(int param_1,int param_2,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_3)

{
  char cVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_170 [8];
  undefined4 uStack_168;
  undefined4 local_144;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  char local_130 [256];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007b0290;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  local_8 = 0;
  if (param_1 < 0) {
    local_134 = 0;
    local_8 = 0xffffffff;
    ExceptionList = &local_10;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
  }
  else if ((param_2 < 1100000) || (1199999 < param_2)) {
    if ((param_2 < 1600000) || (1699999 < param_2)) {
      ExceptionList = &local_10;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (abStack_170,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &param_3);
      cVar1 = FUN_004ab7b0(param_1,0,0);
      if (cVar1 == '\0') {
        local_144 = 0;
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
        local_134 = local_144;
      }
      else {
        if (param_1 < 1) {
          if (param_1 == 0) {
            FUN_004cbb30();
            _sprintf(local_130,"%s");
          }
        }
        else {
          FUN_004cbb30();
          uStack_168 = 0x4b33cf;
          _sprintf(local_130,"%s%.2i.sav");
        }
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  (local_30,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                             *)&DAT_00a14b78);
        local_8._0_1_ = 1;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_30,local_130);
        FUN_004d3570();
        uStack_168 = 0x4b3447;
        FUN_004d3570();
        local_134 = FUN_0043b320();
        local_8 = (uint)local_8._1_3_ << 8;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_30);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
      }
    }
    else {
      local_13c = 0;
      local_8 = 0xffffffff;
      ExceptionList = &local_10;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
      local_134 = local_13c;
    }
  }
  else {
    local_138 = 0;
    local_8 = 0xffffffff;
    ExceptionList = &local_10;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
    local_134 = local_138;
  }
  ExceptionList = local_10;
  return local_134;
}

