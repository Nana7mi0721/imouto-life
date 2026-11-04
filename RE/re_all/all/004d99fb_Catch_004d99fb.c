
void Catch_004d99fb(void)

{
  int unaff_EBP;
  
  FUN_004d96f0(*(int *)(unaff_EBP + 0xc) * 0x4c + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x4c + *(int *)(*(int *)(unaff_EBP + -0x7c) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x7c) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x4c + *(int *)(*(int *)(unaff_EBP + -0x7c) + 8);
  _Destroy_range<>(*(undefined4 *)(unaff_EBP + 8),
                   *(int *)(*(int *)(unaff_EBP + -0x7c) + 8) + *(int *)(unaff_EBP + 0xc) * -0x4c,
                   unaff_EBP + -0x68);
  FUN_004d9ac1();
  return;
}

