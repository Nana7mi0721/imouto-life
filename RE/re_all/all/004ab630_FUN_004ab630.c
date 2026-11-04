
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FUN_004ab630(void)

{
  undefined4 extraout_var;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_38 [28];
  undefined4 local_1c;
  short local_18 [2];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007afdf8;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_38,DAT_00a16734);
  local_8 = 0;
  local_18[0] = FUN_004e5650(extraout_var);
  local_18[0] = local_18[0] + 1;
  local_14 = (void *)FUN_004cbb30();
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_18,2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = (size_t)local_18[0];
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),local_14,DAT_00a0f844);
  }
  else {
    DAT_00a0f844 = (size_t)local_18[0];
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  DAT_00a0f84c = 0x80;
  if (DAT_00a117e8 == 0) {
    DAT_00a0f844 = 2;
    _memcpy((void *)(DAT_00a0f824 + DAT_00a0f820),&DAT_00a0f84c,2);
  }
  else {
    DAT_00a0f844 = 2;
  }
  DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_38);
  ExceptionList = local_10;
  return 1;
}

