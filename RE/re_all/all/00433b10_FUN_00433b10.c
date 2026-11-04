
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00433b10(char param_1)

{
  SHORT SVar1;
  int iVar2;
  undefined8 local_170;
  undefined4 local_168;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_164 [28];
  char local_148 [256];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_48 [28];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad025;
  local_10 = ExceptionList;
  local_2c = DAT_0084b484;
  if (param_1 == '\x01') {
    return DAT_00a1fb48;
  }
  ExceptionList = &local_10;
  if ((DAT_00a117a8 != 0) && (ExceptionList = &local_10, DAT_00a14677 != '\0')) {
    if (DAT_00a0f82c == 0) {
      ExceptionList = &local_10;
      FUN_004176d0();
    }
    else {
      ExceptionList = &local_10;
      FUN_00417950();
    }
  }
  if (DAT_00a14679 != '\0') {
    if (DAT_00a117b4 == 1) {
      local_14 = GetSystemMetrics(0x10);
      local_1c = GetSystemMetrics(0x11);
      FUN_0050e8d0();
      local_18 = FUN_004fe844();
      if (DAT_00a117c4 == 1) {
        SendMessageA(DAT_00a0f804,0x112,0xf120,0);
        FUN_005119d0();
      }
      else if ((local_14 < (local_18 + 1) * DAT_0084b230) ||
              (local_1c < (local_18 + 1) * DAT_0084b234)) {
        SendMessageA(DAT_00a0f804,0x112,0xf030,0);
      }
      else {
        FUN_005119d0();
        SendMessageA(DAT_00a0f804,0x112,0xf120,0);
      }
      FUN_0050f160();
    }
    else {
      _DAT_00a1fb44 = 0;
      FUN_005119d0();
    }
    FUN_00475460();
  }
  if (DAT_00a1467b != '\0') {
    DAT_00a1fb48 = (DAT_00a18a8c + 1) % 3;
    FUN_0042f720();
  }
  if ((DAT_00a14683 != '\0') &&
     (DAT_00a140bc = DAT_00a140bc + 1 & 0x80000001, (int)DAT_00a140bc < 0)) {
    DAT_00a140bc = (DAT_00a140bc - 1 | 0xfffffffe) + 1;
  }
  if ((DAT_00a117a8 != 0) && (DAT_00a1467f != '\0')) {
    FUN_0042fe30();
  }
  if ((DAT_00a14681 != '\0') && (DAT_00a14360 != 0)) {
    FUN_00475460();
    DAT_00a140bc = 0xfffffff6;
  }
  if ((DAT_00a117a8 != 0) && (DAT_00a14681 != '\0')) {
    FUN_004325e0();
  }
  if (((DAT_00a117a8 == 0) && (DAT_00a14688 != '\0')) ||
     ((DAT_00a14608 != '\0' && (DAT_00a14688 != '\0')))) {
    FUN_00511770();
    if (DAT_00a117b4 == 1) {
      DAT_00a117b4 = (DAT_00a117c8 != 1) - 1;
    }
    else {
      DAT_00a117b4 = 1;
    }
    FUN_0052a4a0();
    FUN_00436590();
    FUN_0050f160();
  }
  if (((DAT_00a117a8 != 0) && (DAT_00a14688 != '\0')) && (DAT_00a14608 == '\0')) {
    FUN_005160d0();
    FUN_00536900();
    FUN_00543f70();
    FUN_00526390();
    FUN_005160d0();
    local_20 = 0x12;
    FUN_00543f70();
    basic_string<>(&DAT_007cdca0);
    FUN_00401c50();
    FUN_00540800();
    FUN_00543f70();
    basic_string<>(&DAT_007cdd14);
    FUN_00401c50();
    FUN_00540800();
    FUN_00543f70();
    basic_string<>(&DAT_007cdd28);
    FUN_00401c50();
    FUN_00540800();
    FUN_00543f70();
    basic_string<>(&DAT_007cdd3c);
    FUN_00401c50();
    FUN_00540800();
    FUN_00543f70();
    basic_string<>(&DAT_007cdd68);
    FUN_00401c50();
    FUN_00540800();
    FUN_00543f70();
    basic_string<>(&DAT_007cdd7c);
    FUN_00401c50();
    FUN_004fe844();
    FUN_00540800();
    FUN_00543f70();
    basic_string<>(&DAT_007cdda8);
    FUN_00401c50();
    FUN_00540800();
    thunk_FUN_00522bc0();
    FUN_0044b440();
    DAT_00a140a9 = 1;
    FUN_00536900();
  }
  if ((DAT_00a1468a != '\0') && (DAT_0084b22c != 0)) {
    DAT_00a117e0 = 1;
    FUN_00543f70();
    FUN_00526390();
    thunk_FUN_00522bc0();
    FUN_00475d30();
    FUN_00423060();
    FUN_00475c70();
    FUN_00472b10();
    FUN_00475570();
    DAT_00a13fa0 = 0;
  }
  if (((DAT_00a117dc == 1) && (iVar2 = FUN_0050e880(), iVar2 == 1)) && (DAT_00a117b4 == 0)) {
    FUN_005119d0();
    FUN_00436590();
    FUN_0050f160();
    DAT_00a117dc = 0;
  }
  if (DAT_00a14ae9 != '\0') {
    DAT_00a117dc = 1;
  }
  iVar2 = FUN_0050e880();
  if (((iVar2 == 1) && (DAT_0084b228 != 0)) &&
     ((DAT_00a1468b != '\0' ||
      ((SVar1 = GetAsyncKeyState(0x2c), ((int)SVar1 & 0x8000U) != 0 && (DAT_00a14a8c != '\0')))))) {
    basic_string<>();
    FUN_00401c50();
    thunk_FUN_00511800();
    FID_conflict___time32((__time32_t *)&local_170);
    _localtime(&local_170);
    _localtime(&local_170);
    _localtime(&local_170);
    _localtime(&local_170);
    _localtime(&local_170);
    _localtime(&local_170);
    _sprintf(local_148,"ScreenShot_%d_%02d%02d_%02d_%02d_%02d.png");
    FUN_00525f20();
    FUN_00521db0();
    FUN_00528e50();
    FUN_00515700();
    local_170._4_4_ = FUN_00530810();
    basic_string<>();
    FUN_00401c50();
    basic_string<>();
    local_8 = 0;
    basic_string<>();
    local_8._0_1_ = 1;
    FUN_004e5650();
    FUN_004cbb30();
    local_168 = FUN_0053f680();
    FUN_004e5650();
    FUN_004cbb30();
    local_24 = FUN_0053f680();
    FUN_005160d0();
    FUN_00543f70();
    FUN_004fe844();
    FUN_004fe844();
    FUN_00526390();
    FUN_005160d0();
    local_28 = 0;
    if ((DAT_0084b264 == 0x10) && (DAT_0084b248 == 1)) {
      local_28 = 0xfffffff6;
    }
    if ((DAT_0084b264 == 0x10) && (DAT_0084b248 == 2)) {
      local_28 = 0xffffffec;
    }
    FUN_00543f70();
    FUN_004cbb30();
    FUN_004fe844();
    FUN_00540340();
    FUN_00543f70();
    FUN_004cbb30();
    FUN_004fe844();
    FUN_00540340();
    thunk_FUN_00580b80();
    thunk_FUN_00522bc0();
    FUN_0052ebd0();
    DAT_00a140bc = 0xfffffff6;
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_164);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_48);
  }
  ExceptionList = local_10;
  return -1;
}

