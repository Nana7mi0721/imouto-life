
exception * FUN_0050d7f3(void)

{
  exception *peVar1;
  exception *this;
  int unaff_EBP;
  
  FUN_006c5130();
  peVar1 = *(exception **)(unaff_EBP + 8);
  *(exception **)(unaff_EBP + -0x10) = this;
  exception::exception(this,peVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined ***)this = &PTR_FUN_007d477c;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(this + 0xc),
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (peVar1 + 0xc));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return this;
}

