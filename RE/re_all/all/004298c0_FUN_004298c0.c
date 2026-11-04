
basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_004298c0(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_007acc4a;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  while (iVar1 = FUN_004cbbc0(&DAT_007cd2d4,0), iVar1 != DAT_007d0624) {
    FUN_004cba30(iVar1,1,&DAT_007cd2d8);
  }
  while (iVar1 = FUN_004cbbc0(&DAT_007cd2dc,0), iVar1 != DAT_007d0624) {
    FUN_004cba30(iVar1,3,&DAT_007cd2e0);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )&param_2);
  local_8 = local_8 & 0xffffff00;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  ExceptionList = local_10;
  return param_1;
}

