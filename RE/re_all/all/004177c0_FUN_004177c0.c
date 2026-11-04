
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004177c0(void)

{
  int iVar1;
  undefined4 uVar2;
  LPARAM lParam;
  undefined1 auStack_88 [4];
  undefined4 uStack_84;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_58 [28];
  undefined1 *local_3c;
  int local_38;
  HWND local_34;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007abb43;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  if ((DAT_00a0f80c != (HWND)0x0) && (DAT_00a0f82c == 1)) {
    ExceptionList = &local_10;
    local_34 = GetDlgItem(DAT_00a0f80c,0x3e9);
    local_38 = GetScrollPos(local_34,0);
    uStack_84 = 0x417838;
    SendDlgItemMessageA(DAT_00a0f80c,0x3e9,0xb,0,0);
    iVar1 = FUN_004e5650();
    if (-1 < iVar1 + -2000) {
      FUN_004e5650();
    }
    FUN_004cbc20();
    local_8 = 0;
    uVar2 = FUN_004cbb30();
    local_3c = auStack_88;
    basic_string<>(uVar2);
    FUN_004298c0(local_30);
    local_8 = CONCAT31(local_8._1_3_,2);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58);
    lParam = FUN_004cbb30();
    uStack_84 = 0x4178de;
    SendDlgItemMessageA(DAT_00a0f80c,0x3e9,0xc,0x104,lParam);
    uStack_84 = 0x417906;
    SendDlgItemMessageA(DAT_00a0f80c,0x3e9,0xb6,local_38 / 6,0xffff);
    uStack_84 = 0x41791d;
    SendDlgItemMessageA(DAT_00a0f80c,0x3e9,0xb,1,0);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_30);
  }
  DAT_00a11798 = 0;
  ExceptionList = local_10;
  return;
}

