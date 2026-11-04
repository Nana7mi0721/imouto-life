
void Catch_004e53c2(void)

{
  int unaff_EBP;
  
  FUN_004e4160(*(int *)(unaff_EBP + 8) + *(int *)(unaff_EBP + 0xc) * 2,
               *(int *)(*(int *)(unaff_EBP + -0x28) + 8) + *(int *)(unaff_EBP + 0xc) * 2);
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(*(int *)(unaff_EBP + -0x28) + 8) =
       *(int *)(*(int *)(unaff_EBP + -0x28) + 8) + *(int *)(unaff_EBP + 0xc) * 2;
  FUN_004eee30(*(undefined4 *)(unaff_EBP + 8),
               *(int *)(*(int *)(unaff_EBP + -0x28) + 8) + *(int *)(unaff_EBP + 0xc) * -2,
               unaff_EBP + -0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

