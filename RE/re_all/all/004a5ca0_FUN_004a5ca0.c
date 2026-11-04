
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1
FUN_004a5ca0(int param_1,char param_2,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  LPCSTR lpPathName;
  char *_Filename;
  undefined1 *puVar6;
  undefined1 auStack_2dd0 [20];
  undefined4 uStack_2dbc;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_2db4 [20];
  undefined4 uStack_2da0;
  char *pcStack_2d98;
  undefined4 uStack_2d94;
  size_t sStack_2d90;
  char *_Mode;
  undefined1 local_2d07;
  undefined1 local_2d06;
  undefined1 local_2d05;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_2cf0 [28];
  undefined1 *local_2cd4;
  undefined1 *local_2cd0;
  undefined1 *local_2ccc;
  undefined1 local_579;
  undefined1 *local_578;
  undefined1 *local_574;
  undefined1 *local_570;
  undefined1 *local_56c;
  undefined1 *local_568;
  undefined1 local_561;
  int local_560;
  int local_55c;
  undefined1 local_555;
  int local_554;
  ULARGE_INTEGER local_550;
  size_t local_548;
  char local_544;
  char local_543;
  char local_542;
  char local_540 [260];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_43c [28];
  CHAR local_420 [1024];
  undefined4 local_20;
  char local_1c [4];
  FILE *local_18;
  PULARGE_INTEGER local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_007afc45;
  local_10 = ExceptionList;
  local_14 = (PULARGE_INTEGER)0x4a5cc2;
  local_20 = DAT_0084b484;
  local_8 = 0;
  if (DAT_00a117ac == '\0') {
    ExceptionList = &local_10;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (local_43c,
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_00a14b78);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (param_1 == 0) {
      iVar2 = FUN_004cbbc0();
      if ((iVar2 != -1) || (iVar2 = FUN_004cbbc0(), iVar2 != -1)) {
        if (DAT_00a117a8 != 0) {
          local_568 = (undefined1 *)&pcStack_2d98;
          uStack_2da0 = 0x4a5d6c;
          FUN_00438b60();
          local_8._0_1_ = 2;
          local_570 = abStack_2db4;
          uStack_2dbc = 0x4a5d9a;
          basic_string<>();
          FUN_00401c50();
          uStack_2dbc = 0x4a5dc5;
          local_56c = abStack_2db4;
          basic_string<>();
          local_8._0_1_ = 3;
          local_578 = auStack_2dd0;
          basic_string<>(&DAT_007d14d0);
          uVar3 = FUN_00401c50();
          local_574 = auStack_2dd0;
          basic_string<>(uVar3);
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_0042bed0();
        }
        local_579 = 0;
        local_8 = local_8 & 0xffffff00;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_43c);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
        ExceptionList = local_10;
        return local_579;
      }
      FUN_004cbb30();
      _sprintf(local_540,"%s");
    }
    else {
      FUN_004cbb30();
      sStack_2d90 = 0x4a5e9a;
      _sprintf(local_540,"%s%.2i.sav");
    }
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (local_43c,local_540);
    FUN_004ce060();
    FUN_004d3930();
    cVar1 = const_iterator__operator__();
    if (cVar1 != '\0') {
      FUN_004a66a0();
      local_8._0_1_ = 4;
      FUN_004d3570();
      FUN_004b35a0();
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_004b34a0();
    }
    if (param_2 != '\0') {
      FUN_004d3570();
      FUN_004ab5b0();
      FUN_004d3570();
      FUN_00472eb0();
      FUN_004d3570();
      FUN_00473f10();
      FUN_004d3570();
      FUN_004736a0();
      FUN_004d3570();
      FUN_00474330();
      FUN_004d3570();
      FUN_00472740();
      iVar2 = FUN_004d3570();
      iVar4 = FUN_004d3570();
      *(int *)(iVar4 + 0x2458) = iVar2 + 0x1918;
    }
    local_548 = 0;
    for (local_554 = 1; -1 < local_554; local_554 = local_554 + -1) {
      DAT_00a117e8 = local_554;
      DAT_00a117e4 = 0;
      DAT_00a0f820 = 0;
      if (local_554 == 0) {
        DAT_00a0f824 = _malloc(local_548 + 100);
        _memset(DAT_00a0f824,0,local_548 + 100);
      }
      DAT_00a0f820 = DAT_00a0f820 + 0x14;
      local_555 = 0x19;
      if (DAT_00a117e8 == 0) {
        DAT_00a0f844 = 1;
        _memcpy(DAT_00a0f824 + DAT_00a0f820,&local_555,1);
      }
      else {
        DAT_00a0f844 = 1;
      }
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      FUN_004ab630();
      FUN_004d3570();
      FUN_004a6c00();
      if (DAT_00a117e8 == 0) {
        DAT_00a0f844 = 1;
        _memcpy(DAT_00a0f824 + DAT_00a0f820,&local_555,1);
      }
      else {
        DAT_00a0f844 = 1;
      }
      DAT_00a0f820 = DAT_00a0f820 + DAT_00a0f844;
      local_548 = DAT_00a0f820;
    }
    DAT_00a117e8 = 0;
    FID_conflict___time32((__time32_t *)0x0);
    FUN_004fcb44();
    uVar5 = _rand();
    local_1c[0] = (char)((int)(uVar5 & 0xff0) >> 4);
    uVar5 = _rand();
    local_1c[1] = (char)((int)(uVar5 & 0xff0) >> 4);
    uVar5 = _rand();
    local_1c[2] = (char)((int)(uVar5 & 0xff0) >> 4);
    if (((local_1c[0] == '\0') && (local_1c[1] == '\0')) && (local_1c[2] == '\0')) {
      for (local_55c = 0; local_55c < 3; local_55c = local_55c + 1) {
        uVar5 = _rand();
        local_1c[local_55c] = (char)((int)(uVar5 & 0xff0) >> 4);
      }
    }
    local_544 = '\0';
    local_543 = '\0';
    local_542 = '\0';
    sStack_2d90 = DAT_00a0f820;
    uStack_2d94 = 0x14;
    pcStack_2d98 = DAT_00a0f824;
    local_2ccc = abStack_2db4;
    uStack_2dbc = 0x4a62e7;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (abStack_2db4,
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               local_43c);
    FUN_0041b9e0();
    for (local_560 = 0; local_560 < 0x14; local_560 = local_560 + 1) {
      iVar2 = _rand();
      DAT_00a0f824[local_560] = (char)((uint)iVar2 >> 8);
    }
    *DAT_00a0f824 = local_1c[0];
    DAT_00a0f824[3] = local_1c[1];
    DAT_00a0f824[9] = local_1c[2];
    DAT_00a0f824[2] = local_544;
    DAT_00a0f824[6] = local_543;
    DAT_00a0f824[8] = local_542;
    lpPathName = (LPCSTR)FUN_004cbb30();
    SetCurrentDirectoryA(lpPathName);
    GetCurrentDirectoryA(0x400,local_420);
    local_2cd0 = (undefined1 *)&pcStack_2d98;
    uStack_2da0 = 0x4a63c5;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&pcStack_2d98,
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_00a14b78);
    local_8._0_1_ = 5;
    local_2cd4 = abStack_2db4;
    uStack_2dbc = 0x4a63ef;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              (abStack_2db4,
               (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &param_3);
    local_8._0_1_ = 1;
    uStack_2dbc = 0x4a6405;
    FUN_0041a1d0();
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_2cf0);
    local_14 = &local_550;
    sStack_2d90 = 0x4a6432;
    GetDiskFreeSpaceExA((LPCSTR)0x0,local_14,(PULARGE_INTEGER)0x0,(PULARGE_INTEGER)0x0);
    uVar5 = (int)(DAT_00a0f820 - 200) >> 0x1f;
    if ((uVar5 < local_550.s.HighPart) ||
       ((uVar5 <= local_550.s.HighPart && (DAT_00a0f820 - 200 <= local_550.s.LowPart)))) {
      _Mode = "wb";
      _Filename = (char *)FUN_004cbb30();
      local_18 = _fopen(_Filename,_Mode);
      if (local_18 == (FILE *)0x0) {
        local_2d06 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_43c);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
        local_561 = local_2d06;
      }
      else {
        sStack_2d90 = 0x4a65dd;
        _fwrite(DAT_00a0f824,DAT_00a0f820,1,local_18);
        _fclose(local_18);
        if (DAT_00a117e8 == 0) {
          DAT_00a0f820 = 0;
          _free(DAT_00a0f824);
        }
        _DAT_00a18ac0 = param_1;
        puVar6 = (undefined1 *)FUN_004d39f0();
        *puVar6 = 1;
        puVar6 = (undefined1 *)FUN_004d39f0();
        *puVar6 = 0;
        local_2d07 = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                   local_43c);
        local_8 = 0xffffffff;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
        local_561 = local_2d07;
      }
    }
    else {
      uStack_2da0 = 0x4a6484;
      basic_string<>();
      local_8._0_1_ = 6;
      uStack_2dbc = 0x4a64af;
      basic_string<>();
      FUN_00401c50();
      uStack_2dbc = 0x4a64da;
      basic_string<>();
      local_8._0_1_ = 7;
      basic_string<>(&DAT_007d144c);
      uVar3 = FUN_00401c50();
      basic_string<>(uVar3);
      local_8._0_1_ = 1;
      FUN_0042bed0();
      local_2d05 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_43c);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
      local_561 = local_2d05;
    }
  }
  else {
    local_561 = 1;
    local_8 = 0xffffffff;
    ExceptionList = &local_10;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_3);
  }
  ExceptionList = local_10;
  return local_561;
}

