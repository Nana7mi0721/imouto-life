
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Catch_004e48a0(void)

{
  int unaff_EBP;
  
  FUN_004d9e40(*(int *)(unaff_EBP + 0xc) * 0xbec + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0xbec + *(int *)(*(int *)(unaff_EBP + -0xc1c) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0xc1c) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0xbec + *(int *)(*(int *)(unaff_EBP + -0xc1c) + 8);
  FUN_004eec20(*(undefined4 *)(unaff_EBP + 8),
               *(int *)(*(int *)(unaff_EBP + -0xc1c) + 8) + *(int *)(unaff_EBP + 0xc) * -0xbec,
               unaff_EBP + -0xc08);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00481330();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

