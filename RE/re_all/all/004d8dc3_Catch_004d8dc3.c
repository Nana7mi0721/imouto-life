
void Catch_004d8dc3(void)

{
  int unaff_EBP;
  
  FUN_004d8ac0(*(int *)(unaff_EBP + 0xc) * 0x54 + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x54 + *(int *)(*(int *)(unaff_EBP + -0x7c) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x7c) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x54 + *(int *)(*(int *)(unaff_EBP + -0x7c) + 8);
  _Destroy_range<>(*(undefined4 *)(unaff_EBP + 8),
                   *(int *)(*(int *)(unaff_EBP + -0x7c) + 8) + *(int *)(unaff_EBP + 0xc) * -0x54,
                   unaff_EBP + -0x68);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CBitmapButton::~CBitmapButton((CBitmapButton *)(unaff_EBP + -0x68));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

