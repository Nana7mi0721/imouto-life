
void Catch_004e4057(void)

{
  int unaff_EBP;
  
  FUN_004e3dd0(*(int *)(unaff_EBP + 0xc) * 0x18 + *(int *)(unaff_EBP + 8),
               *(int *)(unaff_EBP + 0xc) * 0x18 + *(int *)(*(int *)(unaff_EBP + -0x3c) + 8));
  __CxxThrowException_8(0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(*(int *)(unaff_EBP + -0x3c) + 8) =
       *(int *)(unaff_EBP + 0xc) * 0x18 + *(int *)(*(int *)(unaff_EBP + -0x3c) + 8);
  _Destroy_range<>(*(undefined4 *)(unaff_EBP + 8),
                   *(int *)(*(int *)(unaff_EBP + -0x3c) + 8) + *(int *)(unaff_EBP + 0xc) * -0x18,
                   unaff_EBP + -0x28);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CDHtmlElementEventSink::~CDHtmlElementEventSink((CDHtmlElementEventSink *)(unaff_EBP + -0x28));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

