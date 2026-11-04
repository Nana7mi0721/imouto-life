
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004ca0a0(undefined4 *param_1)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  long lVar4;
  undefined4 *puVar5;
  byte bVar6;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_68c [4];
  undefined4 uStack_688;
  undefined *puStack_684;
  undefined1 *puStack_67c;
  undefined4 uStack_678;
  undefined4 uStack_670;
  long local_5e8;
  long local_5dc;
  int local_5d0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_578 [28];
  undefined1 *local_55c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_558 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_53c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_520 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_504 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_4e8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_4cc [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_4b0 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_494 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_478 [28];
  undefined1 *local_45c;
  char local_458 [512];
  char local_258 [512];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_58 [28];
  int local_3c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_34 [28];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0e2f;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  DAT_00a14341 = 0;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  local_3c = FUN_004cbbc0();
  if (local_3c == DAT_007d0624) {
    local_55c = (undefined1 *)&uStack_670;
    uStack_678 = 0x4ca5e7;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_670,
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_00a18c00);
    uStack_678 = 0x4ca5f9;
    FUN_004293c0();
    local_8._0_1_ = 0xb;
    FUN_004cb840();
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_578);
  }
  else {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (local_58,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                         *)&DAT_00a18c00);
    local_8._0_1_ = 1;
    local_45c = (undefined1 *)&uStack_670;
    puStack_67c = (undefined1 *)&uStack_670;
    uStack_678 = 0;
    FUN_004cbc20();
    uStack_678 = 0x4ca14c;
    FUN_004293c0();
    local_8._0_1_ = 2;
    FUN_004cb840();
    local_8._0_1_ = 1;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_478);
    FUN_004cb840();
    local_14 = local_3c;
    local_3c = FUN_004cbbc0();
    if (local_3c == DAT_007d0624) {
      FUN_004e5650();
      FUN_004cbc20();
      local_8._0_1_ = 10;
      pcVar3 = (char *)FUN_004cbb30();
      DAT_00a18aa4 = _atol(pcVar3);
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_558);
    }
    else {
      FUN_004cbc20();
      local_8._0_1_ = 3;
      pcVar3 = (char *)FUN_004cbb30();
      DAT_00a18aa4 = _atol(pcVar3);
      local_8._0_1_ = 1;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_494);
      local_14 = local_3c;
      local_3c = FUN_004cbbc0();
      if (local_3c == DAT_007d0624) {
        FUN_004e5650();
        FUN_004cbc20();
        local_8._0_1_ = 9;
        pcVar3 = (char *)FUN_004cbb30();
        DAT_00a18aa8 = _atol(pcVar3);
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_53c);
      }
      else {
        FUN_004cbc20();
        local_8._0_1_ = 4;
        pcVar3 = (char *)FUN_004cbb30();
        DAT_00a18aa8 = _atol(pcVar3);
        local_8._0_1_ = 1;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4b0);
        local_14 = local_3c;
        FUN_004e5650();
        FUN_004cbc20();
        local_8._0_1_ = 5;
        pcVar3 = (char *)FUN_004cbb30();
        lVar4 = _atol(pcVar3);
        bVar1 = -1000 < lVar4;
        if (bVar1) {
          FUN_004e5650();
          FUN_004cbc20();
          local_8._0_1_ = 6;
          pcVar3 = (char *)FUN_004cbb30();
          local_5d0 = _atol(pcVar3);
        }
        else {
          local_5d0 = -999;
        }
        if (local_5d0 < 1000) {
          FUN_004e5650();
          FUN_004cbc20();
          local_8 = 7;
          bVar6 = 2;
          pcVar3 = (char *)FUN_004cbb30();
          lVar4 = _atol(pcVar3);
          if (lVar4 < -999) {
            local_5e8 = -999;
          }
          else {
            FUN_004e5650();
            FUN_004cbc20();
            local_8 = 8;
            bVar6 = 6;
            pcVar3 = (char *)FUN_004cbb30();
            local_5e8 = _atol(pcVar3);
          }
          local_5dc = local_5e8;
        }
        else {
          local_5dc = 999;
          bVar6 = bVar1;
        }
        DAT_00a18b28 = local_5dc;
        local_8 = 7;
        if ((bVar6 & 4) != 0) {
          bVar6 = bVar6 & 0xfb;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_520);
        }
        local_8 = 6;
        if ((bVar6 & 2) != 0) {
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_504);
        }
        local_8 = 5;
        if (bVar1) {
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4e8);
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4cc);
      }
    }
    local_8 = local_8 & 0xffffff00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_58
              );
  }
  cVar2 = operator!=<>();
  if (cVar2 == '\0') {
    DAT_00a18aa0 = 0xffffffff;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_34
              );
  }
  else {
    puStack_684 = (undefined *)0x4ca666;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_67c,
               local_34);
    cVar2 = FUN_00422450();
    if (cVar2 == '\0') {
      uStack_678 = 0x4ca69e;
      basic_string<>();
      pcVar3 = (char *)FUN_00401c50();
      _sprintf(local_258,pcVar3);
      uStack_678 = 0x4ca6dd;
      basic_string<>();
      local_8._0_1_ = 0xc;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_68c,local_34);
      local_8._0_1_ = 0xd;
      basic_string<>(local_258);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0042bed0();
      param_1[1] = 0xffffffff;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_34);
    }
    else {
      puVar5 = (undefined4 *)FUN_004cc680();
      param_1[1] = *puVar5;
      FUN_004cde80();
      FUN_004ce990();
      FUN_00515880();
      if (((int)param_1[6] < (int)*DAT_00a16718) || ((int)param_1[7] < (int)*DAT_00a1671c)) {
        puStack_684 = &DAT_007d20b0;
        uStack_688 = 0x4ca822;
        basic_string<>();
        puStack_684 = (undefined *)0x4ca82d;
        pcVar3 = (char *)FUN_00401c50();
        uStack_670 = 0x4ca849;
        _sprintf(local_458,pcVar3);
        uStack_678 = 0x4ca861;
        basic_string<>();
        FUN_00401c50();
        uStack_678 = 0x4ca88c;
        basic_string<>();
        local_8._0_1_ = 0xe;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_68c,local_34);
        local_8._0_1_ = 0xf;
        basic_string<>(local_458);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0042bed0();
      }
      param_1[10] = 0;
      param_1[0xb] = 0;
      param_1[9] = 0;
      param_1[8] = 0;
      DAT_00a18aa0 = 0xfffffffe;
      *param_1 = 0xfffffffe;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_34);
    }
  }
  ExceptionList = local_10;
  return;
}

