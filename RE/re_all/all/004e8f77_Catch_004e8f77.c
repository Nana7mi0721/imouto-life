
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Catch_004e8f77(void)

{
  int unaff_EBP;
  
  FUN_004e8c10(*(int *)(unaff_EBP + 0xc) * 0x74 + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x74 + *(int *)(*(int *)(unaff_EBP + -0xa4) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0xa4) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x74 + *(int *)(*(int *)(unaff_EBP + -0xa4) + 8);
  _Destroy_range<>(*(undefined4 *)(unaff_EBP + 8),
                   *(int *)(*(int *)(unaff_EBP + -0xa4) + 8) + *(int *)(unaff_EBP + 0xc) * -0x74,
                   unaff_EBP + -0x90);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004c0f80();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

