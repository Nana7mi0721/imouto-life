
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_00465d90(void)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar6;
  undefined1 auStack_a04 [20];
  undefined4 uStack_9f0;
  undefined *puStack_9ec;
  undefined1 auStack_9e8 [20];
  undefined4 uStack_9d4;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_9cc [12];
  undefined4 uStack_9c0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_9bc;
  undefined *puStack_9b8;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbStack_9b4;
  undefined4 local_9b0;
  undefined4 local_9ac;
  undefined4 local_9a8;
  undefined4 local_9a4;
  undefined4 local_9a0;
  undefined4 local_99c;
  undefined4 local_998;
  undefined4 local_994;
  undefined4 local_990;
  undefined4 local_98c;
  undefined4 local_988;
  undefined4 local_984;
  undefined4 local_980;
  undefined4 local_97c;
  undefined4 local_978;
  undefined4 local_974;
  undefined4 local_970;
  undefined4 local_96c;
  undefined4 local_968;
  undefined4 local_964;
  undefined4 local_960;
  undefined4 local_95c;
  undefined4 local_958;
  undefined4 local_954;
  undefined4 local_950;
  undefined4 local_94c;
  undefined4 local_948;
  undefined4 local_944;
  undefined4 local_940;
  undefined4 local_93c;
  undefined4 local_938;
  undefined4 local_934;
  undefined4 local_930;
  undefined4 local_92c;
  undefined4 local_928;
  undefined4 local_924;
  undefined4 local_920;
  undefined1 local_915;
  undefined1 *local_914;
  undefined1 *local_910;
  undefined1 *local_90c;
  undefined1 *local_908;
  undefined1 *local_904;
  undefined1 local_8fd;
  undefined1 *local_8fc;
  undefined1 *local_8f8;
  undefined1 *local_8f4;
  undefined1 *local_8f0;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_8ec [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_8d0 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_8b4 [31];
  char local_895;
  undefined1 *local_894;
  undefined1 *local_890;
  undefined1 *local_88c;
  undefined1 *local_888;
  undefined1 *local_884;
  undefined1 *local_880;
  undefined1 *local_87c;
  undefined1 *local_878;
  undefined1 *local_874;
  undefined1 *local_870;
  undefined1 *local_86c;
  int local_868;
  int local_864;
  int local_860;
  int local_85c;
  int local_858;
  int local_854;
  undefined1 local_84d;
  int local_84c;
  int local_848;
  int local_844;
  int local_840;
  int local_83c;
  int local_838;
  int local_834;
  undefined *local_830;
  int aiStack_82c [511];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae468;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  local_830 = &DAT_00a14438;
  ExceptionList = &local_10;
  for (local_834 = 0; local_834 < DAT_0084b21c; local_834 = local_834 + 1) {
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  local_834;
    puStack_9b8 = (undefined *)0x465e00;
    iVar2 = FUN_004d2620();
    aiStack_82c[local_834] = iVar2;
    *(undefined2 *)(aiStack_82c[local_834] + 0xbc) = 0xffff;
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x0;
    puStack_9b8 = (undefined *)0x465e3d;
    puVar3 = (undefined1 *)FUN_004cd7c0();
    *puVar3 = DAT_00a18ab4;
  }
  pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x1;
  puStack_9b8 = (undefined *)0x465e5a;
  FUN_004ce990();
  pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x1;
  puStack_9b8 = (undefined *)0x465e78;
  puVar4 = (uint *)FUN_004ce990();
  if ((*puVar4 & 0xf) < 3) {
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x2;
    puStack_9b8 = (undefined *)0x465e99;
    puVar5 = (undefined4 *)FUN_004ce990();
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  *puVar5;
    puStack_9b8 = (undefined *)0x465ea7;
    iVar2 = FUN_00487080();
    if (iVar2 + -1 < 0) {
      local_86c = abStack_9cc;
      uStack_9d4 = 0x465ec1;
      local_924 = FUN_00438b60();
      local_8 = 0;
      local_874 = auStack_9e8;
      puStack_9ec = &DAT_007cfef8;
      uStack_9f0 = 0x465ef2;
      local_920 = local_924;
      local_928 = basic_string<>();
      puStack_9ec = (undefined *)0x465efd;
      puStack_9ec = (undefined *)FUN_00401c50();
      uStack_9f0 = 0x465f1d;
      local_92c = puStack_9ec;
      local_870 = auStack_9e8;
      local_934 = basic_string<>();
      local_8 = CONCAT31(local_8._1_3_,1);
      local_87c = auStack_a04;
      local_930 = local_934;
      local_938 = basic_string<>(&DAT_007cff24);
      local_93c = FUN_00401c50();
      local_878 = auStack_a04;
      local_940 = basic_string<>(local_93c);
      local_8 = 0xffffffff;
      FUN_0042bed0();
      ExceptionList = local_10;
      return 1;
    }
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x2;
    puStack_9b8 = (undefined *)0x465fa2;
    puVar5 = (undefined4 *)FUN_004ce990();
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  *puVar5;
    puStack_9b8 = (undefined *)0x465fb0;
    iVar2 = FUN_00487080();
    if (6 < iVar2) {
      local_880 = abStack_9cc;
      uStack_9d4 = 0x465fca;
      local_948 = FUN_00438b60();
      local_8 = 2;
      local_888 = auStack_9e8;
      puStack_9ec = &DAT_007cff58;
      uStack_9f0 = 0x465ffb;
      local_944 = local_948;
      local_94c = basic_string<>();
      puStack_9ec = (undefined *)0x466006;
      puStack_9ec = (undefined *)FUN_00401c50();
      uStack_9f0 = 0x466026;
      local_950 = puStack_9ec;
      local_884 = auStack_9e8;
      local_958 = basic_string<>();
      local_8 = CONCAT31(local_8._1_3_,3);
      local_890 = auStack_a04;
      local_954 = local_958;
      local_95c = basic_string<>(&DAT_007cff84);
      local_960 = FUN_00401c50();
      local_88c = auStack_a04;
      local_964 = basic_string<>(local_960);
      local_8 = 0xffffffff;
      FUN_0042bed0();
      ExceptionList = local_10;
      return 1;
    }
  }
  pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x1;
  puStack_9b8 = (undefined *)0x4660ab;
  puVar4 = (uint *)FUN_004ce990();
  if ((*puVar4 & 0xf) == 0) {
    local_894 = abStack_9cc;
    uStack_9d4 = 0x4660c7;
    local_96c = basic_string<>();
    local_8 = 4;
    uStack_9d4 = 0x4660f3;
    local_968 = local_96c;
    FUN_004ce990();
    uStack_9d4 = 0x466101;
    FUN_00487080();
    local_8 = 0xffffffff;
    FUN_004787b0();
  }
  pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                0x46611c;
  basic_string<>();
  local_8 = 5;
  pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x1;
  puStack_9b8 = (undefined *)0x466136;
  puVar4 = (uint *)FUN_004ce990();
  if ((*puVar4 & 0xf) != 0) {
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x1;
    puStack_9b8 = (undefined *)0x466157;
    puVar4 = (uint *)FUN_004ce990();
    if ((*puVar4 & 0xf) < 4) {
      pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                    0x1;
      puStack_9b8 = (undefined *)0x466178;
      puVar4 = (uint *)FUN_004ce990();
      if ((*puVar4 & 0x100) == 0) {
        pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)0x0;
        puStack_9b8 = (undefined *)0x466198;
        pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)FUN_004cc4c0();
        puStack_9b8 = (undefined *)0x4661a1;
        FUN_004cb840();
      }
      else {
        pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)0x1;
        puStack_9b8 = (undefined *)0x4661b9;
        puVar4 = (uint *)FUN_004ce990();
        if ((*puVar4 & 0x100) != 0) {
          pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                         *)0x0;
          puStack_9b8 = (undefined *)0x3;
          pbStack_9bc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x4661dc;
          puVar5 = (undefined4 *)FUN_004ce990();
          puStack_9b8 = (undefined *)*puVar5;
          pbStack_9bc = local_8b4;
          uStack_9c0 = 0x4661f1;
          puStack_9b8 = (undefined *)FUN_00487160();
          local_8._0_1_ = 6;
          pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                         *)0x7cffbc;
          pbStack_9bc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *
                        )0x466218;
          local_974 = puStack_9b8;
          local_970 = puStack_9b8;
          local_895 = FUN_004ec750();
          local_8._0_1_ = 5;
          pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                         *)0x466230;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_8b4);
          if (local_895 == '\0') {
            pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)0x0;
            puStack_9b8 = (undefined *)0x3;
            pbStack_9bc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x4662bc;
            puVar5 = (undefined4 *)FUN_004ce990();
            puStack_9b8 = (undefined *)*puVar5;
            pbStack_9bc = local_8ec;
            uStack_9c0 = 0x4662d1;
            pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)FUN_00487160();
            local_8._0_1_ = 8;
            puStack_9b8 = (undefined *)0x4662f6;
            local_984 = pbStack_9b4;
            local_980 = pbStack_9b4;
            FUN_004cb840();
            local_8 = CONCAT31(local_8._1_3_,5);
            pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)0x466305;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_8ec);
          }
          else {
            pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)0x0;
            puStack_9b8 = (undefined *)0x3;
            pbStack_9bc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x466250;
            puVar5 = (undefined4 *)FUN_004ce990();
            puStack_9b8 = (undefined *)*puVar5;
            pbStack_9bc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x46625e;
            puStack_9b8 = (undefined *)FUN_00487080();
            pbStack_9bc = local_8d0;
            uStack_9c0 = 0x466271;
            pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)FUN_00487160();
            local_8._0_1_ = 7;
            puStack_9b8 = (undefined *)0x466296;
            local_97c = pbStack_9b4;
            local_978 = pbStack_9b4;
            FUN_004cb840();
            local_8 = CONCAT31(local_8._1_3_,5);
            pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                           *)0x4662a5;
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_8d0);
          }
        }
      }
      local_838 = 0;
      while( true ) {
        pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)0x0;
        puStack_9b8 = &DAT_007cffc8;
        pbStack_9bc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x46631e;
        pbStack_9bc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      FUN_004cbbc0();
        local_838 = (int)pbStack_9bc;
        if (pbStack_9bc ==
            (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)0xffffffff)
        break;
        pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)&DAT_007cffcc;
        puStack_9b8 = (undefined *)0x3;
        uStack_9c0 = 0x466343;
        FUN_004cba30();
      }
      while( true ) {
        pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)0x0;
        puStack_9b8 = &DAT_007cffd0;
        pbStack_9bc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x466354;
        local_838 = FUN_004cbbc0();
        if (local_838 == -1) break;
        pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)&DAT_007cffd4;
        puStack_9b8 = (undefined *)0x2;
        uStack_9c0 = 0x466379;
        pbStack_9bc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      local_838;
        FUN_004cba30();
      }
    }
  }
  pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x1;
  puStack_9b8 = (undefined *)0x46638e;
  puVar4 = (uint *)FUN_004ce990();
  if ((*puVar4 & 0xf) == 1) {
    local_83c = DAT_0084b21c;
    while( true ) {
      pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                    0x2;
      puStack_9b8 = (undefined *)0x4663cc;
      puVar5 = (undefined4 *)FUN_004ce990();
      pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                    *puVar5;
      puStack_9b8 = (undefined *)0x4663da;
      iVar2 = FUN_00487080();
      if (local_83c < iVar2) break;
      local_8f0 = abStack_9cc;
      uStack_9d4 = 0x466403;
      local_988 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                  basic_string<char,std::char_traits<char>,std::allocator<char>_>
                            (abStack_9cc,
                             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                              *)((&local_834)[local_83c] + 8));
      FUN_004787b0();
      local_83c = local_83c + -1;
    }
    local_8f4 = abStack_9cc;
    uStack_9d4 = 0x466431;
    local_990 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                basic_string<char,std::char_traits<char>,std::allocator<char>_>
                          (abStack_9cc,local_30);
    local_8._0_1_ = 9;
    uStack_9d4 = 0x46645a;
    local_98c = local_990;
    FUN_004ce990();
    uStack_9d4 = 0x466468;
    FUN_00487080();
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_004787b0();
  }
  pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x1;
  puStack_9b8 = (undefined *)0x46648b;
  puVar4 = (uint *)FUN_004ce990();
  if ((*puVar4 & 0xf) == 2) {
    local_8f8 = abStack_9cc;
    uStack_9d4 = 0x4664a9;
    local_998 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                basic_string<char,std::char_traits<char>,std::allocator<char>_>
                          (abStack_9cc,local_30);
    local_8._0_1_ = 10;
    uStack_9d4 = 0x4664d2;
    local_994 = local_998;
    FUN_004ce990();
    uStack_9d4 = 0x4664e0;
    FUN_00487080();
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_004787b0();
  }
  pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x1;
  puStack_9b8 = (undefined *)0x466503;
  puVar4 = (uint *)FUN_004ce990();
  if ((*puVar4 & 0xf) == 3) {
    for (local_840 = 0; local_840 < DAT_0084b21c + 1; local_840 = local_840 + 1) {
      pbStack_9b4 = local_30;
      puStack_9b8 = (undefined *)(aiStack_82c[local_840 + -1] + 8);
      pbStack_9bc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x466552;
      cVar1 = FUN_004ec8f0();
      if (cVar1 != '\0') {
        local_8fc = abStack_9cc;
        uStack_9d4 = 0x466571;
        local_99c = basic_string<>();
        FUN_004787b0();
      }
    }
  }
  pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x1;
  puStack_9b8 = (undefined *)0x46659e;
  puVar4 = (uint *)FUN_004ce990();
  if ((*puVar4 & 0xf) == 4) {
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x1;
    puStack_9b8 = (undefined *)0x4665bf;
    puVar4 = (uint *)FUN_004ce990();
    if ((*puVar4 & 0xf0) == 0) {
      local_84d = 0;
      local_84c = 0;
      for (local_854 = 0; local_854 <= DAT_0084b21c; local_854 = local_854 + 1) {
        pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)&DAT_007cffd7;
        puStack_9b8 = (undefined *)(aiStack_82c[local_854 + -1] + 8);
        pbStack_9bc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x466621;
        cVar1 = operator!=<>();
        if (cVar1 != '\0') {
          local_84c = local_84c + 1;
        }
      }
      if (local_84c < 1) {
        local_8fd = 1;
        local_8 = 0xffffffff;
        pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)0x46665b;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_30);
        ExceptionList = local_10;
        return local_8fd;
      }
      local_848 = 0;
      local_844 = -1;
      while (iVar2 = local_84c, local_848 < local_84c) {
        pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)&DAT_007cffd8;
        puStack_9b8 = (undefined *)(aiStack_82c[local_844] + 8);
        pbStack_9bc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4666b6;
        local_844 = local_844 + 1;
        cVar1 = operator!=<>();
        if (cVar1 != '\0') {
          local_904 = abStack_9cc;
          uStack_9d4 = 0x4666e3;
          local_9a0 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                (abStack_9cc,
                                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                                  *)(aiStack_82c[local_844 + -1] + 8));
          FUN_004787b0();
          local_848 = local_848 + 1;
        }
      }
      while (local_844 = iVar2 + 1, local_844 <= DAT_0084b21c) {
        local_908 = abStack_9cc;
        uStack_9d4 = 0x466752;
        local_9a4 = basic_string<>();
        FUN_004787b0();
        iVar2 = local_844;
      }
    }
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x1;
    puStack_9b8 = (undefined *)0x46677f;
    puVar4 = (uint *)FUN_004ce990();
    if ((*puVar4 & 0xf0) == 0x10) {
      for (local_858 = 0; local_858 < DAT_0084b21c + 1; local_858 = local_858 + 1) {
        local_90c = abStack_9cc;
        uStack_9d4 = 0x4667cc;
        local_9a8 = basic_string<>();
        FUN_004787b0();
      }
    }
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x1;
    puStack_9b8 = (undefined *)0x4667f9;
    puVar4 = (uint *)FUN_004ce990();
    if ((*puVar4 & 0xf0) == 0x20) {
      pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                    0x46680f;
      FUN_00446640();
    }
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x1;
    puStack_9b8 = (undefined *)0x466822;
    puVar4 = (uint *)FUN_004ce990();
    if ((*puVar4 & 0xf0) == 0x30) {
      DAT_00a14581 = 1;
      _DAT_00a14584 = 0;
    }
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x1;
    puStack_9b8 = (undefined *)0x466853;
    puVar4 = (uint *)FUN_004ce990();
    if ((*puVar4 & 0xf0) == 0x40) {
      DAT_00a14581 = 0;
      _DAT_00a14584 = 0;
    }
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x1;
    puStack_9b8 = (undefined *)0x466884;
    puVar4 = (uint *)FUN_004ce990();
    if ((*puVar4 & 0xf0) == 0x50) {
      for (local_85c = 0; local_85c < DAT_0084b21c + 1; local_85c = local_85c + 1) {
        *(undefined2 *)(aiStack_82c[local_85c + -1] + 0x44) = 0;
      }
    }
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x1;
    puStack_9b8 = (undefined *)0x4668e4;
    puVar4 = (uint *)FUN_004ce990();
    if ((*puVar4 & 0xf0) == 0x60) {
      for (local_860 = 0; local_860 < DAT_0084b21c + 1; local_860 = local_860 + 1) {
        *(undefined2 *)(aiStack_82c[local_860 + -1] + 0x44) = 0xff;
      }
    }
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x1;
    puStack_9b8 = (undefined *)0x466944;
    puVar4 = (uint *)FUN_004ce990();
    if ((*puVar4 & 0xf0) == 0x70) {
      pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                    (DAT_0084b21c + 1);
      puStack_9b8 = (undefined *)0x466964;
      FUN_004cc400();
      for (local_864 = 0; local_864 < DAT_0084b21c + 1; local_864 = local_864 + 1) {
        pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)(aiStack_82c[local_864 + -1] + 8);
        puStack_9b8 = (undefined *)local_864;
        pbStack_9bc = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4669b1;
        FUN_004cc4c0();
        puStack_9b8 = (undefined *)0x4669b8;
        FUN_004cb840();
      }
    }
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x1;
    puStack_9b8 = (undefined *)0x4669cd;
    puVar4 = (uint *)FUN_004ce990();
    if ((*puVar4 & 0xf0) == 0x80) {
      for (local_868 = 0; local_868 < DAT_0084b21c + 1; local_868 = local_868 + 1) {
        pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)0x466a1b;
        iVar2 = FUN_004cc430();
        if (local_868 < iVar2) {
          pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                         *)local_868;
          puStack_9b8 = (undefined *)0x466a34;
          pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   FUN_004cc4c0();
          local_910 = abStack_9cc;
          uStack_9d4 = 0x466a45;
          local_9ac = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
                      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                (abStack_9cc,pbVar6);
          FUN_004787b0();
        }
        else {
          local_914 = abStack_9cc;
          uStack_9d4 = 0x466a74;
          local_9b0 = basic_string<>();
          FUN_004787b0();
        }
      }
    }
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x1;
    puStack_9b8 = (undefined *)0x466aa4;
    puVar4 = (uint *)FUN_004ce990();
    if ((*puVar4 & 0xf0) == 0x90) {
      DAT_00a18c71 = 1;
    }
    pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                  0x1;
    puStack_9b8 = (undefined *)0x466acc;
    puVar4 = (uint *)FUN_004ce990();
    if ((*puVar4 & 0xf0) == 0xa0) {
      DAT_00a18c71 = 0;
    }
  }
  local_915 = 1;
  local_8 = 0xffffffff;
  pbStack_9b4 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                0x466af9;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_30);
  ExceptionList = local_10;
  return local_915;
}

