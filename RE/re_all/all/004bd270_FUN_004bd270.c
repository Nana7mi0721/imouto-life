
void __fastcall FUN_004bd270(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007b09ea;
  local_10 = ExceptionList;
  local_8 = 9;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
             (param_1 + 0x2740));
  local_8._0_1_ = 8;
  FUN_00484b30();
  local_8._0_1_ = 7;
  FUN_004a6be0();
  local_8._0_1_ = 6;
  CMiniDockFrameWnd::~CMiniDockFrameWnd((CMiniDockFrameWnd *)(param_1 + 0x24e8));
  local_8._0_1_ = 5;
  FUN_004a68c0();
  local_8._0_1_ = 4;
  FUN_004a6aa0();
  local_8._0_1_ = 3;
  FUN_004a6940();
  local_8._0_1_ = 2;
  FUN_004bd250();
  local_8._0_1_ = 1;
  FUN_004bd250();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004bd230();
  local_8 = 0xffffffff;
  FUN_004d3520();
  ExceptionList = local_10;
  return;
}

