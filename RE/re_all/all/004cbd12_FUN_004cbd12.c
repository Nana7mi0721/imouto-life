
undefined4 FUN_004cbd12(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  std::basic_ios<char,std::char_traits<char>_>::setstate
            ((basic_ios<char,std::char_traits<char>_> *)
             (*(int *)(unaff_EBP + -0x24) + *(int *)(**(int **)(unaff_EBP + -0x24) + 4)),
             *(int *)(unaff_EBP + -0x14),false);
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004df000();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x20);
}

