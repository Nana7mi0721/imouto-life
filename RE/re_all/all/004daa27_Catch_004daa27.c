
void Catch_004daa27(void)

{
  int unaff_EBP;
  
  FUN_004da730(*(int *)(unaff_EBP + 0xc) * 0x28 + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x28 + *(int *)(*(int *)(unaff_EBP + -0x4c) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x4c) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x28 + *(int *)(*(int *)(unaff_EBP + -0x4c) + 8);
  _Destroy_range<>(*(undefined4 *)(unaff_EBP + 8),
                   *(int *)(*(int *)(unaff_EBP + -0x4c) + 8) + *(int *)(unaff_EBP + 0xc) * -0x28,
                   unaff_EBP + -0x38);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004ada40();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

