
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Catch_004e4eac(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004db750(*(undefined4 *)(unaff_EBP + -0x224),*(undefined4 *)(unaff_EBP + -0x220));
  deallocate(*(undefined4 *)(unaff_EBP + -0x224),*(undefined4 *)(unaff_EBP + -0x21c));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004d0b50();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x22c) + 4) != 0) {
    FUN_004db750(*(undefined4 *)(*(int *)(unaff_EBP + -0x22c) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x22c) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x22c) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0x22c) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x22c) + 4)) / 0x1fc);
  }
  *(int *)(*(int *)(unaff_EBP + -0x22c) + 0xc) =
       *(int *)(unaff_EBP + -0x21c) * 0x1fc + *(int *)(unaff_EBP + -0x224);
  *(int *)(*(int *)(unaff_EBP + -0x22c) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x1fc + *(int *)(unaff_EBP + -0x224);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x22c) + 4) = *(undefined4 *)(unaff_EBP + -0x224);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00471b50();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

