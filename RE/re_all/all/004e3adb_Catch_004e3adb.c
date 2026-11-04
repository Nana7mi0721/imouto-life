
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Catch_004e3adb(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004d85a0(*(undefined4 *)(unaff_EBP + -0x50),*(undefined4 *)(unaff_EBP + -0x4c));
  deallocate(*(undefined4 *)(unaff_EBP + -0x50),*(undefined4 *)(unaff_EBP + -0x48));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004ce5c0();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x58) + 4) != 0) {
    FUN_004d85a0(*(undefined4 *)(*(int *)(unaff_EBP + -0x58) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x58) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x58) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0x58) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x58) + 4)) / 0x30);
  }
  *(int *)(*(int *)(unaff_EBP + -0x58) + 0xc) =
       *(int *)(unaff_EBP + -0x48) * 0x30 + *(int *)(unaff_EBP + -0x50);
  *(int *)(*(int *)(unaff_EBP + -0x58) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x30 + *(int *)(unaff_EBP + -0x50);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x58) + 4) = *(undefined4 *)(unaff_EBP + -0x50);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004864a0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

