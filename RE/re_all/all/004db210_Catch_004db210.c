
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Catch_004db210(void)

{
  int unaff_EBP;
  
  FUN_004dae30(*(int *)(unaff_EBP + 0xc) * 0xa8 + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0xa8 + *(int *)(*(int *)(unaff_EBP + -0xd4) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0xd4) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0xa8 + *(int *)(*(int *)(unaff_EBP + -0xd4) + 8);
  FUN_004ee2e0(*(undefined4 *)(unaff_EBP + 8),
               *(int *)(*(int *)(unaff_EBP + -0xd4) + 8) + *(int *)(unaff_EBP + 0xc) * -0xa8,
               unaff_EBP + -0xc0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004ada90();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

