
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0042bed0(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_1)

{
  int iVar1;
  char *pcVar2;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> bStack00000020;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> bStack0000003c;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_1bc [28];
  char local_1a0 [260];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_9c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_80 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_64 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_48 [28];
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007acde7;
  local_10 = ExceptionList;
  local_2c = DAT_0084b484;
  local_8 = 2;
  ExceptionList = &local_10;
  FUN_004cbb30();
  FUN_0041a4a0();
  FUN_004cbb30();
  FUN_0041a4a0();
  FUN_004cbb30();
  FUN_0041a4a0();
  FUN_0041a4a0();
  iVar1 = FUN_0050e8c0();
  if ((iVar1 == 0) && (DAT_00a13fa0 != -1)) {
    FUN_00536900();
    FUN_00536af0();
    local_20 = (uint)(DAT_0084b264 == 0x28) * 8 + 0x20;
    FUN_005160d0();
    FUN_00543f70();
    FUN_00526390();
    FUN_005160d0();
    FUN_005161e0();
    local_1c = 0;
    FUN_00536900();
    FUN_004e5650();
    FUN_004cbb30();
    local_28 = FUN_00540320();
    if (local_28 < DAT_0084b230) {
      FUN_00543f70();
      FUN_004cbb30();
      FUN_00540800();
    }
    else {
      FUN_004e5650();
      FUN_004cbc20();
      local_8._0_1_ = 3;
      FUN_004e5650();
      FUN_004cbc20();
      local_8._0_1_ = 4;
      FUN_00543f70();
      FUN_004cbb30();
      FUN_00540800();
      FUN_00543f70();
      FUN_004cbb30();
      FUN_00540800();
      local_8._0_1_ = 3;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_64);
      local_8 = CONCAT31(local_8._1_3_,2);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_48);
    }
    FUN_00536900();
    FUN_004e5650();
    FUN_004cbb30();
    local_18 = FUN_00540320();
    if (local_18 < DAT_0084b230) {
      FUN_00543f70();
      FUN_004cbb30();
      FUN_00540800();
    }
    else {
      FUN_004e5650();
      FUN_004cbc20();
      local_8._0_1_ = 5;
      FUN_004e5650();
      FUN_004cbc20();
      local_8._0_1_ = 6;
      FUN_00543f70();
      FUN_004cbb30();
      FUN_00540800();
      FUN_00543f70();
      FUN_004cbb30();
      FUN_00540800();
      local_8._0_1_ = 5;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_9c);
      local_8 = CONCAT31(local_8._1_3_,2);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_80);
    }
    FUN_004e5650();
    FUN_004cbb30();
    local_14 = FUN_00540320();
    FUN_00543f70();
    FUN_004cbb30();
    FUN_00540800();
    thunk_FUN_00522bc0();
    local_24 = 0;
    FUN_004cb880();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a164c4,
               "\r\n");
    FUN_004cb880();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a164c4,
               "\r\n");
    FUN_004cb880();
    basic_string<>();
    local_8 = CONCAT31(local_8._1_3_,7);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (local_1bc," -->[");
    if (DAT_00a0f818 != -1) {
      _sprintf(local_1a0,"MapEv%d/");
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (local_1bc,local_1a0);
    }
    if (DAT_00a11794 != -1) {
      basic_string<>(&DAT_007cd6c8);
      pcVar2 = (char *)FUN_00401c50();
      _sprintf(local_1a0,pcVar2);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                (local_1bc,local_1a0);
    }
    basic_string<>(&DAT_007cd6d0);
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_1a0,pcVar2);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (local_1bc,local_1a0);
    FUN_004cb880();
    local_8 = CONCAT31(local_8._1_3_,2);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
               local_1bc);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a164c4,
               "\r\n");
    FUN_004177c0();
    while( true ) {
      FUN_0052ece0();
      iVar1 = FUN_0052ece0();
      if (iVar1 != 0) break;
      FUN_0042c8b0();
      if ((DAT_00a14670 != '\0') || (DAT_00a1461d != '\0')) {
LAB_0042c547:
        FUN_00536900();
        local_8._0_1_ = 1;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
        local_8 = (uint)local_8._1_3_ << 8;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000020);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack0000003c);
        ExceptionList = local_10;
        return;
      }
      if ((DAT_00a1466c == '\0') && (DAT_00a1461a == '\0')) {
        local_24 = 0;
      }
      else {
        local_24 = local_24 + 1;
        if (10 < local_24) goto LAB_0042c547;
      }
      FUN_0052eb30();
    }
    DAT_00a1434c = 5000000;
    DAT_00a13fa0 = 0xffffffff;
    local_8._0_1_ = 1;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000020);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack0000003c);
  }
  else {
    DAT_00a1434c = 5000000;
    DAT_00a13fa0 = 0xffffffff;
    local_8._0_1_ = 1;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000020);
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack0000003c);
  }
  ExceptionList = local_10;
  return;
}

