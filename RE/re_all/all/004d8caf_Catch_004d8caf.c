
void Catch_004d8caf(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004d8ac0(*(undefined4 *)(unaff_EBP + -0x74),*(undefined4 *)(unaff_EBP + -0x70));
  deallocate(*(undefined4 *)(unaff_EBP + -0x74),*(undefined4 *)(unaff_EBP + -0x6c));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004cec90();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x7c) + 4) != 0) {
    FUN_004d8ac0(*(undefined4 *)(*(int *)(unaff_EBP + -0x7c) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x7c) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x7c) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0x7c) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x7c) + 4)) / 0x54);
  }
  *(int *)(*(int *)(unaff_EBP + -0x7c) + 0xc) =
       *(int *)(unaff_EBP + -0x6c) * 0x54 + *(int *)(unaff_EBP + -0x74);
  *(int *)(*(int *)(unaff_EBP + -0x7c) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x54 + *(int *)(unaff_EBP + -0x74);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x7c) + 4) = *(undefined4 *)(unaff_EBP + -0x74);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CBitmapButton::~CBitmapButton((CBitmapButton *)(unaff_EBP + -0x68));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

