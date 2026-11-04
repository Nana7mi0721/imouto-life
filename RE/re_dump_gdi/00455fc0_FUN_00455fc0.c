
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 __fastcall FUN_00455fc0(int param_1)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  size_t _Size;
  void *_Str;
  LPCSTR pCVar5;
  BOOL BVar6;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar7;
  undefined4 *puVar8;
  char *pcVar9;
  uint uVar10;
  bool bVar11;
  undefined1 auStack_924 [16];
  undefined4 uStack_914;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_908 [2];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_906 [10];
  undefined4 uStack_8fc;
  undefined1 *puStack_8f8;
  int iStack_8f4;
  undefined4 uStack_8ec;
  undefined4 uStack_8e8;
  undefined1 *puStack_8e4;
  size_t _Count;
  char *_Mode;
  FILE *_File;
  int local_75c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *local_73c;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *local_720;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *local_704;
  undefined4 local_6cc;
  undefined4 local_6c8;
  int local_6c4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_674 [28];
  undefined1 *local_658;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_654 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_638 [28];
  undefined1 *local_61c;
  undefined1 *local_618;
  undefined1 *local_614;
  undefined1 *local_610;
  undefined1 *local_60c;
  undefined1 *local_608;
  undefined1 local_601;
  undefined1 *local_600;
  undefined1 *local_5fc;
  undefined1 *local_5f8;
  undefined1 *local_5f4;
  undefined1 *local_5f0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_5ec [28];
  undefined1 *local_5d0;
  undefined1 local_5c9;
  undefined1 *local_5c8;
  undefined1 *local_5c4;
  undefined1 *local_5c0;
  undefined1 *local_5bc;
  undefined1 *local_5b8;
  undefined1 *local_5b4;
  undefined1 local_5ad;
  undefined1 *local_5ac;
  undefined1 *local_5a8;
  undefined1 *local_5a4;
  undefined1 *local_5a0;
  undefined1 local_59c [16];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_58c [28];
  undefined1 *local_570;
  undefined1 *local_56c;
  undefined1 *local_568;
  undefined1 local_561;
  undefined1 *local_560;
  undefined1 *local_55c;
  undefined1 *local_558;
  undefined1 *local_554;
  undefined1 *local_550;
  undefined1 local_549;
  undefined1 *local_548;
  undefined1 *local_544;
  undefined1 *local_540;
  undefined1 *local_53c;
  undefined1 local_535;
  undefined1 *local_534;
  undefined1 *local_530;
  undefined1 *local_52c;
  undefined1 *local_528;
  undefined1 *local_524;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_520 [28];
  undefined1 *local_504;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_500 [28];
  undefined1 *local_4e4;
  undefined1 *local_4e0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_4dc [31];
  char local_4bd;
  undefined1 *local_4bc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_4b8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_49c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_480 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *local_464;
  undefined1 *local_460;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_45c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_440 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *local_424;
  undefined1 *local_420;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_41c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_400 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *local_3e4;
  undefined1 *local_3e0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3dc [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3c0 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_3a4 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_388 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_36c [31];
  undefined1 local_34d;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_34c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_330 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_314 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2f8 [28];
  undefined1 *local_2dc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2d8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2bc [28];
  int local_2a0;
  int local_29c;
  int local_298;
  int local_294;
  int local_290;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_28c [28];
  int local_270;
  HANDLE local_26c;
  _WIN32_FIND_DATAA local_268;
  int local_124;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_120 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_104 [31];
  char local_e5;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_e4 [28];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_c8 [28];
  FILE *local_ac;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_a8 [28];
  char *local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_74 [28];
  int local_58;
  undefined4 local_54;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_50 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_34 [28];
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ade02;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  basic_string<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  puVar2 = (uint *)FUN_004ce990();
  if ((((((*puVar2 & 0xf00) == 0x100) ||
        (puVar2 = (uint *)FUN_004ce990(), (*puVar2 & 0xf00) == 0x600)) ||
       (puVar2 = (uint *)FUN_004ce990(), (*puVar2 & 0xf00) == 0x800)) ||
      ((puVar2 = (uint *)FUN_004ce990(), (*puVar2 & 0xf00) == 0x900 ||
       (puVar2 = (uint *)FUN_004ce990(), (*puVar2 & 0xf00) == 0xa00)))) ||
     (puVar2 = (uint *)FUN_004ce990(), (*puVar2 & 0xf00) == 0xb00)) {
    puVar2 = (uint *)FUN_004ce990();
    if ((*puVar2 & 0x10) == 0) {
      FUN_004ce990();
      FUN_00487160();
      local_8._0_1_ = 2;
      FUN_004cb840();
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2bc);
    }
    else {
      puVar2 = (uint *)FUN_004ce990();
      if ((*puVar2 & 0x10) != 0) {
        FUN_004ce990();
        FUN_00487080();
        FUN_00487160();
        local_8._0_1_ = 3;
        FUN_004cb840();
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2d8);
      }
    }
  }
  puVar2 = (uint *)FUN_004ce990();
  switch(*puVar2 & 0xf) {
  case 0:
    puStack_8e4 = (undefined1 *)0x0;
    uStack_8e8 = *(undefined4 *)(param_1 + 0x10);
    uStack_8ec = *(undefined4 *)(param_1 + 0x18);
    iStack_8f4 = 0;
    puStack_8f8 = (undefined1 *)0x45626c;
    pbVar7 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             FUN_004cc4c0();
    local_2dc = abStack_908 + -4;
    uStack_914 = 0x45627d;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_908 + -4,pbVar7);
    uStack_914 = 0x45628f;
    FUN_00424670();
    local_8._0_1_ = 4;
    FUN_004cb840();
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2f8);
    break;
  case 1:
    FUN_004ce990();
    FUN_00487160();
    local_8._0_1_ = 5;
    FUN_004cb840();
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_314);
    break;
  case 2:
    FUN_004ce990();
    cVar1 = FUN_00438d40();
    if (cVar1 == '\0') {
      FUN_004ce990();
      FUN_00487160();
      local_8._0_1_ = 7;
      FUN_004cb840();
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34c);
    }
    else {
      FUN_004ce990();
      local_54 = FUN_00487080();
      FUN_00487160();
      local_8._0_1_ = 6;
      FUN_004cb840();
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_330);
    }
    break;
  case 3:
    if (DAT_00a14314 != 0) {
      local_34d = 0;
      local_8 = local_8 & 0xffffff00;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_50);
      ExceptionList = local_10;
      return local_34d;
    }
    DAT_00a14314 = 1;
    DAT_00a18ad0 = 1;
    FUN_00536900();
    if (*DAT_00a166ac == '\0') {
      FUN_00536af0();
    }
    else {
      FUN_00536af0();
    }
    FUN_00563b10();
    FUN_004ce990();
    iVar3 = FUN_00487080();
    if (iVar3 < 2) {
      local_6c4 = 2;
    }
    else {
      FUN_004ce990();
      local_6c4 = FUN_00487080();
    }
    if (local_6c4 < 0x1f5) {
      FUN_004ce990();
      iVar3 = FUN_00487080();
      if (iVar3 < 2) {
        local_6cc = 2;
      }
      else {
        FUN_004ce990();
        local_6cc = FUN_00487080();
      }
      local_6c8 = local_6cc;
    }
    else {
      local_6c8 = 500;
    }
    puStack_8e4 = (undefined1 *)0x2;
    uStack_8e8 = 0x4565b4;
    puVar2 = (uint *)FUN_004ce990();
    puStack_8e4 = (undefined1 *)(uint)((*puVar2 & 0x1000) != 0);
    uStack_8e8 = local_6c8;
    uStack_8ec = 0x4565cf;
    uVar4 = FUN_005673c0();
    *(undefined4 *)(param_1 + 0x85c) = uVar4;
    puVar2 = (uint *)FUN_004ce990();
    *(uint *)(param_1 + 0x880) = (uint)((*puVar2 & 0x1000) == 0);
    FUN_005674f0();
    puVar2 = (uint *)FUN_004ce990();
    if ((*puVar2 & 0x2000) != 0) {
      basic_string<>();
      local_8._0_1_ = 8;
      puVar2 = (uint *)FUN_004ce990();
      if ((*puVar2 & 0x10) == 0) {
        FUN_004ce990();
        FUN_00487160();
        local_8._0_1_ = 9;
        FUN_004cb840();
        local_8._0_1_ = 8;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_36c);
      }
      else {
        puVar2 = (uint *)FUN_004ce990();
        if ((*puVar2 & 0x10) != 0) {
          FUN_004ce990();
          FUN_00487080();
          FUN_00487160();
          local_8._0_1_ = 10;
          FUN_004cb840();
          local_8._0_1_ = 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_388);
        }
      }
      local_78 = 0;
      while (local_78 = FUN_004cbbc0(), local_78 != DAT_007d0624) {
        FUN_004cba30();
      }
      FUN_004ce990();
      local_58 = FUN_00487080();
      iVar3 = FUN_004e5650();
      if (local_58 < iVar3) {
        FUN_004cbb30();
        iVar3 = FUN_0046f680();
        if (iVar3 != 1) goto LAB_00456821;
        FUN_004cbc20();
        local_8._0_1_ = 0xb;
        FUN_004cb840();
        local_8 = CONCAT31(local_8._1_3_,8);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3a4);
      }
      else {
LAB_00456821:
        FUN_004cbc20();
        local_8._0_1_ = 0xc;
        FUN_004cb840();
        local_8 = CONCAT31(local_8._1_3_,8);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3c0);
      }
      FUN_004cbb30();
      FUN_00567080();
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_74);
    }
    puVar2 = (uint *)FUN_004ce990();
    if ((*puVar2 & 0x10) == 0) {
      puVar8 = (undefined4 *)FUN_004ce990();
      *(undefined4 *)(param_1 + 0x860) = *puVar8;
    }
    else {
      FUN_004ce990();
      uVar4 = FUN_00487080();
      *(undefined4 *)(param_1 + 0x860) = uVar4;
    }
    FUN_004cb840();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_50,"");
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_34,"");
  }
  puVar2 = (uint *)FUN_004ce990();
  uVar10 = *puVar2 & 0xf00;
  if (uVar10 < 0x701) {
    if (uVar10 == 0x700) {
      basic_string<>();
      local_8._0_1_ = 0x2c;
      local_e5 = '\x01';
      local_5d0 = (undefined1 *)&uStack_8ec;
      iStack_8f4 = 0x457b06;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_8ec,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_34);
      iStack_8f4 = 0x457b18;
      FUN_004293c0();
      local_8._0_1_ = 0x2d;
      FUN_004cb840();
      local_8._0_1_ = 0x2c;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_5ec);
      iVar3 = FUN_004cbbc0();
      if ((iVar3 != -1) || (iVar3 = FUN_004cbbc0(), iVar3 != -1)) {
        if (DAT_00a117a8 != 0) {
          local_5f0 = (undefined1 *)&uStack_8ec;
          iStack_8f4 = 0x457b99;
          FUN_00438b60();
          local_8._0_1_ = 0x2e;
          local_5f8 = abStack_908;
          basic_string<>();
          FUN_00401c50();
          local_5f4 = abStack_908;
          basic_string<>();
          local_8._0_1_ = 0x2f;
          local_600 = auStack_924;
          basic_string<>(&DAT_007cf238);
          uVar4 = FUN_00401c50();
          local_5fc = auStack_924;
          basic_string<>(uVar4);
          local_8._0_1_ = 0x2c;
          FUN_0042bed0();
        }
        local_601 = 1;
        local_8._0_1_ = 1;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_104);
        local_8 = (uint)local_8._1_3_ << 8;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_50);
        ExceptionList = local_10;
        return local_601;
      }
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (local_120,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_00a14b78);
      local_8._0_1_ = 0x30;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_120,"/")
      ;
      FUN_004cb880();
      iVar3 = FUN_004cbbc0();
      if (iVar3 == 0) {
        if (DAT_00a117a8 != 0) {
          local_608 = (undefined1 *)&uStack_8ec;
          iStack_8f4 = 0x457e5c;
          FUN_00438b60();
          local_8._0_1_ = 0x31;
          local_610 = abStack_908;
          basic_string<>();
          FUN_00401c50();
          local_60c = abStack_908;
          basic_string<>();
          local_8._0_1_ = 0x32;
          local_618 = auStack_924;
          basic_string<>(&DAT_007cf2d4);
          uVar4 = FUN_00401c50();
          local_614 = auStack_924;
          basic_string<>(uVar4);
          local_8._0_1_ = 0x30;
          FUN_0042bed0();
        }
      }
      else {
        local_124 = 0;
        while (local_124 = FUN_004cbbf0(), local_124 != -1) {
          FUN_004cba30();
        }
        pCVar5 = (LPCSTR)FUN_004cbb30();
        BVar6 = PathIsDirectoryA(pCVar5);
        if (BVar6 == 0) {
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_34,
                     "<<ERROR>>");
        }
        else {
          pCVar5 = (LPCSTR)FUN_004cbb30();
          SetCurrentDirectoryA(pCVar5);
          local_26c = FindFirstFileA("*",&local_268);
          if (local_26c != (HANDLE)0xffffffff) {
            do {
              if (local_e5 == '\0') {
                std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                          ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                           local_104,"\n");
              }
              iVar3 = _strcmp(local_268.cFileName,".");
              if ((iVar3 != 0) && (iVar3 = _strcmp(local_268.cFileName,".."), iVar3 != 0)) {
                std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                          ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                           local_104,local_268.cFileName);
                local_e5 = '\0';
              }
              BVar6 = FindNextFileA(local_26c,&local_268);
            } while (BVar6 != 0);
            FindClose(local_26c);
          }
          FUN_004cb840();
          pCVar5 = (LPCSTR)FUN_004cbb30();
          SetCurrentDirectoryA(pCVar5);
        }
      }
      local_8._0_1_ = 0x2c;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_120);
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_104);
    }
    else if (uVar10 < 0x401) {
      if (uVar10 == 0x400) {
        FUN_004cbb30();
        local_80 = FUN_0046f680();
        local_80 = local_80 + 1;
        pcVar9 = (char *)FUN_004cbb30();
        if (*pcVar9 == '\x01') {
          iVar3 = FUN_004cbb30();
          local_80 = *(char *)(iVar3 + 1) + 1;
        }
        iVar3 = FUN_004e5650();
        if (local_80 < iVar3) {
          local_75c = local_80;
        }
        else {
          local_75c = FUN_004e5650();
        }
        local_80 = local_75c;
        puVar2 = (uint *)FUN_004ce990();
        if ((*puVar2 & 0xf) == 1) {
          FUN_004e5650();
          local_4bc = (undefined1 *)&uStack_8ec;
          puStack_8f8 = (undefined1 *)&uStack_8ec;
          iStack_8f4 = local_80;
          uStack_8fc = 0x457033;
          FUN_004cbc20();
          local_8._0_1_ = 0x18;
          iStack_8f4 = 0x45705c;
          FUN_004ce990();
          local_8 = CONCAT31(local_8._1_3_,1);
          iStack_8f4 = 0x45706e;
          FUN_00486bf0();
        }
        puVar2 = (uint *)FUN_004ce990();
        if ((*puVar2 & 0xf) == 2) {
          FUN_004ce990();
          FUN_00487160();
          local_8._0_1_ = 0x19;
          local_4bd = FUN_004ec750();
          local_8._0_1_ = 1;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4dc);
          if (local_4bd == '\0') {
            FUN_004e5650();
            local_4e4 = (undefined1 *)&uStack_8ec;
            puStack_8f8 = (undefined1 *)&uStack_8ec;
            iStack_8f4 = local_80;
            uStack_8fc = 0x45718e;
            FUN_004cbc20();
            local_8._0_1_ = 0x1b;
            iStack_8f4 = 0x4571b7;
            FUN_004ce990();
            local_8 = CONCAT31(local_8._1_3_,1);
            iStack_8f4 = 0x4571c9;
            FUN_00486bf0();
          }
          else {
            FUN_004e5650();
            local_4e0 = (undefined1 *)&uStack_8ec;
            puStack_8f8 = (undefined1 *)&uStack_8ec;
            iStack_8f4 = local_80;
            uStack_8fc = 0x457124;
            FUN_004cbc20();
            local_8._0_1_ = 0x1a;
            iStack_8f4 = 0x45714d;
            FUN_004ce990();
            iStack_8f4 = 0x45715b;
            FUN_00487080();
            local_8 = CONCAT31(local_8._1_3_,1);
            iStack_8f4 = 0x45716b;
            FUN_00486bf0();
          }
        }
        FUN_004cbc20();
        local_8._0_1_ = 0x1c;
        FUN_004cb840();
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_500);
      }
      else if ((uVar10 == 0x200) || (uVar10 == 0x300)) {
        local_7c = 0;
        while (local_7c = FUN_004cbbc0(), local_7c != -1) {
          FUN_004cba30();
        }
        basic_string<>();
        local_8._0_1_ = 0xd;
        local_7c = FUN_00419790();
        local_8._0_1_ = 1;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_3dc);
        puVar2 = (uint *)FUN_004ce990();
        if ((*puVar2 & 0xf00) == 0x300) {
          puVar2 = (uint *)FUN_004ce990();
          if ((*puVar2 & 0xf) == 1) {
            bVar11 = local_7c == -1;
            if (bVar11) {
              local_704 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)basic_string<>();
              local_8 = 0xf;
            }
            else {
              FUN_004e5650();
              local_704 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)FUN_004cbc20();
              local_8 = CONCAT31(local_8._1_3_,0xe);
            }
            local_3e4 = local_704;
            local_3e0 = (undefined1 *)&uStack_8ec;
            iStack_8f4 = 0x456bae;
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
            basic_string<char,std::char_traits<char>,std::allocator<char>_>
                      ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                       &uStack_8ec,local_704);
            local_8 = 0x10;
            iStack_8f4 = 0x456bda;
            FUN_004ce990();
            local_8 = CONCAT31(local_8._1_3_,0xf);
            iStack_8f4 = 0x456bec;
            FUN_00486bf0();
            local_8 = 0xe;
            if (bVar11) {
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_41c);
            }
            local_8._0_1_ = 1;
            local_8._1_3_ = 0;
            if (!bVar11) {
              std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
              ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_400);
            }
          }
          puVar2 = (uint *)FUN_004ce990();
          if ((*puVar2 & 0xf) == 2) {
            FUN_004ce990();
            cVar1 = FUN_00438d40();
            if (cVar1 == '\0') {
              bVar11 = local_7c == -1;
              if (bVar11) {
                local_73c = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                             *)basic_string<>();
                local_8 = 0x15;
              }
              else {
                FUN_004e5650();
                local_73c = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                             *)FUN_004cbc20();
                local_8 = CONCAT31(local_8._1_3_,0x14);
              }
              local_464 = local_73c;
              local_460 = (undefined1 *)&uStack_8ec;
              iStack_8f4 = 0x456e95;
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
              basic_string<char,std::char_traits<char>,std::allocator<char>_>
                        ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                         &uStack_8ec,local_73c);
              local_8 = 0x16;
              iStack_8f4 = 0x456ec1;
              FUN_004ce990();
              local_8 = CONCAT31(local_8._1_3_,0x15);
              iStack_8f4 = 0x456ed3;
              FUN_00486bf0();
              local_8 = 0x14;
              if (bVar11) {
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          (local_49c);
              }
              local_8._0_1_ = 1;
              local_8._1_3_ = 0;
              if (!bVar11) {
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          (local_480);
              }
            }
            else {
              bVar11 = local_7c == -1;
              if (bVar11) {
                local_720 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                             *)basic_string<>();
                local_8 = 0x12;
              }
              else {
                FUN_004e5650();
                local_720 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                             *)FUN_004cbc20();
                local_8 = CONCAT31(local_8._1_3_,0x11);
              }
              local_424 = local_720;
              local_420 = (undefined1 *)&uStack_8ec;
              iStack_8f4 = 0x456d3f;
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
              basic_string<char,std::char_traits<char>,std::allocator<char>_>
                        ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                         &uStack_8ec,local_720);
              local_8 = 0x13;
              iStack_8f4 = 0x456d6b;
              FUN_004ce990();
              iStack_8f4 = 0x456d79;
              FUN_00487080();
              local_8 = CONCAT31(local_8._1_3_,0x12);
              iStack_8f4 = 0x456d89;
              FUN_00486bf0();
              local_8 = 0x11;
              if (bVar11) {
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          (local_45c);
              }
              local_8._0_1_ = 1;
              local_8._1_3_ = 0;
              if (!bVar11) {
                std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          (local_440);
              }
            }
          }
        }
        if (local_7c == -1) {
          FUN_004e5650();
        }
        FUN_004cbc20();
        local_8._0_1_ = 0x17;
        FUN_004cb840();
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4b8);
      }
    }
    else if (uVar10 == 0x500) {
      local_504 = (undefined1 *)&uStack_8ec;
      iStack_8f4 = 0x45722b;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_8ec,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_34);
      iStack_8f4 = 0x45723d;
      FUN_004293c0();
      local_8._0_1_ = 0x1d;
      FUN_004cb840();
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_520);
      iVar3 = FUN_004cbbc0();
      if ((iVar3 != -1) || (iVar3 = FUN_004cbbc0(), iVar3 != -1)) {
        if (DAT_00a117a8 != 0) {
          local_524 = (undefined1 *)&uStack_8ec;
          iStack_8f4 = 0x4572be;
          FUN_00438b60();
          local_8._0_1_ = 0x1e;
          local_52c = abStack_908;
          basic_string<>();
          FUN_00401c50();
          local_528 = abStack_908;
          basic_string<>();
          local_8._0_1_ = 0x1f;
          local_534 = auStack_924;
          basic_string<>(&DAT_007cefc8);
          uVar4 = FUN_00401c50();
          local_530 = auStack_924;
          basic_string<>(uVar4);
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_0042bed0();
        }
        local_535 = 1;
        local_8 = local_8 & 0xffffff00;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_50);
        ExceptionList = local_10;
        return local_535;
      }
      FUN_004cbb30();
      local_84 = FUN_0052e3c0();
      if (local_84 == 0) {
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_34,
                   "<NoFile>");
      }
      else {
        FUN_004cbb30();
        local_88 = FUN_0052c9a0();
        local_8c = _malloc(local_88 + 1);
        _memset(local_8c,0,local_88 + 1);
        FUN_0052cde0();
        thunk_FUN_00580b80();
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_34,
                   local_8c);
        _free(local_8c);
      }
    }
    else if (uVar10 == 0x600) {
      if ((DAT_00a117a8 != 0) && (cVar1 = FUN_004ec750(), cVar1 != '\0')) {
        local_53c = (undefined1 *)&uStack_8ec;
        iStack_8f4 = 0x4574ac;
        basic_string<>();
        local_8._0_1_ = 0x20;
        local_540 = abStack_908;
        FUN_00438b60();
        local_8._0_1_ = 0x21;
        local_548 = auStack_924;
        basic_string<>(&DAT_007cf020);
        uVar4 = FUN_00401c50();
        local_544 = auStack_924;
        basic_string<>(uVar4);
        local_8._0_1_ = 1;
        FUN_0042bed0();
        local_549 = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_50);
        ExceptionList = local_10;
        return local_549;
      }
      iVar3 = FUN_004cbbc0();
      if ((iVar3 != -1) || (iVar3 = FUN_004cbbc0(), iVar3 != -1)) {
        if (DAT_00a117a8 != 0) {
          local_550 = (undefined1 *)&uStack_8ec;
          iStack_8f4 = 0x4575b5;
          FUN_00438b60();
          local_8._0_1_ = 0x22;
          local_558 = abStack_908;
          basic_string<>();
          FUN_00401c50();
          local_554 = abStack_908;
          basic_string<>();
          local_8._0_1_ = 0x23;
          local_560 = auStack_924;
          basic_string<>(&DAT_007cf0b0);
          uVar4 = FUN_00401c50();
          local_55c = auStack_924;
          basic_string<>(uVar4);
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_0042bed0();
        }
        local_561 = 1;
        local_8 = local_8 & 0xffffff00;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_50);
        ExceptionList = local_10;
        return local_561;
      }
      local_568 = (undefined1 *)&uStack_8ec;
      iStack_8f4 = 0x4576b7;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_8ec,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 local_34);
      iStack_8f4 = 0x4576c9;
      FUN_004293c0();
      local_8._0_1_ = 0x24;
      local_56c = (undefined1 *)&uStack_8ec;
      iStack_8f4 = 0x4576eb;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_8ec,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_00a14b78);
      local_8._0_1_ = 0x25;
      local_570 = abStack_908;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_908,local_a8);
      local_8._0_1_ = 0x24;
      FUN_0041a1d0();
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58c);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_c8,local_a8);
      local_8 = CONCAT31(local_8._1_3_,0x26);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin(local_c8);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::end(local_c8);
      puStack_8e4 = (undefined1 *)0x457799;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::begin(local_c8);
      puStack_8e4 = local_59c;
      uStack_8e8 = 0x4577a8;
      FUN_004ecad0();
      iVar3 = FUN_004cbbc0();
      if (((iVar3 != DAT_007d0624) || (iVar3 = FUN_004cbbc0(), iVar3 != DAT_007d0624)) &&
         ((iVar3 = FUN_004cbbc0(), iVar3 != DAT_007d0624 ||
          (iVar3 = FUN_004cbbc0(), iVar3 != DAT_007d0624)))) {
        local_5a0 = (undefined1 *)&uStack_8ec;
        iStack_8f4 = 0x45782c;
        FUN_00438b60();
        local_8._0_1_ = 0x27;
        FUN_004cbb30();
        local_5a4 = abStack_908;
        basic_string<>();
        local_8._0_1_ = 0x28;
        local_5ac = auStack_924;
        basic_string<>(&DAT_007cf128);
        uVar4 = FUN_00401c50();
        local_5a8 = auStack_924;
        basic_string<>(uVar4);
        local_8._0_1_ = 0x26;
        FUN_0042bed0();
        local_5ad = 1;
        local_8._0_1_ = 0x24;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_c8);
        local_8._0_1_ = 1;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_a8);
        local_8 = (uint)local_8._1_3_ << 8;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_50);
        ExceptionList = local_10;
        return local_5ad;
      }
      _Mode = "w";
      pcVar9 = (char *)FUN_004cbb30();
      local_ac = _fopen(pcVar9,_Mode);
      if (local_ac == (FILE *)0x0) {
        local_5b4 = (undefined1 *)&uStack_8ec;
        iStack_8f4 = 0x457957;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_8ec,
                   local_a8);
        local_8._0_1_ = 0x29;
        local_5bc = abStack_908;
        basic_string<>();
        FUN_00401c50();
        local_5b8 = abStack_908;
        basic_string<>();
        local_8._0_1_ = 0x2a;
        local_5c4 = auStack_924;
        basic_string<>(&DAT_007cf1cc);
        uVar4 = FUN_00401c50();
        local_5c0 = auStack_924;
        basic_string<>(uVar4);
        local_8 = CONCAT31(local_8._1_3_,0x26);
        FUN_0042bed0();
      }
      else {
        local_5c8 = (undefined1 *)&uStack_8ec;
        iStack_8f4 = 0x457a2b;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_8ec,
                   (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   local_50);
        iStack_8f4 = 0x457a3d;
        FUN_004293c0();
        local_8._0_1_ = 0x2b;
        _Count = 1;
        _File = local_ac;
        _Size = FUN_004e5650();
        _Str = (void *)FUN_004cbb30();
        puStack_8e4 = (undefined1 *)0x457a70;
        _fwrite(_Str,_Size,_Count,_File);
        _fclose(local_ac);
        local_8 = CONCAT31(local_8._1_3_,0x26);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_e4);
      }
      local_5c9 = 1;
      local_8._0_1_ = 0x24;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_c8);
      local_8._0_1_ = 1;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_a8);
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_50);
      ExceptionList = local_10;
      return local_5c9;
    }
  }
  else if (uVar10 < 0xa01) {
    if (uVar10 == 0xa00) {
      local_298 = 0;
      local_294 = 1;
      while (local_298 = FUN_004cbbc0(), local_298 != -1) {
        FUN_004cba30();
      }
      local_298 = 0;
      local_298 = FUN_00419790();
      if (local_298 != DAT_007d0624) {
        FUN_004cbc20();
        local_8._0_1_ = 0x34;
        FUN_004cb840();
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_638);
        local_294 = 0;
      }
      if (local_294 != 0) {
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_50,
                   "<<NotFound>>");
      }
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_34,"");
    }
    else if (uVar10 == 0x800) {
      local_270 = 0;
      while (local_270 = FUN_00419790(), local_270 != DAT_007d0624) {
        FUN_004e5650();
        FUN_004cba30();
      }
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_34,"");
    }
    else if ((uVar10 == 0x900) && (puVar2 = (uint *)FUN_004ce990(), (*puVar2 & 0xf00) == 0x900)) {
      local_290 = 0;
      puStack_8e4 = (undefined1 *)0x0;
      uStack_8e8 = *(undefined4 *)(param_1 + 0x10);
      uStack_8ec = *(undefined4 *)(param_1 + 0x18);
      iStack_8f4 = 1;
      puStack_8f8 = (undefined1 *)0x458010;
      pbVar7 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004cc4c0();
      local_61c = abStack_908 + -4;
      uStack_914 = 0x458021;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_908 + -4,pbVar7);
      uStack_914 = 0x458033;
      FUN_00424670();
      local_8._0_1_ = 0x33;
      while (local_290 = FUN_00419790(), local_290 != DAT_007d0624) {
        FUN_004cbb30();
        FUN_004e5650();
        FUN_004cba30();
        iVar3 = FUN_004e5650();
        local_290 = iVar3 + local_290;
      }
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_34,"");
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_28c);
    }
  }
  else if (uVar10 == 0xb00) {
    local_2a0 = 0;
    local_29c = 1;
    while (local_2a0 = FUN_004cbbc0(), local_2a0 != -1) {
      FUN_004cba30();
    }
    local_2a0 = 0;
    local_2a0 = FUN_00419790();
    if (local_2a0 != DAT_007d0624) {
      FUN_004e5650();
      FUN_004e5650();
      FUN_004cbc20();
      local_8._0_1_ = 0x35;
      FUN_004cb840();
      local_8 = CONCAT31(local_8._1_3_,1);
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_654);
      local_29c = 0;
    }
    if (local_29c != 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_50,
                 "<<NotFound>>");
    }
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_34,"");
  }
  puStack_8e4 = (undefined1 *)0x0;
  uStack_8e8 = *(undefined4 *)(param_1 + 0x10);
  uStack_8ec = *(undefined4 *)(param_1 + 0x18);
  local_658 = abStack_908 + -4;
  uStack_914 = 0x458305;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (abStack_908 + -4,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             local_34);
  uStack_914 = 0x458317;
  FUN_00424670();
  local_8._0_1_ = 0x36;
  FUN_004cb840();
  local_8 = CONCAT31(local_8._1_3_,1);
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_674);
  FUN_004cb880();
  local_14 = 0;
  puVar2 = (uint *)FUN_004ce990();
  if ((*puVar2 & 0x10) == 0) {
    puVar8 = (undefined4 *)FUN_004ce990();
    local_14 = *puVar8;
  }
  else {
    FUN_004ce990();
    local_14 = FUN_00487080();
  }
  cVar1 = FUN_00438d40();
  if (cVar1 == '\0') {
    iStack_8f4 = 0x458405;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_8ec,
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_50);
    iStack_8f4 = 0x45841a;
    FUN_00486bf0();
  }
  else {
    pcVar9 = (char *)FUN_004cbb30();
    _atol(pcVar9);
    FUN_00486e50();
  }
  local_8 = local_8 & 0xffffff00;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_34);
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_50);
  ExceptionList = local_10;
  return 1;
}

