
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 __fastcall FUN_004b2e70(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined1 local_67a;
  undefined1 local_679;
  undefined1 local_65f;
  undefined1 local_65e;
  undefined1 local_65d;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_65c [28];
  char local_640 [516];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_43c [28];
  char local_420 [516];
  short local_21c [2];
  char local_218 [516];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b026c;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  if (DAT_00a0f828 < DAT_00a0f820 + 2) {
    DAT_00a117e4 = 1;
    local_65d = 0;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_43c);
  }
  else {
    DAT_00a0f844 = 2;
    _memcpy(local_21c,(void *)(DAT_00a0f824 + DAT_00a0f820),2);
    DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
    if (DAT_00a0f828 < local_21c[0] + DAT_00a0f820) {
      DAT_00a117e4 = 1;
      local_65e = 0;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_43c);
      local_65d = local_65e;
    }
    else {
      DAT_00a0f844 = (size_t)local_21c[0];
      _memcpy(local_218,(void *)(DAT_00a0f824 + DAT_00a0f820),DAT_00a0f844);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      if (DAT_00a0f828 < DAT_00a0f820 + 2) {
        DAT_00a117e4 = 1;
        local_65f = 0;
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_43c);
        local_65d = local_65f;
      }
      else {
        DAT_00a0f844 = 2;
        _memcpy(&DAT_00a0f84c,(void *)(DAT_00a0f824 + DAT_00a0f820),2);
        DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_43c,
                   local_218);
        cVar1 = operator!=<>();
        if (cVar1 == '\0') {
          local_67a = 1;
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_43c);
          local_65d = local_67a;
        }
        else {
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    (local_65c,
                     (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )(param_1 + 0x2740));
          local_8 = CONCAT31(local_8._1_3_,1);
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    (local_65c,".anotherGame");
          while( true ) {
            FUN_004cbb30();
            FUN_004cbb30();
            iVar2 = FUN_004fd645();
            if (iVar2 == 0) break;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                      (local_65c,"x");
          }
          basic_string<>();
          pcVar3 = (char *)FUN_00401c50();
          _sprintf(local_218,pcVar3);
          FUN_004cbb30();
          basic_string<>();
          pcVar3 = (char *)FUN_00401c50();
          _sprintf(local_420,pcVar3);
          FUN_004cbb30();
          basic_string<>();
          pcVar3 = (char *)FUN_00401c50();
          _sprintf(local_640,pcVar3);
          basic_string<>();
          local_8._0_1_ = 2;
          basic_string<>();
          local_8._0_1_ = 3;
          basic_string<>(local_218);
          local_8._0_1_ = 1;
          FUN_0042bed0();
          local_679 = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_65c);
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_43c);
          local_65d = local_679;
        }
      }
    }
  }
  ExceptionList = local_10;
  return local_65d;
}

