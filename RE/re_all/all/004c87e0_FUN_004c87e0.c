
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004c87e0(undefined4 *param_1)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  char *pcVar4;
  long lVar5;
  undefined4 *puVar6;
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
  DAT_00a14340 = 0;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  local_3c = FUN_004cbbc0();
  if (local_3c == DAT_007d0624) {
    local_55c = (undefined1 *)&uStack_670;
    uStack_678 = 0x4c8d65;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_670,
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_00a18be4);
    uStack_678 = 0x4c8d77;
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
                         *)&DAT_00a18be4);
    local_8._0_1_ = 1;
    while (local_14 = FUN_004cbbc0(), local_14 != -1) {
      FUN_004cba30();
    }
    local_3c = FUN_004cbbc0();
    local_45c = (undefined1 *)&uStack_670;
    puStack_67c = (undefined1 *)&uStack_670;
    uStack_678 = 0;
    FUN_004cbc20();
    uStack_678 = 0x4c88cb;
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
      pcVar4 = (char *)FUN_004cbb30();
      DAT_00a18a98 = _atol(pcVar4);
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_558);
    }
    else {
      FUN_004cbc20();
      local_8._0_1_ = 3;
      pcVar4 = (char *)FUN_004cbb30();
      DAT_00a18a98 = _atol(pcVar4);
      local_8._0_1_ = 1;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_494);
      local_14 = local_3c;
      local_3c = FUN_004cbbc0();
      if (local_3c == DAT_007d0624) {
        FUN_004e5650();
        FUN_004cbc20();
        local_8._0_1_ = 9;
        pcVar4 = (char *)FUN_004cbb30();
        DAT_00a18a9c = _atol(pcVar4);
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_53c);
      }
      else {
        FUN_004cbc20();
        local_8._0_1_ = 4;
        pcVar4 = (char *)FUN_004cbb30();
        DAT_00a18a9c = _atol(pcVar4);
        local_8._0_1_ = 1;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4b0);
        local_14 = local_3c;
        FUN_004e5650();
        FUN_004cbc20();
        local_8._0_1_ = 5;
        pcVar4 = (char *)FUN_004cbb30();
        lVar5 = _atol(pcVar4);
        bVar1 = -1000 < lVar5;
        if (bVar1) {
          FUN_004e5650();
          FUN_004cbc20();
          local_8._0_1_ = 6;
          pcVar4 = (char *)FUN_004cbb30();
          local_5d0 = _atol(pcVar4);
        }
        else {
          local_5d0 = -999;
        }
        if (local_5d0 < 1000) {
          FUN_004e5650();
          FUN_004cbc20();
          local_8 = 7;
          bVar2 = 2;
          pcVar4 = (char *)FUN_004cbb30();
          lVar5 = _atol(pcVar4);
          if (lVar5 < -999) {
            local_5e8 = -999;
          }
          else {
            FUN_004e5650();
            FUN_004cbc20();
            local_8 = 8;
            bVar2 = 6;
            pcVar4 = (char *)FUN_004cbb30();
            local_5e8 = _atol(pcVar4);
          }
          local_5dc = local_5e8;
        }
        else {
          local_5dc = 999;
          bVar2 = bVar1;
        }
        DAT_00a18b24 = local_5dc;
        local_8 = 7;
        if ((bVar2 & 4) != 0) {
          bVar2 = bVar2 & 0xfb;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_520);
        }
        local_8 = 6;
        if ((bVar2 & 2) != 0) {
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
  cVar3 = operator!=<>();
  if (cVar3 == '\0') {
    DAT_00a18a94 = 0xffffffff;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_34
              );
  }
  else {
    puStack_684 = (undefined *)0x4c8de4;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&puStack_67c,
               local_34);
    cVar3 = FUN_00422450();
    if (cVar3 == '\0') {
      uStack_678 = 0x4c8e1c;
      basic_string<>();
      pcVar4 = (char *)FUN_00401c50();
      _sprintf(local_258,pcVar4);
      uStack_678 = 0x4c8e5b;
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
      puVar6 = (undefined4 *)FUN_004cc680();
      param_1[1] = *puVar6;
      FUN_004cde80();
      FUN_004ce990();
      FUN_00515880();
      if (((int)param_1[6] < (int)*DAT_00a16718) || ((int)param_1[7] < (int)*DAT_00a1671c)) {
        puStack_684 = &DAT_007d1fe8;
        uStack_688 = 0x4c8fa0;
        basic_string<>();
        puStack_684 = (undefined *)0x4c8fab;
        pcVar4 = (char *)FUN_00401c50();
        uStack_670 = 0x4c8fc7;
        _sprintf(local_458,pcVar4);
        uStack_678 = 0x4c8fdf;
        basic_string<>();
        FUN_00401c50();
        uStack_678 = 0x4c900a;
        basic_string<>();
        local_8._0_1_ = 0xe;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_68c,local_34);
        local_8._0_1_ = 0xf;
        basic_string<>(local_458);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0042bed0();
      }
      param_1[8] = 0;
      param_1[9] = 0;
      param_1[0xb] = 0;
      param_1[10] = 0;
      DAT_00a18a94 = 0xfffffffe;
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

