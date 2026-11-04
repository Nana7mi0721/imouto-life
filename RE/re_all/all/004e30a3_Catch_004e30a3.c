
void Catch_004e30a3(void)

{
  int unaff_EBP;
  
  FUN_004e4160(*(int *)(unaff_EBP + 8) + *(int *)(unaff_EBP + 0xc) * 4,
               *(int *)(*(int *)(unaff_EBP + -0x28) + 8) + *(int *)(unaff_EBP + 0xc) * 4);
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(*(int *)(unaff_EBP + -0x28) + 8) =
       *(int *)(*(int *)(unaff_EBP + -0x28) + 8) + *(int *)(unaff_EBP + 0xc) * 4;
  FUN_004edc90(*(undefined4 *)(unaff_EBP + 8),
               *(int *)(*(int *)(unaff_EBP + -0x28) + 8) + *(int *)(unaff_EBP + 0xc) * -4,
               unaff_EBP + -0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

