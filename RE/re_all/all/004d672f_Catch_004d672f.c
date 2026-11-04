
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Catch_004d672f(void)

{
  int unaff_EBP;
  
  FUN_004d6430(*(int *)(unaff_EBP + 0xc) * 0x1c + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x1c + *(int *)(*(int *)(unaff_EBP + -0x44) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x44) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x1c + *(int *)(*(int *)(unaff_EBP + -0x44) + 8);
  _Destroy_range<>(*(undefined4 *)(unaff_EBP + 8),
                   *(int *)(*(int *)(unaff_EBP + -0x44) + 8) + *(int *)(unaff_EBP + 0xc) * -0x1c,
                   unaff_EBP + -0x30);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (unaff_EBP + -0x30));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

