
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Catch_004e472c(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004d9e40(*(undefined4 *)(unaff_EBP + -0xc14),*(undefined4 *)(unaff_EBP + -0xc10));
  deallocate(*(undefined4 *)(unaff_EBP + -0xc14),*(undefined4 *)(unaff_EBP + -0xc0c));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004cfab0();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0xc1c) + 4) != 0) {
    FUN_004d9e40(*(undefined4 *)(*(int *)(unaff_EBP + -0xc1c) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0xc1c) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0xc1c) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0xc1c) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0xc1c) + 4)) / 0xbec);
  }
  *(int *)(*(int *)(unaff_EBP + -0xc1c) + 0xc) =
       *(int *)(unaff_EBP + -0xc0c) * 0xbec + *(int *)(unaff_EBP + -0xc14);
  *(int *)(*(int *)(unaff_EBP + -0xc1c) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0xbec + *(int *)(unaff_EBP + -0xc14);
  *(undefined4 *)(*(int *)(unaff_EBP + -0xc1c) + 4) = *(undefined4 *)(unaff_EBP + -0xc14);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00481330();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

