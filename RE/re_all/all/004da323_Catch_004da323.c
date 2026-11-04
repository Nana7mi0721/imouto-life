
void Catch_004da323(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004da140(*(undefined4 *)(unaff_EBP + -0x3c),*(undefined4 *)(unaff_EBP + -0x38));
  deallocate(*(undefined4 *)(unaff_EBP + -0x3c),*(undefined4 *)(unaff_EBP + -0x34));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004cfc90();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x44) + 4) != 0) {
    FUN_004da140(*(undefined4 *)(*(int *)(unaff_EBP + -0x44) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x44) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x44) + 4),
               *(int *)(*(int *)(unaff_EBP + -0x44) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x44) + 4) >> 5);
  }
  *(int *)(*(int *)(unaff_EBP + -0x44) + 0xc) =
       *(int *)(unaff_EBP + -0x34) * 0x20 + *(int *)(unaff_EBP + -0x3c);
  *(int *)(*(int *)(unaff_EBP + -0x44) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x20 + *(int *)(unaff_EBP + -0x3c);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x44) + 4) = *(undefined4 *)(unaff_EBP + -0x3c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00477f40();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

