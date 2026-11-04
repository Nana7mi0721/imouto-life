
void Catch_004d9430(void)

{
  int unaff_EBP;
  
  FUN_004d9050(*(int *)(unaff_EBP + 0xc) * 0x88 + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x88 + *(int *)(*(int *)(unaff_EBP + -0xb4) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0xb4) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x88 + *(int *)(*(int *)(unaff_EBP + -0xb4) + 8);
  FUN_004ede30(*(undefined4 *)(unaff_EBP + 8),
               *(int *)(*(int *)(unaff_EBP + -0xb4) + 8) + *(int *)(unaff_EBP + 0xc) * -0x88,
               unaff_EBP + -0xa0);
  FUN_004d953e();
  return;
}

