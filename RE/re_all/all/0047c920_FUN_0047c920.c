
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_0047c920(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  char *_Format;
  undefined4 uVar4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_19c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_180 [28];
  size_t local_164;
  char local_160 [256];
  void *local_60;
  int local_5c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_58 [28];
  int local_3c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_38 [28];
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af20c;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  ExceptionList = &local_10;
  iVar2 = FUN_004ce080();
  if (iVar2 == 0) {
    FUN_0047cda0();
  }
  for (local_14 = 0; local_14 < 2; local_14 = local_14 + 1) {
    local_18 = 0;
    while( true ) {
      iVar2 = FUN_004717c0();
      if (iVar2 <= local_18) break;
      FUN_0046ff30();
      local_8 = 0;
      FUN_004e5650();
      iVar2 = FUN_004cbbc0();
      if (iVar2 == DAT_007d0624) {
        FUN_004e5650();
        iVar2 = FUN_004cbbc0();
        if (iVar2 != DAT_007d0624) goto LAB_0047ca1a;
      }
      else {
LAB_0047ca1a:
        puVar3 = (undefined4 *)FUN_004ce990();
        *puVar3 = 1;
      }
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_38);
      local_18 = local_18 + 1;
    }
  }
  local_3c = 0;
  do {
    if (DAT_00a14328 <= local_3c) {
      *(undefined1 *)(param_1 + 0x130) = 1;
      ExceptionList = local_10;
      return;
    }
    FUN_004cbb30();
    basic_string<>();
    local_8 = 1;
    FUN_0046ff30();
    local_8._0_1_ = 2;
    FUN_004cb880();
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_180);
    FUN_004e5650();
    iVar2 = FUN_004cbbc0();
    if (iVar2 == DAT_007d0624) {
      FUN_004e5650();
      iVar2 = FUN_004cbbc0();
      if (iVar2 != DAT_007d0624) goto LAB_0047cb25;
LAB_0047cd67:
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58);
    }
    else {
LAB_0047cb25:
      FUN_004cbb30();
      local_5c = FUN_0052e3c0();
      if (local_5c != 0) {
        if (DAT_00a117b0 != 0) {
          FUN_004cbb30();
          local_164 = FUN_0052c9a0();
          local_60 = _malloc(local_164);
          FUN_0052cde0();
          thunk_FUN_00580b80();
          FUN_00401000();
          FUN_00401600();
          _free(local_60);
        }
        puVar3 = (undefined4 *)FUN_004ce990();
        *puVar3 = 1;
        goto LAB_0047cd67;
      }
      cVar1 = operator!=<>();
      if (cVar1 != '\0') {
        FUN_0046ff30();
        local_8._0_1_ = 3;
        FUN_004cbb30();
        basic_string<>();
        _Format = (char *)FUN_00401c50();
        _sprintf(local_160,_Format);
        local_8._0_1_ = 1;
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_19c);
        basic_string<>();
        local_8._0_1_ = 4;
        basic_string<>();
        local_8._0_1_ = 5;
        basic_string<>(&DAT_007d0bfc);
        uVar4 = FUN_00401c50();
        basic_string<>(uVar4);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_0042bed0();
      }
      puVar3 = (undefined4 *)FUN_004ce990();
      *puVar3 = 0xffffffff;
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58);
    }
    local_3c = local_3c + 1;
  } while( true );
}

