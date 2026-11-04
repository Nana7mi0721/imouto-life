
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00486bf0(int param_1,undefined *param_2,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_3)

{
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_40 [28];
  undefined4 uStack_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007af6d8;
  local_10 = ExceptionList;
  local_8 = 0;
  if (((int)param_2 < 1600000) || (1699999 < (int)param_2)) {
    if ((0x8c3a6f < (int)param_2) && ((int)param_2 < 9200000)) {
      param_2 = &DAT_008adae0 + (int)param_2 % 10 + *(int *)(param_1 + 0x14) * 10;
    }
  }
  else {
    param_2 = &DAT_00e4e1c0 + (int)param_2 % 100 + *(int *)(param_1 + 0x18) * 100;
  }
  _DAT_00a16444 = *(undefined4 *)(param_1 + 0x10);
  uStack_24 = 0;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (abStack_40,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &param_3);
  FUN_0043a2c0(param_2);
  local_8 = 0xffffffff;
  uStack_24 = 0x486cb7;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
  ExceptionList = local_10;
  return;
}

