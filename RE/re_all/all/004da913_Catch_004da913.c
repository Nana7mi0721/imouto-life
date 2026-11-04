
void Catch_004da913(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004da730(*(undefined4 *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x40));
  deallocate(*(undefined4 *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x3c));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004d00e0();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x4c) + 4) != 0) {
    FUN_004da730(*(undefined4 *)(*(int *)(unaff_EBP + -0x4c) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x4c) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x4c) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0x4c) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x4c) + 4)) / 0x28);
  }
  *(int *)(*(int *)(unaff_EBP + -0x4c) + 0xc) =
       *(int *)(unaff_EBP + -0x3c) * 0x28 + *(int *)(unaff_EBP + -0x44);
  *(int *)(*(int *)(unaff_EBP + -0x4c) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x28 + *(int *)(unaff_EBP + -0x44);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x4c) + 4) = *(undefined4 *)(unaff_EBP + -0x44);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004ada40();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

