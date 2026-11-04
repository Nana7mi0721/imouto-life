
void __fastcall FUN_004b34a0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007b02ee;
  local_10 = ExceptionList;
  local_8 = 5;
  ExceptionList = &local_10;
  FUN_004b3550();
  local_8._0_1_ = 4;
  FUN_00484b30();
  local_8._0_1_ = 3;
  FUN_004a6be0();
  local_8._0_1_ = 2;
  CMiniDockFrameWnd::~CMiniDockFrameWnd((CMiniDockFrameWnd *)(param_1 + 0x24b0));
  local_8._0_1_ = 1;
  FUN_004a68c0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004a6aa0();
  local_8 = 0xffffffff;
  FUN_004a6940();
  ExceptionList = local_10;
  return;
}

