
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_00449500(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined1 auStack_404 [52];
  undefined4 uStack_3d0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_3cc;
  undefined4 uStack_3c8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_3c4;
  undefined *puStack_3c0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_378 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_35c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_340 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_324 [28];
  CDHtmlElementEventSink local_308 [20];
  undefined1 *local_2f4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_84 [28];
  uint local_68;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_64 [28];
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_34 [28];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad7d7;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x1658) = param_2;
  puStack_3c0 = (undefined *)0x449548;
  basic_string<>();
  local_8 = 0;
  puStack_3c0 = (undefined *)0x0;
  pbStack_3c4 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                 (param_1 + 0x1658);
  uStack_3c8 = 0;
  pbStack_3cc = local_84;
  uStack_3d0 = 0x449570;
  FUN_0046ff30();
  local_8._0_1_ = 1;
  puStack_3c0 = (undefined *)0x449595;
  FUN_004cb840();
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_84);
  FUN_004cbb30();
  puStack_3c0 = (undefined *)0x4495bb;
  cVar1 = FUN_004180d0();
  if (cVar1 == '\0') {
    DAT_00a13fa0 = 0xffffffff;
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
  }
  else {
    puStack_3c0 = (undefined *)0x4495fe;
    FUN_004d0b90();
    puStack_3c0 = (undefined *)0x44960a;
    FUN_004743a0();
    puStack_3c0 = (undefined *)0x449625;
    FUN_004cb840();
    for (local_3c = 0; local_3c < 0xf; local_3c = local_3c + 1) {
      puStack_3c0 = (undefined *)0x449669;
      FUN_004cb840();
    }
    puStack_3c0 = (undefined *)0x449689;
    FUN_004f09c0();
    puStack_3c0 = (undefined *)0x4496a6;
    FUN_004f09c0();
    puStack_3c0 = (undefined *)0x4496c4;
    FUN_004cd5b0();
    *(undefined4 *)(param_1 + 0x165c) = 0;
    *(undefined4 *)(param_1 + 0x1660) = 0;
    *(undefined1 *)(param_1 + 0x183c) = 0;
    FUN_004d2ab0();
    local_40 = 0;
    while( true ) {
      iVar2 = FUN_004cf550();
      if (iVar2 <= local_40) break;
      puStack_3c0 = (undefined *)0x449743;
      uVar3 = FUN_004cf5e0();
      local_2f4 = auStack_404;
      FUN_0047a2f0(uVar3);
      FUN_00446ca0(*(undefined4 *)(param_1 + 0x1658));
      local_8._0_1_ = 2;
      puStack_3c0 = (undefined *)0x4497a0;
      FUN_004d2a40();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0047a350();
      local_40 = local_40 + 1;
    }
    cVar1 = FUN_004d2da0();
    if (cVar1 != '\0') {
      FUN_004d2e70();
      local_44 = 0;
      while( true ) {
        iVar2 = FUN_004cfab0();
        if (iVar2 <= local_44) break;
        puStack_3c0 = (undefined *)0x449814;
        iVar2 = FUN_004cfb40();
        if ((*(byte *)(iVar2 + 0x20) & 0xf) == 2) {
LAB_0044983a:
          puStack_3c0 = (undefined *)0x449849;
          FUN_0047a0b0();
          local_8._0_1_ = 3;
          puStack_3c0 = (undefined *)0x449877;
          FUN_004d2e00();
          local_8 = (uint)local_8._1_3_ << 8;
          CDHtmlElementEventSink::~CDHtmlElementEventSink(local_308);
        }
        else {
          puStack_3c0 = (undefined *)0x44982e;
          iVar2 = FUN_004cfb40();
          if ((*(byte *)(iVar2 + 0x20) & 0xf) == 3) goto LAB_0044983a;
        }
        local_44 = local_44 + 1;
      }
    }
    *(undefined4 *)(param_1 + 0x1664) = 0;
    *(undefined4 *)(param_1 + 0x1668) = 0;
    *(undefined4 *)(param_1 + 0x166c) = 0;
    *(undefined4 *)(param_1 + 0x1670) = 0;
    *(undefined4 *)(param_1 + 0x1674) = 4;
    *(undefined4 *)(param_1 + 0x1678) = 4;
    local_38 = 0;
    puStack_3c0 = (undefined *)0x4498fe;
    iVar2 = FUN_00477980();
    if (4 < iVar2) {
      puStack_3c0 = (undefined *)0x4;
      pbStack_3c4 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                     (param_1 + 0x1658);
      uStack_3c8 = 0;
      pbStack_3cc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x449924;
      local_38 = FUN_0046f7f0();
      if (local_38 < -1) {
        puStack_3c0 = (undefined *)0x4;
        pbStack_3c4 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **
                       )(param_1 + 0x1658);
        uStack_3c8 = 0;
        pbStack_3cc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x449958;
        iVar2 = FUN_0046f7f0();
        if (iVar2 == -3) {
          puStack_3c0 = (undefined *)0x44996d;
          iVar2 = FUN_00477980();
          if (7 < iVar2) {
            puStack_3c0 = (undefined *)0x7;
            pbStack_3c4 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            **)(param_1 + 0x1658);
            uStack_3c8 = 0;
            pbStack_3cc = local_64;
            uStack_3d0 = 0x449997;
            FUN_0046ff30();
            local_8._0_1_ = 4;
            local_68 = 0;
            local_48 = 0;
            while( true ) {
              puStack_3c0 = &DAT_007ceb18;
              pbStack_3c4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x4499b8;
              local_68 = FUN_004cbbc0();
              if (local_68 == DAT_007d0624) break;
              puStack_3c0 = (undefined *)0x1;
              uStack_3c8 = 0x4499d9;
              pbStack_3c4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)local_68;
              FUN_004cba30();
            }
            cVar1 = FUN_004cbb70();
            if (cVar1 == '\0') {
              puStack_3c0 = &DAT_007ceb1c;
              pbStack_3c4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x4499fd;
              local_68 = FUN_004cbbc0();
              puStack_3c0 = (undefined *)0x0;
              pbStack_3c4 = local_324;
              uStack_3c8 = 0x449a15;
              FUN_004cbc20();
              local_8._0_1_ = 5;
              puStack_3c0 = (undefined *)0x449a3c;
              FUN_004cb840();
              local_8._0_1_ = 4;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_324);
              puStack_3c0 = &DAT_007ceb20;
              pbStack_3c4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x449a5f;
              local_48 = FUN_004cbbc0();
              puStack_3c0 = (undefined *)(((int)local_68 < 0) - 1 & local_68);
              pbStack_3c4 = local_340;
              uStack_3c8 = 0x449a83;
              FUN_004cbc20();
              local_8._0_1_ = 6;
              pcVar4 = (char *)FUN_004cbb30();
              puStack_3c0 = (undefined *)0x449aaa;
              DAT_00a18a98 = _atol(pcVar4);
              local_8._0_1_ = 4;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_340);
              puStack_3c0 = &DAT_007ceb24;
              pbStack_3c4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x449ad5;
              local_68 = FUN_004cbbc0();
              puStack_3c0 = (undefined *)(((int)local_48 < 0) - 1 & local_48);
              pbStack_3c4 = local_35c;
              uStack_3c8 = 0x449af9;
              FUN_004cbc20();
              local_8._0_1_ = 7;
              pcVar4 = (char *)FUN_004cbb30();
              puStack_3c0 = (undefined *)0x449b20;
              DAT_00a18a9c = _atol(pcVar4);
              local_8._0_1_ = 4;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_35c);
              puStack_3c0 = &DAT_007ceb28;
              pbStack_3c4 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)0x449b4b;
              local_48 = FUN_004cbbc0();
              puStack_3c0 = (undefined *)(((int)local_68 < 0) - 1 & local_68);
              pbStack_3c4 = local_378;
              uStack_3c8 = 0x449b6f;
              FUN_004cbc20();
              local_8._0_1_ = 8;
              pcVar4 = (char *)FUN_004cbb30();
              puStack_3c0 = (undefined *)0x449b96;
              DAT_00a18b24 = _atol(pcVar4);
              local_8._0_1_ = 4;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_378);
            }
            else {
              puStack_3c0 = (undefined *)0x449bbe;
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                        ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                         &DAT_00a18be4,"");
              DAT_00a18a98 = 0;
              DAT_00a18a9c = 0;
              DAT_00a18b24 = 0;
            }
            DAT_00a14340 = 1;
            cVar1 = FUN_004cbb70();
            if (cVar1 != '\0') {
              DAT_00a14340 = 0;
              DAT_00a18a94 = -1;
            }
            local_8 = (uint)local_8._1_3_ << 8;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_64);
          }
        }
      }
      else {
        DAT_00a18a94 = local_38;
      }
    }
    *(undefined1 *)(param_1 + 0x1895) = 0;
    *(undefined1 *)(param_1 + 0x1894) = 0;
    puStack_3c0 = (undefined *)0x3;
    pbStack_3c4 = *(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> **)
                   (param_1 + 0x1658);
    uStack_3c8 = 0;
    pbStack_3cc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x449c48;
    local_14 = FUN_0046f7f0();
    if (local_14 == 1) {
      *(undefined1 *)(param_1 + 0x1894) = 1;
    }
    else if (local_14 == 2) {
      *(undefined1 *)(param_1 + 0x1895) = 1;
    }
    else if (local_14 == 3) {
      *(undefined1 *)(param_1 + 0x1894) = 1;
      *(undefined1 *)(param_1 + 0x1895) = 1;
    }
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
  }
  ExceptionList = local_10;
  return;
}

