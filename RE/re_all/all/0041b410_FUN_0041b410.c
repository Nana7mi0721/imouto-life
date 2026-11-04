
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041b410(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_1)

{
  DWORD DVar1;
  char *pcVar2;
  int local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007abd6f;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_004cb880(&param_1);
  DVar1 = timeGetTime();
  pcVar2 = (char *)FUN_0041b5f0(DVar1 - _DAT_00a192f4);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a164c4,pcVar2
            );
  *(DWORD *)(&DAT_00a192c8 + DAT_00a192f0 * 4) = DVar1 - _DAT_00a192f4;
  DAT_00a192f0 = (DAT_00a192f0 + 1) % 10;
  local_18 = 0;
  for (local_1c = 0; local_1c < 10; local_1c = local_1c + 1) {
    local_18 = local_18 + *(int *)(&DAT_00a192c8 + local_1c * 4);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a164c4,
             "\r\n[");
  pcVar2 = (char *)FUN_0041b5f0(local_18);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a164c4,pcVar2
            );
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a164c4,"]");
  _DAT_00a192f4 = DVar1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a164c4,"\r\n"
            );
  FUN_004177c0();
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
  ExceptionList = local_10;
  return;
}

