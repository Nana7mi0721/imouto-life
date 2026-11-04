
void __thiscall FUN_004a59d0(int param_1,CDHtmlElementEventSink param_2)

{
  char cVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007afbd8;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  cVar1 = FUN_004ce600();
  if (cVar1 != '\0') {
    FUN_00473ea0(param_1 + 0x78);
    *(undefined2 *)(param_1 + 0xaa) = *(undefined2 *)(param_1 + 0xa8);
  }
  FUN_00473ea0(&param_2);
  *(undefined2 *)(param_1 + 0xa8) = 0;
  *(undefined1 *)(param_1 + 0x52) = 1;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  FUN_0044cf90();
  local_8 = 0xffffffff;
  CDHtmlElementEventSink::~CDHtmlElementEventSink(&param_2);
  ExceptionList = local_10;
  return;
}

