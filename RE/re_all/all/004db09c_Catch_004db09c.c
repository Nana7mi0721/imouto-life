
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Catch_004db09c(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004dae30(*(undefined4 *)(unaff_EBP + -0xcc),*(undefined4 *)(unaff_EBP + -200));
  deallocate(*(undefined4 *)(unaff_EBP + -0xcc),*(undefined4 *)(unaff_EBP + -0xc4));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004d0530();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0xd4) + 4) != 0) {
    FUN_004dae30(*(undefined4 *)(*(int *)(unaff_EBP + -0xd4) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0xd4) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0xd4) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0xd4) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0xd4) + 4)) / 0xa8);
  }
  *(int *)(*(int *)(unaff_EBP + -0xd4) + 0xc) =
       *(int *)(unaff_EBP + -0xc4) * 0xa8 + *(int *)(unaff_EBP + -0xcc);
  *(int *)(*(int *)(unaff_EBP + -0xd4) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0xa8 + *(int *)(unaff_EBP + -0xcc);
  *(undefined4 *)(*(int *)(unaff_EBP + -0xd4) + 4) = *(undefined4 *)(unaff_EBP + -0xcc);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004ada90();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

