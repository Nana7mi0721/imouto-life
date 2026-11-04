
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Catch_004e5020(void)

{
  int unaff_EBP;
  
  FUN_004db750(*(int *)(unaff_EBP + 0xc) * 0x1fc + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x1fc + *(int *)(*(int *)(unaff_EBP + -0x22c) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x22c) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x1fc + *(int *)(*(int *)(unaff_EBP + -0x22c) + 8);
  FUN_004eed10(*(undefined4 *)(unaff_EBP + 8),
               *(int *)(*(int *)(unaff_EBP + -0x22c) + 8) + *(int *)(unaff_EBP + 0xc) * -0x1fc,
               unaff_EBP + -0x218);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00471b50();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

