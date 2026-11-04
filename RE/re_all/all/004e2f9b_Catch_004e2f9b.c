
void Catch_004e2f9b(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004e4160(*(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + -0x1c));
  deallocate(*(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + -0x18));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar1 = FUN_004ce080();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x28) + 4) != 0) {
    FUN_004e4160(*(undefined4 *)(*(int *)(unaff_EBP + -0x28) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x28) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x28) + 4),
               *(int *)(*(int *)(unaff_EBP + -0x28) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x28) + 4) >> 2);
  }
  *(int *)(*(int *)(unaff_EBP + -0x28) + 0xc) =
       *(int *)(unaff_EBP + -0x20) + *(int *)(unaff_EBP + -0x18) * 4;
  *(int *)(*(int *)(unaff_EBP + -0x28) + 8) =
       *(int *)(unaff_EBP + -0x20) + *(int *)(unaff_EBP + 0xc) * 4;
  *(undefined4 *)(*(int *)(unaff_EBP + -0x28) + 4) = *(undefined4 *)(unaff_EBP + -0x20);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

