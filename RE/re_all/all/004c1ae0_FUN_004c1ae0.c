
void __fastcall FUN_004c1ae0(int param_1)

{
  *(undefined1 *)(param_1 + 0x12e) = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x1c),"")
  ;
  *(undefined1 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x17c) = 0;
  if (DAT_00a14044 != -1) {
    FUN_00487240(*(int *)(param_1 + 0x178) + 2);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a14014,"");
  FUN_00487210(0xffffffff,0);
  DAT_00a1405c = 0;
  DAT_00a140c5 = 0;
  DAT_00a140b9 = 0;
  *(undefined4 *)(param_1 + 0x198) = 0;
  *(undefined4 *)(param_1 + 0x16c) = 0;
  DAT_00a14091 = DAT_00a14090 != '\0';
  return;
}

