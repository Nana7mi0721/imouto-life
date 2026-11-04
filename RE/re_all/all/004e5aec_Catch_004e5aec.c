
void Catch_004e5aec(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004dc240(*(undefined4 *)(unaff_EBP + -0x8cc),*(undefined4 *)(unaff_EBP + -0x8c8));
  deallocate(*(undefined4 *)(unaff_EBP + -0x8cc),*(undefined4 *)(unaff_EBP + -0x8c4));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004d21f0();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x8d4) + 4) != 0) {
    FUN_004dc240(*(undefined4 *)(*(int *)(unaff_EBP + -0x8d4) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x8d4) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x8d4) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0x8d4) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x8d4) + 4)) / 0x8a8);
  }
  *(int *)(*(int *)(unaff_EBP + -0x8d4) + 0xc) =
       *(int *)(unaff_EBP + -0x8c4) * 0x8a8 + *(int *)(unaff_EBP + -0x8cc);
  *(int *)(*(int *)(unaff_EBP + -0x8d4) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x8a8 + *(int *)(unaff_EBP + -0x8cc);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x8d4) + 4) = *(undefined4 *)(unaff_EBP + -0x8cc);
  FUN_004e5d6e();
  return;
}

