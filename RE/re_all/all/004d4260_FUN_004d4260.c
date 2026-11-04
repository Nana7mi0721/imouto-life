
undefined4 * __thiscall FUN_004d4260(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 1),
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (param_2 + 1));
  *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_2 + 8);
  *(undefined1 *)((int)param_1 + 0x21) = *(undefined1 *)((int)param_2 + 0x21);
  *(undefined1 *)((int)param_1 + 0x22) = *(undefined1 *)((int)param_2 + 0x22);
  *(undefined1 *)((int)param_1 + 0x23) = *(undefined1 *)((int)param_2 + 0x23);
  return param_1;
}

