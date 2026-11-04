
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x004ac675) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1
FUN_004ab7b0(int param_1,char param_2,char param_3,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_4)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_12640 [24];
  undefined4 uStack_12628;
  undefined1 auStack_12624 [9956];
  undefined4 uStack_ff40;
  char *pcStack_ff3c;
  undefined4 uStack_ff24;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_ff1c [12];
  undefined4 uStack_ff10;
  undefined *puStack_ff0c;
  int iStack_ff08;
  undefined1 *puStack_ff04;
  char *pcStack_ff00;
  undefined4 uStack_fefc;
  int iStack_fef8;
  undefined1 local_fe06;
  undefined1 local_fded;
  undefined1 local_d692;
  undefined1 local_d691;
  undefined1 local_af3e;
  undefined1 local_af3d;
  undefined1 local_87e5;
  CMiniDockFrameWnd local_7c40 [448];
  undefined1 local_7a80 [10080];
  undefined1 *local_5320;
  undefined1 *local_531c;
  undefined1 local_2bab;
  undefined1 local_2baa;
  undefined1 local_2ba9;
  char local_468 [260];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_364 [28];
  char local_348 [256];
  char local_248 [260];
  char local_144;
  char local_143;
  char local_142;
  char local_140 [256];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_40 [28];
  undefined4 local_24;
  char local_1d;
  char local_1c;
  char local_1b;
  char local_1a;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_007afefc;
  local_10 = ExceptionList;
  local_14 = 0x4ab7d2;
  local_24 = DAT_0084b484;
  local_8 = 0;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_40,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)&DAT_00a14b78);
  local_8._0_1_ = 1;
  if (param_1 < 1) {
    if (param_1 == 0) {
      FUN_004cbb30();
      _sprintf(local_140,"%s");
    }
  }
  else {
    FUN_004cbb30();
    iStack_fef8 = 0x4ab81d;
    _sprintf(local_140,"%s%.2i.sav");
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_40,local_140);
  if ((param_2 == '\0') && (param_3 == '\0')) {
    pcVar2 = (char *)FUN_004d39f0();
    if (*pcVar2 == '\x01') {
      local_2ba9 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_40);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4);
      ExceptionList = local_10;
      return local_2ba9;
    }
    pcVar2 = (char *)FUN_004d39f0();
    if (*pcVar2 == '\x01') {
      local_2baa = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_40);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4);
      ExceptionList = local_10;
      return local_2baa;
    }
  }
  FUN_004cb840();
  DAT_00a117e4 = '\0';
  FUN_004cbb30();
  local_14 = FUN_0052e3c0();
  if (local_14 == 0) {
    puVar3 = (undefined1 *)FUN_004d39f0();
    *puVar3 = 1;
    local_2bab = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_40
              );
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4);
  }
  else {
    puVar3 = (undefined1 *)FUN_004d39f0();
    *puVar3 = 0;
    if (param_2 != '\0') {
      FUN_004d2e70();
      FUN_004d2ab0();
    }
    FUN_004ce060();
    FUN_004d3930();
    cVar1 = const_iterator__operator__();
    if (cVar1 != '\0') {
      local_531c = auStack_12624;
      uStack_12628 = 0x4ab9fd;
      FUN_004a66a0();
      local_8._0_1_ = 2;
      local_5320 = abStack_12640;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (abStack_12640,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_40);
      local_8._0_1_ = 1;
      FUN_004ec9b0(local_7a80);
      local_8._0_1_ = 3;
      FUN_004eca20();
      local_8._0_1_ = 4;
      FUN_004d3720();
      local_8._0_1_ = 3;
      FUN_004b3650();
      local_8._0_1_ = 1;
      FUN_004b3650();
    }
    FUN_004d3570();
    FUN_00447960();
    FUN_00436790();
    local_8._0_1_ = 5;
    FUN_004d3570();
    FUN_004ab5b0();
    local_8._0_1_ = 1;
    FUN_004a68c0();
    FUN_004441f0();
    local_8._0_1_ = 6;
    FUN_004d3570();
    FUN_004736a0();
    local_8._0_1_ = 1;
    CMiniDockFrameWnd::~CMiniDockFrameWnd(local_7c40);
    FUN_00471bd0();
    local_8._0_1_ = 7;
    FUN_004d3570();
    FUN_00472eb0();
    local_8._0_1_ = 1;
    FUN_004a6aa0();
    FUN_004d3570();
    FUN_00472b10();
    FUN_004718a0();
    local_8._0_1_ = 8;
    FUN_004d3570();
    FUN_00472740();
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00484b30();
    iVar4 = FUN_004d3570();
    *(undefined4 *)(iVar4 + 0x2228) = 0;
    DAT_00a117e4 = '\0';
    DAT_00a0f820 = 0;
    if (DAT_00a117e8 == 0) {
      FUN_004cbb30();
      sVar5 = FUN_0052c9a0();
      DAT_00a0f824 = _malloc(sVar5);
      FUN_004cbb30();
      sVar5 = FUN_0052c9a0();
      _memset(DAT_00a0f824,0,sVar5);
    }
    FUN_004cbb30();
    DAT_00a0f828 = FUN_0052c9a0();
    local_18 = DAT_00a0f828;
    FUN_0052cde0();
    thunk_FUN_00580b80();
    DAT_00a0f820 = DAT_00a0f820 + 0x14;
    local_1c = *DAT_00a0f824;
    local_1b = DAT_00a0f824[3];
    local_1a = DAT_00a0f824[9];
    local_144 = DAT_00a0f824[2];
    local_143 = DAT_00a0f824[6];
    local_142 = DAT_00a0f824[8];
    iStack_fef8 = local_18;
    uStack_fefc = 0x14;
    pcStack_ff00 = DAT_00a0f824;
    uStack_ff24 = 0x4abd74;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (abStack_ff1c,
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_40);
    FUN_0041b9e0();
    if (DAT_00a0f828 < DAT_00a0f820 + 1) {
      DAT_00a117e4 = '\x01';
      local_87e5 = 0;
      local_8 = local_8 & 0xffffff00;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_40);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4);
      local_2bab = local_87e5;
    }
    else {
      DAT_00a0f844 = 1;
      _memcpy(&local_1d,DAT_00a0f824 + DAT_00a0f820,1);
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      if (local_1d == '\x19') {
        cVar1 = FUN_004b2e70();
        if (cVar1 == '\0') {
          local_af3e = 0;
          local_8 = local_8 & 0xffffff00;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_40);
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4);
          local_2bab = local_af3e;
        }
        else {
          FUN_004d3570();
          FUN_004ac750();
          if ((DAT_00a117e4 == '\0') && (DAT_00a0f828 + -200 <= DAT_00a0f820)) {
            if (DAT_00a0f828 < DAT_00a0f820 + 1) {
              DAT_00a117e4 = '\x01';
              local_d692 = 0;
              local_8 = local_8 & 0xffffff00;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                        ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          *)local_40);
              local_8 = 0xffffffff;
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4);
              local_2bab = local_d692;
            }
            else {
              DAT_00a0f844 = 1;
              _memcpy(&local_1d,DAT_00a0f824 + DAT_00a0f820,1);
              DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
              if (local_1d == '\x19') {
                iVar4 = FUN_004d3570();
                iVar6 = FUN_004d3570();
                *(int *)(iVar6 + 0x2458) = iVar4 + 0x1918;
                iVar4 = FUN_004d3570();
                *(undefined4 *)(iVar4 + 0x2228) = 1;
                puVar3 = (undefined1 *)FUN_004d39f0();
                *puVar3 = 1;
                if (((local_1c != '\0') || (local_1b != '\0')) || (local_1a != '\0')) {
                  iStack_fef8 = DAT_00a0f820;
                  uStack_fefc = 0x14;
                  pcStack_ff00 = DAT_00a0f824;
                  uStack_ff24 = 0x4ac4c6;
                  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                  basic_string<char,std::char_traits<char>,std::allocator<char>_>
                            (abStack_ff1c,
                             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                              *)local_40);
                  FUN_0041b9e0();
                }
                if (DAT_00a117e8 == 0) {
                  DAT_00a0f820 = 0;
                  _free(DAT_00a0f824);
                }
                if (param_3 == '\0') {
                  if (param_2 != '\0') {
                    iVar4 = FUN_00477850();
                    if (iVar4 == 0) {
                      puStack_ff04 = &DAT_007d0621;
                      iStack_ff08 = 0x4ac570;
                      basic_string<>();
                      local_8._0_1_ = 0x13;
                      uStack_ff24 = 0x4ac597;
                      FUN_00438b60();
                      local_8._0_1_ = 0x14;
                      pcStack_ff3c = &DAT_007d1568;
                      uStack_ff40 = 0x4ac5c5;
                      basic_string<>();
                      pcStack_ff3c = (char *)0x4ac5d0;
                      pcStack_ff3c = (char *)FUN_00401c50();
                      uStack_ff40 = 0x4ac5f0;
                      basic_string<>();
                      local_8._0_1_ = 1;
                      pcStack_ff3c = (char *)0x4ac5ff;
                      FUN_0042bed0();
                      local_8 = (uint)local_8._1_3_ << 8;
                      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ::~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  *)local_40);
                      local_8 = 0xffffffff;
                      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ::~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                (&param_4);
                      ExceptionList = local_10;
                      return 0;
                    }
                    if (param_2 != '\0') {
                      _DAT_00a18ac0 = param_1;
                    }
                    FUN_004d3570();
                    FUN_004b3710();
                    local_8._0_1_ = 0x15;
                    FUN_004b2e30();
                    local_8 = CONCAT31(local_8._1_3_,1);
                    FUN_004b34a0();
                  }
                }
                else {
                  DAT_00a13fa0 = 0;
                  DAT_00a117ac = 1;
                  DAT_00a117ad = 0;
                  FUN_004d3570();
                  FUN_004b36a0();
                }
                local_fe06 = 1;
                local_8 = local_8 & 0xffffff00;
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            *)local_40);
                local_8 = 0xffffffff;
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4)
                ;
                local_2bab = local_fe06;
              }
              else {
                FUN_004a66a0();
                local_8._0_1_ = 0x10;
                FUN_004d3570();
                FUN_004b35a0();
                local_8._0_1_ = 1;
                FUN_004b34a0();
                puStack_ff04 = &DAT_007d0621;
                iStack_ff08 = 0x4ac2e2;
                basic_string<>();
                puStack_ff04 = &DAT_0089544c;
                iStack_ff08 = param_1;
                puStack_ff0c = (undefined *)0x4ac2fc;
                FUN_004b3280();
                puStack_ff0c = &DAT_007d15c0;
                uStack_ff10 = 0x4ac322;
                basic_string<>();
                puStack_ff0c = (undefined *)0x4ac32d;
                pcVar2 = (char *)FUN_00401c50();
                iStack_fef8 = 0x4ac349;
                _sprintf(local_468,pcVar2);
                puStack_ff04 = &DAT_007d0621;
                iStack_ff08 = 0x4ac361;
                basic_string<>();
                local_8._0_1_ = 0x11;
                uStack_ff24 = 0x4ac38c;
                basic_string<>();
                local_8._0_1_ = 0x12;
                pcStack_ff3c = local_468;
                uStack_ff40 = 0x4ac3b9;
                basic_string<>();
                local_8 = CONCAT31(local_8._1_3_,1);
                pcStack_ff3c = (char *)0x4ac3c8;
                FUN_0042bed0();
                if (DAT_00a117e8 == 0) {
                  DAT_00a0f820 = 0;
                  _free(DAT_00a0f824);
                }
                local_fded = 0;
                local_8 = local_8 & 0xffffff00;
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            *)local_40);
                local_8 = 0xffffffff;
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4)
                ;
                local_2bab = local_fded;
              }
            }
          }
          else {
            FUN_004a66a0();
            local_8._0_1_ = 0xc;
            FUN_004d3570();
            FUN_004b35a0();
            local_8._0_1_ = 1;
            FUN_004b34a0();
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
            basic_string<char,std::char_traits<char>,std::allocator<char>_>
                      (local_364,
                       (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_40);
            local_8 = CONCAT31(local_8._1_3_,0xd);
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                      (local_364,".broken");
            while( true ) {
              FUN_004cbb30();
              FUN_004cbb30();
              iVar4 = FUN_004fd645();
              if (iVar4 == 0) break;
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                        (local_364,"x");
            }
            puStack_ff04 = &DAT_007d15c0;
            iStack_ff08 = 0x4ac0e7;
            basic_string<>();
            puStack_ff04 = (undefined1 *)0x4ac0f2;
            pcVar2 = (char *)FUN_00401c50();
            _sprintf(local_348,pcVar2);
            puStack_ff04 = &DAT_007d0621;
            iStack_ff08 = 0x4ac126;
            basic_string<>();
            local_8._0_1_ = 0xe;
            puStack_ff04 = (undefined1 *)0x4ac144;
            FUN_004cbb30();
            uStack_ff24 = 0x4ac155;
            basic_string<>();
            local_8._0_1_ = 0xf;
            pcStack_ff3c = local_348;
            uStack_ff40 = 0x4ac182;
            basic_string<>();
            local_8 = CONCAT31(local_8._1_3_,0xd);
            pcStack_ff3c = (char *)0x4ac191;
            FUN_0042bed0();
            if (DAT_00a117e8 == 0) {
              DAT_00a0f820 = 0;
              _free(DAT_00a0f824);
            }
            local_d691 = 0;
            local_8._0_1_ = 1;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       local_364);
            local_8 = (uint)local_8._1_3_ << 8;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                       local_40);
            local_8 = 0xffffffff;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4);
            local_2bab = local_d691;
          }
        }
      }
      else {
        FUN_004a66a0();
        local_8._0_1_ = 9;
        FUN_004d3570();
        FUN_004b35a0();
        local_8._0_1_ = 1;
        FUN_004b34a0();
        puStack_ff04 = &DAT_007d0621;
        iStack_ff08 = 0x4abe74;
        basic_string<>();
        puStack_ff04 = &DAT_0089544c;
        iStack_ff08 = param_1;
        puStack_ff0c = (undefined *)0x4abe8e;
        FUN_004b3280();
        puStack_ff0c = &DAT_007d15c0;
        uStack_ff10 = 0x4abeb4;
        basic_string<>();
        puStack_ff0c = (undefined *)0x4abebf;
        pcVar2 = (char *)FUN_00401c50();
        iStack_fef8 = 0x4abedb;
        _sprintf(local_248,pcVar2);
        puStack_ff04 = &DAT_007d0621;
        iStack_ff08 = 0x4abef3;
        basic_string<>();
        local_8._0_1_ = 10;
        uStack_ff24 = 0x4abf1e;
        basic_string<>();
        local_8._0_1_ = 0xb;
        pcStack_ff3c = local_248;
        uStack_ff40 = 0x4abf4b;
        basic_string<>();
        local_8 = CONCAT31(local_8._1_3_,1);
        pcStack_ff3c = (char *)0x4abf5a;
        FUN_0042bed0();
        if (DAT_00a117e8 == 0) {
          DAT_00a0f820 = 0;
          _free(DAT_00a0f824);
        }
        local_af3d = 0;
        local_8 = local_8 & 0xffffff00;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_40);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_4);
        local_2bab = local_af3d;
      }
    }
  }
  ExceptionList = local_10;
  return local_2bab;
}

