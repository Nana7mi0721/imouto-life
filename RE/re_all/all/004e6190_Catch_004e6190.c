
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Catch_004e6190(void)

{
  int unaff_EBP;
  
  FUN_004dc4a0(*(int *)(unaff_EBP + 0xc) * 0x148 + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x148 + *(int *)(*(int *)(unaff_EBP + -0x174) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x174) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x148 + *(int *)(*(int *)(unaff_EBP + -0x174) + 8);
  FUN_004eef30(*(undefined4 *)(unaff_EBP + 8),
               *(int *)(*(int *)(unaff_EBP + -0x174) + 8) + *(int *)(unaff_EBP + 0xc) * -0x148,
               unaff_EBP + -0x160);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004788e0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

