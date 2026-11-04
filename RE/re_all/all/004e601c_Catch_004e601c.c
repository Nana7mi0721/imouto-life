
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Catch_004e601c(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004dc4a0(*(undefined4 *)(unaff_EBP + -0x16c),*(undefined4 *)(unaff_EBP + -0x168));
  deallocate(*(undefined4 *)(unaff_EBP + -0x16c),*(undefined4 *)(unaff_EBP + -0x164));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004d25e0();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x174) + 4) != 0) {
    FUN_004dc4a0(*(undefined4 *)(*(int *)(unaff_EBP + -0x174) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x174) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x174) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0x174) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x174) + 4)) / 0x148);
  }
  *(int *)(*(int *)(unaff_EBP + -0x174) + 0xc) =
       *(int *)(unaff_EBP + -0x164) * 0x148 + *(int *)(unaff_EBP + -0x16c);
  *(int *)(*(int *)(unaff_EBP + -0x174) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x148 + *(int *)(unaff_EBP + -0x16c);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x174) + 4) = *(undefined4 *)(unaff_EBP + -0x16c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004788e0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

