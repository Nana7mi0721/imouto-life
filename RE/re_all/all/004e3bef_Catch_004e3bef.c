
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Catch_004e3bef(void)

{
  int unaff_EBP;
  
  FUN_004d85a0(*(int *)(unaff_EBP + 0xc) * 0x30 + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x30 + *(int *)(*(int *)(unaff_EBP + -0x58) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x58) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x30 + *(int *)(*(int *)(unaff_EBP + -0x58) + 8);
  _Destroy_range<>(*(undefined4 *)(unaff_EBP + 8),
                   *(int *)(*(int *)(unaff_EBP + -0x58) + 8) + *(int *)(unaff_EBP + 0xc) * -0x30,
                   unaff_EBP + -0x44);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004864a0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

