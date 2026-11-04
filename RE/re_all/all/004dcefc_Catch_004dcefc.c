
void Catch_004dcefc(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004dcc90(*(undefined4 *)(unaff_EBP + -0x3ac),*(undefined4 *)(unaff_EBP + -0x3a8));
  deallocate(*(undefined4 *)(unaff_EBP + -0x3ac),*(undefined4 *)(unaff_EBP + -0x3a4));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004d3180();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x3b4) + 4) != 0) {
    FUN_004dcc90(*(undefined4 *)(*(int *)(unaff_EBP + -0x3b4) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x3b4) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x3b4) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0x3b4) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x3b4) + 4)) / 0x388);
  }
  *(int *)(*(int *)(unaff_EBP + -0x3b4) + 0xc) =
       *(int *)(unaff_EBP + -0x3a4) * 0x388 + *(int *)(unaff_EBP + -0x3ac);
  *(int *)(*(int *)(unaff_EBP + -0x3b4) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x388 + *(int *)(unaff_EBP + -0x3ac);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x3b4) + 4) = *(undefined4 *)(unaff_EBP + -0x3ac);
  FUN_004dd17e();
  return;
}

