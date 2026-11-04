
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 __thiscall
FUN_004b6f20(char *param_1,char *param_2,char *param_3,char param_4,undefined4 param_5,int param_6)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  LPCSTR pCVar4;
  undefined4 uVar5;
  undefined *puStack_a14;
  undefined *puStack_a10;
  undefined1 auStack_a0c [12];
  undefined4 uStack_a00;
  LPSECURITY_ATTRIBUTES lpSecurityAttributes;
  undefined1 local_99d;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_99c [31];
  undefined1 local_97d;
  undefined1 *local_97c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_978 [31];
  undefined1 local_959;
  undefined1 *local_958;
  undefined1 *local_954;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_950 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_934 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_918 [28];
  undefined1 *local_8fc;
  int local_8f8;
  int local_8f4;
  int local_8f0;
  int local_8ec;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_8e8 [28];
  int local_8cc;
  char local_8c8 [256];
  char local_7c8 [256];
  char local_6c8 [256];
  char local_5c8 [256];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_4c8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_4ac [28];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_490 [28];
  int local_474;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_70 [28];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_54 [28];
  int local_38;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_34 [28];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b070b;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  if (*param_1 == '\0') {
    ExceptionList = &local_10;
    *param_1 = '\x01';
    if (param_6 != 0) {
      *(int *)(param_1 + 0x14a4) = param_6;
      **(undefined4 **)(param_1 + 0x14a4) = 1;
    }
    param_1[0x1401] = param_4;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x146c)
               ,param_2);
    if (((*DAT_00a16628 < 15000) || (0x3c8b < *DAT_00a16628)) &&
       ((iVar2 = FUN_004cbbc0(), iVar2 != DAT_007d0624 ||
        ((iVar2 = FUN_004cbbc0(), iVar2 != DAT_007d0624 ||
         (iVar2 = FUN_004cbbc0(), iVar2 != DAT_007d0624)))))) {
      local_8fc = auStack_a0c;
      puStack_a10 = &DAT_007d1840;
      puStack_a14 = (undefined *)0x4b7053;
      basic_string<>();
      puStack_a10 = (undefined *)0x4b705e;
      pcVar3 = (char *)FUN_00401c50();
      _sprintf(local_5c8,pcVar3);
      uStack_a00 = 0x4b7092;
      _sprintf(local_6c8,"URL : %s");
      FUN_00438b60();
      local_8 = 0;
      FUN_004cbb30();
      uStack_a00 = 0x4b70e2;
      FUN_00475dd0();
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_918);
      local_959 = 1;
    }
    else {
      basic_string<>();
      local_8 = 1;
      basic_string<>();
      local_8._0_1_ = 2;
      iVar2 = FUN_004cbbc0();
      if (iVar2 != DAT_007d0624) {
        FUN_004cbbc0();
        uStack_a00 = 0x4b7166;
        FUN_004cbc20();
        local_8._0_1_ = 3;
        FUN_004cb840();
        local_8._0_1_ = 2;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_934);
      }
      basic_string<>();
      local_8 = CONCAT31(local_8._1_3_,4);
      iVar2 = FUN_004cbbc0();
      if ((iVar2 == -1) && (iVar2 = FUN_004cbbc0(), iVar2 == -1)) {
        local_14 = 0;
        local_14 = FUN_004cbbc0();
        if (local_14 != DAT_007d0624) {
          FUN_004cbb30();
          iVar2 = FUN_0046f680();
          if (iVar2 == 0) {
            uStack_a00 = 0x4b7335;
            FUN_004cba30();
            FUN_004cb840();
          }
          else {
            local_14 = local_14 + 1;
          }
        }
        local_38 = FUN_004e5650();
        do {
          local_38 = local_38 + -1;
          if (local_38 < 1) goto LAB_004b73ea;
          iVar2 = FUN_004cbbc0();
        } while (iVar2 == DAT_007d0624);
        FUN_004e5650();
        uStack_a00 = 0x4b73ac;
        FUN_004cbc20();
        local_8._0_1_ = 6;
        FUN_004cb840();
        local_8 = CONCAT31(local_8._1_3_,4);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_978);
LAB_004b73ea:
        iVar2 = FUN_004e5650();
        if (local_38 == iVar2 + -1) {
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_4ac,
                     "index.htm");
        }
        cVar1 = FUN_004ec750();
        if (cVar1 == '\0') {
          FUN_004cbb30();
          FUN_004fd700();
          FUN_004cbb30();
          FUN_004fd700();
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    (local_490,
                     (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )&DAT_00a14b78);
          local_8._0_1_ = 7;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    (local_34,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                               *)local_70);
          local_8._0_1_ = 8;
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    (local_54,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                               *)local_490);
          local_8 = CONCAT31(local_8._1_3_,9);
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    (local_54,"/");
          local_8cc = 0;
          while (local_8cc = FUN_004cbbc0(), local_8cc != -1) {
            uStack_a00 = 0x4b759f;
            FUN_004cba30();
          }
          local_474 = 0;
          local_8cc = 0xffffffff;
          while( true ) {
            iVar2 = FUN_004e5650();
            if ((iVar2 < 2) || (iVar2 = FUN_004cbbc0(), iVar2 == DAT_007d0624)) goto LAB_004b773c;
            basic_string<>();
            local_8._0_1_ = 10;
            FUN_004cbbc0();
            uStack_a00 = 0x4b7626;
            FUN_004cbc20();
            local_8._0_1_ = 0xb;
            FUN_004cb840();
            local_8 = CONCAT31(local_8._1_3_,10);
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_99c);
            FUN_004cb880();
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                      (local_54,"/");
            local_8ec = 0;
            while (local_8ec = FUN_004cbbc0(), local_8ec != -1) {
              uStack_a00 = 0x4b76bc;
              FUN_004cba30();
            }
            lpSecurityAttributes = (LPSECURITY_ATTRIBUTES)0x0;
            pCVar4 = (LPCSTR)FUN_004cbb30();
            CreateDirectoryA(pCVar4,lpSecurityAttributes);
            pCVar4 = (LPCSTR)FUN_004cbb30();
            SetCurrentDirectoryA(pCVar4);
            iVar2 = FUN_004cbbc0();
            if (iVar2 == DAT_007d0624) break;
            local_474 = FUN_004cbbc0();
            local_474 = local_474 + 1;
            local_8 = CONCAT31(local_8._1_3_,9);
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_8e8);
          }
          local_8 = CONCAT31(local_8._1_3_,9);
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_8e8);
LAB_004b773c:
          pCVar4 = (LPCSTR)FUN_004cbb30();
          SetCurrentDirectoryA(pCVar4);
          FUN_004cb840();
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                     (param_1 + 0x1450),param_3);
          local_8f0 = 0;
          while (local_8f0 = FUN_004cbbc0(), local_8f0 != -1) {
            uStack_a00 = 0x4b77cd;
            FUN_004cba30();
          }
          CreateDirectoryA("",(LPSECURITY_ATTRIBUTES)0x0);
          FUN_004cb840();
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                     (param_1 + 0x1488),"");
          *(undefined4 *)(param_1 + 0x144c) = param_5;
          uVar5 = FUN_00550060();
          *(undefined4 *)(param_1 + 0x1414) = uVar5;
          for (local_8f4 = 0; local_8f4 < 5; local_8f4 = local_8f4 + 1) {
            pcVar3 = param_1 + local_8f4 * 4 + 0x1434;
            pcVar3[0] = '\0';
            pcVar3[1] = '\0';
            pcVar3[2] = '\0';
            pcVar3[3] = '\0';
            pcVar3 = param_1 + local_8f4 * 4 + 0x1420;
            pcVar3[0] = '\0';
            pcVar3[1] = '\0';
            pcVar3[2] = '\0';
            pcVar3[3] = '\0';
          }
          param_1[0x1448] = '\0';
          param_1[0x1449] = '\0';
          param_1[0x144a] = '\0';
          param_1[0x144b] = '\0';
          *(undefined4 *)(param_1 + 0x1434) = *(undefined4 *)(param_1 + 0x1414);
          param_1[0x1420] = '\0';
          param_1[0x1421] = '\0';
          param_1[0x1422] = '\0';
          param_1[0x1423] = '\0';
          param_1[0x1410] = '\0';
          param_1[0x1411] = '\0';
          param_1[0x1412] = '\0';
          param_1[0x1413] = '\0';
          for (local_8f8 = 5; 0 < local_8f8; local_8f8 = local_8f8 + -1) {
            *(undefined4 *)(param_1 + local_8f8 * 4 + 0x14a8) =
                 *(undefined4 *)(param_1 + local_8f8 * 4 + 0x14a4);
          }
          *(int *)(param_1 + 0x14a8) = DAT_00a18a28;
          if ((*DAT_00a16628 < 15000) || (0x3c8b < *DAT_00a16628)) {
            if (DAT_00a18a28 + -0x1e <= *(int *)(param_1 + 0x14ac)) {
              FUN_0052eb30();
            }
            if (DAT_00a18a28 + -0x1e <= *(int *)(param_1 + 0x14b0)) {
              FUN_0052eb30();
            }
            if (DAT_00a18a28 + -0x1e <= *(int *)(param_1 + 0x14b8)) {
              FUN_0052eb30();
            }
            if (DAT_00a18a28 + -0x1e <= *(int *)(param_1 + 0x14bc)) {
              FUN_0052eb30();
            }
            if (DAT_00a18a28 + -0x1e <= *(int *)(param_1 + 0x14c0)) {
              FUN_0052eb30();
            }
          }
          FUN_004cb840();
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                     (param_1 + 0x14d0),param_1 + 1);
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                     (param_1 + 0x14d0),"_tmp");
          param_1[0x1404] = '\0';
          param_1[0x1405] = '\0';
          param_1[0x1406] = '\0';
          param_1[0x1407] = '\0';
          FUN_004cb9c0();
          FUN_004cb9c0();
          FUN_004cb9c0();
          FUN_004b7b20();
          local_99d = 1;
          local_8._0_1_ = 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_54);
          local_8._0_1_ = 7;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_34);
          local_8._0_1_ = 4;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                     local_490);
          local_8._0_1_ = 2;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_70);
          local_8 = CONCAT31(local_8._1_3_,1);
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4ac);
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4c8);
          local_959 = local_99d;
        }
        else {
          local_97c = auStack_a0c;
          puStack_a10 = &DAT_007d17a8;
          puStack_a14 = (undefined *)0x4b7441;
          basic_string<>();
          puStack_a10 = (undefined *)0x4b744c;
          pcVar3 = (char *)FUN_00401c50();
          _sprintf(local_7c8,pcVar3);
          uStack_a00 = 0x4b7480;
          _sprintf(local_8c8,"URL : %s");
          uStack_a00 = 0x4b749e;
          FUN_00475dd0();
          local_97d = 0;
          local_8._0_1_ = 2;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_70);
          local_8 = CONCAT31(local_8._1_3_,1);
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4ac);
          local_8 = 0xffffffff;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4c8);
          local_959 = local_97d;
        }
      }
      else {
        if (DAT_00a117a8 == 0) {
          uStack_a00 = 0x4b72a4;
          FUN_00475dd0();
        }
        else {
          FUN_00438b60();
          local_8._0_1_ = 5;
          FUN_004cbb30();
          local_954 = (undefined1 *)&puStack_a10;
          puStack_a14 = &DAT_007d151c;
          basic_string<>();
          puStack_a14 = (undefined *)0x4b7237;
          FUN_00401c50();
          local_958 = (undefined1 *)&puStack_a14;
          basic_string<>(&DAT_007d17e0);
          FUN_00401c50();
          uStack_a00 = 0x4b7282;
          FUN_00475dd0();
          local_8 = CONCAT31(local_8._1_3_,4);
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_950);
        }
        local_959 = 1;
        local_8._0_1_ = 2;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_70);
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4ac);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_4c8);
      }
    }
  }
  else {
    local_959 = 0;
  }
  ExceptionList = local_10;
  return local_959;
}

