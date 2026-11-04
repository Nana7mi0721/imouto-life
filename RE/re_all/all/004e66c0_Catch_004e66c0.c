
void Catch_004e66c0(void)

{
  int unaff_EBP;
  
  FUN_004dc760(*(int *)(unaff_EBP + 0xc) * 0x268 + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x268 + *(int *)(*(int *)(unaff_EBP + -0x294) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x294) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x268 + *(int *)(*(int *)(unaff_EBP + -0x294) + 8);
  FUN_004eefc0(*(undefined4 *)(unaff_EBP + 8),
               *(int *)(*(int *)(unaff_EBP + -0x294) + 8) + *(int *)(unaff_EBP + 0xc) * -0x268,
               unaff_EBP + -0x280);
  FUN_004e67ce();
  return;
}

