
void Catch_004e37d8(void)

{
  int unaff_EBP;
  
  FUN_004d82a0(*(int *)(unaff_EBP + 0xc) * 0x10 + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x10 + *(int *)(*(int *)(unaff_EBP + -0x34) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x34) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x10 + *(int *)(*(int *)(unaff_EBP + -0x34) + 8);
  _Destroy_range<>(*(undefined4 *)(unaff_EBP + 8),
                   *(int *)(*(int *)(unaff_EBP + -0x34) + 8) + *(int *)(unaff_EBP + 0xc) * -0x10,
                   unaff_EBP + -0x20);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004cc250();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

