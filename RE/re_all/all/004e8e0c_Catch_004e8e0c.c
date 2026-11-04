
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Catch_004e8e0c(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004e8c10(*(undefined4 *)(unaff_EBP + -0x9c),*(undefined4 *)(unaff_EBP + -0x98));
  deallocate(*(undefined4 *)(unaff_EBP + -0x9c),*(undefined4 *)(unaff_EBP + -0x94));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004dec00();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0xa4) + 4) != 0) {
    FUN_004e8c10(*(undefined4 *)(*(int *)(unaff_EBP + -0xa4) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0xa4) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0xa4) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0xa4) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0xa4) + 4)) / 0x74);
  }
  *(int *)(*(int *)(unaff_EBP + -0xa4) + 0xc) =
       *(int *)(unaff_EBP + -0x94) * 0x74 + *(int *)(unaff_EBP + -0x9c);
  *(int *)(*(int *)(unaff_EBP + -0xa4) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x74 + *(int *)(unaff_EBP + -0x9c);
  *(undefined4 *)(*(int *)(unaff_EBP + -0xa4) + 4) = *(undefined4 *)(unaff_EBP + -0x9c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004c0f80();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

