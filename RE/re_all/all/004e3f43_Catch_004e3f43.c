
void Catch_004e3f43(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_004e3dd0(*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x30));
  deallocate(*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x2c));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004ce7d0();
  *(int *)(unaff_EBP + 0xc) = iVar1 + *(int *)(unaff_EBP + 0xc);
  if (*(int *)(*(int *)(unaff_EBP + -0x3c) + 4) != 0) {
    FUN_004e3dd0(*(undefined4 *)(*(int *)(unaff_EBP + -0x3c) + 4),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x3c) + 8));
    deallocate(*(undefined4 *)(*(int *)(unaff_EBP + -0x3c) + 4),
               (*(int *)(*(int *)(unaff_EBP + -0x3c) + 0xc) -
               *(int *)(*(int *)(unaff_EBP + -0x3c) + 4)) / 0x18);
  }
  *(int *)(*(int *)(unaff_EBP + -0x3c) + 0xc) =
       *(int *)(unaff_EBP + -0x2c) * 0x18 + *(int *)(unaff_EBP + -0x34);
  *(int *)(*(int *)(unaff_EBP + -0x3c) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x18 + *(int *)(unaff_EBP + -0x34);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x3c) + 4) = *(undefined4 *)(unaff_EBP + -0x34);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CDHtmlElementEventSink::~CDHtmlElementEventSink((CDHtmlElementEventSink *)(unaff_EBP + -0x28));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

