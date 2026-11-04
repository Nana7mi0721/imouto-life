
void Catch_004e24c3(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004d79d0(*(undefined4 *)(unaff_EBP + -0x28),*(undefined4 *)(unaff_EBP + -0x24));
  deallocate(*(undefined4 *)(unaff_EBP + -0x28),*(undefined4 *)(unaff_EBP + -0x20));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004ccff0();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x30) + 4) != 0) {
    FUN_004d79d0(*(undefined4 *)(*(int *)(unaff_EBP + -0x30) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x30) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x30) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0x30) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x30) + 4)) / 0xc);
  }
  *(int *)(*(int *)(unaff_EBP + -0x30) + 0xc) =
       *(int *)(unaff_EBP + -0x20) * 0xc + *(int *)(unaff_EBP + -0x28);
  *(int *)(*(int *)(unaff_EBP + -0x30) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0xc + *(int *)(unaff_EBP + -0x28);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x30) + 4) = *(undefined4 *)(unaff_EBP + -0x28);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00471980();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

