
basic_string<char,std::char_traits<char>,std::allocator<char>_> * __fastcall
FUN_004ad7e0(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1)

{
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_64 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_48 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2c [28];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b001e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  basic_string<>();
  local_8._0_1_ = 1;
  FUN_004cc150();
  local_8._0_1_ = 2;
  FUN_004cc150();
  local_8._0_1_ = 3;
  FUN_004cf7a0();
  local_8._0_1_ = 4;
  FUN_004cc150();
  local_8._0_1_ = 5;
  FUN_004cd090();
  local_8._0_1_ = 6;
  FUN_004cd090();
  local_8._0_1_ = 7;
  FUN_004ce850();
  local_8._0_1_ = 8;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(param_1,"");
  basic_string<>(&DAT_007d0621);
  local_8._0_1_ = 9;
  FUN_004cc500(local_2c);
  local_8._0_1_ = 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2c);
  FUN_004cde50(1);
  FUN_004cd310(1);
  basic_string<>(&DAT_007d0621);
  local_8._0_1_ = 10;
  FUN_004cc500(local_48);
  local_8._0_1_ = 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_48);
  basic_string<>(&DAT_007d0621);
  local_8._0_1_ = 0xb;
  FUN_004cc500(local_64);
  local_8 = CONCAT31(local_8._1_3_,8);
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_64);
  FUN_004ce970(1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(param_1 + 0x1c,"")
  ;
  FUN_004cf7d0(100);
  ExceptionList = local_10;
  return param_1;
}

