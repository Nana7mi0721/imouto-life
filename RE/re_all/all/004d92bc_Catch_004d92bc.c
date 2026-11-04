
void Catch_004d92bc(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004d9050(*(undefined4 *)(unaff_EBP + -0xac),*(undefined4 *)(unaff_EBP + -0xa8));
  deallocate(*(undefined4 *)(unaff_EBP + -0xac),*(undefined4 *)(unaff_EBP + -0xa4));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004cf130();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0xb4) + 4) != 0) {
    FUN_004d9050(*(undefined4 *)(*(int *)(unaff_EBP + -0xb4) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0xb4) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0xb4) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0xb4) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0xb4) + 4)) / 0x88);
  }
  *(int *)(*(int *)(unaff_EBP + -0xb4) + 0xc) =
       *(int *)(unaff_EBP + -0xa4) * 0x88 + *(int *)(unaff_EBP + -0xac);
  *(int *)(*(int *)(unaff_EBP + -0xb4) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x88 + *(int *)(unaff_EBP + -0xac);
  *(undefined4 *)(*(int *)(unaff_EBP + -0xb4) + 4) = *(undefined4 *)(unaff_EBP + -0xac);
  FUN_004d953e();
  return;
}

