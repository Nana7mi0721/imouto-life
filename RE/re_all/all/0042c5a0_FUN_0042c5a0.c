
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0042c5a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_d4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_d0 [28];
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_b4 [28];
  char local_98 [128];
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ace07;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  ExceptionList = &local_10;
  FUN_00536900(0xc);
  FUN_00536af0(0);
  _sprintf(local_98,"%d   %d   %d",param_1,param_2,param_3);
  basic_string<>(local_98);
  local_8 = 0;
  basic_string<>(&DAT_007cd6e9);
  local_8 = CONCAT31(local_8._1_3_,1);
  uVar1 = FUN_004e5650(0);
  uVar1 = FUN_004cbb30(uVar1);
  iVar2 = FUN_00540320(uVar1);
  uVar1 = FUN_004e5650(0,iVar2);
  uVar1 = FUN_004cbb30(uVar1);
  local_14 = FUN_00540320(uVar1);
  FUN_005160d0(4,0xff);
  uVar1 = FUN_00543f70(0,0x32,0,1);
  FUN_00526390(0,(int)*DAT_00a1671c / 2 + -100,*DAT_00a16718 * DAT_0084b248,
               (int)*DAT_00a1671c / 2 + 100,uVar1);
  FUN_005160d0(0,0xff);
  FUN_005161e0(0xff,0xff,0xff);
  uVar1 = FUN_00543f70(0xff,0xff,0xff,0);
  uVar1 = FUN_004cbb30(uVar1);
  FUN_00540800(((int)*DAT_00a16718 / 2) * DAT_0084b248 - iVar2 / 2,
               ((int)*DAT_00a1671c / 2) * DAT_0084b248,uVar1);
  thunk_FUN_00522bc0();
  local_d4 = 0;
  while (iVar2 = FUN_0052ece0(), iVar2 == 0) {
    FUN_0042c8b0();
    if ((DAT_00a14670 != '\0') || (DAT_00a1461d != '\0')) goto LAB_0042c80c;
    if ((DAT_00a1466c == '\0') && (DAT_00a1461a == '\0')) {
      local_d4 = 0;
    }
    else {
      local_d4 = local_d4 + 1;
      if (10 < local_d4) goto LAB_0042c80c;
    }
    FUN_0052eb30(0x10);
  }
  iVar2 = FUN_0050e8c0();
  if (iVar2 != 0) {
    FUN_0046b640();
  }
  DAT_00a13fa0 = 0xffffffff;
LAB_0042c80c:
  FUN_00536900(DAT_00a18a90);
  local_8 = local_8 & 0xffffff00;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_d0);
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_b4);
  ExceptionList = local_10;
  return;
}

