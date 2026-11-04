
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0042b1d0(long *param_1,long *param_2,undefined4 param_3,long *param_4,long *param_5,
            long *param_6)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  size_t sVar4;
  char *pcVar5;
  undefined1 uStack00000000;
  int local_15d8;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_15d0 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_15b4 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1598 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_157c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1560 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1544 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1528 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_150c [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_14f0 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_14d4 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_14b8 [28];
  undefined4 local_149c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_1498 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_147c [28];
  int local_1460;
  int local_145c;
  char local_1458 [5120];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_58 [28];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_3c [28];
  undefined4 local_20;
  size_t local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007acd7a;
  local_10 = ExceptionList;
  local_14 = 0x42b1f2;
  local_20 = DAT_0084b484;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 0;
  FUN_0041b8f0(local_58);
  local_8 = CONCAT31(local_8._1_3_,1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_58,"Game.ini");
  local_1c = 0;
  uVar1 = FUN_004cbb30(0);
  local_14 = FUN_0052e3c0(uVar1);
  DAT_00a11790 = 0;
  if (DAT_00a117ec == 0) {
    DAT_00a0f830 = _malloc(5000);
    _memset(DAT_00a0f830,0,5000);
  }
  if (local_14 != 0) {
    uVar1 = FUN_004cbb30();
    local_1c = FUN_0052c9a0(uVar1);
    FUN_0052cde0(DAT_00a0f830,local_1c,local_14);
    thunk_FUN_00580b80(local_14);
  }
  if (local_1c == 0) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_3c,"");
  }
  else {
    if (&uStack00000000 == (undefined1 *)0x1458) {
      local_149c = 0xffffffff;
      __CxxThrowException_8(0xffffffbc,&DAT_00842f44);
    }
    if (DAT_00a117ec == 0) {
      DAT_00a1179c = local_1c;
      _memcpy(local_1458,(void *)((int)DAT_00a0f830 + DAT_00a11790),local_1c);
    }
    DAT_00a11790 = DAT_00a11790 + local_1c;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              (local_3c,local_1458);
  }
  if (DAT_00a117ec == 0) {
    _free(DAT_00a0f830);
  }
  local_18 = 0;
  while (iVar2 = FUN_004cbbc0(&DAT_007cd4bc,local_18), iVar2 != DAT_007d0624) {
    local_18 = FUN_004cbbc0(&DAT_007cd4c0,local_18);
    FUN_004cba30(local_18,1,&DAT_007cd4c2);
    if (local_18 + -1 < 0) {
      local_15d8 = 0;
    }
    else {
      local_15d8 = local_18 + -1;
    }
    local_18 = local_15d8;
  }
  local_18 = 0;
  local_18 = FUN_004cbbc0("Start=",0);
  if (local_18 == DAT_007d0624) {
    *param_1 = 0;
  }
  else {
    iVar2 = FUN_004cbbc0(&DAT_007cd4cc,0);
    FUN_004cbc20(local_14b8,local_18 + 6,iVar2 - (local_18 + 6));
    local_8._0_1_ = 2;
    pcVar5 = (char *)FUN_004cbb30();
    lVar3 = _atol(pcVar5);
    *param_1 = lVar3;
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_14b8);
  }
  local_18 = FUN_004cbbc0("SoftModeFlag=",0);
  if (local_18 == DAT_007d0624) {
    *param_2 = 0;
  }
  else {
    FUN_004cbc20(local_14d4,local_18 + 0xd,1);
    local_8._0_1_ = 3;
    pcVar5 = (char *)FUN_004cbb30();
    lVar3 = _atol(pcVar5);
    *param_2 = lVar3;
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_14d4);
  }
  local_18 = FUN_004cbbc0("WindowModeFlag=",0);
  if (local_18 == DAT_007d0624) {
    *param_4 = 1;
  }
  else {
    FUN_004cbc20(local_14f0,local_18 + 0xf,2);
    local_8._0_1_ = 4;
    pcVar5 = (char *)FUN_004cbb30();
    lVar3 = _atol(pcVar5);
    *param_4 = lVar3;
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_14f0);
  }
  local_18 = FUN_004cbbc0("SEandBGM=",0);
  if (local_18 == DAT_007d0624) {
    *param_5 = 3;
  }
  else {
    FUN_004cbc20(local_150c,local_18 + 9,1);
    local_8._0_1_ = 5;
    pcVar5 = (char *)FUN_004cbb30();
    lVar3 = _atol(pcVar5);
    *param_5 = lVar3;
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_150c);
  }
  local_18 = FUN_004cbbc0("FrameSkip=",0);
  if (local_18 == DAT_007d0624) {
    *param_6 = 0;
  }
  else {
    FUN_004cbc20(local_1528,local_18 + 10,1);
    local_8._0_1_ = 6;
    pcVar5 = (char *)FUN_004cbb30();
    lVar3 = _atol(pcVar5);
    *param_6 = lVar3;
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1528);
  }
  local_18 = FUN_004cbbc0("Proxy=",0);
  if (local_18 == DAT_007d0624) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a13f80,"");
  }
  else {
    local_145c = FUN_004cbbc0(&DAT_007cd510,local_18 + 6);
    if (local_145c == -1) {
      local_145c = FUN_004e5650();
    }
    uVar1 = FUN_004cbc20(local_1544,local_18 + 6,local_145c - (local_18 + 7));
    local_8._0_1_ = 7;
    FUN_004cb840(uVar1);
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1544);
  }
  local_18 = FUN_004cbbc0("ProxyPort=",0);
  if (local_18 == DAT_007d0624) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a1439c,"");
  }
  else {
    local_1460 = FUN_004cbbc0(&DAT_007cd520,local_18 + 10);
    if (local_1460 == -1) {
      local_1460 = FUN_004e5650();
    }
    uVar1 = FUN_004cbc20(local_1560,local_18 + 10,local_1460 - (local_18 + 0xb));
    local_8._0_1_ = 8;
    FUN_004cb840(uVar1);
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1560);
  }
  local_18 = FUN_004cbbc0("ScreenShotFlag=",0);
  if (local_18 == DAT_007d0624) {
    DAT_0084b228 = 1;
  }
  else {
    FUN_004cbc20(local_157c,local_18 + 0xf,1);
    local_8._0_1_ = 9;
    pcVar5 = (char *)FUN_004cbb30();
    DAT_0084b228 = _atol(pcVar5);
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_157c);
  }
  local_18 = FUN_004cbbc0("F12_Reset=",0);
  if (local_18 == DAT_007d0624) {
    DAT_0084b22c = 1;
  }
  else {
    FUN_004cbc20(local_1598,local_18 + 10,1);
    local_8._0_1_ = 10;
    pcVar5 = (char *)FUN_004cbb30();
    DAT_0084b22c = _atol(pcVar5);
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1598);
  }
  local_18 = FUN_004cbbc0("Display_Number=",0);
  if (local_18 == DAT_007d0624) {
    DAT_00a117a0 = 0;
  }
  else {
    FUN_004cbc20(local_147c,local_18 + 0xf,1);
    local_8._0_1_ = 0xb;
    FUN_004cbc20(local_15b4,local_18 + 0xf,1);
    local_8._0_1_ = 0xc;
    pcVar5 = (char *)FUN_004cbb30();
    DAT_00a117a0 = _atol(pcVar5);
    local_8._0_1_ = 0xb;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_15b4);
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_147c);
  }
  local_18 = FUN_004cbbc0("Old_DirectX_Use=",0);
  if (local_18 == DAT_007d0624) {
    DAT_00a117c0 = 0;
  }
  else {
    uVar1 = 1;
    sVar4 = _strlen("Old_DirectX_Use=");
    FUN_004cbc20(local_1498,sVar4 + local_18,uVar1);
    local_8._0_1_ = 0xd;
    uVar1 = 1;
    sVar4 = _strlen("Old_DirectX_Use=");
    uVar1 = FUN_004cbc20(local_15d0,sVar4 + local_18,uVar1);
    local_8._0_1_ = 0xe;
    pcVar5 = (char *)FUN_004cbb30(uVar1);
    DAT_00a117c0 = _atol(pcVar5);
    local_8._0_1_ = 0xd;
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_15d0);
    local_8 = CONCAT31(local_8._1_3_,1);
    std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
    ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_1498);
  }
  local_8 = local_8 & 0xffffff00;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_58);
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_3c);
  ExceptionList = local_10;
  return 1;
}

