
void FUN_0050d50e(void)

{
  code *pcVar1;
  int unaff_EBP;
  
  FUN_006c5130();
  basic_string<>("invalid string position");
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FID_conflict_runtime_error
            ((void *)(unaff_EBP + -0x50),
             (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(unaff_EBP + -0x28))
  ;
  *(undefined ***)(unaff_EBP + -0x50) = &PTR_FUN_007d473c;
  __CxxThrowException_8(unaff_EBP + -0x50,&DAT_008452e0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

