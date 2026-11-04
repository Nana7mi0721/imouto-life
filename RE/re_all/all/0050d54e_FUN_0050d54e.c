
void FUN_0050d54e(void)

{
  code *pcVar1;
  int unaff_EBP;
  
  FUN_006c5130();
  basic_string<>("string too long");
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FID_conflict_runtime_error
            ((void *)(unaff_EBP + -0x50),
             (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(unaff_EBP + -0x28))
  ;
  *(undefined ***)(unaff_EBP + -0x50) = &PTR_FUN_007d4730;
  __CxxThrowException_8(unaff_EBP + -0x50,&DAT_00845c30);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

