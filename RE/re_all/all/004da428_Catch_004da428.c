
void Catch_004da428(void)

{
  int unaff_EBP;
  
  FUN_004da140(*(int *)(unaff_EBP + 0xc) * 0x20 + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x20 + *(int *)(*(int *)(unaff_EBP + -0x44) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x44) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x20 + *(int *)(*(int *)(unaff_EBP + -0x44) + 8);
  _Destroy_range<>(*(undefined4 *)(unaff_EBP + 8),
                   *(int *)(*(int *)(unaff_EBP + -0x44) + 8) + *(int *)(unaff_EBP + 0xc) * -0x20,
                   unaff_EBP + -0x30);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00477f40();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

