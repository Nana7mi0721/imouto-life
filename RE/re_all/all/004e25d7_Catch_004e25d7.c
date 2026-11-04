
void Catch_004e25d7(void)

{
  int unaff_EBP;
  
  FUN_004d79d0(*(int *)(unaff_EBP + 0xc) * 0xc + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0xc + *(int *)(*(int *)(unaff_EBP + -0x30) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x30) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0xc + *(int *)(*(int *)(unaff_EBP + -0x30) + 8);
  _Destroy_range<>(*(undefined4 *)(unaff_EBP + 8),
                   *(int *)(*(int *)(unaff_EBP + -0x30) + 8) + *(int *)(unaff_EBP + 0xc) * -0xc,
                   unaff_EBP + -0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00471980();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

