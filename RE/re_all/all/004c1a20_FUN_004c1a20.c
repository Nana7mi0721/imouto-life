
void __fastcall FUN_004c1a20(int param_1)

{
  *(undefined1 *)(param_1 + 0x256) = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x1c),"")
  ;
  *(undefined1 *)(param_1 + 0x254) = 0;
  if (DAT_00a14030 != -1) {
    FUN_004c1ab0();
  }
  DAT_00a140b9 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a13fc0,"");
  FUN_004872d0(0xffffffff,0);
  DAT_00a1405c = 0;
  DAT_00a14090 = 0;
  DAT_00a14091 = 0;
  *(undefined4 *)(param_1 + 0x274) = 0;
  return;
}

