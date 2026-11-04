
void __fastcall FUN_0046f320(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007ae85e;
  local_10 = ExceptionList;
  local_8 = 2;
  ExceptionList = &local_10;
  FUN_004cd870();
  local_8._0_1_ = 1;
  FUN_004cee50();
  local_8 = (uint)local_8._1_3_ << 8;
  CDHtmlElementEventSink::~CDHtmlElementEventSink((CDHtmlElementEventSink *)(param_1 + 0x4c));
  local_8 = 0xffffffff;
  FUN_0046d470();
  ExceptionList = local_10;
  return;
}

