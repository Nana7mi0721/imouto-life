
void Catch_004e6983(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004dc980(*(undefined4 *)(unaff_EBP + -0x30),*(undefined4 *)(unaff_EBP + -0x2c));
  deallocate(*(undefined4 *)(unaff_EBP + -0x30),*(undefined4 *)(unaff_EBP + -0x28));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004d2d60();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x38) + 4) != 0) {
    FUN_004dc980(*(undefined4 *)(*(int *)(unaff_EBP + -0x38) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x38) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x38) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0x38) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x38) + 4)) / 0x14);
  }
  *(int *)(*(int *)(unaff_EBP + -0x38) + 0xc) =
       *(int *)(unaff_EBP + -0x28) * 0x14 + *(int *)(unaff_EBP + -0x30);
  *(int *)(*(int *)(unaff_EBP + -0x38) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x14 + *(int *)(unaff_EBP + -0x30);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x38) + 4) = *(undefined4 *)(unaff_EBP + -0x30);
  FUN_004e6b5d();
  return;
}

