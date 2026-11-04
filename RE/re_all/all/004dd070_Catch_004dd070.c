
void Catch_004dd070(void)

{
  int unaff_EBP;
  
  FUN_004dcc90(*(int *)(unaff_EBP + 0xc) * 0x388 + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x388 + *(int *)(*(int *)(unaff_EBP + -0x3b4) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x3b4) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x388 + *(int *)(*(int *)(unaff_EBP + -0x3b4) + 8);
  FUN_004ee5d0(*(undefined4 *)(unaff_EBP + 8),
               *(int *)(*(int *)(unaff_EBP + -0x3b4) + 8) + *(int *)(unaff_EBP + 0xc) * -0x388,
               unaff_EBP + -0x3a0);
  FUN_004dd17e();
  return;
}

