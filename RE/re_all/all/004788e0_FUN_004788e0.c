
void __fastcall FUN_004788e0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007af010;
  local_10 = ExceptionList;
  local_8 = 4;
  ExceptionList = &local_10;
  FUN_004ce950();
  local_8._0_1_ = 3;
  FUN_004cd870();
  local_8._0_1_ = 2;
  FUN_004ce950();
  local_8._0_1_ = 1;
  CDHtmlElementEventSink::~CDHtmlElementEventSink((CDHtmlElementEventSink *)(param_1 + 0x90));
  local_8 = (uint)local_8._1_3_ << 8;
  CDHtmlElementEventSink::~CDHtmlElementEventSink((CDHtmlElementEventSink *)(param_1 + 0x78));
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (param_1 + 8));
  ExceptionList = local_10;
  return;
}

