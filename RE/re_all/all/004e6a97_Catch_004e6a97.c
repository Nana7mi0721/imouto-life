
void Catch_004e6a97(void)

{
  int unaff_EBP;
  
  FUN_004dc980(*(int *)(unaff_EBP + 0xc) * 0x14 + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x14 + *(int *)(*(int *)(unaff_EBP + -0x38) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x38) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x14 + *(int *)(*(int *)(unaff_EBP + -0x38) + 8);
  _Destroy_range<>(*(undefined4 *)(unaff_EBP + 8),
                   *(int *)(*(int *)(unaff_EBP + -0x38) + 8) + *(int *)(unaff_EBP + 0xc) * -0x14,
                   unaff_EBP + -0x24);
  FUN_004e6b5d();
  return;
}

