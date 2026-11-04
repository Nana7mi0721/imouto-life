
basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_004ec910(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2,
            char *param_3)

{
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *this;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [28];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1b11;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
         std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
         basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_2c,param_2);
  local_8 = 1;
  pbVar1 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                     (this,param_3);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,pbVar1);
  local_8 = local_8 & 0xffffff00;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_2c);
  ExceptionList = local_10;
  return param_1;
}

