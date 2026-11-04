
basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_0041b6f0(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> bStack00000024;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> bStack00000040;
  undefined4 uVar4;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007abdbc;
  local_10 = ExceptionList;
  uVar4 = 0;
  local_8 = 3;
  local_14 = 0;
  ExceptionList = &local_10;
  while( true ) {
    iVar1 = AddRequestHeaders(&bStack00000024,local_14);
    if (iVar1 == -1) break;
    uVar2 = FUN_004cbb30(uVar4);
    uVar3 = FUN_004e5650(uVar2);
    FUN_004cba30(iVar1,uVar3,uVar2);
    local_14 = FUN_004e5650();
    local_14 = local_14 + iVar1;
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )&param_2);
  local_8._0_1_ = 2;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  local_8._0_1_ = 1;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000024);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000040);
  ExceptionList = local_10;
  return param_1;
}

