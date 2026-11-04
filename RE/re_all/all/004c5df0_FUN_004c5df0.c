
void __fastcall FUN_004c5df0(undefined4 *param_1)

{
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_34 [28];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 *local_c;
  undefined1 *local_8;
  
  uStack_14 = param_1[0x9b];
  uStack_18 = 0;
  local_8 = abStack_34;
  local_c = param_1;
  local_10 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
             basic_string<char,std::char_traits<char>,std::allocator<char>_>
                       (abStack_34,
                        (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                         *)(param_1 + 0x5b));
  FUN_004361d0();
  *(undefined1 *)((int)local_c + 0x279) = 1;
  *(undefined1 *)((int)local_c + 0x27a) = 1;
  local_c[1] = 0;
  *local_c = 0;
  return;
}

