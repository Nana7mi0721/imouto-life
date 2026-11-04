
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_00471030(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,int param_2,
            int param_3)

{
  int iVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar2;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae941;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  ExceptionList = &local_10;
  if (((-1 < param_2) && (ExceptionList = &local_10, -1 < param_3)) &&
     (ExceptionList = &local_10, iVar1 = FUN_004d0530(), param_2 < iVar1)) {
    FUN_004d05c0();
    iVar1 = FUN_004cc430();
    if (param_3 < iVar1) {
      FUN_004d05c0();
      pbVar2 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004cc4c0();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_30,pbVar2);
      local_8 = 1;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          *)local_30);
      local_8 = local_8 & 0xffffff00;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_30);
      ExceptionList = local_10;
      return param_1;
    }
  }
  basic_string<>(&DAT_007d0744);
  FUN_00401c50();
  basic_string<>();
  ExceptionList = local_10;
  return param_1;
}

