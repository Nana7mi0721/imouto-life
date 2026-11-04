
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00486e50(int param_1,int param_2)

{
  char *_Format;
  undefined1 auStack_2a8 [16];
  undefined4 uStack_298;
  undefined *puStack_294;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_290;
  undefined1 auStack_28c [12];
  undefined4 uStack_280;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_240 [28];
  undefined1 *local_224;
  undefined1 *local_220;
  undefined1 *local_21c;
  char local_218 [516];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007af711;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  if ((((param_2 < 1600000) || (1699999 < param_2)) && (1099999 < param_2)) &&
     ((param_2 < 1200000 && (*(int *)(param_1 + 0x14) == -1)))) {
    local_21c = (undefined1 *)&pbStack_290;
    puStack_294 = &DAT_007d0fb8;
    uStack_298 = 0x486ef8;
    ExceptionList = &local_10;
    basic_string<>();
    puStack_294 = (undefined *)0x486f03;
    _Format = (char *)FUN_00401c50();
    uStack_280 = 0x486f1f;
    _sprintf(local_218,_Format);
    local_220 = auStack_28c;
    pbStack_290 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  &DAT_007d0621;
    puStack_294 = (undefined *)0x486f37;
    basic_string<>();
    local_8 = 0;
    pbStack_290 = local_240;
    puStack_294 = (undefined *)0x486f5c;
    FUN_00438b60();
    local_8._0_1_ = 1;
    pbStack_290 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                  0x486f80;
    FUN_004cbb30();
    local_224 = auStack_2a8;
    basic_string<>();
    local_8._0_1_ = 2;
    basic_string<>(local_218);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0042bed0();
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_240);
  }
  else {
    _DAT_00a16444 = *(undefined4 *)(param_1 + 0x10);
    uStack_280 = 0x48705d;
    ExceptionList = &local_10;
    FUN_00438f70();
  }
  ExceptionList = local_10;
  return;
}

