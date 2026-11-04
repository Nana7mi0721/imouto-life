
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x004bcbdd) */
/* WARNING: Removing unreachable block (ram,0x004bcbf8) */
/* WARNING: Removing unreachable block (ram,0x004bcc05) */
/* WARNING: Removing unreachable block (ram,0x004bcc1f) */
/* WARNING: Removing unreachable block (ram,0x004bccd9) */
/* WARNING: Removing unreachable block (ram,0x004bcd07) */
/* WARNING: Removing unreachable block (ram,0x004bccc1) */
/* WARNING: Removing unreachable block (ram,0x004bcd1d) */
/* WARNING: Removing unreachable block (ram,0x004bcbe9) */
/* WARNING: Removing unreachable block (ram,0x004bc9da) */
/* WARNING: Removing unreachable block (ram,0x004bc9f5) */
/* WARNING: Removing unreachable block (ram,0x004bca02) */
/* WARNING: Removing unreachable block (ram,0x004bca1c) */
/* WARNING: Removing unreachable block (ram,0x004bca3e) */
/* WARNING: Removing unreachable block (ram,0x004bca50) */
/* WARNING: Removing unreachable block (ram,0x004bca91) */
/* WARNING: Removing unreachable block (ram,0x004bcac6) */
/* WARNING: Removing unreachable block (ram,0x004bca2f) */
/* WARNING: Removing unreachable block (ram,0x004bcad2) */
/* WARNING: Removing unreachable block (ram,0x004bcae1) */
/* WARNING: Removing unreachable block (ram,0x004bc9e6) */
/* WARNING: Removing unreachable block (ram,0x004bcd39) */
/* WARNING: Removing unreachable block (ram,0x004bcd5b) */
/* WARNING: Removing unreachable block (ram,0x004bcd68) */
/* WARNING: Removing unreachable block (ram,0x004bcd82) */
/* WARNING: Removing unreachable block (ram,0x004bcda4) */
/* WARNING: Removing unreachable block (ram,0x004bcdb2) */
/* WARNING: Removing unreachable block (ram,0x004bcdf3) */
/* WARNING: Removing unreachable block (ram,0x004bcd95) */
/* WARNING: Removing unreachable block (ram,0x004bcdfc) */
/* WARNING: Removing unreachable block (ram,0x004bce0b) */
/* WARNING: Removing unreachable block (ram,0x004bcea8) */
/* WARNING: Removing unreachable block (ram,0x004bcd4c) */
/* WARNING: Removing unreachable block (ram,0x004bc25e) */
/* WARNING: Removing unreachable block (ram,0x004bc37d) */
/* WARNING: Removing unreachable block (ram,0x004bc374) */
/* WARNING: Removing unreachable block (ram,0x004bc3c2) */
/* WARNING: Removing unreachable block (ram,0x004bc3f3) */
/* WARNING: Removing unreachable block (ram,0x004bc3ea) */
/* WARNING: Removing unreachable block (ram,0x004bc441) */
/* WARNING: Removing unreachable block (ram,0x004bc4c2) */
/* WARNING: Removing unreachable block (ram,0x004bc4b3) */

void __fastcall FUN_004bb9b0(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined1 auStack_254 [8];
  undefined4 uStack_24c;
  void *pvStack_248;
  int local_208;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1f0 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1d4 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1b8 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_19c [36];
  undefined1 *local_178;
  undefined1 *local_174;
  int local_124;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_f8 [28];
  int local_dc;
  int local_d8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_d4 [28];
  int local_b8;
  int local_b4;
  int local_b0;
  undefined4 local_44;
  void *local_40;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_3c [28];
  undefined4 local_20;
  char local_19;
  int local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b08b9;
  local_10 = ExceptionList;
  local_20 = DAT_0084b484;
  ExceptionList = &local_10;
  FUN_004cc400();
  FUN_004cc4c0();
  FUN_004cb840();
  FUN_004cc4c0();
  FUN_004cb840();
  FUN_004cc4c0();
  FUN_004cb840();
  FUN_004cc4c0();
  FUN_004cb840();
  FUN_00536900();
  FUN_00536940();
  local_44 = 0;
  local_19 = '\x01';
  if (*DAT_00a166b8 < '\x02') {
    if (DAT_0084b218 == 0) {
      local_174 = auStack_254;
      basic_string<>(&DAT_007d1d74);
      pcVar2 = (char *)FUN_00401c50();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),pcVar2);
    }
    else if (DAT_0084b218 == 1) {
      local_178 = auStack_254;
      basic_string<>(&DAT_007d1d74);
      pcVar2 = (char *)FUN_00401c50();
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),pcVar2);
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"Meiryo UI");
    }
    local_44 = 1;
  }
  if (*DAT_00a166b8 == '\x02') {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x3e0),
               "Malgun Gothic");
    local_44 = 2;
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"Batang");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"Gulim");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"Malgun Gothic");
    }
  }
  if (*DAT_00a166b8 == '\x03') {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x3e0),
               "Microsoft JhengHei");
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),&DAT_007d1d28);
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"PMingLiu");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),&DAT_007d1d10);
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"Microsoft JhengHei");
    }
    local_44 = 3;
  }
  if (*DAT_00a166b8 == '\x04') {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x3e0),
               "Microsoft YaHei");
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),&DAT_007d1cf8);
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"SimHei");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"KaiTi");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),&DAT_007d1ce0);
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"SimSun");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),&DAT_007d1cd0);
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"SimSun-ExtB");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),&DAT_007d1cb8);
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"Microsoft YaHei");
    }
    local_44 = 4;
  }
  if (*DAT_00a166b8 == '\x05') {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x3e0),
               "Arial");
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"Segoe UI");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"Times New Roman");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"MS Serif");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"System");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"Arial");
    }
    local_44 = 0;
  }
  if (*DAT_00a166b8 == '\x06') {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x3e0),
               "Segoe UI");
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"Times New Roman");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"MS Serif");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"Arial");
    }
    local_44 = 5;
  }
  if (*DAT_00a166b8 == '\a') {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 0x3e0),
               "Segoe UI");
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"Times New Roman");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"MS Serif");
    }
    FUN_004cbb30();
    iVar3 = FUN_0052fc20();
    if (iVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (param_1 + 0x3e0),"Arial");
    }
    local_44 = 6;
  }
  basic_string<>();
  local_8 = 0;
  local_11 = '\0';
  FUN_004cbb30();
  FUN_00536a20();
  if (local_19 != '\0') {
    for (local_b0 = 0; local_b0 < 4; local_b0 = local_b0 + 1) {
      FUN_004cc4c0();
      cVar1 = FUN_004ec750();
      if (cVar1 != '\0') {
        FUN_004cc4c0();
        FUN_004cb840();
      }
      *(undefined4 *)(param_1 + 0x3cc + local_b0 * 4) = 0xffffffff;
    }
  }
  FUN_00475c70();
  *(undefined4 *)(param_1 + 0x43c) = 100;
  if (*DAT_00a166ac == '\0') {
    *(undefined4 *)(param_1 + 0x3c0) = 0x22;
    *(undefined4 *)(param_1 + 0x3c4) = 0x23;
    *(undefined4 *)(param_1 + 0x3dc) = 1;
  }
  else if (*DAT_00a166ac == '\x01') {
    *(undefined4 *)(param_1 + 0x3c0) = 0;
    *(undefined4 *)(param_1 + 0x3c4) = 1;
    *(undefined4 *)(param_1 + 0x3dc) = 0;
  }
  else if (*DAT_00a166ac == '\x02') {
    *(undefined4 *)(param_1 + 0x3c0) = 0;
    *(undefined4 *)(param_1 + 0x3c4) = 1;
    *(undefined4 *)(param_1 + 0x43c) = 200;
  }
  pvStack_248 = (void *)0x4bc6ba;
  iVar3 = FUN_0052fb20();
  if (iVar3 < 5) {
    local_208 = 5;
  }
  else {
    pvStack_248 = (void *)0x4bc6d9;
    local_208 = FUN_0052fb20();
  }
  local_18 = local_208;
  local_40 = _malloc(local_208 << 6);
  if (local_19 != '\0') {
    for (local_b4 = 0; local_b4 < 4; local_b4 = local_b4 + 1) {
      pvStack_248 = (void *)0x4bc743;
      _memset(local_40,0,local_18 << 6);
      FUN_004cc4c0();
      FUN_004cbb30();
      pvStack_248 = local_40;
      uStack_24c = 0x4bc775;
      FUN_0052fb60();
      for (local_b8 = 0; local_b8 < local_18; local_b8 = local_b8 + 1) {
        basic_string<>();
        local_8._0_1_ = 4;
        cVar1 = FUN_004cbb70();
        if (cVar1 != '\0') {
          local_8 = (uint)local_8._1_3_ << 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_d4);
          break;
        }
        FUN_004cc4c0();
        cVar1 = FUN_004ec8f0();
        if (cVar1 != '\0') {
          *(undefined4 *)(param_1 + 0x3cc + local_b4 * 4) = 0;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_d4);
      }
    }
    for (local_d8 = 0; local_d8 < 4; local_d8 = local_d8 + 1) {
      pvStack_248 = (void *)0x4bc87a;
      _memset(local_40,0,local_18 << 6);
      FUN_004cc4c0();
      FUN_004cbb30();
      pvStack_248 = local_40;
      uStack_24c = 0x4bc8ae;
      FUN_0052fb60();
      for (local_dc = 0; local_dc < local_18; local_dc = local_dc + 1) {
        basic_string<>();
        local_8._0_1_ = 5;
        cVar1 = FUN_004cbb70();
        if (cVar1 != '\0') {
          local_8 = (uint)local_8._1_3_ << 8;
          std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
          ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_f8);
          break;
        }
        FUN_004cc4c0();
        cVar1 = FUN_004ec8f0();
        if (cVar1 != '\0') {
          *(undefined4 *)(param_1 + 0x3cc + local_d8 * 4) = local_44;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_f8);
      }
      if (*(int *)(param_1 + 0x3cc + local_d8 * 4) == -1) {
        FUN_004cc4c0();
        FUN_004cbb30();
        iVar3 = FUN_0052fc20();
        if (iVar3 != 0) {
          *(undefined4 *)(param_1 + 0x3cc + local_d8 * 4) = local_44;
        }
      }
    }
  }
  for (local_124 = 0; local_124 < 4; local_124 = local_124 + 1) {
    if (*(int *)(param_1 + 0x3cc + local_124 * 4) == -1) {
      *(undefined4 *)(param_1 + 0x3cc + local_124 * 4) = local_44;
    }
  }
  if (local_11 != '\0') {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (local_3c,"\n\n-----------\n");
    FUN_004cc4c0();
    pvStack_248 = (void *)0x4bcef2;
    FUN_004ec910();
    local_8._0_1_ = 9;
    FUN_004cb880();
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_19c);
    pcVar2 = (char *)FUN_0041b5f0();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_3c,pcVar2)
    ;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_3c,"\n");
    FUN_004cc4c0();
    pvStack_248 = (void *)0x4bcf79;
    FUN_004ec910();
    local_8._0_1_ = 10;
    FUN_004cb880();
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1b8);
    pcVar2 = (char *)FUN_0041b5f0();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_3c,pcVar2)
    ;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_3c,"\n");
    FUN_004cc4c0();
    pvStack_248 = (void *)0x4bd000;
    FUN_004ec910();
    local_8._0_1_ = 0xb;
    FUN_004cb880();
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1d4);
    pcVar2 = (char *)FUN_0041b5f0();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_3c,pcVar2)
    ;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_3c,"\n");
    FUN_004cc4c0();
    pvStack_248 = (void *)0x4bd087;
    FUN_004ec910();
    local_8._0_1_ = 0xc;
    FUN_004cb880();
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1f0);
    pcVar2 = (char *)FUN_0041b5f0();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_3c,pcVar2)
    ;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_3c,"\n");
    FUN_004cbb30();
    FUN_004209c0();
  }
  _free(local_40);
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_3c);
  ExceptionList = local_10;
  return;
}

