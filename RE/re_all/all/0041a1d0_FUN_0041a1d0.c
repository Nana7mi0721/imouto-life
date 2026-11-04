
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0041a1d0(undefined4 param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  LPCSTR pCVar1;
  int iVar2;
  undefined4 uVar3;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> bStack00000024;
  LPSECURITY_ATTRIBUTES lpSecurityAttributes;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_8c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_70 [28];
  int local_54;
  int local_50;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_4c [28];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007abcce;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  local_8 = 2;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)&param_2);
  local_8._0_1_ = 3;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_4c,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)&bStack00000024);
  local_8 = CONCAT31(local_8._1_3_,4);
  pCVar1 = (LPCSTR)FUN_004cbb30();
  SetCurrentDirectoryA(pCVar1);
  local_54 = 0;
  while (local_54 = FUN_004cbbc0(&DAT_007cba14,local_54), local_54 != -1) {
    FUN_004cba30(local_54,1,&DAT_007cba18);
  }
  while (local_54 = FUN_004cbbc0(&DAT_007cba1c,local_54), local_54 != -1) {
    FUN_004cba30(local_54,2,&DAT_007cba1f);
  }
  while (local_54 = FUN_004cbbc0(&DAT_007cba20,local_54), local_54 != -1) {
    FUN_004cba30(local_54,2,&DAT_007cba24);
  }
  local_50 = 0;
  local_54 = 0xffffffff;
  while( true ) {
    iVar2 = FUN_004e5650();
    if ((iVar2 < 2) || (iVar2 = FUN_004cbbc0(&DAT_007cba28,local_50), iVar2 == DAT_007d0624))
    goto LAB_0041a3f9;
    basic_string<>();
    local_8._0_1_ = 5;
    iVar2 = FUN_004cbbc0(&DAT_007cba2c,local_50);
    uVar3 = FUN_004cbc20(local_8c,local_50,iVar2 - local_50);
    local_8._0_1_ = 6;
    FUN_004cb840(uVar3);
    local_8._0_1_ = 5;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_8c);
    FUN_004cb880(local_70);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_4c,"/");
    lpSecurityAttributes = (LPSECURITY_ATTRIBUTES)0x0;
    pCVar1 = (LPCSTR)FUN_004cbb30();
    CreateDirectoryA(pCVar1,lpSecurityAttributes);
    pCVar1 = (LPCSTR)FUN_004cbb30();
    SetCurrentDirectoryA(pCVar1);
    iVar2 = FUN_004cbbc0(&DAT_007cba34,local_50);
    if (iVar2 == DAT_007d0624) break;
    local_50 = FUN_004cbbc0(&DAT_007cba38,local_50);
    local_50 = local_50 + 1;
    local_8 = CONCAT31(local_8._1_3_,4);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_70);
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_70);
LAB_0041a3f9:
  pCVar1 = (LPCSTR)FUN_004cbb30();
  SetCurrentDirectoryA(pCVar1);
  FUN_004cbc20(param_1,local_50,0xffffffff);
  local_8._0_1_ = 3;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_4c);
  local_8._0_1_ = 2;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_30);
  local_8._0_1_ = 1;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000024);
  ExceptionList = local_10;
  return param_1;
}

