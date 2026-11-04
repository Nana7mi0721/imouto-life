
void Catch_004e654c(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004dc760(*(undefined4 *)(unaff_EBP + -0x28c),*(undefined4 *)(unaff_EBP + -0x288));
  deallocate(*(undefined4 *)(unaff_EBP + -0x28c),*(undefined4 *)(unaff_EBP + -0x284));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004d29a0();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x294) + 4) != 0) {
    FUN_004dc760(*(undefined4 *)(*(int *)(unaff_EBP + -0x294) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x294) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x294) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0x294) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x294) + 4)) / 0x268);
  }
  *(int *)(*(int *)(unaff_EBP + -0x294) + 0xc) =
       *(int *)(unaff_EBP + -0x284) * 0x268 + *(int *)(unaff_EBP + -0x28c);
  *(int *)(*(int *)(unaff_EBP + -0x294) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x268 + *(int *)(unaff_EBP + -0x28c);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x294) + 4) = *(undefined4 *)(unaff_EBP + -0x28c);
  FUN_004e67ce();
  return;
}

