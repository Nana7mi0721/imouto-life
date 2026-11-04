
void Catch_004e5c60(void)

{
  int unaff_EBP;
  
  FUN_004dc240(*(int *)(unaff_EBP + 0xc) * 0x8a8 + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x8a8 + *(int *)(*(int *)(unaff_EBP + -0x8d4) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x8d4) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x8a8 + *(int *)(*(int *)(unaff_EBP + -0x8d4) + 8);
  FUN_004eeea0(*(undefined4 *)(unaff_EBP + 8),
               *(int *)(*(int *)(unaff_EBP + -0x8d4) + 8) + *(int *)(unaff_EBP + 0xc) * -0x8a8,
               unaff_EBP + -0x8c0);
  FUN_004e5d6e();
  return;
}

