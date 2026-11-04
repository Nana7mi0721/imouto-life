
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0042f790(void)

{
  char *pcVar1;
  int local_58;
  int local_54;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_44 [28];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ace69;
  local_10 = ExceptionList;
  local_28 = DAT_0084b484;
  ExceptionList = &local_10;
  FUN_005161e0();
  local_14 = 0xdc;
  local_20 = 10;
  local_1c = 0;
  local_18 = 0;
  basic_string<>(&DAT_007cd7fc);
  FUN_00401c50();
  FUN_00536a20();
  FUN_00536900();
  FUN_00536af0();
  local_24 = 0;
  FUN_005160d0();
  FUN_00543f70();
  FUN_00526390();
  FUN_005160d0();
  local_1c = 0x15e;
  local_18 = 10;
  basic_string<>();
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"[DinputState]\n");
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nButtons(Flag) = ");
  for (local_54 = 0; local_54 < 0x10; local_54 = local_54 + 1) {
    pcVar1 = (char *)FUN_0041b5f0();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1)
    ;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44," / ");
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nPOV[0] = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nPOV[1] = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nPOV[2] = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nPOV[3] = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nRx = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nRy = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nSlider[0] = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nSlider[1] = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,"\nX = ")
  ;
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,"\nY = ")
  ;
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,"\nZ = ")
  ;
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  FUN_004cbb30();
  FUN_00543f70();
  FUN_00540490();
  local_1c = 10;
  local_18 = 200;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"[XinputState]\n");
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nButtons(Flag) = ");
  for (local_58 = 0; local_58 < 0x10; local_58 = local_58 + 1) {
    pcVar1 = (char *)FUN_0041b5f0();
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1)
    ;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44," / ");
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nLeftTrigger = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nRightTrigger = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nThumbLX = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nThumbLY = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nThumbRX = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nThumbRY = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  FUN_004cbb30();
  FUN_00543f70();
  FUN_00540490();
  local_18 = 400;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"[Final inputState]\n");
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nButtons(Flag) = ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44," / ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44," / ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44," / ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44,"\nDirection Key = Up");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44," / Down ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44," / Left ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            (local_44," / Right ");
  pcVar1 = (char *)FUN_0041b5f0();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(local_44,pcVar1);
  FUN_004cbb30();
  FUN_00543f70();
  FUN_00540490();
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_44);
  ExceptionList = local_10;
  return;
}

