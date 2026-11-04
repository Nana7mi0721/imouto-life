
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_00476390(int param_1)

{
  int iVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_70 [20];
  undefined4 uStack_5c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int iStack_4c;
  int iStack_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  undefined1 *local_34;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0658;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  iStack_48 = 0;
  iStack_4c = *(undefined4 *)(param_1 + 600);
  uStack_50 = 0x4763c7;
  ExceptionList = &local_10;
  local_38 = param_1;
  FUN_00515700();
  *(undefined4 *)(local_38 + 0x250) = 0;
  *(undefined4 *)(local_38 + 0x270) = 0;
  *(undefined4 *)(local_38 + 0x274) = 0;
  *(undefined1 *)(local_38 + 0x254) = 0;
  *(undefined1 *)(local_38 + 0x255) = 0;
  *(undefined1 *)(local_38 + 0x256) = 0;
  *(undefined4 *)(local_38 + 0x25c) = 0;
  *(undefined4 *)(local_38 + 0x260) = 0;
  *(undefined4 *)(local_38 + 0x264) = 0;
  iStack_48 = 0;
  iStack_4c = 0;
  uStack_50 = 0;
  uStack_54 = 10;
  pbStack_58 = local_30;
  uStack_5c = 0x47644c;
  FUN_0046ff30();
  local_8 = 0;
  iStack_48 = 0;
  iStack_4c = 1;
  uStack_50 = 0;
  uStack_54 = 10;
  pbStack_58 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               0x476465;
  iVar1 = FUN_0046f7f0();
  if (iVar1 < 1) {
    local_3c = 1;
  }
  else {
    iStack_48 = 0;
    iStack_4c = 1;
    uStack_50 = 0;
    uStack_54 = 10;
    pbStack_58 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 0x476485;
    local_3c = FUN_0046f7f0();
  }
  *(undefined4 *)(local_38 + 0x27c) = local_3c;
  iStack_48 = 0;
  iStack_4c = 0;
  uStack_50 = 1;
  uStack_54 = 1;
  local_34 = abStack_70;
  local_40 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
             basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_70,local_30);
  local_44 = FUN_00423120();
  *(undefined4 *)(local_38 + 600) = local_44;
  if (*(int *)(local_38 + 600) == -1) {
    *(undefined1 *)(local_38 + 0x290) = 0;
  }
  else {
    *(undefined1 *)(local_38 + 0x290) = 1;
  }
  iStack_48 = 0x4764f1;
  FUN_00476550();
  iStack_48 = local_38 + 0x284;
  iStack_4c = local_38 + 0x280;
  uStack_50 = *(undefined4 *)(local_38 + 600);
  uStack_54 = 0x476513;
  FUN_00515880();
  *(undefined4 *)(local_38 + 0x278) = 0;
  local_8 = 0xffffffff;
  iStack_48 = 0x476532;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_30);
  ExceptionList = local_10;
  return;
}

