
void FUN_004f6080(undefined4 param_1,
                 basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                 *param_2)

{
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1fc1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
         FUN_004e22e0(0x1c,param_1);
  local_8 = 0;
  if (this != (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x0) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(this,param_2);
  }
  ExceptionList = local_10;
  return;
}

