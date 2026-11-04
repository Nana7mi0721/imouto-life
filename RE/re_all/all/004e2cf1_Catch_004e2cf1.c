
void Catch_004e2cf1(void)

{
  int unaff_EBP;
  
  FUN_004e4160(*(int *)(unaff_EBP + 8) + *(int *)(unaff_EBP + 0xc),
               *(int *)(*(int *)(unaff_EBP + -0x28) + 8) + *(int *)(unaff_EBP + 0xc));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(*(int *)(unaff_EBP + -0x28) + 8) =
       *(int *)(*(int *)(unaff_EBP + -0x28) + 8) + *(int *)(unaff_EBP + 0xc);
  FUN_004eebf0(*(undefined4 *)(unaff_EBP + 8),
               *(int *)(*(int *)(unaff_EBP + -0x28) + 8) - *(int *)(unaff_EBP + 0xc),
               unaff_EBP + -0x11);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

