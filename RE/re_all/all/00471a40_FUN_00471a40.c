
int __fastcall FUN_00471a40(int param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007aea5a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  _eh_vector_constructor_iterator_
            ((void *)(param_1 + 0x1c),0x1c,0x10,basic_string<>,
             std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>);
  local_8._0_1_ = 1;
  FUN_004cf7a0();
  local_8._0_1_ = 2;
  FUN_004ce850();
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004cf7d0(0x10);
  FUN_004ce970(0x10);
  for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
               (param_1 + 0x1c + local_14 * 0x1c),"");
    puVar1 = (undefined1 *)FUN_004cd7c0(local_14);
    *puVar1 = (undefined1)local_14;
    puVar2 = (undefined4 *)FUN_004ce990(local_14);
    *puVar2 = 0;
  }
  ExceptionList = local_10;
  return param_1;
}

