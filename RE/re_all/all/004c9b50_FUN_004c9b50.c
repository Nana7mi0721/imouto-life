
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004c9b50(int *param_1)

{
  char cVar1;
  int iVar2;
  char *_Format;
  int *piVar3;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_2f4 [8];
  undefined4 uStack_2ec;
  undefined4 uStack_2e4;
  undefined *puStack_2e0;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_2d8 [4];
  undefined4 uStack_2d4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *pbStack_2d0;
  int iStack_2cc;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_26c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_250 [28];
  undefined1 *local_234;
  char local_230 [512];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b0e74;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  ExceptionList = &local_10;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[1] = -1;
  param_1[6] = 2;
  param_1[7] = 2;
  if (DAT_00a18aa0 == -1) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a18c00,"");
  }
  else {
    basic_string<>();
    local_8 = 0;
    if (DAT_00a18aa0 == -2) {
      local_234 = abStack_2d8;
      puStack_2e0 = (undefined *)0x4c9c11;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (abStack_2d8,
                 (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_00a18c00);
      puStack_2e0 = (undefined *)0x4c9c23;
      FUN_004293c0();
      local_8._0_1_ = 1;
      FUN_004cb840();
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_250);
    }
    else {
      iStack_2cc = 0xd;
      pbStack_2d0 = local_26c;
      uStack_2d4 = 0x4c9c7d;
      FUN_0046ff30();
      local_8._0_1_ = 2;
      FUN_004cb840();
      local_8 = (uint)local_8._1_3_ << 8;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_26c);
      iStack_2cc = 0xd;
      pbStack_2d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4c9cc8;
      DAT_00a18aa4 = FUN_0046f7f0();
      iStack_2cc = 0xd;
      pbStack_2d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4c9ce3;
      DAT_00a18aa8 = FUN_0046f7f0();
      iVar2 = FUN_00477980();
      if (3 < iVar2) {
        iStack_2cc = 0xd;
        pbStack_2d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                      0x4c9d10;
        DAT_00a18b28 = FUN_0046f7f0();
      }
    }
    cVar1 = operator!=<>();
    if (cVar1 != '\0') {
      uStack_2ec = 0x4c9d4b;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_2e4,
                 local_30);
      cVar1 = FUN_00422450();
      if (cVar1 == '\0') {
        puStack_2e0 = &DAT_007d2078;
        uStack_2e4 = 0x4c9d8a;
        basic_string<>();
        puStack_2e0 = (undefined *)0x4c9d95;
        _Format = (char *)FUN_00401c50();
        iStack_2cc = 0x4c9db1;
        _sprintf(local_230,_Format);
        puStack_2e0 = (undefined *)0x4c9dc9;
        basic_string<>();
        local_8._0_1_ = 3;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_2f4,local_30);
        local_8._0_1_ = 4;
        basic_string<>(local_230);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0042bed0();
      }
      piVar3 = (int *)FUN_004cc680();
      param_1[1] = *piVar3;
      iStack_2cc = param_1[1];
      pbStack_2d0 = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                    0x4c9e75;
      FUN_004cde80();
      iStack_2cc = 0x4c9e7c;
      FUN_004ce990();
      iStack_2cc = 0x4c9e84;
      FUN_00515880();
      FUN_004cb840();
    }
    local_8 = 0xffffffff;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_30
              );
  }
  *param_1 = DAT_00a18aa0;
  FUN_004c9ef0();
  ExceptionList = local_10;
  return;
}

