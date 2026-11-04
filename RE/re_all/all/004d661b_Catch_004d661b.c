
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Catch_004d661b(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004d6430(*(undefined4 *)(unaff_EBP + -0x3c),*(undefined4 *)(unaff_EBP + -0x38));
  deallocate(*(undefined4 *)(unaff_EBP + -0x3c),*(undefined4 *)(unaff_EBP + -0x34));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004cc430();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x44) + 4) != 0) {
    FUN_004d6430(*(undefined4 *)(*(int *)(unaff_EBP + -0x44) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x44) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x44) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0x44) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x44) + 4)) / 0x1c);
  }
  *(int *)(*(int *)(unaff_EBP + -0x44) + 0xc) =
       *(int *)(unaff_EBP + -0x34) * 0x1c + *(int *)(unaff_EBP + -0x3c);
  *(int *)(*(int *)(unaff_EBP + -0x44) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x1c + *(int *)(unaff_EBP + -0x3c);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x44) + 4) = *(undefined4 *)(unaff_EBP + -0x3c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (unaff_EBP + -0x30));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

