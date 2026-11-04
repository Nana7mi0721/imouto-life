
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

basic_string<char,std::char_traits<char>,std::allocator<char>_> * __thiscall
FUN_004706f0(int param_1,basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_2,
            int param_3,int param_4,int param_5)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_134 [8];
  undefined4 uStack_12c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_128;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *pbStack_124;
  int iStack_120;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_b8 [28];
  undefined1 *local_9c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_98 [28];
  undefined1 *local_7c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_78 [28];
  undefined1 *local_5c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_58 [28];
  undefined1 *local_3c;
  undefined1 *local_38;
  int local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ae90d;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  iStack_120 = 0x470734;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 1;
  if (0x32 < param_5) {
    local_38 = auStack_134;
    basic_string<>(&DAT_007d0750);
    pcVar1 = (char *)FUN_00401c50();
    iStack_120 = 0x470776;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_30,pcVar1)
    ;
    iStack_120 = 0x470782;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (param_2,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)local_30);
    local_8 = local_8 & 0xffffff00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_30
              );
    ExceptionList = local_10;
    return param_2;
  }
  if (((param_3 < 0) || (param_4 < 0)) || (iVar2 = FUN_004d0530(), iVar2 <= param_3)) {
LAB_004707e5:
    local_3c = auStack_134;
    basic_string<>(&DAT_007d0744);
    FUN_00401c50();
    iStack_120 = 0x47081a;
    basic_string<>();
    local_8 = local_8 & 0xffffff00;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_30
              );
    ExceptionList = local_10;
    return param_2;
  }
  iStack_120 = 0x4707d6;
  FUN_004d05c0();
  iVar2 = FUN_004cc430();
  if (iVar2 <= param_4) goto LAB_004707e5;
  iStack_120 = 0x47084f;
  iVar2 = FUN_004d0120();
  if (*(int *)(iVar2 + 0x24) == 0) {
    iStack_120 = param_3;
    pbStack_124 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x47086b;
    FUN_004d05c0();
    iStack_120 = 0x470875;
    FUN_004cc4c0();
    iStack_120 = 0x47087e;
    FUN_004cb840();
  }
  iStack_120 = 0x470890;
  iVar2 = FUN_004d0120();
  if (*(int *)(iVar2 + 0x24) == 1) {
    iStack_120 = param_3;
    pbStack_124 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x4708ac;
    FUN_004d0120();
    iStack_120 = 0x4708b6;
    FUN_004cfcd0();
    iVar2 = FUN_004cc430();
    if (0 < iVar2) {
      iStack_120 = param_4;
      pbStack_124 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)param_3;
      pbStack_128 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4708dc;
      FUN_004d0120();
      pbStack_124 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)0x4708e6;
      FUN_004cfcd0();
      iStack_120 = 0x4708f0;
      FUN_004cc4c0();
      iStack_120 = 0x4708f9;
      FUN_004cb840();
    }
  }
  iStack_120 = 0x47090b;
  iVar2 = FUN_004d0120();
  if (*(int *)(iVar2 + 0x24) == 2) {
    for (local_34 = 1; -1 < param_3 - local_34; local_34 = local_34 + 1) {
      iStack_120 = 0x470939;
      iVar2 = FUN_004d0120();
      if (*(int *)(iVar2 + 0x24) != 2) break;
    }
    if (-1 < param_3 - local_34) {
      iStack_120 = 0x470967;
      FUN_004d05c0();
      iVar2 = FUN_004cc430();
      if (param_4 < iVar2) {
        iStack_120 = param_4;
        pbStack_124 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                      (param_3 - local_34);
        pbStack_128 = local_58;
        uStack_12c = 0x470997;
        FUN_004706f0();
        local_8._0_1_ = 2;
        iStack_120 = 0x4709bc;
        FUN_004cb840();
        local_8 = CONCAT31(local_8._1_3_,1);
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58);
        goto LAB_004709ff;
      }
    }
    local_5c = auStack_134;
    basic_string<>(&DAT_007d0744);
    pcVar1 = (char *)FUN_00401c50();
    iStack_120 = 0x4709ff;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_30,pcVar1)
    ;
  }
LAB_004709ff:
  if (*(int *)(param_1 + 8) != 0) {
    iStack_120 = 0x470a21;
    iVar2 = FUN_004d0120();
    if (9999 < *(int *)(iVar2 + 0x24)) {
      iStack_120 = 0x470a40;
      iVar2 = FUN_004d0120();
      if (*(int *)(iVar2 + 0x24) < 20000) {
        iStack_120 = 0x470a5f;
        FUN_004d0120();
        iStack_120 = 0x470a7c;
        FUN_004d05c0();
        iVar2 = FUN_004cc430();
        if (param_4 < iVar2) {
          iStack_120 = 0x470aa1;
          FUN_004d0120();
          iStack_120 = 0x470abe;
          iVar2 = FUN_004d0120();
          iStack_120 = 0x470ad2;
          iVar3 = FUN_004d0120();
          if (*(int *)(iVar2 + 0x24) != *(int *)(iVar3 + 0x24)) {
            iStack_120 = param_4;
            pbStack_124 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)param_3
            ;
            pbStack_128 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x470af7;
            iVar2 = FUN_004d0120();
            pbStack_124 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          (*(int *)(iVar2 + 0x24) % 10000);
            pbStack_128 = local_78;
            uStack_12c = 0x470b15;
            FUN_004706f0();
            local_8._0_1_ = 3;
            iStack_120 = 0x470b3a;
            FUN_004cb840();
            local_8 = CONCAT31(local_8._1_3_,1);
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_78);
            goto LAB_00470b7d;
          }
        }
        local_7c = auStack_134;
        basic_string<>(&DAT_007d0744);
        pcVar1 = (char *)FUN_00401c50();
        iStack_120 = 0x470b7d;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_30,pcVar1);
      }
    }
  }
LAB_00470b7d:
  if (*(int *)(param_1 + 0xc) != 0) {
    iStack_120 = 0x470b9f;
    iVar2 = FUN_004d0120();
    if (19999 < *(int *)(iVar2 + 0x24)) {
      iStack_120 = 0x470bbe;
      iVar2 = FUN_004d0120();
      if (*(int *)(iVar2 + 0x24) < 30000) {
        iStack_120 = 0x470bdd;
        FUN_004d0120();
        iStack_120 = 0x470bfa;
        FUN_004d05c0();
        iVar2 = FUN_004cc430();
        if (param_4 < iVar2) {
          iStack_120 = 0x470c1f;
          FUN_004d0120();
          iStack_120 = 0x470c3c;
          iVar2 = FUN_004d0120();
          iStack_120 = 0x470c50;
          iVar3 = FUN_004d0120();
          if (*(int *)(iVar2 + 0x24) != *(int *)(iVar3 + 0x24)) {
            iStack_120 = param_4;
            pbStack_124 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)param_3
            ;
            pbStack_128 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x470c75;
            iVar2 = FUN_004d0120();
            pbStack_124 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          (*(int *)(iVar2 + 0x24) % 10000);
            pbStack_128 = local_98;
            uStack_12c = 0x470c96;
            FUN_004706f0();
            local_8._0_1_ = 4;
            iStack_120 = 0x470cbb;
            FUN_004cb840();
            local_8 = CONCAT31(local_8._1_3_,1);
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_98);
            goto LAB_00470d04;
          }
        }
        local_9c = auStack_134;
        basic_string<>(&DAT_007d0744);
        pcVar1 = (char *)FUN_00401c50();
        iStack_120 = 0x470d04;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_30,pcVar1);
      }
    }
  }
LAB_00470d04:
  if (*(int *)(param_1 + 0x10) != 0) {
    iStack_120 = 0x470d26;
    iVar2 = FUN_004d0120();
    if (29999 < *(int *)(iVar2 + 0x24)) {
      iStack_120 = 0x470d45;
      iVar2 = FUN_004d0120();
      if (*(int *)(iVar2 + 0x24) < 40000) {
        iStack_120 = 0x470d64;
        FUN_004d0120();
        iStack_120 = 0x470d81;
        FUN_004d05c0();
        iVar2 = FUN_004cc430();
        if (param_4 < iVar2) {
          iStack_120 = 0x470da6;
          FUN_004d0120();
          iStack_120 = 0x470dc3;
          iVar2 = FUN_004d0120();
          iStack_120 = 0x470dd7;
          iVar3 = FUN_004d0120();
          if (*(int *)(iVar2 + 0x24) != *(int *)(iVar3 + 0x24)) {
            iStack_120 = param_4;
            pbStack_124 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)param_3
            ;
            pbStack_128 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)0x470dfc;
            iVar2 = FUN_004d0120();
            pbStack_124 = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          (*(int *)(iVar2 + 0x24) % 10000);
            pbStack_128 = local_b8;
            uStack_12c = 0x470e1d;
            FUN_004706f0();
            local_8._0_1_ = 5;
            iStack_120 = 0x470e42;
            FUN_004cb840();
            local_8 = CONCAT31(local_8._1_3_,1);
            std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
            ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_b8);
            goto LAB_00470e8b;
          }
        }
        basic_string<>(&DAT_007d0744);
        pcVar1 = (char *)FUN_00401c50();
        iStack_120 = 0x470e8b;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                  (local_30,pcVar1);
      }
    }
  }
LAB_00470e8b:
  iStack_120 = 0;
  pbStack_124 = param_2;
  pbStack_128 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                0x470e9b;
  FUN_004cbc20();
  local_8 = local_8 & 0xffffff00;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_30);
  ExceptionList = local_10;
  return param_2;
}

