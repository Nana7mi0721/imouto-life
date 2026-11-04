
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0042b080(void)

{
  LPCSTR pCVar1;
  BOOL BVar2;
  int iVar3;
  undefined4 uVar4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_84 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_68 [28];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_4c [28];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007accd1;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  ExceptionList = &local_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                       *)&DAT_00a14c70);
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_30,"_NetDownloadData\\");
  pCVar1 = (LPCSTR)FUN_004cbb30();
  BVar2 = PathIsDirectoryA(pCVar1);
  if (BVar2 != 0) {
    basic_string<>();
    local_8._0_1_ = 1;
    basic_string<>();
    local_8._0_1_ = 2;
    FUN_004cb840(&DAT_00a14c70);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (local_4c,"_NetDownloadData");
    FUN_004cb840(&DAT_00a14c70);
    iVar3 = FUN_004e5650();
    uVar4 = FUN_004cbc20(local_84,0,iVar3 + -1);
    local_8._0_1_ = 3;
    FUN_004cb840(uVar4);
    local_8._0_1_ = 2;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_84);
    uVar4 = FUN_004cbb30();
    uVar4 = FUN_004cbb30(uVar4);
    FUN_00421040(uVar4);
    pCVar1 = (LPCSTR)FUN_004cbb30();
    RemoveDirectoryA(pCVar1);
    local_8._0_1_ = 1;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_68);
    local_8 = (uint)local_8._1_3_ << 8;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_4c
              );
  }
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_30);
  ExceptionList = local_10;
  return;
}

