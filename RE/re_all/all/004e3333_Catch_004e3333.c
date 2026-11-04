
void Catch_004e3333(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004d80b0(*(undefined4 *)(unaff_EBP + -0x2c),*(undefined4 *)(unaff_EBP + -0x28));
  deallocate(*(undefined4 *)(unaff_EBP + -0x2c),*(undefined4 *)(unaff_EBP + -0x24));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004cd340();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x34) + 4) != 0) {
    FUN_004d80b0(*(undefined4 *)(*(int *)(unaff_EBP + -0x34) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x34) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x34) + 4),
               *(int *)(*(int *)(unaff_EBP + -0x34) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x34) + 4) >> 4);
  }
  *(int *)(*(int *)(unaff_EBP + -0x34) + 0xc) =
       *(int *)(unaff_EBP + -0x24) * 0x10 + *(int *)(unaff_EBP + -0x2c);
  *(int *)(*(int *)(unaff_EBP + -0x34) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x10 + *(int *)(unaff_EBP + -0x2c);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x34) + 4) = *(undefined4 *)(unaff_EBP + -0x2c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004cd4c0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

