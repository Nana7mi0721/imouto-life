
basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_004297d0(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_64 [12];
  undefined4 uStack_58;
  int iStack_54;
  undefined *puStack_50;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_38 [28];
  undefined1 *local_1c;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_007acc1f;
  local_10 = ExceptionList;
  local_8 = 1;
  local_18 = 0;
  ExceptionList = &local_10;
  local_14 = FUN_004e5650();
  local_1c = abStack_64;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (abStack_64,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &param_2);
  FUN_004293c0(local_38);
  local_8._0_1_ = 2;
  puStack_50 = (undefined *)0x429844;
  FUN_004cb840();
  local_8 = CONCAT31(local_8._1_3_,1);
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_38);
  while( true ) {
    puStack_50 = &DAT_007cd2cc;
    iStack_54 = 0x42985f;
    local_18 = FUN_004cbbc0();
    if (local_18 == DAT_007d0624) break;
    puStack_50 = (undefined *)0x1;
    uStack_58 = 0x429880;
    iStack_54 = local_18;
    FUN_004cba30();
  }
  puStack_50 = (undefined *)0x42988e;
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

